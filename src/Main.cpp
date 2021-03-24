#include <visualconstruct.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_vulkan.h>

using namespace VisualConstruct;

int main()
{
    // Vulkan Test
    uint32_t extensionCount = 0;
    if (vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr) != VK_SUCCESS)
    {
        VC_LOG_VULKAN_ERROR("Vulkan Test: Failed");
        return 0;
    }
    VC_LOG_VULKAN_INFO("Vulkan Test: Pass");

    // GLM Test
    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;
    VC_LOG_CORE_INFO("GLM Test: Pass");

    // GLFW Test
    if (!glfwInit())
    {
        VC_LOG_CLIENT_ERROR("GLFW Test: Failed");
        return 0;
    }
    VC_LOG_CORE_INFO("GLFW Test: Pass");

    GLFWwindow *window = glfwCreateWindow(1920, 1080, "Visual Construct", nullptr, nullptr);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Glad Test
    if (!gladLoadGL())
    {
        VC_LOG_OPENGL_ERROR("GLAD Test: Failed");
        return 0;
    }
    VC_LOG_OPENGL_INFO("GLAD Test: Pass");

    // IMGUI Test
    if (!IMGUI_CHECKVERSION())
    {
        VC_LOG_CLIENT_ERROR("Imgui Test: Failed");
        return 0;
    }
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");
    VC_LOG_CLIENT_INFO("Imgui Test: Pass");

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Storage Test

    StorageDynamic<int> storage(5);
    for (int i = 0; i < 1000; i++)
    {
        auto item_index = storage.allocateItem();
        int *item = storage.getItem(item_index);
        *item = i;
    }

    for (int i = 0; i < 1000; i++)
    {
        storage.freeItem(i);
    }

    for (int i = 0; i < 1000; i++)
    {
        auto item_index = storage.allocateItem();
        int *item = storage.getItem(i);
        *item = i;
    }

    for (int i = 0; i < 1000; i++)
    {
        int *item = storage.getItem(i);
        if (i != *item)
        {
            VC_LOG_CORE_ERROR("Storage Dynamic Fail");
        }
    }

    StorageStatic<int> storageS(1000);
    for (int i = 0; i < 1000; i++)
    {
        auto item_index = storageS.allocateItem();
        int *item = storageS.getItem(item_index);
        *item = i;
    }

    for (int i = 0; i < 1000; i++)
    {
        storageS.freeItem(i);
    }

    for (int i = 0; i < 1000; i++)
    {
        auto item_index = storageS.allocateItem();
        int *item = storageS.getItem(i);
        *item = i;
    }

    for (int i = 0; i < 1000; i++)
    {
        int *item = storageS.getItem(i);
        if (i != *item)
        {
            VC_LOG_CORE_ERROR("Storage Static Fail");
        }
    }
    Renderer *renderer = new OglRenderer;

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");          // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);             // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float *)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button")) // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window); // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        ImGui::Begin("Rendered Scene");
        ImVec2 pos = ImGui::GetCursorScreenPos();
        renderer->render(1080, 1920);
        ImTextureID textureID;
        renderer->getRender(&textureID);
        ImGui::GetWindowDrawList()->AddImage(
            textureID,
            ImVec2(ImGui::GetCursorScreenPos()),
            ImVec2(ImGui::GetCursorScreenPos().x + 1920 / 2, ImGui::GetCursorScreenPos().y + 1080 / 2),
            ImVec2(0, 1),
            ImVec2(1, 0));
        ImGui::End();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }
    // IMGUI Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 1;
}
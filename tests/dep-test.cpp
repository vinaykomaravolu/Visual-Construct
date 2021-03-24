#include "gtest/gtest.h"
#include <visualconstruct.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_vulkan.h>

using namespace std;
using namespace VisualConstruct;

TEST(DependencyTest, vulkan)
{
    // Vulkan Test
    try
    {
        uint32_t extensionCount = 0;
        VkResult result = vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        EXPECT_EQ(VkResult::VK_SUCCESS, result);
    }
    catch (const exception &err)
    {
        ADD_FAILURE() << err.what();
    }
}

TEST(DependencyTest, GLM)
{
    // Vulkan Test
    try
    {
        glm::mat4 matrix;
        glm::vec4 vec;
        auto test = matrix * vec;
        EXPECT_TRUE(true);
    }
    catch (const exception &err)
    {
        ADD_FAILURE() << err.what();
    }
}

TEST(DependencyTest, GLFW)
{
    // Vulkan Test
    try
    {
        EXPECT_EQ(GLFW_TRUE, glfwInit());
        GLFWwindow *window = glfwCreateWindow(1920, 1080, "Visual Construct", nullptr, nullptr);
        EXPECT_NE(nullptr, window);
    }
    catch (const exception &err)
    {
        ADD_FAILURE() << err.what();
    }
}

TEST(DependencyTest, glad)
{
    try
    {
        EXPECT_TRUE(!gladLoadGL());
    }
    catch (const exception &err)
    {
        ADD_FAILURE() << err.what();
    }
}

TEST(DependencyTest, imgui)
{
    try
    {
        EXPECT_TRUE(IMGUI_CHECKVERSION());
    }
    catch (const exception &err)
    {
        ADD_FAILURE() << err.what();
    }
}
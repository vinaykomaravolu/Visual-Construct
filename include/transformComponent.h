#pragma once
#include <component.h>
#include <internal.h>



namespace VisualConstruct
{
    class TransformComponent : public Component
    {
    public:
        TransformComponent(std::string id);
        TransformComponent(std::string id, glm::vec3 position);
        ~TransformComponent();
        void initialize();
        void update();

        void scale(glm::vec3 scale);
        void rotate(float angle, glm::vec3 axis);
        void translate(glm::vec3 vec);

        void setPostion(glm::vec3 position);
        void setTransform(glm::mat4 transform);    
        glm::vec3 getPosition();
        glm::mat4 getTransform();
        
    private:
        glm::mat4 transform = glm::mat4(1);
        glm::vec3 position = glm::vec3(0,0,0);
        float rotationAngle;
        glm::vec3 rotationAxis = glm::vec3(0,0,0);
    };
}

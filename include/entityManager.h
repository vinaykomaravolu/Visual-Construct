#pragma once
#include <internal.h>

namespace VisualConstruct
{
    class EntityManager
    {
    public:
        EntityManager();
        ~EntityManager();
        Entity CreateEntity();
        void DestroyEntity(Entity entity);
        void SetSignature(Entity entity, Signature signature);
        Signature GetSignature(Entity entity);
    private:
        std::queue<Entity> mAvailableEntities;
        std::array<Signature, MAX_ENTITIES> mSignatures{};
        uint32_t mEntityCount = 0;
    };
}

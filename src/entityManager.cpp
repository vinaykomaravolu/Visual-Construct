#include <entityManager.h>

namespace VisualConstruct
{
	EntityManager::EntityManager()
	{
		for (int id = 0; id < MAX_ENTITIES; id++)
		{
			Entity entity;
			entity.id = id;
			mAvailableEntities.push(entity);
		}
	}

	Entity EntityManager::CreateEntity()
	{
		if (mEntityCount > MAX_ENTITIES)
			VC_LOG_CORE_ERROR("Max entity count reached!");

		Entity entity = mAvailableEntities.front();
		mAvailableEntities.pop();
		return entity;
	}

	void EntityManager::DestroyEntity(Entity entity)
	{
		if (entity.id > MAX_ENTITIES)
			VC_LOG_CORE_ERROR("Entity out of range");

		mSignatures[entity.id].reset();


		mAvailableEntities.push(entity);
	}	

	void EntityManager::SetSignature(Entity entity, Signature signature)
	{
		mSignatures[entity.id] = signature;
	}

	Signature EntityManager::GetSignature(Entity entity) 
	{
		return mSignatures[entity.id];
	}

}
#pragma once
#include <internal.h>

namespace VisualConstruct
{
	class Physics
	{
	public:
		Physics();
		~Physics();
		void setGravity(btVector3 gravity);
		void stepSimulation(btScalar timeStep);
		void stepSimulation();
		void test();
	private:
		btDefaultCollisionConfiguration* collisionConfiguration;
		btCollisionDispatcher* dispatcher;
		btBroadphaseInterface* overlappingPairCache;
		btSequentialImpulseConstraintSolver* solver;
		btDiscreteDynamicsWorld* dynamicsWorld;

		btAlignedObjectArray<btCollisionShape*> collisionShapes;

		btScalar defaultTimeStep = 1.f / 60.f;
	};
}
#include <physics.h>

namespace VisualConstruct
{
    /*Physics::Physics()
    {
        collisionConfiguration = new btDefaultCollisionConfiguration();
        dispatcher = new btCollisionDispatcher(collisionConfiguration);
        overlappingPairCache = new btDbvtBroadphase(); // btAxis3Sweep
        solver = new btSequentialImpulseConstraintSolver;
        dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
        // Default gravity settings
        dynamicsWorld->setGravity(btVector3(0, -10, 0));
    }

    Physics::~Physics()
    {
        for (int j = 0; j < collisionShapes.size(); j++)
        {
            btCollisionShape* shape = collisionShapes[j];
            collisionShapes[j] = 0;
            delete shape;
        }

        delete dynamicsWorld;
        delete solver;
        delete overlappingPairCache;
        delete dispatcher;
        delete collisionConfiguration;
    }

    void Physics::setGravity(btVector3 gravity)
    {
        dynamicsWorld->setGravity(gravity);
    }

    void Physics::stepSimulation(btScalar timeStep)
    {
        dynamicsWorld->stepSimulation(timeStep, 10);
    }

    void Physics::stepSimulation()
    {
        dynamicsWorld->stepSimulation(defaultTimeStep, 10);
    }

    // REMOVE LATER
    void Physics::test()
    {
        dynamicsWorld->setGravity(btVector3(0, -10, 0));

        {
            btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(50.), btScalar(50.), btScalar(50.)));

            collisionShapes.push_back(groundShape);

            btTransform groundTransform;
            groundTransform.setIdentity();
            groundTransform.setOrigin(btVector3(0, -56, 0));

            btScalar mass(0.);

            //rigidbody is dynamic if and only if mass is non zero, otherwise static
            bool isDynamic = (mass != 0.f);

            btVector3 localInertia(0, 0, 0);
            if (isDynamic)
                groundShape->calculateLocalInertia(mass, localInertia);

            //using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
            btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
            btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, groundShape, localInertia);
            btRigidBody* body = new btRigidBody(rbInfo);

            //add the body to the dynamics world
            dynamicsWorld->addRigidBody(body);
        }

        {
            //create a dynamic rigidbody

            btCollisionShape* colShape = new btSphereShape(btScalar(1.));
            collisionShapes.push_back(colShape);

            /// Create Dynamic Objects
            btTransform startTransform;
            startTransform.setIdentity();
            startTransform.setOrigin(btVector3(2, 10, 0));

            btScalar mass(1.f);

            //rigidbody is dynamic if and only if mass is non zero, otherwise static
            bool isDynamic = (mass != 0.f);

            btVector3 localInertia(0, 0, 0);
            if (isDynamic)
                colShape->calculateLocalInertia(mass, localInertia);

            //using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
            btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
            btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, colShape, localInertia);
            btRigidBody* body = new btRigidBody(rbInfo);

            dynamicsWorld->addRigidBody(body);
        }


        for (int i = 0; i < 100; i++)
        {
            dynamicsWorld->stepSimulation(1.f / 60.f, 10);
            for (int j = dynamicsWorld->getNumCollisionObjects() - 1; j > 0; j--)
            {
                btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[j];
                btRigidBody* body = btRigidBody::upcast(obj);
                btTransform trans;
                if (body && body->getMotionState())
                {
                    body->getMotionState()->getWorldTransform(trans);
                }
                else
                {
                    trans = obj->getWorldTransform();
                }
                printf("world pos object %d = %f,%f,%f\n", j, float(trans.getOrigin().getX()), float(trans.getOrigin().getY()), float(trans.getOrigin().getZ()));

            }
        }
        // remove the rigidbodies from the dynamics world and delete them
        for (int i = dynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--)
        {
            btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
            btRigidBody* body = btRigidBody::upcast(obj);
            if (body && body->getMotionState())
            {
                delete body->getMotionState();
            }
            dynamicsWorld->removeCollisionObject(obj);
            delete obj;
        }

        //delete collision shapes
        for (int j = 0; j < collisionShapes.size(); j++)
        {
            btCollisionShape* shape = collisionShapes[j];
            collisionShapes[j] = 0;
            delete shape;
        }
    }*/
}
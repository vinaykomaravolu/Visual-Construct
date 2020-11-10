#pragma once
#include <log.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vulkan.h>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <btBulletDynamicsCommon.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <bitset>

#include <storage.h>


#define MAX_ENTITIES 8192
#define MAX_COMPONENT_SYSTEMS 64

using Signature = std::bitset<MAX_COMPONENT_SYSTEMS>;

struct Entity
{
	uint32_t id;
};


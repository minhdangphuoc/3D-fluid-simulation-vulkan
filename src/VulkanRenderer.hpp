#pragma once
#ifndef _VulkanRenderer_
#define _VulkanRenderer_

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept> // For depass exceptions with Vulkan 
#include <vector>

class VulkanRenderer
{
public:
    VulkanRenderer(/* args */);

    int init(GLFWwindow *);

    ~VulkanRenderer();

private:
    GLFWwindow * window;

    // Vulkan Components
    VkInstance instance;

    // Vulkan Functions
    // - Create Functions
    void createInstance();
    // - Support Functions
    bool checkInstanceExtensionSupport(std::vector<const char*> * checkExtensions);
};

#endif // _VulkanRenderer_
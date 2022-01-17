#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept> // For depass exceptions with Vulkan 
#include <vector>
#include <iostream>

#include "VulkanRenderer.hpp"
#include "VulkanRenderer.cpp"

GLFWwindow * window; // For window init
VulkanRenderer vulkanRenderer; // For Vulkan API init


void initWindow(int wHeight = 600, int wWidth = 800, std::string wName = "Test Window")
{
    // Initialise GLFW
    glfwInit();

    // Set GLFW to not work with GLFW - ex: glfwWindowHint(object, value)
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(wWidth, wHeight, wName.c_str(), nullptr, nullptr);

}

int main()
{
    // Create Window
    initWindow(600, 800, "Test Window");

    // Create Vulkan Render instance
    if(vulkanRenderer.init(window) == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    
    while (!glfwWindowShouldClose)
    {
        glfwPollEvents();
    }
    
    // Destroy and stop GLFW window
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
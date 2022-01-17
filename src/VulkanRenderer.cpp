#include <iostream>

#include "VulkanRenderer.hpp"

VulkanRenderer::VulkanRenderer(){}
VulkanRenderer::~VulkanRenderer(){}

int VulkanRenderer::init(GLFWwindow * newWindow)
{
    // Set window to vulkan window
    window = newWindow;

    try{
        createInstance();
    } catch (const std::runtime_error &err){
        std::cerr << "Error: " << err.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}

void VulkanRenderer::createInstance()
{
    // Infomation about the application itself
    // Most data here doesn't affect the program and is for developer convenience
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan App"; // Application name
    appInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1); // Version num
    appInfo.pEngineName = "No Engine"; // Engine name
    appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1); // Custom engine ver
    appInfo.apiVersion =VK_API_VERSION_1_0; // set the version of vulkan

    // Creation Component info
    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;// Stucture type
    createInfo.pApplicationInfo = &appInfo; // get value by ref the appInfo

    // Create list to hold instance extensions
    std::vector<const char*> instanceExtensions = std::vector<const char*>();

    // Set up extensions Instance will use
    uint32_t glfwExtensionCount = 0;    // GLFW may require multiple extensions
    const char** glfwExtensions;        // Extension passed as array of "cstring", so need pointer (the array) to the pointer (the cstring)

    // Vulkan help to setup and add extension for us
    //Get GLFW extensions
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    // Add GLFW extension to liust of extensions;
    // Check this again
    for (0;glfwExtensionCount-1; [&](int i)
    {
        instanceExtensions.push_back(glfwExtensions[i]);
    });

    createInfo.enabledExtensionCount = static_cast<uint32_t> (instanceExtensions.size());
    createInfo.ppEnabledExtensionNames = instanceExtensions.data();

    // Todo: set up validation layers that instance will use
    createInfo.enabledLayerCount = 0;
    createInfo.ppEnabledExtensionNames = nullptr;

    // Create instance
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

    if (result != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to create a Vulkan Instance ");
    }
}
/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018
              Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

#include "flextVk.h"

FlextVkInstance flextVkInstance{};

FlextVkDevice flextVkDevice{};

void flextVkInitInstance(VkInstance instance, FlextVkInstance* data) {
    data->CreateDevice = reinterpret_cast<VkResult(VKAPI_PTR*)(VkPhysicalDevice, const VkDeviceCreateInfo*, const VkAllocationCallbacks*, VkDevice*)>(vkGetInstanceProcAddr(instance, "vkCreateDevice"));
    data->DestroyInstance = reinterpret_cast<void(VKAPI_PTR*)(VkInstance, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyInstance"));
    data->EnumerateDeviceExtensionProperties = reinterpret_cast<VkResult(VKAPI_PTR*)(VkPhysicalDevice, const char*, uint32_t*, VkExtensionProperties*)>(vkGetInstanceProcAddr(instance, "vkEnumerateDeviceExtensionProperties"));
    data->EnumerateDeviceLayerProperties = reinterpret_cast<VkResult(VKAPI_PTR*)(VkPhysicalDevice, uint32_t*, VkLayerProperties*)>(vkGetInstanceProcAddr(instance, "vkEnumerateDeviceLayerProperties"));
    data->EnumeratePhysicalDevices = reinterpret_cast<VkResult(VKAPI_PTR*)(VkInstance, uint32_t*, VkPhysicalDevice*)>(vkGetInstanceProcAddr(instance, "vkEnumeratePhysicalDevices"));
    data->GetDeviceProcAddr = reinterpret_cast<PFN_vkVoidFunction(VKAPI_PTR*)(VkDevice, const char*)>(vkGetInstanceProcAddr(instance, "vkGetDeviceProcAddr"));
    data->GetPhysicalDeviceFeatures = reinterpret_cast<void(VKAPI_PTR*)(VkPhysicalDevice, VkPhysicalDeviceFeatures*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFeatures"));
    data->GetPhysicalDeviceFormatProperties = reinterpret_cast<void(VKAPI_PTR*)(VkPhysicalDevice, VkFormat, VkFormatProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFormatProperties"));
    data->GetPhysicalDeviceImageFormatProperties = reinterpret_cast<VkResult(VKAPI_PTR*)(VkPhysicalDevice, VkFormat, VkImageType, VkImageTiling, VkImageUsageFlags, VkImageCreateFlags, VkImageFormatProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceImageFormatProperties"));
    data->GetPhysicalDeviceMemoryProperties = reinterpret_cast<void(VKAPI_PTR*)(VkPhysicalDevice, VkPhysicalDeviceMemoryProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceMemoryProperties"));
    data->GetPhysicalDeviceProperties = reinterpret_cast<void(VKAPI_PTR*)(VkPhysicalDevice, VkPhysicalDeviceProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties"));
    data->GetPhysicalDeviceQueueFamilyProperties = reinterpret_cast<void(VKAPI_PTR*)(VkPhysicalDevice, uint32_t*, VkQueueFamilyProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyProperties"));
    data->GetPhysicalDeviceSparseImageFormatProperties = reinterpret_cast<void(VKAPI_PTR*)(VkPhysicalDevice, VkFormat, VkImageType, VkSampleCountFlagBits, VkImageUsageFlags, VkImageTiling, uint32_t*, VkSparseImageFormatProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSparseImageFormatProperties"));
}

void flextVkInitDevice(VkDevice device, FlextVkDevice* data) {
    data->AllocateCommandBuffers = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkCommandBufferAllocateInfo*, VkCommandBuffer*)>(vkGetDeviceProcAddr(device, "vkAllocateCommandBuffers"));
    data->AllocateDescriptorSets = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkDescriptorSetAllocateInfo*, VkDescriptorSet*)>(vkGetDeviceProcAddr(device, "vkAllocateDescriptorSets"));
    data->AllocateMemory = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkMemoryAllocateInfo*, const VkAllocationCallbacks*, VkDeviceMemory*)>(vkGetDeviceProcAddr(device, "vkAllocateMemory"));
    data->BeginCommandBuffer = reinterpret_cast<VkResult(VKAPI_PTR*)(VkCommandBuffer, const VkCommandBufferBeginInfo*)>(vkGetDeviceProcAddr(device, "vkBeginCommandBuffer"));
    data->BindBufferMemory = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkBuffer, VkDeviceMemory, VkDeviceSize)>(vkGetDeviceProcAddr(device, "vkBindBufferMemory"));
    data->BindImageMemory = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkImage, VkDeviceMemory, VkDeviceSize)>(vkGetDeviceProcAddr(device, "vkBindImageMemory"));
    data->CmdBeginQuery = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkQueryPool, uint32_t, VkQueryControlFlags)>(vkGetDeviceProcAddr(device, "vkCmdBeginQuery"));
    data->CmdBeginRenderPass = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, const VkRenderPassBeginInfo*, VkSubpassContents)>(vkGetDeviceProcAddr(device, "vkCmdBeginRenderPass"));
    data->CmdBindDescriptorSets = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkPipelineBindPoint, VkPipelineLayout, uint32_t, uint32_t, const VkDescriptorSet*, uint32_t, const uint32_t*)>(vkGetDeviceProcAddr(device, "vkCmdBindDescriptorSets"));
    data->CmdBindIndexBuffer = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkDeviceSize, VkIndexType)>(vkGetDeviceProcAddr(device, "vkCmdBindIndexBuffer"));
    data->CmdBindPipeline = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkPipelineBindPoint, VkPipeline)>(vkGetDeviceProcAddr(device, "vkCmdBindPipeline"));
    data->CmdBindVertexBuffers = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*)>(vkGetDeviceProcAddr(device, "vkCmdBindVertexBuffers"));
    data->CmdBlitImage = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageBlit*, VkFilter)>(vkGetDeviceProcAddr(device, "vkCmdBlitImage"));
    data->CmdClearAttachments = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, const VkClearAttachment*, uint32_t, const VkClearRect*)>(vkGetDeviceProcAddr(device, "vkCmdClearAttachments"));
    data->CmdClearColorImage = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkImage, VkImageLayout, const VkClearColorValue*, uint32_t, const VkImageSubresourceRange*)>(vkGetDeviceProcAddr(device, "vkCmdClearColorImage"));
    data->CmdClearDepthStencilImage = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkImage, VkImageLayout, const VkClearDepthStencilValue*, uint32_t, const VkImageSubresourceRange*)>(vkGetDeviceProcAddr(device, "vkCmdClearDepthStencilImage"));
    data->CmdCopyBuffer = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkBuffer, uint32_t, const VkBufferCopy*)>(vkGetDeviceProcAddr(device, "vkCmdCopyBuffer"));
    data->CmdCopyBufferToImage = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkImage, VkImageLayout, uint32_t, const VkBufferImageCopy*)>(vkGetDeviceProcAddr(device, "vkCmdCopyBufferToImage"));
    data->CmdCopyImage = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageCopy*)>(vkGetDeviceProcAddr(device, "vkCmdCopyImage"));
    data->CmdCopyImageToBuffer = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkImage, VkImageLayout, VkBuffer, uint32_t, const VkBufferImageCopy*)>(vkGetDeviceProcAddr(device, "vkCmdCopyImageToBuffer"));
    data->CmdCopyQueryPoolResults = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t, VkBuffer, VkDeviceSize, VkDeviceSize, VkQueryResultFlags)>(vkGetDeviceProcAddr(device, "vkCmdCopyQueryPoolResults"));
    data->CmdDispatch = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, uint32_t, uint32_t)>(vkGetDeviceProcAddr(device, "vkCmdDispatch"));
    data->CmdDispatchIndirect = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkDeviceSize)>(vkGetDeviceProcAddr(device, "vkCmdDispatchIndirect"));
    data->CmdDraw = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t)>(vkGetDeviceProcAddr(device, "vkCmdDraw"));
    data->CmdDrawIndexed = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, int32_t, uint32_t)>(vkGetDeviceProcAddr(device, "vkCmdDrawIndexed"));
    data->CmdDrawIndexedIndirect = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t)>(vkGetDeviceProcAddr(device, "vkCmdDrawIndexedIndirect"));
    data->CmdDrawIndirect = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t)>(vkGetDeviceProcAddr(device, "vkCmdDrawIndirect"));
    data->CmdEndQuery = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkQueryPool, uint32_t)>(vkGetDeviceProcAddr(device, "vkCmdEndQuery"));
    data->CmdEndRenderPass = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer)>(vkGetDeviceProcAddr(device, "vkCmdEndRenderPass"));
    data->CmdExecuteCommands = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, const VkCommandBuffer*)>(vkGetDeviceProcAddr(device, "vkCmdExecuteCommands"));
    data->CmdFillBuffer = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, uint32_t)>(vkGetDeviceProcAddr(device, "vkCmdFillBuffer"));
    data->CmdNextSubpass = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkSubpassContents)>(vkGetDeviceProcAddr(device, "vkCmdNextSubpass"));
    data->CmdPipelineBarrier = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkPipelineStageFlags, VkPipelineStageFlags, VkDependencyFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*)>(vkGetDeviceProcAddr(device, "vkCmdPipelineBarrier"));
    data->CmdPushConstants = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkPipelineLayout, VkShaderStageFlags, uint32_t, uint32_t, const void*)>(vkGetDeviceProcAddr(device, "vkCmdPushConstants"));
    data->CmdResetEvent = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkEvent, VkPipelineStageFlags)>(vkGetDeviceProcAddr(device, "vkCmdResetEvent"));
    data->CmdResetQueryPool = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t)>(vkGetDeviceProcAddr(device, "vkCmdResetQueryPool"));
    data->CmdResolveImage = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageResolve*)>(vkGetDeviceProcAddr(device, "vkCmdResolveImage"));
    data->CmdSetBlendConstants = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, const float [4])>(vkGetDeviceProcAddr(device, "vkCmdSetBlendConstants"));
    data->CmdSetDepthBias = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, float, float, float)>(vkGetDeviceProcAddr(device, "vkCmdSetDepthBias"));
    data->CmdSetDepthBounds = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, float, float)>(vkGetDeviceProcAddr(device, "vkCmdSetDepthBounds"));
    data->CmdSetEvent = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkEvent, VkPipelineStageFlags)>(vkGetDeviceProcAddr(device, "vkCmdSetEvent"));
    data->CmdSetLineWidth = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, float)>(vkGetDeviceProcAddr(device, "vkCmdSetLineWidth"));
    data->CmdSetScissor = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, uint32_t, const VkRect2D*)>(vkGetDeviceProcAddr(device, "vkCmdSetScissor"));
    data->CmdSetStencilCompareMask = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkStencilFaceFlags, uint32_t)>(vkGetDeviceProcAddr(device, "vkCmdSetStencilCompareMask"));
    data->CmdSetStencilReference = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkStencilFaceFlags, uint32_t)>(vkGetDeviceProcAddr(device, "vkCmdSetStencilReference"));
    data->CmdSetStencilWriteMask = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkStencilFaceFlags, uint32_t)>(vkGetDeviceProcAddr(device, "vkCmdSetStencilWriteMask"));
    data->CmdSetViewport = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, uint32_t, const VkViewport*)>(vkGetDeviceProcAddr(device, "vkCmdSetViewport"));
    data->CmdUpdateBuffer = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, const void*)>(vkGetDeviceProcAddr(device, "vkCmdUpdateBuffer"));
    data->CmdWaitEvents = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, const VkEvent*, VkPipelineStageFlags, VkPipelineStageFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*)>(vkGetDeviceProcAddr(device, "vkCmdWaitEvents"));
    data->CmdWriteTimestamp = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkPipelineStageFlagBits, VkQueryPool, uint32_t)>(vkGetDeviceProcAddr(device, "vkCmdWriteTimestamp"));
    data->CreateBuffer = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*)>(vkGetDeviceProcAddr(device, "vkCreateBuffer"));
    data->CreateBufferView = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkBufferViewCreateInfo*, const VkAllocationCallbacks*, VkBufferView*)>(vkGetDeviceProcAddr(device, "vkCreateBufferView"));
    data->CreateCommandPool = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkCommandPoolCreateInfo*, const VkAllocationCallbacks*, VkCommandPool*)>(vkGetDeviceProcAddr(device, "vkCreateCommandPool"));
    data->CreateComputePipelines = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkPipelineCache, uint32_t, const VkComputePipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*)>(vkGetDeviceProcAddr(device, "vkCreateComputePipelines"));
    data->CreateDescriptorPool = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkDescriptorPoolCreateInfo*, const VkAllocationCallbacks*, VkDescriptorPool*)>(vkGetDeviceProcAddr(device, "vkCreateDescriptorPool"));
    data->CreateDescriptorSetLayout = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkDescriptorSetLayoutCreateInfo*, const VkAllocationCallbacks*, VkDescriptorSetLayout*)>(vkGetDeviceProcAddr(device, "vkCreateDescriptorSetLayout"));
    data->CreateEvent = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkEventCreateInfo*, const VkAllocationCallbacks*, VkEvent*)>(vkGetDeviceProcAddr(device, "vkCreateEvent"));
    data->CreateFence = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkFenceCreateInfo*, const VkAllocationCallbacks*, VkFence*)>(vkGetDeviceProcAddr(device, "vkCreateFence"));
    data->CreateFramebuffer = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkFramebufferCreateInfo*, const VkAllocationCallbacks*, VkFramebuffer*)>(vkGetDeviceProcAddr(device, "vkCreateFramebuffer"));
    data->CreateGraphicsPipelines = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkPipelineCache, uint32_t, const VkGraphicsPipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*)>(vkGetDeviceProcAddr(device, "vkCreateGraphicsPipelines"));
    data->CreateImage = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkImageCreateInfo*, const VkAllocationCallbacks*, VkImage*)>(vkGetDeviceProcAddr(device, "vkCreateImage"));
    data->CreateImageView = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkImageViewCreateInfo*, const VkAllocationCallbacks*, VkImageView*)>(vkGetDeviceProcAddr(device, "vkCreateImageView"));
    data->CreatePipelineCache = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkPipelineCacheCreateInfo*, const VkAllocationCallbacks*, VkPipelineCache*)>(vkGetDeviceProcAddr(device, "vkCreatePipelineCache"));
    data->CreatePipelineLayout = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkPipelineLayoutCreateInfo*, const VkAllocationCallbacks*, VkPipelineLayout*)>(vkGetDeviceProcAddr(device, "vkCreatePipelineLayout"));
    data->CreateQueryPool = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkQueryPoolCreateInfo*, const VkAllocationCallbacks*, VkQueryPool*)>(vkGetDeviceProcAddr(device, "vkCreateQueryPool"));
    data->CreateRenderPass = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkRenderPassCreateInfo*, const VkAllocationCallbacks*, VkRenderPass*)>(vkGetDeviceProcAddr(device, "vkCreateRenderPass"));
    data->CreateSampler = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkSamplerCreateInfo*, const VkAllocationCallbacks*, VkSampler*)>(vkGetDeviceProcAddr(device, "vkCreateSampler"));
    data->CreateSemaphore = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkSemaphoreCreateInfo*, const VkAllocationCallbacks*, VkSemaphore*)>(vkGetDeviceProcAddr(device, "vkCreateSemaphore"));
    data->CreateShaderModule = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkShaderModuleCreateInfo*, const VkAllocationCallbacks*, VkShaderModule*)>(vkGetDeviceProcAddr(device, "vkCreateShaderModule"));
    data->DestroyBuffer = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkBuffer, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyBuffer"));
    data->DestroyBufferView = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkBufferView, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyBufferView"));
    data->DestroyCommandPool = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkCommandPool, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyCommandPool"));
    data->DestroyDescriptorPool = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkDescriptorPool, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyDescriptorPool"));
    data->DestroyDescriptorSetLayout = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkDescriptorSetLayout, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyDescriptorSetLayout"));
    data->DestroyDevice = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyDevice"));
    data->DestroyEvent = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkEvent, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyEvent"));
    data->DestroyFence = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkFence, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyFence"));
    data->DestroyFramebuffer = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkFramebuffer, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyFramebuffer"));
    data->DestroyImage = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkImage, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyImage"));
    data->DestroyImageView = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkImageView, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyImageView"));
    data->DestroyPipeline = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkPipeline, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyPipeline"));
    data->DestroyPipelineCache = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkPipelineCache, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyPipelineCache"));
    data->DestroyPipelineLayout = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkPipelineLayout, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyPipelineLayout"));
    data->DestroyQueryPool = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkQueryPool, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyQueryPool"));
    data->DestroyRenderPass = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkRenderPass, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyRenderPass"));
    data->DestroySampler = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkSampler, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroySampler"));
    data->DestroySemaphore = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkSemaphore, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroySemaphore"));
    data->DestroyShaderModule = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkShaderModule, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkDestroyShaderModule"));
    data->DeviceWaitIdle = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice)>(vkGetDeviceProcAddr(device, "vkDeviceWaitIdle"));
    data->EndCommandBuffer = reinterpret_cast<VkResult(VKAPI_PTR*)(VkCommandBuffer)>(vkGetDeviceProcAddr(device, "vkEndCommandBuffer"));
    data->FlushMappedMemoryRanges = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, uint32_t, const VkMappedMemoryRange*)>(vkGetDeviceProcAddr(device, "vkFlushMappedMemoryRanges"));
    data->FreeCommandBuffers = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkCommandPool, uint32_t, const VkCommandBuffer*)>(vkGetDeviceProcAddr(device, "vkFreeCommandBuffers"));
    data->FreeDescriptorSets = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkDescriptorPool, uint32_t, const VkDescriptorSet*)>(vkGetDeviceProcAddr(device, "vkFreeDescriptorSets"));
    data->FreeMemory = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkDeviceMemory, const VkAllocationCallbacks*)>(vkGetDeviceProcAddr(device, "vkFreeMemory"));
    data->GetBufferMemoryRequirements = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkBuffer, VkMemoryRequirements*)>(vkGetDeviceProcAddr(device, "vkGetBufferMemoryRequirements"));
    data->GetDeviceMemoryCommitment = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkDeviceMemory, VkDeviceSize*)>(vkGetDeviceProcAddr(device, "vkGetDeviceMemoryCommitment"));
    data->GetDeviceQueue = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, uint32_t, uint32_t, VkQueue*)>(vkGetDeviceProcAddr(device, "vkGetDeviceQueue"));
    data->GetEventStatus = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkEvent)>(vkGetDeviceProcAddr(device, "vkGetEventStatus"));
    data->GetFenceStatus = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkFence)>(vkGetDeviceProcAddr(device, "vkGetFenceStatus"));
    data->GetImageMemoryRequirements = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkImage, VkMemoryRequirements*)>(vkGetDeviceProcAddr(device, "vkGetImageMemoryRequirements"));
    data->GetImageSparseMemoryRequirements = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkImage, uint32_t*, VkSparseImageMemoryRequirements*)>(vkGetDeviceProcAddr(device, "vkGetImageSparseMemoryRequirements"));
    data->GetImageSubresourceLayout = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkImage, const VkImageSubresource*, VkSubresourceLayout*)>(vkGetDeviceProcAddr(device, "vkGetImageSubresourceLayout"));
    data->GetPipelineCacheData = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkPipelineCache, size_t*, void*)>(vkGetDeviceProcAddr(device, "vkGetPipelineCacheData"));
    data->GetQueryPoolResults = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkQueryPool, uint32_t, uint32_t, size_t, void*, VkDeviceSize, VkQueryResultFlags)>(vkGetDeviceProcAddr(device, "vkGetQueryPoolResults"));
    data->GetRenderAreaGranularity = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkRenderPass, VkExtent2D*)>(vkGetDeviceProcAddr(device, "vkGetRenderAreaGranularity"));
    data->InvalidateMappedMemoryRanges = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, uint32_t, const VkMappedMemoryRange*)>(vkGetDeviceProcAddr(device, "vkInvalidateMappedMemoryRanges"));
    data->MapMemory = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkDeviceMemory, VkDeviceSize, VkDeviceSize, VkMemoryMapFlags, void**)>(vkGetDeviceProcAddr(device, "vkMapMemory"));
    data->MergePipelineCaches = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkPipelineCache, uint32_t, const VkPipelineCache*)>(vkGetDeviceProcAddr(device, "vkMergePipelineCaches"));
    data->QueueBindSparse = reinterpret_cast<VkResult(VKAPI_PTR*)(VkQueue, uint32_t, const VkBindSparseInfo*, VkFence)>(vkGetDeviceProcAddr(device, "vkQueueBindSparse"));
    data->QueueSubmit = reinterpret_cast<VkResult(VKAPI_PTR*)(VkQueue, uint32_t, const VkSubmitInfo*, VkFence)>(vkGetDeviceProcAddr(device, "vkQueueSubmit"));
    data->QueueWaitIdle = reinterpret_cast<VkResult(VKAPI_PTR*)(VkQueue)>(vkGetDeviceProcAddr(device, "vkQueueWaitIdle"));
    data->ResetCommandBuffer = reinterpret_cast<VkResult(VKAPI_PTR*)(VkCommandBuffer, VkCommandBufferResetFlags)>(vkGetDeviceProcAddr(device, "vkResetCommandBuffer"));
    data->ResetCommandPool = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkCommandPool, VkCommandPoolResetFlags)>(vkGetDeviceProcAddr(device, "vkResetCommandPool"));
    data->ResetDescriptorPool = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkDescriptorPool, VkDescriptorPoolResetFlags)>(vkGetDeviceProcAddr(device, "vkResetDescriptorPool"));
    data->ResetEvent = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkEvent)>(vkGetDeviceProcAddr(device, "vkResetEvent"));
    data->ResetFences = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, uint32_t, const VkFence*)>(vkGetDeviceProcAddr(device, "vkResetFences"));
    data->SetEvent = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkEvent)>(vkGetDeviceProcAddr(device, "vkSetEvent"));
    data->UnmapMemory = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkDeviceMemory)>(vkGetDeviceProcAddr(device, "vkUnmapMemory"));
    data->UpdateDescriptorSets = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, uint32_t, const VkWriteDescriptorSet*, uint32_t, const VkCopyDescriptorSet*)>(vkGetDeviceProcAddr(device, "vkUpdateDescriptorSets"));
    data->WaitForFences = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, uint32_t, const VkFence*, VkBool32, uint64_t)>(vkGetDeviceProcAddr(device, "vkWaitForFences"));
}

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


/* VK_VERSION_1_0 */
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkAllocateCommandBuffers)(VkDevice, const VkCommandBufferAllocateInfo*, VkCommandBuffer*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkAllocateDescriptorSets)(VkDevice, const VkDescriptorSetAllocateInfo*, VkDescriptorSet*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkAllocateMemory)(VkDevice, const VkMemoryAllocateInfo*, const VkAllocationCallbacks*, VkDeviceMemory*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkBeginCommandBuffer)(VkCommandBuffer, const VkCommandBufferBeginInfo*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkBindBufferMemory)(VkDevice, VkBuffer, VkDeviceMemory, VkDeviceSize) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkBindImageMemory)(VkDevice, VkImage, VkDeviceMemory, VkDeviceSize) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBeginQuery)(VkCommandBuffer, VkQueryPool, uint32_t, VkQueryControlFlags) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBeginRenderPass)(VkCommandBuffer, const VkRenderPassBeginInfo*, VkSubpassContents) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBindDescriptorSets)(VkCommandBuffer, VkPipelineBindPoint, VkPipelineLayout, uint32_t, uint32_t, const VkDescriptorSet*, uint32_t, const uint32_t*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBindIndexBuffer)(VkCommandBuffer, VkBuffer, VkDeviceSize, VkIndexType) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBindPipeline)(VkCommandBuffer, VkPipelineBindPoint, VkPipeline) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBindVertexBuffers)(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBlitImage)(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageBlit*, VkFilter) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdClearAttachments)(VkCommandBuffer, uint32_t, const VkClearAttachment*, uint32_t, const VkClearRect*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdClearColorImage)(VkCommandBuffer, VkImage, VkImageLayout, const VkClearColorValue*, uint32_t, const VkImageSubresourceRange*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdClearDepthStencilImage)(VkCommandBuffer, VkImage, VkImageLayout, const VkClearDepthStencilValue*, uint32_t, const VkImageSubresourceRange*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdCopyBuffer)(VkCommandBuffer, VkBuffer, VkBuffer, uint32_t, const VkBufferCopy*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdCopyBufferToImage)(VkCommandBuffer, VkBuffer, VkImage, VkImageLayout, uint32_t, const VkBufferImageCopy*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdCopyImage)(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageCopy*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdCopyImageToBuffer)(VkCommandBuffer, VkImage, VkImageLayout, VkBuffer, uint32_t, const VkBufferImageCopy*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdCopyQueryPoolResults)(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t, VkBuffer, VkDeviceSize, VkDeviceSize, VkQueryResultFlags) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdDispatch)(VkCommandBuffer, uint32_t, uint32_t, uint32_t) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdDispatchIndirect)(VkCommandBuffer, VkBuffer, VkDeviceSize) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdDraw)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdDrawIndexed)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, int32_t, uint32_t) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdDrawIndexedIndirect)(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdDrawIndirect)(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdEndQuery)(VkCommandBuffer, VkQueryPool, uint32_t) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdEndRenderPass)(VkCommandBuffer) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdExecuteCommands)(VkCommandBuffer, uint32_t, const VkCommandBuffer*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdFillBuffer)(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, uint32_t) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdNextSubpass)(VkCommandBuffer, VkSubpassContents) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdPipelineBarrier)(VkCommandBuffer, VkPipelineStageFlags, VkPipelineStageFlags, VkDependencyFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdPushConstants)(VkCommandBuffer, VkPipelineLayout, VkShaderStageFlags, uint32_t, uint32_t, const void*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdResetEvent)(VkCommandBuffer, VkEvent, VkPipelineStageFlags) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdResetQueryPool)(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdResolveImage)(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageResolve*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetBlendConstants)(VkCommandBuffer, const float [4]) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetDepthBias)(VkCommandBuffer, float, float, float) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetDepthBounds)(VkCommandBuffer, float, float) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetEvent)(VkCommandBuffer, VkEvent, VkPipelineStageFlags) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetLineWidth)(VkCommandBuffer, float) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetScissor)(VkCommandBuffer, uint32_t, uint32_t, const VkRect2D*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetStencilCompareMask)(VkCommandBuffer, VkStencilFaceFlags, uint32_t) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetStencilReference)(VkCommandBuffer, VkStencilFaceFlags, uint32_t) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetStencilWriteMask)(VkCommandBuffer, VkStencilFaceFlags, uint32_t) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetViewport)(VkCommandBuffer, uint32_t, uint32_t, const VkViewport*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdUpdateBuffer)(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, const void*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdWaitEvents)(VkCommandBuffer, uint32_t, const VkEvent*, VkPipelineStageFlags, VkPipelineStageFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdWriteTimestamp)(VkCommandBuffer, VkPipelineStageFlagBits, VkQueryPool, uint32_t) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateBuffer)(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateBufferView)(VkDevice, const VkBufferViewCreateInfo*, const VkAllocationCallbacks*, VkBufferView*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateCommandPool)(VkDevice, const VkCommandPoolCreateInfo*, const VkAllocationCallbacks*, VkCommandPool*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateComputePipelines)(VkDevice, VkPipelineCache, uint32_t, const VkComputePipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateDescriptorPool)(VkDevice, const VkDescriptorPoolCreateInfo*, const VkAllocationCallbacks*, VkDescriptorPool*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateDescriptorSetLayout)(VkDevice, const VkDescriptorSetLayoutCreateInfo*, const VkAllocationCallbacks*, VkDescriptorSetLayout*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateDevice)(VkPhysicalDevice, const VkDeviceCreateInfo*, const VkAllocationCallbacks*, VkDevice*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateEvent)(VkDevice, const VkEventCreateInfo*, const VkAllocationCallbacks*, VkEvent*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateFence)(VkDevice, const VkFenceCreateInfo*, const VkAllocationCallbacks*, VkFence*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateFramebuffer)(VkDevice, const VkFramebufferCreateInfo*, const VkAllocationCallbacks*, VkFramebuffer*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateGraphicsPipelines)(VkDevice, VkPipelineCache, uint32_t, const VkGraphicsPipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateImage)(VkDevice, const VkImageCreateInfo*, const VkAllocationCallbacks*, VkImage*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateImageView)(VkDevice, const VkImageViewCreateInfo*, const VkAllocationCallbacks*, VkImageView*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreatePipelineCache)(VkDevice, const VkPipelineCacheCreateInfo*, const VkAllocationCallbacks*, VkPipelineCache*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreatePipelineLayout)(VkDevice, const VkPipelineLayoutCreateInfo*, const VkAllocationCallbacks*, VkPipelineLayout*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateQueryPool)(VkDevice, const VkQueryPoolCreateInfo*, const VkAllocationCallbacks*, VkQueryPool*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateRenderPass)(VkDevice, const VkRenderPassCreateInfo*, const VkAllocationCallbacks*, VkRenderPass*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateSampler)(VkDevice, const VkSamplerCreateInfo*, const VkAllocationCallbacks*, VkSampler*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateSemaphore)(VkDevice, const VkSemaphoreCreateInfo*, const VkAllocationCallbacks*, VkSemaphore*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateShaderModule)(VkDevice, const VkShaderModuleCreateInfo*, const VkAllocationCallbacks*, VkShaderModule*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyBuffer)(VkDevice, VkBuffer, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyBufferView)(VkDevice, VkBufferView, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyCommandPool)(VkDevice, VkCommandPool, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyDescriptorPool)(VkDevice, VkDescriptorPool, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyDescriptorSetLayout)(VkDevice, VkDescriptorSetLayout, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyDevice)(VkDevice, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyEvent)(VkDevice, VkEvent, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyFence)(VkDevice, VkFence, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyFramebuffer)(VkDevice, VkFramebuffer, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyImage)(VkDevice, VkImage, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyImageView)(VkDevice, VkImageView, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyInstance)(VkInstance, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyPipeline)(VkDevice, VkPipeline, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyPipelineCache)(VkDevice, VkPipelineCache, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyPipelineLayout)(VkDevice, VkPipelineLayout, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyQueryPool)(VkDevice, VkQueryPool, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyRenderPass)(VkDevice, VkRenderPass, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroySampler)(VkDevice, VkSampler, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroySemaphore)(VkDevice, VkSemaphore, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyShaderModule)(VkDevice, VkShaderModule, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkDeviceWaitIdle)(VkDevice) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkEndCommandBuffer)(VkCommandBuffer) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkEnumerateDeviceExtensionProperties)(VkPhysicalDevice, const char*, uint32_t*, VkExtensionProperties*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkEnumerateDeviceLayerProperties)(VkPhysicalDevice, uint32_t*, VkLayerProperties*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkEnumeratePhysicalDevices)(VkInstance, uint32_t*, VkPhysicalDevice*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkFlushMappedMemoryRanges)(VkDevice, uint32_t, const VkMappedMemoryRange*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkFreeCommandBuffers)(VkDevice, VkCommandPool, uint32_t, const VkCommandBuffer*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkFreeDescriptorSets)(VkDevice, VkDescriptorPool, uint32_t, const VkDescriptorSet*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkFreeMemory)(VkDevice, VkDeviceMemory, const VkAllocationCallbacks*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetBufferMemoryRequirements)(VkDevice, VkBuffer, VkMemoryRequirements*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetDeviceMemoryCommitment)(VkDevice, VkDeviceMemory, VkDeviceSize*) = nullptr;
FLEXTVK_EXPORT PFN_vkVoidFunction(VKAPI_PTR *flextvkGetDeviceProcAddr)(VkDevice, const char*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetDeviceQueue)(VkDevice, uint32_t, uint32_t, VkQueue*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkGetEventStatus)(VkDevice, VkEvent) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkGetFenceStatus)(VkDevice, VkFence) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetImageMemoryRequirements)(VkDevice, VkImage, VkMemoryRequirements*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetImageSparseMemoryRequirements)(VkDevice, VkImage, uint32_t*, VkSparseImageMemoryRequirements*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetImageSubresourceLayout)(VkDevice, VkImage, const VkImageSubresource*, VkSubresourceLayout*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetPhysicalDeviceFeatures)(VkPhysicalDevice, VkPhysicalDeviceFeatures*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetPhysicalDeviceFormatProperties)(VkPhysicalDevice, VkFormat, VkFormatProperties*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkGetPhysicalDeviceImageFormatProperties)(VkPhysicalDevice, VkFormat, VkImageType, VkImageTiling, VkImageUsageFlags, VkImageCreateFlags, VkImageFormatProperties*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetPhysicalDeviceMemoryProperties)(VkPhysicalDevice, VkPhysicalDeviceMemoryProperties*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetPhysicalDeviceProperties)(VkPhysicalDevice, VkPhysicalDeviceProperties*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetPhysicalDeviceQueueFamilyProperties)(VkPhysicalDevice, uint32_t*, VkQueueFamilyProperties*) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetPhysicalDeviceSparseImageFormatProperties)(VkPhysicalDevice, VkFormat, VkImageType, VkSampleCountFlagBits, VkImageUsageFlags, VkImageTiling, uint32_t*, VkSparseImageFormatProperties*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkGetPipelineCacheData)(VkDevice, VkPipelineCache, size_t*, void*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkGetQueryPoolResults)(VkDevice, VkQueryPool, uint32_t, uint32_t, size_t, void*, VkDeviceSize, VkQueryResultFlags) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetRenderAreaGranularity)(VkDevice, VkRenderPass, VkExtent2D*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkInvalidateMappedMemoryRanges)(VkDevice, uint32_t, const VkMappedMemoryRange*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkMapMemory)(VkDevice, VkDeviceMemory, VkDeviceSize, VkDeviceSize, VkMemoryMapFlags, void**) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkMergePipelineCaches)(VkDevice, VkPipelineCache, uint32_t, const VkPipelineCache*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkQueueBindSparse)(VkQueue, uint32_t, const VkBindSparseInfo*, VkFence) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkQueueSubmit)(VkQueue, uint32_t, const VkSubmitInfo*, VkFence) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkQueueWaitIdle)(VkQueue) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkResetCommandBuffer)(VkCommandBuffer, VkCommandBufferResetFlags) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkResetCommandPool)(VkDevice, VkCommandPool, VkCommandPoolResetFlags) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkResetDescriptorPool)(VkDevice, VkDescriptorPool, VkDescriptorPoolResetFlags) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkResetEvent)(VkDevice, VkEvent) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkResetFences)(VkDevice, uint32_t, const VkFence*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkSetEvent)(VkDevice, VkEvent) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkUnmapMemory)(VkDevice, VkDeviceMemory) = nullptr;
FLEXTVK_EXPORT void(VKAPI_PTR *flextvkUpdateDescriptorSets)(VkDevice, uint32_t, const VkWriteDescriptorSet*, uint32_t, const VkCopyDescriptorSet*) = nullptr;
FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkWaitForFences)(VkDevice, uint32_t, const VkFence*, VkBool32, uint64_t) = nullptr;

void flextVkInitInstance(VkInstance instance) {

    /* VK_VERSION_1_0 */
    flextvkAllocateCommandBuffers = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkCommandBufferAllocateInfo*, VkCommandBuffer*)>(vkGetInstanceProcAddr(instance, "vkAllocateCommandBuffers"));
    flextvkAllocateDescriptorSets = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkDescriptorSetAllocateInfo*, VkDescriptorSet*)>(vkGetInstanceProcAddr(instance, "vkAllocateDescriptorSets"));
    flextvkAllocateMemory = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkMemoryAllocateInfo*, const VkAllocationCallbacks*, VkDeviceMemory*)>(vkGetInstanceProcAddr(instance, "vkAllocateMemory"));
    flextvkBeginCommandBuffer = reinterpret_cast<VkResult(VKAPI_PTR*)(VkCommandBuffer, const VkCommandBufferBeginInfo*)>(vkGetInstanceProcAddr(instance, "vkBeginCommandBuffer"));
    flextvkBindBufferMemory = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkBuffer, VkDeviceMemory, VkDeviceSize)>(vkGetInstanceProcAddr(instance, "vkBindBufferMemory"));
    flextvkBindImageMemory = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkImage, VkDeviceMemory, VkDeviceSize)>(vkGetInstanceProcAddr(instance, "vkBindImageMemory"));
    flextvkCmdBeginQuery = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkQueryPool, uint32_t, VkQueryControlFlags)>(vkGetInstanceProcAddr(instance, "vkCmdBeginQuery"));
    flextvkCmdBeginRenderPass = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, const VkRenderPassBeginInfo*, VkSubpassContents)>(vkGetInstanceProcAddr(instance, "vkCmdBeginRenderPass"));
    flextvkCmdBindDescriptorSets = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkPipelineBindPoint, VkPipelineLayout, uint32_t, uint32_t, const VkDescriptorSet*, uint32_t, const uint32_t*)>(vkGetInstanceProcAddr(instance, "vkCmdBindDescriptorSets"));
    flextvkCmdBindIndexBuffer = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkDeviceSize, VkIndexType)>(vkGetInstanceProcAddr(instance, "vkCmdBindIndexBuffer"));
    flextvkCmdBindPipeline = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkPipelineBindPoint, VkPipeline)>(vkGetInstanceProcAddr(instance, "vkCmdBindPipeline"));
    flextvkCmdBindVertexBuffers = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*)>(vkGetInstanceProcAddr(instance, "vkCmdBindVertexBuffers"));
    flextvkCmdBlitImage = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageBlit*, VkFilter)>(vkGetInstanceProcAddr(instance, "vkCmdBlitImage"));
    flextvkCmdClearAttachments = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, const VkClearAttachment*, uint32_t, const VkClearRect*)>(vkGetInstanceProcAddr(instance, "vkCmdClearAttachments"));
    flextvkCmdClearColorImage = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkImage, VkImageLayout, const VkClearColorValue*, uint32_t, const VkImageSubresourceRange*)>(vkGetInstanceProcAddr(instance, "vkCmdClearColorImage"));
    flextvkCmdClearDepthStencilImage = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkImage, VkImageLayout, const VkClearDepthStencilValue*, uint32_t, const VkImageSubresourceRange*)>(vkGetInstanceProcAddr(instance, "vkCmdClearDepthStencilImage"));
    flextvkCmdCopyBuffer = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkBuffer, uint32_t, const VkBufferCopy*)>(vkGetInstanceProcAddr(instance, "vkCmdCopyBuffer"));
    flextvkCmdCopyBufferToImage = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkImage, VkImageLayout, uint32_t, const VkBufferImageCopy*)>(vkGetInstanceProcAddr(instance, "vkCmdCopyBufferToImage"));
    flextvkCmdCopyImage = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageCopy*)>(vkGetInstanceProcAddr(instance, "vkCmdCopyImage"));
    flextvkCmdCopyImageToBuffer = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkImage, VkImageLayout, VkBuffer, uint32_t, const VkBufferImageCopy*)>(vkGetInstanceProcAddr(instance, "vkCmdCopyImageToBuffer"));
    flextvkCmdCopyQueryPoolResults = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t, VkBuffer, VkDeviceSize, VkDeviceSize, VkQueryResultFlags)>(vkGetInstanceProcAddr(instance, "vkCmdCopyQueryPoolResults"));
    flextvkCmdDispatch = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, uint32_t, uint32_t)>(vkGetInstanceProcAddr(instance, "vkCmdDispatch"));
    flextvkCmdDispatchIndirect = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkDeviceSize)>(vkGetInstanceProcAddr(instance, "vkCmdDispatchIndirect"));
    flextvkCmdDraw = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t)>(vkGetInstanceProcAddr(instance, "vkCmdDraw"));
    flextvkCmdDrawIndexed = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, int32_t, uint32_t)>(vkGetInstanceProcAddr(instance, "vkCmdDrawIndexed"));
    flextvkCmdDrawIndexedIndirect = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t)>(vkGetInstanceProcAddr(instance, "vkCmdDrawIndexedIndirect"));
    flextvkCmdDrawIndirect = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t)>(vkGetInstanceProcAddr(instance, "vkCmdDrawIndirect"));
    flextvkCmdEndQuery = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkQueryPool, uint32_t)>(vkGetInstanceProcAddr(instance, "vkCmdEndQuery"));
    flextvkCmdEndRenderPass = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer)>(vkGetInstanceProcAddr(instance, "vkCmdEndRenderPass"));
    flextvkCmdExecuteCommands = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, const VkCommandBuffer*)>(vkGetInstanceProcAddr(instance, "vkCmdExecuteCommands"));
    flextvkCmdFillBuffer = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, uint32_t)>(vkGetInstanceProcAddr(instance, "vkCmdFillBuffer"));
    flextvkCmdNextSubpass = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkSubpassContents)>(vkGetInstanceProcAddr(instance, "vkCmdNextSubpass"));
    flextvkCmdPipelineBarrier = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkPipelineStageFlags, VkPipelineStageFlags, VkDependencyFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*)>(vkGetInstanceProcAddr(instance, "vkCmdPipelineBarrier"));
    flextvkCmdPushConstants = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkPipelineLayout, VkShaderStageFlags, uint32_t, uint32_t, const void*)>(vkGetInstanceProcAddr(instance, "vkCmdPushConstants"));
    flextvkCmdResetEvent = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkEvent, VkPipelineStageFlags)>(vkGetInstanceProcAddr(instance, "vkCmdResetEvent"));
    flextvkCmdResetQueryPool = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t)>(vkGetInstanceProcAddr(instance, "vkCmdResetQueryPool"));
    flextvkCmdResolveImage = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageResolve*)>(vkGetInstanceProcAddr(instance, "vkCmdResolveImage"));
    flextvkCmdSetBlendConstants = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, const float [4])>(vkGetInstanceProcAddr(instance, "vkCmdSetBlendConstants"));
    flextvkCmdSetDepthBias = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, float, float, float)>(vkGetInstanceProcAddr(instance, "vkCmdSetDepthBias"));
    flextvkCmdSetDepthBounds = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, float, float)>(vkGetInstanceProcAddr(instance, "vkCmdSetDepthBounds"));
    flextvkCmdSetEvent = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkEvent, VkPipelineStageFlags)>(vkGetInstanceProcAddr(instance, "vkCmdSetEvent"));
    flextvkCmdSetLineWidth = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, float)>(vkGetInstanceProcAddr(instance, "vkCmdSetLineWidth"));
    flextvkCmdSetScissor = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, uint32_t, const VkRect2D*)>(vkGetInstanceProcAddr(instance, "vkCmdSetScissor"));
    flextvkCmdSetStencilCompareMask = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkStencilFaceFlags, uint32_t)>(vkGetInstanceProcAddr(instance, "vkCmdSetStencilCompareMask"));
    flextvkCmdSetStencilReference = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkStencilFaceFlags, uint32_t)>(vkGetInstanceProcAddr(instance, "vkCmdSetStencilReference"));
    flextvkCmdSetStencilWriteMask = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkStencilFaceFlags, uint32_t)>(vkGetInstanceProcAddr(instance, "vkCmdSetStencilWriteMask"));
    flextvkCmdSetViewport = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, uint32_t, const VkViewport*)>(vkGetInstanceProcAddr(instance, "vkCmdSetViewport"));
    flextvkCmdUpdateBuffer = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, const void*)>(vkGetInstanceProcAddr(instance, "vkCmdUpdateBuffer"));
    flextvkCmdWaitEvents = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, uint32_t, const VkEvent*, VkPipelineStageFlags, VkPipelineStageFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*)>(vkGetInstanceProcAddr(instance, "vkCmdWaitEvents"));
    flextvkCmdWriteTimestamp = reinterpret_cast<void(VKAPI_PTR*)(VkCommandBuffer, VkPipelineStageFlagBits, VkQueryPool, uint32_t)>(vkGetInstanceProcAddr(instance, "vkCmdWriteTimestamp"));
    flextvkCreateBuffer = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*)>(vkGetInstanceProcAddr(instance, "vkCreateBuffer"));
    flextvkCreateBufferView = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkBufferViewCreateInfo*, const VkAllocationCallbacks*, VkBufferView*)>(vkGetInstanceProcAddr(instance, "vkCreateBufferView"));
    flextvkCreateCommandPool = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkCommandPoolCreateInfo*, const VkAllocationCallbacks*, VkCommandPool*)>(vkGetInstanceProcAddr(instance, "vkCreateCommandPool"));
    flextvkCreateComputePipelines = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkPipelineCache, uint32_t, const VkComputePipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*)>(vkGetInstanceProcAddr(instance, "vkCreateComputePipelines"));
    flextvkCreateDescriptorPool = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkDescriptorPoolCreateInfo*, const VkAllocationCallbacks*, VkDescriptorPool*)>(vkGetInstanceProcAddr(instance, "vkCreateDescriptorPool"));
    flextvkCreateDescriptorSetLayout = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkDescriptorSetLayoutCreateInfo*, const VkAllocationCallbacks*, VkDescriptorSetLayout*)>(vkGetInstanceProcAddr(instance, "vkCreateDescriptorSetLayout"));
    flextvkCreateDevice = reinterpret_cast<VkResult(VKAPI_PTR*)(VkPhysicalDevice, const VkDeviceCreateInfo*, const VkAllocationCallbacks*, VkDevice*)>(vkGetInstanceProcAddr(instance, "vkCreateDevice"));
    flextvkCreateEvent = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkEventCreateInfo*, const VkAllocationCallbacks*, VkEvent*)>(vkGetInstanceProcAddr(instance, "vkCreateEvent"));
    flextvkCreateFence = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkFenceCreateInfo*, const VkAllocationCallbacks*, VkFence*)>(vkGetInstanceProcAddr(instance, "vkCreateFence"));
    flextvkCreateFramebuffer = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkFramebufferCreateInfo*, const VkAllocationCallbacks*, VkFramebuffer*)>(vkGetInstanceProcAddr(instance, "vkCreateFramebuffer"));
    flextvkCreateGraphicsPipelines = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkPipelineCache, uint32_t, const VkGraphicsPipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*)>(vkGetInstanceProcAddr(instance, "vkCreateGraphicsPipelines"));
    flextvkCreateImage = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkImageCreateInfo*, const VkAllocationCallbacks*, VkImage*)>(vkGetInstanceProcAddr(instance, "vkCreateImage"));
    flextvkCreateImageView = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkImageViewCreateInfo*, const VkAllocationCallbacks*, VkImageView*)>(vkGetInstanceProcAddr(instance, "vkCreateImageView"));
    flextvkCreatePipelineCache = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkPipelineCacheCreateInfo*, const VkAllocationCallbacks*, VkPipelineCache*)>(vkGetInstanceProcAddr(instance, "vkCreatePipelineCache"));
    flextvkCreatePipelineLayout = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkPipelineLayoutCreateInfo*, const VkAllocationCallbacks*, VkPipelineLayout*)>(vkGetInstanceProcAddr(instance, "vkCreatePipelineLayout"));
    flextvkCreateQueryPool = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkQueryPoolCreateInfo*, const VkAllocationCallbacks*, VkQueryPool*)>(vkGetInstanceProcAddr(instance, "vkCreateQueryPool"));
    flextvkCreateRenderPass = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkRenderPassCreateInfo*, const VkAllocationCallbacks*, VkRenderPass*)>(vkGetInstanceProcAddr(instance, "vkCreateRenderPass"));
    flextvkCreateSampler = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkSamplerCreateInfo*, const VkAllocationCallbacks*, VkSampler*)>(vkGetInstanceProcAddr(instance, "vkCreateSampler"));
    flextvkCreateSemaphore = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkSemaphoreCreateInfo*, const VkAllocationCallbacks*, VkSemaphore*)>(vkGetInstanceProcAddr(instance, "vkCreateSemaphore"));
    flextvkCreateShaderModule = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkShaderModuleCreateInfo*, const VkAllocationCallbacks*, VkShaderModule*)>(vkGetInstanceProcAddr(instance, "vkCreateShaderModule"));
    flextvkDestroyBuffer = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkBuffer, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyBuffer"));
    flextvkDestroyBufferView = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkBufferView, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyBufferView"));
    flextvkDestroyCommandPool = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkCommandPool, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyCommandPool"));
    flextvkDestroyDescriptorPool = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkDescriptorPool, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyDescriptorPool"));
    flextvkDestroyDescriptorSetLayout = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkDescriptorSetLayout, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyDescriptorSetLayout"));
    flextvkDestroyDevice = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyDevice"));
    flextvkDestroyEvent = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkEvent, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyEvent"));
    flextvkDestroyFence = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkFence, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyFence"));
    flextvkDestroyFramebuffer = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkFramebuffer, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyFramebuffer"));
    flextvkDestroyImage = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkImage, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyImage"));
    flextvkDestroyImageView = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkImageView, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyImageView"));
    flextvkDestroyInstance = reinterpret_cast<void(VKAPI_PTR*)(VkInstance, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyInstance"));
    flextvkDestroyPipeline = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkPipeline, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyPipeline"));
    flextvkDestroyPipelineCache = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkPipelineCache, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyPipelineCache"));
    flextvkDestroyPipelineLayout = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkPipelineLayout, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyPipelineLayout"));
    flextvkDestroyQueryPool = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkQueryPool, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyQueryPool"));
    flextvkDestroyRenderPass = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkRenderPass, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyRenderPass"));
    flextvkDestroySampler = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkSampler, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroySampler"));
    flextvkDestroySemaphore = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkSemaphore, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroySemaphore"));
    flextvkDestroyShaderModule = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkShaderModule, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkDestroyShaderModule"));
    flextvkDeviceWaitIdle = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice)>(vkGetInstanceProcAddr(instance, "vkDeviceWaitIdle"));
    flextvkEndCommandBuffer = reinterpret_cast<VkResult(VKAPI_PTR*)(VkCommandBuffer)>(vkGetInstanceProcAddr(instance, "vkEndCommandBuffer"));
    flextvkEnumerateDeviceExtensionProperties = reinterpret_cast<VkResult(VKAPI_PTR*)(VkPhysicalDevice, const char*, uint32_t*, VkExtensionProperties*)>(vkGetInstanceProcAddr(instance, "vkEnumerateDeviceExtensionProperties"));
    flextvkEnumerateDeviceLayerProperties = reinterpret_cast<VkResult(VKAPI_PTR*)(VkPhysicalDevice, uint32_t*, VkLayerProperties*)>(vkGetInstanceProcAddr(instance, "vkEnumerateDeviceLayerProperties"));
    flextvkEnumeratePhysicalDevices = reinterpret_cast<VkResult(VKAPI_PTR*)(VkInstance, uint32_t*, VkPhysicalDevice*)>(vkGetInstanceProcAddr(instance, "vkEnumeratePhysicalDevices"));
    flextvkFlushMappedMemoryRanges = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, uint32_t, const VkMappedMemoryRange*)>(vkGetInstanceProcAddr(instance, "vkFlushMappedMemoryRanges"));
    flextvkFreeCommandBuffers = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkCommandPool, uint32_t, const VkCommandBuffer*)>(vkGetInstanceProcAddr(instance, "vkFreeCommandBuffers"));
    flextvkFreeDescriptorSets = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkDescriptorPool, uint32_t, const VkDescriptorSet*)>(vkGetInstanceProcAddr(instance, "vkFreeDescriptorSets"));
    flextvkFreeMemory = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkDeviceMemory, const VkAllocationCallbacks*)>(vkGetInstanceProcAddr(instance, "vkFreeMemory"));
    flextvkGetBufferMemoryRequirements = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkBuffer, VkMemoryRequirements*)>(vkGetInstanceProcAddr(instance, "vkGetBufferMemoryRequirements"));
    flextvkGetDeviceMemoryCommitment = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkDeviceMemory, VkDeviceSize*)>(vkGetInstanceProcAddr(instance, "vkGetDeviceMemoryCommitment"));
    flextvkGetDeviceProcAddr = reinterpret_cast<PFN_vkVoidFunction(VKAPI_PTR*)(VkDevice, const char*)>(vkGetInstanceProcAddr(instance, "vkGetDeviceProcAddr"));
    flextvkGetDeviceQueue = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, uint32_t, uint32_t, VkQueue*)>(vkGetInstanceProcAddr(instance, "vkGetDeviceQueue"));
    flextvkGetEventStatus = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkEvent)>(vkGetInstanceProcAddr(instance, "vkGetEventStatus"));
    flextvkGetFenceStatus = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkFence)>(vkGetInstanceProcAddr(instance, "vkGetFenceStatus"));
    flextvkGetImageMemoryRequirements = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkImage, VkMemoryRequirements*)>(vkGetInstanceProcAddr(instance, "vkGetImageMemoryRequirements"));
    flextvkGetImageSparseMemoryRequirements = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkImage, uint32_t*, VkSparseImageMemoryRequirements*)>(vkGetInstanceProcAddr(instance, "vkGetImageSparseMemoryRequirements"));
    flextvkGetImageSubresourceLayout = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkImage, const VkImageSubresource*, VkSubresourceLayout*)>(vkGetInstanceProcAddr(instance, "vkGetImageSubresourceLayout"));
    flextvkGetPhysicalDeviceFeatures = reinterpret_cast<void(VKAPI_PTR*)(VkPhysicalDevice, VkPhysicalDeviceFeatures*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFeatures"));
    flextvkGetPhysicalDeviceFormatProperties = reinterpret_cast<void(VKAPI_PTR*)(VkPhysicalDevice, VkFormat, VkFormatProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFormatProperties"));
    flextvkGetPhysicalDeviceImageFormatProperties = reinterpret_cast<VkResult(VKAPI_PTR*)(VkPhysicalDevice, VkFormat, VkImageType, VkImageTiling, VkImageUsageFlags, VkImageCreateFlags, VkImageFormatProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceImageFormatProperties"));
    flextvkGetPhysicalDeviceMemoryProperties = reinterpret_cast<void(VKAPI_PTR*)(VkPhysicalDevice, VkPhysicalDeviceMemoryProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceMemoryProperties"));
    flextvkGetPhysicalDeviceProperties = reinterpret_cast<void(VKAPI_PTR*)(VkPhysicalDevice, VkPhysicalDeviceProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties"));
    flextvkGetPhysicalDeviceQueueFamilyProperties = reinterpret_cast<void(VKAPI_PTR*)(VkPhysicalDevice, uint32_t*, VkQueueFamilyProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyProperties"));
    flextvkGetPhysicalDeviceSparseImageFormatProperties = reinterpret_cast<void(VKAPI_PTR*)(VkPhysicalDevice, VkFormat, VkImageType, VkSampleCountFlagBits, VkImageUsageFlags, VkImageTiling, uint32_t*, VkSparseImageFormatProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSparseImageFormatProperties"));
    flextvkGetPipelineCacheData = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkPipelineCache, size_t*, void*)>(vkGetInstanceProcAddr(instance, "vkGetPipelineCacheData"));
    flextvkGetQueryPoolResults = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkQueryPool, uint32_t, uint32_t, size_t, void*, VkDeviceSize, VkQueryResultFlags)>(vkGetInstanceProcAddr(instance, "vkGetQueryPoolResults"));
    flextvkGetRenderAreaGranularity = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkRenderPass, VkExtent2D*)>(vkGetInstanceProcAddr(instance, "vkGetRenderAreaGranularity"));
    flextvkInvalidateMappedMemoryRanges = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, uint32_t, const VkMappedMemoryRange*)>(vkGetInstanceProcAddr(instance, "vkInvalidateMappedMemoryRanges"));
    flextvkMapMemory = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkDeviceMemory, VkDeviceSize, VkDeviceSize, VkMemoryMapFlags, void**)>(vkGetInstanceProcAddr(instance, "vkMapMemory"));
    flextvkMergePipelineCaches = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkPipelineCache, uint32_t, const VkPipelineCache*)>(vkGetInstanceProcAddr(instance, "vkMergePipelineCaches"));
    flextvkQueueBindSparse = reinterpret_cast<VkResult(VKAPI_PTR*)(VkQueue, uint32_t, const VkBindSparseInfo*, VkFence)>(vkGetInstanceProcAddr(instance, "vkQueueBindSparse"));
    flextvkQueueSubmit = reinterpret_cast<VkResult(VKAPI_PTR*)(VkQueue, uint32_t, const VkSubmitInfo*, VkFence)>(vkGetInstanceProcAddr(instance, "vkQueueSubmit"));
    flextvkQueueWaitIdle = reinterpret_cast<VkResult(VKAPI_PTR*)(VkQueue)>(vkGetInstanceProcAddr(instance, "vkQueueWaitIdle"));
    flextvkResetCommandBuffer = reinterpret_cast<VkResult(VKAPI_PTR*)(VkCommandBuffer, VkCommandBufferResetFlags)>(vkGetInstanceProcAddr(instance, "vkResetCommandBuffer"));
    flextvkResetCommandPool = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkCommandPool, VkCommandPoolResetFlags)>(vkGetInstanceProcAddr(instance, "vkResetCommandPool"));
    flextvkResetDescriptorPool = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkDescriptorPool, VkDescriptorPoolResetFlags)>(vkGetInstanceProcAddr(instance, "vkResetDescriptorPool"));
    flextvkResetEvent = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkEvent)>(vkGetInstanceProcAddr(instance, "vkResetEvent"));
    flextvkResetFences = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, uint32_t, const VkFence*)>(vkGetInstanceProcAddr(instance, "vkResetFences"));
    flextvkSetEvent = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkEvent)>(vkGetInstanceProcAddr(instance, "vkSetEvent"));
    flextvkUnmapMemory = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, VkDeviceMemory)>(vkGetInstanceProcAddr(instance, "vkUnmapMemory"));
    flextvkUpdateDescriptorSets = reinterpret_cast<void(VKAPI_PTR*)(VkDevice, uint32_t, const VkWriteDescriptorSet*, uint32_t, const VkCopyDescriptorSet*)>(vkGetInstanceProcAddr(instance, "vkUpdateDescriptorSets"));
    flextvkWaitForFences = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, uint32_t, const VkFence*, VkBool32, uint64_t)>(vkGetInstanceProcAddr(instance, "vkWaitForFences"));
}

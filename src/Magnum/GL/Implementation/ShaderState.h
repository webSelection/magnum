#ifndef Magnum_GL_Implementation_ShaderState_h
#define Magnum_GL_Implementation_ShaderState_h
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

#include "Magnum/Types.h"
#include "Magnum/configure.h"
#include "Magnum/GL/OpenGL.h"

namespace Magnum { namespace Implementation {

struct ShaderState {
    explicit ShaderState():
        maxVertexOutputComponents{}, maxFragmentInputComponents{},
        #if !defined(MAGNUM_TARGET_GLES2) && !defined(MAGNUM_TARGET_WEBGL)
        maxTessellationControlInputComponents{}, maxTessellationControlOutputComponents{}, maxTessellationControlTotalOutputComponents{}, maxTessellationEvaluationInputComponents{}, maxTessellationEvaluationOutputComponents{}, maxGeometryInputComponents{}, maxGeometryOutputComponents{}, maxGeometryTotalOutputComponents{}, maxAtomicCounterBuffers{}, maxCombinedAtomicCounterBuffers{}, maxAtomicCounters{}, maxCombinedAtomicCounters{}, maxImageUniforms{}, maxCombinedImageUniforms{}, maxShaderStorageBlocks{}, maxCombinedShaderStorageBlocks{},
        #endif
        maxTextureImageUnits{}, maxTextureImageUnitsCombined{},
        #ifndef MAGNUM_TARGET_GLES2
        maxUniformBlocks{}, maxCombinedUniformBlocks{},
        #endif
        maxUniformComponents{}, maxUniformComponentsCombined{}
        #ifndef MAGNUM_TARGET_GLES2
        , maxCombinedUniformComponents{}
        #endif
        {}

    enum: std::size_t {
        #if !defined(MAGNUM_TARGET_GLES2) && !defined(MAGNUM_TARGET_WEBGL)
        StageCount = 4
        #else
        StageCount = 2
        #endif
    };

    GLint maxVertexOutputComponents,
        maxFragmentInputComponents;
    #if !defined(MAGNUM_TARGET_GLES2) && !defined(MAGNUM_TARGET_WEBGL)
    GLint maxTessellationControlInputComponents,
        maxTessellationControlOutputComponents,
        maxTessellationControlTotalOutputComponents,
        maxTessellationEvaluationInputComponents,
        maxTessellationEvaluationOutputComponents,
        maxGeometryInputComponents,
        maxGeometryOutputComponents,
        maxGeometryTotalOutputComponents;
    GLint maxAtomicCounterBuffers[StageCount];
    GLint maxCombinedAtomicCounterBuffers;
    GLint maxAtomicCounters[StageCount];
    GLint maxCombinedAtomicCounters;
    GLint maxImageUniforms[StageCount];
    GLint maxCombinedImageUniforms;
    GLint maxShaderStorageBlocks[StageCount];
    GLint maxCombinedShaderStorageBlocks;
    #endif
    GLint maxTextureImageUnits[StageCount];
    GLint maxTextureImageUnitsCombined;
    #ifndef MAGNUM_TARGET_GLES2
    GLint maxUniformBlocks[StageCount];
    GLint maxCombinedUniformBlocks;
    #endif
    GLint maxUniformComponents[StageCount];
    GLint maxUniformComponentsCombined;
    #ifndef MAGNUM_TARGET_GLES2
    GLint maxCombinedUniformComponents[StageCount];
    #endif
};

}}

#endif

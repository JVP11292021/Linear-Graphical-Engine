/*
 ________________________________________________________________________________________
| This source code is from the Github repo: Linear Graphical Engine (LGE)                |
|  Created by: JVP11292021 (J. van Polanen)                                              |
|  Started on: 06-01-2023                                                                |
|                                                                                        |
| Copyright (c) Jessy van Polanen                                                        |
|                                                                                        |
| NOTICE:                                                                                |
|   This notice must remain at the top of each file.                                     |
|________________________________________________________________________________________|
*/

#ifndef __LGE_FLY_CAMERA__
#define __LGE_FLY_CAMERA__

#include "engine_setup.h"
#include "lgeCamUtils.hpp"
#include "lgeCamConstants.hpp"

#include <../lmm/lmm.h>

_LGE_BEGIN_NP_LGE_GFX
  
class LGE_API FlyCam {
private:
    // FlyCamera Attributes
    lmm::vec3 position;
    lmm::vec3 front;
    lmm::vec3 up;
    lmm::vec3 right;
    lmm::vec3 worldUp;
    
    // euler Angles
    f32 yaw;
    f32 pitch;

    // FlyCamera options
    f32 movementSpeed;
    f32 mouseSensitivity;
    f32 zoom;

public:
    FlyCam(const lmm::vec3& = lmm::vec3(0.0f, 0.0f, 0.0f), const lmm::vec3& = lmm::vec3(0.0f, 1.0f, 0.0f), f32 = YAW, f32 = PITCH);
    FlyCam(f32, f32, f32, f32, f32, f32, f32, f32);

    /// <summary>
    /// Returns the view matrix calculated using Euler Angles and the LookAt Matrix
    /// </summary>
    /// <returns>lmm::mat4</returns>
    LGE_CUDA_FUNC_DECL lmm::mat4 getViewMatrix();

    /// <summary>
    ///  Processes input received from any keyboard-like input system. Accepts input parameter in the form of FlyCamera defined ENUM (to abstract it from windowing systems)
    /// </summary>
    /// <param name="direction"></param>
    /// <param name="deltaTime"></param>
    /// <returns>void</returns>
    LGE_CUDA_FUNC_DECL void processKeyboard(Camera_Movement, f32);

    /// <summary>
    /// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    /// </summary>
    /// <param name="xoffset"></param>
    /// <param name="yoffset"></param>
    /// <param name="constrainPitch"></param>
    /// <returns>void</returns>
    LGE_CUDA_FUNC_DECL void processMouseMovement(f32, f32, bool = LGE_TRUE);

    /// <summary>
    /// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    /// </summary>
    /// <param name="yoffset"></param>
    /// <returns>void</returns>
    LGE_CUDA_FUNC_DECL void processMouseScroll(f32);

    LGE_CUDA_FUNC_DECL LGE_INLINE lmm::vec3 getPosition() const { return this->position; }
    LGE_CUDA_FUNC_DECL LGE_INLINE lmm::vec3 getFront() const { return this->front; }
    LGE_CUDA_FUNC_DECL LGE_INLINE lmm::vec3 getUp() const { return this->up; }
    LGE_CUDA_FUNC_DECL LGE_INLINE lmm::vec3 getRight() const { return this->right; }
    LGE_CUDA_FUNC_DECL LGE_INLINE lmm::vec3 getWorldUp() const { return this->worldUp; }

    LGE_CUDA_FUNC_DECL LGE_INLINE void setPosition(const lmm::vec3& position) { this->position = position; }
    LGE_CUDA_FUNC_DECL LGE_INLINE void setFront(const lmm::vec3& front) { this->front = front; }
    LGE_CUDA_FUNC_DECL LGE_INLINE void setUp(const lmm::vec3& up) { this->up = up; }
    LGE_CUDA_FUNC_DECL LGE_INLINE void setRight(const lmm::vec3& right) { this->right = right; }
    LGE_CUDA_FUNC_DECL LGE_INLINE void setWorldUp(const lmm::vec3& worldUp) { this->worldUp = worldUp; }

    LGE_CUDA_FUNC_DECL LGE_INLINE f32 getYaw() const { return this->yaw; }
    LGE_CUDA_FUNC_DECL LGE_INLINE f32 getPitch() const { return this->pitch; }
    LGE_CUDA_FUNC_DECL LGE_INLINE f32 getMovementSpeed() const { return this->movementSpeed; }
    LGE_CUDA_FUNC_DECL LGE_INLINE f32 getMouseSensitivity() const { return this->mouseSensitivity; }
    LGE_CUDA_FUNC_DECL LGE_INLINE f32 getZoom() const { return this->zoom; }

    LGE_CUDA_FUNC_DECL LGE_INLINE void setYaw(f32 yaw) { this->yaw = yaw; }
    LGE_CUDA_FUNC_DECL LGE_INLINE void setPitch(f32 pitch) { this->pitch = pitch; }
    LGE_CUDA_FUNC_DECL LGE_INLINE void setMovementSpeed(f32 movementSpeed) { this->movementSpeed = movementSpeed; }
    LGE_CUDA_FUNC_DECL LGE_INLINE void setMouseSensitivity(f32 mouseSensitivity) { this->mouseSensitivity = movementSpeed; }
    LGE_CUDA_FUNC_DECL LGE_INLINE void setZoom(f32 zoom) { this->zoom = zoom; }

private:
    /// <summary>
    /// Calculates the front vector from the FlyCamera's (updated) Euler Angles
    /// </summary>
    /// <returns></returns>
    LGE_CUDA_FUNC_DECL void updateCameraVectors();
};

_LGE_END_NP_LGE_GFX

#endif
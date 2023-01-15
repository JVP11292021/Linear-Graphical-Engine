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

#include "lgeFlyCam.hpp"

_LGE_BEGIN_NP_LGE_GFX

FlyCam::FlyCam(const lmm::vec3& position, const lmm::vec3& up, f32 yaw, f32 pitch)
    : front(lmm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), zoom(FOV)
{
    this->position = position;
    this->worldUp = up;
    this->yaw = yaw;
    this->pitch = pitch;
}

FlyCam::FlyCam(f32 posX, f32 posY, f32 posZ, f32 upX, f32 upY, f32 upZ, f32 yaw, f32 pitch)
    : front(lmm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), zoom(FOV)
{
    this->position = lmm::vec3(posX, posY, posZ);
    this->worldUp = lmm::vec3(upX, upY, upZ);
    this->yaw = yaw;
    this->pitch = pitch;
    this->updateCameraVectors();
}

LGE_CUDA_FUNC_DECL lmm::mat4 FlyCam::getViewMatrix() {
    return lmm::lookAt(position, position + front, up);
}

LGE_CUDA_FUNC_DECL void FlyCam::processKeyboard(Camera_Movement direction, f32 deltaTime) {
    f32 velocity = this->movementSpeed * deltaTime;
    if (direction == FORWARD)
        this->position += front * velocity;
    if (direction == BACKWARD)
        this->position -= front * velocity;
    if (direction == LEFT)
        this->position -= right * velocity;
    if (direction == RIGHT)
        this->position += right * velocity;
}

LGE_CUDA_FUNC_DECL void FlyCam::processMouseMovement(f32 xoffset, f32 yoffset, bool constrainPitch) {
    xoffset *= this->mouseSensitivity;
    yoffset *= this->mouseSensitivity;

    this->yaw += xoffset;
    this->pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch) {
        if (this->pitch > 89.0f)
            this->pitch = 89.0f;
        if (this->pitch < -89.0f)
            this->pitch = -89.0f;
    }

    // update front, right and up Vectors using the updated Euler angles
    this->updateCameraVectors();
}

LGE_CUDA_FUNC_DECL void FlyCam::processMouseScroll(f32 yoffset) {
    this->zoom -= (f32)yoffset;
    if (this->zoom < 1.0f)
        this->zoom = 1.0f;
    if (this->zoom > 45.0f)
        this->zoom = 45.0f;
}

LGE_CUDA_FUNC_DECL void FlyCam::updateCameraVectors() {
    // calculate the new front vector
    lmm::vec3 front;
    front.x = lmm::cos_t(lmm::radians(this->yaw)) * lmm::cos_t(lmm::radians(this->pitch));
    front.y = lmm::sin_t(lmm::radians(this->pitch));
    front.z = lmm::sin_t(lmm::radians(this->yaw)) * lmm::cos_t(lmm::radians(this->pitch));
    front = lmm::normalize(front);
    // also re-calculate the right and up vector
    this->right = lmm::normalize(lmm::cross(front, this->worldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    this->up = lmm::normalize(lmm::cross(this->right, front));
}

_LGE_END_NP_LGE_GFX
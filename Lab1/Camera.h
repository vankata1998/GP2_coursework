#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

struct Camera
{
public:
	Camera() {}

	void initializeCamera(const glm::vec3& pos, float fov, float aspect, float nearClip, float farClip)
	{
		this->pos = pos;
		this->forward = glm::vec3(0.0f, 0.0f, 1.0f);
		this->up = glm::vec3(0.0f, 1.0f, 0.0f);
		this->projection = glm::perspective(fov, aspect, nearClip, farClip);
	}

	glm::vec3 getPos()
	{
		return this->pos;
	}

	inline glm::mat4 GetViewProjection() const
	{
		glm::mat4 view = glm::lookAt(pos, pos + forward, up);
		return projection * view;//pos of camera, position camera is pointing (vector), up (vector)
	}

protected:
private:
	glm::mat4 projection;
	glm::vec3 pos;
	glm::vec3 forward;
	glm::vec3 up;
};



#define GLM_ENABLE_EXPERIMENTAL
#ifndef TRANSFORM_H
#define TRANSFORM_H



#include <glm.hpp>
#include <gtx\transform.hpp>

using namespace glm;

class Transform
{

private:
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;
public:
	Transform(vec3 pos = vec3(), vec3 rot = vec3(), vec3 scale = vec3(1))
	{
		m_position = pos;
		m_rotation = rot;
		m_scale = scale;
	}
	~Transform()
	{}

	glm::vec3 GetPosition()
	{
		return m_position;
	}

	vec3& GetRotation()
	{
		return m_rotation;
	}

	glm::vec3 GetScale()
	{
		return m_scale;
	}

	void SetPosition(glm::vec3 newPosition)
	{
		m_position = newPosition;

	}

	void SetRotation(glm::vec3 newRotation)
	{
		m_rotation = newRotation;
	}

	void SetScale(glm::vec3 newScale)
	{
		m_scale = newScale;
	}

	inline glm::mat4 GetModel() const
	{
		mat4 posMatrix = translate(m_position);
		mat4 rotXMatrix = rotate(m_rotation.x, glm::vec3(1, 0, 0));
		mat4 rotYMatrix = rotate(m_rotation.y, glm::vec3(0, 1, 0));
		mat4 rotZMatrix = rotate(m_rotation.z, glm::vec3(0, 0, 1));
		mat4 scaleMatrix = scale(m_scale);

		mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

		return posMatrix * rotMatrix * scaleMatrix;
	}


};



#endif

#pragma once

#include "Lsst.h"

class Shader 
{
public:
	uint32_t ID;

	Shader() = default;
	Shader& Use();

	void Compile(const char*, const char*, const char*);

	void SetFloat(const char*, float, bool);
	void SetInteger(const char*, int, bool);
	void SetVector2f(const char*, float, float, bool);
	void SetVector2f(const char*, const glm::vec2&, bool);
	void SetVector3f(const char*, float, float, float, bool);
	void SetVector3f(const char*, const glm::vec3&, bool);
	void SetVector4f(const char*, float, float, float, float, bool);
	void SetVector4f(const char*, const glm::vec4&, bool);
	void SetMatrix4(const char*, const glm::mat4&, bool);
private:
	void checkCompileErrors(uint32_t, std::string);
};
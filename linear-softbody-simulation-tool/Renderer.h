#pragma once

#include "Shader.h"

class Renderer
{
public:
	Renderer(Shader&);
	~Renderer();

	void Draw(glm::vec2, glm::vec2, float, glm::vec3);

private:
	Shader m_shader;
	uint32_t m_vao;

	void initRenderData();
};
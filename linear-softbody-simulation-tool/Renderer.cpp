#include "Renderer.h"

Renderer::Renderer(Shader& shader, std::vector<float>& vertices)
{
	this->m_shader = shader;
	this->vertex_data = vertices;

	this->InitRenderData();
}

Renderer::~Renderer() 
{
	glDeleteVertexArrays(1, &this->m_vao);
}

void Renderer::Draw(glm::vec3 position, glm::vec3 size, float rotate, glm::vec3 color)
{
	this->m_shader.Use();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(position));
    model = glm::rotate(model, glm::radians(rotate), glm::vec3(1.0f, 0.3f, 0.5f));
	model = glm::scale(model, glm::vec3(size));

    glm::mat4 view = glm::mat4(1.0f); 
    glm::mat4 projection = glm::mat4(1.0f);

    projection = glm::perspective(glm::radians(45.0f), (float)1024 /( (float)1024/16*9), 0.1f, 100.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -50.0f));

    this->m_shader.SetMatrix4("view", view, true);
    this->m_shader.SetMatrix4("projection", projection, true);
	this->m_shader.SetVector3f("spriteColor", color, true);
	this->m_shader.SetMatrix4("model", model, true);

	glBindVertexArray(this->m_vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

void Renderer::InitRenderData()
{
	uint32_t vbo;

	glGenVertexArrays(1, &this->m_vao);
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertex_data.size(), vertex_data.data(), GL_STATIC_DRAW);

	glBindVertexArray(this->m_vao);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glEnable(GL_DEPTH_TEST);
}

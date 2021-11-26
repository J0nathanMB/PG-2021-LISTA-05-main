#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// GLAD
#include <glad/glad.h>

// GLFW
#include <GLFW/glfw3.h>

#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Object
{
public:
	Object() {};
	~Object();

	void initialize();
	void update();
	void draw();

	inline void setTexture(GLuint texID) { this->texID = texID; };
	inline void setShader(Shader* shader) { this->shader = shader; };
	inline void setPosition(glm::vec3 position) { this->position = position; };
	inline void setDimensions(glm::vec3 scale) { this->scale = scale; };
	inline void setAngle(float angle) { this->angle = angle; };

private:
	void setRotation(float angle, glm::vec3 axis, bool reset = false);
	void setTranslation(glm::vec3 displacements, bool reset = false);
	void setScale(glm::vec3 scaleFactors, bool reset = false);

	GLuint VAO;
	glm::mat4 transform;
	GLuint texID;
	Shader* shader;
	glm::vec3 position, scale;
	float angle;
};


#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

class Camera {
public:

	Camera();

	virtual ~Camera(); ///< @brief Destructor of an Entity

	void computeMatricesFromInputs(GLFWwindow* window);
	glm::mat4 getViewMatrix();
	glm::vec3 getCursor();

private:
	glm::mat4 _viewMatrix;
	// Initial position : on +Z
	glm::vec3 position;
	glm::vec3 cursor;
	float speed;

};



#endif

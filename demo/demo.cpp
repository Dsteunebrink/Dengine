// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <dengine/renderer.h>
#include <dengine/camera.h>
#include <dengine/entity.h>
#include <dengine/sprite.h>

int main( void )
{
	Renderer renderer(1280, 720);

	Camera* camera = new Camera();

	Entity* pencils = new Entity();
	Entity* kingkong = new Entity();
	Entity* rgba = new Entity();

	pencils->position = glm::vec3(400, 300, 0);
	kingkong->position = glm::vec3(900, 400, 0);
	rgba->position = glm::vec3(renderer.width() / 2, renderer.height() / 2, 0);

	pencils->addSprite("assets/pencils.tga");
	kingkong->addSprite("assets/kingkong.tga");
	rgba->addSprite("assets/rgba.tga");

	do {
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
		camera->computeMatricesFromInputs(renderer.window());

		//glm::vec3 cursor = getCursor(); // from Camera
		//printf("(%f,%f)\n",cursor.x, cursor.y);

		// Render all Entit (Entity* entity, Camera* camera, float px, float py, float sx, float sy, float rot)
		renderer.renderEntity(pencils, camera);
		renderer.renderEntity(kingkong, camera);
		renderer.renderEntity(rgba, camera);

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(renderer.window()) == 0 );

	delete pencils;
	delete kingkong;
	delete rgba;
	delete camera;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

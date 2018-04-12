#ifndef ENTITY_H
#define ENTITY_H

#include <GL/glew.h>
#include <glfw3.h>

#include <iostream>
#include <string>
#include <vector>

#include <glm/glm.hpp>

#include <dengine/sprite.h>
#include <dengine/camera.h>

class Entity {
public:
	Entity(); ///< @brief Constructor of an Entity
	virtual ~Entity(); ///< @brief Destructor of an Entity

	/// @brief update this Entity. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	 /// @return void
	virtual void update(float deltaTime) {};

	// transform
	glm::vec3 position; /**< @brief The position of the Entity */
	glm::vec3 rotation; /**< @brief The rotation of the Entity */
	glm::vec3 scale; /**< @brief The scale of the Entity */

	// sprite
	/// @brief get the Sprite from this Entity.
	/// @return Sprite* _sprite
	Sprite* sprite() { return _sprite; };
	/// @brief add a Sprite to this Entity by Sprite*.
	/// @param spr A pointer to a Sprite.
	/// @return void
	void addSprite(Sprite* spr);
	/// @brief add a Sprite to this Entity by filename.
	/// @param filename The filename of the image you want to add as a Sprite.
	/// @return void
	void addSprite(const std::string& filename);
	/// @brief add a Sprite to this Entity.
	/// @param filename The filename of the image you want to add as a Sprite.
	/// @param pivotx The x component of the pivotpoint.
	/// @param pivoty The y component of the pivotpoint.
	/// @return void
	void addSprite(const std::string& filename, float pivotx, float pivoty);

	friend class Renderer;

private:

	// sprite
	Sprite* _sprite; ///< @brief The _sprite of this Entity

	void deleteSprite() {
		if (_sprite != NULL) {
			delete _sprite;
			_sprite = NULL;
		}
	};
};

#endif // !ENTITY_H

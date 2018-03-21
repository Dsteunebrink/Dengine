#ifndef ENTITY_H
#define ENTITY_H

#include <GL/glew.h>
#include <glfw3.h>

#include <iostream>
#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtx/matrix_decompose.hpp>

#include <dengine/sprite.h>
#include <dengine/dengineconfig.h>

class Entity {
public:
	Entity(); ///< @brief Constructor of an Entity
	virtual ~Entity(); ///< @brief Destructor of an Entity

	/// @brief update this Entity. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	 /// @return void
	virtual void update(float deltaTime) = 0;

	// transform
	glm::vec3 position; /**< @brief The position of the Entity */
	glm::vec3 rotation; /**< @brief The rotation of the Entity */
	glm::vec3 scale; /**< @brief The scale of the Entity */

	// data structure
	/// @brief add an Entity as a child of this Entity.
	/// Defines the data structure (parent/children relationship)
	/// @param child The Entity you want to add as a child.
	/// @return void
	void addChild(Entity* child);

	/// @brief remove this Entity from list of children.
	/// @param child The Entity you want to remove from your children.
	/// @return void
	void removeChild(Entity* child);

	Entity* getChild(unsigned int i);
	/// @brief get the list of children.
	/// @return std::vector<Entity*>& _children
	const std::vector<Entity*>& children() { return _children; };

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

	/// @brief get the parent of this Entity.
	/// @return Entity* _parent
	Entity* parent() { return _parent; };

	friend class Renderer;

private:
	Entity* _parent; ///< @brief The _parent of this Entity
	std::vector<Entity*> _children; ///< @brief The _children of this Entity

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

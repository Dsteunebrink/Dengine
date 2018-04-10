#include <iostream>

#include <dengine/entity.h>
#include <dengine/dengineconfig.h>

Entity::Entity() {
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);
	_sprite = NULL;
}

Entity::~Entity() {
	
}

void Entity::addSprite(Sprite* spr)
{
	deleteSprite();
	_sprite = new Sprite();
	*_sprite = *spr;
}

void Entity::addSprite(const std::string& filename)
{
	this->addSprite(filename, 0.5f, 0.5f);
}

void Entity::addSprite(const std::string& filename, float pivotx, float pivoty)
{
	deleteSprite();
	_sprite = new Sprite(filename);
	_sprite->setupSprite(filename, pivotx, pivoty, 1.0f, 1.0f, DEFAULTFILTER, DEFAULTWRAP); // trilinear filter, mirror repeat
}
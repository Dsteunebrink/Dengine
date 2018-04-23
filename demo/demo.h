#ifndef DEMO_H
#define DEMO_H

#include <dengine/entity.h>

class Demo : public Entity {
public:
	Demo();

	virtual ~Demo();

	virtual void update(float deltaTime);
};

#endif // !DEMO_H

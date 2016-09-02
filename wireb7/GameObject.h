#pragma once

class GameObject
{
public:
	int entityId;

	virtual void Update() = 0;
};
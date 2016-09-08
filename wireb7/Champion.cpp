#include "Champion.h"

void Champion::Update()
{
	GameObject::Update();
	HP -= 2.0f;
}
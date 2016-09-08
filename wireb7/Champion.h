#pragma once

#include "GameObject.h"
#include "Wire.h"

class Champion : public GameObject
{
public:
	DECLARE_CLASS(Champion)
	int EntityGlobalUniqueId = 2;
public:
	Champion() {
	}
	virtual void Initialise() {
		dataTableManager = new DataTableManager(gameObjectCounter + 1, EntityGlobalUniqueId);
		entityId = gameObjectCounter++;
		HP = 0.0f;
	}
	virtual void Update();

public:
	WIREDVAR(float, HP);
};
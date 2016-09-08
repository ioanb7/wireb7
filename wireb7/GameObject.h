#pragma once

#include "Wire.h"
#include "DataTableManager.h"

class GameObject
{
public:
	DECLARE_CLASS(GameObject)
	int EntityGlobalUniqueId = 1;
public:
	static int gameObjectCounter;
public:
	static DataTableManager *dataTableManager;
	GameObject()
	{
	}

	virtual void Initialise() {
		dataTableManager = new DataTableManager(gameObjectCounter + 1, EntityGlobalUniqueId);
		entityId = gameObjectCounter++;
	}

	virtual void Update() {}

protected:
	WIREDVAR(int, entityId);
};
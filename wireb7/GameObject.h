#pragma once

#include "DataTableManager.h"
#include "NetworkUtils.h"

class GameObject
{
public:
	int EntityGlobalUniqueId = 1;
public:
	static int gameObjectCounter;
public:
	DataTableManager *dataTableManager = NULL;
	GameObject()
	{
		dataTableManager = NULL;
		isFlying = false;
		posX = 0.0f;
	}

	virtual void Initialise() {
		if(dataTableManager == NULL) 
			dataTableManager = new DataTableManager(gameObjectCounter + 1, EntityGlobalUniqueId);
		entityId = gameObjectCounter++;
		dataTableManager->Add(0, Type::_int, &entityId);
		dataTableManager->Add(1, Type::_bool, &isFlying);
		dataTableManager->Add(2, Type::_float, &posX);
	}

	virtual void Update() {
		NCHANGE(isFlying, !isFlying);

		if (isFlying == true) {
			isFlying = false;
			N0CHANGED(isFlying);
		}
	}

protected:
	int entityId;
	bool isFlying;
	float posX;
};
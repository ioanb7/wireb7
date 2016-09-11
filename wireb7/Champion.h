#pragma once


#include "GameObject.h"
#include "NetworkUtils.h"

class Champion : public GameObject
{
public:
	int EntityGlobalUniqueId = 2;
public:
	Champion() : GameObject(){
		HP = 0.0f;
	}
	virtual void Initialise() {
		if (dataTableManager == NULL)
			dataTableManager = new DataTableManager(gameObjectCounter + 1, EntityGlobalUniqueId);
		entityId = gameObjectCounter++;
		GameObject::Initialise();
		dataTableManager->Add(10, Type::_float, &HP);
		NCHANGE(HP, HP - 0.0f);
	}
	virtual void Update()
	{
		NCHANGE(HP, HP - 1.0f);
	}

public:
	float HP;
};
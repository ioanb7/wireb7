#pragma once


#include "Champion.h"
#include "NetworkUtils.h"

class FlyingChampion : public Champion
{
public:
	int EntityGlobalUniqueId = 3;
public:
	FlyingChampion() : Champion() {
		IsDropping = false;
	}
	virtual void Initialise() {
		if (dataTableManager == NULL)
			dataTableManager = new DataTableManager(gameObjectCounter + 1, EntityGlobalUniqueId);
		entityId = gameObjectCounter++;
		dataTableManager->Add(40, Type::_bool, &IsDropping);
		IsDropping = true;
		N0CHANGED(IsDropping);
	}
	virtual void Update();

public:
	bool IsDropping;
};
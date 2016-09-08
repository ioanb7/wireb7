#pragma once

#include "Champion.h"
#include "Wire.h"

class FlyingChampion : public Champion
{
public:
	DECLARE_CLASS(FlyingChampion)
	int EntityGlobalUniqueId = 3;
public:
	FlyingChampion() {
	}
	virtual void Initialise() {
		dataTableManager = new DataTableManager(gameObjectCounter + 1, EntityGlobalUniqueId);
		entityId = gameObjectCounter++;
		IsFlying = true;
	}
	virtual void Update();

public:
	WIREDVAR(bool, IsFlying);
};
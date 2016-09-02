#pragma once

#include "GameObject.h"
#include "Wire.h"

class Champion : public GameObject
{
public:
	virtual void Update();

public:
	WIREDVAR(float, HP);
};
#include "FlyingChampion.h"

void FlyingChampion::Update()
{
	Champion::Update();
	IsFlying = !IsFlying;
}
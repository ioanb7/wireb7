#include "FlyingChampion.h"

void FlyingChampion::Update()
{
	Champion::Update();
	IsDropping = !IsDropping;
	N0CHANGED(IsDropping);

}
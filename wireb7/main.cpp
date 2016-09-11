#include "Champion.h"
#include "FlyingChampion.h"
//#include "WireVar.h"
#include "Packeter.h"
#include "GameObject.h"
#include <iostream>

int main() {
	Champion champion;
	Champion champion2;
	FlyingChampion flyingChamp;

	champion.Initialise();
	champion2.Initialise();
	flyingChamp.Initialise();

	champion.Update();
	champion2.Update();
	flyingChamp.Update();

	champion2.Update();

	GameObject go;
	go.Initialise();
	go.Update();

	system("pause");
}
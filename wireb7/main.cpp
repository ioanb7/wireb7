#include "Champion.h"
#include "FlyingChampion.h"
#include "WireVar.h"
#include "Packeter.h"
#include <iostream>

int main() {

	if (false) {
		FlyingChampion flyingChamp;
		flyingChamp.Initialise();
		flyingChamp.Update();
	}
	else {
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
	}

	system("pause");
}
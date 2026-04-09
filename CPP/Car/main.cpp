#include <iostream>
#include "car.h"

int main(){
		car meinPorsche("Porsche", "GT3RS", 2022, 67);
		meinPorsche.drive(1500);
		std::cout << "\nFahrzeuginfo:\n";
		meinPorsche.displayInfo();

		return 0;
}

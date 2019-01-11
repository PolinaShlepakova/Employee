#include "employee.h"
#include <iostream>

int main() {
	Employee employee("Rick", "Deckard", "Blade runner");
	std::cout << employee << std::endl;
	employee.showAll();
	std::cout << std::endl;

	Manager manager("Harry", "Bryant", "Captain", 5);
	std::cout << manager << std::endl;
	manager.showAll();
	std::cout << std::endl;

	Fink fink("Leon", "Kowalski", "Cargo loader", "Roy Batty");
	std::cout << fink << std::endl;
	fink.showAll();
	std::cout << std::endl;

	HighFink highFink(manager, "Eduardo Gaff");
	highFink.showAll();
	std::cout << std::endl;

	HighFink highFink2;
	highFink2.setAll();
	std::cout << std::endl;

	std::cout << "Using an AbstractEmployee * pointer:" << std::endl;
	AbstractEmployee* tri[4] = {&employee, &fink, &highFink, &highFink2};
	for (auto& i : tri) {
		i->showAll();
		std::cout << std::endl;
	}
	return 0;
}

#include "employee.h"

AbstractEmployee::AbstractEmployee() :
		first_name_(),
		last_name_(),
		job_() {}

AbstractEmployee::AbstractEmployee(const std::string& fn, const std::string& ln, const std::string& j) :
		first_name_(fn),
		last_name_(ln),
		job_(j) {}

void AbstractEmployee::showAll() const {
	std::cout << "First name: " << first_name_ << std::endl;
	std::cout << "Last name: " << last_name_ << std::endl;
	std::cout << "Job: " << job_ << std::endl;
}

void AbstractEmployee::setAll() {
	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name_);
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name_);
	std::cout << "Enter job: ";
	std::getline(std::cin, job_);
}

std::ostream& operator<<(std::ostream& os, const AbstractEmployee& e) {
	return os << e.first_name_ << " " << e.last_name_;
}

AbstractEmployee::~AbstractEmployee() = default;

Employee::Employee() : AbstractEmployee() {}

Employee::Employee(const std::string& fn, const std::string& ln, const std::string& j) : AbstractEmployee(fn, ln, j) {}

void Employee::showAll() const {
	AbstractEmployee::showAll();
}

void Employee::setAll() {
	AbstractEmployee::setAll();
}

Manager::Manager() : AbstractEmployee(), in_charge_of_() {}

Manager::Manager(const std::string& fn, const std::string& ln, const std::string& j, int ico) :
		AbstractEmployee(fn, ln, j), in_charge_of_(ico) {}

Manager::Manager(const AbstractEmployee& e, int ico) : AbstractEmployee(e), in_charge_of_(ico) {}

Manager::Manager(const Manager& m) : AbstractEmployee(m), in_charge_of_(m.inChargeOf()) {}

void Manager::showAll() const {
	AbstractEmployee::showAll();
	std::cout << "In charge of " << inChargeOf() << " employees" << std::endl;
}

void Manager::setAll() {
	AbstractEmployee::setAll();
	std::cout << "Enter number of employees manager is in charge of: ";
	std::cin >> in_charge_of_;
}

Fink::Fink() : AbstractEmployee(), reports_to_() {}

Fink::Fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo) :
		AbstractEmployee(fn, ln, j), reports_to_(rpo) {}

Fink::Fink(const AbstractEmployee& e, const std::string& rpo) : AbstractEmployee(e), reports_to_(rpo) {}

Fink::Fink(const Fink& e) : AbstractEmployee(e), reports_to_(e.reportsTo()) {}

void Fink::showAll() const {
	AbstractEmployee::showAll();
	std::cout << "Reports to " << reportsTo() << std::endl;
}

void Fink::setAll() {
	AbstractEmployee::setAll();
	std::cout << "Enter person who fink reports to: ";
	std::getline(std::cin, reports_to_);
}

HighFink::HighFink() : AbstractEmployee(), Manager(), Fink() {}

HighFink::HighFink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo,
				   int ico) : AbstractEmployee(fn, ln, j), Manager(fn, ln, j, ico), Fink(fn, ln, j, rpo) {}

HighFink::HighFink(const AbstractEmployee& e, const std::string& rpo, int ico) :
		AbstractEmployee(e), Manager(e, ico), Fink(e, rpo) {}

HighFink::HighFink(const Fink& f, int ico) : AbstractEmployee(f), Fink(f), Manager(f, ico) {}

HighFink::HighFink(const Manager& m, const std::string& rpo) : AbstractEmployee(m), Manager(m), Fink(m, rpo) {}

HighFink::HighFink(const HighFink& h) : AbstractEmployee(h), Manager(h), Fink(h) {}

void HighFink::showAll() const {
	Fink::showAll();
	std::cout << "In charge of " << inChargeOf() << " employees" << std::endl;
}

void HighFink::setAll() {
	Fink::setAll();
	std::cout << "Enter number of employees manager is in charge of: ";
	int ico = 0;
	std::cin >> ico;
	setInChargeOf(ico);
}


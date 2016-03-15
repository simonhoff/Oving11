#pragma once

#include <iostream>

class Person{
private:
	std::string firstName;
	std::string surName;
public:
	Person();
	Person(std::string first, std::string sur);
	std::string getFirstName() const;
	std::string getSurName() const;
	bool operator<(const Person &rhs) const;
	bool operator>(const Person &rhs) const;
	bool operator==(const Person &rhs) const;

};

std::ostream &operator<<(std::ostream &out, Person &rhs);

#include <cstdlib>
#include <iostream>
#include "person.h"

using namespace std;

Person::Person(){
	firstName = "";
	surName = " ";
}

Person::Person(string first, string sur){
	firstName = first;
	surName = sur;
}
	
string Person::getFirstName() const{
	return firstName;
}

string Person::getSurName() const{
	return surName;
}

bool Person::operator<(const Person &rhs) const{
	if (this->getSurName() < rhs.getSurName()){
		return true;
	}else if (this->getSurName() == rhs.getSurName()){
		if (this->getFirstName() < rhs.getFirstName()){
			return true;
		}
	}else{
		return false;
	}
}

bool Person::operator>(const Person &rhs) const{
	if (this->getSurName() > rhs.getSurName()){	
		return true;
	}else if (this->getSurName() == rhs.getSurName()){
		if (this->getFirstName() > rhs.getFirstName()){
			return true;
		}
	}else{
		return false;
	}
}
bool Person::operator==(const Person &rhs) const{
	return (this->getFirstName() == rhs.getFirstName() && this->getSurName() == rhs.getSurName());
}

ostream &operator<<(ostream &out, Person &rhs){
	out << rhs.getFirstName() << " " << rhs.getSurName() << " ";
	return out;
}
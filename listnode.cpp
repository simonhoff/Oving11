#include <cstdlib>
#include <iostream>

#include "listnode.h"

using namespace std;

ListNode(const string& value){
	this->value = value;
	this->next = NULL;
}

const std::string& getValue() const{
	return value;
}

ListNode* getNext() const{
	return next;
}
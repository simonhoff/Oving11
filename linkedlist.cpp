#include <cstdlib>
#include <iostream>
#include <new>
#include <string>
#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList(){
	head = nullptr;
	last = nullptr;
}

LinkedList::~LinkedList(){
	ListNode *current, *next;
	current = head;
	while (next != last){
		next = current->next;
		delete current;
		current = next;
	}
	delete last;
}

bool LinkedList::isEmpty() const{
	if (this->head == nullptr) return true;
	else return false;
}

void LinkedList::insertAtFront(const string & elem){
	if (isEmpty()){
		head = last = new ListNode(elem);
	}else{
		ListNode *oldHead = this->head;
		this->head = new ListNode(elem);
		this->head->next = oldHead;
	}
}

void LinkedList::insertAtBack(const string & elem){
	if (isEmpty()){
		head = last = new ListNode(elem);
	}else{
		last->next = new ListNode(elem);
		this->last = this->last->next;
	}
}

bool LinkedList::removeFromFront(string & output){
	if (this->isEmpty()) return false;
	else{
		ListNode *newHead = this->head->next;
		output = this->head->value;
		delete this->head;
		head = newHead;
		return true;
	}
}

bool LinkedList::removeFromBack(string & output){
	if (this->isEmpty()) return false;
	else{
		ListNode *previous, *current;
		current = this->head;
		while (current != last){
			previous = current;
			current = current->next;
		}
		output = this->last->value;
		previous->next = NULL;
		delete this->last;
		this->last = previous;
		return true;
	}
}

ListNode* LinkedList::search(const string &value){
	ListNode* current = this->head;
	if (this->head->value == value) return this->head;
	while (current != this->last){
		current = current->next;
		if (current->value == value){
			return current;
		}
	}
	return NULL;
}

void LinkedList::remove(const string &value){
	//check head and last
	string temp;
	while (this->head->value == value || this->last->value == value){
		if (this->head->value == value) removeFromFront(temp);
		if (this->last->value == value) removeFromBack(temp);
	}
	//check inside the list
	ListNode *current, *previous;
	current = this->head->next;
	previous = this->head;
	while (current != this->last){
		if (current->value == value){
			previous->next = current->next;
			delete current;
			current = previous->next;
		}else{
			previous = current;
			current = current->next;
		}
	}
}

ostream& operator<<(ostream &stream, const LinkedList & list ){
	stream << "List" << endl;
	int counter = 0;
	ListNode *node = list.head;
	while (node != list.last){
		stream << node->getValue() << "  ";
		node = node->getNext();
		counter++;
		if (counter==4){
			stream << endl;
			counter = 0;
		}
	}
	stream << list.last->getValue() << endl;
	return stream;
}

ListNode::ListNode(const string& value){
	this->value = value;
	this->next = NULL;
}

const string& ListNode::getValue() const{
	return value;
}

ListNode* ListNode::getNext() const{
	return next;
}
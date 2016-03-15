#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include "source.h"
#include "replace.h"
#include "simpleset.h"
#include "person.h"
#include "test.h"
#include "linkedlist.h"

using namespace std;

void test1(){
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	shuffle(&a[0], 7); // Resultat, rekkefolgen i a er endret.
	double b[] = {1.2, 2.2, 3.2, 4.2};
	shuffle(b, 4);
	string c[] = {"one", "two", "three", "four"};
	shuffle(c, 4);
	for (int i = 0; i < 4; i++){
		cout << c[i] << endl;
	}
}

void test2(){

}

void test3(){
	vector<string> strVec;
	strVec.push_back("Lorem");
	strVec.push_back("Ipsum");
	strVec.push_back("Dolor");
	strVec.push_back("Sit");
	strVec.push_back("Amet");
	strVec.push_back("Consecteur");
	typedef vector<string>::iterator it_type;
	for (it_type i = strVec.begin(); i != strVec.end(); i++){
		cout << *i << endl;
	}
	vector<string>::reverse_iterator revIt;
	replace(strVec, "Ipsum", "flipsum");
	for (revIt = strVec.rbegin(); revIt != strVec.rend(); revIt++){
		cout << *revIt << endl;
	}
}

void test4(){
	list<Person> people;
	Person ASD("yy","yy");
	Person QWERTY("zz", "zz");
	Person A("Simen", "Fondevik");
	Person B("Frida", "Viset");
	Person C("Marius", "Rundhovde");
	Person D("Marte", "Myrvold");
	insertSorted(people, QWERTY);
	insertSorted(people, ASD);
	insertSorted(people, A);
	insertSorted(people, B);
	insertSorted(people, C);
	insertSorted(people, D);
	list<Person>::iterator i;
	for (i = people.begin(); i != people.end(); i++){
		cout << *i << endl;
	}
}

void test6(){
	LinkedList dictionary;
	cout <<"declared" << endl;
	dictionary.insertAtFront("has");
	dictionary.insertAtFront("Frida");
	cout << dictionary << endl;
	dictionary.insertAtFront("Little");
	dictionary.insertAtBack("a");
	dictionary.insertAtBack("cat");
	dictionary.insertAtBack("which");
	dictionary.insertAtBack("is");
	dictionary.insertAtBack("named");
	dictionary.insertAtBack("Marius");
	cout << dictionary << endl;
}
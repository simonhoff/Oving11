#include <cstdlib>
#include <list>
#include "source.h"
#include "person.h"

using namespace std;

void insertSorted(list<Person> &people, Person x){
	cout << x << endl;
	if (people.empty()) people.push_back(x);
	else{
		list<Person>::iterator i = people.begin();
		while (x > *i && i != people.end()){
			i++;
		}
		if (i != people.end()) people.insert(i,x);
		else people.push_back(x);
	}
}
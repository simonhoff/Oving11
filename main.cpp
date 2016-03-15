#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <string>
#include "source.h"
#include "replace.h"
#include "simpleset.h"
#include "person.h"
#include "test.h"

using namespace std;

int main(){
	srand(time(NULL));
	cout << "1. Tests task 1,2 \n2. Tests task 3 \n3. Task 4 \n4. Task 5 \n5. Task 6 \n6. task 7 \n0. End Program" << endl;
	int choice; cin >> choice;
	switch (choice){
		case 1:
			test1();
			break;
		case 2:
		//simpleset
		case 3:
			test3();
			break;
		case 4:
			test4();
			break;
		case 5:
			//set
			break;
		case 6:
			test6();
			break;
	}
	return 0;
}
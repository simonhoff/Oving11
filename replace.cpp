#include <iostream>
#include <string>
#include <vector>
#include "replace.h"

using namespace std;

void replace(vector<string> &strVec, string str, string replacement){
	vector<string>::iterator i;
	for (i = strVec.begin(); i != strVec.end(); i++){
		if (*i == str){
			strVec.erase(i);
			strVec.insert(i, replacement);
		}
	}
}
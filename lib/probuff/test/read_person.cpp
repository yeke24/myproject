
#include <iostream>

#include "person.pb.h"

#include <fstream>

#include <string>

 

using namespace std;

 

int main(){

	tutorial::Person *person = new tutorial::Person;

	char buffer[BUFSIZ];

	fstream input("myfile",ios::in|ios::binary);

	input.read(buffer,sizeof(tutorial::Person));

	person->ParseFromString(buffer);  //用这个方法，通常不用ParseFromString

	cout << person->name()<< endl;

	return 0;

}


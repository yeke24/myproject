#include <iostream>

#include "person.pb.h"

#include <fstream>

#include <string>

 

using namespace std;

 

int main(){

	string buffer;

	tutorial::Person person;

	person.set_name("chemical");

	person.set_id(29);

	person.set_email("ygliang2009@gmail.com");

	//person.add_phone("abc");

	//person.add_phone("def");

	fstream output("myfile",ios::out|ios::binary);

	person.SerializeToString(&buffer); //用这个方法，通常不用SerializeToOstream

	output.write(buffer.c_str(),buffer.size());

	return 0;

}


#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
ofstream fout;
fout.open("out.txt",ios::binary);
if(fout.fail())
	cout<<"out.txt open fail."<<endl;
else
	cout<<"out.txt open success."<<endl;
fout<<"ilovec++"<<"\n";
fout.close();

ifstream fin;
fin.open("out.txt",ios::binary);
string str;
fin>>str;
cout<<str<<endl;
fin.close();

return 0;
}

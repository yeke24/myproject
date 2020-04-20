#include<iostream>
#include<fstream>

using namespace std;

int  main()
{
ofstream out("out.txt",ios::out|ios::in);

if(out.is_open())
{
	out.seekp(21,ios::beg);
	out.write("world",6);
}
else
	cout<<"out.txt not here."<<endl;
out.close();

ifstream fin("out.txt");
fin.seekg(0,ios::end);
streampos ps=fin.tellg();
cout<<"文件长度为："<<ps<<endl;
fin.close();

return 0;
}


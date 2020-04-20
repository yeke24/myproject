#include <iostream>

 

using namespace std;

 

 

class XYZ

{

public:

    void putPri();

    static int ipub;

private:

    static int ipri;

};

 

 

void XYZ::putPri()

{

    cout << ipri++ << endl;

}

 


int XYZ::ipub = 1;

int XYZ::ipri = 1;

 

main()

{

    XYZ aaa;

    XYZ bbb;

 

    aaa.putPri();

    cout << aaa.ipub << endl;

    bbb.putPri();

}


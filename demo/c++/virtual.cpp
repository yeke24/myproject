#include <iostream>

using namespace std;

struct base{

       public:

              virtual void print(){cout<<"base fun/n";}

       private:

               string basename;

       };

      

struct derived:base{

       public :

              void print(){cout<<"derived fun/n";}

       };

      
int main(){

    base bobj;

    b.print();

    base *bp1=&bobj;

    bp1->print();

    base& br1=bobj;

    br1.print();

    derived dobj;

    base *bp2=&dobj;

    bp2->print();

    base& br2=dobj;

    br2.print();

    cin.get();

}
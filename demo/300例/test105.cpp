#include<iostream>
using namespace std;

class Cun_A
{
public:
	Cun_A(double x, double y,double z)
	{
		acer_veget=x;
		acer_fruit=y;
		acer_grain=z;
	}

	void SetPerProduct(double a, double b,double c)
	{
		output_per_acerV=a;
		output_per_acerF=b;
		output_per_acerG=c;
	}

	void veget()
	{
		double result=acer_veget*output_per_acerV;		
		cout<<"该村的蔬菜产量为:"<<result<<endl;
	}

	void fruit()
	{
		cout<<"该村的水果产量为:"<<acer_fruit*output_per_acerF<<endl;
	}

	void grain()
	{
		cout<<"该村的稻谷的产量为:"<<acer_grain*output_per_acerG<<endl;
	}

private:
	double acer_veget;
	double output_per_acerV;
	double acer_fruit;
	double output_per_acerF;
	double acer_grain;
	double output_per_acerG;
};

int main()
{
Cun_A A(1.2,2,3);

cout<<"A村"<<endl;

A.SetPerProduct(500,400,700);
A.veget();
A.fruit();
A.grain();

Cun_A b(A);
cout<<"b村"<<endl;
b.SetPerProduct(400,300,600);
b.veget();
b.fruit();
b.grain();

return 0;
}

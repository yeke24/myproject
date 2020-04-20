#include<iostream>
using namespace std;

class Cun_product
{
public:
	Cun_product(){veget_result=0;fruit_result=0;grain_result=0;}
	Cun_product(double x,double y,double z)
	{
		veget_result=x;
		fruit_result=y;
		grain_result=z;
	}

	~Cun_product(){}

	friend Cun_product operator+(Cun_product cun1,Cun_product cun2);

	void output()
	{
		cout<<veget_result<<","<<fruit_result<<","<<grain_result<<endl;
	}

private:
	double veget_result;
	double fruit_result;
	double grain_result;
};

Cun_product operator+(Cun_product cun1,Cun_product cun2)
{
	Cun_product add;
	add.veget_result=cun1.veget_result+cun2.veget_result;
	add.fruit_result=cun1.fruit_result+cun2.fruit_result;
	add.grain_result=cun1.grain_result+cun2.grain_result;
	return add;
}

int main()
{

Cun_product cun_A(1.2,3,4),cun_B(2.3,5,1),cun_C(1.4,3,2),cun;
cun=cun_A+cun_B+cun_C;

cout<<"abc村总共的蔬菜、水果、稻谷的产量分别为："<<endl;
cun.output();

return 0;
}

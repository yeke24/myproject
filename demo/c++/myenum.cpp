#include<iostream>

using namespace std;

enum Day{MON=1, TUE, WED, THU, FRI, SAT, SUN};

class myday
{
public:
	myday():day(MON){};
	myday(Day d):day(d){};
	~myday(){};

	bool operator == (const myday& d)
    {
        return ( d.day == this->day );
    }

    bool operator != (const myday& d)
    {
        return !this->operator==(d);
    }

    bool operator < (const myday& d)
    {
    	return ( this->day < d.day );
    }

public:
		void SetDay(Day d);
		enum Day GetDay();

private:
		Day day;
};

void myday::SetDay(Day d)
{
	day=d;
}

enum Day myday::GetDay()
{
	return day;
}

int main()
{
	myday md;

	if( MON == md.GetDay() )
		cout<<md.GetDay()<<endl;

	md.SetDay(FRI);
	cout<<md.GetDay()<<endl;
	
	return 0;
}
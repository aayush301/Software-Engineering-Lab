// To develop test cases using boundary value analysis for the area of a triangle.
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class TestCase
{
	public:
	int x,y,z;
	float expectedOutput;
	TestCase(int x, int y, int z, float exp)
	{
		this->x=x;
		this->y=y;
		this->z=z;
		this->expectedOutput=exp;
	}
	
};

int main()
{
	cout<<"\n\n------- Boundary value analysis test cases ------------\n\n";
	
	int lower,upper;
	cout<<"Enter lower bound and upper bound:\n";
	cin>>lower>>upper;
	
	int mid = (lower+upper)/2;
	vector<TestCase>testCases;
	vector<int>arr = {lower, lower+1, upper-1, upper};
	
	int i=0;
	for(int count=1; count<=13; count++)
	{
		int x,y,z;
		if(count<=4)
			x=mid, y=mid, z=arr[i];
		else if(count<=8)
			x=mid, y=arr[i], z=mid;
		else if(count<=12)
			x=arr[i], y=mid, z=mid;
		else
			x=mid, y=mid, z=mid;
		
		i = (i+1)%4;
		
		float area = -1;
		float s = (float)(x+y+z)/2;
		if(s>=x and s>=y and s>=z)
		{
			area = sqrt(s*(s-x)*(s-y)*(s-z));
		}
		
		testCases.push_back(TestCase(x,y,z,area));
	}
	
	
	cout<<"\nTest cases are:\n";
	cout<<"Test case     x     y     z   Expected Output\n";
	
	for(int i=0; i<testCases.size(); i++)
	{
		auto t = testCases[i];
		cout<<setw(6)<<i+1;
		cout<<setw(9)<<t.x;
		cout<<setw(6)<<t.y;
		cout<<setw(6)<<t.z;
		cout<<setw(15)<<t.expectedOutput;
		cout<<endl;
	}
	
	
	
}
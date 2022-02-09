// Write a program to implement Basic COCOMO model (effort, development time and people required)
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	system("cls");
	cout<<"\n-----Basic COCOMO model-----\n";
	
	int kloc;
	cout<<"Enter the size of project (in KLOC): ";
	cin>>kloc;
	
	float effort,time,staff;
	float a,b,c,d;
	
	string mode;
	
	if(kloc<=50)
	{
		a=2.4, b=1.05, c=2.5, d=0.38;
		mode = "organic";
		
	}
	else if(kloc<=300)
	{
		a=3.0, b=1.12, c=2.5, d=0.35;
		mode = "semidetached";
	}
	else
	{
		a=3.6, b=1.20, c=2.5, d=0.32;
		mode = "embedded";
	}
	
	effort = a * pow(kloc, b);
	time = c * pow(effort, d);
	staff = effort/time;
	
	cout<<"\nAccording to KLOC, the mode is assumed to be "<<mode<<":\n";
	cout<<"Effort required: "<<effort<<" PM\n";
	cout<<"Development time: "<<time<< " months\n";
	cout<<"Average staff size: "<<staff<<" persons\n\n";
	
	
}

// Write a program to implement intermediate COCOMO model (effort, development time and people required)
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	system("cls");
	cout<<"\n-----Intermediate COCOMO model-----\n";
	
	int kloc;
	float eaf;
	cout<<"Enter the size of project (in KLOC): ";
	cin>>kloc;
	
	cout<<"Enter the value of EAF: ";
	cin>>eaf;
	
	float effort,time,staff;
	float a,b,c,d;
	
	string mode;
	
	if(kloc<=50)
	{
		a=3.2, b=1.05, c=2.5, d=0.38;
		mode = "organic";
		
	}
	else if(kloc<=300)
	{
		a=3.0, b=1.12, c=2.5, d=0.35;
		mode = "semidetached";
	}
	else
	{
		a=2.8, b=1.20, c=2.5, d=0.32;
		mode = "embedded";
	}
	
	effort = a * pow(kloc, b)* eaf;
	time = c * pow(effort, d);
	staff = effort/time;
	
	cout<<"\nAccording to KLOC, the mode is assumed to be "<<mode<<":\n";
	cout<<"Effort required: "<<effort<<" PM\n";
	cout<<"Development time: "<<time<< " months\n";
	cout<<"Average staff size: "<<staff<<" persons\n\n";
	
	
}


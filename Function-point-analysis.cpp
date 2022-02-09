// Function point analysis

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    system("cls");
	
	vector<vector<int>>weights;
    weights = {{3,4,6},{4,5,7},{3,4,6},{7,10,15},{5,7,10}};
    vector<vector<int>>funits(5,vector<int>(3));
    
    vector<string>map(5);
    map[0] = "external inputs";
    map[1] = "external outputs";
    map[2] = "external inquiries";
    map[3] = "internal logical files";
    map[4] = "external interface files";
	
	for(int i=0;i<5;i++)
	{
		cout<<"\nEnter no. of "<<map[i]<<" for the three complexities (low,average,high):\n";
		cin>>funits[i][0];
		cin>>funits[i][1];
		cin>>funits[i][2];
	}
	
	int ufp=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<3;j++)
			ufp += funits[i][j]*weights[i][j];
	}
	
	
	int sum_fi=0;
	cout<<"\nEnter the degree of influence for each of the 14 factors:\n";
	
	for(int i=0;i<14;i++)
	{
		int x;
		cin>>x;
		sum_fi+=x;
	}
	
	
	float caf = 0.65 + 0.01*sum_fi;
	float fp = ufp*caf;
	
	
	int effort,pages_of_doc,total_cost;
	cout<<"\nEnter the effort: ";
	cin>>effort;
	cout<<"Enter the total pages of documentation: ";
	cin>>pages_of_doc;
	cout<<"Enter total cost: ";
	cin>>total_cost;
	
	float productivity = fp/effort;
	float documentation = pages_of_doc/fp;
	float cost = total_cost/productivity;
	
	cout<<"\nResults:"<<endl;
	cout<<"Unadjusted function point count: "<<ufp<<endl;
	cout<<"Adjusted function point count: "<<fp<<endl;
	cout<<"Productivity: "<<productivity<<endl;
	cout<<"Documentation: "<<documentation<<endl;
	cout<<"Cost per function: "<<cost<<endl;
	
	cout<<endl;
	
}
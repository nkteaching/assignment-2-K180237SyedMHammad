#include <iostream>
using namespace std;
void cubes(int i,int n)
{
	if(i>n)
	{
		return;
	}
	else
	{
		cout<<i*i*i<<" ";
		cubes(i+1,n);
	}
}
main()
{
	int n;
	cout<<"Enter the number to which u want to find cubes:";
	cin>>n;
	cubes(1,n);
}

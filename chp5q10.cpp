#include<iostream>
#include <cmath>
using namespace std;
double series(int size,double i,double sum)
{
	if (size<i)
	{
		return sum;
	}
	else
	{
		if(i==1)
		{
			sum=1;
		}
		else if(fmod(i,2)==0)
		{
			sum=sum+(1/i);
		}
		else 
		{
			sum=sum-(1/i);
		}
		return series(size,i+1,sum);
		
	}
	
}
main()
{
	cout<<"Enter the value of n:";
	int n;
	cin>>n;
	double x;
	x=series(n,1,0.0);
	cout<<"Sum of given series:"<<x;
}

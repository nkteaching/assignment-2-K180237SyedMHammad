#include <iostream>
using namespace std;
int m(int i,int n,int num,int mul)
{
	if(i==n)
	{
		return mul;
	}
	else
	{
		mul=mul+num;
		return m(i+1,n,num,mul);
	}
}
main()
{
	int num1,num2,result;
	cout<<"Enter numbers to be multiplied (space seperated):";
	cin>>num1>>num2;
	result=m(0,num1,num2,0);
	cout<<"Product:"<<result;
}

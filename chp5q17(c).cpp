#include<iostream>
using namespace std;
void check(int i,string x,char c)
{
	if(i==x.size())
	{
	   cout<<"After deletion:";
	   for(int j=0;j<x.size();j++)
	   {
	   	    cout<<x[j];
	   }	
	}
	else
	{
		if(x[i]==c)
		{
			x[i]=*("");
			i++;
		}
		else
		{
			i++;
			
		}
		return check(i,x,c);
	}
}
main()
{
	string x;
	char c;
	cout<<"Enter string (without spaces):";
	cin>>x;
	cout<<"Enter character to be searched:";
	cin>>c;
	check(0,x,c);
}

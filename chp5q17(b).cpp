#include<iostream>
using namespace std;
int check(int i,string x,char c)
{
	static int count=0;
	if(i==x.size())
	{
		if(i==0)
		cout<<"Not found!";
		return count;
	}
	else
	{
		if(x[i]==c)
		{
			count++;
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
	int count=check(0,x,c);
	cout<<"Number of times given character appeared:"<<count;
}

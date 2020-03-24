#include <iostream>
using namespace std;
class node{
	public:
		char data;
		node *next;
		node()
		{
			data=NULL;
			next=NULL;
		}
		node(int a)
		{
			data=a;
			next=NULL;
		}
		node(int a,node *x)
		{
			data=a;
			next=x;
		}
};
class stack{
	public:
		node *top,*tail;
		stack()
		{
			top=NULL;
			tail=NULL;
		}
		bool isEmpty()
		{
			if (top==NULL)
			return true;
			else
			return false;
		}
		void push(char a)
		{
			if(this->isEmpty()==true)
			{
				top=new node(a,NULL);
				tail=top;
			}
			else
			{
				top=new node(a,top);
			}
		}
		void pop()
		{
			if(this->isEmpty()==true)
			{
				cout<<"Stack Underflow";
			}
			else
			{
				node *n=top;
				top=top->next;
				delete n;
			}
		}
		char peek()
		{
			if(this->isEmpty()==true)
			{
				cout<<"Stack Underflow";
				return -1;
			}
			else
			{
				return top->data;
			}
		}
		
		
};
main()
{
	stack s;
	string x="ambmb";
//	cout<<"Enter string:";
//	cin>>x;
	int size,size1,flag=0;
	if(x.size()%2==0)
	{
		size=(x.size()-1)/2;
		for(int i=0;i<=size;i++)
		{
			s.push(x[i]);
		}
		for(int j=size+1;j<x.size() || !s.isEmpty();j++)
		{
			char d=s.peek();
			if(d!=x[j])
			{
				flag=1;
				break;
			}
			else
			s.pop();
		}
	}
	else
	{
		size=(x.size()/2);
		for(int i=0;i<size;i++)
		{
			s.push(x[i]);
		}
		for(int j=size+1;j<x.size() || !s.isEmpty();j++)
		{
			if(s.peek()!=x[j])
			{
				flag=1;
				break;
			}
			else
			s.pop();
		}
	}
	if(flag==1)
	{
		cout<<"Not palindrome";
	}
	else
	{
		cout<<"Palindrome";
	}
}

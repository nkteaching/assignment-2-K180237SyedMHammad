#include<iostream>
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
		node(char a)
		{
			data=a;
			next=NULL;
		}
		node(char a,node *x)
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
		bool parenthesis(string x)
	    {
	    	int i=0;
	    	while(i<x.size())
	        {
	        	char ch;
		       if(x[i]=='[' || x[i]=='(' || x[i]=='{')
		       {
			     push(x[i]);
		       }
		       
			   
				if(x[i]==')')
				{
					ch=peek();
					if(ch=='(')
					{
						pop();
					
					}
					else
					{
						cout<<ch;
						cout<<x[i];
						return false;
					    break;
					}
					
				}
				if(x[i]==']')
				{
					ch=peek();
					if(ch=='[')
					{
						pop();
					}
					else
					{
						cout<<ch;
						cout<<x[i];
						return false;
					    break;
					}
				}
				if(x[i]=='}')
				{
					ch=peek();
					if(ch=='{')
					{
						pop();
					}
					else
					{
						cout<<ch;
						cout<<x[i];
						return false;
					    break;
					}
				}
				i++;
				
				
			   
			   if(isEmpty()==true)
			   {
				return true;
			   }
		    
	        }	
			
		}
};
main()
{
	string x;
	stack s;
	cout<<"Enter equation (without spaces):";
	cin>>x;
	if(s.parenthesis(x)==true)
	{
		cout<<"Parenthesis are balanced.";
	}
	else
	{
		cout<<"Parenthesis are not balanced.";
	}
}

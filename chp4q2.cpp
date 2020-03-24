#include <iostream>
using namespace std;
//question1(a)
class node{
	public:
		int data;
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
		void push(int a)
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
				return;
				
			}
			else
			{
				node *n=top;
				top=top->next;
				delete n;
			}
		}
		int peek()
		{
			if(this->isEmpty()==true)
			{
				return -1;
			}
			else
			{
				return top->data;
			}
		}
		void revstack(stack &s1,int size)
		{
		
			
			int temp=s1.peek();
			s1.pop();
			int i=0;
			while(i<size-1)
			{
			    push(s1.peek());
			    s1.pop();
			    i++;
			}
			i=0;
			if(temp<peek())
			{
				s1.push(peek());
				pop();
			}
			else
			{
				s1.push(temp);
				temp=peek();
				pop();
			}
			while(i<size-1)
			{
				if(isEmpty())
				{
					s1.push(temp);
					break;
				}
				if(temp<peek())
			{
				
				s1.push(peek());
				pop();
			}
			else
			{
				s1.push(temp);
				temp=peek();
				pop();
			}
			i++;
			}
			i=0;
			while(i<size-2)
			{
			if(i==0)
			{
				temp=s1.peek();
			    s1.pop();
			}
			
			if(temp<s1.peek())
			{
			push(temp);
			temp=s1.peek();
			s1.pop();
		    }
		    else
		    {
		    	push(s1.peek());
		    	s1.pop();
			}
			i++;
		    }
		    i=0;
			while(i<size-1)
			{
				if(temp<peek() && !isEmpty())
				{
					s1.push(peek());
					pop();
				}
				else
				{
					s1.push(temp);
					temp=peek();
					pop();
				}
				i++;
			}
		    }
		
};
main()
{
	stack s1,s2;
	int element,size1;
	cout<<"Enter size of stack:";
	cin>>size1;
	cout<<"Enter element(s) stack(last entered element will be the top of stack):";
	for(int i=0;i<size1;i++)
	{
		cin>>element;
		s1.push(element);
	}
    s2.revstack(s1,size1);
    cout<<"Reversed array:";
    while(!s1.isEmpty())
    {
    	cout<<s1.peek()<<" ";
    	s1.pop();
	}

}

#include <iostream>
using namespace std;
class stack;
class queue;
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
				cout<<"Stack Underflow";
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
				cout<<"Stack Underflow";
				return -1;
			}
			else
			{
				return top->data;
			}
		}
		void reverse(stack &otherStack)
		{
			if(otherStack.isEmpty()!=true)
			{
				while(otherStack.isEmpty()!=true)
				{
					otherStack.pop();
				}
			}
			while(isEmpty()!=true)
			{
				
				otherStack.push(peek());
				pop();
			}
			
		}
		
};

class queue{
	public:
		node *front,*rear;
		queue()
		{
			front=NULL;
			rear=NULL;
		}
		bool isEmpty()
		{
			if (front==NULL)
			return true;
			else
			return false;
		}
		void push(int a)
		{
			if(this->isEmpty()==true)
			{
				rear=new node(a,NULL);
				front=rear;
			}
			else
			{
				rear->next=new node(a,NULL);
				rear=rear->next;
			}
		}
		void pop()
		{
			if(front==NULL)
			{
				rear=front;
			}
			else
			{
				node *n=front;
				front=front->next;
				delete n;
				
			}
		}
		int peek()
		{
			if(isEmpty()==true)
			{
				cout<<"Queue Underflow";
				return -1;
			}
			else
			{
				return front->data;
			}
		}
		void reverse(queue &otherqueue)
		{
			if(otherqueue.isEmpty()!=true)
			{
				while(otherqueue.isEmpty()!=true)
				{
					otherqueue.pop();
				}
			}
			while(isEmpty()!=true)
			{
				
				otherqueue.push(peek());
				pop();
			}
			
		}
		
};
main()
{
	stack s;
	int element,size1,size2;
	cout<<"Enter size of stack:";
	cin>>size1;
	cout<<"Enter element(s) of stack:";
	for(int i=0;i<size1;i++)
	{
		cin>>element;
		s.push(element);
	}
	queue q1;
	while(!s.isEmpty())
	{
		q1.push(s.peek());
		s.pop();
	}
	while(q1.isEmpty()!=true)
	{
		s.push(q1.peek());
		q1.pop();
	}
	cout<<"Stack after using additional queue:";
	while(!s.isEmpty())
	{
		cout<<s.peek()<<" ";
		s.pop();
	}
}

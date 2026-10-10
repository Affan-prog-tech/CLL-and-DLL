#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
		
	Node(int val)
	{
		data=val;
		next=prev=NULL;
		
	}
};

class List
{
	
	Node* head;
	Node* tail;
	
public:
	List()
	{
		head=tail=NULL;
	}
	
	void pushfront(int val)
	{
		Node* newNode=new Node(val);
		
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
		}
	}
	
	void print()
	{
		Node *temp=head;
		
		while(temp!=NULL)
		{
		cout<<temp->data<<"<=>";
		temp=temp->next;
		}
		cout<<"NULL\n";
	}
	
	void pushback(int val)
	{
		Node* newNode=new Node(val);
		
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
		}
	}

	void popfront()
	{
		if(head==NULL)
		{
			cout<<"List is empty\n";
			return;
		}

		Node* temp=head;
		head=head->next;
		
		if(head!=NULL)
		{
		head->prev=NULL;
		}
		
		temp->next=NULL;
		delete temp;
	}
		
	
	
	void popback()
	{
		if(head==NULL)
		{
			cout<<"List is empty\n";
			return;
		}
		
		Node* temp=tail;
		tail=tail->prev;

		
		if(head!=NULL)
		{
			tail->next=NULL;
		}
		
		temp->prev=NULL;
		
		delete temp;
	}
			
};

int main()
{
	List l1;
	
	l1.pushfront(2);
	l1.pushfront(4);
	l1.pushfront(6);
	l1.pushfront(8);

	l1.print();

}

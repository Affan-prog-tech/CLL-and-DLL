#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
		
	Node(int val)
	{
		data=val;
		next=NULL;
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
		head=newNode;
		tail->next=head;
		}
	}
	
	void print()
	{
		cout<<head->data<<"->";
		Node *temp=head->next;
		
		while(temp!=head)
		{
		cout<<temp->data<<"->";
		temp=temp->next;
		}
		cout<<"HEAD"<<endl;
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
		newNode->next=head;
		tail->next=newNode;
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
		else if(head==tail)
		{
			delete head;
			head=tail=NULL;
			return;
		}
		else
		{
		Node* temp=head;
		head=head->next;
		tail->next=head;
		
		temp->next=NULL;
		delete temp;
		}
		
	}	
	
	void popback()
	{
		if(head==NULL)
		{
			cout<<"List is empty\n";
			return;
		}
		else if(head==tail)
		{
			delete head;
			head=tail=NULL;
		}
		else
		{
		Node* temp=head;

		while(temp->next != tail)
		{
			temp=temp->next;
		}
	
		temp->next=head;
		delete tail;
		tail=temp;
		}
			
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

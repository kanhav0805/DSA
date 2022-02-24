#include<iostream>
using namespace std;
#include "NodeClass.cpp"
void print(Node *head)
{
	/*when we dont want to print the last node
	while(head->next!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}*/
	Node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
int main()
{
	//creating the nodes statically
	Node n1(1);
	Node n2(2);
	Node n3(3);
	//linking the nodes
	n1.next = &n2;
	n2.next = &n3;
	cout<<n1.data<<" "<<n2.data<<" "<<n3.data;
	
	/*creating the nodes dynamically
  	Node *n1 = new Node(10);
	Node *n2 = new Node(20);
	Node *n3 = new Node(30);
	n1->next = n2;
	n2->next = n3;
	cout<<n1->data<<" "<<n2->data<<" "<<n3->data;*/
	
	//creating head node to store the address of first node
	Node *head = &n1;
	//we want to print the linked list
	cout<<endl;
	print(head);
	cout<<endl;
	print(head);
}

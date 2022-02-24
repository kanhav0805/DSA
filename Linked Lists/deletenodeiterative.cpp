#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
Node *deleteNode(Node *head, int pos)
{
    int count = 0;
    Node *temp1 = head;
    if(head==NULL)
    {return NULL;}
    if(pos==0)
    {
        Node *temp = head;
        head = temp->next;
        delete temp;
        return head;
    }
    while((count<pos-1) && (temp1!=NULL))
    {
        temp1 = temp1->next;
        count++;
    }
    if(temp1==NULL || temp1->next==NULL)
    {return head;}
    else
    {
        Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
    return head;
}


int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}

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
void printIthNode(Node *head, int i)
{
    int length = 0;
    Node *temp = head;
    while(temp!=NULL)
    {
        length++;
        temp = temp->next;
    }
    if(i>=length)
    {return;}
    else
    {
        int k=0;
        Node *dummy = head;
        while(k<i)
        {
            dummy = dummy->next;
            k++;
        }
        cout<<dummy->data<<endl;
    }
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
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}

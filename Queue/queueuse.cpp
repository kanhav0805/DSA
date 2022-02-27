#include<iostream>
#include "QueueClass.cpp"
using namespace std;
int main()
{
	QueueUsingArray<int> q1(5);
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	cout<<q1.getSize()<<endl;
	cout<<q1.front()<<endl;
	cout<<q1.dequeue()<<endl;
	q1.enqueue(99);
	q1.enqueue(160);
	q1.enqueue(200);
    cout<<q1.dequeue()<<endl;
    cout<<q1.getSize()<<endl;
	cout<<q1.front()<<endl;
	
}

//generic stack class using templates
#include <climits>
#include<iostream>

using namespace std;
template <typename T>
class Stack{
	T *data;//array
	int nextIndex;//where to put new element
	int capacity;
	public:
	Stack()//int totalSize (not giving because we are making it dynamic)
	{
		data = new T[5];//we make array of size 5 initially
		nextIndex = 0;
		capacity = 5;
	}
	//to get the size of the stack
	int size()
	{
		return nextIndex;
	}
	//to check if the stack is empty or not
	bool isEmpty()
	{
		//if(nextIndex==0){return true;}
		//else {return false;}
		return nextIndex==0;
	}
	//to insert the element in the stack
	void push(T element)
	{
		if(nextIndex==capacity)
		{
//			cout<<"STACK FULL"<<endl;
//			return ;
//WE WILL NOT RETURN BECAUSE THE STACK IS DYNAMIC IN NATURE
            T *newdata = new T[2*capacity];
            for(int i=0;i<capacity;i++)
            {
            	newdata[i] = data[i];
			}
			capacity*=2;//double the capacity
			delete []data;
			data = newdata;//data pointin to new big array
		}
		data[nextIndex] = element;
		nextIndex++;
	}
	//to delete the element from the tos
	T pop()
	{
		if(isEmpty())
		{
			cout<<"STACK IS EMPTY"<<endl;
			return 0;
		}
		nextIndex--;
		return data[nextIndex];
	}
	//to get the top of the element
	T top()
	{
		if(isEmpty())
		{
			cout<<"STACK IS EMPTY"<<endl;
			//return INT_MIN;
			return 0;//beacuse it is generic for every data type
		}
		return data[nextIndex-1];
	}
};


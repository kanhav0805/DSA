#include<iostream>
#include<queue>
using namespace std;
//ksorted array time complexity nearly o(n) which is fastest
void kSortedArray(int *input,int n,int k)
{
	//make a priority queue
	priority_queue<int> pq;
	//insert the first k element in the queue
	for(int i=0;i<k;i++)
	{
		pq.push(input[i]);
	}
	int j=0;//to decide at what index we need to put the value
	//run a loop from j=k to end and put it in heap
	for(int i=k;i<n;i++)
	{
		input[j] = pq.top();//put max element at the index
		pq.pop();//remove the max element
		pq.push(input[i]);//insert element in the queue
		j++;
	}
	//now after this n-k will be sorted we need to sort last k element
	while(pq.empty()!=true)
	{
		input[j] = pq.top();
		pq.pop();
		j++;
	}
}
int main()
{
	int arr[] = {10,12,15,6,9};
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	kSortedArray(arr,5,3);
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
}

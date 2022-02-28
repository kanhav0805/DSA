#include<stack>
int* stockSpan(int *price, int size)  
{
    int *arr = new int[size];
	if(size==0)
    {return{};}
    if(size==1)
    {arr[0] = 1;return arr;}
    stack<int> dibba;
    dibba.push(0);
    arr[0] = 1;
    int span;
    for(int i=1;i<size;i++)
    {
        while(dibba.empty()==false && price[dibba.top()]<price[i])
        {
            dibba.pop();
        }
        if(dibba.empty()==true)
        {
            span = i + 1;
        }
        else
        {
            span = i - dibba.top();
        }
        arr[i] = span;
        dibba.push(i);
    }
    return arr;
}

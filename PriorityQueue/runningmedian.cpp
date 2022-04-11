#include<queue>
#include<algorithm>

void findMedian(int *arr, int n)
{
   if(n==0)
   {return;}
   priority_queue<int> maxH;
   priority_queue<int,vector<int>,greater<int>> minH;
   //put the first element of array in maxheap or min heap
    maxH.push(arr[0]);
  //median of element is element itself
    cout<<arr[0]<<" ";
  //put the element in maxheap and min heap
    for(int i=1;i<n;i++)
    {
        if(maxH.top()>arr[i])
        {maxH.push(arr[i]);}
        else
        {minH.push(arr[i]);}
        //get the size of both the heap
        int size1 = maxH.size();
        int size2 = minH.size();
        if(abs(size1-size2)>1)
        {
            if(size1>size2)
            {
                int tops = maxH.top();
                maxH.pop();
                minH.push(tops);
            }
            else
            {
                int tops = minH.top();
                minH.pop();
                maxH.push(tops);
            }
        }
        //comparing the size of both the heap difference should be less than= 1
        //case when there are even no of elements in total
            if((size1+size2)%2==0)
            {
                int first = maxH.top();
                int second = minH.top();
                int ans = (first + second)/2;
                cout<<ans<<" ";
            }
            else //case when odd number of elements
            {
                if(size1>size2){cout<<maxH.top()<<" ";}
                else{cout<<minH.top()<<" ";}
            }
        
   
    }
}

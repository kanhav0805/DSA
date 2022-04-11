#include<queue>
vector<int> kSmallest(int arr[], int n, int k) 
{
    vector<int> ans;
    //make a priority queue
    priority_queue<int> pq;
    //insert first k elements in the queue
    //assume that these are the min elements
    for(int i=0;i<k;i++)
    {pq.push(arr[i]);}
    //now run a loop from k to n-1 and check with top of pq
    //if top>element we need to remove the top and put element in pq
    //if top<element do nothing
    for(int i=k;i<n;i++)
    {
        if(pq.top()<arr[i])
        {continue;}
        else if(pq.top()>arr[i])
        {
            //remove top element
            pq.pop();
            //insert the new arr[i]
            pq.push(arr[i]);
        }
    }
    //at last only the k smallest element will be in the queue
    //put that in the array
    while(pq.empty()!=true)
    {
        int x = pq.top();
        ans.push_back(x);
        pq.pop();
    }
    return ans;
}

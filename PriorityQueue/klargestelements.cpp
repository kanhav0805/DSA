#include<queue>
vector<int> kLargest(int input[], int n, int k)
{
  priority_queue<int,vector<int>,greater<int>> pq;//this is min priority queue
  //put fisrt k elements in the queue
  for(int i=0;i<k;i++)
  {
      pq.push(input[i]);
  }
  //run a loop from i=k to n-1 and see whether element should come in heap or not
  for(int i=k;i<n;i++)
  {
      int tops = pq.top();
      if(tops>input[i])
      {continue;}
      else if(tops<input[i])
      {
          //remove the min element and put new element in it
          pq.pop();
          pq.push(input[i]);
      }
  }
  //after this our queue will contain the k largest element we need to push it in array
  vector<int> ans;
  while(pq.empty()!=true)
  {
      int tops = pq.top();
      ans.push_back(tops);
      pq.pop();
  }
  return ans;
}

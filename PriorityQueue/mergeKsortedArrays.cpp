#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input) 
{
   //we will simply put all the value in the min heap
   //it will arrange the element accordingly
   //remove element from heap one by one it will come in ascending order
   priority_queue<int,vector<int>,greater<int>> pq;
   //put the valyes of all vector in the heap
   for(int i=0;i<input.size();i++)
   {
       for(int j=0;j<input[i]->size();j++)
       {
           pq.push(input[i]->at(j));
       }
   }
    vector<int> ans;
   //now heap is created we will remove the value till heap is empty
   while(pq.empty()!=true)
   {
       int tops = pq.top();
       pq.pop();
       ans.push_back(tops);
   }
    return  ans;
}

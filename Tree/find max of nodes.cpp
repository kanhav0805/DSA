TreeNode<int>* maxDataNode(TreeNode<int>* root) 
{
   if(root==NULL){return NULL;}
   int max = INT_MIN;
   queue<TreeNode<int>*> pendingMax;
   pendingMax.push(root);
   TreeNode<int> *ans = NULL;
   while(pendingMax.empty()==false)
   {
       TreeNode<int> *front = pendingMax.front();
       pendingMax.pop();
       //check if its data is greater than current max
       if(max<front->data)
       {max = front->data;ans = front;}
       //run a loop to put children in queue
       for(int i=0;i<front->children.size();i++)
       {
           pendingMax.push(front->children[i]);
       }
   }
   return ans;
}

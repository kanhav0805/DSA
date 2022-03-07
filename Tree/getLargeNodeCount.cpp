//find nodes with data greter than x return the count for it
int getLargeNodeCount(TreeNode<int>* root, int x) 
{
    if(root==NULL)
    {return 0;}
    int count = 0;
    //make a queue of tree pointer
    queue<TreeNode<int>*> pending;
    pending.push(root);
    while(pending.size()!=0)
    {
        TreeNode<int> *front = pending.front();
        pending.pop();
        if(x<front->data)
        {count++;}
        //pushing all children of parent in queue
        for(int i=0;i<front->children.size();i++)
        {pending.push(front->children[i]);}
    }
    return count;
}

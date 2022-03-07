TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x)
{
    if(root==NULL)
    {return NULL;}
    TreeNode<int> *ans = NULL;
    int min = INT_MAX;
    queue<TreeNode<int>*> pending;
    //pushing first element int queue
    pending.push(root);
    while(pending.size()!=0)
    {
        TreeNode<int> *front = pending.front();
        pending.pop();
        if(front->data>x)
        {
            if(min>front->data)
            {
                min = front->data;
                ans = front;
            }
       }
       for(int i=0;i<front->children.size();i++)
       {
           pending.push(front->children[i]);
       }
        
    }
    return ans;
}
//by recursion
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) 
{
    if(root==NULL)
    {return NULL;}
    int min = INT_MAX;
    TreeNode<int> *ans = NULL;
    //check if the root data is greater than x or not
    if(root->data>x)
    {
        min = root->data;
        ans = root;
    }
    //calling recursively for all smaller tree
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int> *child = getNextLargerElement(root->children[i],x);
        if(child==NULL)
        {
            continue;
        }
        else if(child->data<min)
        {
            min = child->data;
            ans = child;
        }
    }
    return ans;
}

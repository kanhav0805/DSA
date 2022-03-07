bool isPresent(TreeNode<int>* root, int x) 
{   
    //edge case
    if(root==NULL)
    {return false;}
    //if root contains x
    if(root->data==x)
    {return true;}
    //finding x in smaller tree
    bool ans;
    for(int i=0;i<root->children.size();i++)
    {
        ans = isPresent(root->children[i],x);
        if(ans) 
        {return true;}
    }
    return false;
}

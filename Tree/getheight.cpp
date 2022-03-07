int getHeight(TreeNode<int>* root) 
{
    if(root==NULL)
    {return 0;}
    int max = 0;
    for(int i=0;i<root->children.size();i++)
    {
        int ans = getHeight(root->children[i]);
        if(max<=ans)
        {
            max = ans;
        }
    }
    return (1 + max);
}

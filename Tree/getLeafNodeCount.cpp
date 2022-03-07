int getLeafNodeCount(TreeNode<int>* root) 
{
    //edge case when we do not get a tree
    if(root==NULL)
    {return 0;}
    //check if root dont ave cildren if not return 1
    if(root->children.size()==0)
    {return 1;}
    //call for smaller tree to find their no of leaf nodes
    int ans = 0;
    for(int i=0;i<root->children.size();i++)
    {
        ans += getLeafNodeCount(root->children[i]);
    }
    return ans;
}

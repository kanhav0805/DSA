class pairs{
  public:
    int height;
    bool isBalanced;
};
pairs helper(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        pairs p;
        p.height = 0;
        p.isBalanced = true;
        return p;
    }
    //call recursion on the left and right subtree
    pairs p1 = helper(root->left);
    pairs p2 = helper(root->right);
    pairs ans;
    ans.height = 1 + max(p1.height,p2.height);
    if(p1.isBalanced==true && p2.isBalanced==true)
    {
        if(abs(p1.height-p2.height)>1)
        {ans.isBalanced = false;}
        else
        {ans.isBalanced = true;}
    }
    else if(p1.isBalanced==false || p2.isBalanced==false)
    {
        ans.isBalanced = false;
    }
return ans;
}
bool isBalanced(BinaryTreeNode<int> *root) 
{
	return helper(root).isBalanced;
}

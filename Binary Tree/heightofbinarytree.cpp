int height(BinaryTreeNode<int>* root)
{
    //if no tree is passed by the user
    if(root==NULL)
    {
        return 0;
    }
    //if there is only root node
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    int max1 = 0;
    int max2 = 0;
    //recursion on left part
    max1 = height(root->left);
    //rcursion on right part
    max2 = height(root->right);
    //find max from the height of both subtree
    int ans = max(max1,max2);
    //return 1+max
    return 1+ans;
}

int getSum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {return 0;}
    int sum = root->data;
    sum += getSum(root->left);//call recursion on left part
    sum += getSum(root->right);//call on right part
    return sum;
}

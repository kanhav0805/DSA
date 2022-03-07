void printPostOrder(TreeNode<int>* root) 
{
    //edge case when tree is not passed
    if(root==NULL)
    {return;}
    //first print the child nodes
    for(int i=0;i<root->children.size();i++)
    {
        printPostOrder(root->children[i]);
    }
    //after printing the child node print root node
    cout<<root->data<<" ";
    return;
}

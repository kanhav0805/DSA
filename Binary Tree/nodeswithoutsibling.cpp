void printNodesWithoutSibling(BinaryTreeNode<int> *root) 
{
   //base case when no tree passed or only root node
    if((root==NULL) || (root->left==NULL && root->right==NULL))
    {return;}
    //check if root->left null then root ka right will be node without sibling
    if(root->left==NULL)
    {cout<<root->right->data<<" ";}
    if(root->right==NULL)
    {cout<<root->left->data<<" ";}
    //recursive call on left and right subtree
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

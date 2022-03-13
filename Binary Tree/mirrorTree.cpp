void mirrorBinaryTree(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {return;}
    //case when only one node is present
    if(root->left==NULL && root->right==NULL)
    {return;}
    //save the left subtree in a variable
    BinaryTreeNode<int> *leftchild = root->left;
    //connect root->left to root->right
    root->left = root->right;
    //put the leftchild in root->right
    root->right = leftchild;
    //call recursion for left and right subtree
   mirrorBinaryTree(root->left);
   mirrorBinaryTree(root->right);
}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root)
{
    //base case
    if(root==NULL)
    {return NULL;}
    if(root->left==NULL && root->right==NULL)
    {
        delete root;
        return NULL;
    }
    BinaryTreeNode<int> *leftChild = removeLeafNodes(root->left);
    BinaryTreeNode<int> *rightChild = removeLeafNodes(root->right);
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

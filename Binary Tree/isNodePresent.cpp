//For a given Binary Tree of type integer and a number X, 
//find whether a node exists in the tree with data X or not.
bool isNodePresent(BinaryTreeNode<int> *root, int x) 
{
    //case when no tree is passed
    if(root==NULL)
    {return false;}
    //check if the data x is root->data
    if(root->data==x)
    {return true;}
    // bool ans1 = false;
    // bool ans2 = false;
    // //recusion on left part
    // ans1 = isNodePresent(root->left,x);
    // if(ans1){return true;}
    // ans2 = isNodePresent(root->right,x);
    // if(ans2){return true;}
    // return false;
    //in short
    return isNodePresent(root->left,x) || isNodePresent(root->right,x);
}

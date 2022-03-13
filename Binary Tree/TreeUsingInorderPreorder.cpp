//given inorder and preorder the construct the tree
BinaryTreeNode<int>* helper(int *&preorder,int *&inorder,int preS,int preE,int inS,int inE)
{
    //base case when no element is passed
    if(preE<preS)
    {return NULL;}
    if(preS==preE)
    {
        BinaryTreeNode<int> *dummy = new BinaryTreeNode<int>(preorder[preS]);
        return dummy;
    }
    //first we will find the root node it will be the start of preorder
    //create a node with data at preorder[preS]
    int rootdata = preorder[preS];
    //now create a root node and put the data in it
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    //now we will get inorder and preorder of left subtree
    int linS = inS;//start of left subtree is inorder first element
    int rootIndex = 0;
    for( ;rootIndex<=inE;rootIndex++)
    {
        if(inorder[rootIndex]==rootdata)
        {break;}
    }
    //we have traversed till rootIndex so inorder end of left subtree will be rootIndex-1
    int linE = rootIndex - 1;
    int lpreS = preS + 1;//it will be just next to root
    int lpreE = (linE - linS) + lpreS;
    //now we will calculate the four indexes of right subtree
    int rinS = rootIndex + 1;
    int rinE = inE;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    //now we will call recursion on these smaller part
    BinaryTreeNode<int> *leftChild = helper(preorder,inorder,lpreS,lpreE,linS,linE);
    BinaryTreeNode<int> *rightChild = helper(preorder,inorder,rpreS,rpreE,rinS,rinE);
    //now make the connection with root and return
    root->left = leftChild;
    root->right = rightChild;
    return root;
    
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) 
{
   //preorder for whole big tree
   int preS = 0;
   int preE = preLength - 1;
   //inorder for whole big tree
   int inS = 0;
   int inE = inLength - 1;
   BinaryTreeNode<int> *root = helper(preorder,inorder,preS,preE,inS,inE);
   return root;
}

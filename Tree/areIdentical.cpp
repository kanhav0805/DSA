bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2)
{
    //edge case
    if(root1==NULL && root2==NULL)
    {return true;}
    if((root1==NULL && root2!=NULL)||(root1!=NULL && root2==NULL))
    {return false;}
    //check the data of both the root node
    if(root1->data!=root2->data)
    {return false;}
    //checking if the root has same no of childrens
    if(root1->children.size()!=root2->children.size())
    {return false;}
    bool ans;
    //running a loop to compare subtree
    for(int i=0 ;i<root1->children.size();i++)
    {
        ans = areIdentical(root1->children[i],root2->children[i]);
        //if 1 subtree of both tree are not same return false
        if(ans==false)
        {
            return false;
        }
    }
   return true;//return true when all condititons are satisfied
}

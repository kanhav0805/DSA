void helper(TreeNode<int> *&,int );
void replaceWithDepthValue(TreeNode<int>* root) 
{
    int depth = 0;
    helper(root,depth);
    return;
}
void helper(TreeNode<int> *&root,int depth)
{
    if(root==NULL)
    {return;}
    root->data = depth;
    for(int i=0;i<root->children.size();i++)
    {
        helper(root->children[i],depth+1);
    }
}

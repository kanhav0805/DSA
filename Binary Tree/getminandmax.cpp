pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) 
{
	if(root==NULL)
    {
        pair<int,int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
     pair<int,int> p1 = getMinAndMax(root->left);
     pair<int,int> p2 = getMinAndMax(root->right);
     //get max of all
    int maxm = max(root->data,max(p1.second,p2.second));
    int minm = min(root->data,min(p1.first,p2.first));
    pair<int,int> ans;
    ans.first = minm;
    ans.second = maxm;
    return ans;
}

//function to count the nodes in the binary tree
int countNodes(BinaryTreeNode<int>* root)
{  //if no tree is passed
	if(root==NULL)
	{
		return 0;
	}
	int count1=0,count2=0;
	//check if left of root is not null then call recursion on it
	if(root->left!=NULL)
	{
		count1 = countNodes(root->left);
	}
	//check if right of root is not null then call recursion on it
	if(root->right!=NULL)
	{
		count2 = countNodes(root->right);
	}
	int ans = 1 + count1 + count2;
	return ans;
}

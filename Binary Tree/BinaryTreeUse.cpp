#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
#include<vector>
using namespace std;
 vector<int> largestValues(BinaryTreeNode<int>* root) 
    {
        vector<int> ans;
        if(root==NULL)
        {return ans;}
        if(root->left==NULL && root->right==NULL)
        {ans.push_back(root->data);return ans;}
        queue<BinaryTreeNode<int>*> pending;
        pending.push(root);
        ans.push_back(root->data);
        while(pending.size()!=0)
        {
            int count = pending.size();
            int max = INT_MIN;
            for(int i=0;i<count;i++)
            {
                BinaryTreeNode<int> *front = pending.front();
                pending.pop();
                if(root->left!=NULL)
                {
                    if(max<root->left->data)
                    {max = root->left->data;}
                    pending.push(root->left);
                }
                if(root->right!=NULL)
                {
                    if(max<root->right->data)
                    {max = root->right->data;}
                    pending.push(root->left);
                }
            }
            //level completed 
            ans.push_back(max);
        }
        return ans;
    }
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
//input function to take input from the user lecvel wise
BinaryTreeNode<int>* takeInputLevelWise()
{
	int rootData;
	cout<<"ENTER THE ROOT DATA : "<<endl;
	cin>>rootData;
	if(rootData==-1)
	{
		return NULL;
	}
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	//push the root node in the queue
	pendingNodes.push(root);
	//run a loop till queue is not empty
	while(pendingNodes.size()!=0)
	{
		//get the front from the queue
		BinaryTreeNode<int> *front = pendingNodes.front();
		//pop the front node
		pendingNodes.pop();
		cout<<"ENTER THE LEFT CHILD OF "<<front->data<<" : "<<endl;
		int leftchild;
		cin>>leftchild;
		if(leftchild!=-1)
		{
			BinaryTreeNode<int> *leftpart = new BinaryTreeNode<int>(leftchild);
			//connect with the front 
			front->left = leftpart;
			//push it in the queue
			pendingNodes.push(leftpart);
		}
		cout<<"ENTER THE RIGHT CHILD OF "<<front->data<<" : "<<endl;
		int rightchild;
		cin>>rightchild;
		if(rightchild!=-1)
		{
			BinaryTreeNode<int> *rightpart = new BinaryTreeNode<int>(rightchild);
			//connect with the front 
			front->right = rightpart;
			//push it in the queue
			pendingNodes.push(rightpart);
		}
	}
	//last return the node of the tree
	return root;
}
//input function to take input from the user not level wise
BinaryTreeNode<int>* takeInput()
{
	int rootData;
	cout<<"ENTER DATA"<<endl;
	cin>>rootData;
	//we will use -1 to end the tree
	if(rootData==-1)
	{
		return NULL;
	}
	//else create new root with rootdata
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData); 
	BinaryTreeNode<int> *leftChild = takeInput();
	BinaryTreeNode<int> *rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;  
}
//function to print the binary tree
void printTree(BinaryTreeNode<int> *root)
{
	if(root==NULL)
	{
		return;
	}
	//first print the root data
	cout<<root->data<<" : ";
	//print left and right root node data after checking it is not null
	if(root->left!=NULL)
	{
		cout<<"L "<<root->left->data<<" ";
	}
	if(root->right!=NULL)
	{
		cout<<"R "<<root->right->data<<" ";
	}
	cout<<endl;
	printTree(root->left);
	printTree(root->right);
}
int main()
{
	//create binary 
	BinaryTreeNode<int> *root = takeInputLevelWise(); 
//	BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2); 
//	BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3); 
//	BinaryTreeNode<int> *node3 = new BinaryTreeNode<int>(3); 
	//make the connections
//	root->left = node1;
//	root->right = node2;
	//node2->left = node2;
	printTree(root);
	vector<int> ans = largestValues(root);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	cout<<countNodes(root);
}

#include<iostream>
#include "TreeNode.h"
#include<queue>
using namespace std;
int countNodes(TreeNode<int>* root)
{
	//make a queue
	queue<TreeNode<int> *>pendingCount;
	int  count = 0;
	pendingCount.push(root);
	while(pendingCount.size()!=0)
	{
		TreeNode<int> *front = pendingCount.front();
		count++;
		pendingCount.pop();
		for(int i=0;i<front->children.size();i++)
		{
			pendingCount.push(front->children[i]);
		}
	}
	return count;
}
void printLevelWise(TreeNode<int>* root) 
{
    //create a queue which will store tree node
    queue<TreeNode<int>*> pendingPrint;
    //add the root node in the queue
    pendingPrint.push(root);
    //run a loop till queue is not empty
    while(pendingPrint.empty()==false)
    {
        //get the front node from the queue
        TreeNode<int> *front = pendingPrint.front();
        //pop the front node from the queue
        pendingPrint.pop();
        //print front->data:
        cout<<front->data<<":";
        //run a loop to print the children of front node
        for(int i=0;i<front->children.size();i++)
        {
            //when we print last node we dont need , at last
            if(i==(front->children.size()-1))
            {
                cout<<front->children[i]->data;
            }
            else
            {
			cout<<front->children[i]->data<<",";}
            //now add the children in the queue for further processing
            pendingPrint.push(front->children[i]);
        }
        cout<<endl;
    }
}
TreeNode<int>* takeinputlevelwise()
{
	//get the data of the root node
	int rootData;
	cout<<"ENTER THE DATA OF ROOT NODE->"<<endl;
	cin>>rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	//creating a queue of type treeNode poimter
	queue<TreeNode<int>*> pendingNodes;
	//adding first node in the queue
	pendingNodes.push(root);
	//run a loop while queue is not empty
	while(pendingNodes.size()!=0)
	{
		int numchild;
		//getting the first node in the queue
		TreeNode<int> *front = pendingNodes.front();
		//pop the first node
		pendingNodes.pop();
		//get the no of child you want of front node
		cout<<"ENTER THE NUMBER OF CHILDREN OF "<<front->data<<" -> "<<endl;
		cin>>numchild;
		//getting the number of children specified by user
		for(int i=0;i<numchild;i++)
		{
			int childData;
			cout<<"ENTER THE DATA OF "<<i<<"th NODE OF PARENT "<<front->data<<"->"<<endl;
			cin>>childData;
			TreeNode<int> *child = new TreeNode<int>(childData);
			//now make the connection with the front node
			front->children.push_back(child);
			//now adding the child in the queue
			pendingNodes.push(child);
		}
	}
	return root;
}
TreeNode<int>* takeInput()
{
	//get the data of the root node
	int rootData;
	cout<<"ENTER THE DATA : ";
	cin>>rootData;
	//making a root node with value as root data
	TreeNode<int> *root = new TreeNode<int>(rootData);
	//now we will get the no of childrens from the user
	int n;
	cout<<"ENTER THE NO OF CHILDREN'S OF NODE  "<<rootData<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		TreeNode<int> *child = takeInput();
		//put the child in the root node
		root->children.push_back(child);
	}
	return root;
}
void printTree(TreeNode<int> *root)
{   
    //edge case when we get an empty tree we simply return
	if(root==NULL)
	{
		return;
	}
	//print the data of the root node
	cout<<root->data<<" -> ";
	//print the data of the children of root node
	for(int i=0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	//recursively call for smaller tree to print the data
	for(int i=0;i<root->children.size();i++)
	{
		printTree(root->children[i]);
	}
}
int main()
{
	/*TreeNode<int> *root = new TreeNode<int>();
    root->data = 12;
    to avoid this two steps at making every node we can make use of constructor*/
    //TreeNode<int> *root = new TreeNode<int>(10);
    //TreeNode<int> *node1 = new TreeNode<int>(20);
    //TreeNode<int> *node2 = new TreeNode<int>(30);
    //now putting the address of node1 and node2 in root node
    //root->children.push_back(node1);
    //root->children.push_back(node2);
    //printTree(root);
    TreeNode<int> *root = takeinputlevelwise();
    cout<<countNodes(root)<<endl;
    //printTree(root);
    printLevelWise(root);
}

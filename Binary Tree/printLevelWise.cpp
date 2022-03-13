void printLevelWise(BinaryTreeNode<int> *root) 
{
	//check if the root is null then print -1
    if(root==NULL)
    {
        cout<<"-1";
        return;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    //push the root node in the queue
    pendingNodes.push(root);
    //run a loop while queue is not empty
    while(pendingNodes.size()!=0)
    {
        //get the front node from the queue
        BinaryTreeNode<int> *front = pendingNodes.front();
        //pop the front node from the queue
        pendingNodes.pop();
        //now print the front data
        cout<<front->data<<":";
        //now print left and right if it is not null
        if(front->left==NULL)
        {
            cout<<"L:-1,";
        }
        else if(front->left!=NULL)
        {
            cout<<"L:"<<front->left->data<<",";
            //push in the queue
            pendingNodes.push(front->left);
        }
        //same for the right tree
        if(front->right==NULL)
        {
            cout<<"R:-1";
        }
        else if(front->right!=NULL)
        {
            cout<<"R:"<<front->right->data;
            //push in the queue
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

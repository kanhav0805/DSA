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
            {cout<<front->children[i]->data<<",";}
            //now add the children in the queue for further processing
            pendingPrint.push(front->children[i]);
        }
        cout<<endl;
    }
}

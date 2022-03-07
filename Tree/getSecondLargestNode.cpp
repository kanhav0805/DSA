TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) 
{
    //edge case when no tree is passed to the program
    if(root==NULL)
    {return NULL;}
    TreeNode<int> *max1 = NULL;
    TreeNode<int> *max2 = NULL;
    //make a queue of tree node pointer
    queue<TreeNode<int>*> pending;
    //push root in the queue
    pending.push(root);
    //run a loop till queue is not empty
    while(pending.empty()==false)
    {
        TreeNode<int> *front = pending.front();//get first node from the queue
        pending.pop();//removing tree node from queue
        if(max1==NULL)
        {
            max1 = front;
        }
        if(max1->data<front->data)
        {
            //make front as max1 and max1 as max2
            max2 = max1;
            max1 = front;
        }
        else if(max1->data>front->data)
        {
            if(max2==NULL)
            {max2 = front;}
            else if(max2->data<front->data)
            {max2 = front;}
            else if(max2->data>front->data)
            {max2 = max2;}
        }
        //putting the children in the queue
        for(int i=0;i<front->children.size();i++)
        {
            pending.push(front->children[i]);
        }
    }
    return max2;
}

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int>*> ans;
    if(root==NULL)
    {return ans;}
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    while(pending.size()!=0)
    {
        head = NULL;
        tail = NULL;
        int count = pending.size();
        for(int i=0;i<count;i++)
        {
            BinaryTreeNode<int> *front = pending.front();
            Node<int> *newNode = new Node<int>(front->data);
            pending.pop();
            //make the linked list
            if(head==NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else 
            {
                tail->next = newNode;
                tail = tail->next;
            }
            if(front->left!=NULL)
            {pending.push(front->left);}
            if(front->right!=NULL)
            {pending.push(front->right);}
        }
            ans.push_back(head);
     }
     return ans;   
}

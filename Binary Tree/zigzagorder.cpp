void zigZagOrder(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        cout<<" ";
        return;
    }
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    int count = 0;
    vector<int> ans;
    int level = 0;
    while(pending.size()!=0)
    {
        count = pending.size();
        ans.clear();
        for(int i=0;i<count;i++)
        {
            BinaryTreeNode<int> *front = pending.front();
            ans.push_back(front->data);
            pending.pop();
            if(front->left!=NULL)
            {pending.push(front->left);}
            if(front->right!=NULL)
            {pending.push(front->right);}
        }
        if(level%2==0)
        {
            for(int i=0;i<ans.size();i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        else if(level%2!=0)
        {
            reverse(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        level++;
    }
}

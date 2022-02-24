int findNode(Node *head, int n)
{
    int found = 0;
    bool flag = false;
    Node *temp = head;
    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            flag = true;
            break;
        }
        found++;
        temp = temp->next;
    }
    if(flag) return found;
    return -1;
}

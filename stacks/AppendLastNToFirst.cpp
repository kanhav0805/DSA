Node *appendLastNToFirst(Node *head, int n)
{
    if(head==NULL)
    {return NULL;}
   
    int length = 0;//for counting the length of linked list
    Node *temp = head;
    Node *last;//to keep track of last node
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {last = temp;}
        length++;
        temp = temp->next;
    }
     if(n==0 || n==length)
    {return head;}
    int index = length - n;//kb tk loop chlana hai
    Node *move = head;
    int i=0;
    while(i<index-1)
    {
        move = move->next;
        i++;
    }
    Node *first = move->next;
    last->next = head;
    move->next = NULL;
    head = first;
    return head;
}

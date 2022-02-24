class Stack {
	// Define the data members
    Node *head;
    int size;
   public:
    Stack() {
        head = NULL;
        size = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        if(head==NULL)
        {return true;}
        return false;
    }

    void push(int element) {
        Node *newNode = new Node(element);
        if(head==NULL)
        {head=newNode;}
        else
        {newNode->next = head;head = newNode;}
        size++;
    }

    int pop() {
       if(head==NULL)
       {return -1;}
       int ans = head->data;
       Node *ptr = head;
       head = head->next;
       delete ptr;
         size--;
       return ans;
       
    }

    int top() {
        if(head==NULL)
        {return -1;}
        return head->data;
    }
};

/************************************************************
 
    Following is the structure of the node class 
 
    class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

**************************************************************/

class Queue {
	// Define the data members
    Node *head;
    Node *tail;
    int size;
   public:
    Queue() {
		head = NULL;
        tail = NULL;
        size = 0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		// Implement the getSize() function
        return size;
	}

    bool isEmpty() {
		// Implement the isEmpty() function
        return (size==0);
	}

    void enqueue(int data) {
		// Implement the enqueue() function
        Node *newNode = new Node(data);
        if(head==NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else if(head!=NULL)
        {
            tail->next = newNode;
            tail = tail->next;
        }
        size++;
	}

    int dequeue() {
        //if linked list is empty
        if(head==NULL)
        {return -1;}
        int ans;
        Node *ptr = NULL;
        if(size==1)
        {
            ptr = head;
            ans = ptr->data;
            head = NULL;
            tail = NULL;
            delete ptr;
        }
        else if(size>1)
        {
            ptr = head;
            ans = ptr->data;
            head = head->next;
            delete ptr;
        }
        size--;
        return ans;
    }

    int front() {
        if(head==NULL)
        {
            return -1;
        }
        return head->data;
    }
};

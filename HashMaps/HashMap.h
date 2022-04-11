#include<iostream>
#include<string>
using namespace std;
//class map node which contains key,value and next pointer
template <typename V>
class mapNode
{
	public:
	string key;
	V value;
	mapNode* next;
	//making the constructor for this
	mapNode(string key,V value)
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
	//making the destructor for this function
	~mapNode()
	{
		delete next;
	}
};
//class of the map to store key and value
template <typename V>
class maps
{    
    public:
	//we need an array which will store the head of the linked list
	mapNode<V>** bucket;
	int size;//total elements in the map
	int numBucket;//bucket size
	//constructor to put the values
	maps()
	{
		size = 0;
		numsBucket = 5;
		//we need to make an array of size 5
		bucket = new mapNode<V>*[numsBucket];
		//intially it will be filled wit garbage we need to remove that
		for(int i=0;i<numsBucket;i++)
		{
			bucket[i] = NULL;
		}
	}
	//now destructor to delete the map
	~map()
	{
		//now firstly we will delete the linked list
		for(int i=0;i<numsBucket;i++)
		{
			delete bucket[i];
		}
		//now delete the empty map
		delete []bucket;
	}
	//function to get the total elements in the array
	int getSize()
	{return size;}
	//hash function
	private:
		int getBucketIndex(string key)
		{
			int hashcode = 0;
			int coefficient = 1;
			//format "abc"=a*p^2 + b*p^1 + c*p^0
			//travel array from behind
			for(int i=key.size()-1;i>=0;i--)
			{
				hashcode = hashcode + key[i]*coefficient;
				hashcode%numsBucket;
				coefficient*=37;
				//do modulus so that it is in int limit
				coefficient%numsBucket;
			}
			return hashcode%numsBucket;
		}
	//function to insert the value in the bucket
	public:
	void insert(string key,V value)
	{
		//we need to create a hash function which will give integer value to us
		int index = getBucketIndex(key);
		mapNode<V> *head = bucket[index];
		//now check if the key is already present in the map
		while(head!=NULL)
        {
         	if(head->key==key)
			 {
			 	head->value = value;
			 	return;
			 }
			 head = head->next;	
	    }
		//create a liked list node
		mapNode<V> *newNode = new mapNode(key,value);
		//make connection
		newNode->next = bucket[index];
		//now new head is our new node
		bucket[index] = newNode;
		size++;//to maitain the size
	}
	//function to remove an element
	V remove(string key)
	{
	   int index = getBucketIndex(key);
	   mapNode<V> head = bucket[index];
	   mapNode<V> prev = NULL;
	   while(head!=NULL)
	   {
	   	 if(head->key==key)
	   	 {
	   	   //when it is the first element of the linked list
		   if(prev==NULL)
		   {
		   	 bucket[index] = head->next;
		   }
		   else
		   {
		   	 prev->next = head->next;
		   }
		   //element delte krna hai
		   V value = head->value;
		   head->next = NULL;//to delete it alone
		   count--;
		   delete head;	
		   return value;
		 }
		 prev = head;
		 head = head->next;
	   }
	   return 0;
	}
	//function to get value corresponding to key
	V getValue(string key)
	{   
	    int index = getBucketIndex(key);
		mapNode<V> head = bucket[index];
		while(head!=NULL)
		{
			if(head->key==key)
			{
				return head->value;
			}
			head = head->next;
		}
		return 0;
	}
};

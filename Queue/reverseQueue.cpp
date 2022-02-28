void reverseQueue(queue<int> &input) 
{
	int size = input.size();
    //base case when the size of quque is 0 or 1 dont reverse
    if(size==0 || size==1)
    {return;}
    //call the recursive function to reverse the remaining list
    //remove first element
    int first = input.front();
    input.pop();
    reverseQueue(input);
    input.push(first);
    return;
}

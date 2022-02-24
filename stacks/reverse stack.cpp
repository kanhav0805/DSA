void reverseStack(stack<int> &input, stack<int> &extra) 
{
    int size = input.size();
    //base case when 1 or no element present
    if(size==0 || size==1)
    {return;}
    //save the top element of stack in a variable
    int first = input.top();
    //removing the top element
    input.pop();
    //calling recursion on the smaller stack and assuming it will be revrsed
    reverseStack(input,extra);
    //now smaller stack will be reversed
    //push into extra stack
    while(input.empty()!=true)
    {
        int element = input.top();
        extra.push(element);
        input.pop();
    }
    //now input stack is empty putting first in it
    input.push(first);
    //now getting all elements from extra to input
    while(extra.empty()!=true)
    {
        int element = extra.top();
        input.push(element);
        extra.pop();
    }
}

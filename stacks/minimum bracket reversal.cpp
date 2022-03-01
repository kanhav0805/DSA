#include<stack>
int countBracketReversals(string input) 
{
	int size = input.size();
    //when size is 0 no need to rverse simply return 0
    if(size==0)
    {return 0;}
    //is size of the string is odd means it cannot be balanced
    if(size%2!=0)
    {return -1;}
    //stack to store the brackets
    stack<int> dibba;
    //traverse the whole input string
    for(int i=0;i<size;i++)
    {
        char ch = input[i];
        //if ch is opening bracket simply push in stack
        if(ch=='{')
        {
            dibba.push(ch);
        }
        else if(ch=='}') //if ch is closing bracket the different cases
        {   //if stack is empty simply push closing bracket in stack
            if(dibba.empty())
            {
                dibba.push(ch);
            }
            else //if stack is not empty then there can be closing or opening bracket
            {
               if(dibba.top()=='{')
               {
                   //remove the top it will be balanced parenthesis
                   dibba.pop();
               }
               else if(dibba.top()=='}')
               {
                   //simply push the element in the stack
                   dibba.push(ch);
               }
            }
        }
    }
    //now checking the stack which is filled
    int count = 0;
    if(dibba.size()%2!=0)//it cannot be balnaced
    {return -1;}
    else
    {
        while(dibba.empty()==false)
        {
            char ch1 = dibba.top();
            dibba.pop();
            char ch2 = dibba.top();
            dibba.pop();
            if(ch1==ch2)
            {
                count = count + 1;
            }
            else if(ch1!=ch2)
            {
                count = count + 2;
            }
        }
    }
    return count;
}

#include<stack>
bool checkRedundantBrackets(string expression) 
{
	int size = expression.length();
    if(size==0 || size==1)
    {return false;}
    stack<char> dibba;
    for(int i=0;i<size;i++)
    {
        char ch = expression[i];
        int count = 0;
        if(ch==')')
        {
           while(dibba.empty()==false && dibba.top()!='(')
           {
               count++;
               dibba.pop();
           }
           if(count<=1)
           {return true;}
           else
           {dibba.pop();}
        }
        else
        {
            dibba.push(ch);
        }
        
    }
    return false;
}

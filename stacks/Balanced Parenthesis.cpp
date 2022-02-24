#include<stack>
bool isBalanced(string expression) 
{
    stack<char> dibba;
    for(int i=0;i<expression.length();i++)
    {
       if(expression[i]=='(')
       {
           dibba.push('(');
       }
       else if(expression[i]==')')
       {
           if(dibba.empty())
           {return false;}
           if(dibba.top()=='(')
           {dibba.pop();}
          
       }
    }
    if(dibba.empty())
    {return true;}
    return false;
}

#include<unordered_map>
int pairSum(int *arr, int n)
{
   unordered_map<int,int> h;
   //put the values in the map
   for(int i=0;i<n;i++)
   {
       h[arr[i]]++;
   }
   int count=0;
   //traverse the map and find the -ve of it in map
   for(int i=0;i<n;i++)
   {
       int num1 = arr[i];
       int num2 = -num1;
       if(num1==num2)
       {
           if(h[num1]>0)
           {int n = h[num1]-1;
           count = count + ((n*(n+1))/2);
           h[num1] = 0;}
       }
       if(h[num2]>0)
       {
           count = count + (h[num1]*h[num2]);
           h[num1] = 0;
           h[num2] = 0;
       }
   }
    return count;
}

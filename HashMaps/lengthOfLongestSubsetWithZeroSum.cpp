#include<unordered_map>
#include<climits>
#include<algorithm>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) 
{
   unordered_map<int,int> h;
   int maxi = 0;
   int sum = 0;
   for(int i=0;i<n;i++)
   {
       sum = sum + arr[i];
       //case when we get sum as 0
       if(sum==0)
       {
           maxi = i + 1;
          
       }
       else
       {if(h.find(sum)!=h.end()){maxi = max(maxi,i-h[sum]);}
        else{h[sum] = i;}
       }
   }
    return maxi;
}

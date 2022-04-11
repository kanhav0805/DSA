bool isMaxHeap(int arr[], int n) 
{
   if(n==0)
   {return true;}
   for(int i=0;i<n;i++)
   {
       int lcIndex = 2*i + 1;
       int rcIndex = 2*i + 2;
       if(lcIndex>=n && rcIndex>=n)
       {break;}
       if(lcIndex<n && (arr[i]<arr[lcIndex]))
       {return false;}
       if(rcIndex<n && (arr[i]<arr[rcIndex]))
       {return false;}
   }
   return true;
}

#include<unordered_map>
int pairSum(int *arr, int n) 
{
	unordered_map<int,int> h;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        int num1 = arr[i];
        int num2 = -arr[i];
        if(h.find(num2)!=h.end())
        {
            count = count + h[num2];
        }
        //push the current element in the map
        h[num1]++;
    }
    return count;
}

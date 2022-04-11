#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) 
{
	unordered_map<int,int> h;
    for(int i=0;i<n;i++)
    {
        h[arr[i]]++;
    }
    int count = 0;
    //trevel the whole array
    for(auto x:h)
    {
        int sum = x.first - k;
        if(sum<0)
        {continue;}
        if(h.find(sum)!=h.end())
        {
            if(sum==x.first)
            {
                int n = x.second;
                count = count + (n*(n-1)/2);
                x.second = 0;
            }
            else if(sum!=x.first)
            {
                count = count + (h[sum]*x.second);
            }
        }
        
    }
    return count;
}

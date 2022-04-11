#include<unordered_map>
#include<climits>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) 
{
   //put all elements in the map
    unordered_map<int,int> h;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {h[arr[i]]++;}
    //now check for the longest sequence
    int max = INT_MIN;
    int pehla = 0;
    for(int j=0;j<n;j++)
    {
        int i = arr[j];
        int currmax = 1;
        while(true)
        {
            if(h.find(i+1)!=h.end())
            {
                currmax++;
                i++;
            }
            else
            {
                break;
            }
        }
        if(currmax>max)
        {
            max = currmax;
            pehla = arr[j];
        }
    }
    int last = pehla + (max - 1);
    ans.push_back(pehla);
    ans.push_back(last);
    return ans;
}

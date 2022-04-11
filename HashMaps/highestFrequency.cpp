#include<unordered_map>
#include<climits>
int highestFrequency(int arr[], int n) 
{
    //first put the elements of the array in the unordered map
    unordered_map<int,int> count;
    for(int i=0;i<n;i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }
    //treverse the array once again to count the maximum frequency
    int max = INT_MIN;
    int element;
    for(int i=0;i<n;i++)
    {
        if(count[arr[i]]>max)
        {
            max = count[arr[i]];
            element = arr[i];
        }
    }
    return element;
}

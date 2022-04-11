//remove duplicates
#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
vector<int> removes(int *arr,int n)
{
	unordered_map<int,int> h;
	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		if(h.count(arr[i])>0)
		{
			continue;
		}
		else
		{
			h[arr[i]];
			ans.push_back(arr[i]);
		}
	
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	vector<int> ans = removes(arr,n);
	for(int i=0;i<ans.size();i++)
	{
	   cout<<ans[i]<<" ";
	}
}

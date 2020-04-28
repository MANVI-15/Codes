#include<bits/stdc++.h>
using namespace std;
long long int longest(long long int n,long long int *a)
{
	long long int dp[n]={1};
	int best;
	int cur_length;
	int ans;
	for(int i=1;i<n;i++)
	{
		cur_length=0;
		ans=INT_MIN;
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i])
			{
				cur_length=dp[j];
			}
			ans=max(ans,cur_length);
		}
		dp[i]=ans+1;

	}
	for(int i=0;i<n;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	best=*max_element(dp,dp+n);
	return best;

}
int main()
{
	long long int n;
	cin>>n;
	long long int *a=new long long int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<longest(n,a);
	return 0;
}

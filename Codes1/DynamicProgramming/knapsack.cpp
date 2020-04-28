#include<iostream>
using namespace std;
int knapsack(int *weight,int *value,int s,int n)
{
	int dp[n+1][s+1];
    for(int i=0;i<=n;i++)
    {
       dp[i][0] = 0;
	}

	for(int j=0;j<=s;j++)
    {
		dp[0][j] = 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s;j++)
		{
			if(weight[i]>s)
			{
               dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],value[i]+dp[i-1][j-weight[i]]);
			}
		}
	}

	return dp[n][s];
}

int main()
{
	int n,s;
	cin>>n>>s;
	int *weight=new int[n+1];
	int *value=new int[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>weight[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>value[i];
	}
    cout<<knapsack(weight,value,s,n)<<endl;
	return 0;
}

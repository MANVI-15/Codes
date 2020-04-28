#include<bits/stdc++.h>
using namespace std;
int dp[100]={0,1};
int fibo(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }

    int fib1=fibo(n-1);
    int fib2=fibo(n-2);
    dp[n]=fib1+fib2;
    return dp[n];
}
int fiboDP(int n)
{
    int dp[100]={0,1};
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];

    }
    return dp[n];
}
int countBoardPath(int start,int end)
{
    if(start==end)
    {
        return 1;
    }
    else if(start>end)
    {
        return 0;
    }
    int ans=0;
    for(int i=1;i<=6;i++)
    {
       ans=countBoardPath(start+i,end)+ans;
    }
    return ans;
}

int countmemo(int start,int end,int board[])
{
     if(start==end)
    {
        return 1;
    }
    if(start>end)
    {
        return 0;
    }
    if(board[start]!=0)
    {
        return board[start];
    }
    int ans=0;
    for(int i=1;i<=6;i++)
    {
       ans=ans+countmemo(start+i,end,board);
    }
    board[start]=ans;

    for(int j=0;j<10;j++)
    {
 		cout<<board[j]<<"	 ";
 	}
    return ans;
}
int countBoardPathMemo(int start,int end,int BoardDP[]){
    if(start==end)
    {
	return 1;
	}

	if(start>end)
    {
		return 0;
	}

	if(BoardDP[start]!=0)
    {
 		return BoardDP[start];
 	}

 	int count = 0;

 	for(int dice=1;dice<=6;dice++)
    {
 		count+=countBoardPathMemo(start+dice,end,BoardDP);
 	}

 	BoardDP[start] = count;

 	for(int i=0;i<10;i++)
    {
 		cout<<BoardDP[i]<<"	 ";
 	}
 	cout<<endl;

 	return count;
}
int countboardDP(int start,int end1)
{
    int boarddp[end1+1]={0};
    boarddp[end1]=1;
    for(int i=end1-1;i>=0;i--)
    {
       int ans=0;
       for(int j=1;i+j<=end1 && j<=6;j++)
       {
           ans=ans+boarddp[i+j];
       }
       boarddp[i]=ans;
    }
    for(int i=0;i<=10;i++)
    {
        cout<<boarddp[i]<<"  ";
    }
    cout<<endl;
    return boarddp[start];
}
int count_steps(int n)
{
    int ans1=INT_MAX;
    int ans2=INT_MAX;
    if(n==1)
    {
        return 0;
    }
    if(n%3==0)
    {
       ans1=1+count_steps(n/3);
    }
    if(n%2==0)
    {
      ans2=1+count_steps(n/2);
    }
    int ans3=1+count_steps(n-1);
    return(min(ans1,min(ans2,ans3)));
}
int steps[100]={0};
int count_steps_memo(int n)
{
    int ans1=INT_MAX;
    int ans2=INT_MAX;
    if(steps[n]!=0)
    {
        return steps[n];
    }
    if(n==1)
    {
        return 0;
    }
    if(n%3==0)
    {
       ans1=1+count_steps(n/3);
    }
    if(n%2==0)
    {
      ans2=1+count_steps(n/2);
    }
    int ans3=1+count_steps(n-1);
    return(steps[n]=min(ans1,min(ans2,ans3)));

}
int steps_DP(int n)
{
    int steps1[n+1]={0};
    steps[1]=0;
    for(int i=2;i<=n;i++)
    {
        int ans1=INT_MAX;
        int ans2=INT_MAX;
        int ans3=INT_MAX;
        if(i%3==0)
        {
            ans1=1+steps[i/3];
        }
        if(i%2==0)
        {
          ans2=1+steps[i/2];
        }
        ans3=steps[i-1]+1;
        steps[i]=min(ans1,min(ans2,ans3));

    }
    for(int i=0;i<=n;i++)
    {
        cout<<steps[i]<<" ";
    }
    cout<<endl;
    return steps[n];
}
int catalan_number(int n)
{
    if(n==0)
    {
        return 1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=ans+catalan_number(i-1)*catalan_number(n-i);
    }
    return ans;
}
int catalan[6]={0};
int catalan_number_memo(int n)
{
    if(n==0)
    {
        return 1;
    }
    if(catalan[n]!=0)
    {
        return catalan[n];
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=ans+catalan_number_memo(i-1)*catalan_number_memo(n-i);
    }
    for(int i=0;i<=6;i++)
    {
        cout<<catalan[i]<<"  ";
    }
    cout<<endl;
    catalan[n]=ans;
    return ans;
}
int catalan_DP(int n)
{
    int cat[n+1]={0};
    cat[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cat[i]=cat[i]+(cat[j-1]*cat[i-j]);
        }
    }
    for(int i=0;i<=n;i++)
    {
        cout<<cat[i]<<"  ";
    }
    cout<<endl;
    return cat[n];
}
int coin_change[1000]={0};
int coin_change1(int start,int *coin,int size)
{
   if(start==0)
   {
       return 0;
   }
   if(coin_change[start]!=0)
   {
       return coin_change[start];
   }
   int ans=INT_MAX;
   int ans1=0;
   for(int i=0;i<size;i++)
   {
       if((start-coin[i])>=0)
       {
        ans1=1+coin_change1(start-coin[i],coin,size);
        ans=min(ans,ans1);
       }
       else
       {
           break;
       }
   }
   coin_change[start]=ans;
   return ans;

}
int coin_change_DP(int n,int *coin,int size)
{
    int coin1[100]={0};
    /*for(int i=0;i<size;i++)
    {
        coin1[coin[i]]=1;
    }*/
    int ans=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        ans=INT_MAX;
        for(int j=0;j<size;j++)
        {
            if((i-coin[j])>=0)
            {
                ans=min(ans,coin1[i-coin[j]]);
            }
            else
            {
                break;
            }
        }
        coin1[i]=1+ans;
    }
    for(int i=0;i<=n;i++)
    {
        cout<<coin1[i]<<"   ";
    }
    cout<<endl;
    return coin1[n];
}
int wines_problem(int *wine,int start,int end,int year)
{
    if(start>end)
    {
        return 0;
    }
    int ans1=year*wine[start]+wines_problem(wine,start+1,end,year+1);
    int ans2=year*wine[end]+wines_problem(wine,start,end-1,year+1);
    int ans3=max(ans1,ans2);
    return ans3;
}
int wine_m[10][10]={0};
int wines_memo(int *wine,int start,int end,int year)
{
    if(start>end)
    {
        return 0;
    }
    if(wine_m[start][end]!=0)
    {
        return wine_m[start][end];
    }

    int ans1=year*wine[start]+wines_memo(wine,start+1,end,year+1);
    int ans2=year*wine[end]+wines_memo(wine,start,end-1,year+1);
    int ans3=max(ans1,ans2);
    wine_m[start][end]=ans3;
    for(int i=0;i<=4;i++)
    {
        for(int j=0;j<=4;j++)
        {
            cout<<wine_m[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    return ans3;

}

int step[10]={0};
int min_steps(int n,int k,int start)
{
     if(start>n)
     {
         return 0;
     }
     if(start==n)
     {
         return 1;
     }
     if(step[start]!=0)
     {
         return step[start];
     }
     int ans=0;
     for(int i=1;i<=k;i++)
     {
         ans=ans+min_steps(n,k,start+i);
     }
     step[start]=ans;
     return ans;
}
int ladder_DP(int n,int k,int start)
{
    int ladder[n+1]={0};
    ladder[n]=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<=k;j++)
        {
            if((i+j)<=n)
            {
              ladder[i]=ladder[i]+ladder[i+j];
            }
        }
    }
    return ladder[start];
}
int rod(int *cost,int n,int cur_length)
{
    if(cur_length<=0)
    {
        return 0;
    }
    int best=0;
    int ans=0;
    for(int i=1;i<=cur_length;i++)
    {
          if(cur_length-i>=0)
          {
           best=cost[i]+rod(cost,n,cur_length-i);
           ans=max(best,ans);
          }

    }
    return ans;
}
int rod_DP(int *cost,int n)
{
    int rod[n+1]={INT_MIN};
    rod[0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
          rod[i]=max(rod[i],cost[j]+rod[i-j]);
        }

    }
    return rod[n];
}
int friend1(int n)
{
    int friends[n+1]={0};
    friends[0]=0;
    friends[1]=1;
    friends[2]=2;
    for(int i=3;i<=n;i++)
    {
        friends[i]=friends[i-1]+(i-1)*friends[i-2];
    }
    for(int i=0;i<=n;i++)
    {
        cout<<friends[i]<<" ";
    }
    cout<<endl;
    return friends[n];
}

int main()
{
  //int n;
  //cin>>n;
  //cout<<fiboDP(n);
  cout<<".................."<<endl;
  //int start,end1;
  //cout<<"enter start:";
  //cin>>start;
 // cout<<"enter end:";
 // cin>>end1;
 // int board[11]={0};
  //board[10]=0;
  //cout<<countBoardPath(start,end1)<<endl;
  //cout<<".............."<<endl<<endl;
  //cout<<countmemo(start,end1,board);
  //cout<<endl<<endl;
  //cout<<"..............2..........."<<endl;
  //int BoardDP[11]={0};
  //BoardDP[10]=1;
  //cout<<countBoardPathMemo(start,end1,BoardDP);
  //cout<<countboardDP(start,end1);
  //int n;
  //cout<<"enter number";
  //cin>>n;
  //cout<<count_steps(n);
  //cout<<count_steps_memo(n);
  //cout<<steps_DP(n);
  //cout<<"enter number";
  //int n;
  //cin>>n;
  //cout<<catalan_number(n);
  //cout<<catalan_number_memo(n);
  //cout<<catalan_DP(n);
  /*int coin[]={1,2,5,10,20,50,100,200,500,2000};
  cout<<"enter amount";
  int n;
  cin>>n;
  cout<<coin_change_DP(n,coin,10);*/
  /*cout<<"enter no of bottles";
  int b;
  cin>>b;
  int wines[b];
  for(int i=0;i<b;i++)
  {
      cin>>wines[i];
  }
  cout<<wines_problem(wines,0,b-1,1)<<endl;
  cout<<endl<<wines_memo(wines,0,b-1,1);*/
  /*cout<<"enter n";
  int n,k;
  cin>>n;
  cout<<"enter k";
  cin>>k;
 // cout<<min_steps(n,k,0);
 cout<<ladder_DP(n,k,0);*/
 /*cout<<"enter length";
 int n;
 cin>>n;
 int cost[n+1]={0};
 int p;
 for(int i=1;i<=n;i++)
 {
     cin>>p;
     cost[i]=p;
 }
 //cout<<rod(cost,n,n);
 cout<<rod_DP(cost,n);*/
 cout<<"enter number of friends";
 int n;
 cin>>n;
 cout<<friend1(n);

}

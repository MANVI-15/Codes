#include<bits/stdc++.h>
using namespace std;
int min_cost(int **cost,int r,int c)
{
   int dp[r+1][c+1];
   for(int i=0;i<=r;i++)
   {
       for(int j=0;j<=c;j++)
       {
           dp[i][j]=INT_MAX;
       }
   }
   for(int i=r-1;i>=0;i--)
   {
       for(int j=c-1;j>=0;j--)
       {
           if(i==r-1 && j==c-1)
           {
               dp[i][j]=cost[i][j];
               continue;
           }
           dp[i][j]=cost[i][j]+min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
       }
   }
   for(int i=0;i<r;i++)
   {
       for(int j=0;j<c;j++)
       {
           cout<<dp[i][j]<<"   ";
       }
       cout<<endl;
   }
   cout<<endl;
   return dp[0][0];
}
int no_of_paths(int r,int c)
{
    int dp[r][c];
    for(int i=0;i<r;i++)
   {
       for(int j=0;j<c;j++)
       {
           dp[i][j]=0;
       }
   }
   dp[0][0]=1;
   for(int i=0;i<r;i++)
 {
   for(int j=0;j<c;j++)
   {
      if(i==0 && j>0)
      {
          dp[i][j]=dp[i][j-1];
      }
      else if(j==0 && i>0)
      {
          dp[i][j]=dp[i-1][j];
      }
      else if(i>0 &&  j>0)
      {
          dp[i][j]=dp[i-1][j]+dp[i][j-1];
      }
   }
 }
 cout<<endl;


   return dp[r-1][c-1];
}
int elephant_path(int r,int c,int k)
{
    int dp[r][c];
    for(int i=0;i<r;i++)
   {
       for(int j=0;j<c;j++)
       {
           dp[i][j]=0;
       }
   }
   dp[0][0]=1;
   for(int i=1;i<c;i++)
   {

      int p=k;
      for(int j=i-1;j>=0 && p>=0;j--,p--)
      {
          dp[0][i]=dp[0][j]+dp[0][i];
      }
   }
   for(int i=1;i<r;i++)
   {
       int p=k;
      for(int j=i-1;j>=0 && p>=0;j--,p--)
      {
          dp[i][0]=dp[j][0]+dp[i][0];
      }
   }
   for(int i=1;i<r;i++)
 {

   for(int j=1;j<c;j++)
   {
        int p=k;
        for(int f=j-1;f>=0 && p>=0;f--,p--)
        {

          dp[i][j]=dp[i][f]+dp[i][j];
        }
         p=k;
        for(int f=i-1;f>=0 && p>=0;f--,p--)
        {

          dp[i][j]=dp[f][j]+dp[i][j];
        }
    }
 }
 cout<<endl;
 for(int i=0;i<r;i++)
   {
       for(int j=0;j<c;j++)
       {

           cout<<dp[i][j]<<"   ";
       }
       cout<<endl;
   }
  return dp[r-1][c-1];

}
int robot_path(int **grid,int r,int c)
{
    int dp[r][c];
    for(int i=0;i<r;i++)
   {
       for(int j=0;j<c;j++)
       {
         if(grid[i][j]==-1)
         {
           dp[i][j]=0;
         }
       }
   }
   dp[0][0]=1;
   for(int i=0;i<r;i++)
 {
   for(int j=0;j<c;j++)
   {
       if(dp[i][j]==0)
       {
           continue;
       }
      else if(i==0 && j>0)
      {
          dp[i][j]=dp[i][j-1];
      }
      else if(j==0 && i>0)
      {
          dp[i][j]=dp[i-1][j];
      }
      else if(i>0 &&  j>0)
      {
          dp[i][j]=dp[i-1][j]+dp[i][j-1];
      }
   }
 }
 cout<<endl;
 for(int i=0;i<r;i++)
   {
       for(int j=0;j<c;j++)
       {

           cout<<dp[i][j]<<"   ";
       }
       cout<<endl;
   }
 return dp[r-1][c-1];

}
int main()
{
    /*cout<<"enter cost matrix row";
    int r;
    cin>>r;
    cout<<endl<<"enter cost matrix column";
    int c;
    cin>>c;
    int** cost=new int*[r];
    for(int i=0;i<r;i++)
    {
        cost[i]=new int[c];
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>cost[i][j];
        }
    }
    cout<<min_cost(cost,r,c);*/
    /*cout<<"enter the ending point";
    int r;
    int c;
    cin>>r>>c;
    cout<<no_of_paths(r,c);*/
    /*cout<<"enter the ending point";
    int r;
    int c;
    cin>>r>>c;
    cout<<"enter k";
    int k;
    cin>>k;
    cout<<elephant_path(r,c,k);*/
    cout<<"enter the ending point";
    int r;
    int c;
    cin>>r>>c;
    int** grid=new int*[r];
    for(int i=0;i<r;i++)
    {
        grid[i]=new int[c];
    }
    cout<<"enter the blocked cell";
    int p;
    cin>>p;
    int x,y;
    for(int i=0;i<p;i++)
    {
        cin>>x>>y;
        grid[x-1][y-1]=-1;
    }
    cout<<robot_path(grid,r,c);
}

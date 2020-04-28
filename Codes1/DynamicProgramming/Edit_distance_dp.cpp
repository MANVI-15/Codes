#include<bits/stdc++.h>
using namespace std;
int edit_distance_DP(char s1[],char s2[])
{

   int edit_DP[strlen(s1) + 1][strlen(s2) + 1]={0};


	int check = 0;
	for(int j=strlen(s2);j>=0;j--){
		edit_DP[strlen(s1)][j] = check;
		check++;
	}

	check = 0;
	for(int i=strlen(s1);i>=0;i--){
		edit_DP[i][strlen(s2)] = check;
		check++;
	}
    for(int i=strlen(s1)-1;i>=0;i--)
    {
        for(int j=strlen(s2)-1;j>=0;j--)
        {
            if(s1[i]==s2[j])
            {
                edit_DP[i][j] = edit_DP[i+1][j+1];
            }
            else
            {

                edit_DP[i][j]= 1 + min(edit_DP[i+1][j],min(edit_DP[i][j+1],edit_DP[i+1][j+1]));

            }
        }
    }

         for(int i=0;i<3;i++){
		for(int j=0;j<5;j++){
			cout<<edit_DP[i][j]<<" ";
		}
		cout<<endl;
	    }

    return edit_DP[0][0];
}
int main()
{
  char s1[]="man";
  char s2[]="janvi";

 cout<<edit_distance_DP(s1,s2);
 cout<<endl;
 cout<<editDistance_DP(s1,s2);

}

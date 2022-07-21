//23:23 - 23:29 - 21分
//膜拜柳神 23：50 - 25分
#include<iostream>
using namespace std;
string str;
int dp[1005][1005],MAX=1;
int main(){
    getline(cin,str);
    int len=str.length();
    for(int i=0;i<len;i++)dp[i][i]=1;
    for(int i=1;i<len;i++)
        if(str[i]==str[i-1])dp[i-1][i]=1,MAX=2;
        else dp[i-1][i]=0;
    for(int L=2;L<len;L++)
        for(int i=0;i<len;i++)
            for(int j=i+L;j<len;j++)
                if(str[i]==str[j]&&dp[i+1][j-1])
                    dp[i][j]=dp[i+1][j-1],MAX=L+1;
    cout<<MAX;
}
#include<iostream>
#include<vector>
#define MAXN 0x7fffffff
using namespace std;
int Mp[205][205],N,M,num1,num2,w,beg=0,tot_dis=0;
bool vis[205]={};
vector<int> ans;
int main(){
    cin>>N>>M;
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            if(i!=j)Mp[i][j]=MAXN;
            else Mp[i][j]=0;
    for(int i=0;i<M;i++){
        cin>>num1>>num2>>w;
        Mp[num1][num2]=w;
        Mp[num2][num1]=w;
    }
    for(int k=0;k<=N;k++){
        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++){
                if(Mp[i][k]!=MAXN&&Mp[k][j]!=MAXN)
                    if(Mp[i][j]>Mp[i][k]+Mp[k][j]){
                        Mp[i][j]=Mp[i][k]+Mp[k][j];
                        Mp[j][i]=Mp[i][k]+Mp[k][j];
                }
            }
        }
    }
    for(int i=0;i<=N;i++){
        int u=-1,MIN=MAXN;
        for(int j=0;j<=N;j++){
            if(!vis[j]&&Mp[beg][j]<MIN){
                u=j;
                MIN=Mp[beg][j];
            }
        }
        if(u==-1)break;
        tot_dis+=MIN;
        vis[u]=true;
        ans.push_back(u);
        beg=u;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i<ans.size()-1)cout<<' ';
        else cout<<endl;
    }
    if(ans.size()==N+1)cout<<tot_dis<<endl;
    else{
        vector<int> temp;
        for(int i=0;i<=N;i++)if(!vis[i])temp.push_back(i);
        for(int i=0;i<temp.size();i++){
            cout<<temp[i];
            if(i<temp.size()-1)cout<<' ';
            else cout<<endl;
        }
    }
    // for(int i=0;i<=N;i++){
    //     for(int j=0;j<=N;j++)
    //         if(Mp[i][j]==MAXN)cout<<"-1 ";
    //         else cout<<Mp[i][j]<<' ';
    //     cout<<endl;
    // }
}
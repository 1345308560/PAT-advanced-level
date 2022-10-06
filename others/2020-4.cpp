#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define MAXN 0x7fffffff
using namespace std;
int N,M,K;
int T1,T2,S,D,num[1005];
int dis[1005][1005];
int father[1005][1005],V[1005][1005]={};
vector<string> ans;
map<int,int> Mp;
void BFS(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++){
                if(dis[i][j]!=MAXN&&dis[k][i]!=MAXN&&dis[i][j]+dis[k][i]<dis[k][j]){
                    dis[k][j]=dis[k][i]+dis[i][j];
                    father[k][j]=i;
                }
            }
    bool vis[1005]={};
    bool is_good=true;
    for(int i=0;i<N;i++)if(Mp[i]==0)vis[i]=true;
    for(int i=0;i<K;i++){
        if(vis[num[i]]){
            if(father[num[i]]==num[i]){
                string str1="You may take test ";
                string str2=to_string(num[i]);
                string str3=" directly.";
                ans.push_back(str1+str2+str3);
            }
            else{
                int temp=num[i];
                vector<int> V2;
                while(father[temp]!=temp){
                    V2.push_back(father[temp]);
                    temp=father[temp];
                }
                string str;
                for(int i=0;i<V2.size();i++){
                    str+=to_string(V2[V2.size()-i-1])+"->";
                }
                str+=to_string(num[i]);
                ans.push_back(str);
            }
            for(int j=0;j<N;j++)
                if(V[num[i]][j]>0)
                    vis[j]=true;
        }
        else{
            is_good=false;
            ans.push_back("Error.");
        }
    }
    if(is_good)cout<<"Okay.\n";
    else cout<<"Impossible.\n";
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            father[i][j]=j;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dis[i][j]=MAXN;
    for(int i=0;i<M;i++){
        cin>>T1>>T2>>S>>D;
        Mp[T2]++;
        V[T1][T2]=1;
        dis[T1][T2]=1;
    }
    cin>>K;
    for(int i=0;i<K;i++)cin>>num[i];
    BFS();
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
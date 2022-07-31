// 14:56 - 15:55 - 30分
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
#define INF 0x7fffffff
using namespace std;
int N,M,K,D;
struct Node2{
    int id;
    double min_dis,ave_dis;
    bool operator<(const Node2 B){
        if(min_dis!=B.min_dis)return min_dis>B.min_dis;
        else if(ave_dis!=B.ave_dis)return ave_dis<B.ave_dis;
        else return id<B.id;
    }
};
struct Node{
    int tar,dist;
};
vector<Node> V[1055];
vector<Node2> ans;
void Dijkstra(int beg){
    bool vis[1055];
    int dis[1055];
    for(int i=0;i<N+M;i++){
        vis[i]=false;
        dis[i]=INF;
    }
    dis[beg]=0;
    for(int i=0;i<N+M;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<N+M;j++){
            if(!vis[j]&&dis[j]<MIN){
                u=j;
                MIN=dis[j];
            }
        }
        if(u==-1)break;
        vis[u]=true;
        for(int j=0;j<V[u].size();j++){
            int t_id=V[u][j].tar;
            int t_dis=V[u][j].dist;
            if(!vis[t_id]&&dis[u]+t_dis<dis[t_id]){
                dis[t_id]=dis[u]+t_dis;
            }
        }
    }
    //
    // cout<<"G"<<beg-N+1<<endl;
    // for(int i=0;i<N;i++)cout<<dis[i]<<' ';
    // cout<<endl;
    //
    bool is_ans=true;
    double sum=0,ave=0,min_dis=INF;
    for(int i=0;i<N;i++){
        if(dis[i]==INF||dis[i]>D){is_ans=false;break;}
        else {
            if(i!=beg&&dis[i]<min_dis)min_dis=dis[i];
            sum+=dis[i];
        }
    }
    if(!is_ans)return;
    else{
        ave=sum/N;
        Node2 temp;
        temp.id=beg;
        temp.min_dis=min_dis;
        temp.ave_dis=ave;
        ans.push_back(temp);
    }
}

int main(){
    cin>>N>>M>>K>>D;
    for(int i=0;i<K;i++){
        string str1,str2;
        int num1,num2,dist;
        cin>>str1>>str2>>dist;
        if(str1[0]=='G')num1=str1[1]-'0'+N-1;
        else num1=stoi(str1)-1;
        if(str2[0]=='G')num2=str2[1]-'0'+N-1;
        else num2=stoi(str2)-1;
        // 存入邻接表
        Node temp;
        temp.tar=num2;temp.dist=dist;
        V[num1].push_back(temp);
        temp.tar=num1;
        V[num2].push_back(temp);
    }
    for(int i=N;i<N+M;i++)Dijkstra(i);
    sort(ans.begin(),ans.end());
    if(ans.size()==0){
        cout<<"No Solution";
    }
    else{
        cout<<"G"<<ans[0].id-N+1<<endl;
        printf("%.1f %.1f",ans[0].min_dis,ans[0].ave_dis);
    }
}
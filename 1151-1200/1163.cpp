#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
const int MAXN=0x7fffffff;
int Nv,Ne,K,num1,num2,w,plan[1005];
int vis[1005],dis[1005];
struct Node{
    int des,dis;
};
vector<Node> V[1005];
bool check(){
    int beg=plan[0];
    fill(vis,vis+Nv+1,false);
    fill(dis,dis+Nv+1,MAXN);
    dis[beg]=0;
    for(int i=0;i<Nv;i++){
        int MIN=MAXN;
        for(int j=1;j<=Nv;j++)
            if(!vis[j]&&dis[j]<MIN)
                MIN=dis[j];
        if(dis[plan[i]]!=MIN||vis[plan[i]])return false;
        int u=plan[i];
        vis[u]=true;
        for(int j=0;j<V[u].size();j++){
            int n_des=V[u][j].des,n_dis=V[u][j].dis;
            if(!vis[n_des]&&dis[u]+n_dis<dis[n_des])
                dis[n_des]=dis[u]+n_dis;
        }
    }
    return true;
}
int main(){
    cin>>Nv>>Ne;
    for(int i=0;i<Ne;i++){
        cin>>num1>>num2>>w;
        V[num1].push_back(Node{num2,w});
        V[num2].push_back(Node{num1,w});
    }
    cin>>K;
    for(int i=0;i<K;i++){
        for(int j=0;j<Nv;j++)cin>>plan[j];
        if(check())cout<<"Yes\n";
        else cout<<"No\n";
    }
}
// 10:25 - 11:01 - 23分
#include<iostream>
#include<vector>
#define MAXN 0x7fffffff
using namespace std;
int N,M,num1,num2,flag,length,t,beg,stop,dis1,ti1;
vector<int> ans1,ans2;
struct Node{
    int des,dis,t;
    Node(int d1,int d2,int t1){
        des=d1;dis=d2;t=t1;
    }
};
vector<Node> V[505];
void Dijkstra1(int beg,int stop){
    bool vis[505]={};
    int distance[505],father[505],ti[505];
    for(int i=0;i<N;i++)father[i]=i;
    fill(distance,distance+N,MAXN);
    fill(ti,ti+N,MAXN);
    distance[beg]=0;
    ti[beg]=0;
    for(int i=0;i<N;i++){
        int u=-1,MIN=MAXN;
        for(int j=0;j<N;j++){
            if(!vis[j]&&distance[j]<MIN){
                u=j;
                MIN=distance[j];
            }
        }
        if(u==-1)break;
        vis[u]=true;
        for(int j=0;j<V[u].size();j++){
            int d_des=V[u][j].des;
            int d_dis=V[u][j].dis;
            if(!vis[d_des]&&distance[u]+d_dis<distance[d_des]){
                distance[d_des]=distance[u]+d_dis;
                father[d_des]=u;
                ti[d_des]=ti[u]+V[u][j].t;
            }
            else if(!vis[d_des]&&distance[u]+d_dis==distance[d_des]){
                if(ti[u]+V[u][j].t<ti[d_des]){
                    ti[d_des]=ti[u]+V[u][j].t;
                    father[d_des]=u;
                }
            }
        }
    }
    dis1=distance[stop];
    while(stop!=beg){
        ans1.push_back(stop);
        stop=father[stop];
    }
}
void Dijkstra2(int beg,int stop){
    bool vis[505]={};
    int distance[505],father[505],ti[505];
    for(int i=0;i<N;i++)father[i]=i;
    fill(distance,distance+N,MAXN);
    fill(ti,ti+N,MAXN);
    distance[beg]=0;
    ti[beg]=0;
    for(int i=0;i<N;i++){
        int u=-1,MIN=MAXN;
        for(int j=0;j<N;j++){
            if(!vis[j]&&ti[j]<MIN){
                u=j;
                MIN=ti[j];
            }
        }
        if(u==-1)break;
        vis[u]=true;
        for(int j=0;j<V[u].size();j++){
            int d_des=V[u][j].des;
            int d_dis=V[u][j].dis;
            int d_ti=V[u][j].t;
            if(!vis[d_des]&&ti[u]+d_ti<ti[d_des]){
                ti[d_des]=ti[u]+d_ti;
                distance[d_des]=distance[u]+d_dis;
                father[d_des]=u;
            }
            else if(!vis[d_des]&&ti[u]+d_ti==ti[d_des]){
                if(distance[u]+d_dis<distance[d_des]){
                    distance[d_des]=distance[u]+d_dis;
                    father[d_des]=u;
                }
            }
        }
    }
    ti1=ti[stop];
    while(stop!=beg){
        ans2.push_back(stop);
        stop=father[stop];
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>num1>>num2>>flag>>length>>t;
        V[num1].push_back(Node(num2,length,t));
        if(flag==0)V[num2].push_back(Node(num1,length,t));
    }
    cin>>beg>>stop;
    Dijkstra1(beg,stop);
    Dijkstra2(beg,stop);
    if(beg==stop){
        cout<<"Distance = 0; Time = 0: "<<beg<<" -> "<<stop;
        return 0;
    }
    if(ans1!=ans2){
        cout<<"Distance = "<<dis1<<": ";
        cout<<beg;
        for(int i=0;i<ans1.size();i++){
            cout<<" -> "<<ans1[ans1.size()-i-1];
        }
        cout<<endl;
        cout<<"Time = "<<ti1<<": ";
        cout<<beg;
        for(int i=0;i<ans2.size();i++){
            cout<<" -> "<<ans2[ans2.size()-i-1];
        }
    }
    else{
        cout<<"Distance = "<<dis1<<"; ";
        cout<<"Time = "<<ti1<<": ";
        cout<<beg;
        for(int i=0;i<ans2.size();i++){
            cout<<" -> "<<ans2[ans2.size()-i-1];
        }
    }
    
}
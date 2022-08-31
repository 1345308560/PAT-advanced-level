#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define MAXN 0x7fffffff
using namespace std;
struct Node{
    int des,line;
};
map<int,int> Mp,Mp2;
vector<Node> V[10005];
int N,M,K,num[105],cnt=0;
void Dijkstra(int beg,int stop){
    beg=Mp[beg]; stop=Mp[stop];
    bool vis[10005]={};
    int dis[10005],father[10005],line[10005],tf[10005];
    fill(tf,tf+cnt,0);
    fill(dis,dis+cnt,MAXN);
    fill(line,line+cnt,0);
    for(int i=0;i<cnt;i++)father[i]=i;
    dis[beg]=0;
    for(int i=0;i<cnt;i++){
        int u=-1,MIN=MAXN;
        for(int j=0;j<cnt;j++){
            if(!vis[j]&&dis[j]<MIN){
                u=j;
                MIN=dis[j];
            }
        }
        if(u==-1)break;
        vis[u]=true;
        for(int j=0;j<V[u].size();j++){
            int des=V[u][j].des;
            if(dis[des]>dis[u]+1){
                dis[des]=dis[u]+1;
                father[des]=u;
                line[des]=V[u][j].line;
                if(line[des]!=line[u])tf[des]=tf[u]+1;
                else tf[des]=tf[u];
            }
            else if(dis[des]==dis[u]+1){
                if(V[u][j].line!=line[u]&&tf[u]+1<tf[des]){
                    line[des]=V[u][j].line;
                    tf[des]=tf[u]+1;
                    father[des]=u;
                }
                else if(V[u][j].line==line[u]&&tf[u]<tf[des]){
                    line[des]=V[u][j].line;
                    tf[des]=tf[u];
                    father[des]=u;
                }
            }
        }
    }
    vector<int> path,path2;
    int temp=stop;
    while(1){
        if(temp==beg){
            path.push_back(beg);
            break;
        }
        else{
            path.push_back(temp);
            temp=father[temp];
        }
    }
    reverse(path.begin(),path.end());
    cout<<dis[stop]<<endl;
    line[path[0]]=line[path[1]];
    path2.push_back(path[0]);
    for(int i=1;i<path.size();i++){
        // cout<<Mp2[path[i]]<<' '<<line[path[i]]<<endl;
        if(line[path[i]]!=line[path[i-1]])
            path2.push_back(path[i-1]);
        if(i==path.size()-1)path2.push_back(path[i]);
    }

    for(int i=1;i<path2.size();i++){
        cout<<"Take Line#"<<line[path2[i]]<<" from ";
        cout<<Mp2[path2[i-1]]<<" to "<<Mp2[path2[i]]<<".\n";
    }

}
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>M;
        for(int j=0;j<M;j++){
            cin>>num[j];
            if(Mp.count(num[j])==0){
                Mp[num[j]]=cnt;
                Mp2[cnt]=num[j];
                cnt++;
            }
            if(j>0){
                V[Mp[num[j]]].push_back(Node{Mp[num[j-1]],i});
                V[Mp[num[j-1]]].push_back(Node{Mp[num[j]],i});
            }
        }
    }
    cin>>K;
    for(int i=0;i<K;i++){
        int beg,stop;
        cin>>beg>>stop;
        Dijkstra(beg,stop);
    }
}
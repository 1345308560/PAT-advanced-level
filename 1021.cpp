#include<iostream>
#include<vector>
using namespace std;
int N,l,r;
int root[10005];
bool vis1[10005];
vector<int> V[10005];
int find_root(int num){
    if(num!=root[num])root[num]=find_root(root[num]);
    return root[num];
}
void m_union(int a,int b){
    int ra=find_root(a),rb=find_root(b);
    if(ra!=rb)root[ra]=rb;
}
void DFS(int num){
    if(vis[num])return;
    vis[num]=true;
    
}
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){root[i]=i;vis1[i]=false;}
    for(int i=0;i<N;i++){
        cin>>l>>r;
        V[l].push_back(r);
        V[r].push_back(l);
        m_union(l,r);
    }
    int cnt=0;
    for(int i=1;i<=N;i++)if(root[i]==i)cnt++;
    if(cnt>1){
        cout<<"Error: "<<cnt<<" components";
        return 0;
    }
    DFS(1);
}
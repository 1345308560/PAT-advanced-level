// 10:24
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
int N,K,num,id,l;
double P,r;
vector<int> V[100005];
bool vis[100005]={};
void BFS(){
    queue<int> Q;
    Q.push(0);
    vis[0]=true;
    for(int i=1;;i++){
        int s=Q.size();
        int cnt=0;
        for(int j=0;j<s;j++){
            int temp=Q.front();
            Q.pop();
            if(V[temp].size()==0){l=i;cnt++;}
            for(int k=0;k<V[temp].size();k++){
                if(!vis[V[temp][k]]){
                    Q.push(V[temp][k]);
                    vis[V[temp][k]]=true;
                }
            }
        }
        if(cnt){id=cnt;return;}
    }
}
int main(){
    cin>>N>>P>>r;
    r/=100;
    for(int i=0;i<N;i++){
        cin>>K;
        for(int j=0;j<K;j++){
            cin>>num;
            V[i].push_back(num);
        }
    }
    BFS();
    printf("%.4f %d",P*pow(1+r,l-1),id);
}
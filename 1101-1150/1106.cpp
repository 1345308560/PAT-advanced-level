//20:23 - 20:35 - 25分
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int N,K,num,ans=1,ans2=1;
double P,r;
vector<int> V[100005];
queue<int> Q;
void BFS(){
    Q.push(0);
    for(int i=0;!Q.empty();i++){
        int s=Q.size(),cnt=0;
        for(int j=0;j<s;j++){
            int id=Q.front();
            Q.pop();
            if(V[id].size()==0&&cnt==0){
                ans=i;
                cnt=1;
            }
            else if(V[id].size()==0&&cnt>0)cnt++;
            for(int k=0;k<V[id].size();k++)
                Q.push(V[id][k]);
        }
        if(cnt){
            ans2=cnt;
            return;
        }
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
    printf("%.4f %d",P*pow(1+r,ans),ans2);
}
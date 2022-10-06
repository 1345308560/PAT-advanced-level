#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,num1,num2;
int ans_beg,ans_num=-1;
vector<int> V[105];
void check(int n){
    bool vis[105]={};
    int temp=1,tn=n;
    for(int i=0;i<N;i++){
        vis[n]=true;
        for(int j=0;j<V[n].size();j++){
            if(!vis[V[n][j]]){
                n=V[n][j];
                temp++;
                break;
            }
        }
    }
    if(temp>ans_num){
        ans_num=temp;
        ans_beg=tn;
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>num1>>num2;
        V[num1].push_back(num2);
        V[num2].push_back(num1);
    }
    for(int i=1;i<=N;i++)sort(V[i].begin(),V[i].end());
    for(int i=1;i<=N;i++)check(i);
    cout<<ans_beg<<' '<<ans_num;
}
// 11:07 - 12:09 - 9分
//       - 12:10 - 25分
#include<iostream>
#include<vector>
#define MAXN 0x7fffffff
using namespace std;
int N,M,num1,num2,w,K,n,num[1005],min_w=MAXN,min_id=1;
struct Node{
    int index,w;
    Node(int i,int ww){
        index = i;
        w=ww;
    };
};
vector<Node> V[205],temp;
void check(int id){
    bool is_ts=true,is_simple=true;
    int vis[205]={},dis=0;
    for(int i=0;i<n-1;i++){
        bool find_path=false;
        for(int j=0;j<V[num[i]].size();j++){
            if(num[i+1]==V[num[i]][j].index){
                find_path=true;
                if(dis!=MAXN)dis+=V[num[i]][j].w;
            }
        }
        if(!find_path)dis=MAXN;
        else vis[num[i]]++;
    }
    if(dis==MAXN){
        is_ts=false;
        cout<<"NA";
    }
    else{
        cout<<dis;
        for(int i=1;i<=N;i++)
            if(!vis[i])is_ts=false;
            else if(vis[i]>1)is_simple=false;
        if(num[0]!=num[n-1])is_ts=false;
        if(min_w>dis&&is_ts){
            min_w=dis;
            min_id=id;
        }
    }
    if(is_ts&&is_simple)cout<<" (TS simple cycle)";
    else if(is_ts)cout<<" (TS cycle)";
    else cout<<" (Not a TS cycle)";
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>num1>>num2>>w;
        Node temp1(num2,w),temp2(num1,w);
        V[num1].push_back(temp1);
        V[num2].push_back(temp2);
    }
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>n;
        for(int j=0;j<n;j++)cin>>num[j];
        cout<<"Path "<<i+1<<": ";
        check(i+1);
        cout<<"\n";
    }
    cout<<"Shortest Dist("<<min_id<<") = "<<min_w;
}
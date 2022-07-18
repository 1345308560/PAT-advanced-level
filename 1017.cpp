#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
int N,K;
struct Node{
    string t;
    int st;
    bool operator < (const Node B)const{
        return t<B.t;
    }
}C[10005];
priority_queue<int,vector<int>,greater<int> > Pq;
int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++)cin>>C[i].t>>C[i].st;
    sort(C,C+N);
    double sum,ans,num;
    for(int i=0;i<K;i++)Pq.push(0);
    for(int i=0;i<N;i++){
        if(C[i].t<"08:00:00"){
            int h=stoi(C[i].t.substr(0,2));
            int m=stoi(C[i].t.substr(3,2));
            int s=stoi(C[i].t.substr(6,2));
            sum+=(8*60*60-h*60*60-m*60-s);  // 等待时间
            num++;                          // 增加人数
            // 排队
            int MIN=Pq.top();Pq.pop();
            sum+=MIN;
            MIN+=C[i].st*60;
            Pq.push(MIN);
        }
        else if(C[i].t>"17:00:00")break;
        else{
            int h=stoi(C[i].t.substr(0,2));
            int m=stoi(C[i].t.substr(3,2));
            int s=stoi(C[i].t.substr(6,2));
            int MIN=Pq.top();Pq.pop();
            if(MIN<=h*60*60+m*60+s-8*60*60);
            else sum+=(MIN-(h*60*60+m*60+s-8*60*60));
            MIN+=C[i].st*60;
            Pq.push(MIN);
            num++;
        }
    }
    if(num==0)printf("0.0");
    else printf("%.1f",sum/60/num);
}
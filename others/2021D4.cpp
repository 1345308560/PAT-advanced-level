#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#define MAXN 0x7fffffff
using namespace std;
int N,M,K,h,m,t,num1,num2,d;
int at,am=-999999999;
int dis[1005][1005],plan[1005];
struct Node{
    int h,m,t,Y,P;
}package[1005];
void check(){
    int ans_m=0,ans_t=t,beg=0;
    bool vis[1005]={};
    for(int i=0;i<N;i++){
        ans_t+=dis[beg][plan[i]];
        if(ans_t>package[plan[i]].t)ans_m-=package[plan[i]].P;
        ans_m+=package[plan[i]].Y;
        vis[plan[i]]=true;
        beg=plan[i];
    }
    ans_t+=dis[beg][0];
    for(int i=1;i<=N;i++)if(!vis[i])return;
    if(ans_m>am){
        am=ans_m;
        at=ans_t;
    }
    else if(ans_m==am){
        if(ans_t<at)
            at=ans_t;
    }
}
int main(){
    scanf("%d %d %d:%d",&N,&M,&h,&m);
    t=h*60+m;
    for(int i=1;i<=N;i++){
        scanf("%d:%d",&package[i].h,&package[i].m);
        package[i].t=package[i].h*60+package[i].m;
        scanf("%d %d",&package[i].Y,&package[i].P);
    }
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            dis[i][j]=MAXN;
    for(int i=0;i<M;i++){
        cin>>num1>>num2>>d;
        dis[num1][num2]=min(d,dis[num1][num2]);
        dis[num2][num1]=min(d,dis[num2][num1]);
    }
    for(int k=0;k<=N;k++)
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++){
                if(dis[i][k]!=MAXN&&dis[k][j]!=MAXN)
                    if(dis[i][k]+dis[k][j]<dis[i][j])
                        dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
            }
    cin>>K;
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++)cin>>plan[j];
        check();
    }
    printf("%d %02d:%02d",am,(at/60)%24,at%60);
}   
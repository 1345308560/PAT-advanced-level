//10:53
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int N,M,K;
int full_mark[7];
struct Student{
    int user_id,sum,pf=0,rnk,be_pr=0;
    int V[6]={-2,-2,-2,-2,-2,-2};
    bool operator<(const Student other){
        if(sum!=other.sum) return sum>other.sum;
        else if(pf!=other.pf) return pf>other.pf;
        else return user_id<other.user_id;
    }
}St[10005];
int main(){
    cin>>N>>K>>M;
    for(int i=0;i<K;i++)cin>>full_mark[i+1];
    for(int i=0;i<M;i++){
        int user_id,id,score;
        cin>>user_id>>id>>score;
        if(score>=0)St[user_id].be_pr=1;
        St[user_id].user_id=user_id;
        St[user_id].V[id]=max(St[user_id].V[id],score);
    }
    for(int i=1;i<N+1;i++){
        int sum=0;
        for(int j=1;j<=K;j++)
            if(St[i].V[j]>0){
                sum+=St[i].V[j];
                if(St[i].V[j]==full_mark[j])St[i].pf++;
            }
        if(!St[i].be_pr)sum=-1;
        St[i].sum=sum;
    }
    sort(St+1,St+1+N);
    for(int i=1;i<=N&&St[i].sum>0;i++){
        if(St[i].sum==St[i-1].sum)St[i].rnk=St[i-1].rnk;
        else St[i].rnk=i;
        printf("%d %05d %d",St[i].rnk,St[i].user_id,St[i].sum);
        for(int j=1;j<=K;j++)
            if(St[i].V[j]==-1)cout<<" "<<0;
            else if(St[i].V[j]==-2)cout<<" -";
            else cout<<" "<<St[i].V[j];
        if(i<N)cout<<endl;
    }
}
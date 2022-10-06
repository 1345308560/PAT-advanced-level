#include<iostream>
#include<algorithm>
using namespace std;
int N,ans=0;
int dis[10005]={},num2[10005];
struct Node{
    int pos,weight;
    bool operator<(Node other)const{
        return weight<other.weight;
    }
}num[10005];
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num2[i];
        num[i].weight=num2[i];
        num[i].pos =i;
    }
    sort(num,num+N);
    for(int i=0;i<N;i++){
        if(dis[num[i].pos]>0)continue;

        if(num[i].pos==0){
            if(dis[num[i].pos+1]==0){
                dis[num[i].pos]=200;
                if(num2[num[i].pos+1]==num[i].weight)
                    dis[num[i].pos+1]=200;
            }
            else dis[num[i].pos]=dis[num[i].pos+1]+100;
        }
        else if(num[i].pos==N-1){
            if(dis[num[i].pos-1]==0){
                dis[num[i].pos]=200;
                if(num2[num[i].pos-1]==num[i].weight)
                    dis[num[i].pos-1]=200;
            }
            else dis[num[i].pos]=dis[num[i].pos-1]+100;
        }
        else{
            if(dis[num[i].pos-1]==0&&dis[num[i].pos+1]==0){
                dis[num[i].pos]=200;
            }
            else {
                if(dis[num[i].pos-1]==0&&dis[num[i].pos+1]>0){
                    if(num[i].weight==num2[num[i].pos+1]){
                        dis[num[i].pos]=dis[num[i].pos+1];
                    }
                    else dis[num[i].pos]=dis[num[i].pos+1]+100;
                }
                else if(dis[num[i].pos-1]>0&&dis[num[i].pos+1]==0){
                    if(num[i].weight==num2[num[i].pos-1]){
                        dis[num[i].pos]=dis[num[i].pos-1];
                    }
                    else dis[num[i].pos]=dis[num[i].pos-1]+100;
                }
                else{
                    if(num[i].weight==num2[num[i].pos+1])
                        dis[num[i].pos]=dis[num[i].pos+1];
                    else if(num[i].weight==num2[num[i].pos-1])
                        dis[num[i].pos]=dis[num[i].pos-1];
                    else{
                        dis[num[i].pos]=max(dis[num[i].pos+1],dis[num[i].pos-1])+100;
                    }
                }
            }
        }
    }
    for(int i=0;i<N;i++)ans+=dis[i];
    cout<<ans;
}
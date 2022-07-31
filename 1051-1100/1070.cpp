//15:03 - 15:14 - 25分
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N,D;
double ans=0,now_D;
struct Node{
    double storage,price;
    double p;
    bool operator<(const Node B){
        return p>B.p;
    }
}Ns[1005];
int main(){
    cin>>N>>D;
    for(int i=0;i<N;i++)cin>>Ns[i].storage;
    for(int i=0;i<N;i++){
        cin>>Ns[i].price;
        Ns[i].p=1.0*Ns[i].price/Ns[i].storage;
    }
    sort(Ns,Ns+N);
    now_D=D;
    for(int i=0;now_D>0;i++){
        if(now_D>Ns[i].storage){
            ans+=Ns[i].price;
            now_D-=Ns[i].storage;
        }
        else{
            ans+=Ns[i].p*now_D;
            now_D=0;
        }
    }
    printf("%.2f",ans);
}
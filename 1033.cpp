#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int C,D,Dav,N;
struct Node{
    int pos;
    double price;
    bool operator<(const Node B)const{
        return pos<B.pos;
    }
}Np[505];
int main(){
    cin>>C>>D>>Dav>>N;
    for(int i=0;i<N;i++)cin>>Np[i].price>>Np[i].pos;
    sort(Np,Np+N);
    if(Np[0].pos!=0){
        cout<<"The maximum travel distance = 0.00";
        return 0;
    }
    double ans=0,now_dis=0,now_gas=0;
    int now_pos=0;
    while(now_dis<D){
        double now_price=Np[now_pos].price;  // 当前的价格
        double max_dis=Np[now_pos].pos+Dav*C;// 能行驶的最远距离
        int next_p;
        bool flag=false; // 是否有比现在更便宜的加油站
        for(int next_pos=now_pos+1;next_pos<N&&Np[next_pos].pos<=max_dis;next_pos++){
            if(Np[next_pos].price<=now_price){
                flag=true;
                next_p=next_pos;
            }
        }
        if(!flag){
            if(max_dis>=D){
                ans+=1.0*(D-now_dis)/Dav*now_price;
                printf("%.2f",ans);
                return 0;
            }
            else{
                
            }
        }
        else{
            ans+=1.0*(Np[next_p].pos-now_dis)/Dav*now_price;
            now_pos=next_p;
            now_dis=Np[next_p].pos;
        }
    }

}
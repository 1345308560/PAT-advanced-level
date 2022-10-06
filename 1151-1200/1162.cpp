#include<iostream>
using namespace std;
struct Node{
    string data;
    int l=-1,r=-1;
}Nt[25];
int N,ROOT=-1,cnt[25]={};
void LRM(int pos){

    if(pos==-1)return;
    cout<<"(";
    LRM(Nt[pos].l);
    if(Nt[pos].l==-1&&Nt[pos].r!=-1){
        cout<<Nt[pos].data;
        LRM(Nt[pos].r);
    }
    else{
        LRM(Nt[pos].r);
        cout<<Nt[pos].data;
    }
    cout<<")";
}
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>Nt[i].data>>Nt[i].l>>Nt[i].r;
        if(Nt[i].l!=-1)cnt[Nt[i].l]=1;
        if(Nt[i].r!=-1)cnt[Nt[i].r]=1;
    }
    for(int i=1;i<=N;i++)if(cnt[i]==0)ROOT=i; 
    LRM(ROOT);
}
#include<iostream>
using namespace std;
int N,num,ROOT=-1,cnt=0;
struct Node{
    int l=-1,r=-1,data;
}Nt[25];
int L(int root){
    int temp=Nt[root].r;
    Nt[root].r=Nt[temp].l;
    Nt[temp].l=root;
    return temp;
}
int R(int root){
    int temp=Nt[root].l;
    Nt[root].l=Nt[temp].r;
    Nt[temp].r=root;
    return temp;
}
int LL(int root){
    return R(root);
}
int RR(int root){
    return L(root);
}
int LR(int root){
    Nt[root].l=L(Nt[root].l);
    return R(root);
}
int RL(int root){
    Nt[root].r=R(Nt[root].r);
    return L(root);
}
int MaxH(int root){
    if(root==-1)return 0;
    return max(MaxH(Nt[root].l),MaxH(Nt[root].r))+1;
}
int INSERT(int root,int val){
    if(root==-1){
        Nt[cnt++].data=val;
        return cnt-1;
    }
    if(val>Nt[root].data){
        Nt[root].r=INSERT(Nt[root].r,val);
        if(MaxH(Nt[root].r)-MaxH(Nt[root].l)>1){
            if(val>Nt[Nt[root].r].data)return RR(root);
            else return RL(root);
        }
    }
    else{
        Nt[root].l=INSERT(Nt[root].l,val);
        if(MaxH(Nt[root].l)-MaxH(Nt[root].r)>1){
            if(val<Nt[Nt[root].l].data)return LL(root);
            else return LR(root);
        }
    }
    return root;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        ROOT=INSERT(ROOT,num);
    }
    cout<<Nt[ROOT].data;
}
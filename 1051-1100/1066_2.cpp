#include<iostream>
using namespace std;
struct Node{
    int data,l=-1,r=-1;
}tree[25];
int cnt=0,N,ROOT=-1;
int R(int root){
    int temp=tree[root].l;
    tree[root].l=tree[temp].r;
    tree[temp].r=root;
    return temp;
}
int L(int root){
    int temp=tree[root].r;
    tree[root].r=tree[temp].l;
    tree[temp].l=root;
    return temp;
}
int RR(int root){
    return L(root);
}
int LL(int root){
    return R(root);
}
int LR(int root){
    int temp=L(tree[root].l);
    tree[root].l=temp;
    return R(root);
}
int RL(int root){
    int temp=R(tree[root].r);
    tree[root].r=temp;
    return L(root);
}
int GetH(int pos){
    if(pos==-1)return 0;
    else return max(GetH(tree[pos].l),GetH(tree[pos].r))+1;
}
int Insert(int pos,int num){
    if(pos==-1){
        tree[cnt].data=num;
        cnt++;
        return cnt-1;
    }
    if(num<tree[pos].data){
        tree[pos].l=Insert(tree[pos].l,num);
        if(GetH(tree[pos].l)-GetH(tree[pos].r)>1){
            if(num<tree[tree[pos].l].data)return LL(pos);
            else return LR(pos);
        }
    }
    else{
        tree[pos].r=Insert(tree[pos].r,num);
        if(GetH(tree[pos].r)-GetH(tree[pos].l)>1){
            if(num>tree[tree[pos].r].data)return RR(pos);
            else return RL(pos);
        }
    }
    return pos;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        ROOT=Insert(ROOT,a);
    }
    
    cout<<tree[ROOT].data;
}
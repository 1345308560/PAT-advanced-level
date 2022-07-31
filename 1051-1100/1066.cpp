// 10:58 - 11:22 - 25分
// 必须记忆的板子
#include<iostream>
using namespace std;

struct Node{
    int data,l,r;
    Node(){l=r=-1;}    
}tree[25];

int ROOT=-1,num=0;

int L(int root){
    int temp=tree[root].r;
    tree[root].r=tree[temp].l;
    tree[temp].l=root;
    return temp;
}

int R(int root){
    int temp=tree[root].l;
    tree[root].l=tree[temp].r;
    tree[temp].r=root;
    return temp;
}

int LL(int root){
    int temp=R(root);
    return temp;
}

int RR(int root){
    int temp=L(root);
    return temp;
}

int LR(int root){
    tree[root].l=L(tree[root].l);
    int temp=R(root);
    return temp;
}

int RL(int root){
    tree[root].r=R(tree[root].r);
    int temp=L(root);
    return temp;
}

int getH(int root){
    if(root==-1)return 0;
    else return max(getH(tree[root].l),getH(tree[root].r))+1;
}

int insert(int root,int val){
    if(root==-1){
        tree[num].data=val;
        root=num;
        num++;
        return root;
    }
    
    if(val<tree[root].data){
        tree[root].l=insert(tree[root].l,val);
        if(getH(tree[root].l)-getH(tree[root].r)>=2){
            if(val<tree[tree[root].l].data)root=LL(root);
            else root=LR(root);
        }
    }
    else{
        tree[root].r=insert(tree[root].r,val);
        if(getH(tree[root].r)-getH(tree[root].l)>=2){
            if(val>tree[tree[root].r].data)root=RR(root);
            else root=RL(root);
        }
    }
    return root;
}

int N,num2[25];
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num2[i];
        ROOT=insert(ROOT,num2[i]);
    }
    cout<<tree[ROOT].data;
}
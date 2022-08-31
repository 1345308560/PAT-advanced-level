#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    int l=-1,r=-1;
}tree[25];
int ROOT=-1,N,num,cnt=0;
int tree2[105]={};
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
    return R(root);
}
int RR(int root){
    return L(root);
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
int MaxH(int root){
    if(root==-1)return 0;
    else return max(MaxH(tree[root].l),MaxH(tree[root].r))+1;
}
int Insert(int root,int val){
    if(root==-1){
        tree[cnt++].data=val;
        return cnt-1;
    }
    if(val>tree[root].data){
        tree[root].r=Insert(tree[root].r,val);
        if(MaxH(tree[root].r)-MaxH(tree[root].l)>1){
            if(val>tree[tree[root].r].data) return RR(root);
            else return RL(root);
        }
    }
    else{
        tree[root].l=Insert(tree[root].l,val);
        if(MaxH(tree[root].l)-MaxH(tree[root].r)>1){
            if(val<tree[tree[root].l].data) return LL(root);
            else return LR(root);
        }
    }
    return root;
}
void build(int root,int pos){
    if(root==-1)return;
    tree2[pos]=tree[root].data;
    build(tree[root].l,pos*2+1);
    build(tree[root].r,pos*2+2);
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        ROOT=Insert(ROOT,num);
    }
    build(ROOT,0);
    bool f=true;
    vector<int> V;
    for(int i=0;i<N;i++)
        if(tree2[i]==0)
            f=false;
        else V.push_back(tree2[i]); 
    for(int i=N;i<1005;i++)
        if(tree2[i]>0)
            V.push_back(tree2[i]);
    for(int i=0;i<N;i++){
        cout<<V[i];
        if(i<V.size()-1)cout<<' ';
    }
    cout<<endl;
    if(f)cout<<"YES\n";
    else cout<<"NO\n";
}
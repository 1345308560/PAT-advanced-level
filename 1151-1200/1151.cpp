#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<int,int> Mp1,Mp2;
int N,M,num1,num2;
int in[10005],pre[10005],root[10005];
void find_root(int l1,int r1,int l2,int r2,int rt){
    if(l1>r1||l2>r2)return;

    int n_rt=pre[l1],pos=l2;
    for(;pos<=r2;pos++)if(in[pos]==n_rt)break;
    root[n_rt]=rt;
    find_root(l1+1,l1+pos-l2,l2,pos-1,n_rt);// 左子树
    find_root(l1+pos-l2+1,r1,pos+1,r2,n_rt);
}
void check(){
    map<int,int> mp2;
    num1=Mp1[num1];
    num2=Mp1[num2];
    int rt1=num1,rt2=num2;
    while(rt1!=-1){
        if(rt1==num2){
            cout<<Mp2[num2]<<" is an ancestor of "<<Mp2[num1]<<".\n";
            return;
        }
        rt1=root[rt1];
    }
    while(rt2!=-1){
        if(rt2==num1){
            cout<<Mp2[num1]<<" is an ancestor of "<<Mp2[num2]<<".\n";
            return;
        }
        mp2[rt2]=1;
        rt2=root[rt2];
    }
    rt1=num1;rt2=num2;
    while(rt1!=-1){
        if(mp2.count(rt1)>0){
            cout<<"LCA of "<<Mp2[num1]<<" and "<<Mp2[num2]<<" is "<<Mp2[rt1]<<".\n";
            return ;
        }
        rt1=root[rt1];
    }
}
int main(){
    cin>>M>>N;
    for(int i=0;i<N;i++){
        cin>>in[i];
        Mp1[in[i]]=i;
        Mp2[i]=in[i];
        in[i]=Mp1[in[i]];
    }
    for(int i=0;i<N;i++){
        cin>>pre[i];
        pre[i]=Mp1[pre[i]];
    }
    // for(int i=0;i<N;i++)cout<<in[i]<<' ';
    // cout<<endl;
    // for(int i=0;i<N;i++)cout<<pre[i]<<' ';
    // cout<<endl;
    // fill(root,root+N,-1);
    find_root(0,N-1,0,N-1,-1);
    // for(int i=0;i<N;i++)cout<<root[i]<<' ';
    // cout<<endl;
    for(int i=0;i<M;i++){
        cin>>num1>>num2;
        if(Mp1.count(num1)==0&&Mp1.count(num2)==0){
            cout<<"ERROR: "<<num1<<" and "<<num2<<" are not found.\n";
        }
        else if(Mp1.count(num1)==0){
            cout<<"ERROR: "<<num1<<" is not found.\n";
        }
        else if(Mp1.count(num2)==0){
            cout<<"ERROR: "<<num2<<" is not found.\n";
        }
        else check();
    }
    
}
#include<iostream>
#include<map>
using namespace std;
int N,num,ROOT=-1,max_level=-1;
struct Node{
    int l=-1,r=-1,data;
}Nt[1005];
map<int,int> Mp;
int Insert(int n,int val,int pos,int l){
    max_level=max(l,max_level);
    if(n==-1){
        Nt[pos].data=val;
        Mp[l]++;
        return pos;
    }
    if(val<=Nt[n].data)
        Nt[n].l=Insert(Nt[n].l,val,pos,l+1);
    else Nt[n].r=Insert(Nt[n].r,val,pos,l+1);
    return n;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        ROOT=Insert(ROOT,num,i,0);
    }
    cout<<Mp[max_level]<<" + "<<Mp[max_level-1]<<" = "<<Mp[max_level]+Mp[max_level-1];
}
// 23:56 - 0:11 - 30分
#include<iostream>
#include<map>
using namespace std;
int N,max_level=0;
struct Node{
    int key,l=-1,r=-1;
}Nt[1005];
map<int,int> M;
void Insert(int key,int pos,int id,int l){
    max_level=max(max_level,l);
    if(key<=Nt[pos].key){
        if(Nt[pos].l==-1){
            Nt[pos].l=id;
            M[l]++;
        }
        else Insert(key,Nt[pos].l,id,l+1);
    }
    else{
        if(Nt[pos].r==-1){
            Nt[pos].r=id;
            M[l]++;
        }
        else Insert(key,Nt[pos].r,id,l+1);
    }
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Nt[i].key;
        if(i!=0)Insert(Nt[i].key,0,i,1);
        else M[0]=1;
    }
    cout<<M[max_level]<<" + "<<M[max_level-1]<<" = "<<M[max_level]+M[max_level-1];
}
//21:55 - 22:32 - 25分
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
map<int,int> M1,M2;
vector<int> V1,V2;
struct Node{
    int address,key,next;
}Nl[100005];
int N,beg,next;
int main(){
    cin>>beg>>N;
    for(int i=0;i<N;i++){
        cin>>Nl[i].address>>Nl[i].key>>Nl[i].next;
        M1[Nl[i].address]=i;
    }

    while(beg!=-1){
        if(M2.count(fabs(Nl[M1[beg]].key))==0){
            M2[fabs(Nl[M1[beg]].key)]=1;
            V1.push_back(M1[beg]);
        }
        else V2.push_back(M1[beg]);
        beg=Nl[M1[beg]].next;
    }
    for(int i=0;i<V1.size();i++){
        if(i<V1.size()-1)printf("%05d %d %05d\n",Nl[V1[i]].address,Nl[V1[i]].key,Nl[V1[i+1]].address);
        else printf("%05d %d -1\n",Nl[V1[i]].address,Nl[V1[i]].key);
    }
    for(int i=0;i<V2.size();i++){
        if(i<V2.size()-1)printf("%05d %d %05d\n",Nl[V2[i]].address,Nl[V2[i]].key,Nl[V2[i+1]].address);
        else printf("%05d %d -1\n",Nl[V2[i]].address,Nl[V2[i]].key);
    }
}
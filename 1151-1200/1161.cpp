#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;
int L1,L2,N,cnt=0;
map<int,int> Mp;
struct Node{
    int address,data,next;
}Nl[100005];
vector<int> V1,V2,V3;
int main(){
    cin>>L1>>L2>>N;
    for(int i=0;i<N;i++){
        cin>>Nl[i].address>>Nl[i].data>>Nl[i].next;
        Mp[Nl[i].address]=cnt++;
    }
    while(L1!=-1){
        V1.push_back(Mp[L1]);
        L1=Nl[Mp[L1]].next;
    }
    while(L2!=-1){
        V2.push_back(Mp[L2]);
        L2=Nl[Mp[L2]].next;
    }
    if(V1.size()>V2.size())swap(V1,V2);
    int p1=V1.size()-1,p2=0;
    while(p1>=0||p2<V2.size()){
        if(p2<V2.size())
            V3.push_back(V2[p2++]);
        if(p2<V2.size())
            V3.push_back(V2[p2++]);
        if(p1>=0)
            V3.push_back(V1[p1--]);
    }
    for(int i=0;i<V3.size();i++){
        if(i!=V3.size()-1)
            printf("%05d %d %05d\n",Nl[V3[i]].address,Nl[V3[i]].data,Nl[V3[i+1]].address);
        else printf("%05d %d %d",Nl[V3[i]].address,Nl[V3[i]].data,-1);
    }
} 
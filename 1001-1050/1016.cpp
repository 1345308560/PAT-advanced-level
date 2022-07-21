#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
    string name;
    string t;
    string flag;
    bool operator < (const Node B)const{
        if(name!=B.name)return name<B.name;
        else return t<B.t;
    }
}L[1005];
int rate[24],N;
int main(){
    for(int i=0;i<24;i++)cin>>rate[i];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>L[i].name>>L[i].t>>L[i].flag;
    }
    sort(L,L+N);
}
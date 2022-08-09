//17:20 - 17:32 - 22分
//      - 17:42 - 25分
// 有孤立链点，用vector放入所有的Node
#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
#include<vector>
using namespace std;
map<int,int> M;
int beg,N,K,cnt=0;
inline bool check(int num){
    return num>=0&&num<=K;
}
struct Node{
    int id,address,data,next;
    bool operator<(const Node other)const{
        if(data<0&&other.data>=0)return true;
        else if(data<0&&other.data<0)return id<other.id;
        else if(data>=0&&other.data<0)return false;
        else {
            if(check(data)&&!check(other.data))return true;
            else if(!check(data)&&check(other.data))return false;
            else return id<other.id;
        }
    }
}Nl[100005];
vector<Node> V;
int main(){
    cin>>beg>>N>>K;
    for(int i=0;i<N;i++){
        cin>>Nl[i].address>>Nl[i].data>>Nl[i].next;
        M[Nl[i].address]=i;
    }
    while(beg!=-1){
        Nl[M[beg]].id=cnt++;
        V.push_back(Nl[M[beg]]);
        beg=Nl[M[beg]].next;
    }
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();i++){
        if(i<V.size()-1)printf("%05d %d %05d\n",V[i].address,V[i].data,V[i+1].address);
        else printf("%05d %d -1",V[i].address,V[i].data);
    }
}
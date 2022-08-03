//12:37 - 13:18 - 25分
// deque的应用
#include<algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<cmath>
using namespace std;
deque<int> dq;
struct Node{
    string name;
    int h;
    bool operator<(const Node& other) const{
        if(h!=other.h) return h<other.h;
        else return name>other.name;
    }
}Ns[10005];
vector<int> V[10005];
int N,K,l;
int main(){
    cin>>N>>K;
    l=floor(1.0*N/K);
    for(int i=0;i<N;i++)cin>>Ns[i].name>>Ns[i].h;
    sort(Ns,Ns+N);
    for(int i=0;i<N;i++){
        if(i/l<K)V[i/l].push_back(i);
        else V[K-1].push_back(i);
    }
    for(int i=K-1;i>=0;i--){
        int f=1,s=V[i].size();
        for(int j=s-1;j>=0;j--){
            if(f==1)dq.push_back(V[i][j]);
            else dq.push_front(V[i][j]);
            f*=-1;
        }
        for(int j=0;j<s;j++){
            cout<<Ns[dq.front()].name;
            dq.pop_front();
            if(j<s-1)cout<<' ';
            else cout<<endl;
        }
    }
}   
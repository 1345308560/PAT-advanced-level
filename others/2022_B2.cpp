#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
#include<map>
using namespace std;
int N,M,num,Pq_size=0;
int cnt[20005]={};
struct Node{
    int data,t;
    bool operator<(const Node& other){
        return t<other.t;
    }
};
class cmp{
    public:
    bool operator()(const Node& A,const Node& B){
        return A.t>B.t;
    }
};
vector<int> ans;
priority_queue<Node,vector<Node>,cmp> Pq;
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>num;
        Pq.push(Node{num,i});
        if(cnt[num]==0)Pq_size++;
        cnt[num]++;
        while(Pq_size>N){
            int temp=Pq.top().data;
            Pq.pop();
            cnt[temp]--;
            if(cnt[temp]==0){
                Pq_size--;
                ans.push_back(temp);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i<ans.size()-1)cout<<' ';
    }
}
//13:31 - 14:40 - 18分
// 超时
//      - 15:41 - 25分
// set容器
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int N,K,num;
map<int,int> M;
struct Node{
    int index,num;
    bool operator<(const Node &other)const{
        if(num!=other.num)return num>other.num;
        else return index<other.index;
    }
};
set<Node> S;
int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>num;
        if(i>0){
            cout<<num<<":";
            int s=min(K,(int)S.size()),cnt=0;
            for(auto j:S){
                if(cnt>=s)break;
                cout<<' '<<j.index;
                cnt++;
            }
            cout<<endl;
        }
        if(M.count(num)==0)M[num]=1;
        else M[num]++;
        auto it=S.find(Node{num,M[num]-1});
        if(it!=S.end())S.erase(it);
        S.insert(Node{num,M[num]});
    }
}
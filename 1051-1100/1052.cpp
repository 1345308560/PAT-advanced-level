// 11:01 - 24分
// 膜拜柳神 11:07 - 25分
// 边界调节 当为0时处理失败
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct Node{
    string address,next;
    int key;
    bool operator<(const Node b)const{
        return key<b.key;
    }
}Nl[100005];
int N;
string head;
map<string,int> M;
vector<Node> V;
int main(){
    cin>>N>>head;
    for(int i=0;i<N;i++){
        cin>>Nl[i].address>>Nl[i].key>>Nl[i].next;
        M[Nl[i].address]=i;
    }
    while(head!="-1"){
        V.push_back(Nl[M[head]]);
        head=Nl[M[head]].next;
    }
    cout<<V.size()<<' ';
    sort(V.begin(),V.end());
    cout<<V[0].address<<endl;
    for(int i=0;i<V.size();i++){
        if(i<V.size()-1)cout<<V[i].address<<' '<<V[i].key<<' '<<V[i+1].address<<endl;
        else cout<<V[i].address<<' '<<V[i].key<<" -1";
    }
}
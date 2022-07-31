//11:30 - 11:48 - 16分
//      - 11:51 - 25分
// 漏了一个等号 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,L,H;
struct Node{
    string id;
    int V,T,type;
    bool operator<(const Node B)const{
        if(type!=B.type)return type>B.type;
        else if(V+T!=B.V+B.T)return V+T>B.V+B.T;
        else if(V!=B.V)return V>B.V;
        else return id<B.id;
    }
}Np[100005];
vector<Node> V;
int main(){
    cin>>N>>L>>H;
    for(int i=0;i<N;i++){
        cin>>Np[i].id>>Np[i].V>>Np[i].T;
        if(Np[i].V<L||Np[i].T<L)continue;
        else if(Np[i].V>=H&&Np[i].T>=H)Np[i].type=4;
        else if(Np[i].T<H&&Np[i].V>=H)Np[i].type=3;
        else if(Np[i].V>=Np[i].T)Np[i].type=2;
        else Np[i].type=1;
        V.push_back(Np[i]);
    }
    sort(V.begin(), V.end());
    cout<<V.size();
    for(int i=0;i<V.size();i++){
        cout<<endl<<V[i].id<<' '<<V[i].V<<' '<<V[i].T;
    }
}
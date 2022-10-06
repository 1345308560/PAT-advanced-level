#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int N,num1,num2,cnt2=0;;
struct Node{
    int key,p;
    int level,cnt;
    bool operator<(const Node& other){
        if(level!=other.level)return level<other.level;
        else return cnt<other.cnt;
    }
}Nt[35];
vector<int> V;
void f(vector<int> & v,int l){
    if(v.size()==0)return ;
    int k=0x7fffffff,pos=0;
    for(int i=0;i<v.size();i++)
        if(Nt[v[i]].p<k){
            k=Nt[v[i]].p;
            pos=v[i];
        }
    Nt[pos].level=l;
    Nt[pos].cnt=cnt2++;
    vector<int> temp1,temp2;
    for(int i=0;i<v.size();i++)
        if(v[i]==pos)continue;
        else if(Nt[v[i]].key<Nt[pos].key)temp1.push_back(v[i]);
        else temp2.push_back(v[i]);
    // cout<<k<<' '<<temp1.size()<<' '<<temp2.size()<<endl;
    f(temp1,l+1);
    f(temp2,l+1);
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Nt[i].key>>Nt[i].p;
        V.push_back(i);
    }
    f(V,0);
    sort(Nt,Nt+N);
    for(int i=0;i<N;i++){
        cout<<Nt[i].key;
        if(i<N-1)cout<<' ';
        else cout<<endl;
    }
    for(int i=0;i<N;i++){
        cout<<Nt[i].p;
        if(i<N-1)cout<<' ';
        else cout<<endl;
    }
}
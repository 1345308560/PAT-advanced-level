// 17:28 17:56 15分
//       17:59 23分     
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;

int N,M;
class Node{
public:
    int name;
    int grad;
    Node(int na,int ga){
        name=na;
        grad=ga;
    }
    bool operator<(const Node b)const{
        return grad>b.grad;
    }
};
class Node2{
public:
    int a,c,m,e;
};

vector<Node> VA,VC,VM,VE;
unordered_map<int,Node2> Mp;

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int name;int c,m,e,a;
        cin>>name>>c>>m>>e;
        a=round(1.0*(c+m+e)/3);
        VC.push_back(Node(name,c));
        VM.push_back(Node(name,m));
        VE.push_back(Node(name,e));
        VA.push_back(Node(name,a));
        Node2 temp;
        temp.a=temp.c=temp.m=temp.e=-1;
        Mp[name]=temp;
    }
    sort(VA.begin(),VA.end());
    sort(VC.begin(),VC.end());
    sort(VM.begin(),VM.end());
    sort(VE.begin(),VE.end());
    for(int i=0;i<N;i++){
        Mp[VA[i].name].a=i+1;
        Mp[VC[i].name].c=i+1;
        Mp[VM[i].name].m=i+1;
        Mp[VE[i].name].e=i+1;
    }
    for(int i=0;i<M;i++){
        int name;
        cin>>name;
        if(Mp.count(name)==0)cout<<"N/A";
        else{
            if(Mp[name].a<=Mp[name].c&&Mp[name].a<=Mp[name].m&&Mp[name].a<=Mp[name].e)
                cout<<Mp[name].a<<" A";
            else if(Mp[name].c<=Mp[name].a&&Mp[name].c<=Mp[name].m&&Mp[name].c<=Mp[name].e)
                cout<<Mp[name].c<<" C";
            else if(Mp[name].m<=Mp[name].a&&Mp[name].m<=Mp[name].c&&Mp[name].m<=Mp[name].e)
                cout<<Mp[name].m<<" M";
            else cout<<Mp[name].e<<" E";
        }

        if(i<M-1)cout<<endl;
    }
}
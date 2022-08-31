#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
struct Node{
    string name;
    int gp=-1,gm=-1,gf=-1,g=-1;
    bool operator<(Node &other){
        if(g!=other.g)return g>other.g;
        else return name<other.name;
    }
}Ns[30005];
string str;
int P,N,M,num,cnt=0;
map<string,int> Mp;
int main(){
    cin>>P>>N>>M;
    for(int i=0;i<P;i++){
        cin>>str;
        if(Mp.count(str)==0)
            Mp[str]=cnt++;
        Ns[Mp[str]].name=str;
        cin>>Ns[Mp[str]].gp;
    }
    for(int i=0;i<N;i++){
        cin>>str;
        if(Mp.count(str)==0)
            Mp[str]=cnt++;
        Ns[Mp[str]].name=str;
        cin>>Ns[Mp[str]].gm;
    }
    for(int i=0;i<M;i++){
        cin>>str;
        if(Mp.count(str)==0)
            Mp[str]=cnt++;
        Ns[Mp[str]].name=str;
        cin>>Ns[Mp[str]].gf;
    }
    for(int i=0;i<cnt;i++){
        if(Ns[i].gp>=200){
            if(Ns[i].gf>=Ns[i].gm)Ns[i].g=Ns[i].gf;
            else Ns[i].g=round(Ns[i].gf*0.6+Ns[i].gm*0.4);
        }
    }
    sort(Ns,Ns+cnt);
    for(int i=0;i<cnt;i++){
        if(Ns[i].g<60)break;
        else 
            cout<<Ns[i].name<<' '<<Ns[i].gp<<' '<<Ns[i].gm<<' '<<Ns[i].gf<<' '<<Ns[i].g<<endl;
    }
}
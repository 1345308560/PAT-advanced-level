#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<string,int> Mp;
struct Node{
    string name;
    int S,SB=0,SA=0,ST=0,cnt=0,rk=0;
    bool operator<(Node other){
        if(S!=other.S)return S>other.S;
        else if(cnt!=other.cnt)return cnt<other.cnt;
        else return name<other.name;
    }
}Ni[100005];
string id,name;
int N,score,cnt=0,cnt2=1;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>id>>score>>name;
        for(int i=0;i<name.length();i++)
            if(name[i]>='A'&&name[i]<='Z')
                name[i]=name[i]-'A'+'a';
        if(Mp.count(name)==0)
            Mp[name]=cnt++;
        Ni[Mp[name]].name=name;
        if(id[0]=='A')Ni[Mp[name]].SA+=score;
        else if(id[0]=='B')Ni[Mp[name]].SB+=score;
        else Ni[Mp[name]].ST+=score;
        Ni[Mp[name]].cnt++;
    }
    for(int i=0;i<cnt;i++)
        Ni[i].S=Ni[i].SB/1.5+Ni[i].SA+Ni[i].ST*1.5;
    sort(Ni,Ni+cnt);
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        if(i==0){
            Ni[i].rk=i+1;
            cout<<i+1<<' '<<Ni[i].name<<' '<<Ni[i].S<<' '<<Ni[i].cnt<<endl;
        }
        else{
            if(Ni[i].S!=Ni[i-1].S)Ni[i].rk=i+1;
            else Ni[i].rk=Ni[i-1].rk;
            cout<<Ni[i].rk<<' '<<Ni[i].name<<' '<<Ni[i].S<<' '<<Ni[i].cnt<<endl;
        }
    }
}
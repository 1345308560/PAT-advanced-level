#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

struct Node{
    string id;
    int score;
    bool operator<(const Node& other){
        if(score!=other.score)return score>other.score;
        else return id<other.id;
    }
}Nr[10005];
bool cmp(int a,int b){
    if(Nr[a].score!=Nr[b].score)return Nr[a].score>Nr[b].score;
    else return Nr[a].id<Nr[b].id;
}
map<string,int> Mp1;
map<int,vector<int> >Mp2;
map<int,int> Mp3;
vector<int> V[3]; // B,A,T
vector<int> Site[1005];
int N,M;
bool cmp2(int a,int b){
    if(Mp3[a]!=Mp3[b])return Mp3[a]>Mp3[b];
    else return a<b;
}
void check1(string str){
    int num=0;
    if(str[0]=='B')num=0;
    else if(str[0]=='A')num=1;
    else num=2;
    if(V[num].size()==0){
        cout<<"NA\n";
        return;
    }
    for(int i=0;i<V[num].size();i++){
        cout<<Nr[V[num][i]].id<<' '<<Nr[V[num][i]].score<<endl;
    }
}
void check2(string str){
    int s=stoi(str),sum=0;
    if(Site[s].size()==0){
        cout<<"NA\n";
        return;
    }
    for(int i=0;i<Site[s].size();i++){
        sum+=Nr[Site[s][i]].score;
    }
    cout<<Site[s].size()<<' '<<sum<<endl;
}
void check3(string str){
    int ti=stoi(str);
    if(Mp2.count(ti)==0){
        cout<<"NA\n";
        return;
    }
    vector<int> ans;
    Mp3.clear();
    for(int i=0;i<Mp2[ti].size();i++){
        int ss=stoi(Nr[Mp2[ti][i]].id.substr(1,3));
        if(Mp3.count(ss)==0)ans.push_back(ss);
        Mp3[ss]++;
    }
    sort(ans.begin(),ans.end(),cmp2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' '<<Mp3[ans[i]]<<endl;
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>Nr[i].id>>Nr[i].score;
        Mp1[Nr[i].id]=i;
    }
    sort(Nr,Nr+N);
    for(int i=0;i<N;i++){
        // 分类
        if(Nr[i].id[0]=='T')V[2].push_back(i);
        else if(Nr[i].id[0]=='A')V[1].push_back(i);
        else V[0].push_back(i);
        // site
        int s=stoi(Nr[i].id.substr(1,3));
        Site[s].push_back(i);
        // time;
        int ti=stoi(Nr[i].id.substr(4,6));
        if(Mp2.count(ti)==0){
            vector<int> temp;
            Mp2[ti]=temp;
        }
        Mp2[ti].push_back(i);
    }
    for(int i=0;i<M;i++){
        int type;
        string str;
        cin>>type>>str;
        cout<<"Case "<<i+1<<": "<<type<<" "<<str<<endl;
        if(type==1)check1(str);
        else if(type==2)check2(str);
        else check3(str);
    }
}
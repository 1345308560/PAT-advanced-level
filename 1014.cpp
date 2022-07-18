#include<iostream>
#include<queue>
#include<algorithm>
#define INF 0x7fffffff
// 14:48 15:49 19分
// 16:29       26分
using namespace std;

struct Node{
    int qid;
    int time;
    queue<int>Qtime;// time
    bool operator<(Node B)const{
        if(Qtime.front()!=B.Qtime.front()){
            return Qtime.front()>B.Qtime.front();
        }
        else return qid>B.qid;
    }
}QN[22];

int N,M,K,Q;
int ct[1005]={};
string out_time[1005];

priority_queue<Node> PQN;

string f(int num){
    int h=8,m=0;
    h+=num/60;
    m+=num%60;

    string ans;
    if(h<10){
        ans+="0";
        ans+=to_string(h);
    }
    else ans+=to_string(h);
    ans+=":";
    if(m<10){
        ans+="0";
        ans+=to_string(m);
    }
    else ans+=to_string(m);
    return ans;
}

int main(){
    cin>>N>>M>>K>>Q;
    for(int i=0;i<N;i++){
        QN[i].time=0;
        QN[i].qid=i;
    }
    for(int i=0;i<K;i++){
        cin>>ct[i];
        if(i==M*N){
            for(int j=0;j<N;j++)PQN.push(QN[j]);
        }
        if(i<M*N){
            QN[i%N].Qtime.push(ct[i]);
            if(QN[i%N].time>=540){
                out_time[i]="Sorry";
            }
            else out_time[i]=f(ct[i]+QN[i%N].time);
            QN[i%N].time+=ct[i];
        }
        else{
            Node temp=PQN.top();
            PQN.pop();
            if(temp.time>=540){
                out_time[i]="Sorry";
            }
            else{
                out_time[i]=f(temp.time+ct[i]);
            }
            temp.time+=ct[i];
            temp.Qtime.pop();
            temp.Qtime.push(ct[i]);
            PQN.push(temp);
        }
    }

    for(int i=0;i<Q;i++){
        int num;
        cin>>num;
        num--;
        cout<<out_time[num];
        if(i<Q-1)cout<<endl;
    }
}
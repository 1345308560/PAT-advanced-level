// 16:01 - 16:44 - 25分
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Np,Ng,num;
int ans[1005],ans2[1005];
int Wei[1005],Ord[1005],Rnk[1005]={};
bool cmp(int i,int j){
    return Rnk[i]>Rnk[j];
}
vector<int> now_turn,next_turn;
int main(){
    cin>>Np>>Ng;
    for(int i=0;i<Np;i++)cin>>Wei[i];
    for(int i=0;i<Np;i++){cin>>Ord[i];now_turn.push_back(Ord[i]);}
    for(int i=0;i<Np;i++)ans[i]=i;
    for(int i=0;now_turn.size()>0;i++){
        if(now_turn.size()==1){
            Rnk[now_turn[0]]++;
            now_turn.clear();
        }
        else{
            int MAX=-1,id=-1;
            next_turn.clear();
            for(int j=0;j<now_turn.size();j++){
                Rnk[now_turn[j]]++;
                if(j%Ng==0){MAX=-1;id=-1;}
                if(Wei[now_turn[j]]>MAX){MAX=Wei[now_turn[j]];id=now_turn[j];}
                if(j==now_turn.size()-1||j%Ng==Ng-1)next_turn.push_back(id);
            }
            now_turn=next_turn;
        }
    }
    sort(ans,ans+Np,cmp);
    // for(int i=0;i<Np;i++)cout<<Rnk[i]<<' ';
    // cout<<endl;
    for(int i=0;i<Np;i++){
        if(i==0)ans2[ans[i]]=1;
        else if(Rnk[ans[i]]==Rnk[ans[i-1]])ans2[ans[i]]=ans2[ans[i-1]];
        else ans2[ans[i]]=i+1;
    }
    for(int i=0;i<Np;i++){
        cout<<ans2[i];
        if(i<Np-1)cout<<' ';
    }
}
//15：42 - 15:53 - 23分
//       - 16:24 - 25分
#include<iostream>
#include<vector>
using namespace std;
int N,M,MIN=0x7fffffff;
int num[100005];
vector<pair<int,int> > V,V2;
int main(){
    cin>>N>>M;
    fill(num,num+N+1,0);
    for(int i=1;i<=N;i++){
        cin>>num[i];
        num[i]+=num[i-1];
    }
    for(int i=0;i<N;i++){
        int f_num=num[i]+M;
        int pos=lower_bound(num+i+1,num+N+1,f_num)-num;
        if(num[pos]-num[i]==M)V.push_back(make_pair(i+1,pos));
        else if(num[pos]-num[i]>M){
            if(num[pos]-num[i]<MIN){
                MIN=num[pos]-num[i];
                V2.clear();
            }
            if(num[pos]-num[i]==MIN)
                V2.push_back(make_pair(i+1,pos));
        }
    }
    if(V.size()!=0)
        for(int i=0;i<V.size();i++){
            cout<<V[i].first<<"-"<<V[i].second;
            if(i<V.size()-1)cout<<endl;
        }
    else{
        for(int i=0;i<V2.size();i++){
            cout<<V2[i].first<<"-"<<V2[i].second;
            if(i<V2.size()-1)cout<<endl;
        }
    }
}
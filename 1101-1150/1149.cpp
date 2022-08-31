#include<iostream>
#include<map>
#include<vector>
using namespace std;
int N,M,num1,num2,cnt=0;
int num[10005];
map<int,int> Mp1,Mp2;
vector<int> V[20005];
bool check(int n){
    map<int,int> Mp3;
    for(int i=0;i<n;i++){
        if(Mp1.count(num[i])>0){
            num[i]=Mp1[num[i]];
            Mp3[num[i]]=1;
        }
        else num[i]=-1;
    }
    for(int i=0;i<n;i++)
        if(num[i]!=-1)
        for(int j=0;j<V[num[i]].size();j++)
            if(Mp3.count(V[num[i]][j])>0)
                return false;
            
    return true;
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>num1>>num2;
        if(Mp1.count(num1)==0){
            Mp1[num1]=cnt;
            Mp2[cnt]=num1;
            cnt++;
        }
        if(Mp1.count(num2)==0){
            Mp1[num2]=cnt;
            Mp2[cnt]=num2;
            cnt++;
        }
        num1=Mp1[num1];
        num2=Mp1[num2];
        V[num1].push_back(num2);
        V[num2].push_back(num1);
        // cout<<Mp2[num1]<<' '<<Mp2[num2]<<endl;
    }
    for(int i=0;i<M;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++)cin>>num[j];
        if(check(n))cout<<"Yes\n";
        else cout<<"No\n";
    }
}
// 10:37 - 10:47 - 25分
#include<iostream>
#include<stack>
using namespace std;
int M,N,K;
int num[1005];
bool check(){
    stack<int> St;
    int cnt=0;
    for(int i=1;i<=N;i++){
        St.push(i);
        if(St.size()>M)return false;
        while(!St.empty()&&St.top()==num[cnt]){
            St.pop();
            cnt++;
        }
    }
    return St.size()==0;
}
int main(){
    cin>>M>>N>>K;
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++)cin>>num[j];
        if(check())cout<<"YES";
        else cout<<"NO";
        if(i<K-1)cout<<endl;
    }
}
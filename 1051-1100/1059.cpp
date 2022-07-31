// 21:43 - 23分
// 21:50 边界条件1没有处理好 - 25分
#include<iostream>
#include<map>
using namespace std;
long num;
map<int,int> M;
int main(){
    cin>>num;
    if(num==1){cout<<"1=1";return 0;}
    cout<<num;
    while(num>1){
        for(int i=2;i<=num;i++){
            if(num%i==0){
                num/=i;
                M[i]++;
                break;
            }
        }
    }
    bool f=true;
    for(auto i:M){
        if(f){f=false;cout<<'=';}
        else cout<<'*';
        if(i.second==1)cout<<i.first;
        else if(i.second>1)cout<<i.first<<'^'<<i.second;
    }
}
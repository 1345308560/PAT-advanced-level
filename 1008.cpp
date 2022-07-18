#include<iostream>
using namespace std;
int N,num,pos=0,ans=0;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        ans+=5;
        if(num>pos)ans+=(num-pos)*6;
        else ans+=(pos-num)*4;
        pos=num;
    }
    cout<<ans;
}
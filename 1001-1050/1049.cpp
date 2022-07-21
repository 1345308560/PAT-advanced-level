// 21:20 - 21:22 - 22分(纯暴力)
#include<iostream>
using namespace std;
int N;
int cnt=0;
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        int num=i;
        while(num){
            if(num%10==1)cnt++;
            num/=10;
        }
    }
    cout<<cnt;
}
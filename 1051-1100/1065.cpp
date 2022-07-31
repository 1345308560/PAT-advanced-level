//22:40 - 22:42 - 12分
#include<iostream>
using namespace std;
int N;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        long long num1,num2,num3,sum;
        cin>>num1>>num2>>num3;
        sum=num1+num2;
        cout<<"Case #"<<i+1<<": ";
        if(num1>0&&num2>0&&sum<=0)cout<<"true\n";
        else if(num1<0&&num2<0&&sum>=0)cout<<"false\n";
        else if(sum>num3)cout<<"true\n";
        else cout<<"false\n";
    }
}
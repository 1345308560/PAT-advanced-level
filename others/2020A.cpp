#include<iostream>
using namespace std;
long N,a=0,b=1,temp;
int main(){
    cin>>N;
    while(b<N){
        temp=a+b;
        a=b;
        b=temp;
    }
    if(N-a<=b-N)cout<<a;
    else cout<<b;
}
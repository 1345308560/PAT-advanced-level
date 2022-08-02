//17:47 - 18:06 - 8分
//      - 18:25 - 20分
// 错误：长整型占位符%lld
#include<iostream>
#include<cstdio>
using namespace std;
long long N,u=0,d=1,a,b,g;
long long gcd(long long a, long long b) {return b == 0 ? abs(a) : gcd(b, a % b);}
int main(){ 
    cin>>N;
    for(int i=0;i<N;i++){
        scanf("%lld/%lld",&a,&b);
        u=u*b+a*d;
        d*=b;
        g=gcd(max(abs(u),abs(d)),min(abs(u),abs(d)));
        u/=g;
        d/=g;
    }
    if(u==0){
        cout<<0;
    }
    else if(u%d==0){
        cout<<u/d;
    }
    else if(u>d){
        cout<<u/d<<" ";
        if(u<0)u=-u;
        u=u-(u/d)*d;
        cout<<u<<"/"<<d;
    }
    else cout<<u<<"/"<<d;
}
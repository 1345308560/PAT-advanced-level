//15:48 - 16:06 - 20分
// 模拟分数运算
#include<iostream>
#include<cmath>
#include<cstdio>
#define ll long long
using namespace std;
ll a1,b1,a2,b2;
inline ll gcd(ll a,ll b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
void f(ll a,ll b){
    if(b==0){cout<<"Inf";return;}
    if(b<0){a*=-1;b*=-1;}

    ll g=gcd(fabs(a),fabs(b));
    a/=g;
    b/=g;
    if(a<0)cout<<"(";
    if(a==0)cout<<0;
    else if(b==1)cout<<a;
    else if(fabs(a)>fabs(b)){
        cout<<a/b<<" "<<fabs(a)-fabs((a/b)*b)<<"/"<<b;
    }
    else cout<<a<<"/"<<b;
    if(a<0)cout<<")";
}
int main(){
    scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
    f(a1,b1);cout<<" + ";f(a2,b2);cout<<" = ";f(a1*b2+a2*b1,b1*b2);
    cout<<endl;
    f(a1,b1);cout<<" - ";f(a2,b2);cout<<" = ";f(a1*b2-a2*b1,b1*b2);
    cout<<endl;
    f(a1,b1);cout<<" * ";f(a2,b2);cout<<" = ";f(a1*a2,b1*b2);
    cout<<endl;
    f(a1,b1);cout<<" / ";f(a2,b2);cout<<" = ";f(a1*b2,b1*a2);
}
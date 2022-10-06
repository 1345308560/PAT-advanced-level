#include<iostream>
#include<cmath>
using namespace std;
int N;
bool isPrime(int n){
    if(n==1||n==0)return false;
    for(int i=2;i<sqrt(n)+0.5;i++)
        if(n%i==0)return false;
    return true;
}
bool check1(int n){
    if(!isPrime(n))return false;
    int n1=n-6;
    if(n1>=2){
        if(isPrime(n1)){
            cout<<"Yes\n"<<n1;
            return true;
        }
    }
    int n2=n+6;
    if(!isPrime(n2))return false;
    cout<<"Yes\n"<<n2;
    return true;
}
bool check2(int n){
    if(!isPrime(n))return false;
    int n2=n-6;
    if(n2>=0&&isPrime(n2)){
        cout<<"No\n"<<n;
        return true;
    }
    int n1=n+6;
    if(!isPrime(n1))return false;
    cout<<"No\n"<<n;
    return true;
}
int main(){
    cin>>N;
    if(check1(N));
    else{
        for(int i=N+1;;i++)
            if(check2(i))break;
    }

}
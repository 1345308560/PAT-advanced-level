#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool isPrime(int n){
    if(n==1||n==0)return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)return false;
    return true;
}
int main(){
    int l, k;
    string s;
    cin >> l >> k >> s;
    for(int i=0;i<=l-k;i++){
        string t=s.substr(i,k);
        int num=stoi(t);
        if(isPrime(num)){
            cout<<num;
            return 0;
        }
    }
    cout<<"404\n";
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
string str;
long N,z,a,b;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>str;
        z=stoi(str);
        a=stoi(str.substr(0,str.length()/2));
        b=stoi(str.substr(str.length()/2));
        if(a!=0&&z%a==0){
            z/=a;
            if(b!=0&&z%b==0)cout<<"Yes\n";
            else cout<<"No\n";
        }
        else cout<<"No\n";
    }
    
}
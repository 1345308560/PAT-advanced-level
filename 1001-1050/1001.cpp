#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long a,b;
    cin>>a>>b;
    long long ans=a+b;
    string strAns=to_string(ans);
    reverse(strAns.begin(),strAns.end());
    string newAns="";
    for(int i=0;i<strAns.size();i++){
        if(i==0);
        else if(strAns[i]=='-');
        else if(i%3==0)newAns+=",";

        newAns+=strAns[i];
    }
    reverse(newAns.begin(),newAns.end());
    cout<<newAns<<endl;

}
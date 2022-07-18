#include<iostream>
using namespace std;
int cnt1[10]={},cnt2[10]={};
int num1[25]={},num2[25]={};
int main(){
    string n1,n2;
    cin>>n1;
    for(int i=0;i<n1.length();i++){
        num1[i]=n1[n1.length()-i-1]-'0';
        cnt1[num1[i]]++;
        num2[i]+=num1[i]*2;
        if(num2[i]>=10){
            num2[i+1]++;
            num2[i]%=10;
        }
        cnt2[num2[i]]++;
    }
    int l2=n1.length();
    if(num2[l2]!=0){
        l2++;
        cout<<"No\n";
    }
    else{
        bool flag=true;
        for(int i=0;i<10;i++)
            if(cnt1[i]!=cnt2[i])flag=false;
        if(flag==true)cout<<"Yes\n";
        else cout<<"No\n";
    }
    for(int i=l2-1;i>=0;i--)cout<<num2[i];
}
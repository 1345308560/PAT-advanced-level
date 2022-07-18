#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string str1,str2;
int tag,radix;

long long f(string s,int n){
    string temp=s;
    long long ans=0;
    long long base=1;
    reverse(temp.begin(),temp.end());
    for(int i=0;i<temp.length();i++){
        int num;
        if(temp[i]>='0'&&temp[i]<='9')num=temp[i]-'0';
        else num=(temp[i]-'a')+10;
        if(num>=n)return -1;
        ans+=base*num;
        base*=n;
    }
    return ans;
}

int main(){
    cin>>str1>>str2>>tag>>radix;
    if(tag==1){
        long long ans1=f(str1,radix);
        int radix2=2;
        for(;radix2<37;radix2++){
            long long ans2=f(str2,radix2);
            if(ans1==ans2)break;
        }
        if(radix2==37)cout<<"Impossible";
        else cout<<radix2;
    }
    else{
        long long ans1=f(str2,radix);
        int radix2=2;
        for(;radix2<37;radix2++){
            long long ans2=f(str1,radix2);
            if(ans1==ans2)break;
        }
        if(radix2==37)cout<<"Impossible";
        else cout<<radix2;
    }
}
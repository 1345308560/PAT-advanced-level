#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string str1,str2;
int main(){
    cin>>str1;
    bool f=true;
    for(int i=1;i<4;i++)if(str1[i]!=str1[i-1])f=false;
    if(f){
        cout<<str1<<" - "<<str1<<" = "<<"0000";
        return 0;
    }
    while(1){
        sort(str1.begin(),str1.end());
        str2=str1;
        reverse(str2.begin(),str2.end());
        int M=stoi(str2),m=stoi(str1);
        printf("%04d - %04d = %04d",M,m,M-m);
        if(M-m==6174)break;
        else printf("\n");
        str1=to_string(M-m);
        while(str1.length()<4)str1+="0";
    }
}
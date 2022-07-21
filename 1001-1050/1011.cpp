#include<iostream>
#include<cstdio>
using namespace std;

// 23:06 - 23:13

double num[3][3];
double ans=1;

int main(){
    for(int i=0;i<3;i++){
        double a=-1;
        for(int j=0;j<3;j++){
            cin>>num[i][j];
            a=max(a,num[i][j]);
        }
        if(num[i][0]>=num[i][1]&&num[i][0]>=num[i][2])cout<<"W ";
        else if(num[i][1]>=num[i][0]&&num[i][1]>=num[i][2])cout<<"T ";
        else cout<<"L ";
        ans*=a;
    }
    printf("%.2f",(ans*0.65-1)*2);
}
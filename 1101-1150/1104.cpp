// 21:58 - 22:06 - 15分
//       - 22:12 - 20分
// double 精度不够
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long N,sum=0;
double num;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        sum+=(long long)(num*1000)*(i+1)*(N-i);
    }
    printf("%.2f",sum/1000.0);
}
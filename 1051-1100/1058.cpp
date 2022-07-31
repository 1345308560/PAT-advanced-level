//21:29 - 21:33 - 20分
#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int a1,a2,a3,b1,b2,b3;
int main(){
    scanf("%d.%d.%d",&a1,&a2,&a3);
    scanf("%d.%d.%d",&b1,&b2,&b3);
    a1+=b1;
    a2+=b2;
    a3+=b3;
    if(a3>=29){a2+=(a3/29);a3%=29;}
    if(a2>=17){a1+=(a2/17);a2%=17;}
    printf("%d.%d.%d",a1,a2,a3);
}
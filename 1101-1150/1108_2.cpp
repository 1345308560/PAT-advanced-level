#include<iostream>
#include<string.h>
using namespace std;
int N,cnt=0;
double temp,ans=0;
char str1[50],str2[50];
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        scanf("%s",str1);
        sscanf(str1,"%lf",&temp);
        sprintf(str2,"%.2f",temp);
        int flag=1;
        for(int i=0;i<strlen(str1);i++){
            if(i>=strlen(str2))flag=0;
            else if(str1[i]!=str2[i])flag=0;
        }
        if(!flag||temp>1000||temp<-1000){
            cout<<"ERROR: "<<str1<<" is not a legal number\n";
        }
        else {
            ans+=temp;
            cnt++;
        }
    }
    if(cnt>1)printf("The average of %d numbers is %.2f",cnt,ans/cnt);
    else if(cnt==1)printf("The average of %d number is %.2f",cnt,ans/cnt);
    else printf("The average of 0 numbers is Undefined");
}
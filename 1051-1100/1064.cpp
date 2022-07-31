//16:32 - 17:03 - 30分
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int N,num[1005],ans[1005];
void f(int root,int beg,int len){
    if(len==0)return;
    else if(len==1)ans[root]=num[beg];
    else if(len==2){
        ans[root]=num[beg+1];
        ans[root*2+1]=num[beg];
    }
    else {
        int l=0;
        while(pow(2,l)<=len)l++;
        int l_num=pow(2,l-2)-1,r_num=pow(2,l-2)-1;
        if(len-1-l_num-r_num<=pow(2,l-2))l_num+=len-1-l_num-r_num;
        else{
            l_num+=pow(2,l-2);
            r_num=(len-1-l_num);
        }
        ans[root]=num[beg+l_num];
        f(root*2+1,beg,l_num);
        f(root*2+2,beg+l_num+1,r_num);
    }
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>num[i];
    sort(num,num+N);
    f(0,0,N);
    for(int i=0;i<N;i++){
        cout<<ans[i];
        if(i<N-1)cout<<' ';
    }
}
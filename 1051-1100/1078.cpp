// 17:05 - 17:13 - 17分
//       - 17:25 - 22分
//       - 17:28 - 25分
// 没有考虑是1的情况
#include<iostream>
#define MAXN 10555
using namespace std;
int Msize,N;
int isPrime[MAXN];
int ans[MAXN]={};
int main(){
    cin>>Msize>>N;
    fill(isPrime,isPrime+MAXN,true);
    for(int i=2;i<MAXN;i++)
        for(int j=i*i;j<MAXN;j+=i)
            isPrime[j]=false;
    while(!isPrime[Msize]||Msize<=1)Msize++;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        if(ans[num%Msize]!=0){
            bool f=false;
            for(int k=1;k<Msize;k++){
                if(ans[(num+k*k)%Msize]==0){
                    f=true;
                    ans[(num+k*k)%Msize]=1;
                    cout<<(num+k*k)%Msize;
                    break;
                }
            }
            if(!f)cout<<'-';
        }
        else {
            ans[num%Msize]=1;
            cout<<num%Msize;
        }
        if(i<N-1)cout<<' ';
    }
}
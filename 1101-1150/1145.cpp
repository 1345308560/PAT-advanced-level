#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define MAXN 0x7fffffff
using namespace std;

int Msize,N,M,cnt=0,ans=0;
int HashTable[11005],num;
bool isPrime[11005]={true,true};
int main(){
    cin>>Msize>>N>>M;
    for(int i=2;i<11005;i++){
        for(int j=i*i;j<11005;j+=i)
            isPrime[j]=true;
    }
    // for(int i=0;i<100;i++)if(!isPrime[i])cout<<i<<endl;
    while(isPrime[Msize])Msize++;
    fill(HashTable,HashTable+Msize,MAXN);
    for(int i=0;i<N;i++){
        cin>>num;
        bool find_pos=false;
        for(int j=0;j<=Msize;j++){
            if(HashTable[(num+j*j)%Msize]==MAXN){
                HashTable[(num+j*j)%Msize]=num;
                find_pos=true;
                break;
            }
        }
        if(!find_pos)cout<<num<<" cannot be inserted.\n";
    }
    for(int i=0;i<M;i++){
        cin>>num;
        for(int j=0;j<=Msize;j++){
            ans++;
            if(HashTable[(num+j*j)%Msize]==num||HashTable[(num+j*j)%Msize]==MAXN)break;
        }
    }
    printf("%.1f",1.0*ans/M);
}
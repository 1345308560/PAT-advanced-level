#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
int N,num[10005],K;
map<int,int> Rank;
bool check(int n){
    if(n==1)return false;
    for(int i=2;i<sqrt(n)+0.5;i++)
        if(n%i==0)return false;
    return true;
}
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>num[i];
        if(i==1)Rank[num[i]]=0;
        else if(check(i))Rank[num[i]]=1;
        else Rank[num[i]]=2;
    }

    cin>>K;
    for(int i=0;i<K;i++){
        int temp;
        cin>>temp;
        printf("%04d: ",temp);
        if(Rank.count(temp)==0){
            cout<<"Are you kidding?\n";
        }
        else{
            if(Rank[temp]==-1)
                cout<<"Checked\n";
            else if(Rank[temp]==0)
                cout<<"Mystery Award\n";
            else if(Rank[temp]==1)
                cout<<"Minion\n";
            else 
                cout<<"Chocolate\n";
            Rank[temp]=-1;
        }
    }
}
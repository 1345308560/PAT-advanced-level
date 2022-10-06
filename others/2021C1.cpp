#include<iostream>
using namespace std;
long N,K,num,dp=1;
struct Node{
    long beg,len;
}Nl[10005];
void check(long n){
    for(long i=0;i<N;i++){
        if(n<Nl[i].len&&n>=0){
            cout<<Nl[i].beg+4*n<<endl;
            dp=max(dp,i+1);
            return;
        }
        else n-=Nl[i].len;
    }
    cout<<"Illegal Access\n";
}
int main(){
    cin>>N>>K;
    for(long i=0;i<N;i++)
        cin>>Nl[i].beg>>Nl[i].len;
    for(long i=0;i<K;i++){
        cin>>num;
        check(num);
    }
    cout<<dp<<endl;
}
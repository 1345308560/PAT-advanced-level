// 19:29 - 19:38 - 25分
#include<iostream>
using namespace std;
int N,Q,K,num1,num2,maxn=-1,cnt=0;
int f[10005];
int find_father(int num){
    if(num!=f[num])f[num]=find_father(f[num]);
    return f[num];
}
void union_m(int a,int b){
    int ra=find_father(a),rb=find_father(b);
    if(ra!=rb)f[ra]=rb;
}
int main(){
    cin>>N;
    for(int i=0;i<10005;i++)f[i]=i;
    for(int i=0;i<N;i++){
        cin>>K;
        for(int j=0;j<K;j++){
            if(j==0){cin>>num1;maxn=max(maxn,num1);}
            else{
                cin>>num2;
                maxn=max(maxn,num2);
                union_m(num1,num2);
                num1=num2;
            }
        }
    }
    cin>>Q;
    for(int i=1;i<=maxn;i++)if(find_father(i)==i)cnt++;
    cout<<cnt<<' '<<maxn<<endl;
    for(int i=0;i<Q;i++){
        cin>>num1>>num2;
        if(find_father(num1)==find_father(num2))cout<<"Yes\n";
        else cout<<"No\n";
    }
}
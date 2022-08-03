//13:28 - 13:34 - 13分
//      - 13:35 - 14分
//      - 13:46 - 24分
//      - 13:47 - 25分
// 错误一：没有使用lower_bound()
// 错误二：l初值为应为0
#include<iostream>
#include<algorithm>
using namespace std;
int N;
int num[100005];
bool check(int n){
    int pos=lower_bound(num,num+N,n+1)-num;
    if(n>=num[pos])return false;
    if(N-pos>=n)return true;
    else return false;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>num[i];
    sort(num,num+N);
    int l=0,r=N;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
}
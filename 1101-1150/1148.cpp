#include<iostream>
#include<vector>
using namespace std;
int N,ans1=-1,ans2=-1;
int num[105];
bool check(int a,int b){
    // cout<<a<<' '<<b<<" : "<<endl;
    vector<int> v(N+1,0),l;
    v[a]=v[b]=-1;
    
    for(int i=1;i<=N;i++){
        if(v[abs(num[i])]*num[i]<0)l.push_back(i);
        else if(num[i]<0&&abs(num[i])!=a&&abs(num[i])!=b)l.push_back(i);
        else v[abs(num[i])]=(num[i]>0?1:-1);
        // for(int i=1;i<=N;i++)cout<<v[i]<<' ';
        // cout<<endl;
    }
    // cout<<" l size : "<<l.size()<<endl;
    if(l.size()==2&&v[l[0]]*v[l[1]]<0){
        ans1=a;
        ans2=b;
        return true;
    }
    return false;
}
void f(){
    for(int i=1;i<=N;i++)
        for(int j=i+1;j<=N;j++)
            if(check(i,j))
                return;
}
int main(){
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>num[i];
    // check(1,5);
    f();
    if(ans1==-1)cout<<"No Solution\n";
    else cout<<ans1<<' '<<ans2;
}
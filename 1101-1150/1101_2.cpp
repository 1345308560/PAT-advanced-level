#include<iostream>
#include<vector>
using namespace std;
int N,num[100005],M=-1,m=0x7fffffff;
bool is_max[100005];
vector<int> ans;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i];
        if(num[i]>M){M=num[i];is_max[i]=true;}
        else is_max[i]=false;
    }
    for(int i=N-1;i>=0;i--){
        if(num[i]<m){
            m=num[i];
            if(is_max[i])
                ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<num[ans[ans.size()-1-i]];
        if(i<ans.size()-1)cout<<' ';
    }
    cout<<endl;
}
#include<iostream>
#include<vector>
#include<map>
using namespace std;
string str[1005];
vector<string> ans;
map<string,int>Mp;
int M,N,S,cnt;
int main(){
    cin>>M>>N>>S;
    for(int i=1;i<=M;i++)
        cin>>str[i];
    cnt=N-1;
    for(int i=S;i<=M;i++){
        if(cnt==N-1){
            while(i<=M&&Mp.count(str[i])!=0)i++;
            if(i<=M){
                cnt=0;
                Mp[str[i]]=1;
                ans.push_back(str[i]);
            }
        }
        else cnt++;
    }
    if(ans.size()==0)cout<<"Keep going...\n";
    else 
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<endl;
        
}
//10:56 - 11:13 - 18分
//      - 11:18 - 20分
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int K;
string S;
vector<char> V;
map<char,bool> M,in_vec;
int main(){
    cin>>K>>S;
    for(int i=0;i<S.length();i++){
        if(M.count(S[i])==0)M[S[i]]=false;
        if(i==S.length()-1)M[S[i]]=true;
        for(int j=1;j<K;j++){
            if(i+j>=S.length())break;
            if(S[i]!=S[i+j]){
                M[S[i]]=true;
                break;
            }
            if(j==K-1&&M[S[i]]==false)i+=j;
        }
    }
    for(int i=0;i<S.length();i++){
        if(M[S[i]]==false&&in_vec.count(S[i])==0){
            V.push_back(S[i]);
            in_vec[S[i]]=true;
        }
    }
    for(int i=0;i<V.size();i++)cout<<V[i];
    cout<<endl;
    for(int i=0;i<S.length();i++)
        if(M[S[i]]==true)cout<<S[i];
        else {cout<<S[i];i+=K-1;}
}   
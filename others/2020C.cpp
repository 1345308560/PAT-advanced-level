#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

string str;
int N,K,num;
int root[10005],vis[10005]={};
int level[1005];
vector<int> ans;
int cnt(string s){
    int n=0;
    while(s[n]==' ')n++;
    return n;
}

int main(){
    cin>>N;getchar();
    for(int i=0;i<N;i++){
        getline(cin,str);
        vis[stoi(str)]=1;
        int s=cnt(str);
        level[s]=stoi(str);
        if(s-1>=0)root[stoi(str)]=level[s-1];
    }
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>num;
        if(!vis[num]){
            printf("Error: %04d is not found.\n",num);
        }
        else{
            int temp=num;
            ans.clear();
            ans.push_back(temp);
            while(root[temp]!=temp){
                ans.push_back(root[temp]);
                temp=root[temp];
            }
            for(int i=0;i<ans.size();i++){
                printf("%04d",ans[ans.size()-i-1]);
                if(i<ans.size()-1)printf("->");
            }
            printf("\n");
        }
    }
}
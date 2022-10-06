#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N,M,K;
int indices[25],products[15];
bool vis_eq[55]={},vis_ind[105]={};
vector<int> has_eq[105];
vector<vector<int> >V; //反应，最后一个是生成物
vector<int> ans;
string reactants[55];

void Insert(string s){
    vector<int> temp;
    string s_temp;
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'||s[i]=='+'){
            temp.push_back(stoi(s_temp));
            s_temp="";
        }
        else if(s[i]>='0'&&s[i]<='9')
            s_temp+=s[i];
        if(i==s.length()-1&&s_temp.length()>0)
            temp.push_back(stoi(s_temp));
    }
    V.push_back(temp);
}
bool cmp(vector<int> v1, vector<int> v2){
    int s1=v1.size(), s2=v2.size();
    for(int i=0;i<min(s1,s2);i++)
        if(v1[i]!=v2[i]) return v1[i]<v2[i];
    return true;
}
//     第几个生成物
bool check(int eq_id){
    if(vis_eq[eq_id]==false)return false;
    for(int i=0;i<V[eq_id].size()-1;i++)
        if(vis_ind[V[eq_id][i]]==false)
            return false;
    return true;
}
bool DFS(int pos,vector<int> Vt){
    if(pos>=M){
        ans=Vt;
        return true;
    }
    for(int i=0;i<has_eq[products[pos]].size();i++){
        int eq_id=has_eq[products[pos]][i];
        if(check(eq_id)){
            vis_eq[eq_id]=false;
            for(int j=0;j<V[eq_id].size()-1;j++)
                vis_ind[V[eq_id][j]]=false;
            Vt.push_back(eq_id);
            bool flag=DFS(pos+1,Vt);
            if(flag)return flag;
            Vt.pop_back();
            for(int j=0;j<V[eq_id].size()-1;j++)
                vis_ind[V[eq_id][j]]=true;
            vis_eq[eq_id]=true;
        }
    }
    return false;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>indices[i];
        vis_ind[indices[i]]=true;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>products[i];
        string temp=to_string(products[i])+" -> "+to_string(products[i]);
        Insert(temp);
    }
    cin>>K;getchar();
    for(int i=0;i<K;i++){
        getline(cin,reactants[i]);
        Insert(reactants[i]);
    }
    sort(V.begin(),V.end());
    // 检验存储公式
    // for(int i=0;i<V.size();i++){
    //     cout<<i<<": ";
    //     for(int j=0;j<V[i].size();j++){
    //         cout<<V[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<V.size();i++){
        vis_eq[i]=true;
        has_eq[V[i][V[i].size()-1]].push_back(i);
    }
    // 每个元素拥有的公式
    // for(int i=0;i<105;i++){
    //     if(has_eq[i].size()>0)
    //         cout<<i<<' '<<has_eq[i].size()<<endl;
    // }
    vector<int> V_temp;
    DFS(0,V_temp);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<V[ans[i]].size()-1;j++){
            printf("%02d",V[ans[i]][j]);
            if(j<V[ans[i]].size()-2)cout<<" + ";
        }
        cout<<" -> ";
        printf("%02d\n",V[ans[i]][V[ans[i]].size()-1]);
    }
}
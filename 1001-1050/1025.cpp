#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
    string name;
    int grade;
    int f_r,l_n,l_r;
};
bool cmp1(Node A,Node B){
    if(A.grade!=B.grade)return A.grade > B.grade;
    else return A.name < B.name;
}
vector<Node> V[105];
vector<Node> ans;
int N,K;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>K;
        for(int j=0;j<K;j++){
            string name;
            int grade;
            cin>>name>>grade;
            Node temp;
            temp.name = name;
            temp.grade = grade;
            temp.l_n=i+1;
            V[i].push_back(temp);
        }
        sort(V[i].begin(), V[i].end(),cmp1);
        V[i][0].l_r=1;
        for(int j=1;j<K;j++){
            if(V[i][j].grade==V[i][j-1].grade)V[i][j].l_r=V[i][j-1].l_r;
            else V[i][j].l_r=j+1;
        }
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<V[i].size();j++)
            ans.push_back(V[i][j]);
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end(),cmp1);
    ans[0].f_r=1;
    for(int i=1;i<ans.size();i++){
        if(ans[i].grade==ans[i-1].grade)ans[i].f_r=ans[i-1].f_r;
        else ans[i].f_r=i+1;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].name<<" "<<ans[i].f_r<<" "<<ans[i].l_n<<" "<<ans[i].l_r;
        if(i<ans.size()-1)cout<<endl;
    }
}
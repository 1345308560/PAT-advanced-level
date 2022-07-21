#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int N,K;
struct Node{
    string l,r;
    int t;
    Node(string a,string b,int tt){
        l=a;r=b;t=tt;
    }
};
vector<Node> V;
map<string,int> m1;
map<int,string> m2;
int root[1005],m_rank[1005],cnt=0;

int find_root(int  num){
    if(num!=root[num])root[num]=find_root(root[num]);
    return root[num];
}

void m_union(int a,int b,int w){
    int ra=find_root(a),rb=find_root(b);
    m_rank[a]+=w;
    m_rank[b]+=w;
    if(ra!=rb)root[ra]=rb;
}

struct Node2{
    int size;
    int tot_rank;
    int max_rank;
    string name;
};

map<int,Node2> m3;


struct Node3{
    string name;
    int size;
    bool operator<(const Node3& other) const{
        return name<other.name;
    }
};

vector<Node3> V3;

int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        string a,b,MIN,MAX;
        int t;
        cin>>a>>b>>t;
        MIN=min(a,b);
        MAX=max(a,b);
        if(m1.count(MIN)==0){
            m1[MIN]=cnt;
            m2[cnt]=MIN;
            cnt++;
        }
        if(m1.count(MAX)==0){
            m1[MAX]=cnt;
            m2[cnt]=MAX;
            cnt++;
        }
        if(V.empty())V.push_back(Node(MIN,MAX,t));
        else{
            string aa=V[V.size()-1].l,bb=V[V.size()-1].r;
            if(aa==MIN&&bb==MAX)V[V.size()-1].t+=t;
            else V.push_back(Node(MIN,MAX,t));
        }
    }
    for(int i=0;i<cnt;i++){
        root[i]=i;
        m_rank[i]=0;
    }
    for(int i=0;i<V.size();i++){
        int ln=m1[V[i].l],rn=m1[V[i].r];
        //cout<<ln<<" "<<rn<<" "<<V[i].t<<endl;
        m_union(ln,rn,V[i].t);
    }
    for(int i=0;i<cnt;i++){
        find_root(i);
        //cout<<root[i]<<" "<<m_rank[i]<<endl;
        if(m3.count(root[i])==0){
            Node2 temp;
            temp.size=1;
            temp.tot_rank=m_rank[i];
            temp.max_rank=m_rank[i];
            temp.name=m2[i];
            m3[root[i]]=temp;
        }
        else{
            m3[root[i]].size++;
            m3[root[i]].tot_rank+=m_rank[i];
            if(m_rank[i]>m3[root[i]].max_rank){
                m3[root[i]].max_rank=m_rank[i];
                m3[root[i]].name=m2[i];
            }
            else if(m_rank[i]==m3[root[i]].max_rank){
                m3[root[i]].name=min(m3[root[i]].name,m2[i]);
            }
        }
    }
    int cnt2=0;
    for(auto i:m3){
        if(i.second.size>2&&i.second.tot_rank>K*2)cnt2++;
    }
    cout<<cnt2;
    for(auto i:m3){
        if(i.second.size>2&&i.second.tot_rank>K*2){
            Node3 temp;
            temp.name=i.second.name;
            temp.size=i.second.size;
            V3.push_back(temp);
        }
    }
    sort(V3.begin(),V3.end());
    for(int i=0;i<V3.size();i++){
        cout<<endl<<V3[i].name<<" "<<V3[i].size;
    }
}
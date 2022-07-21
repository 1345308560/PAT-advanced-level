//23：17 - 23:22 AC
#include<iostream>
#include<set>
#include<map>
using namespace std;
int N,K;
map<string,set<int> > M;
int main(){
    cin>>N>>K;
    for(int i=0;i<K;i++){
        int course,num;
        cin>>course>>num;
        for(int j=0;j<num;j++){
            string name;
            cin>>name;
            if(M.count(name)==0){
                set<int> temp;
                temp.insert(course);
                M[name]=temp;
            }
            else M[name].insert(course);
        }
    }
    for(int i=0;i<N;i++){
        string name;
        cin>>name;
        cout<<name<<" "<<M[name].size();
        for(auto j:M[name]){
            cout<<" "<<j;
        }
        if(i<N-1)cout<<endl;
    }
}
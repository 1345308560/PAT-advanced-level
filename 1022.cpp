#include<iostream>
#include<cstdio>
#include<map>
#include<set>
using namespace std;
int N,M;
map<string,set<string> > Msv;
void Add(string t,string id){
    if(Msv.count(t)==0){
        set<string> temp;
        temp.insert(id);
        Msv[t]=temp;
    }
    else Msv[t].insert(id);
}
void Add_k(string s,string id){
    int l=0,r=0,len=s.length();
    while(l<len&&r<=len){
        for(;r<=len;r++)
            if(s[r]==' '||r==len){
                string temp=s.substr(l,r-l);
                //cout<<endl<<temp<<endl;
                Add(temp,id);
                l=r+1;
                r=r+1;
                break;
            }
    }
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        string ID,year;
        string title,author,key,publisher;
        cin>>ID;getchar();
        getline(cin,title);
        getline(cin,author);
        getline(cin,key);
        getline(cin,publisher);
        cin>>year;
        Add(year,ID);
        Add(title,ID);
        Add_k(key,ID);
        Add(author,ID);
        Add(publisher,ID);
        //cout<<ID<<" "<<title<<" "<<author<<" "<<year<<endl;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        int num;
        scanf("%d: ",&num);
        string str;
        getline(cin,str);
        cout<<num<<": "<<str<<endl;
        if(Msv.count(str)==0){
            cout<<"Not Found";
        }
        else{
            int s=0;
            for(auto i:Msv[str]){
                cout<<i;
                if(s<Msv[str].size()-1)cout<<endl;
                s++;
            }
        }
        if(i<M-1)cout<<endl;
    }
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
struct Node{
    string name,cla;
    int grade;
    bool operator < (const Node B)const{
        return grade > B.grade;
    }
};
vector<Node> Vm,Vf;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        Node temp;
        char c;
        cin>>temp.name>>c>>temp.cla>>temp.grade;
        if(c=='M')Vm.push_back(temp);
        else Vf.push_back(temp);
    }
    sort(Vm.begin(),Vm.end());
    sort(Vf.begin(),Vf.end());
    if(Vm.size()==0){
        cout<<Vf[0].name<<" "<<Vf[0].cla<<endl;
        cout<<"Absent\n";
        cout<<"NA";
    }
    else if(Vf.size()==0){
        cout<<"Absent\n";
        cout<<Vm[Vm.size()-1].name<<" "<<Vm[Vm.size()-1].cla<<endl;
        cout<<"NA";
    }
    else{
        cout<<Vf[0].name<<" "<<Vf[0].cla<<endl;
        cout<<Vm[Vm.size()-1].name<<" "<<Vm[Vm.size()-1].cla<<endl;
        cout<<Vf[0].grade-Vm[Vm.size()-1].grade;
    }
}
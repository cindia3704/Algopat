/*
    작성자: 김지수
    작성일: 2022/07/27
    백준 -- 가장 가까운 공통 조상 (3584번)
*/

#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;
int totalNode;
vector<int> parent[MAX];
vector<int> ancestor1;
vector<int> ancestor2; 

void getAnces1(int node){
    ancestor1.push_back(node);
    for(int i=0;i<parent[node].size();i++){
        getAnces1(parent[node][i]);
    }
}
void getAnces2(int node){
    ancestor2.push_back(node);
    for(int i=0;i<parent[node].size();i++){
        getAnces2(parent[node][i]);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int testCase;
    cin>>testCase;

    while(testCase--){
        ancestor1.clear();
        ancestor2.clear();
        for(int i=0;i<MAX;i++){
            parent[i].clear();
        }

        cin>>totalNode;
        for(int i=1;i<totalNode;i++){
            int par,child;
            cin>>par>>child;
            parent[child].push_back(par);
        }

        int target1,target2;
        cin>>target1>>target2;
        getAnces1(target1);
        getAnces2(target2); 
        
        bool found = false;
        for(int i=0;i<ancestor1.size();i++){
            for(int j=0;j<ancestor2.size();j++){
                if(ancestor1[i] == ancestor2[j] && !found){
                    found= true;
                    cout<<ancestor1[i]<<"\n";
                    break;
                }
            }
        }
    }
}
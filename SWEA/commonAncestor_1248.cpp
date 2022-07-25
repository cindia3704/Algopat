/*
    작성자: 김지수
    작성일: 2022/07/24
    SWEA -- 공통 조상 (1248번)
*/

#include<iostream>
#include <vector>
#include <algorithm>
#include <set> 
#define MAX 10001

using namespace std;
vector<int> tree[MAX];
vector<int> ancestor1;
vector<int> ancestor2;
vector<int> treePToC[MAX];
int ansSize = 0;

void findAncestor1(int nodeNum){
    if(tree[nodeNum].size()>0){
        ancestor1.push_back(nodeNum);
        findAncestor1(tree[nodeNum][0]);
    }else{
        ancestor1.push_back(nodeNum);
        return;
    }
}
void findAncestor2(int nodeNum){
    if(tree[nodeNum].size()>0){
        ancestor2.push_back(nodeNum);
        findAncestor2(tree[nodeNum][0]);
    }else{
        ancestor2.push_back(nodeNum);
        return;
    }
}
void findSizeofSubTree(int node){
    ansSize++;
    for(int i=0;i<treePToC[node].size();i++){
        findSizeofSubTree(treePToC[node][i]);
    }
}

int main(int argc, char** argv)
{
    int t;
    cin>>t;
	for(int test_case = 1; test_case <= t; ++test_case)
	{
        int totalNode, totalEdge, target1,target2; 
        cin>>totalNode>>totalEdge>>target1>>target2; 
        for(int i=0;i<MAX;i++){
            tree[i].clear();
            treePToC[i].clear();
        }
        ancestor1.clear();
        ancestor2.clear();
        ansSize = 0;
        for(int i=0;i<totalEdge;i++){
            int parent,child;
            cin>>parent>>child;
            tree[child].push_back(parent);
            treePToC[parent].push_back(child);
        }
        findAncestor1(tree[target1][0]);
        findAncestor2(tree[target2][0]); 
       
       // 가장 가까운 조상 찾기 ( 깊이가 깊다고 노드 번호가 더 높은게 아님! -> 찾으면 그만 업데이트 )
        int commonAnces; 
        bool found = false;
        for(int i=0;i<ancestor1.size();i++){
            for(int j=0;j<ancestor2.size();j++){
                if(ancestor1[i] == ancestor2[j] && !found){
                    found = true;
                    commonAnces =ancestor1[i];
                    break;
                }
            }
        }

        
        findSizeofSubTree(commonAnces);
        cout<<"#"<<test_case<<" "<<commonAnces<<" "<<ansSize<<'\n';
    
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
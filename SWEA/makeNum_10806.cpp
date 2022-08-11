/*
    작성자: 김지수
    작성일: 2022/08/11
    SWEA -- 수 만들기 (10806번)
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> numberList; 
int numCnt, target; 
struct Node{
    int x;
    int addCnt;
};

struct cmp{
    bool operator()(Node a,Node b){
        return a.addCnt > b.addCnt;
    }
};

int bfs(){
    priority_queue<Node,vector<Node>,cmp> q; 
    Node start;
    start.addCnt=0;
    start.x = target;
    q.push(start);
    int ans =0;
    while(!q.empty()){
        Node now = q.top();
        q.pop();
        if(now.x == 0){
            ans = now.addCnt;
            break;
        }
        bool found = false;
        for(int i=0;i<numCnt;i++){
            int a = numberList[i];
            if(now.x>=a){
                found = true;
                Node next; 
                next.x = (now.x/a);
                next.addCnt = now.addCnt + (now.x%a);
                q.push(next);
            }
        }
        if(!found){
            Node next; 
            next.x = 0;
            next.addCnt = now.addCnt+now.x;
            q.push(next);
        }
        
    }
    return ans;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        numberList.clear();
        cin>>numCnt;
        
        for(int i=0;i<numCnt;i++){
            int a;
            cin>>a;
            numberList.push_back(a);
        }

        cin>>target;
       
        cout<<"#"<<test_case<<" "<<bfs()<<'\n';
	}
	return 0;
}
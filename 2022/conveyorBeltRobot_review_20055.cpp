/*
    작성자: 김지수
    작성일: 2022/10/12
    백준 -- 컨베이어 벨트 위의 로봇 (20055번)
*/

#include <iostream>
#include <deque>
using namespace std; 
int n,k;

deque<pair<int,bool> > belt;
void print(){
    for(int i=0;i<belt.size();i++){
        cout<<"("<<belt[i].first<<" , "<<belt[i].second<<")"<<endl;
    }
}

bool check(){
    int cnt =0;
    for(int i=0;i<belt.size();i++){
        if(belt[i].first ==0){
            cnt++;
        }
    }
    if(cnt>=k){
        return true;
    }else{
        return false;
    }
}

void moveBelt(){
    if(belt[n-1].second==true){
        belt[n-1].second = false;
    }
    pair<int,bool> temp = belt.back();
    belt.push_front(temp);
    belt.pop_back();
    if(belt[n-1].second==true){
        belt[n-1].second = false;
    }
}

void moveRobot(){
    for(int i=n-1;i>=0;i--){
        pair<int,bool> now = belt[i];
        if(now.second == true){
            int ny = i;
            if(i==n-1){
                belt[i].second = false;
                continue;
            }
            int next = i+1;
            if(belt[next].second == false && belt[next].first >=1){
                belt[i].second = false;
                belt[next].second = true;
                belt[next].first--;
                ny = next;
                if(next==n-1){
                    belt[next].second = false;
                }
            }
        }
    }
}
void addRobot(){
    if(belt[0].first >0 && belt[0].second == false){
        belt[0].first --;
        belt[0].second = true;
    }
    if(belt[n-1].second ==true){
        belt[n-1].second = false;
    }
}

int startGame(){
    int stage = 1;
    while(true){
        moveBelt();
        moveRobot();
        addRobot();
        if(check()){
            break;
        }
        stage++;
    }
    return stage; 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<2*n;i++){
        int num;
        cin>>num;
        belt.push_back(make_pair(num,false));
    }
    cout<<startGame();

}
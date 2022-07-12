/*
    작성자: 김지수
    작성일: 2022/07/12
    백준 -- ⚾ (17281번)
*/

#include <iostream> 
#include <cstring>
#include <queue>
#define MAX 51
using namespace std; 

int iningNum;
int result[MAX][10];
bool picked[10];
int pick[10];
int ans=0; 
int base[3]; 

// 1루 -> 2루 -> 3루 -> 마지막으로 1칸씩 옮기기 
int moveBase(){
    int ret = 0;
    // 3루에 사람이 있으면 점수 ++ 
    if(base[2]!=-1){
        ret++;
    }
    base[2] = -1;
    // 이전base 에 있는 사람이 현재 base로 오고, 이전 base = -1(비어있다)로 세팅 
    for(int i=2;i>0;i--){
        base[i] = base[i-1];
        base[i-1]=-1;
    }
    return ret; 
}


int calcScore(){
    memset(base,-1,sizeof(base));
    int outCount = 0; 
    int idx = 0;
    int ining = 0;
    int score =0;
   
    while(ining < iningNum){
        int nowPlayer = pick[idx];
        int nowResult = result[ining][nowPlayer];
        switch (nowResult)
        {
        case 0: // 아웃
            outCount ++;
            break;
        case 1: // 안타
            score += moveBase();
            base[0] = nowPlayer;
            break;
        case 2: // 2루타
            score+=moveBase();
            base[0] = nowPlayer;
            score+=moveBase();
            break;
        case 3: // 3루타 
            score+=moveBase();
            base[0] = nowPlayer;
            score+=moveBase();
            score+=moveBase();
            break;
        case 4: // 홈런 
            score+=moveBase();
            base[0] = nowPlayer;
            score+=moveBase();
            score+=moveBase();
            score+=moveBase();
            break;
        default:
            break;
        }

        idx++;
        // 아웃이 3번이면 이닝 끝 -> base에 아무도 없게 세팅 
        if(outCount == 3){
            ining++;
            outCount = 0;
            memset(base,-1,sizeof(base));
        }
        // 이닝이 바뀌어도 타순은 변하지 않음=> 9번타자가 친다음엔 1번타자 차례
        if(idx == 9){
            idx = 0;
        }
    }
    return score;
}

void makeComb(int pickCount){
    if(pickCount == 9){
        // 9명 다 뽑으면 점수 계산 후 최대값 업데이트 
        int temp = calcScore();
        ans = max(ans,temp);
        return;
    }else if(pickCount == 3){
        // 가장 좋아하는 선수인 1번 선수를 4번 타자로 미리 결정했다
        pick[pickCount] = 0;
        picked[0] = true;
        makeComb(pickCount+1);
    }else{
        // 1번선수가 4번타자로 미니 결정되었기 때문에 2번선수부터 돌림 
        for(int i=1;i<9;i++){
            if(!picked[i]){
                picked[i] = true;
                pick[pickCount] = i;
                makeComb(pickCount+1);
                picked[i] = false;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>iningNum;

    for(int i=0;i<iningNum;i++){
        for(int j=0;j<9;j++){
            cin>>result[i][j];
        }
    }

    memset(picked,false,sizeof(picked));
    makeComb(0);
    cout<<ans;
}
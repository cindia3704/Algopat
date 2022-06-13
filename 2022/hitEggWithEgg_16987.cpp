/*
    작성자: 김지수
    작성일: 2022/06/13
    백준 -- 계란으로 계란치기 (16987번)
*/

#include <iostream>
#include <algorithm> 
#define MAX 9
using namespace std;

struct EGG{
    int eggStrength;
    int eggWeight; 
};

int eggNum; 
EGG eggList[MAX];
bool broken[MAX];
int ans =0;

void makeComb(int pickedIdx){
    // 왼쪽부터 하나씩 보니, 모든 계란 다 볼때까지 반복 
    // 모든 계란 다 보면 깨진 계란 개수 구한후 최대값 업데이트 
    if(pickedIdx == eggNum){
        int countBroken = 0;
        for(int i=0;i<eggNum;i++){
            if(broken[i]){
                countBroken++;
            }
        }
        if(countBroken>ans){
            ans = countBroken;
        }
        return;
    } else if(broken[pickedIdx]){
        // 이전에 손에 쥔 계란 바로 옆 계란 들기 때문에 만약 깨진 계란 들었으면 다음 계란 보기 
        makeComb(pickedIdx+1);
        }
        else{
            // 순서대로 보면서 
            for(int i=0;i<eggNum;i++){
                // 지금 달걀로 깰 다음 달걀 고르기 
                if(!broken[i] && i!=pickedIdx){
                    // 계란 1 & 2의 내구도 계산 
                    eggList[i].eggStrength -=eggList[pickedIdx].eggWeight;
                    eggList[pickedIdx].eggStrength -= eggList[i].eggWeight;

                    // 내구도가 0이하면 깨진것 
                    if(eggList[i].eggStrength<=0){
                        broken[i] = true; 
                    }
                    if(eggList[pickedIdx].eggStrength<=0){
                        broken[pickedIdx] = true; 
                    }
                    // 다음 계란 들기 
                    makeComb(pickedIdx+1);

                    // 내구도 복구 & 모두 깨지지 않았다고 업데이트 
                    eggList[i].eggStrength +=eggList[pickedIdx].eggWeight;
                    eggList[pickedIdx].eggStrength += eggList[i].eggWeight;
                    broken[i] = false;
                    broken[pickedIdx] = false; 
                }
                // 계란이 하나남은 경우 고려 (마지막 하나)
                else if(i==eggNum-1){
                    makeComb(pickedIdx+1);
                }
            }
        }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>eggNum;

    // 모든 달걀의 내구도 & 무게 입력 받음 
    for(int i=0;i<eggNum;i++){
        cin>>eggList[i].eggStrength>>eggList[i].eggWeight;
    }

    // 계란 깨짐 여부 기록 
    fill(broken,broken+MAX,false);


    makeComb(0);
    cout<<ans;
    
}
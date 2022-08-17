/*
    작성자: 김지수
    작성일: 2022/08/18
    백준 -- 1 (4375번)
*/

#include <iostream>
using namespace std; 
int getAns(int num){
    long long div = 0; 
    int digitCnt=0;
    bool found = false; 
    while(!found){
        div=(div*10)+1;
        digitCnt++;
        div%=num;
        if(div == 0){
            found =true; 
        }
    }
    return digitCnt;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (1) {
        int num;
        cin >> num;
        if (cin.eof()) break; // cin.eof() returns true if eof
        cout<<getAns(num)<<'\n';
    }
    return 0;
}
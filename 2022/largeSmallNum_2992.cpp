/*
    작성자: 김지수
    작성일: 2022/10/05
    백준 -- 크면서 작은 수 (2992번)
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 7
using namespace std; 

vector<int> numberList;



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string number; 
    cin>>number;
    for(int i=0;i<number.length();i++){
        int num = number[i]-'0';
        numberList.push_back(num);
    }   

    next_permutation(numberList.begin(),numberList.end());
    int changedNum = 0;
    for(int i=0;i<numberList.size();i++){
       changedNum=(changedNum*10)+numberList[i];
    }
    if(changedNum<=stoi(number)){
        cout<<0;
    }else{
        cout<<changedNum;
    }
}
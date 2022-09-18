/*
    작성자: 김지수
    작성일: 2022/09/18
    프로그래머스 -- N개의 최소공배수 (12953번)
*/

#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
int answer = 1;
bool used[101];

int findGCD(int a, int b){
    if(b>a){
        swap(a,b);
    }
    if(b==0){
        return a;
    }else{
        return findGCD(b,a%b);
    }
}

int findLCM(int a,int b){
    return a*b/findGCD(a,b);
}

int solution(vector<int> arr) {
    sort(arr.begin(),arr.end()); 
    answer=arr[0];
    for(int i=1;i<arr.size();i++){
        answer=findLCM(answer,arr[i]);
    }
    return answer;
}
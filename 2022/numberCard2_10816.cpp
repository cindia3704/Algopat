/*
    작성자: 김지수
    작성일: 2022/06/22
    백준 -- 숫자 카드 2 (10816번)
*/

#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
using namespace std; 


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; 
    cin>>n;
    vector<int> nums;
    
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        nums.push_back(number);
    }
    sort(nums.begin(),nums.end());
    
    int m;
    cin>>m;
    while(m--){
        int input;
        cin>>input;
        //등장 횟수 = 가장 마지막에 등장한 index - 가장 처음 등장한 index
        cout<< upper_bound(nums.begin(),nums.end(),input) - lower_bound(nums.begin(),nums.end(),input)<<" ";
    }


}

/*
    작성자: 김지수
    작성일: 2022/09/07
    프로그래머스 -- 최댓값과 최솟값 (12939번)
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> numList;

string solution(string s) {
    string answer = "";
    int idx = 0;
    string num ="";
    while(idx<s.length()){
        if(s[idx]==' '){
            int addNum = stoll(num);
            numList.push_back(addNum);
            num = "";
        }else{
        num= num+ s[idx];
        }
        idx++;
    }
    numList.push_back(stoll(num));
    sort(numList.begin(),numList.end());
    
    answer+=to_string(numList[0]);
    answer+=" ";
    answer+=to_string(numList[numList.size()-1]);
    return answer;
}
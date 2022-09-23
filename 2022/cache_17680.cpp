/*
    작성자: 김지수
    작성일: 2022/09/23
    백준 -- [1차] 캐시 (17680 번)
*/

#include <string>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#define HIT 1
#define MISS 5

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> q; 
    
    for(int i=0;i<cities.size();i++){
        string now = cities[i];
        for(int j=0;j<now.length();j++){
            now[j] =tolower(now[j]);
        }
        if(cacheSize>0){
        if(find(q.begin(),q.end(),now)==q.end()){
            if(q.size()<cacheSize){
                q.push_back(now);
                answer+=MISS;
            }else{
                q.pop_front();
                answer+=MISS;
                q.push_back(now);
            }
        }else{
            answer+=HIT;
            for(deque<string> ::iterator it = q.begin();it!=q.end();it++){
                if(*it == now){
                    q.erase(it);
                    break;
                }
            }
            q.push_back(now);
        }
        }else{
            answer+=MISS;
        }
    }
    return answer;
}
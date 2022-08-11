/*
    KMP 알고리즘 구현 
*/

#include <iostream>
#include <vector> 
using namespace std; 

// 접두사 & 접미사가 일치하는 최대길이 구하는 함수 
// ex: a b a c a a b a => 0 0 1 0 1 1 2 3
vector<int> makeTable(string word){
    int patternSize = word.size();
    vector<int> table(patternSize,0);
    int j=0;
    for(int i=1;i<patternSize;i++){
        while(j>0 && word[j]!=word[i]){
            j = table[j-1];
        }
        if(word[j]==word[i]){
            table[i] = ++j;
        }
    } 
    return table;
}

int KMP(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int sameCnt = 0;
    int j=0;
    for(int i=0;i<parentSize;i++){
        while(j>0 && pattern[j]!=parent[i]){
            j=table[j-1];
        }
        if(parent[i]==pattern[j]){
            if(j==patternSize-1){
                sameCnt++;
                cout<<"found in "<<i-patternSize+2<<endl;
                j=table[j];
            }else{
                j++;
            }
        }
    }
    return sameCnt;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int temp = KMP("ababacabacaabacaaba","abacaaba");
    cout<<"Found Cnt:"<<temp<<endl;
}
/*
    작성자: 김지수
    작성일: 2022/07/19
    SWEA -- 새로운 불면증 치료법 (1288번)
*/

#include <iostream>
#include <cstring>
#include <string> 

using namespace std;
bool used[10];
bool check(){
    for(int i=0;i<10;i++){
        if(used[i] == false){
            return false;
        }
    }
    return true;
}

int findTurn(int n){
    int countTurn = 1;
    long long nowNum = n;
    string numString = to_string(n);

    for(int i=0;i<numString.size();i++){
        if(!used[numString[i]-'0']){
            used[numString[i]-'0'] = true;
        }
    }

    while(!check()){
        countTurn++;
        nowNum = n*countTurn;
        numString = to_string(nowNum);
        for(int i=0;i<numString.size();i++){
            if(!used[numString[i]-'0']){
                used[numString[i]-'0'] = true;
            }
        }
    }
    
    return countTurn;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n; 
        cin>>n; 
        memset(used,false,sizeof(used));
        
        int turn = findTurn(n);
        cout<<"#"<<test_case<<" "<<turn*n<<'\n';
		


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
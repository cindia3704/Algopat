/*
    작성자: 김지수
    작성일: 2022/09/08
    백준 -- 괄호 추가하기 (16637번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <string> 
#define MAX 20
using namespace std; 

int eqLen;
char equation[MAX];
int calculated[MAX];
int pick[MAX];
int ans = -0x7fffffff;
int calc(int num1,string op,int num2){
    if(op.compare("+")==0){
        return num1+num2;
    }else if(op.compare("-")==0){
        return num1-num2;
    }else if(op.compare("*")==0){
        return num1*num2;
    }
}

void makeComb(int pickCount){
    if(pickCount == eqLen/2){
        stack<string> st; 
        int idx = 0;
        while(idx<eqLen){
            if(idx%2==1){
                st.push(string(1,equation[idx]));
                idx++;
            }else{
                if(idx == eqLen-1){
                    int temp = equation[idx]-'0';
                    if(!st.empty()){
                        string ops = st.top();
                        st.pop();
                        int num = stoi(st.top());
                        temp = calc(num,ops,temp);
                    }
                    st.push(to_string(temp));
                    idx++;
                }
                else{
                    if(pick[idx/2]==1){
                        int temp = calculated[idx/2];
                        if(!st.empty()){
                            string ops = st.top();
                            st.pop();
                            int num = stoi(st.top());
                            temp = calc(num,ops,temp);
                        }
                        st.push(to_string(temp));
                        idx+=3;
                    }else{
                        int temp = equation[idx]-'0';
                        if(!st.empty()){
                           string ops = st.top();
                            st.pop();
                            int num = stoi(st.top());
                            temp = calc(num,ops,temp);
                        }
                        st.push(to_string(temp));
                        idx++;
                    }
                }
            }
        }
        int tempAns = stoi(st.top());
        ans = max(ans,tempAns);
        return;
    }
    if(pickCount == 0){
        pick[pickCount]=1;
        makeComb(pickCount+1);
        pick[pickCount]=0;
        makeComb(pickCount+1);
    }else{
        if(pick[pickCount-1]==1){
            pick[pickCount] = 0;
            makeComb(pickCount+1);
        }else{
            pick[pickCount]=1;
            makeComb(pickCount+1);
            pick[pickCount]=0;
            makeComb(pickCount+1);
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>eqLen; 
    string s; 
    cin>>s;
    for(int i=0;i<s.length();i++){
        equation[i] = s[i];
    }
    if(eqLen/2>0){
        int idx = 0;
        for(int i=0;i<s.length()-2;){
            calculated[idx] = calc(equation[i]-'0',string(1,equation[i+1]),equation[i+2]-'0');
            idx++;
            i+=2;
        }
        makeComb(0);
    }else{
        ans = s[0]-'0';
    }
    cout<<ans;
}
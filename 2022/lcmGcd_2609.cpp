/*
    작성자: 김지수
    작성일: 2022/08/18
    백준 -- 약수의 합 (17425번)
*/
#include <iostream>
using namespace std; 

int calcGCD(int a, int b){
    if(b%a==0){
        return a; 
    }else{
        return calcGCD(b%a,a);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b; 
    cin>>a>>b; 
    if(b<a){
        int temp;
        temp = a;
        a = b; 
        b = temp;
    }
   int gcd = calcGCD(a,b);
   cout<<gcd<<'\n';
   cout<<gcd*(a/gcd)*(b/gcd);
}
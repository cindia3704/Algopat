/*
    작성자: 김지수
    작성일: 2022/08/26
    SWEA -- Segment Tree 연습 - 2 (14733번)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define MAX 100001

using namespace std;
struct SegmentTree{
    ll n;
    vector<ll> tree; 

    ll merge(ll left,ll right){
        return (left+right);
    }
    
    ll buildTree(const ll arr[],ll node, ll left, ll right){
       // cout<<"buildTree "<<left<<" - "<<right<<"  node:"<<node<<endl;
        if(left == right){
            return tree[node] = arr[left];
        }
        ll mid = left+(right-left)/2;
        ll lVal = buildTree(arr,node*2,left,mid);
        ll rVal = buildTree(arr,node*2+1,mid+1,right);
        return tree[node] = merge(lVal,rVal);
    }

    void make(const ll arr[],ll size){
        n = size; 
        tree.resize(n*4);
        buildTree(arr,1,0,n-1);
    }

    ll calcQuery(ll left,ll right, ll node, ll nodeLeft,ll nodeRight){
        if(right<nodeLeft || nodeRight<left){
            return 0;
        }
        if(left<=nodeLeft && nodeRight<=right){
            return tree[node];
        }

        ll mid = nodeLeft + (nodeRight-nodeLeft)/2;
        return merge(calcQuery(left,right,node*2,nodeLeft,mid),calcQuery(left,right,node*2+1,mid+1,nodeRight));
    }

    ll query(ll left,ll right){
        return calcQuery(left,right,1,0,n-1);
    }

    ll updateData(ll index, ll newValue, ll node,ll nodeLeft,ll nodeRight){
        if(index<nodeLeft || nodeRight<index){
            return tree[node];
        }
        if(nodeLeft == nodeRight){
            return tree[node] = newValue;
        }

        ll mid = nodeLeft + (nodeRight-nodeLeft)/2;
        ll lVal = updateData(index,newValue,node*2,nodeLeft,mid);
        ll rVal = updateData(index,newValue,node*2+1,mid+1,nodeRight);
        return tree[node] = merge(lVal,rVal);
    }
    ll update(int index, int newVal){
        return updateData(index,newVal,1,0,n-1);
    }
};

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	int test_case;
	int T;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{   
        SegmentTree tree;
        vector<ll> ans; 
        ll arr[MAX];
        ll arrLength, queryCnt;
        cin>>arrLength>>queryCnt;
        for(int i=0;i<arrLength;i++){
            cin>>arr[i];
            if(i%2==1){
                arr[i]*=-1;
            }
        }
        tree.make(arr,arrLength);
        for(ll i=0;i<queryCnt;i++){
            int command; 
            cin>>command;
            if(command == 0){
                ll idx, changeVal;
                cin>>idx>>changeVal;
                if(idx%2==1){
                    changeVal=-changeVal;
                }
                tree.update(idx,changeVal);
            }else{
                ll left,right; 
                cin>>left>>right; 
                ll sum = tree.query(left,right-1);
                if(left%2==1){
                    sum*=-1;
                }
               
                ans.push_back(sum);
            }
        }

        cout<<"#"<<test_case<<" ";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
	}
	return 0;
}
/*
    작성자: 김지수
    작성일: 2022/08/26
    SWEA -- Segment Tree 구현
*/

#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

struct SegmentTree{
    int n;
    vector<int> tree; 

    int merge(int left,int right){
        return (left+right);
    }
    
    int buildTree(const int arr[],int node, int left, int right){
        cout<<"buildTree "<<left<<" - "<<right<<"  node:"<<node<<endl;
        if(left == right){
            return tree[node] = arr[left];
        }
        int mid = left+(right-left)/2;
        int lVal = buildTree(arr,node*2,left,mid);
        int rVal = buildTree(arr,node*2+1,mid+1,right);
        return tree[node] = merge(lVal,rVal);
    }

    void make(const int arr[],int size){
        cout<<"make!"<<endl;
        n = size; 
        tree.resize(n*4);
        cout<<"resize done!"<<endl;
        buildTree(arr,1,0,n-1);
    }

    int calcQuery(int left,int right, int node, int nodeLeft,int nodeRight){
        if(right<nodeLeft || nodeRight<left){
            return 0;
        }
        if(left<=nodeLeft && nodeRight<=right){
            return tree[node];
        }

        int mid = nodeLeft + (nodeRight-nodeLeft)/2;
        return merge(calcQuery(left,right,node*2,nodeLeft,mid),calcQuery(left,right,node*2+1,mid+1,nodeRight));
    }

    int query(int left,int right){
        return calcQuery(left,right,1,0,n-1);
    }

    int updateData(int index, int newValue, int node,int nodeLeft,int nodeRight){
        if(index<nodeLeft || nodeRight<index){
            return tree[node];
        }
        if(nodeLeft == nodeRight){
            return tree[node] = newValue;
        }

        int mid = nodeLeft + (nodeRight-nodeLeft)/2;
        int lVal = updateData(index,newValue,node*2,nodeLeft,mid);
        int rVal = updateData(index,newValue,node*2+1,mid+1,nodeRight);
        return tree[node] = merge(lVal,rVal);
    }
    int update(int index, int newVal){
        return updateData(index,newVal,1,0,n-1);
    }
};

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int arrLength;
    cin>>arrLength;
    int arr[MAX];
    for(int i=0;i<arrLength;i++){
        cin>>arr[i];
    }
    SegmentTree sTree; 
    sTree.make(arr,arrLength);
    cout<<"sum 0-3: "<<sTree.query(0,3)<<endl;
    cout<<"sum 1-3: "<<sTree.query(1,3)<<endl;
    cout<<"sum 1-4: "<<sTree.query(1,4)<<endl;
    cout<<"change 0 to 7"<<endl;
    sTree.update(0,7);
    cout<<"sum 0-3: "<<sTree.query(0,3)<<endl;


}
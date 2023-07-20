#include<bits/stdc++.h>
class node{
    public:
    int data;
    int row,col;
    node(int d, int i , int j){
        data = d;
        row = i;
        col = j;
    }
};
class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.

    priority_queue<node*, vector<node*>, compare>minHeap;
   // if(k==0) return 0;
   int mx = INT_MIN;
    for(int i=0;i<k;i++){
        node* temp = new node(a[i][0], i,0);
        minHeap.push(temp);
        mx = max(mx,a[i][0]);
    }
    int minimum = INT_MAX;
    while(!minHeap.empty()){
        node* top = minHeap.top();
        int mn = top->data;
        int row = top->row;
        int col = top->col;
        minHeap.pop();

        if(mx-mn<=minimum) minimum = mx-mn;
        if(col+1 < a[row].size()){
            node* temp = new node(a[row][col+1], row, col+1);
            minHeap.push(temp);
            mx = max(a[row][col+1],mx);
        }else break;
    }
    return minimum == INT_MAX ? 0 : minimum+1;
}

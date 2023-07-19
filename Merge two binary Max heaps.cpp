class Solution{
    private:
    void hepify(vector<int>&ans, int &size, int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left<size and ans[largest] < ans[left]) largest = left;
        if(right<size and ans[largest] < ans[right]) largest = right;
        if(largest!=i){
            swap(ans[largest], ans[i]);
            hepify(ans, size, largest);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>ans;
        for(auto i:a) ans.push_back(i);
        for(auto i:b) ans.push_back(i);
        int size = n+m;
        for(int i = size/2-1;i>=0;i--){
            hepify(ans, size, i);
        }
        return ans;
    }
};

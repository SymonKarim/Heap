#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	int n = arr.size();
	priority_queue<int,vector<int>, greater<int>> pq;
	int sum =0;
	for(int i=0;i<n;i++){
		sum = 0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			if(pq.size()<k){
			  pq.push(sum);
			}
			else{
				if(sum > pq.top()){
					pq.pop();
					pq.push(sum);
				} 
		   }
		}
		
	}
	return pq.top();
}

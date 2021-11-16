#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
	vector<int> nums;

	public:
	
	int parent(int i) { return (i-1)/2; }
	int lchild(int i) { return 2 * i + 1; }
	int rchild(int i) { return 2 * i + 2; }
	int size() { return nums.size(); }
	
	void push(int num) {
		nums.push_back(num);
		int i = size() - 1;
		percolateUp(i);
	}
	
	void percolateUp(int i) {
		if(i <= 0) {
			return;
		}
		
		int p = parent(i);
		if(nums[p] > nums[i]) {
			swap(nums[p], nums[i]);
			percolateUp(p);
		}
	}
	
	int top() {
		return size() == 0 ? -1 : nums[0];
	}
	
	void pop() {
		if(size() == 1) {
			nums.pop_back();
		} else {
			swap(nums[0], nums[size() - 1]);
			nums.pop_back();
			percolateDown(0);
		}
	}
	
	void percolateDown(int i) {
		int lc = lchild(i);
		int rc = rchild(i);
		
		int imin = i;
		
		if(lc < size() && nums[lc] < nums[imin]) {
			imin = lc;
		}
		
		if(rc < size() && nums[rc] < nums[imin]) {
			imin = rc;
		}
		
		if(i != imin) {
			swap(nums[i], nums[imin]);
			percolateDown(imin);
		}
	}
};

int optimal_merge(int n, vector<int> nums) {
	MinHeap minHeap;
	for(int num : nums) {
		minHeap.push(num);
	}
	
	int totalMergeCost = 0;
	while(minHeap.size() > 1) {
		int record1 = minHeap.top();
		minHeap.pop();
		
		int record2 = minHeap.top();
		minHeap.pop();
		
		int mergeCost = record1 + record2;
		totalMergeCost += mergeCost;
		
		cout << "Cost of merging " << record1 << " and " << record2 << " is " << mergeCost << endl;
		
		minHeap.push(mergeCost);
	}
	
	return totalMergeCost;
}

int main() {
	int n;
	cout << "Enter no of records: ";
	cin >> n;
	
	vector<int> nums(n);
	cout << "Enter sizes of each record: ";
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	
	int optimal_merge_value = optimal_merge(n, nums);
	
	cout << optimal_merge_value << endl;
	
	return 0;
}

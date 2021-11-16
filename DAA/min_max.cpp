#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int mini, maxi;

void minMax(vector<int> arr, int i, int j) {
	if(i == j) { 
		mini = arr[i];
		maxi = arr[i];
	}
	
	else if(i == j - 1) {
		maxi = max(arr[i], arr[j]);
		mini = min(arr[i], arr[j]);
	} else {
		int mid = (i + j) / 2;
		
		int max1 = maxi;
		int min1 = mini;
		
		minMax(arr, i, mid);
		minMax(arr, mid + 1, j);
		
		maxi = max(max1, maxi);
		mini = min(min1, mini);
	}
}

int main() {
	
	int n;
	cout << "Enter no of elements in the array: ";
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	mini = INT_MAX;
	maxi = INT_MIN;
	
	int i = 0;
	int j = arr.size() - 1;
	
	minMax(arr, i , j);
	
	cout << "Maximum: " << maxi << endl;
	cout << "Minimum: " << mini << endl;
}

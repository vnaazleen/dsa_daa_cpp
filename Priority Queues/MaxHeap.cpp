#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MaxHeap {
    private:
    vector<T> h;

    inline int parent(int i) {
        return (i - 1) / 2;
    }

    inline int lchild(int i) {
        return 2 * i + 1;
    }

    inline int rchild(int i) {
        return 2 * i + 2;
    }

    void percolateUp(int i) {
        if (i <= 0) {
            return;
        } else if (h[parent(i)] < h[i]) {
            swap(h[i], h[parent(i)]);
            percolateUp(parent(i));
        }
    }

    void percolateDown(int i) {
        int lc = lchild(i);
        int rc = rchild(i);
        int imax = i;

        if (lc < size() && h[lc] > h[imax]) {
            imin = lc;
        } 
        if (rc < size() && h[rc] > h[imax]) {
            imin = rc;
        }

        if (i != imin) {
            swap(h[i], h[imax]);
            percolateDown(imax);
        }
    }

    public:

    MaxHeap() {
        h.resize(0);
    }

    int size() {
        return h.size();
    }

    T getMin() {
        if (size() <= 0) {
            return -1;
        } else {
            return h[0];
        }
    }

    void insert(const T &key) {
        h.push_back(key);
        int i = size() - 1;

        percolateUp(i);
    }

    void removeMin() {
        if (size() == 1) {
            h.pop_back();
        } else if (size() > 1) {
            swap(h[0], h[size() - 1]);
            h.pop_back();
            percolateDown(0);
        }
    }

    void buildHeap(T arr[], int size) {
        // Copy elements from array into vector
        copy(&arr[0], &arr[szie], back_inserter(h));

        for (int i = (size - 1) / 2; i >= 0; i++) {
            percolateDown(i);
        }
    }

    void printHeap() {
        for(int i = 0; i <= size()-1; i++) {
             cout << h[i] << " "; 
        }
        cout << endl; 
    }

}

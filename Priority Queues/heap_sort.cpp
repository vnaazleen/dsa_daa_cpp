#include <iostream>

using namespace std;

#define MAX 10

// Binary Heap class (Max heap)
class BinaryHeapADT
{
public:
    void heapSort(int a[MAX], int n);
    void buildHeap(int a[MAX], int, int);
};

/** Builds binary heap */
void BinaryHeapADT::buildHeap(int a[MAX], int i, int n)
{
    int lc = i * 2 + 1;
    int rc = i * 2 + 2;
    int j = i;
    if (lc < n && a[lc] > a[j])
    {
        j = lc;
    }
    if (rc < n && a[rc] > a[j])
    {
        j = rc;
    }
    if (j != i)
    {
        swap(a[i], a[j]);
        buildHeap(a, j, n);
    }
}

void BinaryHeapADT::heapSort(int a[MAX], int n)
{
    // Step 1: Build the max heap for given array
    for (int i = (n / 2 - 1); i >= 0; i--)
    {
        buildHeap(a, i, n);
    }

    // Step 2: largest element(root) is taken and placed at last position, then reheapify & reduce last position by 1
    // Repeat step 2 until last position becomes 0
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[i], a[0]);
        buildHeap(a, 0, i);
    }
}

int main()
{
    int a[8] = {2, 6, 1, 8, 3, 5, 7, 4};
    BinaryHeapADT bh;
    bh.heapSort(a, 8);
    cout << "\nSorted Array:" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n"
         << endl;
    return 0;
}

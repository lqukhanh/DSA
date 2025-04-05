#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
void printArray(vector<int> &a)
{
    int n = a.size();
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << a[i] << "]" << endl;
        }
        else
        {
            cout << a[i] << ",";
        }
    }
}
int nextGap(int gap)
{
    if (gap <= 1)
    {
        return 0;
    }
    return (int)ceil(gap / 2.0);
}

void inPlaceMerge(vector<int> &a, int l, int r)
{
    int gap = r - l + 1;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        for (int i = l; i + gap <= r; i++)
        {
            int j = i + gap;
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
    printArray(a);
}

void mergeSort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    inPlaceMerge(a, l, r);
}

int main()
{

    vector<int> a = {5, 4, 3, 2, 1};
    cout << "Initial: ";
    printArray(a);
    int n = a.size();
    mergeSort(a, 0, n - 1);
    cout << "Final: ";
    printArray(a);
    cout << "Max auxiliary space used: 0 elements (in-place merge)" << endl;
}

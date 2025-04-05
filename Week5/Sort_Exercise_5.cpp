#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Time complexity: O(k * n), với k = độ dài chuỗi tối đa, n = số chuỗi
// Space complexity: O(n + c), với c = 256 (bảng đếm ASCII)
void countingSort(vector<string> &s, int pos)
{
    int n = s.size();
    vector<int> count(256, 0);
    char ch;
    for (auto x : s)
    {
        if (pos < x.length())
        {
            ch = x[pos];
        }
        else
        {
            ch = 0;
        }
        count[ch]++;
    }
    for (int i = 1; i < 256; i++)
    {
        count[i] += count[i - 1];
    }
    vector<string> output(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (pos < s[i].length())
        {
            ch = s[i][pos];
        }
        else
        {
            ch = 0;
        }
        output[count[ch] - 1] = s[i];
        count[ch]--;
    }
    s = output;
}

void radixSort(vector<string> &s)
{
    int m = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (m < s[i].length())
        {
            m = s[i].length();
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        countingSort(s, i);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    radixSort(s);
    for (auto x : s)
    {
        cout << x << endl;
    }
}
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct job
{
    string name;
    int time;
};

struct Processer
{
    int load = 0;
    vector<string> listName;
};

void merge(vector<job> &a, vector<job> &aux, int l, int m, int r)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        aux[i] = a[i];
    }
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
    {
        if (aux[i].time >= aux[j].time)
        {
            a[k++] = aux[i++];
        }
        else if (aux[i].time < aux[j].time)
        {
            a[k++] = aux[j++];
        }
    }
    while (i <= m)
    {
        a[k++] = aux[i++];
    }
    while (j <= r)
    {
        a[k++] = aux[j++];
    }
}

void mergeSort(vector<job> &a, vector<job> &aux, int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(a, aux, l, m);
    mergeSort(a, aux, m + 1, r);
    merge(a, aux, l, m, r);
}

int loadProblem(vector<job> &jobs, vector<Processer> &processers, int n, int t)
{
    for (int i = 0; i < n; i++)
    {
        int idx = 0;
        int m = INT_MAX;
        for (int j = 0; j < t; j++)
        {
            if (processers[j].load < m)
            {
                idx = j;
                m = processers[j].load;
            }
        }
        processers[idx].load += jobs[i].time;
        processers[idx].listName.push_back(jobs[i].name);
    }
    int result = 0;
    for (int i = 0; i < t; i++)
    {
        if (processers[i].load > result)
        {
            result = processers[i].load;
        }
    }
    return result;
}

int main()
{
    int n, t;
    cin >> t >> n;
    vector<job> aux(n);
    vector<job> jobs(n);
    vector<Processer> processers(t);
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].name >> jobs[i].time;
    }
    mergeSort(jobs, aux, 0, n - 1);

    int result = loadProblem(jobs, processers, n, t);
    for (int i = 0; i < t; i++)
    {
        cout << "Processor " << i + 1 << ": ";
        for (auto x : processers[i].listName)
        {
            cout << x << " ";
        }
        cout << "(load: " << processers[i].load << ")" << endl;
    }
    cout << "Makespan: " << result << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int s1(vector<int> nbs, int target) {
    unordered_map<int, int> m;

    for (int i = 0; i < (int)nbs.size(); i++) {
        int nb = nbs[i];
        if (m[target - nb] == 1)
            return nb * (target - nb);
        m[nb] = 1;
    }
    return -1;
}


/* assume vector already sorted */
int twoPointer(vector<int> nbs, int target) {
    int low = 0, high = nbs.size()-1;

    while (low < high) {
        int sm = nbs[low] + nbs[high];
        if (sm == target)
            return nbs[low] * nbs[high];
        else if (sm > target)
            high--;
        else 
            low++;
    }
    return -1;
}

int s2(vector<int> nbs, int target) {
    int tp = 0;
    sort(nbs.begin(), nbs.end());
    for (int i = 0; i < nbs.size(); i++) {
        tp = twoPointer(nbs, target - nbs[i]);
        if (tp != -1)
            return nbs[i] * tp;
    }
    return -1;
}

auto main() -> int
{
    FILE *file;
    int nb;
    vector<int> v;
    file = fopen("../../2020/day01/input.txt", "r");
    while (fscanf(file, "%d", &nb) != EOF) {
        v.push_back(nb);
    }

    cout << s1(v, 2020) << endl; // 440979
    cout << s2(v, 2020) << endl; // 82498112
    return 0;
}
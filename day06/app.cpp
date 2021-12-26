#include <bits/stdc++.h>

using namespace std;

vector<int> parseline(string str, char sep) {
    string nb;
    vector<int> res;
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] != sep) {
            nb.push_back(str[i]);
        } else {
            if (nb.size() > 0) {
                res.push_back(atoi(nb.c_str()));
                nb = "";
            }
        }
    }
    res.push_back(atoi(nb.c_str()));
    return res;
}


int s1(vector<int> v, int days) {
    vector<int> rep;

    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] == 0) {
            rep.push_back(8);
            rep.push_back(6);
        } else {
            rep.push_back(v[i]-1);
        }
    }
    return days - 1 > 0 ? s1(rep, days-1) : rep.size();
}

uintmax_t s2(vector<int> v, int days) {
    unordered_map<int, uintmax_t > fishBand;
    int CYCLE = 8;
    uintmax_t cnt = 0;

    for (auto &f: v)
        fishBand[f]++;

    for (int day = 0; day < days; day++) {
        int newBorn = fishBand[0];

        for (int i = 0; i < CYCLE; i++) {
            fishBand[i] = fishBand[i+1];
        }

        fishBand[CYCLE] = newBorn;
        fishBand[CYCLE-2] += newBorn;

        /* debug */
        cout << "Day n" << day << " : " << endl;
        for (int i = 0; i <= CYCLE; i++) {
            cout << i << ": " << fishBand[i] << endl;
        }
        cout << endl;
        /* end debug */
    }

    for (int i = 0; i <= CYCLE; i++) {
        cout << i << ": " << fishBand[i] << endl;
        cnt += fishBand[i];
    }
    return cnt;
}

auto main() -> int {
    string str;
    vector<int> v;
    ifstream fstream;

    fstream.open("input.txt", ios::in);
    
    getline(fstream, str);
    v = parseline(str, ',');
    cout << "Solution 1: " << s1(v, 80) << endl;
    // cout << s1(v, 256) << endl; // overflow alloc size
    cout << "Solution 2: " << s2(v, 256) << endl; // Overflow :( had to use python .. 
}
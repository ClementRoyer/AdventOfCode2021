#include <bits/stdc++.h>

using namespace std;

int createLine(unordered_map<int, unordered_map<int, int>> &map, pair<int, int> from, pair<int, int> to) {

    int col = 0;
    int diffA = from.first > to.first ? -1 : from.first == to.first ? 0 : 1,
        diffB = from.second > to.second ? -1 : from.second == to.second ? 0 : 1;

    while (from.first != to.first + diffA|| from.second != to.second + diffB) {
        if (++map[from.first][from.second] == 2)
            col++;
        from.first += diffA;
        from.second += diffB;
    }

    return col;
}

/* ======================= */

void solution(FILE *file) {
    int ya,xa, yb,xb;
    unordered_map<int, unordered_map<int, int>> mapA, mapB; // {{x, y}, overlap}
    int s1 = 0, s2 = 0;

    while (fscanf(file, "%d,%d -> %d,%d", &ya, &xa, &yb, &xb) != EOF) {
        if (ya == yb || xa == xb)
            s1 += createLine(mapA, {xa, ya}, {xb, yb});
        s2 += createLine(mapB, {xa, ya}, {xb, yb});
    }
    
    cout << "Solution 1 : " << s1 << endl;
    cout << "Solution 2 : " << s2 << endl;
}


/* FLEX */
auto main() -> int {
    FILE *file;

    file = fopen("input.txt", "r");
    solution(file);
    return 0;
}
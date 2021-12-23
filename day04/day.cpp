class Board {
    private:
        unordered_map<int, vector<vector<int>>> m; // { n , [{posa, posb}, {posa, posb}] }
        vector<vector<bool>> board;
        vector<vector<int>> board_value;
    int id;
    
        vector<int> parseline(string str, char sep) {
            string nb;
            vector<int> res;
            for (int i = 0; i < str.size(); i++) {
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


        void create_board() {
            string str;
            vector<int> line;
            
            for (int i = 0; i < 5 && getline(cin, str); i++) {
                line = parseline(str, ' ');
                board.push_back({});
                board_value.push_back({});
                for (int z = 0; z < line.size(); z++) {
                    m[line[z]].push_back({z, i});
                    board.back().push_back(false);
                    board_value.back().push_back(line[z]);
                }
            }
        }
    
    bool check_line(int x) {
        int res = 0;
        for (int i = 0; i < board[0].size(); i++) {
            res += board[x][i];
        }
        return res == board.size();
    }
    
    bool check_column(int y) {
        int res = 0;
        for (int i = 0; i < board.size(); i++) {
            res += board[i][y];
        }
        return res == board.size();
    }
    
        bool check_win_at(vector<int> pos) {
            bool res;
            int y = pos[0], x = pos[1];

            res = check_column(y);
            res = res || check_line(x);
            return res;
        }
    
        int calculate_win() {
            int res = 0;
            for (int y = 0; y < board.size(); y++) {
                for (int x = 0; x < board[y].size(); x++)
                    if (!board[y][x])
                        res += board_value[y][x];
            }
            return res;
        }

    public:
        Board(int _id) {
            id = _id;
            create_board();
        }
    
        auto getId() -> int {
            return this->id;
        }
    
        int place(int nb) {
            bool res;
            if (m[nb].size() > 0)
                for (auto &pos: m[nb]) {
                    board[pos[1]][pos[0]] = true;
                    res = check_win_at(pos);
                    if (res)
                        return calculate_win() * nb;
                }
            return -1;
        }
};

vector<int> parseline(string str, char sep) {
    string nb;
    vector<int> res;
    for (int i = 0; i < str.size(); i++) {
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

vector<int> getInput() {
    string str, n;
    getline(cin, str);
    return parseline(str, ',');
}

int s1(vector<int> input, vector<Board*> boards) {
    int res;
    for (int i = 0; i < input.size(); i++) {
        for (auto &board : boards) {
            res = board->place(input[i]);
            if (res != -1)
                return res;
        }
    }
    return -1;
}

int s2(vector<int> input, vector<Board*> boards) {
    int res;
    unordered_map<int, Board*> winBoards;
    int nbWin = 0;

    for (int i = 0; i < input.size(); i++) {
        for (auto &board : boards) {
            if (!winBoards[board->getId()]) {
                res = board->place(input[i]);
                if (res != -1) {
                    winBoards[board->getId()] = board;
                    nbWin++;
                }
            }
            if (nbWin == boards.size()) {
                return res;
            }
        }
    }
    return -1;
}

void day4() {
    string str;
    vector<int> input;
    vector<Board*> boards;
    
    input = getInput();
    
    for (int id = 0; getline(cin, str); id++) {
        boards.push_back(new Board(id));
    }
    cout << "S1 :" << s1(input, boards) << endl;
    cout << "S2 :" << s2(input, boards) << endl;
}

int main() {
    day4();
    return 0;
}
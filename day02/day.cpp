class Day2 {
    public:
    int s1(vector<int> y, vector<int> x) {
        int cnty = accumulate(y.begin(), y.end(), 0);
        int cntx = accumulate(x.begin(), x.end(), 0);
        
        return cnty * cntx;
    }
    
    int main() {
        int y = 0, x = 0, aim = 0;
        int n;
        string str;
        
        while (cin >> str) {
            cin >> n;
            if (str == "forward") {
                x += n;
                y += aim * n;
            }
            else if (str == "down")
                aim += n;
            else if (str == "up")
                aim -= n;
        }
        
        cout << (y * x) << endl;

        return 0;
    }
};

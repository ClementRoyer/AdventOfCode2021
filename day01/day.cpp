class Day1 : public Day {
    public:
    int s1(vector<int> nums) {
        int cnt = 0;

        for (int i = 1; i < nums.size(); i++)
            cnt += nums[i-1] <= nums[i];

        return cnt;
    }

    int s2(vector<int> nums) {
        int cnt = 0;
        int ca, cb;

        ca += nums[0] + nums[1] + nums[2];
        cb = ca - nums[0];

        for (int i = 3; i < nums.size(); i++) {
            cb += nums[i];
            cnt += ca < cb;
            ca = cb;
            cb -= nums[i-2];
        }

        return cnt;
    }

    int main() {
        int n;
        vector<int> v;

        while (cin >> n)
            v.push_back(n);

        cout << "Res 1: " << s1(v) << endl;
        cout << "Res 2: " << s2(v) << endl;
        return 0;
    }
};
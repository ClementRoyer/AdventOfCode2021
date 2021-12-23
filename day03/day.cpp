class Day3 {
    private:
    int to_int(string bits) {
        int num = 0;
        for (char c : bits)
            num = (num << 1) | (c - '0');
        return num;
    }
    void _memset(string &str, int size) {
        while (size-- > 0)
            str.push_back(0);
    }
    
    char calculate_bit(vector<string> bits, int pos, bool oxy) {
        int bit = 0;
        for (int i = 0; i < bits.size(); i++) {
            bit += bits[i][pos] == '0' ? -1 : 1;
        }
        return oxy ? bit >= 0 ? '1' : '0'
                   : bit >= 0 ? '0' : '1';
    }
    
    string calculate(vector<string> bits, bool oxy) {
        vector<string> next;
        char bit;
        string str;
        
        _memset(str, bits[0].size());

        for (int i = 0; i < bits[0].size() && bits.size() > 1; i++) {
            bit = calculate_bit(bits, i, oxy);
            for (int z = 0; z < bits.size(); z++) {
                str = bits[z];
                if (str[i] == bit)
                    next.push_back(str);
            }
            bits = next;
            next = {};
        }
        return bits[0];
    }
    public:
    
    int s1(vector<string> bits) {
        
        string str, gamma, epsilon;
        
        for (int i = 0; i < bits[0].size(); i++)
            str.push_back(0);
        
        gamma = epsilon = str;

        for (int i = 0; i < bits.size(); i++) {
            str = bits[i];
            for (int i = 0; i < str.size(); i++) {
                gamma[i] += str[i] == '1' ?  1 : -1;
            }
            
        }

        for (int i = 0; i < gamma.size(); i++) {
            epsilon[i] = gamma[i] > 0 ? '0' : '1';
            gamma[i] = gamma[i] > 0 ? '1' : '0';
        }

        return to_int(gamma) * to_int(epsilon);
    }
    
    int s2(vector<string> bits) {
        
        string co2 = calculate(bits, false);
        string oxy = calculate(bits, true);

        return to_int(co2) * to_int(oxy);
    }
    
    int main() {
        string str;
        vector<string> bits;
        
        while (getline(cin, str))
            bits.push_back(str);
        
        cout << s2(bits) << endl;
        return 0;
    }
};
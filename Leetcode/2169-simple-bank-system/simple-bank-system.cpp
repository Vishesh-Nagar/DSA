class Bank {
public:
    vector<long long> accs;
    Bank(vector<long long>& balance) {
        accs.push_back(-1);
        for (long long i : balance)
            accs.push_back(i);
    }

    bool isValid(int a) {
        return a > 0 && a < accs.size();
    }

    bool transfer(int a1, int a2, long long m) {
        if (!isValid(a1) || !isValid(a2) || accs[a1] < m)
            return false;
        accs[a1] -= m;
        accs[a2] += m;
        return true;
    }

    bool deposit(int a, long long m) {
        if (!isValid(a))
            return false;
        accs[a] += m;
        return true;
    }

    bool withdraw(int a, long long m) {
        if (!isValid(a) || accs[a] < m)
            return false;
        accs[a] -= m;
        return true;
    }
};
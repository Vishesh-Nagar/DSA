#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    pair<int, int> p = {-1, -1};
    sort(a.begin(), a.end());

    if (a[0] > x) {
        p.second = a[0];
        return p;
    }

    if (a[n - 1] < x) {
        p.first = a[n - 1];
        return p;
    }

    int s = 0, e = n - 1;
    int mid;

    while (s <= e) {
        mid = s + (e - s) / 2;

        if (a[mid] == x) {
            p.first = p.second = x;
            return p;
        } else if (a[mid] < x) {
            p.first = a[mid];
            s = mid + 1;
        } else {
            p.second = a[mid];
            e = mid - 1;
        }
    }

    return p;
}
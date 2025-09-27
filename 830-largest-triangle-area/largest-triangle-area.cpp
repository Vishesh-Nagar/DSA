class Solution {
public:
    struct Point {
        double x, y;
        bool operator<(const Point& other) const {
            return x < other.x || (x == other.x && y < other.y);
        }
    };

    double cross(const Point& a, const Point& b, const Point& c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    double area(const Point& a, const Point& b, const Point& c) {
        return abs(cross(a, b, c)) / 2.0;
    }

    vector<Point> convexHull(vector<Point>& pts) {
        sort(pts.begin(), pts.end());
        int n = pts.size();
        vector<Point> hull;

        // lower hull
        for (int i = 0; i < n; i++) {
            while (hull.size() >= 2 &&
                   cross(hull[hull.size() - 2], hull.back(), pts[i]) <= 0)
                hull.pop_back();
            hull.push_back(pts[i]);
        }

        // upper hull
        int m = hull.size();
        for (int i = n - 2; i >= 0; i--) {
            while (hull.size() > m &&
                   cross(hull[hull.size() - 2], hull.back(), pts[i]) <= 0)
                hull.pop_back();
            hull.push_back(pts[i]);
        }

        hull.pop_back();
        return hull;
    }

    double largestTriangleArea(vector<vector<int>>& p) {
        vector<Point> pts;
        for (auto& v : p)
            pts.push_back({(double)v[0], (double)v[1]});

        vector<Point> hull = convexHull(pts);
        int h = hull.size();
        if (h < 3)
            return 0.0;

        double ans = 0.0;
        // Rotating calipers for max area triangle
        for (int i = 0; i < h; i++) {
            for (int j = i + 1; j < h; j++) {
                int k = (j + 1) % h;
                while (true) {
                    double curr = area(hull[i], hull[j], hull[k]);
                    double next = area(hull[i], hull[j], hull[(k + 1) % h]);
                    if (next > curr)
                        k = (k + 1) % h;
                    else
                        break;
                }
                ans = max(ans, area(hull[i], hull[j], hull[k]));
            }
        }
        return ans;
    }
};
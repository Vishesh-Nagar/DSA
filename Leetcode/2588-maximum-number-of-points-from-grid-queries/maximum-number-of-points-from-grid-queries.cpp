class Cell {
public:
    int row;
    int col;
    int value;
    Cell(int r, int c, int v) : row(r), col(c), value(v) {}
};

class Query {
public:
    int index;
    int value;
    Query(int i, int v) : index(i), value(v) {}
};

bool operator<(const Query& a, const Query& b) {
    return a.value < b.value;
}

bool operator<(const Cell& a, const Cell& b) {
    return a.value < b.value;
}

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int n) : parent(vector<int>(n, -1)), size(vector<int>(n, 1)) {}

    int find(int node) {
        if (parent[node] < 0)
            return node;

        return parent[node] = find(parent[node]);
    }

    bool union_nodes(int nodeA, int nodeB) {
        int rootA = find(nodeA);
        int rootB = find(nodeB);
        if (rootA == rootB)
            return false;

        if (size[rootA] > size[rootB]) {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        } else {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        return true;
    }

    int getSize(int node) {
        return size[find(node)];
    }
};

const vector<int> drow = {0, 0, 1, -1};
const vector<int> dcol = {1, -1, 0, 0};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();
        int totalCells = n * m;

        vector<Query> sortedQueries;
        for (int i = 0; i < queries.size(); i++)
            sortedQueries.push_back(Query(i, queries[i]));

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<Cell> sortedCells;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++)
                sortedCells.push_back(Cell(row, col, grid[row][col]));
        }

        sort(sortedCells.begin(), sortedCells.end());

        UnionFind uf = UnionFind(totalCells);
        vector<int> result(queries.size());
        int idx = 0;

        for (Query query : sortedQueries) {
            while (idx < totalCells && sortedCells[idx].value < query.value) {
                int row = sortedCells[idx].row;
                int col = sortedCells[idx].col;
                int cellId = row * m + col;

                for (int i = 0; i < 4; i++) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] < query.value)
                        uf.union_nodes(cellId, nrow * m + ncol);
                
                }
                idx++;
            }
            result[query.index] = query.value > grid[0][0] ? uf.getSize(0) : 0;
        }
        return result;
    }
};
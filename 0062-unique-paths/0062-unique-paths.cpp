class Solution {
public:
    int paths(int curR, int curC, int m, int n,  map<pair<int, int>, int>& path){
        if(curR == m-1 && curC == n-1){
            return 1;
        }
        if(curR >= m || curC >= n) return 0;

        if(path.count({curR, curC})){
            return path[{curR, curC}];
        }

        return path[{curR, curC}] = paths(curR+1, curC, m, n, path) + paths(curR, curC+1, m, n, path);
    }
    int uniquePaths(int m, int n) {
        int curR = 0;
        int curC = 0;
        map<pair<int, int>, int> path;

        return paths(curR, curC, m, n, path);

    }
};
class Solution {
public:
    int dist(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) +
               (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> d = {
            dist(p1, p2),
            dist(p1, p3),
            dist(p1, p4),
            dist(p2, p3),
            dist(p2, p4),
            dist(p3, p4)
        };

        sort(d.begin(), d.end());

        // A valid square must have 4 equal smaller sides and 2 equal larger diagonals.
        return d[0] > 0 && 
               d[0] == d[1] && 
               d[1] == d[2] && 
               d[2] == d[3] && 
               d[4] == d[5] && 
               2 * d[0] == d[4];
    }
};

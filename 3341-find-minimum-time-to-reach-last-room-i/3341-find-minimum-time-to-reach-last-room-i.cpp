// class State {
// public:
//     int x;
//     int y;
//     int dis;
//     State(int x, int y, int dis) : x(x), y(y), dis(dis) {}
// };

// class Solution {
// public:
//     int minTimeToReach(vector<vector<int>>& moveTime) {
//         int inf = 0x3f3f3f3f;
//         int n = moveTime.size(), m = moveTime[0].size();
//         vector<vector<int>> d(n, vector<int>(m, inf));
//         vector<vector<int>> v(n, vector<int>(m, 0));

//         int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//         d[0][0] = 0;

//         auto cmp = [](const State& a, const State& b) { return a.dis > b.dis; };

//         priority_queue<State, vector<State>, decltype(cmp)> q(cmp);
//         q.push(State(0, 0, 0));

//         while (!q.empty()) {
//             State s = q.top();
//             q.pop();
//             if (v[s.x][s.y]) continue;
//             v[s.x][s.y] = 1;

//             for (int i = 0; i < 4; i++) {
//                 int nx = s.x + dirs[i][0];
//                 int ny = s.y + dirs[i][1];
//                 if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

//                 int dist = max(d[s.x][s.y], moveTime[nx][ny]) + 1;
//                 if (d[nx][ny] > dist) {
//                     d[nx][ny] = dist;
//                     q.push(State(nx, ny, dist));
//                 }
//             }
//         }

//         return d[n - 1][m - 1];
//     }
// };
// Define a class to represent a state in the grid
class State {
public:
    int x;      // row index
    int y;      // column index
    int dis;    // time (distance) taken to reach this state

    State(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int inf = 0x3f3f3f3f;  // A large number representing "infinity"
        int n = moveTime.size();       // Number of rows
        int m = moveTime[0].size();    // Number of columns

        // d[i][j] will hold the minimum time to reach cell (i, j)
        vector<vector<int>> d(n, vector<int>(m, inf));

        // v[i][j] is used to mark whether cell (i, j) has been visited
        vector<vector<int>> v(n, vector<int>(m, 0));

        // Direction vectors: down, up, right, left
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Starting point: time to reach (0, 0) is 0
        d[0][0] = 0;

        // Min-heap priority queue based on `dis` (time)
        auto cmp = [](const State& a, const State& b) {
            return a.dis > b.dis;  // smaller time gets higher priority
        };

        priority_queue<State, vector<State>, decltype(cmp)> q(cmp);
        q.push(State(0, 0, 0));  // Start from top-left corner

        while (!q.empty()) {
            State s = q.top();  // Get the current state with the smallest time
            q.pop();

            if (v[s.x][s.y]) continue;  // Skip if already visited
            v[s.x][s.y] = 1;            // Mark as visited

            // Try all four directions
            for (int i = 0; i < 4; i++) {
                int nx = s.x + dirs[i][0];
                int ny = s.y + dirs[i][1];

                // Skip out-of-bounds coordinates
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                // You must wait until moveTime[nx][ny], if you arrive earlier
                // So, new time to reach (nx, ny) is:
                // max(current_time, moveTime[nx][ny]) + 1 for the move itself
                int dist = max(d[s.x][s.y], moveTime[nx][ny]) + 1;

                // If this path offers a shorter time to (nx, ny), update it
                if (d[nx][ny] > dist) {
                    d[nx][ny] = dist;
                    q.push(State(nx, ny, dist));  // Add new state to queue
                }
            }
        }

        // Final answer: minimum time to reach bottom-right corner
        return d[n - 1][m - 1];
    }
};

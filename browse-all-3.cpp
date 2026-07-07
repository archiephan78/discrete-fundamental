/*
 * Problem: Traveling Salesman Problem (TSP) - Brute Force / Backtracking
 *
 * A traveler wants to visit n cities numbered from 1 to n.
 * Starting at city 1, the traveler must visit every other city
 * exactly once, then return to the starting city (city 1).
 *
 * The cost of traveling from city i to city j (1 <= i, j <= n)
 * is given as c[i][j].
 *
 * Task: Using a brute-force (backtracking) algorithm, find a tour
 * for the traveler such that the total travel cost is minimized.
 *
 * Input:
 * - The first line contains a positive integer n (n <= 30), the
 *   number of cities.
 * - Each of the next n lines contains n positive integers c[i][j]
 *   (1 <= j <= n), where each value <= 10^6 and c[i][i] = 0.
 *
 * Output:
 * - If there is exactly one optimal solution:
 *   + The first line prints the minimum total cost (f*).
 *   + The second line prints n integers representing the order
 *     of cities visited in the optimal tour found.
 * - If there is more than one optimal solution:
 *   + The first line prints two values: the minimum total cost (f*)
 *     and the number of optimal tours, separated by a space.
 *   + Each of the following lines prints one optimal tour.
 *
 * Approach:
 * - Fix the starting city as city 1 (index 0), since the tour is
 *   a cycle, so the starting point doesn't affect the total cost.
 * - Use recursive backtracking to try each unvisited city as the
 *   next city in the path.
 * - Keep track of the best (minimum) cost found so far. If the
 *   partial cost already exceeds the current best, prune that
 *   branch immediately (branch-and-bound pruning) to reduce
 *   unnecessary exploration.
 * - When all n cities have been visited, add the cost of returning
 *   to the starting city to get the total tour cost:
 *   + If this total is strictly less than the current best, update
 *     the best cost and reset the list of optimal solutions.
 *   + If this total equals the current best, add this tour as
 *     another optimal solution.
 */
 #include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<long long>> c;
vector<int> path_;
vector<bool> visited_;
long long best;
vector<vector<int>> solutions;

void backtrack(long long cost) {
    int pos = (int)path_.size();
    if (pos == n) {
        long long total = cost + c[path_.back()][path_[0]];
        if (total < best) {
            best = total;
            solutions.clear();
            solutions.push_back(path_);
        } else if (total == best) {
            solutions.push_back(path_);
        }
        return;
    }

    for (int city = 1; city < n; city++) {
        if (!visited_[city]) {
            long long newCost = cost + c[path_.back()][city];
            if (newCost > best) continue;
            visited_[city] = true;
            path_.push_back(city);
            backtrack(newCost);
            path_.pop_back();
            visited_[city] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    c.assign(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];

    best = LLONG_MAX;
    visited_.assign(n, false);
    visited_[0] = true;
    path_.push_back(0);

    backtrack(0);

    if (solutions.size() == 1) {
        cout << best << "\n";
        for (int i = 0; i < n; i++) {
            cout << solutions[0][i] + 1 << (i + 1 < n ? ' ' : '\n');
        }
    } else {
        cout << best << " " << solutions.size() << "\n";
        for (auto &sol : solutions) {
            for (int i = 0; i < n; i++) {
                cout << sol[i] + 1 << (i + 1 < n ? ' ' : '\n');
            }
        }
    }

    return 0;
}
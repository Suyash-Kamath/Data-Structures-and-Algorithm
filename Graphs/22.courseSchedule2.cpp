#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (order.size() == numCourses) {
            return order;
        } else {
            return {}; 
        }
    }
};

int main() {
    int numCourses, numPrerequisites;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    cout << "Enter the number of prerequisite pairs: ";
    cin >> numPrerequisites;

    vector<vector<int>> prerequisites(numPrerequisites, vector<int>(2));
    cout << "Enter the prerequisite pairs (course, prerequisite):" << endl;
    for (int i = 0; i < numPrerequisites; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    Solution solution;
    vector<int> result = solution.findOrder(numCourses, prerequisites);

    if (result.empty()) {
        cout << "No valid order to finish all courses." << endl;
    } else {
        cout << "Valid course order: ";
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}

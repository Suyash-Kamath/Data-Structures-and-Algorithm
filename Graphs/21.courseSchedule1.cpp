#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return count == numCourses;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    int numPrerequisites;
    cout << "Enter the number of prerequisite pairs: ";
    cin >> numPrerequisites;

    vector<vector<int>> prerequisites(numPrerequisites, vector<int>(2));
    cout << "Enter the prerequisite pairs (course, prerequisite):" << endl;
    for (int i = 0; i < numPrerequisites; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    if (canFinish(numCourses, prerequisites)) {
        cout << "Yes, all courses can be finished." << endl;
    } else {
        cout << "No, it's not possible to finish all courses." << endl;
    }

    return 0;
}

#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <sstream>
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
#define pi M_PI
#define pb push_back
#define loop(i,n) for(long long i=0; i<n;i++)
#define in insert
using namespace std;

// Global
unordered_map<string, set<string>> frags;
unordered_map<string, string> parentMap;

// Checks if the current station connects to the end
bool IsConnection(string station, string end) {
    for (string s: frags[station])
        if (s == end)
            return true;
    return false;
}

// Traces back from the end node to each parent and reverses it
vector<string> ReconstructPath(string end) {
    vector<string> path;
    string station = end;

    while (station != "") {
        path.pb(station);
        station = parentMap[station];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int N;
    cin >> N;

    // Gets rid of lingering \n
    cin.ignore(256, '\n');

    // Input into unordered map
    for (int i=0; i < N; i++) {
        string line, name, temp;
        set<string> st;
        getline(cin, line);
        stringstream ss(line);
        ss >> name;
        while (ss >> temp)
            st.insert(temp);
        frags[name] = st;
        ss.clear();
        st.clear();
    }
    string start, end;
    cin >> start >> end;

    // Fix Missing Nodes (Unidirectional)
    for (const auto& pair : frags) {
        for (string s: pair.second) {
            if (frags.find(s) == frags.end() || frags[s].find(pair.first) == frags[s].end()) {
                frags[s].insert(pair.first);
            }
        }
    }

    // BFS
    queue<string> q;
    q.push(start);
    parentMap[start] = "";
    string station = start;
    bool foundConnection = false;
    while (!q.empty()) {
        station = q.front();
        q.pop();

        // Break Condiiton
        if (IsConnection(station, end)) {
            foundConnection = true;
            parentMap[end] = station;
            break;
        }

        for (string s: frags[station]) {
            if (parentMap.find(s) == parentMap.end()) { // If not visited
                q.push(s);
                parentMap[s] = station;
            }
        }
    }

    if (foundConnection) {
        for (string s: ReconstructPath(end))
            cout << s << " ";
    }
    else
        cout << "no route found" << endl;

    return 0;
}
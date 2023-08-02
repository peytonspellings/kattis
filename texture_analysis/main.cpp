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

string Solve(string line) {
    string pattern = line.substr(0, line.find('*',1));

    vector<string> tokens;
    string s = line;
    string tok;
    while (s.size() >= pattern.size()) {
        tok = s.substr(0,pattern.size());
        tokens.pb(tok);
        s = s.substr(pattern.size(),s.size());
    }

    if (!(s == "*" || s == ""))
        return "NOT EVEN";

    for (string tok: tokens) {
        if (pattern != tok)
            return "NOT EVEN";
    }
    
    return "EVEN";
}

int main() {
    string line;
    ll i=1;
    while (getline(cin,line)) {
        if (line == "END")
            break;
        cout << i << " " << Solve(line) << endl;
        i++;
    }
    return 0;
}

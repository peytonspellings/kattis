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

vector<int> flipped = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};

ll flip(ll x) {
    // Convert to String
    stringstream ss;
    ss << x;
    string str = ss.str();
    string flipped_str = "";
    
    // Iterate through each char
    for (ll i=0; i < str.size(); i++) {
        int digit = str.at(i) - '0';
        if (flipped.at(digit) == -1)
            return -1;
            
        // Prepend the string in reverse order
        string pre = "";
        pre += flipped.at(digit) + '0';
        flipped_str.insert(0, pre);
    }
    
    return stoll(flipped_str, nullptr, 10);
}

int main()
{
    vector<ll> cards;
    vector<ll> flips;

    // Input
    int n, s;
    cin >> n >> s;
    loop (i, n) {
        int tmp;
        cin >> tmp;
        cards.pb(tmp);
    }
    
    // Loops over every card combination (but fast)
    unordered_set<ll> uset;
    unordered_set<ll> flip_set;
    for (ll i=0; i < n; i++) {

        // Generating Flips as we go
        flips.pb(flip(cards.at(i)));

        // Input Reg
        ll diff = s - cards.at(i);
        auto it = uset.find(diff);
        auto fit = flip_set.find(diff);
        
        if (it != uset.end() || fit != flip_set.end()) {
            cout << "YES";
            return 0;
        }
        uset.insert(cards.at(i));


        // Input Flip
        if (flips.at(i) == -1)
            continue;

        diff = s - flips.at(i);
        if (diff < 1)
            continue;

        it = uset.find(diff);
        fit = flip_set.find(diff);
        if (diff != cards.at(i) && it != uset.end() || fit != flip_set.end()) {
            cout << "YES";
            return 0;
        }
        flip_set.insert(flips.at(i));
    }

    cout << "NO";

    return 0;
}

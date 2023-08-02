#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findLow(vector<char> v) {
    for (int i=0; i < v.size(); i++) {
        if (v.at(i) == 'O')
            return i;
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    
    vector<char> v;
    char c;
    for (int i=0; i < N; i++) {
        cin >> c;
        v.push_back(c);
    }
    reverse(v.begin(), v.end());
    
    int count = 0;
    int odex = findLow(v);
    
    while (odex != -1) {
        v[odex] = 'Z';
        
        // Turns Zebras into Ocelots that are under
        for (int i=0; i < odex; i++) {
            if (v.at(i) == 'Z')
                v[i] = 'O';
        }
        
        count++;
        odex = findLow(v);
    }
    
    cout << count;
    return 0;
}

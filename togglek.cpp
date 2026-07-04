#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void solve(int testcase) {
    int R, C, K;
    cin >> R >> C >> K;
    
    map<string, int> rowFreq;
    
    // Read the matrix and build row patterns
    for (int i = 0; i < R; i++) {
        string current_row = "";
        for (int j = 0; j < C; j++) {
            int val;
            cin >> val;
            current_row += to_string(val);
        }
        // Increment the frequency of this specific row pattern
        rowFreq[current_row]++;
    }
    
    int max_rows_with_ones = 0;
    
    // Iterate through our map of unique row patterns
    for (auto const& [row_pattern, frequency] : rowFreq) {
        int zero_count = 0;
        for (char ch : row_pattern) {
            if (ch == '0') {
                zero_count++;
            }
        }
        
        // Check if this pattern can be turned into all 1s
        if (zero_count <= K && (K - zero_count) % 2 == 0) {
            max_rows_with_ones = max(max_rows_with_ones, frequency);
        }
    }
    
    cout << "#" << testcase << " " << max_rows_with_ones << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; i++) {
            solve(i);
        }
    }
    return 0;
}
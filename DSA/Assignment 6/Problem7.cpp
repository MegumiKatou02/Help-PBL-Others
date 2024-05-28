#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minStep(const vector<long long>& A) {
    unordered_map<int, int> count;
    for (int x : A) {
        count[x]++;
    }
    
    int steps = 0;
    for (const auto& pair : count) {
        int value = pair.first;
        int frequency = pair.second;
        
        if (frequency < value) {
            steps += frequency;
        } else {
            steps += frequency - value;
        }
    }
    
    return steps;
}

int main() {
    vector<long long> a;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }

    cout << minStep(a);

    return 0;
}
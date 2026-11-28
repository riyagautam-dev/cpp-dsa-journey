
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int totalFruit(vector<int>& fruits) {
    int left = 0;
    int maxFruits = 0;
    unordered_map<int, int> freq;

    for (int right = 0; right < fruits.size(); right++) {
        freq[fruits[right]]++;

        while (freq.size() > 2) {
            freq[fruits[left]]--;

            if (freq[fruits[left]] == 0) {
                freq.erase(fruits[left]);
            }

            left++;
        }

        maxFruits = max(maxFruits, right - left + 1);
    }

    return maxFruits;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> fruits(n);

    cout << "Enter fruits: ";
    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }

    cout << "Maximum fruits: " << totalFruit(fruits) << endl;

    return 0;
}

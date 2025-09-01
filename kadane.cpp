#include <iostream>
#include <vector>
#include <climits>

using namespace std;

pair<int, pair<int, int>> maxSubArraySum(const vector<int>& arr) {
    int n = arr.size();

    // Initialize variables for Kadane's algorithm
    int maxSum = INT_MIN;  // This will store the maximum sum found
    int currentSum = 0;    // This will store the current subarray sum
    int start = 0, end = 0, tempStart = 0; // Variables to track the subarray indices

    for (int i = 0; i < n; ++i) {
        currentSum += arr[i]; // Add current element to the current sum

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }

        if (currentSum < 0) {//currentsum<=0 dile eijaigai shortest subarray pawa jabe
            currentSum = 0;
            tempStart = i + 1; // Start a new subarray after the current element
        }
    }

    // Return the maximum sum and the indices of the subarray
    return {maxSum, {start, end}};
}

int main() {
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    auto result = maxSubArraySum(arr);
    int maxSum = result.first;
    int start = result.second.first;
    int end = result.second.second;

    cout << "Maximum Subarray Sum: " << maxSum << endl;
    cout << "Subarray indices: [" << start << ", " << end << "]" << endl;
    cout << "Subarray: ";
    for (int i = start; i <= end; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


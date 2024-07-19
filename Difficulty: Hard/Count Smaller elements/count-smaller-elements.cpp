//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, vector<int>& indices, vector<int>& count, int left, int mid, int right) {
        int n = right - left + 1;
        vector<int> newIndices(n);
        int i = left, j = mid + 1, k = 0, rightCounter = 0;

        while (i <= mid && j <= right) {
            if (arr[indices[i]] <= arr[indices[j]]) {
                newIndices[k] = indices[i];
                count[indices[i]] += rightCounter;
                i++;
            } else {
                newIndices[k] = indices[j];
                rightCounter++;
                j++;
            }
            k++;
        }

        while (i <= mid) {
            newIndices[k] = indices[i];
            count[indices[i]] += rightCounter;
            i++;
            k++;
        }

        while (j <= right) {
            newIndices[k] = indices[j];
            j++;
            k++;
        }

        for (int p = 0; p < n; p++) {
            indices[left + p] = newIndices[p];
        }
    }

    void mergeSort(vector<int>& arr, vector<int>& indices, vector<int>& count, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, indices, count, left, mid);
            mergeSort(arr, indices, count, mid + 1, right);
            merge(arr, indices, count, left, mid, right);
        }
    }

    vector<int> constructLowerArray(vector<int> &arr) {
        int n = arr.size();
        vector<int> indices(n), count(n, 0);

        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        mergeSort(arr, indices, count, 0, n - 1);

        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
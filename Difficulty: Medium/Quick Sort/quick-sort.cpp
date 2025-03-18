//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        printf("%d ", num);
    printf("\n");
}


// } Driver Code Ends

class Solution {
  public:
    void quickSort(vector<int>& arr, int start, int end) {
     if(start>=end)return;
     int pivot=partition(arr,start,end);
     quickSort(arr,start,pivot-1);
     quickSort(arr,pivot+1,end);
    }

  public:
    int partition(vector<int>& arr, int start, int end) {
        int pos=start;
        for(int i=start;i<=end;i++){
            if(arr[i]<=arr[end]){
                swap(arr[i],arr[pos]);
                pos++;
            }
        }
        return pos-1;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    scanf("%d", &T);
    getchar(); // to consume newline after T

    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.quickSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    return 0;
}

// } Driver Code Ends
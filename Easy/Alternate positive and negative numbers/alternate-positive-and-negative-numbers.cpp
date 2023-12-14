//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> pos,neg;   //to store positive and negative elements separately.
	    //separating positive and negative elements
        for(int i=0; i<n; i++){
            if(arr[i]>=0)
                pos.push_back(arr[i]);
            else
                neg.push_back(arr[i]); 
        }
        int i=0,j=0,k=0;
        while(pos.size()>i && neg.size()>j){
            arr[k++]=pos[i++];
            arr[k++]=neg[j++];
        }
        //f there are any remaining elements in either pos or neg,
        //the code fills them at the end of the array.
        while(pos.size()>i){
           arr[k++]=pos[i++];
        }
        while(neg.size()>j){
            arr[k++]=neg[j++];
        }
	}
	//tc:-O(n)
	//sc:-O(n)//vector pos and neg taking n/2 size each.
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
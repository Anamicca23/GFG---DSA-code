//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        vector<int>temp;//to store rotated element
        //taking module to handle cases where d >n.
        d%=n;
        for(int i=0; i<n; i++){
            temp.push_back(arr[(i+d)%n]);
        }
        for(int i=0;i<n;i++){
            arr[i]=temp[i];
        }
        //time complexity:O(n),
        //space complexity:O(n) //use of addition temp-vector.
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
// } Driver Code Ends


//----------------------------------------------------------------------------------------------------
//2.Approach


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    //Function to reverse an array. 
    void reverse(int arr[],int d,int n){
        while(d<n){
            swap(arr[d++],arr[n--]); //two pointer
        }
    }
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        if(d>n)
        d%=n;  //to handle case when d>n.
        reverse(arr,0,d-1); //reverse first d element
        reverse(arr,d,n-1); //reverse remaining element
        reverse(arr,0,n-1); //reverse entire array
    }
    //time complexity:O(n).
    //space complexity:O(1).
};

//{ Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
// } Driver Code Ends

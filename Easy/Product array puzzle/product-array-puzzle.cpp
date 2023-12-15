//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        int countz=0;  //to count zeroes in array
        long long int prodarray=1; //store the product of all non-zero elements.
        //if element is not zero then it multiplies else increase count of zeroes.
        for(auto i:nums){
            (i!=0)?prodarray*=i:countz++;  
        }
        //if multiple zeroes exist fill array with zero.
        if (countz > 1) fill(nums.begin(), nums.end(), 0);
        //If countz !=0 & the current element = 0, set it to prodarray
        //else divide prodarray by current element by using transform stl function.
        else transform(nums.begin(), nums.end(), nums.begin(), [&](int x) { 
              return countz ? (x == 0 ? prodarray : 0) : prodarray / x; 
       });
       //return modified array
      return nums;
    }
    //Time Complexity: O(N)
    //Space Complexity: O(1)
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
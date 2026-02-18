class Solution {
  public:
    virtual int merge(int s, int e, int m, vector<int> &arr){
      
      int ln=m-s+1, rn=e-m;
      vector<int> left(ln);
      vector<int> right(rn);
      
      int k=s;
      while(k<=m){
        left[k-s]=arr[k]; k++;  
      }
      
      k=m+1;
      while(k<=e){
        right[k-m-1]=arr[k]; k++;  
      }
      
      k=s;
      int ans=0;
      int l=0, r=0;
      
      while(l<ln && r<rn){
        if(left[l] <= right[r]){
          arr[k++] = left[l++];    
        }else{
          arr[k++] = right[r++];
          ans += (ln-l);
        }  
      }
      
      while(l<ln){
        arr[k++] = left[l++];  
      }
      
      while(r<rn){
        arr[k++] = right[r++];  
      }
      
      return ans;      
    }
    
    
    virtual int mergeSort(int s, int e, vector<int> &arr){
      if(s>=e) return 0;
      int ans=0;
      int m=s+(e-s)/2;
      
      ans += mergeSort(s, m, arr);
      ans += mergeSort(m+1, e, arr);
      ans += merge(s, e, m, arr);
      
      return ans;
    }
    
    virtual int inversionCount(vector<int> &arr) {
      int n=arr.size();
      return mergeSort(0, n-1, arr);
    }
};
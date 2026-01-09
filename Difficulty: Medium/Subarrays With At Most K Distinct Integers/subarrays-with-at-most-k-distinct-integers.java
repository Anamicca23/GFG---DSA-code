class Solution {
    public int countAtMostK(int arr[], int k) {
        // code here
        return atmostSolution(arr,k);
    }
    public int atmostSolution(int []arr,int k)
    {
        HashMap<Integer,Integer>freq= new HashMap<>();
        int l=0;
        int r=0;
        int ans=0;
        int n=arr.length;
        while(r<n)
        {
            freq.put(arr[r],freq.getOrDefault(arr[r],0)+1);
            while(freq.size()>k)
            {
               freq.put(arr[l],freq.getOrDefault(arr[l],0)-1);
               if(freq.get(arr[l])==0)
               freq.remove(arr[l]);
               l++;
               
            }
            ans+=r-l+1;
            r++;
        }
        
        return ans;
    }
}


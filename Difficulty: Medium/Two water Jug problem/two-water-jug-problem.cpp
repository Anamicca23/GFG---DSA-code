class Solution {
  public:
    
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    
    int pour(int fromCap, int toCap, int d) {
        int from = fromCap;
        int to = 0;
        int steps = 1;
        
        while (from != d && to != d) {
            
            int transfer = min(from, toCap - to);
            to += transfer;
            from -= transfer;
            steps++;
            
            if (from == d || to == d)
                break;
            
            if (from == 0) {
                from = fromCap;
                steps++;
            }
            
            if (to == toCap) {
                to = 0;
                steps++;
            }
        }
        
        return steps;
    }
    
    int minSteps(int m, int n, int d) {
        
        if (d > max(m, n))
            return -1;
        
        if (d % gcd(m, n) != 0)
            return -1;
        
        return min(pour(m, n, d), pour(n, m, d));
    }
};
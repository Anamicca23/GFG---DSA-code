class Solution {
  public:
    string profession(int level, int pos) {
        int flip = 0;
        while(pos>1)
        {
            if(pos%2==0)
            flip = 1 - flip;
            pos = (pos+1)/2;
        }
        if(flip ==0)
        return "Engineer";
        else
        return "Doctor";
    }
};

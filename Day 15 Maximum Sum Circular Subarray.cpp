class Solution {
public:
    
    int maxsubarray(vector <int>& A)
    {
        int csum=A[0];
        int gsum=A[0];
        for(int i=1;i<A.size();i++)
        {
            csum=max(A[i],A[i]+csum);
            if(csum>gsum)
                gsum=csum;
        }
        return gsum;
    }
        
     int maxSubarraySumCircular(vector<int>& A){
         //case 1 all negative numbers
         int flag=1;
         int maxnegele=INT_MIN;
         for(int i=0;i<A.size();i++)
         {
             if(A[i]>maxnegele)
                 maxnegele=A[i];
             if(A[i]>=0)
                 flag=0;
         }
         if(flag)
             return maxnegele;
         //case 2 kadanes algo
         int csum=A[0];
        int gsum=A[0];
        for(int i=1;i<A.size();i++)
        {
            csum=max(A[i],A[i]+csum);
            if(csum>gsum)
                gsum=csum;
        }
         //case 3 total-min
         int maxsum=0;
         for(int i=0;i<A.size();i++)
         {
             maxsum+=A[i];
             A[i]=-1*A[i];
         }
         int x=maxsubarray(A); 
         x=x*-1;
         return max(gsum,(maxsum-x));
     }
    
    
    
    
};

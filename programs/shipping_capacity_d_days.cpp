class Solution {
  public:
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int t_c,t_d ,mid,l=0 , r = 0 ;
        for(int i = 0 ; i < n ; i++){
            if (arr[i] > l) l = arr[i];
            r += arr[i];
        }
        while(1){
            if (l == r) break;
            mid = (l+r)/2 ;
            t_c = mid ;
            t_d = 1 ;
            for (int i = 0 ; i< n ; i++){
                if (arr[i] <= t_c) t_c -= arr[i];
                else {t_c = mid ; t_d++; i--;}
            }
            if (t_d > d) l = mid+1;
            if (t_d <= d) r = mid ;
        }
        return l;
    }
};
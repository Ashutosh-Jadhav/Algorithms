class Solution {
  public:
    void merge(vector<int>& arr, int l , int mid , int r) {
        // array is sorted from l to mid and mid +1 to r
        int l1,l2,k,n = mid-l+1,m = r-mid;          // sizes of 2 vectors to merge
        vector<int> l_s(n,0); vector<int> r_s(m,0);
        for (int i = 0 ; i < n ; i++) {
            l_s[i] = arr[l+i];
        }
        for (int i = 0 ; i < m ; i++) {
            r_s[i] = arr[mid+1+i];
        }
        l1 = 0 ; l2 = 0 ; k = l ;
        while (l1 < n && l2 < m ) {
            if (l_s[l1] > r_s[l2]) arr[k++] = r_s[l2++];
            else arr[k++] = l_s[l1++];
        }
        while (l1 < n ) {
            arr[k++] = l_s[l1++];
        }
        while (l2 < m ) {
            arr[k++] = r_s[l2++];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        int mid;
        if (l >= r) return;
        mid = l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};
class Solution {
  public:
    void merge(int l, int mid , int r, vector<pair<int,int>>& idx, vector<int>& counts){
        int n,m,l1,l2,k ; n = mid-l+1; m = r-mid;
        vector<pair<int,int>> r_s; vector<pair<int,int>> l_s;
        for (int i = 0 ; i < n ; i++) {
            l_s.push_back(idx[l+i]);
        }
        for (int i = 0 ; i < m ; i++) {
            r_s.push_back(idx[mid+1+i]);
        }
        k = l ; l1 = 0  ; l2 = 0 ;
        while (l1 < n && l2 < m && k <= r ) {
            if (r_s[l2].first > l_s[l1].first) {
                counts[l_s[l1].second] += m-l2;
                idx[k++] = l_s[l1++];
            }
            else idx[k++] = r_s[l2++];
        }
        while (l1 < n && k <= r) {
            idx[k++] = l_s[l1++];
        }
        while (l2 < m && k <= r) {
            idx[k++] = r_s[l2++];
        }
    }
  
    void mergeSort(int l , int r ,vector<pair<int,int>>& idx, vector<int>& counts) {
        int mid;
        if (l >= r) return;
        mid = l+(r-l)/2;
        mergeSort(l,mid,idx,counts);
        mergeSort(mid+1,r,idx,counts);
        merge(l,mid,r,idx,counts);
    }

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        // write your code here
        vector<pair<int,int>> idx; vector<int> counts(n,0); vector<int> ans(queries,0);
        for (int i = 0 ; i < n ; i++) {
            idx.push_back({arr[i],i});
        }
        mergeSort(0,n-1,idx,counts);
        for (int i = 0 ; i < queries ; i++) {
            ans[i] = counts[indices[i]];
        }
        return ans;
    }
};
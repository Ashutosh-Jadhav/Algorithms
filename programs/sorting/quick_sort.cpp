class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if (low >= high) return;
        int l;
        l = partition(arr,low,high);
        quickSort(arr,low,l-1);
        quickSort(arr,l+1,high);
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int r,p,temp; r = low;
        p = high;
        for (int k=0 ; k < high-low ; k++) {
            if (arr[low+k] < arr[p]) {
                temp = arr[r]; arr[r] = arr[low+k]; arr[low+k] = temp;
                r++;
            }
        }
        temp = arr[p]; arr[p] = arr[r]; arr[r] = temp;
        return r;
        // code here
    }
};
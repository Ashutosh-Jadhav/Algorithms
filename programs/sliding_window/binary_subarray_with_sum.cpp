// BruteForce                              TLE

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(),sum = 0,c=0;
        for (int k = 1 ; k <= n ; k++){
            for (int i = 0 ; i <= n-k ; i++) {
                sum = 0;
                for (int j = i ; j < i+k ; j++) {
                    sum += nums[j];
                }
                if (sum == goal) c++;
            }
        }
        return c;
    }
};


// using hashing

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(),sum = 0,c=0;
        vector<int>prefix(n,0);
        unordered_map<int,int> um;
        um.insert({0,1});
        for (int i = 0 ; i < n ; i++) {
            sum = sum + nums[i];
            prefix[i] = sum;
            if (um.find(-goal+prefix[i]) != um.end()) {
                c += um[-goal+prefix[i]];
            }
            if (um.find(prefix[i]) == um.end()) um.insert({prefix[i],1});
            else um[prefix[i]]++;
        }
        return c;
    }
};


// using 2 pointer

class Solution {
public:
    int at_most(vector<int>& nums , int goal) {
        if (goal < 0) return 0;
        int c,curr_sum,l; c= 0 ; curr_sum = 0; l = 0;
        for (int r = 0 ; r < nums.size() ; r++) {
            curr_sum = curr_sum + nums[r];
            while (curr_sum > goal) {
                curr_sum -= nums[l];
                l++;
            }
            c += r-l+1;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(),c=0;
        c = at_most(nums,goal) - at_most(nums,goal-1);
        return c;
    }
};
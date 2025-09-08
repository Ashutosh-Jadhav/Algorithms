// using hashing

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n,t; n = nums.size();
        set<vector<int>> ans;
        unordered_map<int,int>um;
        for (int i =0  ; i < n ; i++) {
            um[nums[i]] = i;
            // um.insert({nums[i],i});
        }
        for (int i = 0 ; i < n ; i++) {
            t = (-1)*nums[i];
            for (int j = i+1 ; j < n ; j++) {
                auto m = um.find(t - nums[j]);
                if (m != um.end() && m->second != j && j!=i && m->second != i && m->second > j) {
                    vector<int> tri = {nums[i],nums[j],nums[m->second]};
                    sort(tri.begin(),tri.end());
                    ans.insert(tri);
                }
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
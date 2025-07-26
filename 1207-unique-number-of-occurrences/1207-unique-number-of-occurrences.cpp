class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>map;
        unordered_set<int>ans;
        for(auto & it : arr){
            map[it]++;
        }
        for(auto &[_,f] :map){
            if(ans.count(f)) return false;
            ans.insert(f);
        }
        return true;
    }
};
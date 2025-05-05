class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        //easy questions hai so we can used tge hash table and c
       map<pair<int,int>,int>mp;
       for(auto &d : dominoes){
        if(d[0]>d[1]){
            swap(d[0],d[1]);
        }
        mp[{d[0],d[1]}]++;
       }
        int ans=0;
        for(auto &it :mp){
            int fre=it.second;
            ans+=(fre* (fre-1))/2;
        }
        return ans;
    }
};
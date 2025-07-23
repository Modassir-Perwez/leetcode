// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         //palindrome may be a odd or even can
//         // s="aacecaaa"
//         int n=s.size();
//        string rev=s;
//        reverse(rev.begin(),rev.end());
//        for(int i=0; i<s.size(); i++){
//         if(s.substr(0,n-i)== string (rev.begin()+i,rev.end())){
//             return rev.substr(0,i)+s;
//         }
//        }
//        return s;
//     }
// };
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        // Combine to use KMP prefix function
        string combined = s + "#" + rev;
        vector<int> lps(combined.size(), 0);

        for (int i = 1; i < combined.size(); i++) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            if (combined[i] == combined[len]) {
                len++;
            }
            lps[i] = len;
        }

        int longestPalindromePrefix = lps.back();
        return rev.substr(0, s.size() - longestPalindromePrefix) + s;
    }
};

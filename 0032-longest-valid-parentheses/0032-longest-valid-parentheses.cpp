class Solution {
public:
    int longestValidParentheses(string s) {
                     stack<int>st;
                     st.push(-1);
                    // int ans=INT_MIN;
                    int cnt=0;
                  for(int i=0; i<s.size(); i++){
                      if(s[i]=='('){
                        st.push(i);
                        // cnt=i-st.top();
                      }
                      else  {
                        st.pop();
                         if(st.empty()){
                            st.push(i);
                         }
                             else{
                                cnt=max(cnt,i-st.top());
                             }
                      
                      }
                    //   ans=max(ans)
               }
               return cnt;
    }
};
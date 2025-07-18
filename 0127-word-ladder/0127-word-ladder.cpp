class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         //logic likho
         //ek q lo jisme string and step dal do aur push kar do startWord
         queue<pair<string,int>>q;
        q.push({beginWord,1});
        // set lelo usko sort karlo
        set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord) return steps;
        //loop chala lo word ke size ke equal
            for(int i=0; i<word.size(); i++){
                //cahr ko introduce karo word[i]
                char original=word[i];
                for(char ch='a'; ch<='z'; ch++){
                    //change karo
                    word[i]=ch;
                    //it exist in set for check
                    if(st.find(word)!= st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};
// isme step likna hai
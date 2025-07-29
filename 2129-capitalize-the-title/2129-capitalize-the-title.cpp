class Solution {
public:
    string capitalizeTitle(string title) {
        int n=title.size();
        for(int i=0; i<n; ){
               //phle letter c karna hai
               int j=i;
               while(j<n && title[j]!= ' '){
                   j++;
               }
                   int wordLength=j-i;
                   for(int k=i; k<j; k++){
                    //lower case me convert kard do
                    if(title[k]>='A' && title[k]<='Z'){
                        title[k]=title[k]+('a'-'A');
                   }
               }
                  // Capitalize first letter if word length >= 3
                  if(wordLength>=3 && title[i]>='a' && title[i]<='z'){
                    title[i]=title[i]-('a'-'A');
                  }
                  i=j+1;
               }
               return title;
    }
};
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
       vector<int>ans;
       int n=mat.size();
       int m=mat[0].size();
       int row=0,col=0;
       bool goingUp=true;
       while(ans.size()<n*m){
        ans.push_back(mat[row][col]);
        if(goingUp){
            //move upright riGht
            if(row==0 || col==m-1){
                goingUp=false;
                if(col==m-1){
                      row++;
                }else{
                     col++;
                }
            }
                else{
                    row--;
                    col++;
                }
        }
        else{
            // Move down-left
                if (col == 0 || row == n - 1) {
                    goingUp = true;
                    if (row == n - 1) {
                        col++;
                    } else {
                        row++;
                    }
                } else {
                    row++;
                    col--;
                }

           }
       }
    

       return ans;
    }
};
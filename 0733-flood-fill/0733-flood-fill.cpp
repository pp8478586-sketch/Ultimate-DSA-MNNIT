class Solution {
    void dfs(vector<vector<int>>&image,int row,int col,int color,int ref){
        image[row][col]=color;
        int del_row[]={-1,0,1,0};
        int del_col[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int new_row=row+del_row[i];
            int new_col=col+del_col[i];
            if(new_row>=0&&new_col>=0&&
            new_row<image.size()&&new_col<image[0].size()&&
            image[new_row][new_col]==ref){
                dfs(image,new_row,new_col,color,ref);
            }
        }


    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ref=image[sr][sc];
        if(ref==color)return image;
        dfs(image,sr,sc,color,ref);
        return image;
    }
};
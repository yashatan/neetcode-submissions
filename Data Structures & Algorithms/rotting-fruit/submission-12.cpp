class Solution {

        queue<pair<int, int>> rottenFruits;
        int remainFreshFruit=0;
        int rows;
        int cols;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        // vector<vector<int>> visit(rows, vector<int>(cols));
        
        for (int i=0; i<rows;i++){
            for(int j =0; j<cols;j++){
                if (grid[i][j] ==1){
                    remainFreshFruit++;
                }
                if(grid[i][j] ==2){
                    rottenFruits.push({i,j});
                }
            }
        }

        // if(rottenFruits.empty() && remainFreshFruit==0){
        //     return 0;
        // }
        // if(rottenFruits.empty()){
        //     return -1;
        // }

        // if(remainFreshFruit ==0){
        //     return 0;
        // }
        
        return bfs(grid);
    }

    int bfs(vector<vector<int>>& grid){
        int res=0;
        while(remainFreshFruit > 0 && !rottenFruits.empty()){
            int rottenFruitsLength = rottenFruits.size();
            for(int i =0; i <rottenFruitsLength; i++){
                pair<int, int> location = rottenFruits.front();
                rottenFruits.pop();

                int r = location.first;
                int c = location.second;
                
                int neighbors[4][2] = {{r+1,c},{r,c+1},{r-1,c},{r,c-1}};
                for (int j=0;j<4;j++){
                    int newR = neighbors[j][0];
                    int newC = neighbors[j][1];

                    if(min(newR, newC) <0 || (newR == rows) || (newC == cols) || (grid[newR][newC]==0) ||  (grid[newR][newC]==2) ){
                        continue;
                    }
                    grid[newR][newC] =2;
                    rottenFruits.push({newR, newC});
                    remainFreshFruit--; 
                }
            }
            res++;  
        }
         return remainFreshFruit == 0 ? res : -1;
    }
};

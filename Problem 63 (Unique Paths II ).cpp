class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=0;
        if(n!=0){
             m= obstacleGrid[0].size();
        }
        
        int arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1){
                    arr[i][j]=-1;
                }else{
                    arr[i][j]=0;
                }
            }
        }
        
        int k=1;
        for(int i=n-1;i>=0;i--){
            if(arr[i][m-1]==-1){
                k=0;
                continue;
            }
            
            arr[i][m-1]=k;
        }
        
        k=1;
        for(int i=m-1;i>=0;i--){
            if(arr[n-1][i]==-1){
                k=0;
                continue;
            }
            
            arr[n-1][i]=k;
        }
        
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(arr[i][j]!=-1){
                    long int ans=0;
                    if(arr[i][j+1]!=-1){
                        ans+=arr[i][j+1];
                    }
                    
                    if(arr[i+1][j]!=-1){
                        ans+=arr[i+1][j];
                    }
                    
                    arr[i][j]=ans;
                }
            }
        }
        
        
        if(arr[0][0]==-1 || arr[n-1][m-1]==-1){
            return 0;
        }
        
        return arr[0][0];
    }
};
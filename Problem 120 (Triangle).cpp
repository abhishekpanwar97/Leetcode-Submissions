class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int arr[n][n];
        for(int i=0;i<n;i++){
            arr[n-1][i]=triangle[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                arr[i][j]=triangle[i][j]+min(arr[i+1][j],arr[i+1][j+1]);
            }
        }
        
        
        return arr[0][0];
        
        
    }
};
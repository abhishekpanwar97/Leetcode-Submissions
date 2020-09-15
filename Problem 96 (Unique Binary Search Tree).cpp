class Solution {
public:
    void catalan(int* G, int n){
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=G[i]*G[n-1-i];
        }
        
        G[n]=ans;
    }
    
    int numTrees(int n) {
        int* G=new int[n+1];
        for(int i=0;i<=n;i++){
            G[i]=-1;
        }
        
        G[0]=1;
        G[1]=1;
        for(int i=2;i<=n;i++){
            catalan( G, i);
        }
        
        return G[n];
    }
};
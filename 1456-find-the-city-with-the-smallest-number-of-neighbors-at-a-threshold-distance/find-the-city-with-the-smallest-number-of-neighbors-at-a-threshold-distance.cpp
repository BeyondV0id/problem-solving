


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
      
      const int INF = 1e9;
      vector<vector<int>>dist(n,vector<int>(n,INF));

      for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        dist[u][v] = w;
        dist[v][u] = w;
      }

      for(int i = 0; i < n; i++)
        dist[i][i] = 0;
        

      for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }

      int ans = -1;
      int minCities = INF;

      for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
          if(i != j && dist[i][j] <= distanceThreshold){
            cnt++;
          } 
        }
        if(cnt <= minCities){
          minCities = cnt;
          ans = i;
        }
      }

      return ans;
    }
};

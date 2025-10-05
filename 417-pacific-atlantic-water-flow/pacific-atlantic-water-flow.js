// @leet start
/**
 * @param {number[][]} heights
 * @return {number[][]}
 */
var pacificAtlantic = function(heights) {
  const res = [];
  const dirs = [
    [0,1],
    [0,-1],
    [1,0],
    [-1,0]
  ];
  
  const m = heights.length;
  const n = heights[0].length;
  const pacific = Array.from({length:m}, ()=> Array(n).fill(false));
  const atlantic = Array.from({length:m}, ()=> Array(n).fill(false));
  function dfs(r,c,visited){
    visited[r][c] = true;
    for(const [rr,cc] of dirs){
      const nr = rr+r;
      const nc = cc+c;
      if(nr >= 0 && nr < m && nc >=0 && nc<n && !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) 
        dfs(nr,nc,visited); 
  }
  }
  
  for(let c = 0; c < n; c++){
    dfs(0,c,pacific);
    dfs(m-1,c,atlantic);
  }
  for(let r=0 ; r < m; r++){
    dfs(r,0,pacific);
    dfs(r,n-1,atlantic);
  }

  for(let r = 0; r < m;r++){
    for(let c = 0;c <n ;c++){
      if(pacific[r][c] && atlantic[r][c])
        res.push([r,c]);
    }
  }
  return res;
};
// @leet end

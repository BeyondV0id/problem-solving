// Last updated: 3/26/2025, 9:48:30 PM
class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int containers = n*n;
        int containerWeight = containers*w;
        if(maxWeight<containerWeight){
            return maxWeight/w;

        }
        return containers;

        
    }
};
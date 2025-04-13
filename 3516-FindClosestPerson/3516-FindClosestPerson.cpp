// Last updated: 4/13/2025, 10:42:14 AM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distance1 = abs(z-x);
        int distance2 = abs(z-y);
        if(distance1 == distance2)return 0;
        return (distance1<distance2)?1:2;
        
        
        
    }
};
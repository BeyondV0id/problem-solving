// Last updated: 4/3/2025, 1:04:18 PM
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

int len(int n) {
    int l = 0;
    while(n) {
        l++;
        n /= 10;
    }
    return l;
}

class Solution_ {
public:
bool isHappy(int n) {
    std::set<int> seen;
    seen.insert(n);
    while(1) {
        if(n == 1) {
            return true;
        }
  
        int new_num = 0;
        while(n) {
            int r = n % 10;
            new_num += (r * r);
            n /= 10;
        }
        n = new_num;
        auto pr = seen.insert(n);
        if(pr.second == false) {
            break;
        }
    }   
    return false;
}

};

int sum_square(int n) {
    int sum = 0;
    while(n) {
        int t = n % 10;
        sum += (t * t);
        n /= 10;
    }
    return sum;
}

class Solution {
public:
bool isHappy(int n) {
    int slow = n;
    int fast = n;
    
    do {
       slow = sum_square(slow);
       fast = sum_square(sum_square(fast));
        
    }   while(slow != fast);
    return slow == 1;
}

};
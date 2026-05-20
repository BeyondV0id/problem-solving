#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        priority_queue<pair<int, char>> pq;

        if(a > 0)
            pq.push({a, 'a'});

        if(b > 0)
            pq.push({b, 'b'});

        string res = "";

        while(!pq.empty()) {

            auto [freq, letter] = pq.top();
            pq.pop();

            if(res.size() >= 2 &&
               res[res.size() - 1] == letter &&
               res[res.size() - 2] == letter) {

                if(pq.empty())
                    break;

                auto [freq2, letter2] = pq.top();
                pq.pop();

                res += letter2;
                freq2--;

                if(freq2 > 0)
                    pq.push({freq2, letter2});

                pq.push({freq, letter});
            }
            else {

                res += letter;
                freq--;

                if(freq > 0)
                    pq.push({freq, letter});
            }
        }

        return res;
    }
};
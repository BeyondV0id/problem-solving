class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push({});

        int i = 0, n = formula.size();

        while (i < n) {
            if (formula[i] == '(') {
                st.push({});
                i++;
            }
            else if (formula[i] == ')') {
                i++;
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                if (num == 0) num = 1;

                auto top = st.top();
                st.pop();

                for (auto &p : top) {
                    st.top()[p.first] += p.second * num;
                }
            }
            else {

                string element;
                element += formula[i++];

                while (i < n && islower(formula[i])) {
                    element += formula[i++];
                }

                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                if (num == 0) num = 1;

                st.top()[element] += num;
            }
        }

        map<string, int> result = st.top();
        string ans;

        for (auto &p : result) {
            ans += p.first;
            if (p.second > 1) {
                ans += to_string(p.second);
            }
        }

        return ans;
    }
};
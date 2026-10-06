class Solution {
public:
    int lengthLongestPath(string input) {

        vector<string> chunks;

        int i = 0;
        int n = input.size();

        while (i < n) {
            int j = i;
            while (j < n && input[j] != '\n') {
                j++;
            }
            string chunk = input.substr(i, j - i);
            chunks.push_back(chunk);
            i = j + 1;
        }

        vector<pair<string, int>> paths;

        for (auto chunk : chunks) {
            int depth = 0;
            int n = chunk.size();
            int i = 0;
            while (i < n && chunk[i] == '\t') {
                depth++;
                i++;
            }

            paths.push_back({chunk.substr(i, n - i), depth});
        }

        vector<pair<string, int>> st;

        int ans = 0;

        for (auto& [name, depth] : paths) {

            while (st.size() > depth) {
                st.pop_back();
            }

            int currentLength;

            if (st.empty()) {
                currentLength = name.size();
            } else {
                currentLength = st.back().second + 1 + name.size();
            }

            bool isFile = false;

            for (char c : name) {
                if (c == '.') {
                    isFile = true;
                    break;
                }
            }

            if (isFile) {
                ans = max(ans, currentLength);
            } else {
                st.push_back({name, currentLength});
            }
        }

        return ans;
    }
};
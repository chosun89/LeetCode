class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        int n = products.size();
        vector<int> match(n, 0);

        for (int i = 0; i < n; i++) {
            string &p = products[i];
            match[i] = 0;

            while (match[i] < (int) p.size() && match[i] < (int) searchWord.size() && p[match[i]] == searchWord[match[i]])
                match[i]++;
        }

        vector<vector<string>> answer(searchWord.size());

        for (int len = 1; len <= (int) searchWord.size(); len++) {
            int count = 0;

            for (int i = 0; i < n && count < 3; i++)
                if (match[i] >= len) {
                    answer[len - 1].push_back(products[i]);
                    count++;
                }
        }

        return answer;
    }
};

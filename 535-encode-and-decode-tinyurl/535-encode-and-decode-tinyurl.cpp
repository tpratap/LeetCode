class Solution {
public:
    unordered_map<string, string> Map;
    // Encodes a URL to a shortened URL.
    string generateKey() {
        string key = "";
        srand(time(0));
        for(int i = 0; i < 6; i++) {
            int r1 = rand()%2;
            if(r1 == 0) {
                int r2 = rand()%26;
                key += (r2 + 'a');
            }
            else if(r1== 1) {
                int r2 = rand()%26;
                key += (r2 + 'A');
            }
            else {
                int r2 = rand()%9;
                key += (r2 + '0');
            }
        }
        return key;
    }
    
    string encode(string longUrl) {
        string key = generateKey();
        while(Map.find(key) != Map.end()) {
            key = generateKey();
        }
        Map[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return Map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
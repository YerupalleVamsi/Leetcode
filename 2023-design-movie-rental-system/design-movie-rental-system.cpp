class MovieRentingSystem {
public:
    // movie -> {price, shop} for available movies
    unordered_map<int, set<pair<int,int>>> available;
    
    // {price, shop, movie}
    set<tuple<int,int,int>> rented;
    
    // price map
    map<pair<int,int>, int> mp;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            mp[{shop, movie}] = price;
            available[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        if (!available.count(movie)) return ans;
        
        for (auto it = available[movie].begin(); it != available[movie].end() && ans.size() < 5; ++it) {
            ans.push_back(it->second); // shop
        }
        return ans;
    }

    void rent(int shop, int movie) {
        int price = mp[{shop, movie}];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = mp[{shop, movie}];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for (auto it = rented.begin(); it != rented.end() && ans.size() < 5; ++it) {
            auto [price, shop, movie] = *it;
            ans.push_back({shop, movie});
        }
        return ans;
    }
};



/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
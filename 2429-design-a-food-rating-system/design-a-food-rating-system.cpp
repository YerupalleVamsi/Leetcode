class FoodRatings {
public:
struct Compare {
    bool operator()(const pair<string,int> &a, const pair<string,int> &b) {
        if (a.second == b.second) {
            return a.first > b.first;  
            // if ints are equal, smaller string should come first
        }
        return a.second < b.second;  
        // smaller int has higher priority (max-heap on int)
    }
};
    unordered_map<string,string>fc;
    unordered_map<string,int>fr;
    unordered_map<string,priority_queue<pair<string,int>,vector<pair<string,int>>,Compare>>heap_map;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            string  food=foods[i];
            string  cuisine=cuisines[i];
            int rating=ratings[i];
            fc[food]=cuisine;
            fr[food]=rating;
            heap_map[cuisine].push({food,rating});
            }
    }
    
   void changeRating(string food, int newRating) {
    string cuisine = fc[food];
    fr[food] = newRating;
    heap_map[cuisine].push({food, newRating});
}

    
    string highestRated(string cuisine) {
    auto &pq = heap_map[cuisine];
    while (!pq.empty()) {
        string food = pq.top().first;
        int rating = pq.top().second;
        if (fr[food] == rating) return food;  // checking if the food is has the new updated rating ...
        pq.pop(); 
    }
    return "";
}

};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
class Solution {
public:
    // read question carefully nigga 
    // given n cars and pos gives the distance fromm 0
    // travelling to reach mile target
    // speed --> speed[i] miles per hour
    // car cant pass another car
    // but it can travel at same speed of another car
    // car fleet is the number of cars next to each other
    // speed of the car fleet is the min speed of all cars next to each other
    // if a car catches to fleet at target mile still considered as fleet
    // so return the number of cars in fleet

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       // base 
       int fleet=0;
       int n=speed.size();
       if(n==1)return 1;
       vector<pair<int,int>>cars;
       for(int i=0;i<n;i++){
        cars.push_back({position[i],speed[i]});
       }
       sort(cars.rbegin(),cars.rend());
    stack<double> st;  
    for (auto& car : cars) {
        double time = (double)(target - car.first) / car.second;

        if (st.empty() || time > st.top()) {
            st.push(time); 
        }

    }
    return st.size();
    }
};
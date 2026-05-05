int carFleet(int target, vector<int>& pos, vector<int>& speed) {
    vector<pair<int, double>> cars;

    for (int i = 0; i < pos.size(); i++) {
        double time = (double)(target - pos[i]) / speed[i];
        cars.push_back({pos[i], time});
    }

    sort(cars.rbegin(), cars.rend());

    int fleets = 0;
    double currTime = 0;

    for (auto& car : cars) {
        if (car.second > currTime) {
            fleets++;
            currTime = car.second;
        }
    }
    return fleets;
}
class ExamRoom {
    set<int> seats;
    int N;
public:
    ExamRoom(int n) {
        N = n;
    }
    
    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
        
        int maxDist = *seats.begin();
        int pos = 0;
        
        auto prev = seats.begin();
        for (auto it = next(seats.begin()); it != seats.end(); it++) {
            int dist = (*it - *prev) / 2;
            if (dist > maxDist) {
                maxDist = dist;
                pos = *prev + dist;
            }
            prev = it;
        }
        
        if (N - 1 - *seats.rbegin() > maxDist) {
            pos = N - 1;
        }
        
        seats.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};
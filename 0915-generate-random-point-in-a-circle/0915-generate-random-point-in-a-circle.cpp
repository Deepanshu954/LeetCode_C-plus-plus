class Solution {
public:
    double r, xc, yc;
    
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        xc = x_center;
        yc = y_center;
    }
    
    vector<double> randPoint() {
        double len = sqrt((double)rand() / RAND_MAX) * r;
        double deg = (double)rand() / RAND_MAX * 2 * M_PI;
        return {xc + len * cos(deg), yc + len * sin(deg)};
    }
};
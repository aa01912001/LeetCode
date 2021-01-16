class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12) hour = 0;
        double h_to_m = hour * 5 + 5*minutes/60.; // convert hour scale into minute scale
        double ret = abs(h_to_m - minutes)*6; //  calculate the angle between hour and minites
        return ret > 180 ? 360 - ret : ret; // choose the smaller angle
    }
};
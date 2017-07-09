//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/#/description
/*
There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.
An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:
Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
*/

static bool mycompare(pair<int, int> s1, pair<int, int> s2){
    return s1.first<s2.first;
}

int findMinArrowShots(vector<pair<int, int>>& points) {
    if(points.size()==0)
        return 0;
    sort(points.begin(),points.end(),mycompare);
    //idea is to get overlap area among ballons
    vector<pair<int, int>> overlap;
    overlap.push_back(points[0]);
    for(int i=1;i<points.size();i++){
        if(points[i].first<=overlap.back().second){
            overlap.back().first = max(points[i].first,overlap.back().first);  //calculate possible overlap and update
            overlap.back().second = min(points[i].second,overlap.back().second);
        }else{
            overlap.push_back(points[i]);
        }

    }
    return overlap.size();
}

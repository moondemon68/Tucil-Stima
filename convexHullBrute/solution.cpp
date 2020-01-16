#include <bits/stdc++.h>
// #include "matplotlibcpp.h"

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define point pair<double, double>
#define LL long long

using namespace std;
// namespace plt = matplotlibcpp;

const int MAXN = 2500;
int n;
point p[MAXN + 5];
set<point> hullPoints;
vector<pair<point, point>> hullSegments;

// Given line that goes from point a to b. Returns 1 if point c is located on one side of the line, 0 if it is on the line, and -1 if it is on the other side.
int position (point a, point b, point c) {
    double x = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (x < 0) return -1;
    else if (x == 0) return 0;
    else return 1;
}

// Draw the graph
// void draw () {
//     plt::figure_size(1200, 780);
//     vector<double> px, py;
//     for (int i=1;i<=n;i++) {
//         px.pb(p[i].x);
//         py.pb(p[i].y);
//     }
//     plt::scatter(px, py);
//     for (auto p : hullSegments) {
//         px.clear();
//         py.clear();
//         px.pb(p.first.x);
//         py.pb(p.first.y);
//         px.pb(p.second.x);
//         py.pb(p.second.y);
//         plt::plot(px, py);
//     }
//     plt::show();
// }

int main () {
    // INPUT
    cin >> n;
    for (int i=1;i<=n;i++) cin >> p[i].x >> p[i].y;

    // PROCESS
    clock_t start = clock();    // start timer
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i == j) continue;
            bool oneside = 1;   // 1 if ALL points (other than the two selected) is on one side of the line made up of the two selected points
            for (int k=1;k<=n;k++) {
                if (k == i || k == j) continue;
                if (position(p[i], p[j], p[k]) == -1) {
                    oneside = 0;
                    break;
                } 
            }
            if (oneside) {
                hullPoints.insert(p[i]);
                hullSegments.pb(mp(p[i], p[j]));
            }
        }
    }
    cerr << "Time needed: " << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    
    // OUTPUT
    cout << hullPoints.size() << endl;
    for (auto p : hullPoints) {
        cout << p.x << " " << p.y << endl;
    }
    // draw();
    return 0;
}
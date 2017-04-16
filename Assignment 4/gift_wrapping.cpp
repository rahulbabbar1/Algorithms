#include <bits/stdc++.h>
using namespace std;
 
struct Point{
    int x, y;
};

int findOrientation(Point a, Point b, Point c){
    int val = (b.y - a.y)*(c.x - b.x)-(b.x - a.x)*(c.y - b.y); 
    if (val == 0) 
        return 0; 
    else if(val > 0)
        return 1;
    else
        return 2;
}

void convexHull(Point points[], int n){
    if (n < 3) return;
    vector<Point> hull;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    int p = l, q;
    do
    {
        hull.push_back(points[p]);
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
           if (findOrientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
        p = q;
 
    } while (p != l);  
    for (int i = 0; i < hull.size(); i++)
    {
        cout << "(" << hull[i].x << ", "<< hull[i].y << ")\n";
    }
}

int main(){

    int n;
    cin>>n;

    Point *P = new Point[n];

    for(int i=0;i<n;i++){
       cin>>P[i].x>>P[i].y;
    }

    float start = clock();
    convexHull(P, n);
    float end = clock();
    float diff = end-start;
    cout<<"Time taken is"<< diff/CLOCKS_PER_SEC<<" seconds"<<"\n";
    return 0;
}

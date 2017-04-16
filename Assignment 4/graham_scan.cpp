#include <bits/stdc++.h>
using namespace std;
 
struct Point{
    int x, y;
};

Point p;

Point nextToTop(stack<Point> &s){
    Point p_temp = s.top();
    s.pop();
    Point rs_temp = s.top();
    s.push(p_temp);
    return rs_temp;
}

int swap(Point &p_a, Point &p_b){
    Point p_temp = p_a;
    p_a = p_b;
    p_b = p_temp;
}

int distSq(Point a, Point b){
    return (a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y);
}

int findOrientation(Point a, Point b, Point c){
    int val = (b.y - a.y)*(c.x - b.x)-(b.x - a.x)*(c.y - b.y); 
    if (val == 0) 
        return 0; 
    else if(val > 0)
        return 1;
    else
        return 2;
}

int compare(const void *a, const void *b){
   Point *a_t = (Point *)a;
   Point *b_t = (Point *)b;
   int o = orientation(p, *a_t, *b_t);
   if (o == 0)
     return (distSq(p, *b_t) >= distSq(p, *a_t))? -1 : 1;
   return (o == 2)? -1: 1;
}

void convexHull(Point points[], int n){

   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++){
       int y = points[i].y;
       if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
           ymin = points[i].y, min = i;
   }

   swap(points[0], points[min]);
   p = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
   int m = 1; 

   for (int i=1; i<n; i++){
       while (i < n-1 && orientation(p, points[i],points[i+1]) == 0)
          i++;
       points[m] = points[i];
       m++;  
   }

   if (m < 3) return;
      stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);

   for (int i = 3; i < m; i++){
      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }

   while (!S.empty()){
       Point p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }
}
int main()
{
    int n;
    cin>>n;
    Point *P= new Point[n];
    for(int i=0;i<n;i++)
    {
       cin>>P[i].x>>P[i].y;
    }
    
    float start = clock();
    convexHull(P, n);
    float end = clock();
    float diff = end-start;
    cout<<"Time taken is"<< diff/CLOCKS_PER_SEC<<" seconds"<<"\n";
    return 0;
}
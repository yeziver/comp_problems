#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Rectangle {
  public:
    int x1, y1, x2, y2;

    Rectangle() {}

    Rectangle(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {}

    bool includes(int x, int y) {
      return x >= x1 && y >= y1 && x <= x2 && y <= y2;
    }
};

class Point {
public:
  int x, y;

  Point() {}

  Point(int x, int y): x(x), y(y) {}
};

int main(void) {
  //reading input
  int n, m;
  cin >> n >> m;

  vector<Rectangle> rectangles;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    rectangles.push_back(Rectangle(x1, y1, x2, y2));
  }

  vector<Point> points;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    points.push_back(Point(x, y));
  }

  //main algorithm
  int max = -1;
  int res = 0;
  for (int i = 0; i < n; i++) { //for every rectangle
    int count = 0;
    for (int j = 0; j < m; j++) { //for every point
      if (rectangles[i].includes(points[j].x, points[j].y)) {
        count++;
      }
    }
    if (count > max) {
      max = count;
      res = i+1;
    }
  }

  cout << res;
}

//Star League Tigers are deeply motivated to eat all cows of Farmer John, including always 
//troublemaker Bessie - cause of all the USACO problems. Tigers №007 got the plans of Farmer 
//John's farm. They found that Farmer John's farm consists of exactly 3 rectangles.  

//Tigers know that the population ratio of the FJ's farm is 1 cow/unit square. And they 
//want make a team of tigers such that each tiger will eat one cow.

//Please help tigers to find how many tigers will be in the team.  

//INPUT FORMAT:
//  Input consists of 3 lines. 
//  Each line contains four space-separated integers: x1 y1 x2 y2, where 
//     (x1,y1) and (x2,y2) are the coordinates of the lower-left and upper-right 
//     corners of one rectangles
//  All coordinates are in the range -10000 to +10000.

//OUTPUT FORMAT:
//  Please output the total combined area of 3 rectangles. 

//SAMPLE INPUT:
//1 0 4 7
//8 4 9 8
//2 4 5 5

//SAMPLE OUTPUT:
//26


class Rectangle {
  public:
    int x1, y1, x2, y2;

    Rectangle() {}

    Rectangle(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {}

    Rectangle intersection(Rectangle other) {
      int X1 = max(x1, other.x1);
      int Y1 = max(y1, other.y1);
      int X2 = min(x2, other.x2);
      int Y2 = min(y2, other.y2);
      if (X1 > X2 || Y1 > Y2) {
        return Rectangle(0, 0, 0, 0);
      } else {
        return Rectangle(X1, Y1, X2, Y2);
      }
    }

    int area() {
      return (x2-x1) * (y2-y1);
    }
};

int main(void) {
  int area = 0;
  vector<Rectangle> r(3);

  for (int i = 0; i < 3; ++i) {
    cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;

    area += r[i].area();
  }

  Rectangle r01 = r[0].intersection(r[1]);
  Rectangle r02 = r[0].intersection(r[2]);
  Rectangle r12 = r[1].intersection(r[2]);
  Rectangle r012 = r[0].intersection(r[1]).intersection(r[2]);

  area = area - r01.area() - r02.area() - r12.area() + r012.area();
  cout << area;
}

#include <cmath>
#include <iostream>
using namespace std;

void calculate(int n, int y, int x, int sum) {
   int area = pow(2, n - 1) * pow(2, n - 1);
   if (y < 2 && x < 2) {
      sum += 2 * y + x;
      cout << sum;
      return;
   }
   if (x >= pow(2, n - 1) && y < pow(2, n - 1)) {
      sum += area;
      x -= pow(2, n - 1);
   } else if (y >= pow(2, n - 1) && x < pow(2, n - 1)) {
      sum += area * 2;
      y -= pow(2, n - 1);
   } else if (y >= pow(2, n - 1) && x >= pow(2, n - 1)) {
      sum += area * 3;
      y -= pow(2, n - 1);
      x -= pow(2, n - 1);
   }
   calculate(n - 1, y, x, sum);
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n, y, x;
   cin >> n >> y >> x;
   calculate(n, y, x, 0);
}
#include <iostream>

using namespace std;

int main(void) {
  int n,m,s,t,x,y,i,M[100][100]={0};

  cin >> n >> m >> s >> t;
  if (!cin)
    return 1;
  // n between 1 and 100
  if (n <= 0 || n > 100)
    return 2;
  // m between 0 and n(n-1)/2
  if (m < 0 || m > (n*(n-1))/2)
    return 3;
  // s between 0 and n-1
  if (s < 0 || s >= n)
    return 4;
  // t between 0 and 9
  if (t < 0 || t > 9)
    return 5;

  for (i=0;i<m;i++) {
    cin >> x >> y;
    if (!cin)
      return 6;

    // x and y between 0 and n-1
    if (x < 0 || x >= n)
      return 7;
    if (y < 0 || y >= n)
      return 8;

    if (M[x][y])
      return 9;

    M[x][y] = M[y][x] = 1;
  }

  // we win!
  return 42;
}


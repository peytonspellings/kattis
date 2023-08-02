// Tom Wexler

import java.util.*;
import java.io.*;

public class squawkM1 {
  public static void main(String[] args) {
        //int[][] board = new int[5][5];
    int c = 1;
    Scanner input = new Scanner(System.in);
    int n = input.nextInt();
    int m = input.nextInt();
    int s = input.nextInt();
    int t = input.nextInt();
      int[][] a = new int[n][n];
      for(int i = 0; i < m; i++) {
        int x = input.nextInt();
        int y = input.nextInt();
        a[x][y] = 1;
        a[y][x] = 1;
      }
      long[][] b = new long[t+1][n];
      b[0][s] = 1;
      for (int i = 1; i < t+1; i++) {
        for (int x = 0; x < n; x++) {
          for (int y = 0; y < n; y++) {
            b[i][x] += b[i-1][y]*a[x][y];
          }
        }
      }
      long total = 0;
      for (int x = 0; x < n; x++) {
        total += b[t][x];
      }
      System.out.println(total);
  }
}

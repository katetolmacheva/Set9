#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
void tqs(std::vector<std::string>& a, int l, int r, int d) {
  if (r <= l) return;
  char pivc = a[l].length() > d ? a[l][d] : -1;
 
  int lt = l;
  int gt = r;
  int i = l + 1;
 
  while (i <= gt) {
    char tv = a[i].length() > d ? a[i][d] : -1;
 
    if (tv < pivc) {
      std::swap(a[lt++], a[i++]);
    }
    else if (tv > pivc) {
      std::swap(a[i], a[gt--]);
    }
    else {
      i++;
    }
  }
 
  tqs(a, l, lt - 1, d);
 
  if (pivc != -1) {
    tqs(a, lt, gt, d + 1);
  }
 
  tqs(a, gt + 1, r, d);
}

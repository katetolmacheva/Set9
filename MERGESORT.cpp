#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
void mg(std::vector<std::string>& a, int l, int m, int r) {
  int s1 = m - l + 1;
  int s2 = r - m;
 
  std::vector<std::string> la(s1);
  std::vector<std::string> ra(s2);
 
  for (int i = 0; i < s1; i++) {
    la[i] = a[l + i];
  }
  for (int j = 0; j < s2; j++) {
    ra[j] = a[m + 1 + j];
  }
 
  int i1 = 0;
  int i2 = 0;
  int im = l;
 
  while (i1 < s1 && i2 < s2) {
    if (la[i1] <= ra[i2]) {
      a[im] = la[i1];
      i1++;
    }
    else {
      a[im] = ra[i2];
      i2++;
    }
    im++;
  }
 
  while (i1 < s1) {
    a[im] = la[i1];
    i1++;
    im++;
  }
 
  while (i2 < s2) {
    a[im] = ra[i2];
    i2++;
    im++;
  }
}
 
void mgs(std::vector<std::string>& a, int b, int e) {
  if (b >= e) {
    return;
  }
 
  int m = b + (e - b) / 2;
  mgs(a, b, m);
  mgs(a, m + 1, e);
  mg(a, b, m, e);
}

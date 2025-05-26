#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
const int asz = 257;
 
int gch(const std::string& s, int d) {
  if (d >= s.length()) {
    return 0;
  }
  return static_cast<unsigned char>(s[d]) + 1;
}
 
void msdrs(std::vector<std::string>& a, int l, int r, int d) {
  if (r <= l) return;
 
  std::vector<std::string> aux(r - l + 1);
  std::vector<int> cnt(asz, 0);
 
  for (int i = l; i <= r; i++) {
    cnt[gch(a[i], d)]++;
  }
 
  for (int i = 0; i < asz - 1; i++) {
    cnt[i + 1] += cnt[i];
  }
 
  for (int i = r; i >= l; i--) {
    aux[cnt[gch(a[i], d)] - 1] = a[i];
    cnt[gch(a[i], d)]--;
  }
 
  for (int i = l; i <= r; i++) {
    a[i] = aux[i - l];
  }
 
  int prev_cnt = 0;
  for (int i = 0; i < asz; i++) {
    if (cnt[i] > prev_cnt) {
      msdrs(a, l + prev_cnt, l + cnt[i] - 1, d + 1);
    }
    prev_cnt = cnt[i];
  }
}

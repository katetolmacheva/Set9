#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int asz = 257;
const int swt = 74;

int gch(const std::string& s, int d) {
  if (d >= s.length()) {
    return 0;
  }
  return static_cast<unsigned char>(s[d]) + 1;
}

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

void msdrs(std::vector<std::string>& a, int l, int r, int d) {
  if (r - l + 1 <= swt) {
    tqs(a, l, r, d);
    return;
  }
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

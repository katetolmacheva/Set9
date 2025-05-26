#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include <atomic> 
#include <iomanip> 

class sgen {
private:
  std::string cs = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#%:;^&*()-.";
  std::mt19937_64 rng;

  int minl;
  int maxl;

  std::string grs() {
    std::uniform_int_distribution<int> ldist(minl, maxl);
    int cl = ldist(rng);
    std::string s = "";
    for (int i = 0; i < cl; ++i) {
      std::uniform_int_distribution<int> cdist(0, cs.length() - 1);
      s += cs[cdist(rng)];
    }
    return s;
  }

public:
  sgen(int minlen, int maxlen) : minl(minlen), maxl(maxlen) {
    rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
  }

  std::vector<std::string> grnd(int cnt) {
    std::vector<std::string> d(cnt);
    for (int i = 0; i < cnt; ++i) {
      d[i] = grs();
    }
    return d;
  }

  std::vector<std::string> grvs(int cnt) {
    std::vector<std::string> d = grnd(cnt);
    std::sort(d.begin(), d.end());
    std::reverse(d.begin(), d.end());
    return d;
  }

  std::vector<std::string> grns(int cnt, int swp) {
    std::vector<std::string> d = grnd(cnt);
    std::sort(d.begin(), d.end());

    std::uniform_int_distribution<int> idist(0, cnt - 1);
    for (int i = 0; i < swp; ++i) {
      int idx1 = idist(rng);
      int idx2 = idist(rng);
      if (idx1 != idx2) {
        std::swap(d[idx1], d[idx2]);
      }
    }
    return d;
  }

  std::vector<std::string> gcp(int cnt, const std::string& pre) {
    std::vector<std::string> d(cnt);
    std::uniform_int_distribution<int> ldist(std::max(minl, (int)pre.length()), maxl);
    for (int i = 0; i < cnt; ++i) {
      int cl = ldist(rng);
      std::string s = pre;
      for (int j = pre.length(); j < cl; ++j) {
        std::uniform_int_distribution<int> cdist(0, cs.length() - 1);
        s += cs[cdist(rng)];
      }
      d[i] = s;
    }
    return d;
  }
};

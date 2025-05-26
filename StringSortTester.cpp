std::atomic<long long> gcmpc;

class sst {
public:
  std::pair<long long, long long> rst(std::vector<std::string>& d, void (*sf)(std::vector<std::string>&, int, int, int)) {
    gcmpc = 0;
    auto start = std::chrono::high_resolution_clock::now();
    sf(d, 0, d.size() - 1, 0);
    auto end = std::chrono::high_resolution_clock::now();
    long long tt = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return { tt, gcmpc.load() };
  }

  std::pair<long long, long long> rststd(std::vector<std::string>& d, void (*sf)(std::vector<std::string>&, int, int)) {
    gcmpc = 0;
    auto start = std::chrono::high_resolution_clock::now();
    sf(d, 0, d.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    long long tt = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return { tt, gcmpc.load() };
  }
};

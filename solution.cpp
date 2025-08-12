#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> acts = {"Swimming", "Running", "Football"};
int Count = 0;
int n = 0;

void createUniqueActivities(int x, vector<string> vec) {
  if (x == n) {
    Count++;
    for (string str : vec) {
      cout << str << " ";
    }
    cout << endl;
    return;
  }
  vector<string> A = vec;
  A.push_back(acts[0]);
  vector<string> B = vec;
  B.push_back(acts[1]);
  vector<string> C = vec;
  C.push_back(acts[2]);

  if (vec.empty()) {
    createUniqueActivities(x + 1, A);
    createUniqueActivities(x + 1, B);
    createUniqueActivities(x + 1, C);
  }

  else if (vec.back() == acts[0]) {
    createUniqueActivities(x + 1, B);
    createUniqueActivities(x + 1, C);
  }

  else if (vec.back() == acts[1]) {
    createUniqueActivities(x + 1, A);
    createUniqueActivities(x + 1, C);
  }

  else if (vec.back() == acts[2]) {
    createUniqueActivities(x + 1, A);
    createUniqueActivities(x + 1, B);
  }
}

int main() {
  cin >> n;
  createUniqueActivities(0, {});
  cout << endl << "Count: " << Count << endl;
  return 0;
}

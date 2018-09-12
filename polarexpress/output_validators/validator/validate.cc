#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include "validate.h"

using namespace std;


void train_op(const int k, vector<int> &a) {
  const int n = a.size();
  vector<int> result(n);
  for (int i = k; i < n; i++) {
    result[i - k] = a[i];
  }
  for (int i = 0; i < k; i++) {
    result[n - i - 1] = a[i];
  }
  a = std::move(result);
}


bool is_ordered(const vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != i + 1) {
      return false;
    }
  }
  return true;
}


void check_case() {
  // Read in initial permutation.
  int N;
  assert(judge_in >> N);
  vector<int> trains(N);
  for (int i = 0; i < N; i++) {
    assert(judge_in >> trains[i]);
  }

  // Read M from output.
  int M;
  string line;
  if (!getline(author_out, line)) {
    wrong_answer("Failed to read M");
  } else {
    try {
      M = std::stoi(line);
    } catch (...) {
      wrong_answer("Expected number in output, got: %s\n", line.c_str());
    }
    if (M < 0 || M > 1000) {
      wrong_answer("M must be within [0, 1000], received: %d\n", M);
    }
  }

  // Read the sequence of instructions.
  int k;
  int counter = 0;
  while (getline(author_out, line)) {
    if (counter >= M) {
      wrong_answer("Number of instructions exceeded M given\n");
    }
    try {
      k = std::stoi(line);
    } catch (...) {
      wrong_answer("Expected number in output, got: %s\n", line.c_str());
    }
    if (k < 1 || k > N) {
      wrong_answer("Each k must be within [1, N], got: %d\n", k);
    }
    // Perform train operation.
    train_op(k, trains);
    counter++;
  }
  if (counter < M) {
    wrong_answer("Number of instructions less than M given\n");
  }
  if (!is_ordered(trains)) {
    wrong_answer("Trains not ordered at the end\n");
  }
}


int main(int argc, char **argv) {
  init_io(argc, argv);

  check_case();

  /* Check for trailing output. */
  string trash;
  if (author_out >> trash) {
    wrong_answer("Trailing output.\n");
  }

  accept();
  return 0;
}

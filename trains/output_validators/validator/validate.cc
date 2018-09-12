#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include "validate.h"

using namespace std;

void train_op(const int k, vector<int>& a) {

  const int n = a.size();
  vector<int> result(n);

  for (int i = k; i < n; i++) result[i-k] = a[i];
  
  for (int i = 0; i < k; i++) result[n-i-1] = a[i];

  a = std::move(result);
}

bool is_ordered(const vector<int>& a)
{
  for (int i = 0; i < a.size(); i++) 
    if (a[i] != i+1) 
      return false;
  return true;
}

void check_case() {
  // Read in initial permutation.
  int N;
  assert(judge_in >> N);
  vector<int> trains(N);
  for (int i = 0; i < N; i++) {
    assert(cin >> trains[i]);
  }

  // Read M from output
  int M;

  string line;
  if (!getline(author_out, line)) {
    wrong_answer("Failed to read M.");
  }
  else {
    stringstream ss(line);
    string token;
    if (ss >> token) {
      try {
        M = std::stoi(token);
      } catch (...) {
        wrong_answer("Invalid token detected in output: %s\n", token.c_str());
      }
      if (M < 0 || M > 1000) {
        wrong_answer("M must be within [0, 1000], received: %d\n", M);
      }
    }
    else wrong_answer("Failed to read M.\n");
  }

  // Read the sequence of instructions.
  if (!getline(author_out, line)) {
    wrong_answer("Failed to read instruction sequence.\n");
  }
  else {
    stringstream ss(line);
    string token;
    int k;
    int counter = 0;
    while (ss >> token) {

      if (counter >= M) {
        wrong_answer("Number of instructions does not match M given.\n");
      }
      try {
        k = std::stoi(token);
      } catch (...) {
        wrong_answer("Invalid token detected in output: %s\n", token.c_str());
      }
      if (k < 1 || k > N) {
        wrong_answer("Each K must be within [1, N].\n");
      }

      // Perform train operation.
      train_op(k, trains);

      counter++;
    }
    if (counter < M) {
      wrong_answer("Number of instructions does not match M given.\n");
    }
  }

  if (!is_ordered(trains)) wrong_answer("Incorrect.\n");
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

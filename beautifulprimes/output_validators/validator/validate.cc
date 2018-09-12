#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include "validate.h"

using namespace std;


class bigint {
  std::string digits;
  int sign;

  void normalize() {
    size_t pos = digits.find_last_not_of('0');
    if (pos != std::string::npos) {
      digits.erase(pos + 1);
    }
    if (digits.empty()) {
      digits = "0";
    }
    if (digits.size() == 1 && digits[0] == '0') {
      sign = 1;
      return;
    }
  }

  static int comp(const std::string &a, const std::string &b,
                  int asign, int bsign) {
    if (asign != bsign) {
      return asign < bsign ? -1 : 1;
    }
    if (a.size() != b.size()) {
      return a.size() < b.size() ? -asign : asign;
    }
    for (int i = (int)a.size() - 1; i >= 0; i--) {
      if (a[i] != b[i]) {
        return a[i] < b[i] ? -asign : asign;
      }
    }
    return 0;
  }

  static bigint add(const std::string &a, const std::string &b,
                    int asign, int bsign) {
    if (asign != bsign) {
      return (asign == 1) ? sub(a, b, asign, 1) : sub(b, a, bsign, 1);
    }
    bigint res;
    res.sign = asign;
    res.digits.resize(std::max(a.size(), b.size()) + 1, '0');
    for (int i = 0, carry = 0; i < (int)res.digits.size(); i++) {
      int d = carry;
      if (i < (int)a.size()) {
        d += a[i] - '0';
      }
      if (i < (int)b.size()) {
        d += b[i] - '0';
      }
      res.digits[i] = '0' + (d % 10);
      carry = d/10;
    }
    res.normalize();
    return res;
  }

  static bigint sub(const std::string &a, const std::string &b,
                    int asign, int bsign) {
    if (asign == -1 || bsign == -1) {
      return add(a, b, asign, -bsign);
    }
    bigint res;
    if (comp(a, b, asign, bsign) < 0) {
      res = sub(b, a, bsign, asign);
      res.sign = -1;
      return res;
    }
    res.digits.assign(a.size(), '0');
    for (int i = 0, borrow = 0; i < (int)res.digits.size(); i++) {
      int d = (i < (int)b.size() ? a[i] - b[i] : a[i] - '0') - borrow;
      if (a[i] > '0') {
        borrow = 0;
      }
      if (d < 0) {
        d += 10;
        borrow = 1;
      }
      res.digits[i] = '0' + (d % 10);
    }
    res.normalize();
    return res;
  }

 public:
  bigint(long long n = 0) {
    sign = (n < 0) ? -1 : 1;
    if (n == 0) {
      digits = "0";
      return;
    }
    for (n = (n > 0) ? n : -n; n > 0; n /= 10) {
      digits += '0' + (n % 10);
    }
    normalize();
  }

  bigint(const std::string &s) {
    if (s.empty() || (s[0] == '-' && s.size() == 1)) {
      throw std::runtime_error("Invalid string format to construct bigint.");
    }
    digits.assign(s.rbegin(), s.rend());
    if (s[0] == '-') {
      sign = -1;
      digits.erase(digits.size() - 1);
    } else {
      sign = 1;
    }
    if (digits.find_first_not_of("0123456789") != std::string::npos) {
      throw std::runtime_error("Invalid string format to construct bigint.");
    }
    normalize();
  }

  std::string to_string() const {
    return (sign < 0 ? "-" : "") + std::string(digits.rbegin(), digits.rend());
  }

  friend int comp(const bigint &a, const bigint &b) {
    return comp(a.digits, b.digits, a.sign, b.sign);
  }

  friend bigint add(const bigint &a, const bigint &b) {
    return add(a.digits, b.digits, a.sign, b.sign);
  }

  friend bigint sub(const bigint &a, const bigint &b) {
    return sub(a.digits, b.digits, a.sign, b.sign);
  }

  friend bigint mul(const bigint &a, const bigint &b) {
    bigint res, row(a);
    for (int i = 0; i < (int)b.digits.size(); i++) {
      for (int j = 0; j < (b.digits[i] - '0'); j++) {
        res = add(res.digits, row.digits, res.sign, row.sign);
      }
      if (row.digits.size() > 1 || row.digits[0] != '0') {
        row.digits.insert(0, "0");
      }
    }
    res.sign = a.sign*b.sign;
    res.normalize();
    return res;
  }
};


bool is_prime(int n) {
  if (n == 2 || n == 3) {
    return true;
  }
  if (n < 2 || n % 2 == 0 || n % 3 == 0) {
    return false;
  }
  for (int i = 5, w = 4; i*i <= n; i += w) {
    if (n % i == 0) {
      return false;
    }
    w = 6 - w;
  }
  return true;
}


void check_case() {
  int T, N;
  assert(judge_in >> T);
  for (int i = 1; i <= T; i++) {
    assert(judge_in >> N);

    string line;
    if (!getline(author_out, line)) {
      wrong_answer("Did not get answer for case %d\n", i);
    }

    stringstream ss(line);
    string token;
    vector<int> v;
    while (ss >> token) {
      int val;
      try {
        val = std::stoi(token);
      } catch (...) {
        wrong_answer("Invalid token detected in output: %s\n", token.c_str());
      }
      if (val < 1 || val > 1000000) {
        wrong_answer("Outputs must be in [1, 10^6], received: %d\n", val);
      }
      if (!is_prime(val)) {
        wrong_answer("Outputs must prime, received: %d\n", val);
      }
      v.push_back(val);
    }

    if (v.size() != N) {
      wrong_answer("Output must have %d values, received %d\n", N, v.size());
    }

    bigint curr(v[0]);
    for (int i = 1; i < v.size(); i++) {
      curr = mul(curr, bigint(v[i]));
    }

    string s = curr.to_string();
    if (s.size() != N) {
      wrong_answer("Product has %d digits, expected %d digits\n", s.size(), N);
    }
  }
}


int main(int argc, char **argv) {
  init_io(argc, argv);

  check_case();

  /* Check for trailing output. */
  string trash;
  if (author_out >> trash) {
    wrong_answer("Trailing output\n");
  }

  accept();
  return 0;
}

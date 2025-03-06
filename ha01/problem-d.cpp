#include <cctype>
#include <iostream>
#include <string>
#include <vector>

// extract digits from input string using cctype isdigit to skip '-'
// convert string to char for each char in id string
// check char to see if digit using isdigit from cctype
std::vector<int> extractDigits(std::string &id) {
  std::vector<int> parseID;
  for (char ch : id) {
    if (isdigit(ch)) {
      parseID.push_back(ch - '0');
    }
  }
  return parseID;
}

// loop through each vector to multiply id by const check vector
// tally and return sum
int calculateValid(std::vector<int> id, std::vector<int> control) {
  int sum = 0;
  int product;
  for (int i = 0; i < id.size(); i++) {
    product = id[i] * control[i];
    sum += product;
  }
  return sum;
}

// check if sum is valid by sum%11
// return true if sum%11 is 0
bool checkValid(int sum) {
  bool isGood = false;
  if (sum % 11 == 0) {
    isGood = true;
  }
  return isGood;
}
int main() {
  std::string idInput;
  const std::vector<int> control = {4, 3, 2, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> parseID;
  int sum;
  bool isGood;
  std::cin >> idInput;
  parseID = extractDigits(idInput);
  sum = calculateValid(parseID, control);
  isGood = checkValid(sum);
  isGood == true ? std::cout << "1" : std::cout << "0";
}

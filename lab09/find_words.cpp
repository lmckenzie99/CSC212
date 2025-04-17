#include "bst.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>
std::vector<std::string> getDict() {
  std::string line;
  std::vector<std::string> dict;
  std::ifstream myFile("words.txt");
  if (myFile.is_open()) {
    while (std::getline(myFile, line)) {
      dict.push_back(line);
    }
    myFile.close();
  }
  return dict;
}
std::vector<std::string> tokenize(const std::string &line) {
  std::vector<std::string> tokens;
  std::string currentToken;

  for (char c : line) {
    if (std::isalpha(c)) {
      // add alphabetic character to the current token
      currentToken += std::tolower(c);
    } else if (!currentToken.empty()) {
      // Non-alphabetic character encountered after a token
      // Push the current token to the vector and reset it
      tokens.push_back(currentToken);
      currentToken.clear();
    }
  }

  // Add the last token if the line ends with a valid token
  if (!currentToken.empty()) {
    tokens.push_back(currentToken);
  }

  return tokens;
}

std::vector<std::vector<std::string>> getBook() {
  std::string filename = "2600-0.txt";
  // Open the file
  std::ifstream inputFile(filename);
  // Check if the file was opened successfully
  // Read the file line by line
  std::string line;
  std::vector<std::vector<std::string>> words;
  while (std::getline(inputFile, line)) { 
    // Tokenize the line
    words.push_back(tokenize(line));
    // Print each token for verification
  }
  return words;
}

int main() {
  std::vector<std::string> dict = getDict();
  std::vector<std::vector<std::string>> book = getBook();
  BST<std::string> bst, not_found;
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(dict.begin(), dict.end(), g);
  for (const auto &c : dict) {
    bst.insert(c);
  }

  std::cout << "Size: " << bst.get_size() << '\n'
            << "Height: " << bst.get_height() << '\n'
            << "log2 size: " << std::log2(bst.get_size());

  for (const auto &line : book) {
    for (const auto &word : line) {
      if (!bst.search(word)) {
        if (!not_found.search(word)) {
          not_found.insert(word);
        }
      }
    }
  }
  std::cout << "Words not found in dictionary: ";
  not_found.print_in_order();
}

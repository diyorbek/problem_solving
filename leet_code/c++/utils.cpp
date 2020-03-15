#pragma once
#include <iostream>
#include <string>
#include <vector>

void printVector(std::vector<int>& nums) {
  std::cout << "[ ";
  for (auto i = nums.begin(); i != nums.end(); i++)
    std::cout << *i << " ";
  std::cout << "]";
}

void printVector(std::vector<std::string>& nums) {
  std::cout << "[ ";
  for (auto i = nums.begin(); i != nums.end(); i++)
    std::cout << *i << " ";
  std::cout << "]";
}

void print2dVector(std::vector<std::vector<int>>& list) {
  for (auto i = list.begin(); i != list.end(); i++) {
    printVector(*i);
    std::cout << std::endl;
  }
}

void print2dVector(std::vector<std::vector<std::string>>& list) {
  for (auto i = list.begin(); i != list.end(); i++) {
    printVector(*i);
    std::cout << std::endl;
  }
}
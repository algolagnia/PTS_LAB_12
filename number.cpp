#include "number.h"
#include <cmath>
#include <iostream>
#include <limits>

namespace io {
    int Number = 0;
    int digitSum = 0;
}

void io::inputData() {
  bool validInput = false;
  do {
    std::cout << "Введіть ціле число: ";
    if (std::cin >> io::Number) {
      validInput = true;
    } else {
      std::cout << "Помилка: введіть ціле число.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while (!validInput);
}

int io::calculateDigitSum(int number) {
  int sum = 0;
  number = std::abs(number);

  while (number > 0) {
    sum += number % 10;
    number /= 10;
  }
  return sum;
}

void io::displayResults() {
  io::digitSum = calculateDigitSum(io::Number);
  std::cout << "Сума цифр числа " << io::Number << " дорівнює " << io::digitSum
            << std::endl;
}

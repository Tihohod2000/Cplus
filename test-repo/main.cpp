#include <vector>
#include <functional>
#include <iostream>
#include "candle.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;


// Тест 1: Проверка попадания цены внутри тела зеленой свечи
bool test1() {
  Candle candle(100.0, 120.0, 90.0, 110.0); // Зеленая свеча (close > open)
  return candle.body_contains(105.0); // Ожидается true
}

// Тест 2: Проверка попадания цены на границы тела красной свечи
bool test2() {
  Candle candle(110.0, 120.0, 90.0, 100.0); // Красная свеча (open > close)
  return candle.body_contains(110.0) && candle.body_contains(100.0); // Ожидается true для обеих границ
}

// Тест 3: Проверка цены вне тела свечи
bool test3() {
  Candle candle(100.0, 120.0, 90.0, 110.0); // Зеленая свеча
  return !candle.body_contains(95.0) && !candle.body_contains(115.0); // Ожидается false для обеих цен
}

//тест 2
bool test5()
{
  //пример какого-то теста
  return 42 != (41 + 1); //failed
}

//тест 3
bool test6()
{
  Candle candle{ 0.0, 3.0, 3.0, 3.0 };

  //пример какого-то теста
  return candle.high == 3.0;
}

void initTests()
{
  tests.push_back(test1);
  tests.push_back(test2);
  tests.push_back(test3);
  //tests.push_back(test4);
  //tests.push_back(test5);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}

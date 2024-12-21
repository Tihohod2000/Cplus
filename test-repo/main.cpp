#include <vector>
#include <functional>
#include <iostream>
#include "candle.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

//2.1
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
//2.2
//тест 4
bool test4()
{
  //цена внутри диапазона свечи
  Candle candle(100.0, 120.0, 90.0, 110.0);
  return candle.contains(101.0); //Ожидается true
}

//тест 5
bool test5()
{
  Candle candle(100.0, 120.0, 90.0, 110.0); // Любая свеча
  return candle.contains(90.0) && candle.contains(120.0); // Ожидается true для обеих границ
}

//тест 6
bool test6()
{
  Candle candle(100.0, 120.0, 90.0, 110.0); // Любая свеча
  return !candle.contains(80.0) && !candle.contains(130.0); // Ожидается false для цен ниже low и выше high
}

//2.3
//тест 7
bool test7() {
  Candle candle(100.0, 120.0, 90.0, 110.0); // Любая свеча
  return candle.full_size() == 30.0; // Ожидается 120.0 - 90.0 = 30.0
}

//тест 8
bool test8() {
  Candle candle(100.0, 120.0, 120.0, 110.0); // Любая свеча
  return candle.full_size() == 0.0; // Ожидается 120.0 - 120.0 = 0.0
}

//тест 9
bool test9() {
  Candle candle(100.0, 100.0, 120.0, 110.0); // Любая свеча
  return candle.full_size() == 20.0; // Ожидается 100.0 - 120.0 = 20.0
}


//2.4
//тест 10
bool test10() {
  Candle candle(100.0, 100.0, 120.0, 110.0); // Зеленая свеча (close > open)
  return candle.body_size() == 10.0; // Ожидается 110.0 - 100.0 = 10.0
}

//тест 11
bool test11() {
  Candle candle(100.0, 100.0, 120.0, 100.0); // Свеча с одинаковыми open и close
  return candle.body_size() == 0.0; // Ожидается 100.0 - 100.0 = 0.0
}

//тест 12
bool test12() {
  Candle candle(110.0, 100.0, 120.0, 100.0); // Красная свеча (open > close)
  return candle.body_size() == 10.0; // Ожидается 110.0 - 100.0 = 10.0
}

//2.5
//тест 13
bool test13() {
  Candle candle(110.0, 120.0, 90.0, 100.0); // Красная свеча (open > close)
  return candle.is_red(); // Ожидается true, так как open > close
}

//тест 14
bool test14() {
  Candle candle(100.0, 120.0, 90.0, 100.0); // Нейтральная свеча (open == close)
  return !candle.is_red(); // Ожидается false, так как цена открытия равна цене закрытия
}

//тест 14
bool test15() {
  Candle candle(100.0, 120.0, 90.0, 110.0); // Зеленая свеча (open > close)
  return !candle.is_red(); // Ожидается false, так как open > close
}

void initTests()
{
  tests.push_back(test1);
  tests.push_back(test2);
  tests.push_back(test3);
  tests.push_back(test4);
  tests.push_back(test5);
  tests.push_back(test6);
  tests.push_back(test7);
  tests.push_back(test8);
  tests.push_back(test9);
  tests.push_back(test10);
  tests.push_back(test11);
  tests.push_back(test12);
  tests.push_back(test13);
  tests.push_back(test14);
  tests.push_back(test15);
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

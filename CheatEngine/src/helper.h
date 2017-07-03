#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <iostream>

// Declarations
template <class T, class Pred>
T ask_for(const std::string& message, const std::string& error, Pred predicate);

template <class T>
T ask_for(const std::string& message, const std::string& error);



// Definitions
template <class T, class Pred>
T ask_for(const std::string& message, const std::string& error, Pred verification) {
  static const char PROMPT = ':';
  T t;
  std::cout << message << PROMPT << " ";
  while (!(std::cin >> t) || !verification(t)) {
    std::cerr << error << std::endl;
    std::cout << message << PROMPT << " ";

    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore(std::cin.rdbuf()->in_avail());
    }
  }

  return t;
}

template <class T>
T ask_for(const std::string& message, const std::string& error) {
  return ask_for<T>(message, error, [](const T& t) { return true; });
}

#endif

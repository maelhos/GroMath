#pragma once

#define DEBUG

#include <iostream>
#include <string>
#include <stdbool.h>
#include <signal.h>
#include <vector>
#include <memory>
#include <variant>
#include <sstream>

// helper type for the visitor #4
template<class... Ts>
struct overloaded : Ts... { using Ts::operator()...; };
// explicit deduction guide (not needed as of C++20)
template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

template<typename ...Fs>
auto make_overloaded(Fs ... fs) {
return overloaded<Fs ...>(fs ...);
}

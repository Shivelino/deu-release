/*********************************************************************
 * @file    rand.h    
 * @brief   
 * @details  
 * @author  Shivelino
 * @date
 * @version 
 * @par Copyright(c): 
 * @par todo:
 * @par history: 
 *********************************************************************/
#pragma once
#include <iostream>
#include <random>
#include <unordered_set>

#include "metaprogramming/concepts.hpp"

namespace ceu {

/**
 * @brief   random int.
 * @details [min, max]
 * @return   
 * @par todo:
 * @par history: 
 */
inline int rand_int(int num1, int num2) {
    int min_limit = std::min(num1, num2);
    int max_limit = std::max(num1, num2);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min_limit, max_limit);
    return distribution(gen);
}

inline int rand_int() {
    return rand_int(INT_MIN, INT_MAX);
}

template <typename _Ty>
    requires std::is_arithmetic_v<_Ty>
inline _Ty random(_Ty num1, _Ty num2) {
    _Ty min_limit = std::min(num1, num2);
    _Ty max_limit = std::max(num1, num2);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<_Ty> distribution(min_limit, max_limit);
    return distribution(gen);
}

template <typename _Ty>
    requires std::is_arithmetic_v<_Ty>
class RandomGenerator {
private:
    _Ty _min_limit;
    _Ty _max_limit;
    std::mt19937 _gen;
    std::uniform_int_distribution<_Ty> _distribution;

public:
    RandomIntegralGenerator(_Ty num1, _Ty num2) {
        _min_limit = std::min(num1, num2);
        _max_limit = std::max(num1, num2);
        std::random_device rd;
        _gen = std::mt19937(rd());
        _distribution = std::uniform_int_distribution<_Ty>(_min_limit, _max_limit);
    }

public:
    _Ty random() { return _distribution(_gen); }

    _Ty random(_Ty except_num) {
        _Ty num;
        do
            num = _distribution(_gen);
        while (num == except_num);
        return num;
    }

    _Ty random(const std::vector<_Ty>& except_nums) {
        std::unordered_set<_Ty> except_nums_hashset;
        for (_Ty n : except_nums)
            except_nums_hashset.insert(n);

        _Ty num;
        do
            num = _distribution(_gen);
        while (except_nums_hashset.find(num) != except_nums_hashset.end());
        return num;
    }
};

/**
 * @brief   random string.
 * @details  1. MAX length of random string is 1024
 * @param[in] length: string length
 * @return   
 * @par todo:
 * @par history: 
 */
inline std::string rand_string(int length) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, characters.size() - 1);

#define _RAND_STRING_MAX_LENGTH 1024
    length = std::min(length, _RAND_STRING_MAX_LENGTH);
#undef _RAND_STRING_MAX_LENGTH

    std::string random_string = std::string(length, 'a');  // initialize
    for (int i = 0; i < length; ++i) {
        random_string[i] = characters[distribution(gen)];
    }

    return random_string;
}

inline char rand_char() {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, characters.size() - 1);
    return characters[distribution(gen)];
}

}  // namespace ceu

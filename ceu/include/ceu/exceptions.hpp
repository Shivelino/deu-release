/*********************************************************************
 * @file    exceptions.hpp    
 * @brief   
 * @details  
 * @author  Shivelino
 * @date    2024.8.22
 * @version 
 * @par Copyright(c): 
 * @par todo:
 *  1, gcc std::exception does not have constructor 
 *     `std::exception(const char*)`
 * @par history: 
 *********************************************************************/
#pragma once
#include <cstdio>
#include <exception>

#include "macro.hpp"

namespace ceu {

// declare ErrorCode. ERROR_CODE = EXCEPTION_CODE + 64
#define _CEU_DECLARE_ECODE(_ecode_base, _except_code) CEU_CAT(Exception, _ecode_base) = _except_code, CEU_CAT(Error, _ecode_base) = _except_code + 0x40

/**
 * @brief Error and Exception Code.
 * @note 保证在uint8_t范围内
 */
enum class ErrorCode {
    NoErr = 0,
    // exception: 64(0b01000000)-127(0b01111111)
    // error: 128(0b10000000)-191(0b10111111)
    // ERROR_CODE = EXCEPTION_CODE + 64
    _CEU_DECLARE_ECODE(Unknown, 64),
    _CEU_DECLARE_ECODE(Type, 65),
    // reserved: 192(0b11000000)-254(0b11111110)
    Undefined = 192,
    // unknown
    Unknown = 255
};

#undef _CEU_DECLARE_ECODE

/**
 * @brief 判断是否是exception或error
 */
ALWAYS_INLINE_FUNCTION bool is_no_err(ErrorCode code) {
    return !(uint8_t)code;
}

/**
 * @brief 判断是否是exception.
 */
ALWAYS_INLINE_FUNCTION bool is_exception(ErrorCode code) {
    return !((uint8_t)code & 0xC0 ^ 0x40);
}

/**
 * @brief 判断是否是error.
 */
ALWAYS_INLINE_FUNCTION bool is_error(ErrorCode code) {
    return !((uint8_t)code & 0xC0 ^ 0x80);
}

/**
 * @brief throwable基类.
 */
class Throwable {
protected:
    ErrorCode _code = ErrorCode::Unknown;  // Ecode

    class ThrowableImpl : public std::exception {
    public:
        inline ThrowableImpl() noexcept :
            std::exception() {}

        inline ThrowableImpl(const char* msg) noexcept :
            std::exception(msg) {}
    };

    ThrowableImpl* _impl;

public:
    inline Throwable() noexcept { _impl = new ThrowableImpl(); }

    inline Throwable(const char* msg) noexcept { _impl = new ThrowableImpl(msg); }

    inline Throwable(ErrorCode code, const char* msg) noexcept :
        _code(code) {
        _impl = new ThrowableImpl(msg);
    }

    inline Throwable(const Throwable& other) {
        _code = other._code;
        _impl = new ThrowableImpl(other.what());
    }

    inline Throwable& operator=(const Throwable& other) noexcept {
        if (this == &other)
            return *this;
        _code = other._code;
        delete _impl;
        _impl = new ThrowableImpl(other.what());
        return *this;
    }

    inline virtual ~Throwable() noexcept { delete _impl; }

public:
    [[nodiscard]] inline virtual void print() noexcept { printf("ErrorCode: %d. %s\n", _code, what()); }

    [[nodiscard]] inline virtual ErrorCode ecode() noexcept { return _code; }

    [[nodiscard]] inline virtual char const* what() const { return _impl->what(); }
};

/**
 * @brief 异常基类.
 */
class Exception : public Throwable {
public:
    inline Exception() noexcept :
        Throwable() {}

    inline Exception(const char* msg) noexcept :
        Throwable(msg) {}

    inline Exception(ErrorCode code, const char* msg) noexcept :
        Throwable(code, msg) {}
};

/**
 * @brief 错误基类.
 */
class Error : public Throwable {
public:
    inline Error() noexcept :
        Throwable() {}

    inline Error(const char* msg) noexcept :
        Throwable(msg) {}

    inline Error(ErrorCode code, const char* msg) noexcept :
        Throwable(code, msg) {}
};

/**
 * @brief 根据base生成对应ErrorCode的异常和错误类
 */
#define _CEU_DECLARE_CUSTOM_THROW(_ecode_base)                             \
    class CEU_CAT(Exception, _ecode_base) :                                \
        public Exception {                                                 \
    public:                                                                \
        inline CEU_CAT(Exception, _ecode_base)() noexcept :                \
            Exception() {                                                  \
            _code = CEU_CAT(ErrorCode::Exception, _ecode_base);            \
        }                                                                  \
        inline CEU_CAT(Exception, _ecode_base)(const char* msg) noexcept : \
            Exception(msg) {                                               \
            _code = CEU_CAT(ErrorCode::Exception, _ecode_base);            \
        }                                                                  \
    };                                                                     \
    class CEU_CAT(Error, _ecode_base) :                                    \
        public Error {                                                     \
    public:                                                                \
        inline CEU_CAT(Error, _ecode_base)() noexcept :                    \
            Error() {                                                      \
            _code = CEU_CAT(ErrorCode::Error, _ecode_base);                \
        }                                                                  \
        inline CEU_CAT(Error, _ecode_base)(const char* msg) noexcept :     \
            Error(msg) {                                                   \
            _code = CEU_CAT(ErrorCode::Error, _ecode_base);                \
        }                                                                  \
    }

_CEU_DECLARE_CUSTOM_THROW(Type);  // Type异常和错误

#undef _CEU_DECLARE_CUSTOM_THROW
}  // namespace ceu

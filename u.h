/* assume standards compliant compiler. */
#ifndef LOCAL_U_H
#define LOCAL_U_H
#if defined(__cplusplus)
extern "C" {
#endif

#include <stddef.h> /* for size_t, ptrdiff_t, NULL, offsetof */
#include <stdint.h> /* for int8_t, int16_t, int32_t, int64_t */

/* nil: nullptr for C++11/C23, NULL otherwise. */
#ifndef nil
# if (defined(__cplusplus) && __cplusplus >= 201103L) \
    || (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 202311L))
#  define nil nullptr
# else
#  define nil NULL
# endif
#endif

/* bool: use built-in or stdbool.h, fallback to typedef enum. */
#if defined(__cplusplus)
  /* C++ has built-in bool. */
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
# include <stdbool.h> /* for bool, true, false */
#elif !defined(bool)
  typedef enum {
    false = (1 == 0),
    true = (!false)
  } bool;
#endif

/* PROC_NAME: function name macro. */
#ifndef PROC_NAME
# if defined(__func__)
#  define PROC_NAME __func__
# elif defined(__FUNCTION__)
#  define PROC_NAME __FUNCTION__
# else
#  define PROC_NAME "(unknown)"
# endif
#endif

/* INLINE: portable inline macro. */
#ifndef INLINE
# if defined(__cplusplus) \
  || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)
#  define INLINE inline
# elif defined(_MSC_VER)
#  define INLINE __inline
# elif defined(__GNUC__)
#  define INLINE __inline__
# else
#  define INLINE
# endif
#endif

/* countof: number of elements in a static array. */
#ifndef countof
# define countof(a) (sizeof(a) / sizeof((a)[0]))
#endif

/* containerof: get pointer to containing struct from member pointer. */
#ifndef containerof
# define containerof(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))
#endif

/* UNUSED: silence unused variable warnings. */
#ifndef UNUSED
# define UNUSED(x) (void)(x)
#endif

/* likely/unlikely: branch prediction hints. */
#ifndef likely
# if defined(__GNUC__) || defined(__clang__)
#  define likely(x)   __builtin_expect(!!(x), 1)
#  define unlikely(x) __builtin_expect(!!(x), 0)
# else
#  define likely(x)   (x)
#  define unlikely(x) (x)
# endif
#endif

/* Integer typedefs: only if not already defined. */
#ifdef UINT8_MAX
# ifndef i8
  typedef int8_t  i8;
# endif
# ifndef u8
  typedef uint8_t u8;
# endif
#endif

#ifdef UINT16_MAX
# ifndef i16
  typedef int16_t  i16;
# endif
# ifndef u16
  typedef uint16_t u16;
# endif
#endif

#ifdef UINT32_MAX
# ifndef i32
  typedef int32_t  i32;
# endif
# ifndef u32
  typedef uint32_t u32;
# endif
#endif

#ifdef UINT64_MAX
# ifndef i64
  typedef int64_t  i64;
# endif
# ifndef u64
  typedef uint64_t u64;
# endif
#endif

#ifndef usize
typedef size_t    usize;
#endif
#ifndef isize
typedef ptrdiff_t isize;
#endif

#ifndef ichar
typedef signed char ichar;
#endif
#ifndef uchar
typedef unsigned char uchar;
#endif
#ifndef ushort
typedef unsigned short ushort;
#endif
#ifndef uint
typedef unsigned int uint;
#endif
#ifndef ulong
typedef unsigned long ulong;
#endif
#ifndef vlong
typedef long long vlong;
#endif
#ifndef uvlong
typedef unsigned long long uvlong;
#endif

#if defined(__cplusplus)
}
#endif
#endif /* LOCAL_U_H */

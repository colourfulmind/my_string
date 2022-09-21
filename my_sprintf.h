#ifndef MY_SPRINTF_H_
#define MY_SPRINTF_H_

#include "my_string.h"

#ifdef __APPLE__
#define int8 long int
#else
#define int8 long long
#endif

#define MAX_WIDTH 127

typedef struct format_type {
  char left_alignment;
  char sign;
  char space;
  char diez;
  char zero;
  char up;
  char e;
  char g;
  int radix;
  int width;
  int precision;
} format_type;

int my_sprintf(char* str, const char* format, ...);
long long int minOf(long long int a, long long int b);

int my_get_default_precision(char specificator);

const char* my_processing_sprintf_flags(const char* str, format_type* flags);

const char* my_set_format_data(format_type* format_data, const char* str,
                                va_list* args);

const char* my_get_width_or_precision(const char* str, int* width_or_precision,
                                       va_list* args);

const char* my_get_width_or_precision_from_argument(const char* str,
                                                     int* width_or_precision,
                                                     va_list* args);

const char* my_get_width_or_precision_from_format(const char* str,
                                                   int* width_or_precision);

my_size_t my_change_buffer_size_by_param(my_size_t width,
                                           my_size_t precision, int sign,
                                           int buffer_size);

my_size_t my_get_buf_size_uint(my_size_t width, my_size_t precision,
                                 unsigned long int unsigned_value,
                                 my_size_t radix, int sign);

my_size_t my_get_buf_size_int(my_size_t width, my_size_t precision,
                                long int value, int sign);

my_size_t my_transformation_from_int_to_str(char* dest,
                                              format_type format_data,
                                              long int value, my_size_t bsize);

char* my_print_int(char* tar, format_type format_data, char bytec,
                    va_list* args);

format_type my_set_radix(format_type format_data, char specificator);

char* my_print_uint(char* tar, format_type format_data, char bytec,
                     va_list* args);

my_size_t my_transformation_from_unsigned_to_str(char* dest,
                                                   format_type format_data,
                                                   unsigned long int value,
                                                   my_size_t bsize);

char* my_print_char(char* str, format_type format_data, va_list* args);

char* my_print_str(char* str, format_type format_data, char bytec,
                    va_list* args);

char* my_set_symbols_to_string(char* str, int width, char symbol,
                                int start_index);

int my_normalize_value(long double* value);

char* my_print_ptr(char* str, format_type format_data, va_list* args);

format_type my_set_precision_for_g_specificator(format_type format_data,
                                                 long double value);

my_size_t my_get_buf_size_flt(my_size_t width, my_size_t precision,
                                long double value, int sign);

char my_get_num_char(int num, int up);

my_size_t my_handling_non_finite_numbers(char* str, long double value,
                                           int upper);

my_size_t my_float_to_str(char* str, format_type format_data,
                            long double value, my_size_t bsize);

char* my_proseccing_specificator(char* str, char* old, const char* format_str,
                                  format_type format_data, va_list* args);

#endif  // MY_SPRINTF_H_

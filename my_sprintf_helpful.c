#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "my_sprintf.h"
#include "my_string.h"

// char specs[] = "diuoxXcsnpfFeEgG%";

// обработка флагов сспринтф
const char* my_processing_sprintf_flags(const char* str, format_type* flags) {
  while (str) {
    if (*str == '+')
      flags->sign = 1;
    else if (*str == '-')
      flags->left_alignment = 1;
    else if (*str == '#')
      flags->diez = 1;
    else if (*str == ' ')
      flags->space = 1;
    else if (*str == '0')
      flags->zero = 1;
    else
      break;
    str++;
  }
  // вставляем пробел перед значением, если нет флага знака
  flags->space = flags->space && !flags->sign;
  // вставляем нули перед числом, если нет выравнивания по левому краю
  flags->zero = flags->zero && !flags->left_alignment;
  return str;
}
// получение ширины, если стоит * , то ширина поля указывается в списке
// аргументов перед значением для вывода
const char* my_get_width_or_precision(const char* str, int* width_or_precision,
                                       va_list* args) {
  *width_or_precision = 0;
  if (*str == '*') {
    // получение ширины из аргумента
    str =
        my_get_width_or_precision_from_argument(str, width_or_precision, args);
  } else {
    // получение ширины из формата
    str = my_get_width_or_precision_from_format(str, width_or_precision);
  }
  return str;
}

// получение ширины, если стоит * , то ширина поля указывается в списке
// аргументов перед значением для вывода
const char* my_get_width_or_precision_from_argument(const char* str,
                                                     int* width_or_precision,
                                                     va_list* args) {
  // получение ширины из аргумента
  *width_or_precision = va_arg(*args, int);
  if (abs(*width_or_precision) > MAX_WIDTH) {
    if (*width_or_precision > 0) {
      *width_or_precision = MAX_WIDTH;
    } else {
      *width_or_precision = -MAX_WIDTH;
    }
  }
  str++;
  return str;
}

// получение ширины и точности из формата
const char* my_get_width_or_precision_from_format(const char* str,
                                                   int* width_or_precision) {
  // получение ширины из формата
  while (str) {
    if ('0' <= *str && *str <= '9') {
      // перевод числа из строки в инт
      int tmp_width_or_precision = (*width_or_precision) * 10 + *str - 48;
      if (tmp_width_or_precision <= MAX_WIDTH) {
        *width_or_precision = tmp_width_or_precision;
      } else {
        *width_or_precision = MAX_WIDTH;
      }
    } else {
      break;
    }
    str++;
  }
  return str;
}
// изменение буфера в зависимости от ширины, точности и знака
my_size_t my_change_buffer_size_by_param(my_size_t width,
                                           my_size_t precision, int sign,
                                           int buffer_size) {
  buffer_size += sign;
  precision += sign;
  my_size_t result = buffer_size;
  if (width > result || precision > result) {
    if (precision > result) {
      result = precision;
    } else {
      result = width;
    }
  }
  return result;
}
// получение размера буфера для знакового инта
my_size_t my_get_buf_size_int(my_size_t width, my_size_t precision,
                                long int value, int sign) {
  my_size_t buff_size = 0;
  while (value != 0) {
    value /= 10;
    buff_size++;
  }
  my_size_t output_result =
      my_change_buffer_size_by_param(width, precision, sign, buff_size);
  return output_result;
}
// получение буфера для беззнакового инта
my_size_t my_get_buf_size_uint(my_size_t width, my_size_t precision,
                                 unsigned long int unsigned_value,
                                 my_size_t radix, int sign) {
  my_size_t buff_size = 0;
  while (unsigned_value != 0) {
    unsigned_value /= radix;
    buff_size++;
  }
  my_size_t output_result =
      my_change_buffer_size_by_param(width, precision, sign, buff_size);
  return output_result;
}
// получение размера буфера для флоата
my_size_t my_get_buf_size_flt(my_size_t width, my_size_t precision,
                                long double value, int sign) {
  my_size_t float_buff = 1 + (precision > 0);
  // пока число больше 0 и является конечным числом
  while (fabsl(value) - 1.0 >= 0 && isfinite(value)) {
    value /= 10.0;
    float_buff++;
  }
  float_buff += precision + sign;
  if (!isfinite(value)) {
    float_buff = 5;
  }
  if (width > float_buff) {
    float_buff = width;
  }
  return float_buff;
}
// возвращает число в зависимости от системы счисления
char my_get_num_char(int num, int up) {
  char number_in_16 = ' ';
  if (0 <= num && num <= 9) {
    number_in_16 = num + 48;
  } else if (num == 10) {
    number_in_16 = 'a' - up * 32;
  } else if (num == 11) {
    number_in_16 = 'b' - up * 32;
  } else if (num == 12) {
    number_in_16 = 'c' - up * 32;
  } else if (num == 13) {
    number_in_16 = 'd' - up * 32;
  } else if (num == 14) {
    number_in_16 = 'e' - up * 32;
  } else if (num == 15) {
    number_in_16 = 'f' - up * 32;
  } else {
    number_in_16 = '?';
  }
  return number_in_16;
}
// обработка nan, inf, -inf
my_size_t my_handling_non_finite_numbers(char* str, long double value,
                                           int upper) {
  my_size_t output_buffer = 0;
  if (isnan(value)) {
    if (upper) {
      my_strcpy(str, "NAN");
    } else {
      my_strcpy(str, "nan");
    }
    output_buffer = 3;
  } else if (value == INFINITY) {
    if (upper) {
      my_strcpy(str, "FNI");
    } else {
      my_strcpy(str, "fni");
    }
    output_buffer = 4;
  } else if (value == -INFINITY) {
    if (upper) {
      my_strcpy(str, "FNI-");
    } else {
      my_strcpy(str, "fni-");
    }
    output_buffer = 5;
  } else {
    output_buffer = 0;
  }
  return output_buffer;
}
// установка данных о формате
const char* my_set_format_data(format_type* format_data, const char* str,
                                va_list* args) {
  // обработка флагов спринтф
  str = my_processing_sprintf_flags(str, format_data);
  // получение ширины, если она есть
  str = my_get_width_or_precision(str, &(format_data->width), args);
  if (*str == '.') {
    str++;
    // получение точности, если она есть
    str = my_get_width_or_precision(str, &(format_data->precision), args);
  }
  if (format_data->width < 0) {
    // если ширина отрицательная, то надо выравнять по левому краю
    format_data->width = -format_data->width;
    format_data->left_alignment = 1;
  }
  if (format_data->precision < 0) {
    // сигнализируем о последующей установке дефолтного значения
    format_data->precision = -1;
  }
  return str;
}

// установка точности, если после точки нет значения
int my_get_default_precision(char specificator) {
  int precision = -1;
  // diuoxXcsnpfFeEgG%
  switch (specificator) {
    case 'd':
    case 'i':
    case 'u':
    case 'o':
    case 'x':
    case 'X':
    case 'p':
      precision = 1;
      break;
    case 'f':
    case 'F':
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case '%':
      precision = 6;
      break;
  }
  return precision;
}
// нормализация числа и возврат степени десятки
int my_normalize_value(long double* value) {
  int ten_power = 0;
  if (*value) {
    if (fabsl(*value) < 1.0) {
      for (; fabsl(*value) < 1.0; ten_power--) {
        *value = *value * 10;
      }
    } else if (fabsl(*value) >= 10.0) {
      for (; fabsl(*value) >= 10.0; ten_power++) {
        *value = *value / 10;
      }
    }
  }
  return ten_power;
}
// установка системы счисления
format_type my_set_radix(format_type format_data, char specificator) {
  switch (specificator) {
    case 'o':
      format_data.radix = 8;
      break;
    case 'x':
      format_data.radix = 16;
      break;
    case 'X':
      format_data.radix = 16;
      format_data.up = 1;
      break;
  }
  return format_data;
}
// установка форматов g, e, G, E, F

// format_type my_set_scientific(format_type format_data, char specificator) {
//     switch (specificator) {
//         case 'g':
//             format_data.g = 1;
//             break;
//         case 'e':
//             format_data.e = 1;
//             break;
//         case 'G':
//             format_data.g = 1;
//             format_data.up = 1;
//             break;
//         case 'E':
//             format_data.e = 1;
//             format_data.up = 1;
//             break;
//         case 'F':
//             format_data.up = 1;
//             break;
//     }
//     return format_data;
// }

// установка точности для типа g
format_type my_set_precision_for_g_specificator(format_type format_data,
                                                 long double value) {
  int ten_power = my_normalize_value(&value);
  if (!format_data.precision) {
    format_data.precision = 1;
  }
  //преобразуется в %e если экспонента меньше чем -4 или больше или равна
  //точностию Иначе - как %f .
  if (ten_power < -4 || ten_power >= format_data.precision) {
    format_data.e = 1;
    format_data.precision -= 1;
  } else {
    format_data.precision = format_data.precision - ten_power - 1;
  }
  return format_data;
}
// преобразование числа в строку
my_size_t my_transformation_from_int_to_str(char* dest,
                                              format_type format_data,
                                              long int value,
                                              my_size_t bsize) {
  my_size_t i = 0;
  long double absolute_value = fabsl((long double)value);
  int sign = format_data.sign || format_data.space || value < 0;
  for (; i < bsize && absolute_value >= 1.0; i++, absolute_value /= 10) {
    dest[i] = fmodl(absolute_value, 10.0l) + 48;
  }
  for (; (i + sign < (my_size_t)format_data.width && format_data.zero) ||
         i < (my_size_t)format_data.precision;
       i++) {
    dest[i] = '0';
  }

  if (format_data.space && value >= 0) {
    dest[i++] = ' ';
  }
  if (value < 0) {
    dest[i++] = '-';
  }
  if (format_data.sign && value > 0) {
    dest[i++] = '+';
  }
  for (; i < (my_size_t)format_data.width && !format_data.left_alignment;
       i++) {
    dest[i] = ' ';
  }
  return i;
}
// преобразование беззнакового числа в строку
my_size_t my_transformation_from_unsigned_to_str(char* str,
                                                   format_type format_data,
                                                   unsigned long int value,
                                                   my_size_t bsize) {
  my_size_t i = 0;
  unsigned long int tmp_value = value;
  // int sign = (((format_data.space && format_data.radix == 10) ||
  // (format_data.diez && format_data.radix == 8)) + 2*(format_data.diez &&
  // format_data.radix == 16));
  int sign = 0;
  if (format_data.space && format_data.radix == 10) {
    sign = 1;
  } else if (format_data.diez && format_data.radix == 8) {
    sign = 1;
  } else if (format_data.diez && format_data.radix == 16) {
    sign = 2;
  }
  for (sign *= (value != 0); i < bsize && tmp_value > 0;
       i++, tmp_value /= format_data.radix) {
    str[i] = my_get_num_char(tmp_value % format_data.radix, format_data.up);
  }
  my_size_t correct_width = 0;
  if ((long long int)format_data.width > (long long int)format_data.precision) {
    correct_width = (my_size_t)format_data.width;
  } else {
    correct_width = (my_size_t)format_data.precision;
  }
  for (; ((i + sign < correct_width && format_data.zero &&
           (format_data.precision - 1))) ||
         (i + format_data.diez * (format_data.radix == 8) <
          (my_size_t)format_data.precision) ||
         (i + sign < (my_size_t)format_data.width && format_data.zero &&
          !(format_data.precision - 1));
       i++) {
    str[i] = '0';
  }

  if (value || format_data.g) {
    if (format_data.diez && format_data.radix == 16 && format_data.up) {
      str[i++] = 'X';
    } else if (format_data.diez && format_data.radix == 16 && !format_data.up) {
      str[i++] = 'x';
    }
    if (format_data.diez && format_data.radix != 10) {
      str[i++] = '0';
    }
  }

  for (; i < (my_size_t)format_data.width && !format_data.left_alignment;
       i++) {
    str[i] = ' ';
  }
  return i;
}
// запись типа float в строку
my_size_t my_float_to_str(char* str, format_type format_data,
                            long double value, my_size_t bsize) {
  // signbit - макрос, определяющий знак числа (0 - если число >= 0, иначе
  // отличное от нуля значение)
  int sign_value = signbit(value);
  // обработка inf, nan
  my_size_t size_buf =
      my_handling_non_finite_numbers(str, value, format_data.up);
  if (!size_buf) {
    long double whol, frac;
    frac = modfl(value, &whol);
    frac = roundl(fabsl(frac) * powl(10.0l, format_data.precision));
    if (format_data.g && !format_data.diez) {
      for (; (int)frac % 10 == 0 && frac > 0;
           frac /= 10.0l, format_data.precision--) {
      }
    }
    if (format_data.g && !frac) {
      format_data.precision = 0;
    }
    if (format_data.precision) {
      for (; size_buf < bsize && size_buf < (my_size_t)format_data.precision;
           size_buf++, frac /= 10.0l) {
        str[size_buf] = (int)(frac - floorl(frac / 10.0l) * 10.0l) + 48;
      }
      str[size_buf++] = '.';
    }
    for (whol = roundl(fabsl(whol) + frac * (format_data.precision == 0));
         size_buf < bsize && whol >= 10.0l; size_buf++, whol /= 10.0l) {
      str[size_buf] = (int)(whol - floorl(whol / 10.0l) * 10.0l) + 48;
    }
    str[size_buf++] = (int)whol + 48;
    for (; size_buf + (format_data.sign || format_data.space || value < 0) +
                   4 * format_data.e <
               (my_size_t)format_data.width &&
           format_data.zero;
         size_buf++) {
      str[size_buf] = '0';
    }
    if (format_data.space && value >= 0) {
      str[size_buf++] = ' ';
    }
    if (value < 0 || sign_value) {
      str[size_buf++] = '-';
    }
    if (format_data.sign && value > 0) {
      str[size_buf++] = '+';
    }
    for (; size_buf + 4 * format_data.e < (my_size_t)format_data.width &&
           !format_data.left_alignment;
         size_buf++) {
      str[size_buf] = ' ';
    }
  } else {
    if (format_data.space && value >= 0) {
      str[size_buf++] = ' ';
    }
    if (format_data.sign && value > 0) {
      str[size_buf++] = '+';
    }
    for (; size_buf + 4 * format_data.e < (my_size_t)format_data.width &&
           !format_data.left_alignment;
         size_buf++) {
      str[size_buf] = ' ';
    }
  }
  return size_buf;
}

// получение из i и d строки
char* my_print_int(char* str, format_type format_data, char bytec,
                    va_list* args) {
  long int value;
  // определить как long int, short int или int
  if (bytec == 'l') {
    value = (long int)va_arg(*args, long int);
  } else if (bytec == 'h') {
    value = (short)va_arg(*args, int);
  } else {
    value = (int)va_arg(*args, int);
  }
  my_size_t bsize = my_get_buf_size_int(
      format_data.width, format_data.precision, value,
      format_data.sign || format_data.space || (value < 0));
  char* buffer = malloc(bsize);
  int i = my_transformation_from_int_to_str(buffer, format_data, value, bsize);
  for (int j = i - 1; j >= 0; j--) {
    *str = buffer[j];
    str++;
  }
  str = my_set_symbols_to_string(str, format_data.width, ' ', i);
  free(buffer);
  return str;
}
// преобразование из беззнакового целого в строку
char* my_print_uint(char* str, format_type format_data, char bytec,
                     va_list* args) {
  unsigned long int value;
  if (bytec == 'l') {
    value = (unsigned long int)va_arg(*args, unsigned long int);
  } else if (bytec == 'h') {
    value = (unsigned short)va_arg(*args, unsigned int);
  } else {
    value = (unsigned int)va_arg(*args, unsigned int);
  }
  my_size_t bsize = my_get_buf_size_uint(
      format_data.width, format_data.precision, value, format_data.radix,
      format_data.space + format_data.diez + (format_data.radix == 16));
  char* buffer = malloc(bsize);
  int i = my_transformation_from_unsigned_to_str(buffer, format_data, value,
                                                  bsize);
  for (int j = i - 1; j >= 0; j--, str++) {
    *str = buffer[j];
  }
  str = my_set_symbols_to_string(str, format_data.width, ' ', i);
  free(buffer);
  return str;
}
// обработка f, e, E, g, G в строку
char* my_print_float(char* str, format_type format_data, char L,
                      va_list* args) {
  long double value;
  int e;
  if (L == 'L') {
    value = va_arg(*args, long double);
  } else {
    value = va_arg(*args, double);
  }
  if (format_data.g) {
    format_data = my_set_precision_for_g_specificator(format_data, value);
  }
  if (format_data.e) {
    e = my_normalize_value(&value);
  }
  my_size_t bsize = my_get_buf_size_flt(
      format_data.width, format_data.precision, value,
      format_data.sign || format_data.space || (value < 0));
  char* buffer = malloc(bsize);
  int i = my_float_to_str(buffer, format_data, value, bsize);
  for (int j = i - 1; j >= 0; j--, str++) {
    *str = buffer[j];
  }
  if (format_data.e) {
    *(str++) = 'e' - format_data.up * 32;
    *(str++) = '-' * (e < 0) + '+' * (e >= 0);
    *(str++) = abs(e / 10) + 48;
    *(str++) = abs(e % 10) + 48;
  }
  for (; i + 4 * format_data.e < format_data.width; i++, str++) {
    *str = ' ';
  }
  free(buffer);
  return str;
}
// получение из сhar строки
char* my_print_char(char* str, format_type format_data, va_list* args) {
  int char_code = va_arg(*args, int);
  if (!format_data.left_alignment) {
    str = my_set_symbols_to_string(str, format_data.width - 1, ' ', 0);
  }
  *str = '\0';
  if (char_code <= UCHAR_MAX) {
    *(str++) = char_code;
  } else {
    return MY_NULL;
  }
  if (format_data.left_alignment) {
    str = my_set_symbols_to_string(str, format_data.width - 1, ' ', 0);
  }
  return str;
}
// установка определенных символов в строку
char* my_set_symbols_to_string(char* str, int width, char symbol,
                                int start_index) {
  for (int i = start_index; i < width; i++, str++) {
    *str = symbol;
  }
  return str;
}

// получение из s строки
char* my_print_str(char* str, format_type format_data, char bytec,
                    va_list* args) {
  char* str_value = va_arg(*args, char*);
  if (str_value) {
    int str_width = format_data.width;
    if (format_data.precision != -1 &&
        (my_strlen(str_value) < (my_size_t)format_data.precision)) {
      str_width -= my_strlen(str_value);
    } else if (str_width > 0) {
      if (my_strlen(str_value) <= (my_size_t)format_data.precision) {
        str_width -= my_strlen(str_value);
      } else {
        str_width -= format_data.precision;
      }
    } else if (format_data.precision != -1) {
      str_width -= format_data.precision;
    }
    if (!format_data.left_alignment) {
      str = my_set_symbols_to_string(str, str_width, ' ', 0);
    }
    for (int i = 0;
         ((i < format_data.precision && format_data.precision != -1) ||
          format_data.precision == -1) &&
         *str_value;
         i++, str++) {
      if (bytec == 'l') {
        // wchar_t - широкий символ
        if (*((wchar_t*)str_value) <= UCHAR_MAX) {
          *str = *str_value;
        } else {
          return MY_NULL;
        }
        str_value += sizeof(wchar_t);
      } else {
        *str = *str_value;
        str_value++;
      }
    }
    if (format_data.left_alignment) {
      str = my_set_symbols_to_string(str, str_width, ' ', 0);
    }

  } else {
    str = my_memcpy(str, "(null)", 6);
    str += 6;
  }
  return str;
}
// обработка p в строку
char* my_print_ptr(char* str, format_type format_data, va_list* args) {
  void* var = va_arg(*args, void*);
  unsigned long int ptr = (unsigned long int)var;
  format_data.radix = 16;
  format_data.g = 1;
  format_data.diez = 1;
  // вычисление объема памяти
  my_size_t bsize =
      my_get_buf_size_uint(format_data.width, format_data.precision, ptr,
                            format_data.radix, format_data.diez * 2);
  char* buffer = malloc(bsize);
  int i =
      my_transformation_from_unsigned_to_str(buffer, format_data, ptr, bsize);
  for (int j = i - 1; j >= 0; j--, str++) {
    *str = buffer[j];
  }
  str = my_set_symbols_to_string(str, format_data.width, ' ', i);
  free(buffer);
  return str;
}
//  получение спецификатора sprintf
char* my_proseccing_specificator(char* str, char* old, const char* format_str,
                                  format_type format_data, va_list* args) {
  int* n = MY_NULL;
  switch (*format_str) {
    case 'd':
    case 'i':
      str = my_print_int(str, format_data, *(format_str - 1), args);
      break;
    case 'u':
    case 'o':
    case 'x':
    case 'X':
      format_data = my_set_radix(format_data, *format_str);
      str = my_print_uint(str, format_data, *(format_str - 1), args);
      break;
    case 'c':
      str = my_print_char(str, format_data, args);
      break;
    case 's':
      str = my_print_str(str, format_data, *(format_str - 1), args);
      break;
    case 'p':
      str = my_print_ptr(str, format_data, args);
      break;
    case 'n':
      n = va_arg(*args, int*);
      *n = str - old;
      break;
    case 'f':
      str = my_print_float(str, format_data, *(format_str - 1), args);
      break;
    case 'F':
      format_data.up = 1;
      str = my_print_float(str, format_data, *(format_str - 1), args);
      break;
    case 'e':
      format_data.e = 1;
      str = my_print_float(str, format_data, *(format_str - 1), args);
      break;
    case 'E':
      format_data.e = 1;
      format_data.up = 1;
      str = my_print_float(str, format_data, *(format_str - 1), args);
      break;
    case 'g':
      format_data.g = 1;
      str = my_print_float(str, format_data, *(format_str - 1), args);
      break;
    case 'G':
      format_data.g = 1;
      format_data.up = 1;
      str = my_print_float(str, format_data, *(format_str - 1), args);
      break;
    case '%':
      *(str++) = *format_str;
      break;
    default:
      str = MY_NULL;
      break;
  }
  if (str != MY_NULL) {
    *str = '\0';
  }
  return str;
}

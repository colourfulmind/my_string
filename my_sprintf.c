#include "my_sprintf.h"

int my_sprintf(char *str, const char *format_str, ...) {
  char *old = str;
  va_list args;
  va_start(args, format_str);
  int output_result = 0;
  // если строка и значение формата не 0, парсим формат
  for (; *format_str && str; format_str++) {
    if (*format_str == '%') {
      // первоначально устанавливаем десятичную систему счисления и точность
      format_type format_data = {0, 0, 0, 0, 0, 0, 0, 0, 10, 0, -1};
      format_str++;
      format_str = my_set_format_data(&format_data, format_str, &args);
      // поиск спецификатора
      while (!my_strchr("diuoxXcsnpfFeEgG%", *format_str)) {
        format_str++;
      }
      // получение дефолтной точности при presicion == -1
      if (format_data.precision == -1) {
        format_data.precision = my_get_default_precision(*format_str);
      }
      str =
          my_proseccing_specificator(str, old, format_str, format_data, &args);
    } else {
      *(str++) = *format_str;
    }
  }
  va_end(args);
  if (!str) {
    output_result = -1;
  } else {
    *str = '\0';
    output_result = str - old;
  }
  return output_result;
}

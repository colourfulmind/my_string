#include "my_sscanf.h"

// Строка в целое число
long long int my_atoi(const char *str) {
  int i = 0;              //  текущая позиция в строке
  long long int res = 0;  //  Результат
  int sign = 1;           //  Здесь храним знак
  while (str[i] == '0' ||
         str[i] == ' ')  //  Убираем лидирующие (незначащие) нули и пробелы
    i++;
  if (str[i] == '-') {  // Сохраняем знак
    sign = -1;
    i++;
  }
  while ('0' <= str[i] && str[i] <= '9') {  //  Забираем все цифры
    res = res * 10 + ((int)str[i] - '0');  //  Собираем в res
    i++;
  }
  return res * sign;
}

//  Проверка корректности экспоненцияльной записи
int exp_num_error(const char *mass, const char **c) {
  int k = 0;
  if (mass[0] == '-' || mass[0] == '+') {  //  Если строка начинается с +/-
    k += 1;
  }
  while (mass[k] != '\0') {  //  Проверяем
    if (*c[0] == '.' && mass[k] == '.') {  //  Строка содержит десятичную точку
      k = -1;
      break;
    }
    //  Строка содержит знак
    if ((*c[0] == '+' || *c[0] == '-') && (mass[k] == '+' || mass[k] == '-')) {
      c[0] -= 1;
      c[0] -= 1;
      k = -1;
      break;
    }
    //  Строки содержат Е
    if ((*c[0] == 'e' || *c[0] == 'E') && (mass[k] == 'e' || mass[k] == 'E')) {
      c[0] -= 1;
      k = -1;
      break;
    }
    k++;
  }
  return k;
}

//  Забираем в *val значение из строки exp записи
void exp_num(char *mass, const char *format, ...) {
  for (int i = 0; i < (int)my_strlen(mass); i++) {
    if ((mass[i] == 'e' || mass[i] == 'E') &&
        (mass[i + 1] == '-' || mass[i + 1] == '+') &&
        (mass[i + 2] >= '0' && mass[i + 2] <= '9')) {
      char sign = mass[++i];
      i += 1;
      for (int j = 0; j < (int)my_strlen(mass); j++) {
        if (mass[i] >= '0' && mass[i] <= '9') {
          mass[j] = mass[i++];
        } else {
          mass[j] = '\0';
        }
      }
      va_list args;
      va_start(args, format);
      if (my_strcmp(format, "double") == 0) {
        double *val = va_arg(args, double *);
        if (sign == '+') {
          *val *= pow(10, my_atoi(mass));
        } else if (sign == '-') {
          *val /= pow(10, my_atoi(mass));
        }
      } else if (my_strcmp(format, "long double") == 0) {
        long double *val = va_arg(args, long double *);
        if (sign == '+') {
          *val *= pow(10, my_atoi(mass));
        } else if (sign == '-') {
          *val /= pow(10, my_atoi(mass));
        }
      } else if (my_strcmp(format, "float") == 0) {
        float *val = va_arg(args, float *);
        if (sign == '+') {
          *val *= pow(10, my_atoi(mass));
        } else if (sign == '-') {
          *val /= pow(10, my_atoi(mass));
        }
      }
      va_end(args);
      break;
    }
  }
}

char *str_to_mass(const char **str, char *mass, int *n, const char *format,
                  size_t i, int *error_code, int width) {
  while (*str[0] == ' ' || *str[0] == format[i]) {
    str[0]++;
    (*n)++;
  }
  int j = 0;
  if (mass[0] == '-') {
    j += 1;
  }
  int flag = 0;
  if (width != 0) {
    flag = 1;
  }
  if ((*str[0] == '+' || *str[0] == '-') &&
      (*(str[0] + 1) >= '0' && *(str[0] + 1) <= '9')) {
    if (flag == -1) {
    } else if (flag == 1 && width != 0) {
      if (*str[0] == '+') {
        width--;
        *(n) += 1;
        str[0] += 1;
      } else if (*str[0] == '-') {
        mass[j++] = *str[0]++;
        *(n) += 1;
        width--;
      }

    } else if (flag == 0) {
      mass[j++] = *str[0]++;
      *(n) += 1;
    }
  }
  if (mass[1] == '-') {
    mass[0] = '-';
    mass[1] = '0';
    j += 1;
  }

  if (flag == 1 && width == 0) {
    flag = -1;
  }
  if (*str[0] >= '0' && *str[0] <= '9') {
    if ((format[i] == 'f' || format[i + 1] == 'f' || format[i + 1] == 'g' ||
         format[i + 1] == 'G' || format[i + 1] == 'e' ||
         format[i + 1] == 'E') &&
        (*str[0] >= '0' && *str[0] <= '9')) {
      for (; *str[0] != ' '; j++) {
        if (*str[0] == '.' || *str[0] == 'E' || *str[0] == 'e' ||
            *str[0] == '+' || *str[0] == '-' ||
            (*str[0] >= '0' && *str[0] <= '9')) {
          if ((*str[0] == '+' || *str[0] == '-') &&
              (!(mass[j - 1] == 'e' || mass[j - 1] == 'E'))) {
            break;
          }
          if ((*str[0] == 'e' || *str[0] == 'E') &&
              (!(mass[j - 1] >= '0' && mass[j - 1] <= '9'))) {
            break;
          }
          if (flag == -1) {
            mass[0] = '\0';
            *error_code = -1;
            break;
          }
          if (*str[0] == '.' &&
              !(*(str[0] + 1) >= '0' && *(str[0] + 1) <= '9')) {
            str[0]++;
            (*n)++;
            break;
          }
          if (exp_num_error(mass, &str[0]) == -1) {
            break;
          }
          if (flag == 1 && width != 0) {
            mass[j] = *str[0]++;
            (*n)++;
            width--;
          } else if (flag == 0) {
            mass[j] = *str[0]++;
            (*n)++;
          } else if (flag == 1 && width == 0) {
            break;
          }
        } else {
          break;
        }
      }
    } else if (format[i] == 'd' || format[i + 1] == 'd' || format[i] == 'u' ||
               format[i + 1] == 'u' || format[i] == 'i' ||
               format[i + 1] == 'i') {
      for (; *str[0] != ' ' && (*str[0] >= '0' && *str[0] <= '9'); j++) {
        if (flag == -1) {
          mass[0] = '\0';
          *error_code = -1;
          break;
        }
        if (flag == 1 && width != 0) {
          mass[j] = *str[0]++;
          (*n)++;
          width--;
        } else if (flag == 0) {
          mass[j] = *str[0]++;
          (*n)++;
        } else if (flag == 1 && width == 0) {
          break;
        }
      }
    }
  } else {
    *error_code = -1;
  }
  return mass;
}

//  Строку в число с плавающей точкой
long double my_atof(const char *str) {
  int i = 0;
  long double res = 0;
  int sign = 1;
  while (str[i] == '0' || str[i] == ' ') i++;
  if (str[i] == '-') {
    sign = -1;
    i++;
  }
  if (str[i] == '+') {
    i++;
  }
  while ('0' <= str[i] && str[i] <= '9') {
    res = res * 10 + ((int)str[i] - '0');
    i++;
  }
  short precision = 0;
  if (str[i] == '.') {
    i++;
    while ('0' <= str[i] && str[i] <= '9') {
      res = res * 10 + ((int)str[i] - '0');
      i++;
      precision++;
    }
  }
  // printf("precision = %d\n", precision);
  res /= pow(10, precision);
  return res * sign;
}

// Разбираю число в восьмеричной системе счисления
int oct_pars(char **mass, const char **str, int *n, const char *format,
             size_t i, int *error_code, int width) {
  int flag = 0;
  int j = 0;
  while (*str[0] == ' ' || *str[0] == format[i]) {
    str[0]++;
    (*n)++;
  }
  int wi_flag = 0;
  if (width != 0) {
    wi_flag = 1;
  }
  if ((*str[0] == '+' || *str[0] == '-') &&
      (*(str[0] + 1) >= '0' && *(str[0] + 1) <= '9')) {
    if (wi_flag == 1 && width != 0) {
      if (*str[0] == '+') {
        str[0] += 1;
        (*n)++;
        width--;
      }
      if (*str[0] == '-') {
        mass[0][j++] = '-';
        str[0] += 1;
        *(n) += 1;
        width--;
      }
    } else if (wi_flag == 0) {
      mass[0][j++] = *str[0]++;
      *(n) += 1;
    }
  }
  if (wi_flag == 1 && width == 0) {
    wi_flag = -1;
  }
  mass[0][j++] = '0';
  if ((*str[0] >= '0' &&
       *str[0] <= '7')) {  // Для восьмеричной системы счисления
    if ((*str[0] == '0' && (*(str[0] + 1) >= '0' && *(str[0] + 1) <= '7')) ||
        ((format[i + 1] == 'o'))) {
      for (; (*str[0] >= '0' && *str[0] <= '7'); j++) {
        if (wi_flag == -1) {
          mass[0][0] = '\0';
          *error_code = -1;
          break;
        }
        if (*str[0] == ' ') {
          break;
        }
        if (wi_flag == 1 && width != 0) {
          mass[0][j] = *str[0]++;
          (*n)++;
          width--;
        } else if (wi_flag == 0) {
          mass[0][j] = *str[0]++;
          (*n)++;
        } else if (wi_flag == 1 && width == 0) {
          break;
        }
      }
    } else {
      flag = -1;
    }
  } else {
    *error_code = -1;
  }
  return flag;
}

// Конвертируем из строки восмеричное число в десятичное
long oct_to_dec(char *mass) {
  short sign = 1;
  long int oct = 0;
  int j = 0;
  if (mass[j++] == '-') {
    sign *= -1;
  }
  for (int i = (int)my_strlen(mass) - 2; i >= 0; i--) {
    oct += (mass[j++] - '0') * pow(8, i);
  }
  return oct * sign;
}

// Разбираю число в шестнадцатеричной системе счисления
int hex_pars(char **mass, const char **str, int *n, const char *format,
             size_t i, int *error_code, int width) {
  int flag = 0;
  int j = 0;
  while (*str[0] == ' ' || *str[0] == format[i]) {
    str[0]++;
    (*n)++;
  }
  int wi_flag = 0;
  if (width != 0) {
    wi_flag = 1;
  }
  if (mass[0][0] == '-') {
    mass[0][1] = '-';
  }
  if ((*str[0] == '+' || *str[0] == '-') &&
      (*(str[0] + 1) >= '0' && *(str[0] + 1) <= '9') && format[i + 1] != 'p') {
    if (wi_flag == 1 && width != 0) {
      if (*str[0] == '+') {
        str[0] += 1;
        (*n)++;
        width--;
      }
      if (*str[0] == '-') {
        mass[0][j++] = '-';
        str[0] += 1;
        *(n) += 1;
        width--;
      }
    } else if (wi_flag == 0) {
      mass[0][j++] = *str[0]++;
      *(n) += 1;
    }
  }
  if (wi_flag == 1 && width == 0) {
    wi_flag = -1;
  }
  mass[0][j++] = '0';
  if ((*str[0] >= '0' && *str[0] <= '9') ||
      (*str[0] >= 'a' && *str[0] <= 'f') ||
      (*str[0] >= 'F' && *str[0] <= 'F')) {
    if ((*str[0] == '0' && (*(str[0] + 1) == 'x' || *(str[0] + 1) == 'X') &&
         ((((*str[0] + 2) >= '0' && (*str[0] + 2) <= '9') ||
           ((*str[0] + 2) >= 'A' && (*str[0] + 2) <= 'F') ||
           ((*str[0] + 2) >= 'a' && (*str[0] + 2) <= 'f')))) ||
        (format[i + 1] == 'x' || (format[i + 1] == 'X') ||
         (format[i + 1] == 'p'))) {
      if (*(str[0] - 1) == '-') {
        mass[0][0] = '-';
        mass[0][1] = '0';
      }
      if (format[i + 1] == 'p') {
        if ((*str[0] >= '0' && *str[0] <= '9')) {
          mass[0][j++] = '0';
        }
      }
      if (format[i + 1] == 'x' || format[i + 1] == 'X' ||
          format[i + 1] == 'i') {
        if (*(str[0] - 1) == '-' && mass[0][0] != '-') {
          mass[0][j++] = *(str[0]++ - 1);
          str[0]++;
          (*n)++;
        } else {
          str[0] += 2;
          mass[0][j++] = '0';
        }
        if (format[i + 1] == 'x' || format[i + 1] == 'X') {
          str[0] -= 2;
        }
      }
      for (; (*str[0] >= '0' && *str[0] <= '9') ||
             (*str[0] >= 'A' && *str[0] <= 'F') ||
             (*str[0] >= 'a' && *str[0] <= 'f') || *str[0] == 'x' ||
             *str[0] == 'X';
           j++) {
        if (wi_flag == -1) {
          mass[0][0] = '\0';
          *error_code = -1;
          break;
        }
        if (*str[0] == ' ') {
          break;
        }
        if (wi_flag == 1 && width != 0) {
          mass[0][j] = *str[0]++;
          (*n)++;
          width--;
        } else if (wi_flag == 0) {
          mass[0][j] = *str[0]++;
          (*n)++;
        } else if (wi_flag == 1 && width == 0) {
          break;
        }
      }
    } else {
      flag = -1;
    }
  } else {
    *error_code = -1;
  }
  return flag;
}

// Конвертируем шестнадцатеричное число (строку) в десятичное
long hex_to_dec(char *mass) {
  int sign = 1;
  long int hex = 0;
  int j = 0;
  if (mass[j++] == '-') {
    sign *= -1;
  }
  for (int i = (int)my_strlen(mass) - 2; i >= 0; i--) {
    int tmp = 0;
    if (mass[j] <= '9') {
      tmp = mass[j++] - '0';
    } else if (mass[j] > '9') {
      switch (mass[j++]) {
        case 'a':
        case 'A': {
          tmp = 10;
          break;
        }
        case 'b':
        case 'B': {
          tmp = 11;
          break;
        }
        case 'c':
        case 'C': {
          tmp = 12;
          break;
        }
        case 'd':
        case 'D': {
          tmp = 13;
          break;
        }
        case 'e':
        case 'E': {
          tmp = 14;
          break;
        }
        case 'f':
        case 'F': {
          tmp = 15;
          break;
        }
      }
    }
    hex += tmp * pow(16, i);
  }
  return hex * sign;
}

int my_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int count = 0;
  int n = 0;
  int error_code = 0;
  int width = 0;
  char tmp_width[32] = {0};
  for (size_t i = 0; i < my_strlen(format); i++) {
    if (error_code == -1) {
      break;
    }
    //  если указана точность (width)
    if (format[i] == '%' && format[i + 1] != '*') {
      if (format[i] == '%' && (format[i + 1] >= '0' && format[i + 1] <= '9')) {
        for (int x = 0; (format[i + 1] >= '0' && format[i + 1] <= '9'); x++) {
          tmp_width[x] = format[i + 1];
          i++;
        }  //  получил точность
        width = my_atoi(tmp_width);
        //  tmp_width[0] = 0;
        for (int y = 0; tmp_width[y] != 0; y++) {
          tmp_width[y] = '\0';
        }
      }
      if (format[i + 1] == 'l' || format[i + 1] == 'L' ||
          format[i + 1] == 'h') {
        i += 1;
      }
      if (format[i + 1] == 'c' || format[i + 1] == 'd' ||
          format[i + 1] == 'i' || format[i + 1] == 'f' ||
          format[i + 1] == 's' || format[i + 1] == 'u' ||
          format[i + 1] == '%' || format[i + 1] == 'o' ||
          format[i + 1] == 'x' || format[i + 1] == 'X' ||
          format[i + 1] == 'p' || format[i + 1] == 'n' ||
          format[i + 1] == 'g' || format[i + 1] == 'G' ||
          format[i + 1] == 'e' || format[i + 1] == 'E') {
        switch (format[i + 1]) {
          case 'c': {
            char *p = va_arg(args, char *);
            if (count != 0) {
              while ((*str == ' ' || *str == format[i]) &&
                     (format[i - 1] != '%')) {
                str++;
                n++;
              }
            }
            *p = *str++;
            if (error_code != -1) {
              count++;
            }
            n++;
            break;
          }
          case 'd': {
            char mass[20] = {0};
            if (format[i] == 'h') {
              short *p = va_arg(args, short *);
              *p = my_atoi(
                  str_to_mass(&str, mass, &n, format, i, &error_code, width));
            } else if (format[i] == 'l') {
              long *p = va_arg(args, long *);
              *p = my_atoi(
                  str_to_mass(&str, mass, &n, format, i, &error_code, width));
            } else {
              int *p = va_arg(args, int *);
              *p = my_atoi(
                  str_to_mass(&str, mass, &n, format, i, &error_code, width));
            }
            if (error_code != -1) {
              count++;
            }
            break;
          }
          case 'i': {
            char *mass = (char *)calloc(20, sizeof(char));
            ;
            if (format[i] == 'h') {
              short *p = va_arg(args, short *);
              if (oct_pars(&mass, &str, &n, format, i, &error_code, width) ==
                  0) {
                *p = oct_to_dec(mass);
              } else if (hex_pars(&mass, &str, &n, format, i, &error_code,
                                  width) == 0) {
                *p = hex_to_dec(mass);
              } else {
                *p = my_atoi(
                    str_to_mass(&str, mass, &n, format, i, &error_code, width));
              }
            } else if (format[i] == 'l') {
              long *p = va_arg(args, long *);
              if (oct_pars(&mass, &str, &n, format, i, &error_code, width) ==
                  0) {
                *p = oct_to_dec(mass);
              } else if (hex_pars(&mass, &str, &n, format, i, &error_code,
                                  width) == 0) {
                *p = hex_to_dec(mass);
              } else {
                *p = my_atoi(
                    str_to_mass(&str, mass, &n, format, i, &error_code, width));
              }
            } else {
              int *p = va_arg(args, int *);
              if (oct_pars(&mass, &str, &n, format, i, &error_code, width) ==
                  0) {
                *p = oct_to_dec(mass);
              } else if (hex_pars(&mass, &str, &n, format, i, &error_code,
                                  width) == 0) {
                *p = hex_to_dec(mass);
              } else {
                *p = my_atoi(
                    str_to_mass(&str, mass, &n, format, i, &error_code, width));
              }
            }
            free(mass);
            if (error_code != -1) count++;
            break;
          }
          case 'E':
          case 'e':
          case 'G':
          case 'g':
          case 'f': {
            char mass[50] = {0};
            if (format[i] == 'l') {
              double *p = va_arg(args, double *);
              double val = 0.0;
              val = my_atof(
                  str_to_mass(&str, mass, &n, format, i, &error_code, width));
              exp_num(mass, "double", &val);
              *p = val;
            } else if (format[i] == 'L') {
              long double *p = va_arg(args, long double *);
              long double val = 0.0;
              val = my_atof(
                  str_to_mass(&str, mass, &n, format, i, &error_code, width));
              exp_num(mass, "long double", &val);
              *p = val;
            } else {
              float *p = va_arg(args, float *);
              float val = 0.0;
              val = my_atof(
                  str_to_mass(&str, mass, &n, format, i, &error_code, width));
              exp_num(mass, "float", &val);
              *p = val;
            }
            if (error_code != -1) count++;
            break;
          }
          case 's': {
            char *p = va_arg(args, char *);
            int j = 0;
            while ((*str == ' ' || *str == format[i]) &&
                   (format[i - 1] != '%')) {
              str++;
              n++;
            }
            for (; *str != ' '; j++) {
              if (width > 0) {
                while (width != 0) {
                  if (*str == ' ') {
                    break;
                  }
                  *(p + j++) = *str++;
                  n++;
                  width -= 1;
                }
                if (width == 0) break;
              } else {
                *(p + j) = *str++;
                n++;
              }
            }
            *(p + j) = '\0';
            if (error_code != -1) count++;
            break;
          }
          case 'u': {
            char mass[20] = {0};
            if (format[i] == 'h') {
              unsigned short *p = va_arg(args, unsigned short *);
              *p = (unsigned short)my_atoi(
                  str_to_mass(&str, mass, &n, format, i, &error_code, width));
            } else if (format[i] == 'l') {
              unsigned long *p = va_arg(args, unsigned long *);
              *p = (unsigned long)my_atoi(
                  str_to_mass(&str, mass, &n, format, i, &error_code, width));
            } else {
              unsigned int *p = va_arg(args, unsigned int *);
              *p = (unsigned int)my_atoi(
                  str_to_mass(&str, mass, &n, format, i, &error_code, width));
            }
            if (error_code != -1) count++;
            break;
          }
          case '%': {
            break;
          }
          case 'o': {
            char *mass = (char *)calloc(20, sizeof(char));
            if (format[i] == 'h') {
              short *p = va_arg(args, short *);
              if (oct_pars(&mass, &str, &n, format, i, &error_code, width) ==
                  0) {
                *p = oct_to_dec(mass);
              }
            } else if (format[i] == 'l') {
              long *p = va_arg(args, long *);
              if (oct_pars(&mass, &str, &n, format, i, &error_code, width) ==
                  0) {
                *p = oct_to_dec(mass);
              }
            } else {
              int *p = va_arg(args, int *);
              if (oct_pars(&mass, &str, &n, format, i, &error_code, width) ==
                  0) {
                *p = oct_to_dec(mass);
              }
            }
            free(mass);
            if (error_code != -1) count++;
            break;
          }
          case 'p':
          case 'x':
          case 'X': {
            char *mass = (char *)calloc(20, sizeof(char));
            if (format[i] == 'h') {
              short *p = va_arg(args, short *);
              if (hex_pars(&mass, &str, &n, format, i, &error_code, width) ==
                  0) {
                *p = hex_to_dec(mass);
              }
            } else if (format[i] == 'l') {
              long *p = va_arg(args, long *);
              if (hex_pars(&mass, &str, &n, format, i, &error_code, width) ==
                  0) {
                *p = hex_to_dec(mass);
              }
            } else {
              int *p = va_arg(args, int *);
              if (hex_pars(&mass, &str, &n, format, i, &error_code, width) ==
                  0) {
                *p = hex_to_dec(mass);
              }
            }
            free(mass);
            if (error_code != -1) count++;
            break;
          }
          case 'n': {
            int *p = va_arg(args, int *);
            *p = n;
          }
          default:
            break;
        }
      }
    } else if (format[i] == *str) {
      n++;
      str += 1;
    }
    width = 0;
  }
  va_end(args);
  return count;
}

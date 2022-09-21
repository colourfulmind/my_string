#include "my_string.h"

#include "my_sprintf.h"

// Вычисляет длину строки str, не включая завершающий нулевой символ.
my_size_t my_strlen(const char *str) {
  my_size_t _len = 0;
  if (str) {
    for (; str[_len] != '\0'; _len++) {
      ;
    }
  }
  return _len;
}

// Выполняет поиск первого вхождения символа c (беззнаковый тип)
// в строке, на которую указывает аргумент str.
char *my_strchr(const char *str, int c) {
  char *ptr = (char *)str;  // новый char-указатель на строку, т.к. она const
  char symbol = (char)c;  //  int с в символ
  int i = 0;
  while (*ptr != symbol && *ptr != 0) {
    ptr++;  // пока не пуст или не совпал
    i++;
  }
  if (((my_size_t)(ptr - str)) == my_strlen(str)) ptr = MY_NULL;
  if (c == 0) ptr = "";
  // возвращаем указатель либо на NULL если конец строки
  // или на первое вхождение с
  return ptr;
}

// Выполняет поиск первого вхождения символа c (беззнаковый тип)
// в первых n байтах строки, на которую указывает аргумент str.
void *my_memchr(const void *str, int c, my_size_t n) {
  const char *ptr = str;
  while (n != 0) {
    if ((char)c != *ptr) {
      ptr++;
      n--;
    } else {
      break;
    }
  }
  if (n <= 0) {
    ptr = MY_NULL;
  }
  return (void *)ptr;
}

// Сравнивает первые n байтов str1 и str2.
int my_memcmp(const void *str1, const void *str2, my_size_t n) {
  const unsigned char *str1_mem = str1;
  const unsigned char *str2_mem = str2;
  int flg = 1;
  while (n--) {
    if (*str1_mem != *str2_mem) {
      flg = 0;
      break;
    }
    str1_mem++;
    str2_mem++;
  }
  return flg ? 0 : *(unsigned char *)str1_mem - *(unsigned char *)str2_mem;
}

// Копирует n символов из src в dest.
void *my_memcpy(void *dest, const void *src, my_size_t n) {
  char *dest_str = dest;
  const char *src_str = src;
  for (my_size_t i = 0; i < n; i++) {
    dest_str[i] = src_str[i];
  }
  return dest;
}

// Еще одна функция для копирования n символов из str2 в str1.
void *my_memmove(void *dest, const void *src, my_size_t n) {
  char *dest_str;
  const char *src_str;
  if (dest < src) {
    dest_str = dest;
    src_str = src;
    for (my_size_t i = 0; i < n; i++) {
      *dest_str++ = *src_str++;
    }
  } else {
    dest_str = (char *)dest + n - 1;
    src_str = (char *)src + n - 1;
    for (my_size_t i = n; i > 0; i--) {
      *dest_str-- = *src_str--;
    }
  }
  return dest;
}

// Копирует символ c (беззнаковый тип)
// в первые n символов строки, на которую указывает аргумент str.
void *my_memset(void *str, int c, my_size_t n) {
  char *xstr = str;
  while (n--) *xstr++ = c;
  return str;
}

// Добавляет строку, на которую указывает src,
// в конец строки, на которую указывает dest.
char *my_strcat(char *dest, const char *src) {
  int i = my_strlen(dest), j = 0;
  while (src[j]) {
    dest[i + j] = src[j];
    j++;
  }
  dest[i + j] = '\0';
  return dest;
}

// Добавляет строку, на которую указывает src, в конец строки,
// на которую указывает dest, длиной до n символов.
char *my_strncat(char *dest, const char *src, my_size_t n) {
  char *buffer = dest;
  if (src && dest) {
    int i = my_strlen(dest), j = 0;
    if (n > 0) {
      while (src[j] != '\0') {
        buffer[i + j] = src[j];
        j++;
        n--;
        if (n == 0) {
          buffer[i + j] = '\0';
          break;
        }
      }
    }
  }
  return dest;
}

// Сравнивает строку, на которую указывает str1,
// со строкой, на которую указывает str2.
int my_strcmp(const char *str1, const char *str2) {
  int res = 0;
  int flag = 0;
  if (*str1 != '\0' && *str2 != '\0') {
    while (*str1 == *str2 && flag == 0) {
      str1++;
      str2++;
      if (*str1 == '\0' || *str2 == '\0') {
        flag = 1;
      }
    }
  }
  if (*(unsigned char *)str2 == 0) {
    res = *(unsigned char *)str1;
  } else {
    res = *(unsigned char *)str1 - *(unsigned char *)str2;
  }
  return res;
}

// Сравнивает не более первых n байтов str1 и str2.
int my_strncmp(const char *str1, const char *str2, my_size_t n) {
  for (my_size_t i = 0; *str1 && (*str2 == *str1) && i < n - 1;
       str1++, str2++, i++) {
  }
  return *str1 - *str2;
}

// Копирует строку, на которую указывает src, в dest.
char *my_strcpy(char *dest, const char *src) {
  char *ptr = dest;
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return ptr;
}

// Копирует до n символов из строки, на которую указывает src, в dest.
char *my_strncpy(char *dest, const char *src, my_size_t n) {
  my_size_t i = 0;
  while (i <= n - 1) {
    dest[i] = src[i];
    i++;
    if (src[i] == '\0') {
      while (i <= n - 1) {
        dest[i] = '\0';
        i++;
      }
    }
  }
  return dest;
}

// Вычисляет длину начального сегмента str1,
// который полностью состоит из символов, не входящих в str2.
my_size_t my_strcspn(const char *str1, const char *str2) {
  my_size_t len = my_strlen(str1);
  for (my_size_t i = 0; i < my_strlen(str1); i++) {
    for (my_size_t j = 0; j < my_strlen(str2); j++) {
      if (str1[i] == str2[j] && i < len) {
        len = i;
      }
    }
  }
  return len;
}

// Выполняет поиск во внутреннем массиве номера ошибки errnum и
// возвращает указатель на строку с сообщением об ошибке.
// Нужно объявить макросы, содержащие массивы сообщений об ошибке
// для операционных систем mac и linux. Описания ошибок есть
// в оригинальной библиотеке. Проверка текущей ОС осуществляется
// с помощью директив.
char *my_strerror(int errnum) {
  char *arr[] = error;
  static char res[50];
  my_sprintf(res, "Unknown error: %d", errnum);
  return (errnum >= 0 && errnum <= INDEX) ? arr[errnum] : res;
}

// Находит первый символ в строке str1,
// который соответствует любому символу, указанному в str2.
char *my_strpbrk(const char *str1, const char *str2) {
  my_size_t lenStr2 = my_strlen(str2);
  int flag = 0;
  char *pointer = (char *)str1;

  while (*pointer != 0 && flag != 1) {
    for (unsigned int i = 0; i < lenStr2; i++) {
      if (*pointer == str2[i]) {
        flag = 1;
      }
    }

    if (flag != 1) {
      pointer++;
    }
  }

  return flag != 1 ? MY_NULL : pointer;
}

// Выполняет поиск последнего вхождения символа
// c (беззнаковый тип) в строке, на которую указывает аргумент str.
char *my_strrchr(const char *str, int c) {
  char *p = MY_NULL;
  if (*str == c) {
    p = (char *)str;
  }
  while (*str++) {
    if (*str == c) {
      p = (char *)str;
    }
  }
  return p;
}

// Вычисляет длину начального сегмента str1,
// который полностью состоит из символов str2.
my_size_t my_strspn(const char *str1, const char *str2) {
  my_size_t len = 0;
  if (str1 != MY_NULL && str2 != MY_NULL) {
    while (*str1 && my_strchr(str2, *str1++)) {
      len++;
    }
  }

  return len;
}

// Находит первое вхождение всей строки needle
// (не включая завершающий нулевой символ),
// которая появляется в строке haystack.
char *my_strstr(const char *haystack, const char *needle) {
  char *s1 = MY_NULL;
  char *s2 = MY_NULL;
  if (my_strlen(needle) == 0) {
    s1 = (char *)haystack;
  } else {
    int flg = 1;
    while (*haystack != '\0' && flg == 1) {
      s1 = (char *)haystack;
      s2 = (char *)needle;
      while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
        s1++;
        s2++;
      }
      if (*s2 == '\0') {
        flg = 0;
      }
      if (flg == 1) {
        haystack++;
      }
    }
    if (flg == 1) {
      s1 = MY_NULL;
    } else {
      s1 = (char *)haystack;
    }
  }
  return s1;
}

// Разбивает строку str на ряд токенов, разделенных delim.
char *my_strtok(char *str, const char *delim) {
  static char *p = MY_NULL;
  int flg = 1;
  if (!(str == MY_NULL)) {
    p = str;
  } else if (!p) {
    p = MY_NULL;
    flg = 0;
  }
  if (flg) {
    str = p + my_strspn(p, delim);
    p = str + my_strcspn(str, delim);
  }
  if (p == str) {
    p = MY_NULL;
    flg = 0;
  } else {
    p = *p ? *p = 0, p + 1 : 0;
  }
  return flg ? str : p;
}
//  Возвращает копию строки (str), преобразованной в верхний регистр.
//  В случае какой-либо ошибки следует вернуть значение NULL
void *my_to_upper(const char *str) {
  char *new_str = MY_NULL;
  if (str != MY_NULL) {
    new_str = (char *)malloc(my_strlen(str) + 1);
    my_size_t i = 0;

    while (str[i] != 0) {
      if (str[i] > 96 && str[i] < 123) {
        new_str[i] = str[i] - 32;
      } else {
        new_str[i] = str[i];
      }
      i++;
    }
    new_str[i] = 0;
  }
  return (char *)new_str;
}

//  Возвращает копию строки (str), преобразованной в нижний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL
void *my_to_lower(const char *str) {
  char *new_str = MY_NULL;
  if (str != MY_NULL) {
    new_str = (char *)malloc((int)my_strlen(str) + 1);
    my_size_t i = 0;

    while (str[i] != 0) {
      if (str[i] > 64 && str[i] < 91) {
        new_str[i] = str[i] + 32;
      } else {
        new_str[i] = str[i];
      }
      i++;
    }
    new_str[i] = 0;
  }
  return (char *)new_str;
}

// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL void *my_insert(const char *src, const
// char *str, my_size_t start_index) {
//     char *new_str = MY_NULL;
//     my_size_t new_strlen = my_strlen(str) + my_strlen(src);
//     if (str != MY_NULL && src != MY_NULL) {
//         new_str = (char*) malloc(new_strlen + 1);
//     }

//     my_size_t i = 0, j = 0, k = 0;

//     for (; i < new_strlen; i++) {
//         if (i >= start_index && j < my_strlen(src)) {
//             new_str[i] = src[j];
//             j++;
//         } else {
//             new_str[i] = str[k];
//             k++;
//         }
//     }
//     new_str[i] = 0;
//     return (char *) new_str;
// }
void *my_insert(const char *src, const char *str, my_size_t start_index) {
  char *dest = MY_NULL;
  if (src && str) {
    my_size_t size_src = my_strlen(src);
    my_size_t size_str = my_strlen(str);
    if ((size_str != 0 || size_src != 0) && start_index <= size_src) {
      my_size_t i = 0;
      dest = (char *)calloc(size_src + size_str + 2, sizeof(char));
      if (dest != MY_NULL) {
        for (; i < start_index; i++) {
          dest[i] = src[i];
        }
        int j = 0;
        for (; i < start_index + size_str; i++, j++) {
          dest[i] = str[0 + j];
        }
        for (; i < size_src + size_str; i++) {
          dest[i] = src[i - size_str];
        }
      }
    }
  }
  return (void *)dest;
}

// void *my_insert(const char *src, const char *str, my_size_t start_index) {
//     char* new_str = MY_NULL;
//     if (src && str && my_strlen(src) >= start_index) {
//         new_str = (char*)malloc((my_strlen(src) + my_strlen(str) + 1) *
//         sizeof(char)); if (new_str) {
//             my_strncpy(new_str, src, start_index);
//             *(new_str + start_index) = '\0';
//             my_strcat(new_str, str);
//             my_strcat(new_str, src + start_index);
//         }
//     }
//     return (void*)new_str;
// }

void *my_trim(const char *src, const char *trim_chars) {
  char res[4096] = "";
  char *buff = "";
  if (src && trim_chars) {
    my_strcpy(res, src);
    for (int i = 0; i < 2; i++) {
      char buff2[4096] = "";
      char buff3[4096] = "";
      my_size_t len_left = my_strspn(res, trim_chars);
      my_strcpy(buff2, &res[len_left]);
      for (int i = 0, j = my_strlen(buff2); j != 0; i++, j--) {
        buff3[i] = buff2[j - 1];
        if (j == 1) {
          buff3[i + 1] = '\0';
        }
      }
      my_strcpy(res, buff3);
    }
    my_size_t len = my_strlen(res) + 1;
    buff = malloc(len * sizeof(char));
    my_strcpy(buff, res);
  } else {
    buff = MY_NULL;
  }
  return buff;
}

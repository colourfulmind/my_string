#include "my_sprintf.h"
#include "my_sscanf.h"
#include "my_string.h"

#include <check.h>
#include <float.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>

// memchr

START_TEST(memchr_1) {
  char str[] = "Hello w\0orld\0";
  ck_assert_pstr_eq(memchr(str, 'r', 5), my_memchr(str, 'r', 5));
}

END_TEST

START_TEST(memchr_2) {
  char str[] = "Hello world!";
  ck_assert_pstr_eq(memchr(str, 's', 6), my_memchr(str, 's', 6));
}

END_TEST

START_TEST(memchr_3) {
  char str[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
  ck_assert_pstr_eq(memchr(str, 'l', 5), my_memchr(str, 'l', 5));
}

END_TEST

START_TEST(memchr_4) {
  char str[] = "Hello\nworld";
  ck_assert_pstr_eq(memchr(str, ' ', 5), my_memchr(str, ' ', 5));
}

END_TEST

START_TEST(memchr_5) {
  char str[] = "Hello world";
  ck_assert_pstr_eq(memchr(str, ' ', 5), my_memchr(str, ' ', 5));
}

END_TEST

START_TEST(memchr_6) {
  char str[] = "Hello w\0orld\0";
  char find = 'r';
  ck_assert_pstr_eq(memchr(str, find, 5), my_memchr(str, find, 5));
}

END_TEST

START_TEST(memchr_7) {
  char str[] = "Hello world!";
  char find = 's';
  ck_assert_pstr_eq(memchr(str, find, 5), my_memchr(str, find, 5));
}

END_TEST

START_TEST(memchr_8) {
  char str[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
  char find = 'l';
  ck_assert_pstr_eq(memchr(str, find, 5), my_memchr(str, find, 5));
}

END_TEST

START_TEST(memchr_9) {
  char str[] = "Hello\nworld";
  char find = ' ';
  ck_assert_pstr_eq(memchr(str, find, 5), my_memchr(str, find, 5));
}

END_TEST

START_TEST(memchr_10) {
  char str[] = "Hello world";
  char find = ' ';
  ck_assert_pstr_eq(memchr(str, find, 5), my_memchr(str, find, 5));
}

END_TEST

// memcmp

START_TEST(memcmp_1) {
  void *str_1 = "Hello, world";
  void *str_2 = "Hello, world";
  ck_assert_int_eq(memcmp(str_1, str_2, 3), my_memcmp(str_1, str_2, 3));
}

END_TEST

START_TEST(memcmp_2) {
  void *str_1 = "Hello, world";
  void *str_2 = "He  llo, world!";
  ck_assert_int_eq(memcmp(str_1, str_2, 3), my_memcmp(str_1, str_2, 3));
}

END_TEST

START_TEST(memcmp_3) {
  void *str_1 = " Hello, world";
  void *str_2 = "HELLO!";
  ck_assert_int_eq(memcmp(str_1, str_2, 3), my_memcmp(str_1, str_2, 3));
}

END_TEST

START_TEST(memcmp_4) {
  void *str_1 = "Hello, world";
  void *str_2 = "Hello, world";
  ck_assert_int_eq(memcmp(str_1, str_2, 0), my_memcmp(str_1, str_2, 0));
}

END_TEST

START_TEST(memcmp_5) {
  void *str_1 = "Hello, world";
  void *str_2 = "He  llo, world!";
  ck_assert_int_eq(memcmp(str_1, str_2, 3), my_memcmp(str_1, str_2, 3));
}

END_TEST

START_TEST(memcmp_6) {
  void *str_1 = " Hello, world";
  void *str_2 = "HELLO!";
  ck_assert_int_eq(memcmp(str_1, str_2, 2), my_memcmp(str_1, str_2, 2));
}

END_TEST

START_TEST(memcmp_7) {
  void *str_1 = "12345";
  void *str_2 = "12345";
  ck_assert_int_eq(memcmp(str_1, str_2, 5), my_memcmp(str_1, str_2, 5));
}

END_TEST

START_TEST(memcmp_8) {
  void *str_1 = "12345";
  void *str_2 = "1";
  ck_assert_int_eq(memcmp(str_1, str_2, 1), my_memcmp(str_1, str_2, 1));
}

END_TEST

START_TEST(memcmp_9) {
  void *str_1 = "1324";
  void *str_2 = "1234";
  ck_assert_int_eq(memcmp(str_1, str_2, 2), my_memcmp(str_1, str_2, 2));
}

END_TEST

START_TEST(memcmp_10) {
  void *str_1 = "01234567890123456789abcdefghijklmnopqrstuvwxyzabcdefghijklmnop"
                "qrstuvwxyZ";
  void *str_2 = "01234567890123456789abcdefghijklmnopqrstuvwxyzabcdefghijklmnop"
                "qrstuvwxyz";
  ck_assert_int_eq(memcmp(str_1, str_2, 72), my_memcmp(str_1, str_2, 72));
}

END_TEST

// memcpy

START_TEST(memcpy_1) {
  char dest1[128] = "";
  char dest2[128] = "";
  char str[128] = "Hello, world!!!";
  ck_assert_pstr_eq(memcpy(dest1, str, 3), my_memcpy(dest2, str, 3));
}

END_TEST

START_TEST(memcpy_2) {
  char dest1[128] = "";
  char dest2[128] = "";
  char str[128] = "Hello, \0world!!!";
  ck_assert_pstr_eq(memcpy(dest1, str, 5), my_memcpy(dest2, str, 5));
}

END_TEST

START_TEST(memcpy_3) {
  char dest1[128] = "1234";
  char dest2[128] = "1234";
  char str[128] = "Hello, world!!!";
  ck_assert_pstr_eq(memcpy(dest1, str, 4), my_memcpy(dest2, str, 4));
}

END_TEST

START_TEST(memcpy_4) {
  char dest1[128] = "Hello, world!!!";
  char dest2[128] = "Hello, world!!!";
  ck_assert_pstr_eq(memcpy(dest1, dest1 + 7, 4),
                    my_memcpy(dest2, dest2 + 7, 4));
}

END_TEST

START_TEST(memcpy_5) {
  char src[] = "Hello, world!!!";
  char res[20];
  char expected[20];
  my_memcpy(res, src, 12);
  memcpy(expected, src, 12);
  ck_assert_mem_eq(res, expected, 12);
}

END_TEST

START_TEST(memcpy_6) {
  char src[] = "Hello, \0world!!!";
  char res[20];
  char expected[20];
  my_memcpy(res, src, 10);
  memcpy(expected, src, 10);
  ck_assert_mem_eq(res, expected, 10);
}

END_TEST

START_TEST(memcpy_7) {
  char src[] = "";
  char res[20];
  char expected[20];
  my_memcpy(res, src, 1);
  memcpy(expected, src, 1);
  ck_assert_mem_eq(res, expected, 1);
}

END_TEST

START_TEST(memcpy_8) {
  char src[] = "1234";
  char res[20];
  char expected[20];
  my_memcpy(res, src, 1);
  memcpy(expected, src, 1);
  ck_assert_mem_eq(res, expected, 1);
}

END_TEST

START_TEST(memcpy_9) {
  char src[] = "abcdefghijklmnopqrstuvwxyz";
  char res[40];
  char expected[40];
  my_memcpy(res, src, 26);
  memcpy(expected, src, 26);
  ck_assert_mem_eq(res, expected, 26);
}

END_TEST

START_TEST(memcpy_10) {
  char src[] = "abcdefghijklmnopqrstuvwxyz";
  char res[40];
  char expected[40];
  my_memcpy(res, src, 27);
  memcpy(expected, src, 27);
  ck_assert_mem_eq(res, expected, 27);
}

END_TEST

// memmove

START_TEST(memmove_1) {
  char src1[128] = "Hello, world!";
  char src2[128] = "Hello, world!";
  ck_assert_pstr_eq(memmove(src1, src1 + 5, 3), my_memmove(src2, src2 + 5, 3));
}

END_TEST

START_TEST(memmove_2) {
  char src1[128] = "Hello, \0world!";
  char src2[128] = "Hello, \0world!";
  ck_assert_pstr_eq(memmove(src1, src1, 4), my_memmove(src2, src2, 4));
}

END_TEST

START_TEST(memmove_3) {
  char src1[128] = "1234567890";
  char src2[128] = "1234567890";
  ck_assert_pstr_eq(memmove(src1, src1, 4), my_memmove(src2, src2, 4));
}

END_TEST

START_TEST(memmove_4) {
  char src1[128] = "abcdefghijklmnopqrstuvwxyz";
  char src2[128] = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_pstr_eq(memmove(src1, src1, 4), my_memmove(src2, src2, 4));
}

END_TEST

START_TEST(memmove_5) {
  char src1[128] = "abcdefghijklmnopqrstuvwxyz";
  char src2[128] = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_pstr_eq(memmove(src1, src1, 26), my_memmove(src2, src2, 26));
}

END_TEST

START_TEST(memmove_6) {
  char src1[128] = "abcdefghijklmnopqrstuvwxyz";
  char src2[128] = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_pstr_eq(memmove(src1, src1, 0), my_memmove(src2, src2, 0));
}

END_TEST

START_TEST(memmove_7) {
  char src[128] = "abcdefghijk\0lmnopqrstuvwxyz";
  char src2[128] = "abcdefghijk\0lmnopqrstuvwxyz";
  char *res = src;
  char *expected = src2;
  memmove(expected, src, 12);
  my_memmove(res, src2, 12);
  ck_assert_pstr_eq(res, expected);
}

END_TEST

START_TEST(memmove_8) {
  char src[128] = "abcdefghijklmnopqrstuvwxyz";
  char src2[128] = "abcdefghijklmnopqrstuvwxyz";
  char *expected = src;
  char *res = src2;
  memmove(expected, src, 30);
  my_memmove(res, src2, 30);
  ck_assert_pstr_eq(res, expected);
}

END_TEST

START_TEST(memmove_9) {
  char src[128] = "\nabcdefg\nhijk\0lmnopqrstuvwxyz";
  char src2[128] = "\nabcdefg\nhijk\0lmnopqrstuvwxyz";
  char *expected = src;
  char *res = src2;
  memmove(expected, src, 14);
  my_memmove(res, src2, 14);
  ck_assert_mem_eq(res, expected, 14);
}

END_TEST

START_TEST(memmove_10) {
  char src[200] = "";
  char src2[200] = "";
  char *expected = src;
  char *res = src2;
  memmove(expected, src, 0);
  my_memmove(res, src2, 0);
  ck_assert_mem_eq(res, expected, 0);
}

END_TEST

// memset

START_TEST(memset_1) {
  char src1[128] = "Hello world!";
  char src2[128] = "Hello world!";
  ck_assert_pstr_eq(memset(src1, 'l', 6), my_memset(src2, 'l', 6));
}

END_TEST

START_TEST(memset_2) {
  char src1[128] = "  Hello \nworld!";
  char src2[128] = "  Hello \nworld!";
  ck_assert_pstr_eq(memset(src1, '\0', 6), my_memset(src2, '\0', 6));
}

END_TEST

START_TEST(memset_3) {
  char src1[128] = "Hello \0world!";
  char src2[128] = "Hello \0world!";
  ck_assert_pstr_eq(memset(src1, 'w', 6), my_memset(src2, 'w', 6));
}

END_TEST

START_TEST(memset_4) {
  char src1[128] = " \n\0";
  char src2[128] = " \n\0!";
  ck_assert_pstr_eq(memset(src1, '1', 1), my_memset(src2, '1', 1));
}

END_TEST

START_TEST(memset_5) {
  char src1[128] = "Hello Hello Hello Hello";
  char src2[128] = "Hello Hello Hello Hello";
  ck_assert_pstr_eq(memset(src1, 'H', 25), my_memset(src2, 'H', 25));
}

END_TEST

START_TEST(memset_6) {
  char src1[128] = "12345";
  char src2[128] = "12345";
  ck_assert_pstr_eq(memset(src1, '1', 5), my_memset(src2, '1', 5));
}

END_TEST

START_TEST(memset_7) {
  char src1[128] = "12345";
  char src2[128] = "12345";
  ck_assert_pstr_eq(memset(src1, '1', 6), my_memset(src2, '1', 6));
}

END_TEST

START_TEST(memset_8) {
  char src1[128] = "H";
  char src2[128] = "H";
  ck_assert_pstr_eq(memset(src1, 'l', 1), my_memset(src2, 'l', 1));
}

END_TEST

START_TEST(memset_9) {
  char src1[128] = "H";
  char src2[128] = "H";
  ck_assert_pstr_eq(memset(src1, 'i', 1), my_memset(src2, 'i', 1));
}

END_TEST

START_TEST(memset_10) {
  char src1[128] = "\0";
  char src2[128] = "\0";
  ck_assert_pstr_eq(memset(src1, 'l', 1), my_memset(src2, 'l', 1));
}

END_TEST

// strcat

START_TEST(strcat_1) {
  char dest1[128] = "";
  char dest2[128] = "";
  char src[128] = "Hello world!";
  ck_assert_pstr_eq(strcat(dest1, src), my_strcat(dest2, src));
}

END_TEST

START_TEST(strcat_2) {
  char dest1[128] = "Hello, ";
  char dest2[128] = "Hello, ";
  char src[128] = "Hello world!";
  ck_assert_pstr_eq(strcat(dest1, src), my_strcat(dest2, src));
}

END_TEST

START_TEST(strcat_3) {
  char dest1[128] = "Hello";
  char dest2[128] = "Hello";
  char src[128] = " world!";
  ck_assert_pstr_eq(strcat(dest1, src), my_strcat(dest2, src));
}

END_TEST

START_TEST(strcat_4) {
  char dest1[128] = "123";
  char dest2[128] = "123";
  char src[128] = "Hello world!";
  ck_assert_pstr_eq(strcat(dest1, src), my_strcat(dest2, src));
}

END_TEST

START_TEST(strcat_5) {
  char dest1[128] = "";
  char dest2[128] = "";
  char src[128] = "";
  ck_assert_pstr_eq(strcat(dest1, src), my_strcat(dest2, src));
}

END_TEST

START_TEST(strcat_6) {
  char dest1[128] = "123";
  char dest2[128] = "123";
  char src[128] = "456789!";
  ck_assert_pstr_eq(strcat(dest1, src), my_strcat(dest2, src));
}

END_TEST

START_TEST(strcat_7) {
  char dest1[128] = "123\0";
  char dest2[128] = "123\0";
  char src[128] = "456789!";
  ck_assert_pstr_eq(strcat(dest1, src), my_strcat(dest2, src));
}

END_TEST

START_TEST(strcat_8) {
  char dest1[128] = "Hello\0";
  char dest2[128] = "Hello\0";
  char src[128] = ", world!";
  ck_assert_pstr_eq(strcat(dest1, src), my_strcat(dest2, src));
}

END_TEST

START_TEST(strcat_9) {
  char dest1[128] = "";
  char dest2[128] = "";
  char src[128] = "";
  ck_assert_pstr_eq(strcat(dest1, src), my_strcat(dest2, src));
}

END_TEST

START_TEST(strcat_10) {
  char dest1[128] = "\0";
  char dest2[128] = "\0";
  char src[128] = "";
  ck_assert_pstr_eq(strcat(dest1, src), my_strcat(dest2, src));
}

END_TEST

// strncat

START_TEST(strncat_1) {
  char dest1[128] = "Hello, ";
  char dest2[128] = "Hello, ";
  char src[128] = "Hello world!";
  ck_assert_pstr_eq(strncat(dest1, src, 12), my_strncat(dest2, src, 12));
}

END_TEST

START_TEST(strncat_2) {
  char dest1[128] = "";
  char dest2[128] = "";
  char src[128] = "Hello world!";
  ck_assert_pstr_eq(strncat(dest1, src, 2), my_strncat(dest2, src, 2));
}

END_TEST

START_TEST(strncat_3) {
  char dest1[128] = "Hello,";
  char dest2[128] = "Hello,";
  char src[128] = " world!";
  ck_assert_pstr_eq(strncat(dest1, src, 2), my_strncat(dest2, src, 2));
}

END_TEST

START_TEST(strncat_4) {
  char dest1[128] = "Hello,";
  char dest2[128] = "Hello,";
  char src[128] = " world!";
  ck_assert_pstr_eq(strncat(dest1, src, 7), my_strncat(dest2, src, 7));
}

END_TEST

START_TEST(strncat_5) {
  char dest1[128] = "123\0";
  char dest2[128] = "123\0";
  char src[128] = "456789!";
  ck_assert_pstr_eq(strncat(dest1, src, 2), my_strncat(dest2, src, 2));
}

END_TEST

START_TEST(strncat_6) {
  char dest1[128] = "123";
  char dest2[128] = "123";
  char src[128] = "456789!";
  ck_assert_pstr_eq(strncat(dest1, src, 7), my_strncat(dest2, src, 7));
}

END_TEST

START_TEST(strncat_7) {
  char dest1[128] = "";
  char dest2[128] = "";
  char src[128] = "Hello world!";
  ck_assert_pstr_eq(strncat(dest1, src, 8), my_strncat(dest2, src, 8));
}

END_TEST

START_TEST(strncat_8) {
  char dest1[128] = "Hello world!";
  char dest2[128] = "Hello world!";
  char src[128] = "";
  ck_assert_pstr_eq(strncat(dest1, src, 2), my_strncat(dest2, src, 2));
}

END_TEST

START_TEST(strncat_9) {
  char dest1[128] = "\0";
  char dest2[128] = "\0";
  char src[128] = "Hello world!";
  ck_assert_pstr_eq(strncat(dest1, src, 2), my_strncat(dest2, src, 2));
}

END_TEST

START_TEST(strncat_10) {
  char dest1[128] = "Hello world!\0";
  char dest2[128] = "Hello world!\0";
  char src[128] = "";
  ck_assert_pstr_eq(strncat(dest1, src, 2), my_strncat(dest2, src, 2));
}

END_TEST

// strchr

START_TEST(strchr_1) {
  char src[] = "Hello, world!";
  char find = 'l';
  ck_assert_pstr_eq(my_strchr(src, find), strchr(src, find));
}

END_TEST

START_TEST(strchr_2) {
  char src[] = "Hello, world!";
  char find = 'a';
  ck_assert_pstr_eq(my_strchr(src, find), strchr(src, find));
}

END_TEST

START_TEST(strchr_3) {
  char src[] = "Hello, world!";
  char find = 'L';
  ck_assert_pstr_eq(my_strchr(src, find), strchr(src, find));
}

END_TEST

START_TEST(strchr_4) {
  char src[] = "";
  char find = 'a';
  ck_assert_pstr_eq(my_strchr(src, find), strchr(src, find));
}

END_TEST

START_TEST(strchr_5) {
  char src[] = "Hello \0world!";
  char find = 'd';
  ck_assert_pstr_eq(my_strchr(src, find), strchr(src, find));
}

END_TEST

START_TEST(strchr_6) {
  char src[] = "Hello \nworld!\0";
  char find = '\n';
  ck_assert_pstr_eq(my_strchr(src, find), strchr(src, find));
}

END_TEST

START_TEST(strchr_7) {
  char src[] = "\0";
  char find = ' ';
  ck_assert_pstr_eq(my_strchr(src, find), strchr(src, find));
}

END_TEST

START_TEST(strchr_8) {
  char src[] = "";
  char find = ' ';
  ck_assert_pstr_eq(my_strchr(src, find), strchr(src, find));
}

END_TEST

START_TEST(strchr_9) {
  char src[] = "\0\0\0";
  char find = ' ';
  ck_assert_pstr_eq(my_strchr(src, find), strchr(src, find));
}

END_TEST

START_TEST(strchr_10) {
  char src[] = "\t\n\t\n\0";
  char find = '\n';
  ck_assert_pstr_eq(my_strchr(src, find), strchr(src, find));
}

END_TEST

// strcmp

START_TEST(strcmp_1) {
  int src1 = my_strcmp("Hello, world", "Hello");
  int src2 = strcmp("Hello, world", "Hello");
  ck_assert_int_eq(src1 > 0 && src2 > 0, 1);
}

END_TEST

START_TEST(strcmp_2) {
  int src1 = my_strcmp("Hello, world", "");
  int src2 = strcmp("Hello, world", "");
  ck_assert_int_eq(src1 > 0 && src2 > 0, 1);
}

END_TEST

START_TEST(strcmp_3) {
  int src1 = my_strcmp("Hello, world", "Hello, world");
  int src2 = strcmp("Hello, world", "Hello, world");
  ck_assert_int_eq(src1, src2);
}

END_TEST

START_TEST(strcmp_4) {
  int src1 = my_strcmp("", "");
  int src2 = strcmp("", "");
  ck_assert_int_eq(src1, src2);
}

END_TEST

START_TEST(strcmp_5) {
  int src1 = my_strcmp("Hello", "Hello, world");
  int src2 = strcmp("Hello", "Hello, world");
  ck_assert_int_eq(src1 < 0 && src2 < 0, 1);
}

END_TEST

START_TEST(strcmp_6) {
  int src1 = my_strcmp("", "Hello");
  int src2 = strcmp("", "Hello");
  ck_assert_int_eq(src1 < 0 && src2 < 0, 1);
}

END_TEST

START_TEST(strcmp_7) {
  int src1 = my_strcmp("Hello\0, world", "Hello");
  int src2 = strcmp("Hello\0, world", "Hello");
  ck_assert_int_eq(src1, src2);
}

END_TEST

START_TEST(strcmp_8) {
  int src1 = my_strcmp("Hello\n, world", "Hello");
  int src2 = strcmp("Hello\n, world", "Hello");
  ck_assert_int_eq(src1 > 0 && src2 > 0, 1);
}

END_TEST

START_TEST(strcmp_9) {
  int src1 = my_strcmp("12345", "1234");
  int src2 = strcmp("12345", "1234");
  ck_assert_int_eq(src1 > 0 && src2 > 0, 1);
}

END_TEST

START_TEST(strcmp_10) {
  int src1 = my_strcmp("\0", "\0");
  int src2 = strcmp("\0", "\0");
  ck_assert_int_eq(src1, src2);
}

END_TEST

// strncmp

START_TEST(strncmp_1) {
  int src1 = my_strncmp("Hello, world", "Hello!", 6);
  int src2 = strncmp("Hello, world", "Hello!", 6);
  ck_assert_int_eq(src1 > 0 && src2 > 0, 1);
}

END_TEST

START_TEST(strncmp_2) {
  int src1 = my_strncmp("Hello, world", "Hello", 7);
  int src2 = strncmp("Hello, world", "Hello", 7);
  ck_assert_int_eq(src1 > 0 && src2 > 0, 1);
}

END_TEST

START_TEST(strncmp_3) {
  int src1 = my_strncmp("Hello, world", " ", 3);
  int src2 = strncmp("Hello, world", " ", 3);
  ck_assert_int_eq(src1 > 0 && src2 > 0, 1);
}

END_TEST

START_TEST(strncmp_4) {
  int src1 = my_strncmp("Hello, world", "Hello, world", 12);
  int src2 = strncmp("Hello, world", "Hello, world", 12);
  ck_assert_int_eq(src1, src2);
}

END_TEST

START_TEST(strncmp_5) {
  int src1 = my_strncmp("Hello, world", "Hello, world", 20);
  int src2 = strncmp("Hello, world", "Hello, world", 20);
  ck_assert_int_eq(src1, src2);
}

END_TEST

START_TEST(strncmp_6) {
  int src1 = my_strncmp("", "", 3);
  int src2 = strncmp("", "", 3);
  ck_assert_int_eq(src1, src2);
}

END_TEST

START_TEST(strncmp_7) {
  int src1 = my_strncmp("Hello!", "Hello, world", 6);
  int src2 = strncmp("Hello!", "Hello, world", 6);
  ck_assert_int_eq(src1 < 0 && src2 < 0, 1);
}

END_TEST

START_TEST(strncmp_8) {
  int src1 = my_strncmp("Hello", "Hello, world", 7);
  int src2 = strncmp("Hello", "Hello, world", 7);
  ck_assert_int_eq(src1 < 0 && src2 < 0, 1);
}

END_TEST

START_TEST(strncmp_9) {
  int src1 = my_strncmp(" ", "Hello, world", 3);
  int src2 = strncmp(" ", "Hello, world", 3);
  ck_assert_int_eq(src1 < 0 && src2 < 0, 1);
}

END_TEST

// strcpy

START_TEST(strcpy_1) {
  char dest1[128] = "";
  char dest2[128] = "";
  char src[128] = "Hello, world!";
  ck_assert_pstr_eq(strcpy(dest1, src), my_strcpy(dest2, src));
}

END_TEST

START_TEST(strcpy_2) {
  char dest1[128] = "";
  char dest2[128] = "";
  char src[128] = "Hello,\0 world!";
  ck_assert_pstr_eq(strcpy(dest1, src), my_strcpy(dest2, src));
}

END_TEST

START_TEST(strcpy_3) {
  char dest1[128] = "";
  char dest2[128] = "";
  char src[128] = "Hello, world!";
  ck_assert_pstr_eq(strcpy(dest1, src), my_strcpy(dest2, src));
}

END_TEST

START_TEST(strcpy_4) {
  char dest1[128] = "123";
  char dest2[128] = "123";
  char src[128] = "Hello, world!";
  ck_assert_pstr_eq(strcpy(dest1, src), my_strcpy(dest2, src));
}

END_TEST

START_TEST(strcpy_5) {
  char dest1[128] = "Hello, ";
  char dest2[128] = "Hello, ";
  char src[] = "World!";
  ck_assert_str_eq(my_strcpy(dest2, src), strcpy(dest1, src));
}

END_TEST

START_TEST(strcpy_6) {
  char dest1[128] = "";
  char dest2[128] = "";
  char src[128] = "";
  ck_assert_pstr_eq(strcpy(dest1, src), my_strcpy(dest2, src));
}

END_TEST

START_TEST(strcpy_7) {
  char dest1[128] = "\0";
  char dest2[128] = "\0";
  char src[128] = "Hello, world!";
  ck_assert_pstr_eq(strcpy(dest1, src), my_strcpy(dest2, src));
}

END_TEST

START_TEST(strcpy_8) {
  char dest1[128] = "\0";
  char dest2[128] = "\0";
  char src[128] = "\0";
  ck_assert_pstr_eq(strcpy(dest1, src), my_strcpy(dest2, src));
}

END_TEST

START_TEST(strcpy_9) {
  char dest1[128] = "Hello, world!";
  char dest2[128] = "Hello, world!";
  char src[128] = "Hello\0, world!";
  ck_assert_pstr_eq(strcpy(dest1, src), my_strcpy(dest2, src));
}

END_TEST

START_TEST(strcpy_10) {
  char dest1[128] = "123\0";
  char dest2[128] = "123\0";
  char src[128] = "Hello, world!";
  ck_assert_pstr_eq(strcpy(dest1, src), my_strcpy(dest2, src));
}

END_TEST

// strncpy

START_TEST(strncpy_1) {
  char dest1[128] = "Hello, world!";
  char dest2[128] = "Hello, world!";
  char src[128] = "Hello\0";
  ck_assert_pstr_eq(strncpy(dest1, src, 5), my_strncpy(dest2, src, 5));
}

END_TEST

START_TEST(strncpy_2) {
  char dest1[128] = "Hello, world!";
  char dest2[128] = "Hello, world!";
  char src[128] = "Hello\0";
  ck_assert_pstr_eq(strncpy(dest1, src, 6), my_strncpy(dest2, src, 6));
}

END_TEST

START_TEST(strncpy_3) {
  char dest1[128] = "Hello\0, world!";
  char dest2[128] = "Hello\0, world!";
  char src[128] = "Hello";
  ck_assert_pstr_eq(strncpy(dest1, src, 7), my_strncpy(dest2, src, 7));
}

END_TEST

START_TEST(strncpy_4) {
  char dest1[128] = "";
  char dest2[128] = "";
  char src[128] = "";
  ck_assert_pstr_eq(strncpy(dest1, src, 1), my_strncpy(dest2, src, 1));
}

END_TEST

START_TEST(strncpy_5) {
  char dest1[128] = "\0123";
  char dest2[128] = "\0123";
  char src[128] = "\0";
  ck_assert_pstr_eq(strncpy(dest1, src, 1), my_strncpy(dest2, src, 1));
}

END_TEST

START_TEST(strncpy_6) {
  char dest1[128] = "";
  char dest2[128] = "";
  char src[128] = "\0";
  ck_assert_pstr_eq(strncpy(dest1, src, 1), my_strncpy(dest2, src, 1));
}

END_TEST

START_TEST(strncpy_7) {
  char dest1[128] = "Hello, world!";
  char dest2[128] = "Hello, world!";
  char src[128] = "";
  ck_assert_pstr_eq(strncpy(dest1, src, 5), my_strncpy(dest2, src, 5));
}

END_TEST

START_TEST(strncpy_8) {
  char dest1[128] = "Hello, world!";
  char dest2[128] = "Hello, world!";
  char src[128] = "\0";
  ck_assert_pstr_eq(strncpy(dest1, src, 5), my_strncpy(dest2, src, 5));
}

END_TEST

START_TEST(strncpy_9) {
  char dest1[128] = "Hello";
  char dest2[128] = "Hello";
  char src[128] = "World!";
  ck_assert_pstr_eq(strncpy(dest1, src, 6), my_strncpy(dest2, src, 6));
}

END_TEST

START_TEST(strncpy_10) {
  char dest1[128] = "Hello\0";
  char dest2[128] = "Hello\0";
  char src[128] = "Hello, world!";
  ck_assert_pstr_eq(strncpy(dest1, src, 5), my_strncpy(dest2, src, 5));
}

END_TEST

// strcspn

START_TEST(strcspn_1) {
  char str1[] = "Hello, world!";
  ck_assert_int_eq(strcspn(str1, "lrd"), my_strcspn(str1, "lrd"));
}

END_TEST

START_TEST(strcspn_2) {
  char str1[] = "Hello, world!";
  ck_assert_int_eq(strcspn(str1, "erd"), my_strcspn(str1, "erd"));
}

END_TEST

START_TEST(strcspn_3) {
  char str1[] = "Hello, world!";
  ck_assert_int_eq(strcspn(str1, "ll"), my_strcspn(str1, "ll"));
}

END_TEST

START_TEST(strcspn_4) {
  char str1[] = "Hello, world!";
  ck_assert_int_eq(strcspn(str1, "d"), my_strcspn(str1, "d"));
}

END_TEST

START_TEST(strcspn_5) {
  char str1[] = "Hello, world!";
  ck_assert_int_eq(strcspn(str1, "\0"), my_strcspn(str1, "\0"));
}

END_TEST

START_TEST(strcspn_6) {
  char str1[] = "Hello, world!";
  ck_assert_int_eq(strcspn(str1, " ,"), my_strcspn(str1, " ,"));
}

END_TEST

START_TEST(strcspn_7) {
  char str1[14] = {'H', 'e', 'l', 'l', 'o', ',', ' ',
                   'w', 'o', 'r', 'l', 'd', '!'};
  ck_assert_int_eq(strcspn(str1, " ,"), my_strcspn(str1, " ,"));
}

END_TEST

START_TEST(strcspn_8) {
  char str1[14] = {'H', 'e', 'l', 'l', 'o', ',', ' ',
                   'w', 'o', 'r', 'l', 'd', '!'};
  ck_assert_int_eq(strcspn(str1, "ll"), my_strcspn(str1, "ll"));
}

END_TEST

START_TEST(strcspn_9) {
  char str1[14] = {'H', 'e', 'l', 'l', 'o', ',', ' ',
                   'w', 'o', 'r', 'l', 'd', '!'};
  ck_assert_int_eq(strcspn(str1, "o"), my_strcspn(str1, "o"));
}

END_TEST

START_TEST(strcspn_10) {
  char str1[14] = {'H', 'e', 'l', 'l', 'o', ',', ' ',
                   'w', 'o', 'r', 'l', 'd', '!'};
  ck_assert_int_eq(strcspn(str1, "world!"), my_strcspn(str1, "world!"));
}

END_TEST

//  strerror

START_TEST(strerror_test) {
  for (int i = -1; i < INDEX + 2; i++) {
    ck_assert_str_eq(my_strerror(i), strerror(i));
  }
}

END_TEST

// strlen

START_TEST(strlen_1) {
  char *str = "Hello world\0";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}

END_TEST

START_TEST(strlen_2) {
  char *str = "Hello world\n \0HELLO!";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}

END_TEST

START_TEST(strlen_3) {
  char *str = "\0";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}

END_TEST

START_TEST(strlen_4) {
  char *str = "a\n\0";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}

END_TEST

START_TEST(strlen_5) {
  char *str = " \n\0";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}

END_TEST

START_TEST(strlen_6) {
  char *str = "NULLNULLNULL\\0";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}

END_TEST

START_TEST(strlen_7) {
  char *str = "\n\0";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}

END_TEST

START_TEST(strlen_8) {
  char *str = "\\n\\0";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}

END_TEST

START_TEST(strlen_9) {
  char *str = "Hello world";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}

END_TEST

START_TEST(strlen_10) {
  char *str = "\t00\n";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}

END_TEST

// strpbrk

START_TEST(strpbrk_1) {
  char str[] = "Hello world!";
  ck_assert_pstr_eq(strpbrk(str, "Hello"), my_strpbrk(str, "Hello"));
}

END_TEST

START_TEST(strpbrk_2) {
  char str[] = "Hello world!";
  ck_assert_pstr_eq(strpbrk(str, "W0rld"), my_strpbrk(str, "W0rld"));
}

END_TEST

START_TEST(strpbrk_3) {
  char str[] = "Hello world!";
  ck_assert_pstr_eq(strpbrk(str, ""), my_strpbrk(str, ""));
}

END_TEST

START_TEST(strpbrk_4) {
  char str[] = "Hello world!";
  ck_assert_pstr_eq(strpbrk(str, "\0"), my_strpbrk(str, "\0"));
}

END_TEST

START_TEST(strpbrk_5) {
  char str[] = "Hello world!";
  ck_assert_pstr_eq(strpbrk(str, "123"), my_strpbrk(str, "123"));
}

END_TEST

START_TEST(strpbrk_6) {
  char str[] = "Hello world!";
  ck_assert_pstr_eq(strpbrk(str, "\n "), my_strpbrk(str, "\n "));
}

END_TEST

START_TEST(strpbrk_7) {
  char str[] = "Hello world!";
  ck_assert_pstr_eq(strpbrk(str, ".,!:;"), my_strpbrk(str, ".,!:;"));
}

END_TEST

START_TEST(strpbrk_8) {
  char str[] = "Hello world!";
  ck_assert_pstr_eq(strpbrk(str, "////"), my_strpbrk(str, "////"));
}

END_TEST

START_TEST(strpbrk_9) {
  char str[] = "Hello\0 world!";
  ck_assert_pstr_eq(strpbrk(str, "\0\0"), my_strpbrk(str, "\0\0"));
}

END_TEST

START_TEST(strpbrk_10) {
  char str[] = "Hello\n world\0!!!";
  ck_assert_pstr_eq(strpbrk(str, "!!!"), my_strpbrk(str, "!!!"));
}

END_TEST

// strrchr

START_TEST(strrchr_1) {
  char str[] = "01234567890123456789";
  ck_assert_pstr_eq(strrchr(str, '6'), my_strrchr(str, '6'));
}

END_TEST

START_TEST(strrchr_2) {
  char str[] = "Hello, world!";
  ck_assert_pstr_eq(strrchr(str, 'o'), my_strrchr(str, 'o'));
}

END_TEST

START_TEST(strrchr_3) {
  char str[] = "01234567890123456789";
  ck_assert_pstr_eq(strrchr(str, 'a'), my_strrchr(str, 'a'));
}

END_TEST

START_TEST(strrchr_4) {
  char str[] = "01234567890123456789";
  ck_assert_pstr_eq(strrchr(str, '!'), my_strrchr(str, '!'));
}

END_TEST

START_TEST(strrchr_5) {
  char str[] = "Hello, world!";
  ck_assert_pstr_eq(strrchr(str, '\0'), my_strrchr(str, '\0'));
}

END_TEST

START_TEST(strrchr_6) {
  char str[] = "Hello\0, world!";
  ck_assert_pstr_eq(strrchr(str, 'o'), my_strrchr(str, 'o'));
}

END_TEST

START_TEST(strrchr_7) {
  char str[] = "Hello\0, world!";
  ck_assert_pstr_eq(strrchr(str, 'O'), my_strrchr(str, 'O'));
}

END_TEST

START_TEST(strrchr_8) {
  char str[] = "Hello, \n\0\tworld!";
  ck_assert_pstr_eq(strrchr(str, '\t'), my_strrchr(str, '\t'));
}

END_TEST

START_TEST(strrchr_9) {
  char str[] = "Hello,    world!";
  ck_assert_pstr_eq(strrchr(str, ' '), my_strrchr(str, ' '));
}

END_TEST

START_TEST(strrchr_10) {
  char str[] = "";
  ck_assert_pstr_eq(strrchr(str, ' '), my_strrchr(str, ' '));
}

END_TEST

// strspn

START_TEST(strspn_1) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strspn(str, "ldrwo"), my_strspn(str, "ldrwo"));
}

END_TEST

START_TEST(strspn_2) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strspn(str, " , "), my_strspn(str, " , "));
}

END_TEST

START_TEST(strspn_3) {
  char str[] = "Hello\0, world!";
  ck_assert_int_eq(strspn(str, "ldrwo"), my_strspn(str, "ldrwo"));
}

END_TEST

START_TEST(strspn_4) {
  char str[] = "Hello, \0world!";
  ck_assert_int_eq(strspn(str, " \0"), my_strspn(str, " \0"));
}

END_TEST

START_TEST(strspn_5) {
  char str[] = "Hello\0, world!";
  ck_assert_int_eq(strspn(str, ", "), my_strspn(str, ", "));
}

END_TEST

START_TEST(strspn_6) {
  char str[] = "Hello, world!\n";
  ck_assert_int_eq(strspn(str, "\n "), my_strspn(str, "\n "));
}

END_TEST

START_TEST(strspn_7) {
  char str[] = "Hello,\n world!";
  ck_assert_int_eq(strspn(str, "\n"), my_strspn(str, "\n"));
}

END_TEST

START_TEST(strspn_8) {
  char str[] = "\0";
  ck_assert_int_eq(strspn(str, "\0"), my_strspn(str, "\0"));
}

END_TEST

START_TEST(strspn_9) {
  char str[] = "";
  ck_assert_int_eq(strspn(str, "ldrwo"), my_strspn(str, "ldrwo"));
}

END_TEST

START_TEST(strspn_10) {
  char str[] = "\0";
  ck_assert_int_eq(strspn(str, "ldrwo"), my_strspn(str, "ldrwo"));
}

END_TEST

// strstr

START_TEST(strstr_1) {
  char str[] = "";
  ck_assert_pstr_eq(strstr(str, ""), my_strstr(str, ""));
}

END_TEST

START_TEST(strstr_2) {
  char str[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(str, "Hello"), my_strstr(str, "Hello"));
}

END_TEST

START_TEST(strstr_3) {
  char str[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(str, "123"), my_strstr(str, "123"));
}

END_TEST

START_TEST(strstr_4) {
  char str[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(str, "Orl"), my_strstr(str, "Orl"));
}

END_TEST

START_TEST(strstr_5) {
  char str[] = "Hello\0, world!";
  ck_assert_pstr_eq(strstr(str, ", "), my_strstr(str, ", "));
}

END_TEST

START_TEST(strstr_6) {
  char str[] = "Hello, world!\0";
  ck_assert_pstr_eq(strstr(str, "Hello, world!\0"),
                    my_strstr(str, "Hello, world!\0"));
}

END_TEST

START_TEST(strstr_7) {
  char str[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(str, "Hello, world!\0"),
                    my_strstr(str, "Hello, world!\0"));
}

END_TEST

START_TEST(strstr_8) {
  char str[] = "Hello, \nworld!";
  ck_assert_pstr_eq(strstr(str, "\n"), my_strstr(str, "\n"));
}

END_TEST

START_TEST(strstr_9) {
  char str[] = "";
  ck_assert_pstr_eq(strstr(str, "\0"), my_strstr(str, "\0"));
}

END_TEST

START_TEST(strstr_10) {
  char str[] = "\0";
  ck_assert_pstr_eq(strstr(str, ""), my_strstr(str, ""));
}

END_TEST

// strtok

START_TEST(strtok_test) {
  char str[12][50] = {"Hello world",  "Hello world\n", "a\n",
                      "     \n",      "NULL",          "Hello, world\n",
                      "abababababa",  "aaaaaa",        "\n\n\n\0",
                      "NULLNULLNULL", "Hello",         "I love 21 school!"};
  char delim[12][50] = {"l", " ", "\n", "0", "N",  "Hello, world",
                        "b", "a", "\n", "U", "He", "21"};
  for (int i = 0; i < 12; i++) {
    ck_assert_ptr_eq(my_strtok(str[i], delim[i]), strtok(str[i], delim[i]));
  }
}

END_TEST

// sprintf

START_TEST(sprintf_int_1) {
  char str1[128], str2[128];
  ck_assert_int_eq(my_sprintf(str1, "n%d", 123), sprintf(str2, "n%d", 123));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_int_2) {
  char str1[128], str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%.7d", 123), sprintf(str2, "%.7d", 123));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_int_3) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%3i", 111), sprintf(str2, "%3i", 111));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_int_4) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%-8d", 123), sprintf(str2, "%-8d", 123));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_int_5) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%+4i", 123), sprintf(str2, "%+4i", 123));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_int_6) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%.0d", 1), sprintf(str2, "%.0d", 1));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_int_7) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "% d", 0), sprintf(str2, "% d", 0));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_ld) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%10ld", (long int)1),
                   sprintf(str2, "%10ld", (long int)1));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_hd) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%hi%hd%hu", (short int)123,
                              (short int)-111, (short int)100),
                   sprintf(str2, "%hi%hd%hu", (short int)123, (short int)-111,
                           (short int)100));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_li_1) {
  char str1[256];
  char str2[256];
  char *format = "%+li%+lu%+d";
  ck_assert_int_eq(my_sprintf(str1, format, -123, 999, -111),
                   sprintf(str2, format, -123, 999, -111));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_li_2) {
  char str1[256];
  char str2[256];
  char *format = "%-11.11li%-35.5lu%-3.5ld";
  ck_assert_int_eq(
      my_sprintf(str1, format, 66666666666, 5555555555, 44444444444),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_li_3) {
  char str1[256];
  char str2[256];
  char *format = "% 0.0li% 0.0lu% 0.0ld";
  ck_assert_int_eq(my_sprintf(str1, format, 11, 2, 4444333333),
                   sprintf(str2, format, 11, 2, 4444333333));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_unsgint_1) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%u", (unsigned int)123),
                   sprintf(str2, "%u", (unsigned int)123));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_unsgint_2) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%9u", (unsigned int)12345),
                   sprintf(str2, "%9u", (unsigned int)12345));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_unsgint_3) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%-16u", (unsigned int)12345),
                   sprintf(str2, "%-16u", (unsigned int)12345));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_unsgint_4) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%.51u", (unsigned int)12345),
                   sprintf(str2, "%.51u", (unsigned int)12345));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_unsgint_5) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%40.4u", (unsigned int)12345),
                   sprintf(str2, "%40.4u", (unsigned int)12345));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_unsgint_6) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%u", (unsigned)0),
                   sprintf(str2, "%u", (unsigned)0));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_unsgint_short) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%hu", (unsigned short int)12345),
                   sprintf(str2, "%hu", (unsigned short int)12345));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_unsgint_long) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%lu", (unsigned long int)1234567890),
                   sprintf(str2, "%lu", (unsigned long int)1234567890));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_unsgint_all) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(
      my_sprintf(str1, "%lu, %u, %hu, %.5u, %5.u",
                 (unsigned long int)1234567890, (unsigned)11,
                 (unsigned short)1111, (unsigned)11111, (unsigned)1234),
      sprintf(str2, "%lu, %u, %hu, %.5u, %5.u", (unsigned long int)1234567890,
              (unsigned)11, (unsigned short)1111, (unsigned)11111,
              (unsigned)1234));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_iint_1) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_iint_2) {
  char str1[128];
  char str2[128];
  ck_assert_int_eq(my_sprintf(str1, "%i%i%i", -128, 256, 0),
                   sprintf(str2, "%i%i%i", -128, 256, 0));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_float_1) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(my_sprintf(str1, "%f", 0.0003), sprintf(str2, "%f", 0.0003));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_float_2) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(
      my_sprintf(str1, "%f%f%f%f", -123.456, 123.456, 0.0001, -100.001),
      sprintf(str2, "%f%f%f%f", -123.456, 123.456, 0.0001, -100.001));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_float_3) {
  char str1[256];
  char str2[256];
  char *format = "% f";
  double d = 0.000000000;
  ck_assert_int_eq(my_sprintf(str1, format, (float)d),
                   sprintf(str2, format, (float)d));
}

END_TEST

START_TEST(sprintf_float_4) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(my_sprintf(str1, "%1.1f", 1.1), sprintf(str2, "%1.1f", 1.1));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_float_5) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(my_sprintf(str1, "%7.7f", 123.4567890),
                   sprintf(str2, "%7.7f", 123.4567890));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_float_6) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(my_sprintf(str1, "%.f", 123.456),
                   sprintf(str2, "%.f", 123.456));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_char_1) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(my_sprintf(str1, "%c", 'H'), sprintf(str2, "%c", 'H'));
  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(sprintf_char_2) {
  char str1[256];
  char str2[256];
  char *format = "%.5c";
  ck_assert_int_eq(my_sprintf(str1, format, 'e'), sprintf(str2, format, 'e'));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_char_3) {
  char str1[256];
  char str2[256];
  char *format = "% -7c";
  ck_assert_int_eq(my_sprintf(str1, format, 'l'), sprintf(str2, format, 'l'));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_char_4) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(my_sprintf(str1, "%11c", 'l'), sprintf(str2, "%11c", 'l'));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_char_5) {
  char str1[256];
  char str2[256];
  char *format = "%-10.5c";
  ck_assert_int_eq(my_sprintf(str1, format, 'o'), sprintf(str2, format, 'o'));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_char_6) {
  char str1[256];
  char str2[256];
  char *format = "%-5.3c%c%c%c%c, world!";
  ck_assert_int_eq(my_sprintf(str1, format, 'H', 'e', 'l', 'l', 'o'),
                   sprintf(str2, format, 'H', 'e', 'l', 'l', 'o'));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_char_7) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(my_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_char_8) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(
      my_sprintf(str1, "%c%c%c%c%c%c", '\t', '\n', '0', 'S', 's', '!'),
      sprintf(str2, "%c%c%c%c%c%c", '\t', '\n', '0', 'S', 's', '!'));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_str_1) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(my_sprintf(str1, "%s", "Hello, world!"),
                   sprintf(str2, "%s", "Hello, world!"));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_str_2) {
  char str1[256];
  char str2[256];
  char *format = "%.9s";
  ck_assert_int_eq(my_sprintf(str1, format, "Hello, world!"),
                   sprintf(str2, format, "Hello, world!"));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_str_3) {
  char str1[256];
  char str2[256];
  char *format = "%15s";
  ck_assert_int_eq(my_sprintf(str1, format, "Hello, world!"),
                   sprintf(str2, format, "Hello, world!"));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_str_4) {
  char str1[256];
  char str2[256];
  char *format = "%-20.10s";
  ck_assert_int_eq(my_sprintf(str1, format, "Hello, world!"),
                   sprintf(str2, format, "Hello, world!"));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_str_5) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(my_sprintf(str1, "%s", "Hello, world!"),
                   sprintf(str2, "%s", "Hello, world!"));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_str_6) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(my_sprintf(str1, "%s%s%s", "Hello, world!", "", "12345"),
                   sprintf(str2, "%s%s%s", "Hello, world!", "", "12345"));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_str_7) {
  char str1[256];
  char str2[256];
  char *format = "%111s";
  ck_assert_int_eq(my_sprintf(str1, format, "Hello, world!"),
                   sprintf(str2, format, "Hello, world!"));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(sprintf_str_8) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(my_sprintf(str1, "%4.4s", ""), sprintf(str2, "%4.4s", ""));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_my_to_upper_1) {
  char *my_result = my_to_upper("Hello");
  char *original_result = "HELLO";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_to_upper_2) {
  char *my_result = my_to_upper("01My 78 // DEAR friend,");
  char *original_result = "01MY 78 // DEAR FRIEND,";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_to_upper_3) {
  char *my_result = my_to_upper("ONE TWO");
  char *original_result = "ONE TWO";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_to_upper_4) {
  char *my_result = my_to_upper(MY_NULL);
  char *original_result = MY_NULL;
  ck_assert_ptr_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_to_upper_5) {
  char *my_result = my_to_upper(" ");
  char *original_result = " ";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_to_upper_6) {
  char *my_result = my_to_upper("\n");
  char *original_result = "\n";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_to_lower_1) {
  char *my_result = my_to_lower("Hello");
  char *original_result = "hello";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_to_lower_2) {
  char *my_result = my_to_lower("01My 78 // DEAR friend,");
  char *original_result = "01my 78 // dear friend,";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_to_lower_3) {
  char *my_result = my_to_lower("one");
  char *original_result = "one";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_to_lower_4) {
  char *my_result = my_to_lower(MY_NULL);
  char *original_result = MY_NULL;
  ck_assert_ptr_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_to_lower_5) {
  char *my_result = my_to_lower(" ");
  char *original_result = " ";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_to_lower_6) {
  char *my_result = my_to_lower("\n");
  char *original_result = "\n";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_insert_1) {
  char str[] = "Hello !";
  char src[] = "World";
  my_size_t index = 6;
  char original_result[] = "Hello World!";
  char *my_result = (char *)my_insert(str, src, index);
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_insert_2) {
  char *src = "job";
  char *str = "Good ";
  my_size_t index = 5;
  char *my_result = (char *)my_insert(str, src, index);
  char *original_result = "Good job";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_insert_3) {
  char *str1 = "Good ";
  char *str2 = "job";
  my_size_t index = 5;
  char *my_result = my_insert(str1, str2, index);
  char *original_result = "Good job";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_insert_4) {
  char *str2 = " !";
  char *str1 = "Good";
  my_size_t index = 4;
  char *my_result = my_insert(str1, str2, index);
  char *original_result = "Good !";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_trim_1) {
  char *str1 = "Hello";
  char *str2 = "l";
  char *my_result = my_trim(str1, str2);
  char *original_result = "Hello";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_trim_2) {
  char *str1 = "ABCDIEFD";
  char *str2 = "ABC";
  char *my_result = my_trim(str1, str2);
  char *original_result = "DIEFD";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_trim_3) {
  char *str1 = "My names Ana";
  char *str2 = "na";
  char *my_result = my_trim(str1, str2);
  char *original_result = "My names A";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(test_my_trim_4) {
  char *str1 = "Hello love student";
  char *str2 = "He";
  char *my_result = my_trim(str1, str2);
  char *original_result = "llo love student";
  ck_assert_str_eq(my_result, original_result);
  if (my_result)
    free(my_result);
}

END_TEST

START_TEST(sprintf_width_char) {
  char str1[256];
  char str2[256];
  char *format = "Test test test test %5c";
  char w = 'd';
  int a = my_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}

END_TEST

START_TEST(sprintf_space) {
  char str_our[10] = {0}, str_std[10] = {0};
  char format[] = "% d\0";
  int d = 42;
  int res_our = my_sprintf(str_our, format, d);
  int res_std = sprintf(str_std, format, d);
  ck_assert_str_eq(str_our, str_std);
  ck_assert_int_eq(res_our, res_std);
}

END_TEST

START_TEST(sprintf_percent) {
  char str_our[10] = {0}, str_std[10] = {0};
  char format[] = "%%%d\0";
  int d = 21;
  int res_our = my_sprintf(str_our, format, d);
  int res_std = sprintf(str_std, format, d);
  ck_assert_str_eq(str_our, str_std);
  ck_assert_int_eq(res_our, res_std);
}

END_TEST

START_TEST(sprintf_float_zero) {
  char str_our[10] = {0};
  int res_our = my_sprintf(str_our, "%4.1f", 42.0);
  char str_std[10] = {0};
  int res_std = sprintf(str_std, "%4.1f", 42.0);
  ck_assert_str_eq(str_our, str_std);
  ck_assert_int_eq(res_our, res_std);
}

END_TEST

START_TEST(my_sprintf_c_test_1) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%c  %c", 'a', 'b'),
                   my_sprintf(my_s, "%c  %c", 'a', 'b'));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_2) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%c%c", '\t', '\n'),
                   my_sprintf(my_s, "%c%c", '\t', '\n'));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_3) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%c%c", 3, 'a'),
                   my_sprintf(my_s, "%c%c", 3, 'a'));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_4) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%c%c", -1, 1), my_sprintf(my_s, "%c%c", -1, 1));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_5) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%lc  %lc", L'a', L'b'),
                   my_sprintf(my_s, "%lc  %lc", L'a', L'b'));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_6) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%5c", 'a'), my_sprintf(my_s, "%5c", 'a'));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_8) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%-5c", 'a'), my_sprintf(my_s, "%-5c", 'a'));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_9) {
  char s[40] = "";
  char my_s[40] = "";
  char *format = "%+5c";
  ck_assert_int_eq(sprintf(s, format, 'a'), my_sprintf(my_s, format, 'a'));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_10) {
  char s[400] = "";
  char my_s[40] = "";
  char c = 'a';
  ck_assert_int_eq(sprintf(s, "%20c", c), my_sprintf(my_s, "%20c", c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_11) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%20.10c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_12) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%10.20c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_13) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%-20c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_15) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%-020c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_16) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%.10c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_17) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%-.10c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_18) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%0.10c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_19) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%-0.10c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_20) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%-0.20c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_21) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%-020.10c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_22) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%-010.20c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_23) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%-+20c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_24) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%-+20c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_25) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "%-+#20.10c";
  ck_assert_int_eq(sprintf(s, format, c), my_sprintf(my_s, format, c));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_c_test_26) {
  char s[400] = "";
  char my_s[400] = "";
  char c = 'a';
  char *format = "-+#*.*c";
  ck_assert_int_eq(sprintf(s, format, 20, 10, c),
                   my_sprintf(my_s, format, 20, 10, c));
  ck_assert_str_eq(s, my_s);
  printf("Start group test sprintf %%i\n");
}

END_TEST

START_TEST(my_sprintf_i_test_1) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%i%i";
  ck_assert_int_eq(sprintf(s, format, 9, 0xf),
                   my_sprintf(my_s, format, 9, 0xf));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_i_test_2) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%i%i", 10, '1'),
                   my_sprintf(my_s, "%i%i", 10, '1'));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_i_test_3) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%i%i", 012, 0x27),
                   my_sprintf(my_s, "%i%i", 012, 0x27));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_i_test_4) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%10i %10i", 255, 0xFF),
                   my_sprintf(my_s, "%10i %10i", 255, 0xFF));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_i_test_5) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%-10i %-10i", 255, 0xFF),
                   my_sprintf(my_s, "%-10i %-10i", 255, 0xFF));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_i_test_6) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%-010i %-010i";
  ck_assert_int_eq(sprintf(s, format, 255, 0xFF),
                   my_sprintf(my_s, format, 255, 0xFF));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_i_test_7) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%010i %010i";
  ck_assert_int_eq(sprintf(s, format, 255, 0xFF),
                   my_sprintf(my_s, format, 255, 0xFF));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_i_test_8) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "% 10i % 10i", 255, 0xFF),
                   my_sprintf(my_s, "% 10i % 10i", 255, 0xFF));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_i_test_9) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "% -10i % -10i", 255, 0xFF),
                   my_sprintf(my_s, "% -10i % -10i", 255, 0xFF));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_i_test_10) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%+-10i %+-10i", 255, 0xFF),
                   my_sprintf(my_s, "%+-10i %+-10i", 255, 0xFF));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_i_test_11) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%#10i %#10i";
  ck_assert_int_eq(sprintf(s, format, 255, 0xFF),
                   my_sprintf(my_s, format, 255, 0xFF));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_i_test_12) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%#10i %#10i";
  ck_assert_int_eq(sprintf(s, format, 255, 0xFF),
                   my_sprintf(my_s, format, 255, 0xFF));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_i_test_13) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%#10i %#10i";
  ck_assert_int_eq(sprintf(s, format, 255, 20, 10, 0xFF),
                   my_sprintf(my_s, format, 255, 20, 10, 0xFF));
  ck_assert_str_eq(s, my_s);
  printf("Start group test sprintf %%u\n");
}

END_TEST

START_TEST(my_sprintf_u_test_1) {
  char s[100] = "";
  char my_s[100] = "";
  ck_assert_uint_eq(sprintf(s, "%u %u", 1, 9), my_sprintf(my_s, "%u %u", 1, 9));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_u_test_2) {
  char s[100] = "";
  char my_s[100] = "";
  ck_assert_uint_eq(sprintf(s, "%-u %u", 1, 9),
                    my_sprintf(my_s, "%-u %u", 1, 9));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_u_test_3) {
  char s[100] = "";
  char my_s[100] = "";
  char *format = "%-10u %+10u";
  ck_assert_uint_eq(sprintf(s, format, 1, 9), my_sprintf(my_s, format, 1, 9));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_u_test_4) {
  char s[100] = "";
  char my_s[100] = "";
  char *format = "%-10.5u %10.5u";
  ck_assert_int_eq(sprintf(s, format, 1, 9), my_sprintf(my_s, format, 1, 9));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_u_test_5) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%-#20u";
  ck_assert_int_eq(sprintf(s, format, 505), my_sprintf(my_s, format, 505));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_u_test_6) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%-#20u";
  ck_assert_int_eq(sprintf(s, format, 505), my_sprintf(my_s, format, 505));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_u_test_7) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%020u", 505), my_sprintf(my_s, "%020u", 505));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_u_test_8) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%-+020u";
  ck_assert_int_eq(sprintf(s, format, 505), my_sprintf(my_s, format, 505));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_u_test_9) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%+020u";
  ck_assert_int_eq(sprintf(s, format, 505), my_sprintf(my_s, format, 505));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_u_test_10) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%0*.*u";
  ck_assert_int_eq(sprintf(s, format, 10, 10, 505),
                   my_sprintf(my_s, format, 10, 10, 505));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_test_LINES) {
  char s[100] = "";
  char my_s[100] = "";
  ck_assert_uint_eq(sprintf(s, "some garbage: %2c %-3d %3d %.9f %u %s  ", 'X',
                            13, 13, 42.1, -9, "privet or poka"),
                    my_sprintf(my_s, "some garbage: %2c %-3d %3d %.9f %u %s  ",
                               'X', 13, 13, 42.1, -9, "privet or poka"));
  ck_assert_str_eq(s, my_s);
  printf("Start group test sprintf %%d\n");
}

END_TEST

START_TEST(my_sprintf_d_test_0) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%d", 1), my_sprintf(my_s, "%d", 1));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_lh_test_1) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%2d%2.2d", -1, 1),
                   my_sprintf(my_s, "%2d%2.2d", -1, 1));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_1) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%2d%2.2d", -1, 1),
                   my_sprintf(my_s, "%2d%2.2d", -1, 1));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_2) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%5.d%.5d", 21, -42),
                   my_sprintf(my_s, "%5.d%.5d", 21, -42));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_3) {
  char s[40] = "";
  char my_s[40] = "";
  char *format = "%ld%hd";
  ck_assert_int_eq(sprintf(s, format, -1, 1), my_sprintf(my_s, format, -1, 1));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_4) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%+d % d", 21, 42),
                   my_sprintf(my_s, "%+d % d", 21, 42));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_5) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%d", -12), my_sprintf(my_s, "%d", -12));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_6) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%-6d", -12), my_sprintf(my_s, "%-6d", -12));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_7) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "% 3d", 123456),
                   my_sprintf(my_s, "% 3d", 123456));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_8) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%-d", -12), my_sprintf(my_s, "%-d", -12));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_9) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%.4d", 228), my_sprintf(my_s, "%.4d", 228));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_10) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%+10d", 2), my_sprintf(my_s, "%+10d", 2));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_11) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%+-10d", -21), my_sprintf(my_s, "%+-10d", -21));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_12) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%+10d", -21), my_sprintf(my_s, "%+10d", -21));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_13) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%-10d", 2), my_sprintf(my_s, "%-10d", 2));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_14) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "% 10d", 2), my_sprintf(my_s, "% 10d", 2));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_d_test_15) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%+-10d", 2), my_sprintf(my_s, "%+-10d", 2));
}

END_TEST

START_TEST(my_sprintf_d_test_16) {
  char s[40] = "";
  char my_s[40] = "";
  ck_assert_int_eq(sprintf(s, "%+-*.*d", 20, 10, 2),
                   my_sprintf(my_s, "%+-*.*d", 20, 10, 2));
  printf("Start group test sprintf %%%%\n");
}

END_TEST

START_TEST(my_sprintf_percent_test_1) {
  char s[100] = "";
  char my_s[100] = "";
  ck_assert_int_eq(sprintf(s, "hello %%"), my_sprintf(my_s, "hello %%"));
  ck_assert_str_eq(s, my_s);
  printf("Start group test sprintf %%s\n");
}

END_TEST

START_TEST(my_sprintf_s_test_1) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  sprintf(s, "%s", "test");
  my_sprintf(my_s, "%s", "test");
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_s_test_2) {
  char s[100] = "";
  char my_s[100] = "";
  ck_assert_int_eq(sprintf(s, "%s%s", "t\best\n", "\n \t"),
                   my_sprintf(my_s, "%s%s", "t\best\n", "\n \t"));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_s_test_3) {
  char s[100] = "";
  char my_s[100] = "";
  ck_assert_int_eq(sprintf(s, "%s%s", "", "\\"),
                   my_sprintf(my_s, "%s%s", "", "\\"));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_s_test_4) {
  char s[100] = {0};
  char my_s[100] = {0};
  ck_assert_int_eq(sprintf(s, "%20s", "UR MOMMA GAY"),
                   my_sprintf(my_s, "%20s", "UR MOMMA GAY"));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_s_test_5) {
  char s[100] = "";
  char my_s[100] = "";
  ck_assert_int_eq(sprintf(s, "%-20s", "GAY LORD"),
                   my_sprintf(my_s, "%-20s", "GAY LORD"));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_s_test_6) {
  char s[100] = "";
  char my_s[100] = "";
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_s_test_7) {
  char s[100] = "";
  char my_s[100] = "";
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_default) {
  char s[100] = "";
  char my_s[100] = "";
  char *format = " ";
  ck_assert_int_eq(sprintf(s, format, " "), my_sprintf(my_s, format, " "));
  ck_assert_str_eq(s, my_s);
  printf("Start group test sprintf %%f\n");
}

END_TEST

START_TEST(my_sprintf_f_test_0) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  ck_assert_int_eq(sprintf(s, "%-10f", -0.0), my_sprintf(my_s, "%-10f", -0.0));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_1) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  char *format = "%12f";
  ck_assert_int_eq(sprintf(s, format, 0), my_sprintf(my_s, format, 0));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_2) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  ck_assert_int_eq(sprintf(s, "%f", 0.123), my_sprintf(my_s, "%f", 0.123));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_3) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  ck_assert_int_eq(sprintf(s, "%f%f", 0.123, 0.123),
                   my_sprintf(my_s, "%f%f", 0.123, 0.123));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_4) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  ck_assert_int_eq(sprintf(s, "%f %f", 0.123, 0.123),
                   my_sprintf(my_s, "%f %f", 0.123, 0.123));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_5) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  ck_assert_int_eq(sprintf(s, "%f%f", -0.0123, -0.0123),
                   my_sprintf(my_s, "%f%f", -0.0123, -0.0123));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_6) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  ck_assert_int_eq(sprintf(s, "%f%f", -56.0123, -89.0123),
                   my_sprintf(my_s, "%f%f", -56.0123, -89.0123));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_7) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  ck_assert_int_eq(sprintf(s, "%+-f", 41.2), my_sprintf(my_s, "%+-f", 41.2));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_8) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  ck_assert_int_eq(sprintf(s, "%+-f", -41.2), my_sprintf(my_s, "%+-f", -41.2));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_9) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  char *format = "% +-f";
  ck_assert_int_eq(sprintf(s, format, -41.2), my_sprintf(my_s, format, -41.2));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_10) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  ck_assert_int_eq(sprintf(s, "% f", -41.2), my_sprintf(my_s, "% f", -41.2));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_11) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  ck_assert_int_eq(sprintf(s, "% f", 41.2), my_sprintf(my_s, "% f", 41.2));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_12) {
  char s[100] = {'\0'};
  char my_s[100] = {'\0'};
  ck_assert_int_eq(sprintf(s, "%lf", 41.2), my_sprintf(my_s, "%lf", 41.2));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_13) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%+10f", 50.123456789),
                   my_sprintf(my_s, "%+10f", 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_14) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%-10f", 50.123456789),
                   my_sprintf(my_s, "%-10f", 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%+10f", 50.123456789),
                   my_sprintf(my_s, "%+10f", 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_16) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%#10f", 50.123456789),
                   my_sprintf(my_s, "%#10f", 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_17) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%+-10f", 50.123456789),
                   my_sprintf(my_s, "%+-10f", 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_18) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%20f", 50.123456789),
                   my_sprintf(my_s, "%20f", 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_19) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%-20f", 50.123456789),
                   my_sprintf(my_s, "%-20f", 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_20) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%-+20f", 50.123456789),
                   my_sprintf(my_s, "%-+20f", 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_21) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%-#20f", 50.123456789),
                   my_sprintf(my_s, "%-#20f", 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_22) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%#20f", 50.123456789),
                   my_sprintf(my_s, "%#20f", 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_23) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%020f", 50.123456789),
                   my_sprintf(my_s, "%020f", 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_24) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%-020f";
  ck_assert_int_eq(sprintf(s, format, 50.123456789),
                   my_sprintf(my_s, format, 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_25) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%020.10f", 50.123456789),
                   my_sprintf(my_s, "%020.10f", 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_26) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%-020.10f";
  ck_assert_int_eq(sprintf(s, format, 50.123456789),
                   my_sprintf(my_s, format, 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_27) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%010.16f", 50.123456789),
                   my_sprintf(my_s, "%010.16f", 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_28) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%-010.16f";
  ck_assert_int_eq(sprintf(s, format, 50.123456789),
                   my_sprintf(my_s, format, 50.123456789));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_29) {
  char s[400] = "";
  char my_s[400] = "";
  char *format = "%020.10f";
  ck_assert_int_eq(sprintf(s, format, NAN), my_sprintf(my_s, format, NAN));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_30) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%020.10f", -NAN),
                   my_sprintf(my_s, "%020.10f", -NAN));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_31) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%*.*f", 20, 10, -NAN),
                   my_sprintf(my_s, "%*.*f", 20, 10, -NAN));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_32) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%020.10F", NAN),
                   my_sprintf(my_s, "%020.10F", NAN));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_f_test_33) {
  char s[400] = "";
  char my_s[400] = "";
  ck_assert_int_eq(sprintf(s, "%020.10F", -NAN),
                   my_sprintf(my_s, "%020.10F", -NAN));
  ck_assert_str_eq(s, my_s);
}

END_TEST

START_TEST(my_sprintf_test_1) {
  char str1[1000];
  char str2[1000];
  char *format = "%-3.4hi`% .9i% hi1% hie[";
  ck_assert_int_eq(my_sprintf(str1, format, 14041, 335953, -19935, -8407),
                   sprintf(str2, format, 14041, 335953, -19935, -8407));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_2) {
  char str1[1000];
  char str2[1000];
  char *format = "% 9hd-";
  ck_assert_int_eq(my_sprintf(str1, format, -18939),
                   sprintf(str2, format, -18939));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_3) {
  char str1[1000];
  char str2[1000];
  char *format = "%-4hd%-2hi%-8hiq%+hd";
  ck_assert_int_eq(my_sprintf(str1, format, -17643, 13118, -6230, 5128),
                   sprintf(str2, format, -17643, 13118, -6230, 5128));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_4) {
  char str1[1000];
  char str2[1000];
  char *format = "%-10.10hdu% 7.4ds%+.8hi%+f1i-%-1.5hu%+f%-3.8hd";
  ck_assert_int_eq(
      my_sprintf(str1, format, 23648, -555935, 17624, 296.1368183037445, 25563,
                 344.61232124755765, -24822),
      sprintf(str2, format, 23648, -555935, 17624, 296.1368183037445, 25563,
              344.61232124755765, -24822));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_5) {
  char str1[1000];
  char str2[1000];
  ck_assert_int_eq(my_sprintf(str1, "%-8d%-10.9s-v%+.5db%+.4dm", -772441,
                              "5wj/j", -608735, -969186),
                   sprintf(str2, "%-8d%-10.9s-v%+.5db%+.4dm", -772441, "5wj/j",
                           -608735, -969186));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_6) {
  char str1[1000];
  char str2[1000];
  char *format = "%+.10hi0";
  ck_assert_int_eq(my_sprintf(str1, format, -9713),
                   sprintf(str2, format, -9713));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_7) {
  char str1_7[1000];
  char str2_7[1000];
  char *format = "% d,u%+6hd%+.8f%+hi";
  ck_assert_int_eq(
      my_sprintf(str1_7, format, 963573, -30607, -22433.816055572064, -6015),
      sprintf(str2_7, format, 963573, -30607, -22433.816055572064, -6015));
  ck_assert_str_eq(str1_7, str2_7);
}

END_TEST

START_TEST(my_sprintf_test_8) {
  char str1_8[1000];
  char str2_8[1000];
  char *format = "%-10u/,o%-10hihb.%-8.4sb%+hie%+9.4hd4% f";
  ck_assert_int_eq(my_sprintf(str1_8, format, 715175, -24432, "", -28253, 4912,
                              -5179.804383826965),
                   sprintf(str2_8, format, 715175, -24432, "", -28253, 4912,
                           -5179.804383826965));
  ck_assert_str_eq(str1_8, str2_8);
}

END_TEST

START_TEST(my_sprintf_test_9) {
  char str1_9[1000];
  char str2_9[1000];
  char *format = "% 8.2hd[dra% .3hi3%+4.9hdi%-10ilc5%+i% 6i%+6d%+hd";
  ck_assert_int_eq(my_sprintf(str1_9, format, 9583, 9388, -46, -332909, 345716,
                              -729090, 27648, 7340),
                   sprintf(str2_9, format, 9583, 9388, -46, -332909, 345716,
                           -729090, 27648, 7340));
  ck_assert_str_eq(str1_9, str2_9);
}

END_TEST

START_TEST(my_sprintf_test_10) {
  char str10[1000];
  char str20[1000];
  char *format = "%-8.2hd0%+4.7f%-2.1ul%-10hio%-2hu%-8.6hds";
  ck_assert_int_eq(my_sprintf(str10, format, -4857, -8889.321130669963, -328797,
                              -20398, -5454, -28318),
                   sprintf(str20, format, -4857, -8889.321130669963, -328797,
                           -20398, -5454, -28318));
  ck_assert_str_eq(str10, str20);
}

END_TEST

START_TEST(my_sprintf_test_11) {
  char str11[1000];
  char str21[1000];
  ck_assert_int_eq(my_sprintf(str11, "% .7f9", 7323.074127088405),
                   sprintf(str21, "% .7f9", 7323.074127088405));
  ck_assert_str_eq(str11, str21);
}

END_TEST

START_TEST(my_sprintf_test_12) {
  char str12[1000];
  char str22[1000];
  char *format = "% 3i% hd67% 5fnuf% hi%+2.2hd";
  ck_assert_int_eq(
      my_sprintf(str12, format, 769747, 17216, 14106.499706718036, 3028, -397),
      sprintf(str22, format, 769747, 17216, 14106.499706718036, 3028, -397));
  ck_assert_str_eq(str12, str22);
}

END_TEST

START_TEST(my_sprintf_test_13) {
  char str13[1000];
  char str23[1000];
  char *format = "%-1.7hur%-1hd% i/%-9.3hi.";
  ck_assert_int_eq(my_sprintf(str13, format, 22810, 5223, 326747, -18109),
                   sprintf(str23, format, 22810, 5223, 326747, -18109));
  ck_assert_str_eq(str13, str23);
}

END_TEST

START_TEST(my_sprintf_test_14) {
  char str1[1000];
  char str2[1000];
  char *format = "%-5hd";
  ck_assert_int_eq(my_sprintf(str1, format, 7797), sprintf(str2, format, 7797));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_15) {
  char str15[1000];
  char str25[1000];
  char *format = "%-9.10hum%+6f%+1iv% 4f%+.2dg8";
  ck_assert_int_eq(my_sprintf(str15, format, -29060, 995.5613707854264, -477384,
                              -9407.172595315968, -681488),
                   sprintf(str25, format, -29060, 995.5613707854264, -477384,
                           -9407.172595315968, -681488));
  ck_assert_str_eq(str15, str25);
}

END_TEST

START_TEST(my_sprintf_test_16) {
  char str16[1000];
  char str26[1000];
  char *format = "% 1.7f%-9.6hi6% .2d%+8.7ds% hi%-5hi%+hi%+.2hi";
  ck_assert_int_eq(my_sprintf(str16, format, -14418.471800016401, -7839, -50364,
                              795585, 28059, 28651, 25534, 126),
                   sprintf(str26, format, -14418.471800016401, -7839, -50364,
                           795585, 28059, 28651, 25534, 126));
  ck_assert_str_eq(str16, str26);
}

END_TEST

START_TEST(my_sprintf_test_17) {
  char str17[1000];
  char str27[1000];
  char *format = "%-1dv;%-7.3hi% .2hi% 1.5hd%-7hi3t% .9d%-10.10i92o";
  ck_assert_int_eq(my_sprintf(str17, format, -604818, 135, -28239, -5381, -7281,
                              412700, 352344),
                   sprintf(str27, format, -604818, 135, -28239, -5381, -7281,
                           412700, 352344));
  ck_assert_str_eq(str17, str27);
}

END_TEST

START_TEST(my_sprintf_test_18) {
  char str18[1000];
  char str28[1000];
  char *format = "%+10hdpat% .6i%+4fv1e%+7.9hdp%+d";
  ck_assert_int_eq(
      my_sprintf(str18, format, 10697, 689813, 2535.826358688669, 27104, -8958),
      sprintf(str28, format, 10697, 689813, 2535.826358688669, 27104, -8958));
  ck_assert_str_eq(str18, str28);
}

END_TEST

START_TEST(my_sprintf_test_19) {
  char str19[1000];
  char str29[1000];
  char *format = "%+1.8i-6mq%+.7f4nc%+hd%+.4hiu%-4.2hua";
  ck_assert_int_eq(
      my_sprintf(str19, format, 333112, 785.4249123367454, 18140, 9508, -12274),
      sprintf(str29, format, 333112, 785.4249123367454, 18140, 9508, -12274));
  ck_assert_str_eq(str19, str29);
}

END_TEST

START_TEST(my_sprintf_test_20) {
  char str10[1000];
  char str20[1000];
  char *format = "%-5.4s%+4.8f%+3hd%-1.3i[r2%+.3hi";
  ck_assert_int_eq(my_sprintf(str10, format, "ga;c7up,8ljnb3.u`m6;v",
                              -9285.299159823255, 10279, 552556, 12855),
                   sprintf(str20, format, "ga;c7up,8ljnb3.u`m6;v",
                           -9285.299159823255, 10279, 552556, 12855));
  ck_assert_str_eq(str10, str20);
}

END_TEST

START_TEST(my_sprintf_test_21) {
  char str11[1000];
  char str21[1000];
  char *format = "% .7d% 4.0hd`%+hdg%-10.7u% 1i";
  ck_assert_int_eq(
      my_sprintf(str11, format, 654517, -20259, -24474, -49242, -434264),
      sprintf(str21, format, 654517, -20259, -24474, -49242, -434264));
  ck_assert_str_eq(str11, str21);
}

END_TEST

START_TEST(my_sprintf_test_22) {
  char str12[1000];
  char str22[1000];
  ck_assert_int_eq(my_sprintf(str12, "%-9cb%-10.3i", 'm', -877687),
                   sprintf(str22, "%-9cb%-10.3i", 'm', -877687));
  ck_assert_str_eq(str12, str22);
}

END_TEST

START_TEST(my_sprintf_test_23) {
  char str13[1000];
  char str23[1000];
  char *format =
      "%-8.7hd% 5.5hd%-4hdaxgbm%-5.9hi%+hi5xe`%+hd% 10.8its%-9.8i% 3.9i";
  ck_assert_int_eq(my_sprintf(str13, format, -28193, -16329, -3631, 31078,
                              16949, 21700, -97599, 937455, 901222),
                   sprintf(str23, format, -28193, -16329, -3631, 31078, 16949,
                           21700, -97599, 937455, 901222));
  ck_assert_str_eq(str13, str23);
}

END_TEST

START_TEST(my_sprintf_test_24) {
  char str1[1000];
  char str2[1000];
  ck_assert_int_eq(my_sprintf(str1, "% 4.7d", -6443),
                   sprintf(str2, "% 4.7d", -6443));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_25) {
  char str1[1000];
  char str2[1000];
  char *format = "%+hd[%+f3n%+i%-5.7u%+4i%+d%-1c";
  ck_assert_int_eq(my_sprintf(str1, format, 8429, -376.4499578468168, -397689,
                              280735, -835352, -91685, '/'),
                   sprintf(str2, format, 8429, -376.4499578468168, -397689,
                           280735, -835352, -91685, '/'));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_26) {
  char str16[1000];
  char str26[1000];
  char *format = "% fm%+6.7hi%+iz%-5.5hu% 5.3hd%-7hde3.ww8%-1huz%+.2i";
  ck_assert_int_eq(my_sprintf(str16, format, 6498.984921721617, -30334, -105739,
                              16826, 11755, 27864, 15927, 519492),
                   sprintf(str26, format, 6498.984921721617, -30334, -105739,
                           16826, 11755, 27864, 15927, 519492));
  ck_assert_str_eq(str16, str26);
}

END_TEST

START_TEST(my_sprintf_test_27) {
  char str17[1000];
  char str27[1000];
  char *format = "% 7.1dx%-7hdbl% dc%+.5hi%-6.7f7qw%-5.4ucej1=4% i4kk";
  ck_assert_int_eq(my_sprintf(str17, format, 757814, 3437, 321862, -5243,
                              -9653.053297656352, 979188, -749567),
                   sprintf(str27, format, 757814, 3437, 321862, -5243,
                           -9653.053297656352, 979188, -749567));
  ck_assert_str_eq(str17, str27);
}

END_TEST

START_TEST(my_sprintf_test_28) {
  char str18[1000];
  char str28[1000];
  char *format = "%+fn2% 3.5hd-% 1.9hd%-6.4hi`%-8.8hd/%-5.5hu% .0hi";
  ck_assert_int_eq(my_sprintf(str18, format, -16189.245738990434, 16085, -31875,
                              11189, -4034, 2519, -2218),
                   sprintf(str28, format, -16189.245738990434, 16085, -31875,
                           11189, -4034, 2519, -2218));
  ck_assert_str_eq(str18, str28);
}

END_TEST

START_TEST(my_sprintf_test_29) {
  char str19[1000];
  char str29[1000];
  char *format = "%+7.8hie";
  ck_assert_int_eq(my_sprintf(str19, format, 15877),
                   sprintf(str29, format, 15877));
  ck_assert_str_eq(str19, str29);
}

END_TEST

START_TEST(my_sprintf_test_30) {
  char str10[1000];
  char str20[1000];
  char *format = "% 3fv% .4ipd0%-10.0s%+.0hd2% 2.6hdj% .4d";
  ck_assert_int_eq(my_sprintf(str10, format, -26633.903149775222, 670438,
                              "rr3i0g1;uitthc;wh0dl[", -12123, 7834, -231792),
                   sprintf(str20, format, -26633.903149775222, 670438,
                           "rr3i0g1;uitthc;wh0dl[", -12123, 7834, -231792));
  ck_assert_str_eq(str10, str20);
}

END_TEST

START_TEST(my_sprintf_test_31) {
  char str11[1000];
  char str21[1000];
  char *format =
      "%+.1f%+.5f=t.a%+dl[b0dxhx1%-5.2dozw% 2hdz%-4hu%-7hd%+.1fk%-4.1ue";
  ck_assert_int_eq(
      my_sprintf(str11, format, -12708.572893094994, 5366.963461066268, -532198,
                 547134, 24933, -5388, -15277, 23055.43779178404, 640042),
      sprintf(str21, format, -12708.572893094994, 5366.963461066268, -532198,
              547134, 24933, -5388, -15277, 23055.43779178404, 640042));
  ck_assert_str_eq(str11, str21);
}

END_TEST

START_TEST(my_sprintf_test_32) {
  char str12[1000];
  char str22[1000];
  char *format = "%+10diy7s%-7sc;5t%-7.4hdf%-2.6siw%-3.7hd%+6.7f%-2fb%-4hd";
  ck_assert_int_eq(my_sprintf(str12, format, -636225,
                              "beh.2ew5admf0n4xc16o1[9-", -19004,
                              "b/k24caw`g4eda", 2102, 1538.3421668949131,
                              -1328.0128438729926, -27600),
                   sprintf(str22, format, -636225, "beh.2ew5admf0n4xc16o1[9-",
                           -19004, "b/k24caw`g4eda", 2102, 1538.3421668949131,
                           -1328.0128438729926, -27600));
  ck_assert_str_eq(str12, str22);
}

END_TEST

START_TEST(my_sprintf_test_33) {
  char str13[1000];
  char str23[1000];
  char *format = "%-3.5hu%+i% hd%-10hd";
  ck_assert_int_eq(my_sprintf(str13, format, -29931, 959727, 10688, 4435),
                   sprintf(str23, format, -29931, 959727, 10688, 4435));
  ck_assert_str_eq(str13, str23);
}

END_TEST

START_TEST(my_sprintf_test_34) {
  char str1[1000];
  char str2[1000];
  char *format =
      "%+.3hir%+.7hd% 7.1hdv9u0% .2hi% 9.7f% im%+.5hdvl%-4.5hu%-4hd2";
  ck_assert_int_eq(my_sprintf(str1, format, -26577, -21570, -2767, 12726,
                              3725.890446989353, 435365, 12283, 7569, -18432),
                   sprintf(str2, format, -26577, -21570, -2767, 12726,
                           3725.890446989353, 435365, 12283, 7569, -18432));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_35) {
  char str1[1000];
  char str2[1000];
  char *format = "%+hd2% .0hi%-6hi-";
  ck_assert_int_eq(my_sprintf(str1, format, -12574, -6917, -30446),
                   sprintf(str2, format, -12574, -6917, -30446));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_36) {
  char str1[1000];
  char str2[1000];
  char *format = "% .2hi% .6d%-2.9hu%+6.5hi8wi";
  ck_assert_int_eq(my_sprintf(str1, format, 12237, 460834, 19570, 21532),
                   sprintf(str2, format, 12237, 460834, 19570, 21532));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_37) {
  char str1[1000];
  char str2[1000];
  char *format =
      "% 9.0hd% .2i8yk%+7.3hdz%+.7i5%-8hdy% 7.2hi`.%-1.6hi7=%-5.3hu%+6.9f";
  ck_assert_int_eq(my_sprintf(str1, format, 31351, -672089, 14145, 794309,
                              -31268, 9178, 25057, -10256, -23272.83614405469),
                   sprintf(str2, format, 31351, -672089, 14145, 794309, -31268,
                           9178, 25057, -10256, -23272.83614405469));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_38) {
  char str18[1000];
  char str28[1000];
  char *format = "%+5.0dutfq%+iniucw4% 10d%+4.10f% 4i%-5i=";
  ck_assert_int_eq(my_sprintf(str18, format, 450079, 897759, 731831,
                              18496.764956936597, -638458, -285090),
                   sprintf(str28, format, 450079, 897759, 731831,
                           18496.764956936597, -638458, -285090));
  ck_assert_str_eq(str18, str28);
}

END_TEST

START_TEST(my_sprintf_test_39) {
  char str1[1000];
  char str2[1000];
  char *format = "%+7d%-6hui%+fm%+7dxw%-6hdegg/";
  ck_assert_int_eq(
      my_sprintf(str1, format, 283839, -10557, 10647.37034801353, 870332,
                 14511),
      sprintf(str2, format, 283839, -10557, 10647.37034801353, 870332, 14511));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_40) {
  char str1[1000];
  char str2[1000];
  char *format = "% hi% 9.1f% 4hi";
  ck_assert_int_eq(my_sprintf(str1, format, 30893, -6827.386339743354, 6489),
                   sprintf(str2, format, 30893, -6827.386339743354, 6489));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_41) {
  char str1[1000];
  char str2[1000];
  char *format = "% 2hito%+2.5hd%-4hi%+7hdmn%-9.6hdz";
  ck_assert_int_eq(
      my_sprintf(str1, format, -14562, -17247, -8884, -3170, -9375),
      sprintf(str2, format, -14562, -17247, -8884, -3170, -9375));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_42) {
  char str1[1000];
  char str2[1000];
  char *format = "%+hi%+f";
  ck_assert_int_eq(my_sprintf(str1, format, 8296, 23934.40719021175),
                   sprintf(str2, format, 8296, 23934.40719021175));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_43) {
  char str1[1000];
  char str2[1000];
  char *format = "% 7.7djw.%+10hdcss%+.0ip%+d%-3hu% .8d5=gh8`p";
  ck_assert_int_eq(
      my_sprintf(str1, format, -811445, -1372, -125615, 447554, -4900, -887957),
      sprintf(str2, format, -811445, -1372, -125615, 447554, -4900, -887957));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_44) {
  char str1[1000];
  char str2[1000];
  char *format = "%-10.10hd%-10.9f";
  ck_assert_int_eq(my_sprintf(str1, format, 5391, 4015.3394399502913),
                   sprintf(str2, format, 5391, 4015.3394399502913));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_45) {
  char str1[1000];
  char str2[1000];
  char *format = "% 2.0fa% hd6%-10iz%-4c";
  ck_assert_int_eq(
      my_sprintf(str1, format, -19451.248098235646, 16475, -474292, 'o'),
      sprintf(str2, format, -19451.248098235646, 16475, -474292, 'o'));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_46) {
  char str1[1000];
  char str2[1000];
  char *format = "% hdc4% hi4% 8.7hd%-6hu%+2.7hi%+hi%-2sj%+10.0hd";
  ck_assert_int_eq(my_sprintf(str1, format, -19360, 4809, 161, -960, -27665,
                              -29275, "=cm[sgftnt-ws1,zntli", -30493),
                   sprintf(str2, format, -19360, 4809, 161, -960, -27665,
                           -29275, "=cm[sgftnt-ws1,zntli", -30493));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_47) {
  char str1[1000];
  char str2[1000];
  char *format = "%+i% 6hdh%+f;q% hi%+10i% 1.7di%+hd%+7iqp%-5s";
  ck_assert_int_eq(my_sprintf(str1, format, -50386, -27385, -5294.23821030174,
                              -22521, -437175, 171322, 12502, -161143, "dj"),
                   sprintf(str2, format, -50386, -27385, -5294.23821030174,
                           -22521, -437175, 171322, 12502, -161143, "dj"));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_48) {
  char str18[1000];
  char str28[1000];
  char *format = "%+1hi%+hi;az%-6hic";
  ck_assert_int_eq(my_sprintf(str18, format, 30989, 22487, 8568),
                   sprintf(str28, format, 30989, 22487, 8568));
  ck_assert_str_eq(str18, str28);
}

END_TEST

START_TEST(my_sprintf_test_49) {
  char str19[1000];
  char str2[1000];
  char *format = "%-8hi% 2f%-3d";
  ck_assert_int_eq(
      my_sprintf(str19, format, -17297, -14410.655980567524, 484794),
      sprintf(str2, format, -17297, -14410.655980567524, 484794));
  ck_assert_str_eq(str19, str2);
}

END_TEST

START_TEST(my_sprintf_test_50) {
  printf("Additional test for sprintf 50 of 500\n");
  char str10[1000];
  char str20[1000];
  char *format = "% .10hi;k%-8cd%+3.5d% 1.4d% .0f%+7him";
  ck_assert_int_eq(my_sprintf(str10, format, 19402, '1', -318461, -767940,
                              -7019.559048074657, 31864),
                   sprintf(str20, format, 19402, '1', -318461, -767940,
                           -7019.559048074657, 31864));
  ck_assert_str_eq(str10, str20);
}

END_TEST

START_TEST(my_sprintf_test_51) {
  char str11[1000];
  char str21[1000];
  char *format = "%-9hi%+hic06% 7.5dh% .4hi% 5.6d%+hi%+2i";
  ck_assert_int_eq(my_sprintf(str11, format, -596, 16725, -770559, -22244,
                              -137139, -23424, -578623),
                   sprintf(str21, format, -596, 16725, -770559, -22244, -137139,
                           -23424, -578623));
  ck_assert_str_eq(str11, str21);
}

END_TEST

START_TEST(my_sprintf_test_52) {
  char str12[1000];
  char str22[1000];
  char *format = "% 6i% 1d.n% 2.9hdl%-9.0s0% 4.6hilvjx`=xo%-2.7hi%+hii";
  ck_assert_int_eq(my_sprintf(str12, format, -627407, 524949, -3044, "4weg;1",
                              13770, 3459, 9224),
                   sprintf(str22, format, -627407, 524949, -3044, "4weg;1",
                           13770, 3459, 9224));
  ck_assert_str_eq(str12, str22);
}

END_TEST

START_TEST(my_sprintf_test_53) {
  char str13[1000];
  char str23[1000];
  char *format = "% 10.9hi%-2.10itzw% .3hi";
  ck_assert_int_eq(my_sprintf(str13, format, -19352, -898025, 8282),
                   sprintf(str23, format, -19352, -898025, 8282));
  ck_assert_str_eq(str13, str23);
}

END_TEST

START_TEST(my_sprintf_test_54) {
  char str1[1000];
  char str2[1000];
  char *format = "%+.10d% 4hi%+9d3%+hd% 9fo%-6u%+9dl5%-2.5u%+5d";
  ck_assert_int_eq(
      my_sprintf(str1, format, -150500, 24198, -608465, -30240,
                 1311.410345996852, -863711, 155711, 439945, -463327),
      sprintf(str2, format, -150500, 24198, -608465, -30240, 1311.410345996852,
              -863711, 155711, 439945, -463327));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(my_sprintf_test_55) {
  char str15[1000];
  char str25[1000];
  char *format = "%+d95% .8d9";
  ck_assert_int_eq(my_sprintf(str15, format, -809477, 988717),
                   sprintf(str25, format, -809477, 988717));
  ck_assert_str_eq(str15, str25);
}

END_TEST

START_TEST(my_sprintf_test_56) {
  char str16[1000];
  char str26[1000];
  char *format = "%-1db,z%+hi.% i%+hde61-% 3.3i7yj%+.0i% 9.0i%-3.3hi";
  ck_assert_int_eq(my_sprintf(str16, format, 343886, 15570, 687622, 535, -65047,
                              457804, -735126, 3419),
                   sprintf(str26, format, 343886, 15570, 687622, 535, -65047,
                           457804, -735126, 3419));
  ck_assert_str_eq(str16, str26);
}

END_TEST

START_TEST(my_sprintf_test_57) {
  char str17[1000];
  char str27[1000];
  char *format = "%+9hde%-1f%+f%-10s%+1fa";
  ck_assert_int_eq(
      my_sprintf(str17, format, 14114, 17.30980892115329, 4172.038961800877,
                 "=-l;o5dwkaghqkxm", -24425.179635802793),
      sprintf(str27, format, 14114, 17.30980892115329, 4172.038961800877,
              "=-l;o5dwkaghqkxm", -24425.179635802793));
  ck_assert_str_eq(str17, str27);
}

END_TEST

START_TEST(my_sprintf_test_58) {
  char str18[1000];
  char str28[1000];
  char *format = "% hdf%-10.5f%+8.8hi=x%+5.2f";
  ck_assert_int_eq(my_sprintf(str18, format, 17759, 747.2964770894596, 9581,
                              -5008.873775770445),
                   sprintf(str28, format, 17759, 747.2964770894596, 9581,
                           -5008.873775770445));
  ck_assert_str_eq(str18, str28);
}

END_TEST

START_TEST(my_sprintf_test_59) {
  char str19[1000];
  char str29[1000];
  ck_assert_int_eq(
      my_sprintf(str19, "%-3.10i%+.1f", -52906, 11247.914237048682),
      sprintf(str29, "%-3.10i%+.1f", -52906, 11247.914237048682));
  ck_assert_str_eq(str19, str29);
}

END_TEST

START_TEST(my_sprintf_test_ptr_1) {
  char str100[1000];
  char str200[1000];
  int a = 50;
#define TESTDATA "%p", &a
  ck_assert_int_eq(my_sprintf(str100, TESTDATA), sprintf(str200, TESTDATA));
  ck_assert_str_eq(str100, str200);
#undef TESTDATA
}

END_TEST

START_TEST(my_sprintf_test_hex) {
  char str100[1000];
  char str200[1000];
#define TESTDATA "%x", 0x00abcdef
  ck_assert_int_eq(my_sprintf(str100, TESTDATA), sprintf(str200, TESTDATA));
  ck_assert_str_eq(str100, str200);
#undef TESTDATA
}

END_TEST

START_TEST(my_sprintf_i_001) {
  printf("    i spec: ");
  char my_buff[256];
  char buff[256];
  ck_assert_int_eq(my_sprintf(my_buff, "%i", -150), sprintf(buff, "%i", -150));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+i", -150),
                   sprintf(buff, "%+i", -150));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "% i", 420), sprintf(buff, "% i", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-i", -150),
                   sprintf(buff, "%-i", -150));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5i", -150),
                   sprintf(buff, "%5i", -150));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "kek%i", -150),
                   sprintf(buff, "kek%i", -150));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*i", 8, 420),
                   sprintf(buff, "%*i", 8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*i", 8, 420),
                   sprintf(buff, "%.*i", 8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*i", -8, 420),
                   sprintf(buff, "%*i", -8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*i", -8, 420),
                   sprintf(buff, "%.*i", -8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0i", -150),
                   sprintf(buff, "%0i", -150));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.5i", -150),
                   sprintf(buff, "%.5i", -150));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5.2i", 100),
                   sprintf(buff, "%5.2i", 100));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.2i", 100),
                   sprintf(buff, "%.2i", 100));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-5.2i", 100),
                   sprintf(buff, "%-5.2i", 100));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+5.2i", 100),
                   sprintf(buff, "%+5.2i", 100));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%i", 950), sprintf(buff, "%i", 950));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5li", 420l),
                   sprintf(buff, "%5li", 420l));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%i %i %+i", 420, 380, 470),
                   sprintf(buff, "%i %i %+i", 420, 380, 470));
  ck_assert_str_eq(my_buff, buff);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_u_001) {
  printf("    u spec: ");
  char my_buff[256];
  char buff[256];
  ck_assert_int_eq(my_sprintf(my_buff, "%u", 128), sprintf(buff, "%u", 128));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-u", 128), sprintf(buff, "%-u", 128));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5u", 128), sprintf(buff, "%5u", 128));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%05u", 128),
                   sprintf(buff, "%05u", 128));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "kek%u", 128),
                   sprintf(buff, "kek%u", 128));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*u", 8, 420),
                   sprintf(buff, "%*u", 8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*u", 8, 420),
                   sprintf(buff, "%.*u", 8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*u", -8, 420),
                   sprintf(buff, "%*u", -8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*u", -8, 420),
                   sprintf(buff, "%.*u", -8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0u", 560), sprintf(buff, "%0u", 560));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.5u", 560),
                   sprintf(buff, "%.5u", 560));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.2u", 560),
                   sprintf(buff, "%.2u", 560));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5.2u", 560),
                   sprintf(buff, "%5.2u", 560));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-5.2u", 890),
                   sprintf(buff, "%-5.2u", 890));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5lu", 980lu),
                   sprintf(buff, "%5lu", 980lu));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%u %u %-u %5u", 420, 0u - 1u, 300, 600),
                   sprintf(buff, "%u %u %-u %5u", 420, 0u - 1u, 300, 600));
  ck_assert_str_eq(my_buff, buff);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_o_001) {
  printf("    o spec: ");
  char my_buff[256];
  char buff[256];
  ck_assert_int_eq(my_sprintf(my_buff, "%o", 148), sprintf(buff, "%o", 148));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-o", 148), sprintf(buff, "%-o", 148));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5o", 148), sprintf(buff, "%5o", 148));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "kek%o", 148),
                   sprintf(buff, "kek%o", 148));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*o", 8, 420),
                   sprintf(buff, "%*o", 8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*o", 8, 420),
                   sprintf(buff, "%.*o", 8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*o", -8, 420),
                   sprintf(buff, "%*o", -8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*o", -8, 420),
                   sprintf(buff, "%.*o", -8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0o", 420), sprintf(buff, "%0o", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.5o", 420),
                   sprintf(buff, "%.5o", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.2o", 420),
                   sprintf(buff, "%.2o", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5.2o", 420),
                   sprintf(buff, "%5.2o", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-5.2o", 420),
                   sprintf(buff, "%-5.2o", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%o", 420), sprintf(buff, "%o", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5lo", 420lu),
                   sprintf(buff, "%5lo", 420lu));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*o", 10, 250),
                   sprintf(buff, "%#.*o", 10, 250));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*o", 100, 1050),
                   sprintf(buff, "%#.*o", 100, 1050));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%o %#o %-o %5o", 420, 1420, 300, 600),
                   sprintf(buff, "%o %#o %-o %5o", 420, 1420, 300, 600));
  ck_assert_str_eq(my_buff, buff);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_x_001) {
  printf("    x spec: ");
  char my_buff[256];
  char buff[256];
  ck_assert_int_eq(my_sprintf(my_buff, "%x", 148), sprintf(buff, "%x", 148));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-x", 148), sprintf(buff, "%-x", 148));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5x", 148), sprintf(buff, "%5x", 148));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "kek%x", 148),
                   sprintf(buff, "kek%x", 148));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*x", 8, 420),
                   sprintf(buff, "%*x", 8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*x", 8, 420),
                   sprintf(buff, "%.*x", 8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*x", -8, 420),
                   sprintf(buff, "%*x", -8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*x", -8, 420),
                   sprintf(buff, "%.*x", -8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0x", 420), sprintf(buff, "%0x", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.5x", 420),
                   sprintf(buff, "%.5x", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.2x", 420),
                   sprintf(buff, "%.2x", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5.2x", 420),
                   sprintf(buff, "%5.2x", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5.2x", 721082),
                   sprintf(buff, "%5.2x", 721082));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-5.2x", 420),
                   sprintf(buff, "%-5.2x", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%x", 420), sprintf(buff, "%x", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5lx", 420lu),
                   sprintf(buff, "%5lx", 420lu));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*x", 10, 250),
                   sprintf(buff, "%#.*x", 10, 250));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*x", -10, 1050),
                   sprintf(buff, "%#.*x", -10, 1050));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*x", 100, 1050),
                   sprintf(buff, "%#.*x", 100, 1050));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%x %#x %-x %5x", 420, 1420, 300, 600),
                   sprintf(buff, "%x %#x %-x %5x", 420, 1420, 300, 600));
  ck_assert_str_eq(my_buff, buff);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_X_001) {
  printf("    X spec: ");
  char my_buff[256];
  char buff[256];
  ck_assert_int_eq(my_sprintf(my_buff, "%X", 148), sprintf(buff, "%X", 148));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-X", 148), sprintf(buff, "%-X", 148));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5X", 148), sprintf(buff, "%5X", 148));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "kek%x", 148),
                   sprintf(buff, "kek%X", 148));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*X", 8, 420),
                   sprintf(buff, "%*X", 8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*X", 8, 420),
                   sprintf(buff, "%.*X", 8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*X", -8, 420),
                   sprintf(buff, "%*X", -8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*X", -8, 420),
                   sprintf(buff, "%.*X", -8, 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0X", 420), sprintf(buff, "%0X", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5.2X", 912145),
                   sprintf(buff, "%5.2X", 912145));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.5X", 420),
                   sprintf(buff, "%.5X", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.2X", 420),
                   sprintf(buff, "%.2X", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5.2X", 420),
                   sprintf(buff, "%5.2X", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-5.2X", 420),
                   sprintf(buff, "%-5.2X", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%X", 420), sprintf(buff, "%X", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5lX", 420), sprintf(buff, "%5X", 420));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*X", 10, 250),
                   sprintf(buff, "%#.*X", 10, 250));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*X", 100, 1050),
                   sprintf(buff, "%#.*X", 100, 1050));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%X %#X %-X %5X", 420, 1420, 300, 600),
                   sprintf(buff, "%X %#X %-X %5X", 420, 1420, 300, 600));
  ck_assert_str_eq(my_buff, buff);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_c_001) {
  printf("    c spec: ");
  char my_buff[256];
  char buff[256];
  sprintf(buff, "qwe");
  for (int i = 33; i < 127; i++) {
    ck_assert_int_eq(my_sprintf(my_buff, "%c", i), sprintf(buff, "%c", i));
    ck_assert_str_eq(my_buff, buff);
  }
  ck_assert_int_eq(my_sprintf(my_buff, "%%"), sprintf(buff, "%%"));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%10c", 'g'),
                   sprintf(buff, "%10c", 'g'));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%c", -1), sprintf(buff, "%c", -1));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-10c", 'c'),
                   sprintf(buff, "%-10c", 'c'));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%lc", 'o'), sprintf(buff, "%lc", 'o'));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%lc", 420), sprintf(buff, "%lc", 420));
  ck_assert_str_eq(my_buff, buff);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_g_001) {
  printf("    g spec: ");
  char my_buff[256];
  char buff[256];
  ck_assert_int_eq(my_sprintf(my_buff, "%g", 148.228),
                   sprintf(buff, "%g", 148.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%g", 148.0),
                   sprintf(buff, "%g", 148.0));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+g", 14.228),
                   sprintf(buff, "%+g", 14.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-g", 148.228),
                   sprintf(buff, "%-g", 148.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5g", 148.228),
                   sprintf(buff, "%5g", 148.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "kek%g", 148.228),
                   sprintf(buff, "kek%g", 148.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*g", 8, 420.228),
                   sprintf(buff, "%*g", 8, 420.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*g", 8, 420.228),
                   sprintf(buff, "%.*g", 8, 420.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*g", -8, 420.228),
                   sprintf(buff, "%*g", -8, 420.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.0g", 0.00089),
                   sprintf(buff, "%.0g", 0.00089));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*g", -8, 420.228),
                   sprintf(buff, "%.*g", -8, 420.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0g", 420.228),
                   sprintf(buff, "%0g", 420.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.5g", 420.228),
                   sprintf(buff, "%.5g", 420.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0.2g", 420.228),
                   sprintf(buff, "%0.2g", 420.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5.2g", 420.228),
                   sprintf(buff, "%5.2g", 420.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0.2g", 420.228),
                   sprintf(buff, "%0.2g", 420.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-5.2g", 420.228),
                   sprintf(buff, "%-5.2g", 420.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+5.2g", 420.228),
                   sprintf(buff, "%+5.2g", 420.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*g", 10, 250.228),
                   sprintf(buff, "%#.*g", 10, 250.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*Lg", -10, 1050.228l),
                   sprintf(buff, "%#.*Lg", -10, 1050.228l));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*g", 19, 1050.228),
                   sprintf(buff, "%#.*g", 19, 1050.228));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(
      my_sprintf(my_buff, "%g %+g %-g %5g", 420.1450, 1420.1450, 300.1450,
                 600.1450),
      sprintf(buff, "%g %+g %-g %5g", 420.1450, 1420.1450, 300.1450, 600.1450));
  ck_assert_str_eq(my_buff, buff);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_G_001) {
  printf("    G spec: ");
  char my_buff[256];
  char buff[256];
  ck_assert_int_eq(my_sprintf(my_buff, "%G", 148.25612),
                   sprintf(buff, "%G", 148.25612));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+G", 148.25612),
                   sprintf(buff, "%+G", 148.25612));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-G", 148.25612),
                   sprintf(buff, "%-G", 148.25612));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5G", 148.25612),
                   sprintf(buff, "%5G", 148.25612));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "kek%G", 148.25612),
                   sprintf(buff, "kek%G", 148.25612));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*G", 8, 420.25612),
                   sprintf(buff, "%*G", 8, 420.25612));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*G", 8, 420.25612),
                   sprintf(buff, "%.*G", 8, 420.25612));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*G", -8, 420.25612),
                   sprintf(buff, "%*G", -8, 420.25612));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*G", -8, 420.25612),
                   sprintf(buff, "%.*G", -8, 420.25612));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0G", 420.1214),
                   sprintf(buff, "%0G", 420.1214));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.5G", 420.1214),
                   sprintf(buff, "%.5G", 420.1214));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.0G", 0.00089),
                   sprintf(buff, "%.0G", 0.00089));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0.2G", 420.1214),
                   sprintf(buff, "%0.2G", 420.1214));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5.2G", 420.1214),
                   sprintf(buff, "%5.2G", 420.1214));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0.2G", 420.1214),
                   sprintf(buff, "%0.2G", 420.1214));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-5.2G", 420.1214),
                   sprintf(buff, "%-5.2G", 420.1214));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+5.2G", 420.1214),
                   sprintf(buff, "%+5.2G", 420.1214));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+G", 50.1470),
                   sprintf(buff, "%+G", 50.1470));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-G", 20.1470),
                   sprintf(buff, "%-G", 20.1470));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*G", 10, 250.1470),
                   sprintf(buff, "%#.*G", 10, 250.1470));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*LG", -10, 1050.1470l),
                   sprintf(buff, "%#.*LG", -10, 1050.1470l));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*G", 19, 1050.1470),
                   sprintf(buff, "%#.*G", 19, 1050.1470));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(
      my_sprintf(my_buff, "%G %+G %-G %5G", 420.12, 1420.12, 300.12, 600.12),
      sprintf(buff, "%G %+G %-G %5G", 420.12, 1420.12, 300.12, 600.12));
  ck_assert_str_eq(my_buff, buff);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_s_001) {
  printf("    s spec: ");
  char my_buff[256];
  char buff[256];
  char *test_strings[] = {"xyz",    "@",      "nothing", "-2-10",     "\n\b\t",
                          "\n\n\n", "s",      "n0thing", "nothingx2", "empty",
                          "rty",    "zxcvbn", "asd",     "%",         "\t\t",
                          "\0",     "b",      "\0abcd",  "\nabd",     "\b",
                          "\v",     "ab\v\0", NULL};

  for (int i = 0; i < 23; i++) {
    ck_assert_int_eq(sprintf(buff, "%s", test_strings[i]),
                     my_sprintf(my_buff, "%s", test_strings[i]));
    ck_assert_str_eq(buff, my_buff);
  }
  ck_assert_int_eq(sprintf(buff, "%20s", "string"),
                   my_sprintf(my_buff, "%20s", "string"));
  ck_assert_str_eq(buff, my_buff);
  ck_assert_int_eq(sprintf(buff, "%-20s", "string"),
                   my_sprintf(my_buff, "%-20s", "string"));
  ck_assert_str_eq(buff, my_buff);
  ck_assert_int_eq(sprintf(buff, "%20.3s", "string"),
                   my_sprintf(my_buff, "%20.3s", "string"));
  ck_assert_str_eq(buff, my_buff);
  ck_assert_int_eq(sprintf(buff, "%ls", L"string"),
                   my_sprintf(my_buff, "%ls", L"string"));
  ck_assert_str_eq(buff, my_buff);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_f_001) {
  printf("    f spec: ");
  char my_buff[256];
  char buff[256];
  ck_assert_int_eq(my_sprintf(my_buff, "%f", 14.4), sprintf(buff, "%f", 14.4));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%f", 14.0), sprintf(buff, "%f", 14.0));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "% f", 45.47),
                   sprintf(buff, "% f", 45.47));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "% .f", 45.47),
                   sprintf(buff, "% .f", 45.47));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+f", 148.64),
                   sprintf(buff, "%+f", 148.64));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-f", 148.765),
                   sprintf(buff, "%-f", 148.765));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5f", 148.871),
                   sprintf(buff, "%5f", 148.871));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "kek%f", -3.27651),
                   sprintf(buff, "kek%f", -3.27651));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*f", 8, 3.27651),
                   sprintf(buff, "%*f", 8, 3.27651));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*f", 8, 3.27651),
                   sprintf(buff, "%.*f", 8, 3.27651));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*f", -8, 176435.213),
                   sprintf(buff, "%*f", -8, 176435.213));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%015f", 0.69089),
                   sprintf(buff, "%015f", 0.69089));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "% f", 148.871),
                   sprintf(buff, "% f", 148.871));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%f", 0.00089),
                   sprintf(buff, "%f", 0.00089));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*f", -8, 176435.213),
                   sprintf(buff, "%.*f", -8, 176435.213));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0f", 420.89),
                   sprintf(buff, "%0f", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.5f", 420.89),
                   sprintf(buff, "%.5f", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0.2f", 420.89),
                   sprintf(buff, "%0.2f", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5.2f", 420.89),
                   sprintf(buff, "%5.2f", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0.2f", 420.89),
                   sprintf(buff, "%0.2f", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-5.2f", 420.89),
                   sprintf(buff, "%-5.2f", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+5.2f", 4420.89),
                   sprintf(buff, "%+5.2f", 4420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*f", 10, 2420.89),
                   sprintf(buff, "%#.*f", 10, 2420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*Lf", -10, 10420.89l),
                   sprintf(buff, "%#.*Lf", -10, 10420.89l));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*f", 19, 1050.25),
                   sprintf(buff, "%#.*f", 19, 1050.25));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(
      my_sprintf(my_buff, "%f %+f %-f %5f", 420.0, 3.1415, 300.25, 600.25),
      sprintf(buff, "%f %+f %-f %5f", 420.0, 3.1415, 300.25, 600.25));
  ck_assert_str_eq(my_buff, buff);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_F_001) {
  printf("    F spec: ");
  char my_buff[256];
  char buff[256];
  ck_assert_int_eq(my_sprintf(my_buff, "%F", 14.4), sprintf(buff, "%F", 14.4));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+F", 148.64),
                   sprintf(buff, "%+F", 148.64));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-F", 148.765),
                   sprintf(buff, "%-F", 148.765));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5F", 148.871),
                   sprintf(buff, "%5F", 148.871));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "% F", 148.871),
                   sprintf(buff, "% F", 148.871));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "kek%F", -3.27651),
                   sprintf(buff, "kek%F", -3.27651));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*F", 8, 3.27651),
                   sprintf(buff, "%*F", 8, 3.27651));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*F", 8, 3.27651),
                   sprintf(buff, "%.*F", 8, 3.27651));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*F", -8, 176435.213),
                   sprintf(buff, "%*F", -8, 176435.213));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*F", -8, 176435.213),
                   sprintf(buff, "%.*F", -8, 176435.213));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%010F", 420.89),
                   sprintf(buff, "%010F", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%015F", 0.69089),
                   sprintf(buff, "%015F", 0.69089));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%F", 0.00089),
                   sprintf(buff, "%F", 0.00089));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.5F", 420.89),
                   sprintf(buff, "%.5F", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0.2F", 420.89),
                   sprintf(buff, "%0.2F", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5.2F", 420.89),
                   sprintf(buff, "%5.2F", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0.2F", 420.89),
                   sprintf(buff, "%0.2F", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-5.2F", 420.89),
                   sprintf(buff, "%-5.2F", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+5.2F", 4420.89),
                   sprintf(buff, "%+5.2F", 4420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*F", 10, 2420.89),
                   sprintf(buff, "%#.*F", 10, 2420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*LF", -10, 10420.89l),
                   sprintf(buff, "%#.*LF", -10, 10420.89l));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*F", 16, 1050.256),
                   sprintf(buff, "%#.*F", 16, 1050.256));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(
      my_sprintf(my_buff, "%F %+F %-F %5F", 420.0, 3.1415, 300.0, 600.256),
      sprintf(buff, "%F %+F %-F %5F", 420.0, 3.1415, 300.0, 600.256));
  ck_assert_str_eq(my_buff, buff);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_n_001) {
  printf("    n spec: ");
  char s_21[256];
  char buff[256];
  char *test[] = {"ret%n", "b\b%nr", "%nreti", "rreiriotieri%n",
                  "rreiri%notieri"};
  int s_21_num = 0;
  int buff_num = 0;
  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(sprintf(buff, test[i], &buff_num),
                     my_sprintf(s_21, test[i], &s_21_num));
    ck_assert_int_eq(buff_num, s_21_num);
  }
  ck_assert_int_eq(sprintf(buff, "%d%n", -2147483647, &buff_num),
                   my_sprintf(s_21, "%d%n", -2147483647, &s_21_num));
  ck_assert_int_eq(buff_num, s_21_num);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_p_001) {
  printf("    p spec: ");
  char buff[256];
  char s_21[256];

  int n[16];
  int adr_c = 16;
  for (int i = 0; i < adr_c; i++) {
    ck_assert_int_eq(sprintf(buff, "%p", &n[i]), my_sprintf(s_21, "%p", &n[i]));
    ck_assert_str_eq(buff, s_21);
  }
  for (int i = 0; i < adr_c; i++) {
    ck_assert_int_eq(sprintf(buff, "%32p", &n[i]),
                     my_sprintf(s_21, "%32p", &n[i]));
    ck_assert_str_eq(buff, s_21);
  }
  for (int i = 0; i < adr_c; i++) {
    ck_assert_int_eq(sprintf(buff, "%-32p", &n[i]),
                     my_sprintf(s_21, "%-32p", &n[i]));
    ck_assert_str_eq(buff, s_21);
  }
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_e_001) {
  // //#line 9516
  printf("    e spec: ");
  char my_buff[256];
  char buff[256];
  ck_assert_int_eq(my_sprintf(my_buff, "%e", 14.4), sprintf(buff, "%e", 14.4));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%e", 14.0), sprintf(buff, "%e", 14.0));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "% e", 14.4),
                   sprintf(buff, "% e", 14.4));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+e", 148.64),
                   sprintf(buff, "%+e", 148.64));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-e", 148.765),
                   sprintf(buff, "%-e", 148.765));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5e", 148.871),
                   sprintf(buff, "%5e", 148.871));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "kek%e", 3.27651),
                   sprintf(buff, "kek%e", 3.27651));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*e", 8, 3.27651),
                   sprintf(buff, "%*e", 8, 3.27651));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*e", 8, 3.27651),
                   sprintf(buff, "%.*e", 8, 3.27651));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*e", -8, 176435.213),
                   sprintf(buff, "%*e", -8, 176435.213));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*e", -8, 176435.213),
                   sprintf(buff, "%.*e", -8, 176435.213));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0e", 420.89),
                   sprintf(buff, "%0e", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.5e", 420.89),
                   sprintf(buff, "%.5e", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0.2e", 420.89),
                   sprintf(buff, "%0.2e", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5.2e", 420.89),
                   sprintf(buff, "%5.2e", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0.2e", 420.89),
                   sprintf(buff, "%0.2e", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-5.2e", 420.89),
                   sprintf(buff, "%-5.2e", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+5.2e", 4420.89),
                   sprintf(buff, "%+5.2e", 4420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*e", 10, 2420.89),
                   sprintf(buff, "%#.*e", 10, 2420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*e", -10, 10420.89),
                   sprintf(buff, "%#.*e", -10, 10420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*e", 10, 1050.255),
                   sprintf(buff, "%#.*e", 10, 1050.255));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(
      my_sprintf(my_buff, "%e %+e %-e %5e", 420.255, 3.1415, 300.255, 600.255),
      sprintf(buff, "%e %+e %-e %5e", 420.255, 3.1415, 300.255, 600.255));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%12.15e", 2.731),
                   sprintf(buff, "%12.15e", 2.731));
  ck_assert_str_eq(my_buff, buff);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sprintf_E_001) {
  // //#line 9570
  printf("    E spec: ");
  char my_buff[256];
  char buff[256];
  ck_assert_int_eq(my_sprintf(my_buff, "%E", 14.4), sprintf(buff, "%E", 14.4));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+E", 148.64),
                   sprintf(buff, "%+E", 148.64));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-E", 148.765),
                   sprintf(buff, "%-E", 148.765));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5E", 148.871),
                   sprintf(buff, "%5E", 148.871));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "kek%E", 3.27651),
                   sprintf(buff, "kek%E", 3.27651));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*E", 8, 3.27651),
                   sprintf(buff, "%*E", 8, 3.27651));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*E", 8, 3.27651),
                   sprintf(buff, "%.*E", 8, 3.27651));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%*E", -8, 176435.213),
                   sprintf(buff, "%*E", -8, 176435.213));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.*E", -8, 176435.213),
                   sprintf(buff, "%.*E", -8, 176435.213));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0E", 420.89),
                   sprintf(buff, "%0E", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%.5E", 420.89),
                   sprintf(buff, "%.5E", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0.2E", 420.89),
                   sprintf(buff, "%0.2E", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%5.2E", 420.89),
                   sprintf(buff, "%5.2E", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%0.2E", 420.89),
                   sprintf(buff, "%0.2E", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%-5.2E", 420.89),
                   sprintf(buff, "%-5.2E", 420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%+5.2E", 4420.89),
                   sprintf(buff, "%+5.2E", 4420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*E", 10, 2420.89),
                   sprintf(buff, "%#.*E", 10, 2420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*E", -10, 10420.89),
                   sprintf(buff, "%#.*E", -10, 10420.89));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%#.*E", 10, 1050.12),
                   sprintf(buff, "%#.*E", 10, 1050.12));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(
      my_sprintf(my_buff, "%E %+E %-E %5E", 420.12, 3.1415, 300.12, 600.12),
      sprintf(buff, "%E %+E %-E %5E", 420.12, 3.1415, 300.12, 600.12));
  ck_assert_str_eq(my_buff, buff);
  ck_assert_int_eq(my_sprintf(my_buff, "%12.15lE", 2.731),
                   sprintf(buff, "%12.15lE", 2.731));
  ck_assert_str_eq(my_buff, buff);
  printf("[PASS]\n");
}

END_TEST

START_TEST(my_sscanf_c_test2) {
  printf("Start group test sscanf %%c\n");
  char c_original;
  char c_fake;
  char str[500] = "12345 test";
  char str2[500] = "12345 test";
  int expected_res = sscanf(str, "12345 %c", &c_original);
  int my_res = my_sscanf(str2, "12345 %c", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_c_test3) {
  char c_original;
  char c_fake;
  char str[500] = "12345 test";
  char str2[500] = "12345 test";
  int expected_res = sscanf(str, "1 %c", &c_original);
  int my_res = my_sscanf(str2, "1 %c", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_c_test4) {
  char c_original;
  char c_fake;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int expected_res = sscanf(str, "- %c", &c_original);
  int my_res = my_sscanf(str2, "- %c", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST
START_TEST(my_sscanf_c_test5) {
  char c_original;
  char c_fake;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int expected_res = sscanf(str, "%c", &c_original);
  int my_res = my_sscanf(str2, "%c", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_c_test6) {
  char c_original;
  char c_fake;
  char c_original2;
  char c_fake2;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int expected_res = sscanf(str, "-%c e%c", &c_original, &c_original2);
  int my_res = my_sscanf(str2, "-%c e%c", &c_fake, &c_fake2);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_c_test7) {
  //#line 3350
  char c_original;
  char c_fake;
  char c_original2;
  char c_fake2;
  char str[500] = "     -test 12345";
  char str2[500] = "     -test 12345";
  int expected_res = sscanf(str, "%c %c", &c_original, &c_original2);
  int my_res = my_sscanf(str2, "%c %c", &c_fake, &c_fake2);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_d_test0) {
  //#line 3362
  printf("Start group test sscanf %%d\n");
  int c_original = 0;
  int c_fake = 0;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int expected_res = sscanf(str, "%d", &c_original);
  int my_res = my_sscanf(str2, "%d", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_d_test1) {
  //#line 3373
  int c_original = 0;
  int c_fake = 0;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int expected_res = sscanf(str, "-%d", &c_original);
  int my_res = my_sscanf(str2, "-%d", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_d_test2) {
  //#line 3383
  int c_original;
  int c_fake;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int expected_res = sscanf(str, "-test%d", &c_original);
  int my_res = my_sscanf(str2, "-test%d", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_d_test3) {
  //#line 3393
  int c_original;
  int c_fake;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int expected_res = sscanf(str, "-test%2d", &c_original);
  int my_res = my_sscanf(str2, "-test%2d", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_d_test4) {
  //#line 3403
  long int c_original;
  long int c_fake;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int expected_res = sscanf(str, "-test%2ld", &c_original);
  int my_res = my_sscanf(str2, "-test%2ld", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_d_test6) {
  //#line 3414
  short int c_original;
  short int c_fake;
  char str[500] = "-1928479817248.981427";
  char str2[500] = "-1928479817248.981427";
  int expected_res = sscanf(str, "%10hd", &c_original);
  int my_res = my_sscanf(str2, "%10hd", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_d_test8) {
  //#line 3425
  int c_original = 0;
  int c_fake = 0;
  int c_original2 = 0;
  int c_fake2 = 0;
  char str[500] = "-19284--79[[--817248.981427";
  char str2[500] = "-19284--79[[--817248.981427";
  int expected_res = sscanf(str, "-%10d %d", &c_original, &c_original2);
  int my_res = my_sscanf(str2, "-%10d %d", &c_fake, &c_fake2);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(c_original2, c_fake2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_d_test9) {
  //#line 3438
  int c_original = 0;
  int c_fake = 0;
  int c_original2 = 0;
  int c_fake2 = 0;
  int c_original3 = 0;
  int c_fake3 = 0;
  char str[500] = "-19284--79[[--817248.981427";
  char str2[500] = "-19284--79[[--817248.981427";
  int expected_res =
      sscanf(str, "-%10d %d %2d", &c_original, &c_original2, &c_original3);
  int my_res = my_sscanf(str2, "-%10d %d %2d", &c_fake, &c_fake3, &c_fake3);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(c_original2, c_fake2);
  ck_assert_int_eq(c_original3, c_fake3);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST
START_TEST(my_sscanf_d_test_oi_1) {
  //#line 3438
  int c_original = 0;
  int c_fake = 0;
  char str[500] = "19284";
  char str2[500] = "19284";
  char *format = "%+10d";
  int expected_res = sscanf(str, format, &c_original);
  int my_res = my_sscanf(str2, format, &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_i_test0) {
  //#line 3454
  printf("Start group test sscanf %%i\n");
  int check = 0;
  int my_check = 0;
  char str[500] = "-123124";
  char str2[500] = "-123124";
  int expected_res = sscanf(str, "%i", &check);
  int my_res = my_sscanf(str2, "%i", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_int_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_i_test1) {
  //#line 3466
  int check = 0;
  int my_check = 0;
  int check2 = 0;
  int my_check2 = 0;
  char str[500] = "-123124 0xffe";
  char str2[500] = "-123124 0xffe";
  int expected_res = sscanf(str, "-%i %i", &check, &check2);
  int my_res = my_sscanf(str2, "-%i %i", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_int_eq(check, my_check);
  ck_assert_int_eq(check2, my_check2);
}

END_TEST

START_TEST(my_sscanf_i_test2) {
  //#line 3480
  int check = 0;
  int my_check = 0;
  int check2 = 0;
  int my_check2 = 0;
  char str[500] = "05524 0xFFE";
  char str2[500] = "05524 0xFFE";
  int expected_res = sscanf(str, "%i%i", &check, &check2);
  int my_res = my_sscanf(str2, "%i%i", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_int_eq(check, my_check);
  ck_assert_int_eq(check2, my_check2);
}

END_TEST

START_TEST(my_sscanf_i_test3) {
  //#line 3494
  int check = 0;
  int my_check = 0;
  int check2 = 0;
  int my_check2 = 0;
  char str[500] = "-05524 \t -FFE";
  char str2[500] = "-05524 \t -FFE";
  int expected_res = sscanf(str, "%7i%i", &check, &check2);
  int my_res = my_sscanf(str2, "%7i%i", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_int_eq(check, my_check);
  ck_assert_int_eq(check2, my_check2);
}

END_TEST

START_TEST(my_sscanf_i_test4) {
  //#line 3508
  int check = 0;
  int my_check = 0;
  int check2 = 0;
  int my_check2 = 0;
  char str[500] = "-05524 asdasd-FFE";
  char str2[500] = "-05524 asdasd-FFE";
  int expected_res = sscanf(str, "%3i%i", &check, &check2);
  int my_res = my_sscanf(str2, "%3i%i", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_int_eq(check, my_check);
  ck_assert_int_eq(check2, my_check2);
}

END_TEST

START_TEST(my_sscanf_i_test5) {
  //#line 3522
  int check = 0;
  int my_check = 0;
  int check2 = 0;
  int my_check2 = 0;
  char str[500] = "55=24 \n-FFE";
  char str2[500] = "55=24 \n-FFE";
  int expected_res = sscanf(str, "%i%i", &check, &check2);
  int my_res = my_sscanf(str2, "%i%i", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_int_eq(check, my_check);
  ck_assert_int_eq(check2, my_check2);
}

END_TEST

START_TEST(my_sscanf_i_test6) {
  //#line 3536
  int check = 0;
  int my_check = 0;
  int check2 = 0;
  int my_check2 = 0;
  char str[500] = "55FF=E";
  char str2[500] = "55FF=E";
  int expected_res = sscanf(str, "%i%1i", &check, &check2);
  int my_res = my_sscanf(str2, "%i%1i", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_int_eq(check, my_check);
  ck_assert_int_eq(check2, my_check2);
}

END_TEST

START_TEST(my_sscanf_i_test8) {
  //#line 3550
  int check = 0;
  int my_check = 0;
  int check2 = 0;
  int my_check2 = 0;
  char str[500] = "FFE0679";
  char str2[500] = "FFE0679";
  int expected_res = sscanf(str, "%2i%4i", &check, &check2);
  int my_res = my_sscanf(str2, "%2i%4i", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_int_eq(check, my_check);
  ck_assert_int_eq(check2, my_check2);
}

END_TEST

START_TEST(my_sscanf_i_test88) {
  //#line 3564
  long int check = 0;
  long int my_check = 0;
  short int check2 = 0;
  short int my_check2 = 0;
  char str[500] = "FFE0679";
  char str2[500] = "FFE0679";
  int expected_res = sscanf(str, "%li%hi", &check, &check2);
  int my_res = my_sscanf(str2, "%li%hi", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_int_eq(check, my_check);
  ck_assert_int_eq(check2, my_check2);
}

END_TEST

START_TEST(my_sscanf_i_test9) {
  //#line 3578
  long int check = 0;
  long int my_check = 0;
  short int check2 = 0;
  short int my_check2 = 0;
  char str[500] = "FFEF0679";
  char str2[500] = "FFEF0679";
  int expected_res = sscanf(str, "F%li%2hi", &check, &check2);
  int my_res = my_sscanf(str2, "F%li%2hi", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_int_eq(check, my_check);
  ck_assert_int_eq(check2, my_check2);
}

END_TEST

START_TEST(my_sscanf_i_test11) {
  //#line 3592
  short int check = 0;
  short int my_check = 0;
  short int check2 = 0;
  short int my_check2 = 0;
  char str[500] = "FFEF0679";
  char str2[500] = "FFEF0679";
  int expected_res = sscanf(str, "F%hi%2hi", &check, &check2);
  int my_res = my_sscanf(str2, "F%hi%2hi", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_int_eq(check, my_check);
  ck_assert_int_eq(check2, my_check2);
}

END_TEST

START_TEST(my_sscanf_i_test12) {
  //#line 3606
  short int check = 0;
  short int my_check = 0;
  char str[500] = "0xFFa";
  char str2[500] = "0xFFa";
  int expected_res = sscanf(str, "%hi", &check);
  int my_res = my_sscanf(str2, "%hi", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_int_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_i_test13) {
  //#line 3616
  short int check = 0;
  short int my_check = 0;
  char str[500] = "+0xFFa";
  char str2[500] = "+0xFFa";
  int expected_res = sscanf(str, "%hi", &check);
  int my_res = my_sscanf(str2, "%hi", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_int_eq(check, my_check);

  // e tests
}

END_TEST

START_TEST(my_sscanf_e_test0) {
  //#line 3627
  printf("Start group test sscanf %%e\n");
  float check = 0.;
  float my_check = 0.;
  float check2 = 0.;
  float my_check2 = 0.;
  float check3 = 0.;
  float my_check3 = 0.;
  float check4 = 0.;
  float my_check4 = 0.;
  char str[500] = "1.1e-2 1.1e+002 1.1e+ d";
  char str2[500] = "1.1e-2 1.1e+002 1.1e+ d";
  int expected_res =
      sscanf(str, "%e %e %e %e", &check, &check2, &check3, &check4);
  int my_res = my_sscanf(str2, "%e %e %e %e", &my_check, &my_check2, &my_check3,
                         &my_check4);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_double_eq(check3, my_check3);
  ck_assert_double_eq(check4, my_check4);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_e_test1) {
  //#line 3648
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "1.1111111 3123123.22212125";
  char str2[500] = "1.1111111 3123123.22212125";
  int expected_res = sscanf(str, "%e %le", &check, &check2);
  int my_res = my_sscanf(str2, "%e %le", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_e_test2) {
  //#line 3662
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-1.1111111 +3.22212125";
  char str2[500] = "-1.1111111 +3.22212125";
  int expected_res = sscanf(str, "%e %le", &check, &check2);
  int my_res = my_sscanf(str2, "%e %le", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_e_test3) {
  //#line 3676
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int expected_res = sscanf(str, "%3e %17le", &check, &check2);
  int my_res = my_sscanf(str2, "%3e %17le", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_e_test4) {
  //#line 3690
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-0.1111111 -3444.22212125";
  char str2[500] = "-0.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%1e %3le", &check, &check2);
  int my_res = my_sscanf(str2, "%1e %3le", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_e_test6) {
  //#line 3704
  long double check = 0;
  long double my_check = 0;
  long double check2 = 0;
  long double my_check2 = 0;
  char str[500] = "-111111110.1111111 -3444.22212125";
  char str2[500] = "-111111110.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%12Le %1Le", &check, &check2);
  int my_res = my_sscanf(str2, "%12Le %1Le", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_e_test7) {
  //#line 3718
  long double check = 0;
  long double my_check = 0;
  long double check2 = 0;
  long double my_check2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%22Le %1Le", &check, &check2);
  int my_res = my_sscanf(str2, "%22Le %1Le", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_ldouble_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_e_test8) {
  //#line 3732
  long double check = 0;
  long double my_check = 0;
  long double check2 = 0;
  long double my_check2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%100Le %1Le", &check, &check2);
  int my_res = my_sscanf(str2, "%100Le %1Le", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_ldouble_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_e_test9) {
  //#line 3746
  long double check = 0;
  long double my_check = 0;
  long double check2 = 0;
  long double my_check2 = 0;
  char str[500] = "111111110.1111111 -0.222155552125";
  char str2[500] = "111111110.1111111 -0.222155552125";
  int expected_res = sscanf(str, "%1Le %1Le", &check, &check2);
  int my_res = my_sscanf(str2, "%1Le %1Le", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_ldouble_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);

  // E
}

END_TEST

START_TEST(my_sscanf_E_test0) {
  //#line 3762
  printf("Start group test sscanf %%E\n");
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "1.1 3.2";
  char str2[500] = "1.1 3.2";
  int expected_res = sscanf(str, "%E %lE", &check, &check2);
  int my_res = my_sscanf(str2, "%E %lE", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_E_test1) {
  //#line 3777
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "1.1111111 3.22212125";
  char str2[500] = "1.1111111 3.22212125";
  int expected_res = sscanf(str, "%E %lE", &check, &check2);
  int my_res = my_sscanf(str2, "%E %lE", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_E_test2) {
  //#line 3791
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int expected_res = sscanf(str, "%E %lE", &check, &check2);
  int my_res = my_sscanf(str2, "%E %lE", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_E_test3) {
  //#line 3805
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int expected_res = sscanf(str, "%3E %17lE", &check, &check2);
  int my_res = my_sscanf(str2, "%3E %17lE", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_E_test4) {
  //#line 3819
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-0.1111111 -3444.22212125";
  char str2[500] = "-0.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%1E %5lE", &check, &check2);
  int my_res = my_sscanf(str2, "%1E %5lE", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_E_test5) {
  //#line 3833
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "0.1111111 3444.22212125";
  char str2[500] = "0.1111111 3444.22212125";
  int expected_res = sscanf(str, "%1E %1lE", &check, &check2);
  int my_res = my_sscanf(str2, "%1E %1lE", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_E_test6) {
  //#line 3847
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-111111110.1111111 -3444.22212125";
  char str2[500] = "-111111110.1111111 -3444.22212125";
  int expected_res = sscanf(str, "-%12LE %1lE", &check, &check2);
  int my_res = my_sscanf(str2, "-%12LE %1lE", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_E_test7) {
  //#line 3861
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "111111120.1111111 -3444.22212125";
  char str2[500] = "111111120.1111111 -3444.22212125";
  int expected_res = sscanf(str, "11%22LE %1lE", &check, &check2);
  int my_res = my_sscanf(str2, "11%22LE %1lE", &my_check, &my_check2);
  ck_assert_ldouble_lt(fabsl(check - my_check), 1e-6);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_E_test8) {
  //#line 3875
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int expected_res = sscanf(str, "111%100LE %1lE", &check, &check2);
  int my_res = my_sscanf(str2, "111%100LE %1lE", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_E_test9) {
  //#line 3889
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "111111110.1111111 -0.222155552125";
  char str2[500] = "111111110.1111111 -0.222155552125";
  int expected_res = sscanf(str, "11%1LE %1lE", &check, &check2);
  int my_res = my_sscanf(str2, "11%1LE %1lE", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);

  // f
}

END_TEST

START_TEST(my_sscanf_f_test0) {
  //#line 3904
  printf("Start group test sscanf %%f\n");
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "1.1 3.2";
  char str2[500] = "1.1 3.2";
  int expected_res = sscanf(str, "%f %lf", &check, &check2);
  int my_res = my_sscanf(str2, "%f %lf", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test1) {
  //#line 3919
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "1231231.11231231  -. 3111.2123123";
  char str2[500] = "1231231.11231231  -. 3111.2123123";
  int expected_res = sscanf(str, "%f %lf", &check, &check2);
  int my_res = my_sscanf(str2, "%f %lf", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test2) {
  //#line 3933
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-1231.11231231  -. -3111.2123123";
  char str2[500] = "-1231.11231231  -. -3111.2123123";
  int expected_res = sscanf(str, "%f %lf", &check, &check2);
  int my_res = my_sscanf(str2, "%f %lf", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test3) {
  //#line 3947
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "1.1111111 3.22212125";
  char str2[500] = "1.1111111 3.22212125";
  int expected_res = sscanf(str, "%f %lf", &check, &check2);
  int my_res = my_sscanf(str2, "%f %lf", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test4) {
  //#line 3961
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int expected_res = sscanf(str, "%f %lf", &check, &check2);
  int my_res = my_sscanf(str2, "%f %lf", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test5) {
  //#line 3975
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int expected_res = sscanf(str, "%3f %17lf", &check, &check2);
  int my_res = my_sscanf(str2, "%3f %17lf", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test6) {
  //#line 3989
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-0.1111111 -3444.22212125";
  char str2[500] = "-0.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%1f -%3lf", &check, &check2);
  int my_res = my_sscanf(str2, "%1f -%3lf", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test9) {
  //#line 4004
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%22Lf %1lf", &check, &check2);
  int my_res = my_sscanf(str2, "%22Lf %1lf", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test10) {
  //#line 4018
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%100Lf %1lf", &check, &check2);
  int my_res = my_sscanf(str2, "%100Lf %1lf", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test11) {
  //#line 4032
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "111111110.1111111 -0.222155552125";
  char str2[500] = "111111110.1111111 -0.222155552125";
  int expected_res = sscanf(str, "%1Lf %1lf", &check, &check2);
  int my_res = my_sscanf(str2, "%1Lf %1lf", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test13) {
  //#line 4045
  double check = 1;
  double my_check = 1;
  char str[500] = "3e-1";
  char str2[500] = "3e-1";
  int expected_res = sscanf(str, "%lf", &check);
  int my_res = my_sscanf(str2, "%lf", &my_check);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test14) {
  //#line 4055
  long double check = 1;
  long double my_check = 1;
  char str[500] = "3e-1";
  char str2[500] = "3e-1";
  int expected_res = sscanf(str, "%Lf", &check);
  int my_res = my_sscanf(str2, "%Lf", &my_check);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test15) {
  //#line 4065
  float check = 1;
  float my_check = 1;
  char str[500] = "3e-1";
  char str2[500] = "3e-1";
  int expected_res = sscanf(str, "%f", &check);
  int my_res = my_sscanf(str2, "%f", &my_check);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test16) {
  //#line 4076
  float check = 1;
  float my_check = 1;
  char str[500] = "3ee-1";
  char str2[500] = "3ee-1";
  int expected_res = sscanf(str, "%f", &check);
  int my_res = my_sscanf(str2, "%f", &my_check);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test17) {
  //#line 4086
  float check = 1;
  float my_check = 1;
  char str[500] = "3eE--1";
  char str2[500] = "3eE--1";
  int expected_res = sscanf(str, "%f", &check);
  int my_res = my_sscanf(str2, "%f", &my_check);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test18) {
  //#line 4096
  float check = 1;
  float my_check = 1;
  char str[500] = "3..5eE--1";
  char str2[500] = "3..5eE--1";
  int expected_res = sscanf(str, "%f", &check);
  int my_res = my_sscanf(str2, "%f", &my_check);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test19) {
  //#line 4106
  float check = 1;
  float my_check = 1;
  char str[500] = "3.5E+1";
  char str2[500] = "3.5E+1";
  int expected_res = sscanf(str, "%f", &check);
  int my_res = my_sscanf(str2, "%f", &my_check);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test20) {
  //#line 4116
  double check = 1;
  double my_check = 1;
  char str[500] = "3.5E+1";
  char str2[500] = "3.5E+1";
  int expected_res = sscanf(str, "%lf", &check);
  int my_res = my_sscanf(str2, "%lf", &my_check);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test21) {
  //#line 4126
  long double check = 1;
  long double my_check = 1;
  char str[500] = "3.5E+1";
  char str2[500] = "3.5E+1";
  int expected_res = sscanf(str, "%Lf", &check);
  int my_res = my_sscanf(str2, "%Lf", &my_check);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test22) {
  //#line 4136
  long double check = 1;
  long double my_check = 1;
  char str[500] = "-3.5E+1";
  char str2[500] = "-3.5E+1";
  int expected_res = sscanf(str, "%Lf", &check);
  int my_res = my_sscanf(str2, "%Lf", &my_check);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test23) {
  //#line 4146
  long double check = 1;
  long double my_check = 1;
  char str[500] = "+3.5E+1";
  char str2[500] = "+3.5E+1";
  int expected_res = sscanf(str, "%Lf", &check);
  int my_res = my_sscanf(str2, "%Lf", &my_check);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test24) {
  //#line 4156
  float check = 1;
  float my_check = 1;
  char str[500] = "3.5E-+1";
  char str2[500] = "3.5E-+1";
  int expected_res = sscanf(str, "%f", &check);
  int my_res = my_sscanf(str2, "%f", &my_check);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test25) {
  //#line 4166
  float check = 1;
  float my_check = 1;
  char str[500] = "3.5E++1";
  char str2[500] = "3.5E++1";
  int expected_res = sscanf(str, "%f", &check);
  int my_res = my_sscanf(str2, "%f", &my_check);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_f_test26) {
  //#line 4176
  float check = 1;
  float my_check = 1;
  int n1 = 0;
  int n2 = 0;
  int d1 = 0;
  int d2 = 0;
  char str[500] = "3.5e-1     5";
  char str2[500] = "3.5e-1     5";
  int expected_res = sscanf(str, "%f%n%d", &check, &n1, &d1);
  int my_res = my_sscanf(str2, "%f%n%d", &my_check, &n2, &d2);
  ck_assert_int_eq(expected_res, my_res);
  // g
}

END_TEST

START_TEST(my_sscanf_g_test0) {
  //#line 4189
  printf("Start group test sscanf %%g\n");
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "1.1 3.2";
  char str2[500] = "1.1 3.2";
  int expected_res = sscanf(str, "%g %lg", &check, &check2);
  int my_res = my_sscanf(str2, "%g %lg", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_g_test1) {
  //#line 4204
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "1231231.11231231  -. 3111.2123123";
  char str2[500] = "1231231.11231231  -. 3111.2123123";
  int expected_res = sscanf(str, "%g  . %lg", &check, &check2);
  int my_res = my_sscanf(str2, "%g  . %lg", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_g_test2) {
  //#line 4218
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-1231.11231231  -. -3111.2123123";
  char str2[500] = "-1231.11231231  -. -3111.2123123";
  int expected_res = sscanf(str, "-%g -%lg", &check, &check2);
  int my_res = my_sscanf(str2, "-%g -%lg", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_g_test3) {
  //#line 4232
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "1.1111111 3.22212125";
  char str2[500] = "1.1111111 3.22212125";
  int expected_res = sscanf(str, "%g %lg", &check, &check2);
  int my_res = my_sscanf(str2, "%g %lg", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_g_test4) {
  //#line 4246
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-1.1111111 - - - -3.22212125";
  char str2[500] = "-1.1111111 - - - -3.22212125";
  int expected_res = sscanf(str, "%g -%lg", &check, &check2);
  int my_res = my_sscanf(str2, "%g -%lg", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_g_test5) {
  //#line 4260
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int expected_res = sscanf(str, "%3g %17lg", &check, &check2);
  int my_res = my_sscanf(str2, "%3g %17lg", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_g_test6) {
  //#line 4274
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-0.1111111 -3444.22212125";
  char str2[500] = "-0.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%1g %3lg", &check, &check2);
  int my_res = my_sscanf(str2, "%1g %3lg", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_g_test7) {
  //#line 4288
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "0.1111111 3444.22212125";
  char str2[500] = "0.1111111 3444.22212125";
  int expected_res = sscanf(str, "%1g 344%2lg", &check, &check2);
  int my_res = my_sscanf(str2, "%1f 344%2lg", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_g_test8) {
  //#line 4302
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-111111110.1111111 -3444.22212125";
  char str2[500] = "-111111110.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%12Lg %1lg", &check, &check2);
  int my_res = my_sscanf(str2, "%12Lg %1lg", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_g_test9) {
  //#line 4316
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%22Lg %1lg", &check, &check2);
  int my_res = my_sscanf(str2, "%22Lg %1lg", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_g_test10) {
  //#line 4330
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%100Lg %1lg", &check, &check2);
  int my_res = my_sscanf(str2, "%100Lg %1lg", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_g_test11) {
  //#line 4344
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "111111110.1111111 -0.222155552125";
  char str2[500] = "111111110.1111111 -0.222155552125";
  int expected_res = sscanf(str, "%1Lg %1lg", &check, &check2);
  int my_res = my_sscanf(str2, "%1Lg %1lg", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);

  // G
}

END_TEST

START_TEST(my_sscanf_G_test0) {
  //#line 4360
  printf("Start group test sscanf %%G\n");
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "1.1 3.2";
  char str2[500] = "1.1 3.2";
  int expected_res = sscanf(str, "%G %lG", &check, &check2);
  int my_res = my_sscanf(str2, "%G %lG", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_G_test2) {
  //#line 4376
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-1231.11231231  -. -3111.2123123";
  char str2[500] = "-1231.11231231  -. -3111.2123123";
  int expected_res = sscanf(str, "-%G -%lG", &check, &check2);
  int my_res = my_sscanf(str2, "-%G -%lG", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_G_test3) {
  //#line 4390
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "1.1111111 3.22212125";
  char str2[500] = "1.1111111 3.22212125";
  int expected_res = sscanf(str, "%G %lG", &check, &check2);
  int my_res = my_sscanf(str2, "%G %lG", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_G_test4) {
  //#line 4404
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-1.1111111 - - - -3.22212125";
  char str2[500] = "-1.1111111 - - - -3.22212125";
  int expected_res = sscanf(str, "%G -%lG", &check, &check2);
  int my_res = my_sscanf(str2, "%G -%lG", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_G_test5) {
  //#line 4418
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int expected_res = sscanf(str, "%3G %17lG", &check, &check2);
  int my_res = my_sscanf(str2, "%3G %17lG", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_G_test7) {
  //#line 4432
  float check = 0;
  float my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "0.1111111 3444.22212125";
  char str2[500] = "0.1111111 3444.22212125";
  int expected_res = sscanf(str, "%1G 344%1lG", &check, &check2);
  int my_res = my_sscanf(str2, "%1G 344%1lG", &my_check, &my_check2);
  ck_assert_float_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_G_test8) {
  //#line 4446
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "-111111110.1111111 -3444.22212125";
  char str2[500] = "-111111110.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%12LG %1lG", &check, &check2);
  int my_res = my_sscanf(str2, "%12LG %1lG", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_G_test9) {
  //#line 4460
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int expected_res = sscanf(str, "%22LG %1lG", &check, &check2);
  int my_res = my_sscanf(str2, "%22LG %1lG", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_G_test11) {
  //#line 4475
  long double check = 0;
  long double my_check = 0;
  double check2 = 0;
  double my_check2 = 0;
  char str[500] = "111111110.1111111 -0.222155552125";
  char str2[500] = "111111110.1111111 -0.222155552125";
  int expected_res = sscanf(str, "%1LG %1lG", &check, &check2);
  int my_res = my_sscanf(str2, "%1LG %1lG", &my_check, &my_check2);
  ck_assert_ldouble_eq(check, my_check);
  ck_assert_double_eq(check2, my_check2);
  ck_assert_int_eq(expected_res, my_res);

  // o
}

END_TEST

START_TEST(my_sscanf_o_test0) {
  //#line 4490
  printf("Start group test sscanf %%o\n");
  unsigned int check = 0;
  unsigned int mycheck = 0;
  unsigned long int check2 = 0;
  unsigned long int mycheck2 = 0;
  unsigned short int check3 = 0;
  unsigned short int mycheck3 = 0;
  char str[500] = "0123 565 . -146";
  char str2[500] = "0123 565 . -146";
  int expected_res = sscanf(str, "%o %lo %ho", &check, &check2, &check3);
  int my_res = my_sscanf(str2, "%o %lo %ho", &mycheck, &mycheck2, &mycheck3);
  ck_assert_uint_eq(check, mycheck);
  ck_assert_uint_eq(check2, mycheck2);
  ck_assert_uint_eq(check3, mycheck3);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_o_test1) {
  //#line 4508
  unsigned int check = 0;
  unsigned int mycheck = 0;
  unsigned long int check2 = 0;
  unsigned long int mycheck2 = 0;
  unsigned short int check3 = 0;
  unsigned short int mycheck3 = 0;
  char str[500] = "0123 565 . -146";
  char str2[500] = "0123 565 . -146";
  int expected_res = sscanf(str, "%1o %2lo %3ho", &check, &check2, &check3);
  int my_res = my_sscanf(str2, "%1o %2lo %3ho", &mycheck, &mycheck2, &mycheck3);
  ck_assert_uint_eq(check, mycheck);
  ck_assert_uint_eq(check2, mycheck2);
  ck_assert_uint_eq(check3, mycheck3);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_o_test2) {
  //#line 4525
  unsigned int check = 0;
  unsigned int mycheck = 0;
  unsigned long int check2 = 0;
  unsigned long int mycheck2 = 0;
  unsigned short int check3 = 0;
  unsigned short int mycheck3 = 0;
  char str[500] = "0123 565 . -146";
  char str2[500] = "0123 565 . -146";
  int expected_res = sscanf(str, "%1o %2lo %3ho", &check, &check2, &check3);
  int my_res = my_sscanf(str2, "%1o %2lo %3ho", &mycheck, &mycheck2, &mycheck3);
  ck_assert_uint_eq(check, mycheck);
  ck_assert_uint_eq(check2, mycheck2);
  ck_assert_uint_eq(check3, mycheck3);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_o_test3) {
  //#line 4542
  unsigned int check = 0;
  unsigned int mycheck = 0;
  unsigned long int check2 = 0;
  unsigned long int mycheck2 = 0;
  unsigned short int check3 = 0;
  unsigned short int mycheck3 = 0;
  char str[500] = "015555555528 777 . -886 54 126";
  char str2[500] = "015555555528 777 . -886 54 126";
  unsigned char c1, c1_;
  unsigned long long int c2, c2_;
  int expected_res = sscanf(str, "%25o %5lo %4ho %hho %llo", &check, &check2,
                            &check3, &c1, &c2);
  int my_res = my_sscanf(str2, "%25o %5lo %4ho %hho %llo", &mycheck, &mycheck2,
                         &mycheck3, &c1_, &c2_);
  ck_assert_uint_eq(check, mycheck);
  ck_assert_uint_eq(check2, mycheck3);
  ck_assert_uint_eq(check3, mycheck3);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_o_test4) {
  //#line 4560
  unsigned int check = 0;
  unsigned int mycheck = 0;
  unsigned long int check2 = 0;
  unsigned long int mycheck2 = 0;
  unsigned short int check3 = 0;
  unsigned short int mycheck3 = 0;
  char str[500] = "+015555555528 777 . -886 54 126";
  char str2[500] = "+015555555528 777 . -886 54 126";
  unsigned char c1, c1_;
  unsigned long long int c2, c2_;
  int expected_res = sscanf(str, "%25o %5lo %4ho %hho %llo", &check, &check2,
                            &check3, &c1, &c2);
  int my_res = my_sscanf(str2, "%25o %5lo %4ho %hho %llo", &mycheck, &mycheck2,
                         &mycheck3, &c1_, &c2_);
  ck_assert_uint_eq(check, mycheck);
  ck_assert_uint_eq(check2, mycheck3);
  ck_assert_uint_eq(check3, mycheck3);
  ck_assert_int_eq(expected_res, my_res);

  // s
}

END_TEST

START_TEST(my_sscanf_s_test1) {
  //#line 4582
  printf("Start group test sscanf %%s\n");
  char str_org[500];
  char str_fke[500];
  char str[500] = "Hello test test test";
  char str2[500] = "Hello test test test";
  int expected_res = sscanf(str, "%3s", str_org);
  int my_res = my_sscanf(str2, "%3s", str_fke);
  ck_assert_str_eq(str_org, str_fke);
  ck_assert_int_eq(my_res, expected_res);
}

END_TEST

START_TEST(my_sscanf_u_test0) {
  //#line 4638
  printf("Start group test sscanf %%u\n");
  unsigned int check = 0;
  unsigned int my_check = 0;
  char str[500] = " 15...";
  char str2[500] = " 15...";
  int expected_res = sscanf(str, "%u", &check);
  int my_res = my_sscanf(str2, "%u", &my_check);
  ck_assert_uint_eq(check, my_check);
  ck_assert_int_eq(my_res, expected_res);
}

END_TEST

START_TEST(my_sscanf_u_test1) {
  //#line 4650
  unsigned int check = 0;
  unsigned int my_check = 0;
  char str[500] = " -15...";
  char str2[500] = " -15...";
  int expected_res = sscanf(str, " %u", &check);
  int my_res = my_sscanf(str2, " %u", &my_check);
  ck_assert_uint_eq(check, my_check);
  ck_assert_int_eq(my_res, expected_res);
}

END_TEST

START_TEST(my_sscanf_u_test3) {
  //#line 4661
  unsigned int check = 0;
  unsigned int my_check = 0;
  unsigned int check2 = 0;
  unsigned int my_check2 = 0;
  char str[500] = " 15.124..";
  char str2[500] = " 15.124..";
  int c1, c1_;
  int expected_res = sscanf(str, " %2u.%3u..%n", &check, &check2, &c1);
  int my_res = my_sscanf(str2, " %2u.%3u..%n", &my_check, &my_check2, &c1_);
  ck_assert_uint_eq(check, my_check);
  ck_assert_uint_eq(check2, my_check2);
  ck_assert_int_eq(my_res, expected_res);
}

END_TEST

START_TEST(my_sscanf_u_test4) {
  //#line 4676
  unsigned int check = 0;
  unsigned int my_check = 0;
  unsigned int check2 = 0;
  unsigned int my_check2 = 0;
  char str[500] = " -15 -. - .\0 124..";
  char str2[500] = " -15 -. - .\0 124..";
  int expected_res = sscanf(str, " %1u %2u", &check, &check2);
  int my_res = my_sscanf(str2, " %1u %2u", &my_check, &my_check2);
  ck_assert_int_eq(my_res, expected_res);
  ck_assert_uint_eq(check, my_check);
  ck_assert_uint_eq(check2, my_check2);
}

END_TEST

START_TEST(my_sscanf_u_test5) {
  //#line 4690
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  char str[500] = " 15...";
  char str2[500] = " 15...";
  int expected_res = sscanf(str, "%hu", &check);
  int my_res = my_sscanf(str2, "%hu", &my_check);
  ck_assert_uint_eq(check, my_check);
  ck_assert_int_eq(my_res, expected_res);
}

END_TEST

START_TEST(my_sscanf_u_test6) {
  //#line 4701
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  char str[500] = " -15...";
  char str2[500] = " -15...";
  int expected_res = sscanf(str, " %1hu", &check);
  int my_res = my_sscanf(str2, " %1hu", &my_check);
  ck_assert_uint_eq(check, my_check);
  ck_assert_int_eq(my_res, expected_res);
}

END_TEST

START_TEST(my_sscanf_u_test7) {
  //#line 4712
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  char str[500] = " 15.124..";
  char str2[500] = " 15.124..";
  int expected_res = sscanf(str, " %6hu", &check);
  int my_res = my_sscanf(str2, " %6hu", &my_check);
  ck_assert_uint_eq(check, my_check);
  ck_assert_int_eq(my_res, expected_res);
}

END_TEST

START_TEST(my_sscanf_u_test8) {
  //#line 4723
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  unsigned short int check2 = 0;
  unsigned short int my_check2 = 0;
  char str[500] = " 15.124..";
  char str2[500] = " 15.124..";
  int expected_res = sscanf(str, " %2hu %3hu", &check, &check2);
  int my_res = my_sscanf(str2, " %2hu %3hu", &my_check, &my_check2);
  ck_assert_uint_eq(check, my_check);
  ck_assert_uint_eq(check2, my_check2);
  ck_assert_int_eq(my_res, expected_res);
}

END_TEST

START_TEST(my_sscanf_u_test9) {
  //#line 4737
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  unsigned short int check2 = 0;
  unsigned short int my_check2 = 0;
  char str[500] = " -15 -. - .\0 124..";
  char str2[500] = " -15 -. - .\0 124..";
  int expected_res = sscanf(str, " %hu %hu", &check, &check2);
  int my_res = my_sscanf(str2, " %hu %hu", &my_check, &my_check2);
  ck_assert_uint_eq(check, my_check);
  ck_assert_uint_eq(check2, my_check2);
  ck_assert_int_eq(my_res, expected_res);
}

END_TEST

START_TEST(my_sscanf_u_test10) {
  //#line 4751
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  char str[500] = " .15000000000...";
  char str2[500] = " .15000000000...";
  int expected_res = sscanf(str, "%lu", &check);
  int my_res = my_sscanf(str2, "%lu", &my_check);
  ck_assert_uint_eq(check, my_check);
  ck_assert_int_eq(my_res, expected_res);
}

END_TEST

START_TEST(my_sscanf_u_test11) {
  //#line 4762
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  char str[500] = " -15...";
  char str2[500] = " -15...";
  int expected_res = sscanf(str, " %1lu", &check);
  int my_res = my_sscanf(str2, " %1lu", &my_check);
  ck_assert_uint_eq(check, my_check);
  ck_assert_int_eq(my_res, expected_res);
}

END_TEST

START_TEST(my_sscanf_u_test12) {
  //#line 4773
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  char str[500] = " 15.124..";
  char str2[500] = " 15.124..";
  int expected_res = sscanf(str, " %6lu", &check);
  int my_res = my_sscanf(str2, " %6lu", &my_check);
  ck_assert_uint_eq(check, my_check);
  ck_assert_int_eq(my_res, expected_res);
}

END_TEST

START_TEST(my_sscanf_u_test13) {
  //#line 4784
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  unsigned long int check2 = 0;
  unsigned long int my_check2 = 0;
  char str[500] = " 15.124..";
  char str2[500] = " 15.124..";
  int expected_res = sscanf(str, " %2lu %3lu", &check, &check2);
  int my_res = my_sscanf(str2, " %2lu %3lu", &my_check, &my_check2);
  ck_assert_uint_eq(check, my_check);
  ck_assert_uint_eq(check2, my_check2);
  ck_assert_int_eq(my_res, expected_res);
}

END_TEST

START_TEST(my_sscanf_u_test14) {
  //#line 4798
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  unsigned long int check2 = 0;
  unsigned long int my_check2 = 0;
  char str[500] = " -15 -. - .\0 124..";
  char str2[500] = " -15 -. - .\0 124..";
  int expected_res = sscanf(str, " %lu %lu", &check, &check2);
  int my_res = my_sscanf(str2, " %lu %lu", &my_check, &my_check2);
  ck_assert_uint_eq(check, my_check);
  ck_assert_uint_eq(check2, my_check2);
  ck_assert_int_eq(my_res, expected_res);

  // X
}

END_TEST

START_TEST(my_sscanf_X_test1) {
  //#line 4814
  printf("Start group test sscanf %%X\n");
  unsigned int check = 0;
  unsigned int my_check = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int expected_res = sscanf(str, "0%X", &check);
  int my_res = my_sscanf(str2, "0%X", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test2) {
  //#line 4826
  unsigned int check = 0;
  unsigned int my_check = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int expected_res = sscanf(str, "%X", &check);
  int my_res = my_sscanf(str2, "%X", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test3) {
  //#line 4837
  unsigned int check = 0;
  unsigned int my_check = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int expected_res = sscanf(str, "%X", &check);
  int my_res = my_sscanf(str2, "%X", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test4) {
  //#line 4848
  unsigned int check = 0;
  unsigned int my_check = 0;
  unsigned int check2 = 0;
  unsigned int my_check2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int expected_res = sscanf(str, "%X %X", &check, &check2);
  int my_res = my_sscanf(str2, "%X %X", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test5) {
  //#line 4861
  unsigned int check = 0;
  unsigned int my_check = 0;
  unsigned int check2 = 0;
  unsigned int my_check2 = 0;
  char str[500] = "0xFFe,,,\0AAAa";
  char str2[500] = "0xFFe,,,\0AAAa";
  int expected_res = sscanf(str, "%1X ,%3X", &check, &check2);
  int my_res = my_sscanf(str2, "%1X ,%3X", &my_check, &my_check2);
  ck_assert_uint_eq(check, my_check);
  ck_assert_int_eq(expected_res, my_res);
}

END_TEST

START_TEST(my_sscanf_X_test6) {
  //#line 4874
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int expected_res = sscanf(str, "%hX", &check);
  int my_res = my_sscanf(str2, "%hX", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test7) {
  //#line 4885
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int expected_res = sscanf(str, "0%hX", &check);
  int my_res = my_sscanf(str2, "0%hX", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test8) {
  //#line 4896
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int expected_res = sscanf(str, "%hX", &check);
  int my_res = my_sscanf(str2, "%hX", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test9) {
  //#line 4907
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int expected_res = sscanf(str, "%hX", &check);
  int my_res = my_sscanf(str2, "%hX", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test10) {
  //#line 4918
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  unsigned short int check2 = 0;
  unsigned short int my_check2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int expected_res = sscanf(str, "%hX %hX", &check, &check2);
  int my_res = my_sscanf(str2, "%hX %hX", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test11) {
  //#line 4931
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  unsigned short int check2 = 0;
  unsigned short int my_check2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int expected_res = sscanf(str, "%1hX ,%3hX", &check, &check2);
  int my_res = my_sscanf(str2, "%1hX ,%3hX", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test14) {
  //#line 4944
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int expected_res = sscanf(str, "%lX", &check);
  int my_res = my_sscanf(str2, "%lX", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test15) {
  //#line 4955
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int expected_res = sscanf(str, "0%lX", &check);
  int my_res = my_sscanf(str2, "0%lX", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test16) {
  //#line 4966
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int expected_res = sscanf(str, "%lX", &check);
  int my_res = my_sscanf(str2, "%lX", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test17) {
  //#line 4977
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int expected_res = sscanf(str, "%lX", &check);
  int my_res = my_sscanf(str2, "%lX", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test18) {
  //#line 4988
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  unsigned long int check2 = 0;
  unsigned long int my_check2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int expected_res = sscanf(str, "%lX %lX", &check, &check2);
  int my_res = my_sscanf(str2, "%lX %lX", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test19) {
  //#line 5001
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  unsigned long int check2 = 0;
  unsigned long int my_check2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int expected_res = sscanf(str, "%1lX ,%3lX", &check, &check2);
  int my_res = my_sscanf(str2, "%1lX ,%3lX", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_X_test20) {
  //#line 5013
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  unsigned long int check2 = 0;
  unsigned long int my_check2 = 0;
  char str[500] = "+0xFFe,,,\0AAAa";
  char str2[500] = "+0xFFe,,,\0AAAa";
  int expected_res = sscanf(str, "%1lX ,%3lX", &check, &check2);
  int my_res = my_sscanf(str2, "%1lX ,%3lX", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);

  // x
}

END_TEST

START_TEST(my_sscanf_x_test0) {
  //#line 5027
  printf("Start group test sscanf %%x\n");
  unsigned int check = 0;
  unsigned int my_check = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int expected_res = sscanf(str, "%x", &check);
  int my_res = my_sscanf(str2, "%x", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test1) {
  //#line 5039
  unsigned int check = 0;
  unsigned int my_check = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int expected_res = sscanf(str, "0%x", &check);
  int my_res = my_sscanf(str2, "0%x", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test2) {
  //#line 5050
  unsigned int check = 0;
  unsigned int my_check = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int expected_res = sscanf(str, "%x", &check);
  int my_res = my_sscanf(str2, "%x", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test3) {
  //#line 5061
  unsigned int check = 0;
  unsigned int my_check = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int expected_res = sscanf(str, "%x", &check);
  int my_res = my_sscanf(str2, "%x", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test4) {
  //#line 5072
  unsigned int check = 0;
  unsigned int my_check = 0;
  unsigned int check2 = 0;
  unsigned int my_check2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int expected_res = sscanf(str, "%x %x", &check, &check2);
  int my_res = my_sscanf(str2, "%x %x", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test5) {
  //#line 5085
  unsigned int check = 0;
  unsigned int my_check = 0;
  unsigned int check2 = 0;
  unsigned int my_check2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int expected_res = sscanf(str, "%1x ,%3x", &check, &check2);
  int my_res = my_sscanf(str2, "%1x ,%3x", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test6) {
  //#line 5098
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int expected_res = sscanf(str, "%hx", &check);
  int my_res = my_sscanf(str2, "%hx", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test7) {
  //#line 5109
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int expected_res = sscanf(str, "0%hx", &check);
  int my_res = my_sscanf(str2, "0%hx", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test8) {
  //#line 5120
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int expected_res = sscanf(str, "%hx", &check);
  int my_res = my_sscanf(str2, "%hx", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test9) {
  //#line 5131
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int expected_res = sscanf(str, "%hx", &check);
  int my_res = my_sscanf(str2, "%hx", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test10) {
  //#line 5142
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  unsigned short int check2 = 0;
  unsigned short int my_check2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int expected_res = sscanf(str, "%hx %hx", &check, &check2);
  int my_res = my_sscanf(str2, "%hx %hx", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test11) {
  //#line 5155
  unsigned short int check = 0;
  unsigned short int my_check = 0;
  unsigned short int check2 = 0;
  unsigned short int my_check2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int expected_res = sscanf(str, "%1hx ,%3hx", &check, &check2);
  int my_res = my_sscanf(str2, "%1hx ,%3hx", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test14) {
  //#line 5168
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int expected_res = sscanf(str, "%lx", &check);
  int my_res = my_sscanf(str2, "%lx", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test15) {
  //#line 5179
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int expected_res = sscanf(str, "0%lx", &check);
  int my_res = my_sscanf(str2, "0%lx", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test16) {
  //#line 5190
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int expected_res = sscanf(str, "%lx", &check);
  int my_res = my_sscanf(str2, "%lx", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test17) {
  //#line 5201
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int expected_res = sscanf(str, "%lx", &check);
  int my_res = my_sscanf(str2, "%lx", &my_check);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test18) {
  //#line 5212
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  unsigned long int check2 = 0;
  unsigned long int my_check2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int expected_res = sscanf(str, "%lx %lx", &check, &check2);
  int my_res = my_sscanf(str2, "%lx %lx", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

START_TEST(my_sscanf_x_test19) {
  //#line 5225
  unsigned long int check = 0;
  unsigned long int my_check = 0;
  unsigned long int check2 = 0;
  unsigned long int my_check2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int expected_res = sscanf(str, "%1lx ,%3lx", &check, &check2);
  int my_res = my_sscanf(str2, "%1lx ,%3lx", &my_check, &my_check2);
  ck_assert_int_eq(expected_res, my_res);
  ck_assert_uint_eq(check, my_check);
}

END_TEST

Suite *

funcs_suite() {
  Suite *my = suite_create("my_suite");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, memchr_1);
  tcase_add_test(tc_core, memchr_2);
  tcase_add_test(tc_core, memchr_3);
  tcase_add_test(tc_core, memchr_4);
  tcase_add_test(tc_core, memchr_5);
  tcase_add_test(tc_core, memchr_6);
  tcase_add_test(tc_core, memchr_7);
  tcase_add_test(tc_core, memchr_8);
  tcase_add_test(tc_core, memchr_9);
  tcase_add_test(tc_core, memchr_10);

  tcase_add_test(tc_core, memcmp_1);
  tcase_add_test(tc_core, memcmp_2);
  tcase_add_test(tc_core, memcmp_3);
  tcase_add_test(tc_core, memcmp_4);
  tcase_add_test(tc_core, memcmp_5);
  tcase_add_test(tc_core, memcmp_6);
  tcase_add_test(tc_core, memcmp_7);
  tcase_add_test(tc_core, memcmp_8);
  tcase_add_test(tc_core, memcmp_9);
  tcase_add_test(tc_core, memcmp_10);

  tcase_add_test(tc_core, memcpy_1);
  tcase_add_test(tc_core, memcpy_2);
  tcase_add_test(tc_core, memcpy_3);
  tcase_add_test(tc_core, memcpy_4);
  tcase_add_test(tc_core, memcpy_5);
  tcase_add_test(tc_core, memcpy_6);
  tcase_add_test(tc_core, memcpy_7);
  tcase_add_test(tc_core, memcpy_8);
  tcase_add_test(tc_core, memcpy_9);
  tcase_add_test(tc_core, memcpy_10);

  tcase_add_test(tc_core, memmove_1);
  tcase_add_test(tc_core, memmove_2);
  tcase_add_test(tc_core, memmove_3);
  tcase_add_test(tc_core, memmove_4);
  tcase_add_test(tc_core, memmove_5);
  tcase_add_test(tc_core, memmove_6);
  tcase_add_test(tc_core, memmove_7);
  tcase_add_test(tc_core, memmove_8);
  tcase_add_test(tc_core, memmove_9);
  tcase_add_test(tc_core, memmove_10);

  tcase_add_test(tc_core, memset_1);
  tcase_add_test(tc_core, memset_2);
  tcase_add_test(tc_core, memset_3);
  tcase_add_test(tc_core, memset_4);
  tcase_add_test(tc_core, memset_5);
  tcase_add_test(tc_core, memset_6);
  tcase_add_test(tc_core, memset_7);
  tcase_add_test(tc_core, memset_8);
  tcase_add_test(tc_core, memset_9);
  tcase_add_test(tc_core, memset_10);

  tcase_add_test(tc_core, strcat_1);
  tcase_add_test(tc_core, strcat_2);
  tcase_add_test(tc_core, strcat_3);
  tcase_add_test(tc_core, strcat_4);
  tcase_add_test(tc_core, strcat_5);
  tcase_add_test(tc_core, strcat_6);
  tcase_add_test(tc_core, strcat_7);
  tcase_add_test(tc_core, strcat_8);
  tcase_add_test(tc_core, strcat_9);
  tcase_add_test(tc_core, strcat_10);

  tcase_add_test(tc_core, strncat_1);
  tcase_add_test(tc_core, strncat_2);
  tcase_add_test(tc_core, strncat_3);
  tcase_add_test(tc_core, strncat_4);
  tcase_add_test(tc_core, strncat_5);
  tcase_add_test(tc_core, strncat_6);
  tcase_add_test(tc_core, strncat_7);
  tcase_add_test(tc_core, strncat_8);
  tcase_add_test(tc_core, strncat_9);
  tcase_add_test(tc_core, strncat_10);

  tcase_add_test(tc_core, strchr_1);
  tcase_add_test(tc_core, strchr_2);
  tcase_add_test(tc_core, strchr_3);
  tcase_add_test(tc_core, strchr_4);
  tcase_add_test(tc_core, strchr_5);
  tcase_add_test(tc_core, strchr_6);
  tcase_add_test(tc_core, strchr_7);
  tcase_add_test(tc_core, strchr_8);
  tcase_add_test(tc_core, strchr_9);
  tcase_add_test(tc_core, strchr_10);

  tcase_add_test(tc_core, strcmp_1);
  tcase_add_test(tc_core, strcmp_2);
  tcase_add_test(tc_core, strcmp_3);
  tcase_add_test(tc_core, strcmp_4);
  tcase_add_test(tc_core, strcmp_5);
  tcase_add_test(tc_core, strcmp_6);
  tcase_add_test(tc_core, strcmp_7);
  tcase_add_test(tc_core, strcmp_8);
  tcase_add_test(tc_core, strcmp_9);
  tcase_add_test(tc_core, strcmp_10);

  tcase_add_test(tc_core, strncmp_1);
  tcase_add_test(tc_core, strncmp_2);
  tcase_add_test(tc_core, strncmp_3);
  tcase_add_test(tc_core, strncmp_4);
  tcase_add_test(tc_core, strncmp_5);
  tcase_add_test(tc_core, strncmp_6);
  tcase_add_test(tc_core, strncmp_7);
  tcase_add_test(tc_core, strncmp_8);
  tcase_add_test(tc_core, strncmp_9);
  // tcase_add_test(tc_core, strncmp_10);

  tcase_add_test(tc_core, strcpy_1);
  tcase_add_test(tc_core, strcpy_2);
  tcase_add_test(tc_core, strcpy_3);
  tcase_add_test(tc_core, strcpy_4);
  tcase_add_test(tc_core, strcpy_5);
  tcase_add_test(tc_core, strcpy_6);
  tcase_add_test(tc_core, strcpy_7);
  tcase_add_test(tc_core, strcpy_8);
  tcase_add_test(tc_core, strcpy_9);
  tcase_add_test(tc_core, strcpy_10);

  tcase_add_test(tc_core, strncpy_1);
  tcase_add_test(tc_core, strncpy_2);
  tcase_add_test(tc_core, strncpy_3);
  tcase_add_test(tc_core, strncpy_4);
  tcase_add_test(tc_core, strncpy_5);
  tcase_add_test(tc_core, strncpy_6);
  tcase_add_test(tc_core, strncpy_7);
  tcase_add_test(tc_core, strncpy_8);
  tcase_add_test(tc_core, strncpy_9);
  tcase_add_test(tc_core, strncpy_10);

  tcase_add_test(tc_core, strcspn_1);
  tcase_add_test(tc_core, strcspn_2);
  tcase_add_test(tc_core, strcspn_3);
  tcase_add_test(tc_core, strcspn_4);
  tcase_add_test(tc_core, strcspn_5);
  tcase_add_test(tc_core, strcspn_6);
  tcase_add_test(tc_core, strcspn_7);
  tcase_add_test(tc_core, strcspn_8);
  tcase_add_test(tc_core, strcspn_9);
  tcase_add_test(tc_core, strcspn_10);

  tcase_add_test(tc_core, strerror_test);

  tcase_add_test(tc_core, strlen_1);
  tcase_add_test(tc_core, strlen_2);
  tcase_add_test(tc_core, strlen_3);
  tcase_add_test(tc_core, strlen_4);
  tcase_add_test(tc_core, strlen_5);
  tcase_add_test(tc_core, strlen_6);
  tcase_add_test(tc_core, strlen_7);
  tcase_add_test(tc_core, strlen_8);
  tcase_add_test(tc_core, strlen_9);
  tcase_add_test(tc_core, strlen_10);

  tcase_add_test(tc_core, strpbrk_1);
  tcase_add_test(tc_core, strpbrk_2);
  tcase_add_test(tc_core, strpbrk_3);
  tcase_add_test(tc_core, strpbrk_4);
  tcase_add_test(tc_core, strpbrk_5);
  tcase_add_test(tc_core, strpbrk_6);
  tcase_add_test(tc_core, strpbrk_7);
  tcase_add_test(tc_core, strpbrk_8);
  tcase_add_test(tc_core, strpbrk_9);
  tcase_add_test(tc_core, strpbrk_10);

  tcase_add_test(tc_core, strrchr_1);
  tcase_add_test(tc_core, strrchr_2);
  tcase_add_test(tc_core, strrchr_3);
  tcase_add_test(tc_core, strrchr_4);
  tcase_add_test(tc_core, strrchr_5);
  tcase_add_test(tc_core, strrchr_6);
  tcase_add_test(tc_core, strrchr_7);
  tcase_add_test(tc_core, strrchr_8);
  tcase_add_test(tc_core, strrchr_9);
  tcase_add_test(tc_core, strrchr_10);

  tcase_add_test(tc_core, strspn_1);
  tcase_add_test(tc_core, strspn_2);
  tcase_add_test(tc_core, strspn_3);
  tcase_add_test(tc_core, strspn_4);
  tcase_add_test(tc_core, strspn_5);
  tcase_add_test(tc_core, strspn_6);
  tcase_add_test(tc_core, strspn_7);
  tcase_add_test(tc_core, strspn_8);
  tcase_add_test(tc_core, strspn_9);
  tcase_add_test(tc_core, strspn_10);

  tcase_add_test(tc_core, strstr_1);
  tcase_add_test(tc_core, strstr_2);
  tcase_add_test(tc_core, strstr_3);
  tcase_add_test(tc_core, strstr_4);
  tcase_add_test(tc_core, strstr_5);
  tcase_add_test(tc_core, strstr_6);
  tcase_add_test(tc_core, strstr_7);
  tcase_add_test(tc_core, strstr_8);
  tcase_add_test(tc_core, strstr_9);
  tcase_add_test(tc_core, strstr_10);

  tcase_add_test(tc_core, strtok_test);

  tcase_add_test(tc_core, sprintf_int_1);
  tcase_add_test(tc_core, sprintf_int_2);
  tcase_add_test(tc_core, sprintf_int_3);
  tcase_add_test(tc_core, sprintf_int_4);
  tcase_add_test(tc_core, sprintf_int_5);
  tcase_add_test(tc_core, sprintf_int_6);
  tcase_add_test(tc_core, sprintf_int_7);

  tcase_add_test(tc_core, sprintf_ld);
  tcase_add_test(tc_core, sprintf_hd);
  tcase_add_test(tc_core, sprintf_li_1);
  tcase_add_test(tc_core, sprintf_li_2);
  tcase_add_test(tc_core, sprintf_li_3);

  tcase_add_test(tc_core, sprintf_unsgint_1);
  tcase_add_test(tc_core, sprintf_unsgint_2);
  tcase_add_test(tc_core, sprintf_unsgint_3);
  tcase_add_test(tc_core, sprintf_unsgint_4);
  tcase_add_test(tc_core, sprintf_unsgint_5);
  tcase_add_test(tc_core, sprintf_unsgint_6);
  tcase_add_test(tc_core, sprintf_unsgint_short);
  tcase_add_test(tc_core, sprintf_unsgint_long);
  tcase_add_test(tc_core, sprintf_unsgint_all);

  tcase_add_test(tc_core, sprintf_iint_1);
  tcase_add_test(tc_core, sprintf_iint_2);

  tcase_add_test(tc_core, sprintf_float_1);
  tcase_add_test(tc_core, sprintf_float_2);
  tcase_add_test(tc_core, sprintf_float_3);
  tcase_add_test(tc_core, sprintf_float_4);
  tcase_add_test(tc_core, sprintf_float_5);
  tcase_add_test(tc_core, sprintf_float_6);

  tcase_add_test(tc_core, sprintf_char_1);
  tcase_add_test(tc_core, sprintf_char_2);
  tcase_add_test(tc_core, sprintf_char_3);
  tcase_add_test(tc_core, sprintf_char_4);
  tcase_add_test(tc_core, sprintf_char_5);
  tcase_add_test(tc_core, sprintf_char_6);
  tcase_add_test(tc_core, sprintf_char_7);
  tcase_add_test(tc_core, sprintf_char_8);

  tcase_add_test(tc_core, sprintf_str_1);
  tcase_add_test(tc_core, sprintf_str_2);
  tcase_add_test(tc_core, sprintf_str_3);
  tcase_add_test(tc_core, sprintf_str_4);
  tcase_add_test(tc_core, sprintf_str_5);
  tcase_add_test(tc_core, sprintf_str_6);
  tcase_add_test(tc_core, sprintf_str_7);
  tcase_add_test(tc_core, sprintf_str_8);

  tcase_add_test(tc_core, test_my_to_upper_1);
  tcase_add_test(tc_core, test_my_to_upper_2);
  tcase_add_test(tc_core, test_my_to_upper_3);
  tcase_add_test(tc_core, test_my_to_upper_4);
  tcase_add_test(tc_core, test_my_to_upper_5);
  tcase_add_test(tc_core, test_my_to_upper_6);

  tcase_add_test(tc_core, test_my_to_lower_1);
  tcase_add_test(tc_core, test_my_to_lower_2);
  tcase_add_test(tc_core, test_my_to_lower_3);
  tcase_add_test(tc_core, test_my_to_lower_4);
  tcase_add_test(tc_core, test_my_to_lower_5);
  tcase_add_test(tc_core, test_my_to_lower_6);

  tcase_add_test(tc_core, test_my_insert_1);
  tcase_add_test(tc_core, test_my_insert_2);
  tcase_add_test(tc_core, test_my_insert_3);
  tcase_add_test(tc_core, test_my_insert_4);

  tcase_add_test(tc_core, test_my_trim_1);
  tcase_add_test(tc_core, test_my_trim_2);
  tcase_add_test(tc_core, test_my_trim_3);
  tcase_add_test(tc_core, test_my_trim_4);

  tcase_add_test(tc_core, sprintf_width_char);
  tcase_add_test(tc_core, sprintf_space);
  tcase_add_test(tc_core, sprintf_percent);
  tcase_add_test(tc_core, sprintf_float_zero);

  tcase_add_test(tc_core, my_sprintf_c_test_1);
  tcase_add_test(tc_core, my_sprintf_c_test_2);
  tcase_add_test(tc_core, my_sprintf_c_test_3);
  tcase_add_test(tc_core, my_sprintf_c_test_4);
  tcase_add_test(tc_core, my_sprintf_c_test_5);
  tcase_add_test(tc_core, my_sprintf_c_test_6);
  tcase_add_test(tc_core, my_sprintf_c_test_8);
  tcase_add_test(tc_core, my_sprintf_c_test_9);
  tcase_add_test(tc_core, my_sprintf_c_test_10);
  tcase_add_test(tc_core, my_sprintf_c_test_11);
  tcase_add_test(tc_core, my_sprintf_c_test_12);
  tcase_add_test(tc_core, my_sprintf_c_test_13);
  tcase_add_test(tc_core, my_sprintf_c_test_15);
  tcase_add_test(tc_core, my_sprintf_c_test_16);
  tcase_add_test(tc_core, my_sprintf_c_test_17);
  tcase_add_test(tc_core, my_sprintf_c_test_18);
  tcase_add_test(tc_core, my_sprintf_c_test_19);
  tcase_add_test(tc_core, my_sprintf_c_test_20);
  tcase_add_test(tc_core, my_sprintf_c_test_21);
  tcase_add_test(tc_core, my_sprintf_c_test_22);
  tcase_add_test(tc_core, my_sprintf_c_test_23);
  tcase_add_test(tc_core, my_sprintf_c_test_24);
  tcase_add_test(tc_core, my_sprintf_c_test_25);
  tcase_add_test(tc_core, my_sprintf_c_test_26);
  tcase_add_test(tc_core, my_sprintf_i_test_1);
  tcase_add_test(tc_core, my_sprintf_i_test_2);
  tcase_add_test(tc_core, my_sprintf_i_test_3);
  tcase_add_test(tc_core, my_sprintf_i_test_4);
  tcase_add_test(tc_core, my_sprintf_i_test_5);
  tcase_add_test(tc_core, my_sprintf_i_test_6);
  tcase_add_test(tc_core, my_sprintf_i_test_7);
  tcase_add_test(tc_core, my_sprintf_i_test_8);
  tcase_add_test(tc_core, my_sprintf_i_test_9);
  tcase_add_test(tc_core, my_sprintf_i_test_10);
  tcase_add_test(tc_core, my_sprintf_i_test_11);
  tcase_add_test(tc_core, my_sprintf_i_test_12);
  tcase_add_test(tc_core, my_sprintf_i_test_13);
  tcase_add_test(tc_core, my_sprintf_u_test_1);
  tcase_add_test(tc_core, my_sprintf_u_test_2);
  tcase_add_test(tc_core, my_sprintf_u_test_3);
  tcase_add_test(tc_core, my_sprintf_u_test_4);
  tcase_add_test(tc_core, my_sprintf_u_test_5);
  tcase_add_test(tc_core, my_sprintf_u_test_6);
  tcase_add_test(tc_core, my_sprintf_u_test_7);
  tcase_add_test(tc_core, my_sprintf_u_test_8);
  tcase_add_test(tc_core, my_sprintf_u_test_9);
  tcase_add_test(tc_core, my_sprintf_u_test_10);
  tcase_add_test(tc_core, my_sprintf_test_LINES);
  tcase_add_test(tc_core, my_sprintf_d_test_0);
  tcase_add_test(tc_core, my_sprintf_lh_test_1);
  tcase_add_test(tc_core, my_sprintf_d_test_1);
  tcase_add_test(tc_core, my_sprintf_d_test_2);
  tcase_add_test(tc_core, my_sprintf_d_test_3);
  tcase_add_test(tc_core, my_sprintf_d_test_4);
  tcase_add_test(tc_core, my_sprintf_d_test_5);
  tcase_add_test(tc_core, my_sprintf_d_test_6);
  tcase_add_test(tc_core, my_sprintf_d_test_7);
  tcase_add_test(tc_core, my_sprintf_d_test_8);
  tcase_add_test(tc_core, my_sprintf_d_test_9);
  tcase_add_test(tc_core, my_sprintf_d_test_10);
  tcase_add_test(tc_core, my_sprintf_d_test_11);
  tcase_add_test(tc_core, my_sprintf_d_test_12);
  tcase_add_test(tc_core, my_sprintf_d_test_13);
  tcase_add_test(tc_core, my_sprintf_d_test_14);
  tcase_add_test(tc_core, my_sprintf_d_test_15);
  tcase_add_test(tc_core, my_sprintf_d_test_16);
  tcase_add_test(tc_core, my_sprintf_percent_test_1);
  tcase_add_test(tc_core, my_sprintf_s_test_1);
  tcase_add_test(tc_core, my_sprintf_s_test_2);
  tcase_add_test(tc_core, my_sprintf_s_test_3);
  tcase_add_test(tc_core, my_sprintf_s_test_4);
  tcase_add_test(tc_core, my_sprintf_s_test_5);
  tcase_add_test(tc_core, my_sprintf_s_test_6);
  tcase_add_test(tc_core, my_sprintf_s_test_7);
  tcase_add_test(tc_core, my_default);
  tcase_add_test(tc_core, my_sprintf_f_test_0);
  tcase_add_test(tc_core, my_sprintf_f_test_1);
  tcase_add_test(tc_core, my_sprintf_f_test_2);
  tcase_add_test(tc_core, my_sprintf_f_test_3);
  tcase_add_test(tc_core, my_sprintf_f_test_4);
  tcase_add_test(tc_core, my_sprintf_f_test_5);
  tcase_add_test(tc_core, my_sprintf_f_test_6);
  tcase_add_test(tc_core, my_sprintf_f_test_7);
  tcase_add_test(tc_core, my_sprintf_f_test_8);
  tcase_add_test(tc_core, my_sprintf_f_test_9);
  tcase_add_test(tc_core, my_sprintf_f_test_10);
  tcase_add_test(tc_core, my_sprintf_f_test_11);
  tcase_add_test(tc_core, my_sprintf_f_test_12);
  tcase_add_test(tc_core, my_sprintf_f_test_13);
  tcase_add_test(tc_core, my_sprintf_f_test_14);
  tcase_add_test(tc_core, my_sprintf_f_test);
  tcase_add_test(tc_core, my_sprintf_f_test_16);
  tcase_add_test(tc_core, my_sprintf_f_test_17);
  tcase_add_test(tc_core, my_sprintf_f_test_18);
  tcase_add_test(tc_core, my_sprintf_f_test_19);
  tcase_add_test(tc_core, my_sprintf_f_test_20);
  tcase_add_test(tc_core, my_sprintf_f_test_21);
  tcase_add_test(tc_core, my_sprintf_f_test_22);
  tcase_add_test(tc_core, my_sprintf_f_test_23);
  tcase_add_test(tc_core, my_sprintf_f_test_24);
  tcase_add_test(tc_core, my_sprintf_f_test_25);
  tcase_add_test(tc_core, my_sprintf_f_test_26);
  tcase_add_test(tc_core, my_sprintf_f_test_27);
  tcase_add_test(tc_core, my_sprintf_f_test_28);
  tcase_add_test(tc_core, my_sprintf_f_test_29);
  tcase_add_test(tc_core, my_sprintf_f_test_30);
  tcase_add_test(tc_core, my_sprintf_f_test_31);
  tcase_add_test(tc_core, my_sprintf_f_test_32);
  tcase_add_test(tc_core, my_sprintf_f_test_33);
  tcase_add_test(tc_core, my_sprintf_test_1);
  tcase_add_test(tc_core, my_sprintf_test_2);
  tcase_add_test(tc_core, my_sprintf_test_3);
  tcase_add_test(tc_core, my_sprintf_test_4);
  tcase_add_test(tc_core, my_sprintf_test_5);
  tcase_add_test(tc_core, my_sprintf_test_6);
  tcase_add_test(tc_core, my_sprintf_test_7);
  tcase_add_test(tc_core, my_sprintf_test_8);
  tcase_add_test(tc_core, my_sprintf_test_9);
  tcase_add_test(tc_core, my_sprintf_test_10);
  tcase_add_test(tc_core, my_sprintf_test_11);
  tcase_add_test(tc_core, my_sprintf_test_12);
  tcase_add_test(tc_core, my_sprintf_test_13);
  tcase_add_test(tc_core, my_sprintf_test_14);
  tcase_add_test(tc_core, my_sprintf_test_15);
  tcase_add_test(tc_core, my_sprintf_test_16);
  tcase_add_test(tc_core, my_sprintf_test_17);
  tcase_add_test(tc_core, my_sprintf_test_18);
  tcase_add_test(tc_core, my_sprintf_test_19);
  tcase_add_test(tc_core, my_sprintf_test_20);
  tcase_add_test(tc_core, my_sprintf_test_21);
  tcase_add_test(tc_core, my_sprintf_test_22);
  tcase_add_test(tc_core, my_sprintf_test_23);
  tcase_add_test(tc_core, my_sprintf_test_24);
  tcase_add_test(tc_core, my_sprintf_test_25);
  tcase_add_test(tc_core, my_sprintf_test_26);
  tcase_add_test(tc_core, my_sprintf_test_27);
  tcase_add_test(tc_core, my_sprintf_test_28);
  tcase_add_test(tc_core, my_sprintf_test_29);
  tcase_add_test(tc_core, my_sprintf_test_30);
  tcase_add_test(tc_core, my_sprintf_test_31);
  tcase_add_test(tc_core, my_sprintf_test_32);
  tcase_add_test(tc_core, my_sprintf_test_33);
  tcase_add_test(tc_core, my_sprintf_test_34);
  tcase_add_test(tc_core, my_sprintf_test_35);
  tcase_add_test(tc_core, my_sprintf_test_36);
  tcase_add_test(tc_core, my_sprintf_test_37);
  tcase_add_test(tc_core, my_sprintf_test_38);
  tcase_add_test(tc_core, my_sprintf_test_39);
  tcase_add_test(tc_core, my_sprintf_test_40);
  tcase_add_test(tc_core, my_sprintf_test_41);
  tcase_add_test(tc_core, my_sprintf_test_42);
  tcase_add_test(tc_core, my_sprintf_test_43);
  tcase_add_test(tc_core, my_sprintf_test_44);
  tcase_add_test(tc_core, my_sprintf_test_45);
  tcase_add_test(tc_core, my_sprintf_test_46);
  tcase_add_test(tc_core, my_sprintf_test_47);
  tcase_add_test(tc_core, my_sprintf_test_48);
  tcase_add_test(tc_core, my_sprintf_test_49);
  tcase_add_test(tc_core, my_sprintf_test_50);
  tcase_add_test(tc_core, my_sprintf_test_51);
  tcase_add_test(tc_core, my_sprintf_test_52);
  tcase_add_test(tc_core, my_sprintf_test_53);
  tcase_add_test(tc_core, my_sprintf_test_54);
  tcase_add_test(tc_core, my_sprintf_test_55);
  tcase_add_test(tc_core, my_sprintf_test_56);
  tcase_add_test(tc_core, my_sprintf_test_57);
  tcase_add_test(tc_core, my_sprintf_test_58);
  tcase_add_test(tc_core, my_sprintf_test_59);
  tcase_add_test(tc_core, my_sprintf_test_ptr_1);
  tcase_add_test(tc_core, my_sprintf_test_hex);
  tcase_add_test(tc_core, my_sprintf_i_001);
  tcase_add_test(tc_core, my_sprintf_u_001);
  tcase_add_test(tc_core, my_sprintf_o_001);
  tcase_add_test(tc_core, my_sprintf_x_001);
  tcase_add_test(tc_core, my_sprintf_X_001);
  tcase_add_test(tc_core, my_sprintf_c_001);
  tcase_add_test(tc_core, my_sprintf_g_001);
  tcase_add_test(tc_core, my_sprintf_G_001);
  tcase_add_test(tc_core, my_sprintf_s_001);
  tcase_add_test(tc_core, my_sprintf_f_001);
  tcase_add_test(tc_core, my_sprintf_F_001);
  tcase_add_test(tc_core, my_sprintf_n_001);
  tcase_add_test(tc_core, my_sprintf_p_001);
  tcase_add_test(tc_core, my_sprintf_e_001);
  tcase_add_test(tc_core, my_sprintf_E_001);
  tcase_add_test(tc_core, my_sscanf_c_test2);
  tcase_add_test(tc_core, my_sscanf_c_test3);
  tcase_add_test(tc_core, my_sscanf_c_test4);
  tcase_add_test(tc_core, my_sscanf_c_test5);
  tcase_add_test(tc_core, my_sscanf_c_test6);
  tcase_add_test(tc_core, my_sscanf_c_test7);
  tcase_add_test(tc_core, my_sscanf_d_test0);
  tcase_add_test(tc_core, my_sscanf_d_test_oi_1);
  tcase_add_test(tc_core, my_sscanf_d_test1);
  tcase_add_test(tc_core, my_sscanf_d_test2);
  tcase_add_test(tc_core, my_sscanf_d_test3);
  tcase_add_test(tc_core, my_sscanf_d_test4);
  tcase_add_test(tc_core, my_sscanf_d_test6);
  tcase_add_test(tc_core, my_sscanf_d_test8);
  tcase_add_test(tc_core, my_sscanf_d_test9);
  tcase_add_test(tc_core, my_sscanf_i_test0);
  tcase_add_test(tc_core, my_sscanf_i_test1);
  tcase_add_test(tc_core, my_sscanf_i_test2);
  tcase_add_test(tc_core, my_sscanf_i_test3);
  tcase_add_test(tc_core, my_sscanf_i_test4);
  tcase_add_test(tc_core, my_sscanf_i_test5);
  tcase_add_test(tc_core, my_sscanf_i_test6);
  tcase_add_test(tc_core, my_sscanf_i_test8);
  tcase_add_test(tc_core, my_sscanf_i_test88);
  tcase_add_test(tc_core, my_sscanf_i_test9);
  tcase_add_test(tc_core, my_sscanf_i_test11);
  tcase_add_test(tc_core, my_sscanf_i_test12);
  tcase_add_test(tc_core, my_sscanf_i_test13);
  tcase_add_test(tc_core, my_sscanf_e_test0);
  tcase_add_test(tc_core, my_sscanf_e_test1);
  tcase_add_test(tc_core, my_sscanf_e_test2);
  tcase_add_test(tc_core, my_sscanf_e_test3);
  tcase_add_test(tc_core, my_sscanf_e_test4);
  tcase_add_test(tc_core, my_sscanf_e_test6);
  tcase_add_test(tc_core, my_sscanf_e_test7);
  tcase_add_test(tc_core, my_sscanf_e_test8);
  tcase_add_test(tc_core, my_sscanf_e_test9);
  tcase_add_test(tc_core, my_sscanf_E_test0);
  tcase_add_test(tc_core, my_sscanf_E_test1);
  tcase_add_test(tc_core, my_sscanf_E_test2);
  tcase_add_test(tc_core, my_sscanf_E_test3);
  tcase_add_test(tc_core, my_sscanf_E_test4);
  tcase_add_test(tc_core, my_sscanf_E_test5);
  tcase_add_test(tc_core, my_sscanf_E_test6);
  tcase_add_test(tc_core, my_sscanf_E_test7);
  tcase_add_test(tc_core, my_sscanf_E_test8);
  tcase_add_test(tc_core, my_sscanf_E_test9);
  tcase_add_test(tc_core, my_sscanf_f_test0);
  tcase_add_test(tc_core, my_sscanf_f_test1);
  tcase_add_test(tc_core, my_sscanf_f_test2);
  tcase_add_test(tc_core, my_sscanf_f_test3);
  tcase_add_test(tc_core, my_sscanf_f_test4);
  tcase_add_test(tc_core, my_sscanf_f_test5);
  tcase_add_test(tc_core, my_sscanf_f_test6);
  tcase_add_test(tc_core, my_sscanf_f_test9);
  tcase_add_test(tc_core, my_sscanf_f_test10);
  tcase_add_test(tc_core, my_sscanf_f_test11);
  tcase_add_test(tc_core, my_sscanf_f_test13);
  tcase_add_test(tc_core, my_sscanf_f_test14);
  tcase_add_test(tc_core, my_sscanf_f_test15);
  tcase_add_test(tc_core, my_sscanf_f_test16);
  tcase_add_test(tc_core, my_sscanf_f_test17);
  tcase_add_test(tc_core, my_sscanf_f_test18);
  tcase_add_test(tc_core, my_sscanf_f_test19);
  tcase_add_test(tc_core, my_sscanf_f_test20);
  tcase_add_test(tc_core, my_sscanf_f_test21);
  tcase_add_test(tc_core, my_sscanf_f_test22);
  tcase_add_test(tc_core, my_sscanf_f_test23);
  tcase_add_test(tc_core, my_sscanf_f_test24);
  tcase_add_test(tc_core, my_sscanf_f_test25);
  tcase_add_test(tc_core, my_sscanf_f_test26);
  tcase_add_test(tc_core, my_sscanf_g_test0);
  tcase_add_test(tc_core, my_sscanf_g_test1);
  tcase_add_test(tc_core, my_sscanf_g_test2);
  tcase_add_test(tc_core, my_sscanf_g_test3);
  tcase_add_test(tc_core, my_sscanf_g_test4);
  tcase_add_test(tc_core, my_sscanf_g_test5);
  tcase_add_test(tc_core, my_sscanf_g_test6);
  tcase_add_test(tc_core, my_sscanf_g_test7);
  tcase_add_test(tc_core, my_sscanf_g_test8);
  tcase_add_test(tc_core, my_sscanf_g_test9);
  tcase_add_test(tc_core, my_sscanf_g_test10);
  tcase_add_test(tc_core, my_sscanf_g_test11);
  tcase_add_test(tc_core, my_sscanf_G_test0);
  tcase_add_test(tc_core, my_sscanf_G_test2);
  tcase_add_test(tc_core, my_sscanf_G_test3);
  tcase_add_test(tc_core, my_sscanf_G_test4);
  tcase_add_test(tc_core, my_sscanf_G_test5);
  tcase_add_test(tc_core, my_sscanf_G_test7);
  tcase_add_test(tc_core, my_sscanf_G_test8);
  tcase_add_test(tc_core, my_sscanf_G_test9);
  tcase_add_test(tc_core, my_sscanf_G_test11);
  tcase_add_test(tc_core, my_sscanf_o_test0);
  tcase_add_test(tc_core, my_sscanf_o_test1);
  tcase_add_test(tc_core, my_sscanf_o_test2);
  tcase_add_test(tc_core, my_sscanf_o_test3);
  tcase_add_test(tc_core, my_sscanf_o_test4);
  tcase_add_test(tc_core, my_sscanf_s_test1);
  tcase_add_test(tc_core, my_sscanf_u_test0);
  tcase_add_test(tc_core, my_sscanf_u_test1);
  tcase_add_test(tc_core, my_sscanf_u_test3);
  tcase_add_test(tc_core, my_sscanf_u_test4);
  tcase_add_test(tc_core, my_sscanf_u_test5);
  tcase_add_test(tc_core, my_sscanf_u_test6);
  tcase_add_test(tc_core, my_sscanf_u_test7);
  tcase_add_test(tc_core, my_sscanf_u_test8);
  tcase_add_test(tc_core, my_sscanf_u_test9);
  tcase_add_test(tc_core, my_sscanf_u_test10);
  tcase_add_test(tc_core, my_sscanf_u_test11);
  tcase_add_test(tc_core, my_sscanf_u_test12);
  tcase_add_test(tc_core, my_sscanf_u_test13);
  tcase_add_test(tc_core, my_sscanf_u_test14);
  tcase_add_test(tc_core, my_sscanf_X_test1);
  tcase_add_test(tc_core, my_sscanf_X_test2);
  tcase_add_test(tc_core, my_sscanf_X_test3);
  tcase_add_test(tc_core, my_sscanf_X_test4);
  tcase_add_test(tc_core, my_sscanf_X_test5);
  tcase_add_test(tc_core, my_sscanf_X_test6);
  tcase_add_test(tc_core, my_sscanf_X_test7);
  tcase_add_test(tc_core, my_sscanf_X_test8);
  tcase_add_test(tc_core, my_sscanf_X_test9);
  tcase_add_test(tc_core, my_sscanf_X_test10);
  tcase_add_test(tc_core, my_sscanf_X_test11);
  tcase_add_test(tc_core, my_sscanf_X_test14);
  tcase_add_test(tc_core, my_sscanf_X_test15);
  tcase_add_test(tc_core, my_sscanf_X_test16);
  tcase_add_test(tc_core, my_sscanf_X_test17);
  tcase_add_test(tc_core, my_sscanf_X_test18);
  tcase_add_test(tc_core, my_sscanf_X_test19);
  tcase_add_test(tc_core, my_sscanf_X_test20);
  tcase_add_test(tc_core, my_sscanf_x_test0);
  tcase_add_test(tc_core, my_sscanf_x_test1);
  tcase_add_test(tc_core, my_sscanf_x_test2);
  tcase_add_test(tc_core, my_sscanf_x_test3);
  tcase_add_test(tc_core, my_sscanf_x_test4);
  tcase_add_test(tc_core, my_sscanf_x_test5);
  tcase_add_test(tc_core, my_sscanf_x_test6);
  tcase_add_test(tc_core, my_sscanf_x_test7);
  tcase_add_test(tc_core, my_sscanf_x_test8);
  tcase_add_test(tc_core, my_sscanf_x_test9);
  tcase_add_test(tc_core, my_sscanf_x_test10);
  tcase_add_test(tc_core, my_sscanf_x_test11);
  tcase_add_test(tc_core, my_sscanf_x_test14);
  tcase_add_test(tc_core, my_sscanf_x_test15);
  tcase_add_test(tc_core, my_sscanf_x_test16);
  tcase_add_test(tc_core, my_sscanf_x_test17);
  tcase_add_test(tc_core, my_sscanf_x_test18);
  tcase_add_test(tc_core, my_sscanf_x_test19);
  suite_add_tcase(my, tc_core);
  return my;
}

int main(void) {
  int number_failed = 0;
  Suite *my = NULL;
  SRunner *sr = NULL;

  my = funcs_suite();
  sr = srunner_create(my);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

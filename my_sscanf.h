#ifndef MY_SSCANF_H_
#define MY_SSCANF_H_

#include "my_string.h"

void exp_num(char *mass, const char *format, ...);

int exp_num_error(const char *mass, const char **c);

char *str_to_mass(const char **str, char *mass, int *n, const char *format,
                  size_t i, int *error_code, int width);

long double my_atof(const char *str);

int oct_pars(char **mass, const char **str, int *n, const char *format,
             size_t i, int *error_code, int width);

long oct_to_dec(char *mass);

int hex_pars(char **mass, const char **str, int *n, const char *format,
             size_t i, int *error_code, int width);

long hex_to_dec(char *mass);

int my_sscanf(const char *str, const char *format, ...);

#endif  //  MY_SSCANF_H_

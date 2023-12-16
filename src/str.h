// Copyright (C) 2023 Arcane Lactiflora <arcanelactiflora@outlook.com>
// Licensed under GPLv3. See LICENSE for details.

#ifndef DYMC_STR_H_
#define DYMC_STR_H_

#include <stdio.h>
#include <stddef.h>

char *str_strip(char *str);
char **str_split(char *str, char delim);
void destroy_str_list(char **list);


// string stream
void* new_ss();
void ss_add(void *self, char *format, ...);
void ss_addc(void *self, char c);
char *ss_str(void *self);
size_t ss_size(void* self);

char *fgetline(FILE *fp);
int fpeek(FILE *fp);

#endif

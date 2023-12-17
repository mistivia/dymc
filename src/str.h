// Copyright (C) 2023 Arcane Lactiflora <arcanelactiflora@outlook.com>
// Licensed under GPLv3. See LICENSE for details.

#ifndef DYMC_STR_H_
#define DYMC_STR_H_

#include <stdio.h>
#include <stddef.h>

char *str_strip(const char *str);
char **str_split(const char *str, char delim);


// string stream
void* new_ss();
void ss_add(void *self, char *format, ...);
void ss_addc(void *self, char c);
char *ss_cstr(void *self);
size_t ss_size(void* self);

char *fgetline(FILE *fp);
int fpeek(FILE *fp);

#endif

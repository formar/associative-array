/*
  associative_array.h
  (C) 2012 jtRIPper
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 1, or (at your option)
  any later version.
   
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
   
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef _ASSOCIATIVE_ARRAY
#define _ASSOCIATIVE_ARRAY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *key;
  void *value;
} hash_element;

typedef struct {
  hash_element **hashes;
  int num;
} hash;

void create_element(hash *array);
int assign_element(hash *array, char *key, void *value, int size);
int search_elements(hash *array, char *key);
void *access_element(hash *array, char *key);
void delete_element(hash *array, char *key);
void destroy(hash *array);

/*! \brief Function for loading valid data into hash list
 *
 *  This function take a valid char stream which contains properly
 *  formatted data and loads it into a hash array. The format is as
 *  follows: $key'\0'$(int16_t)data
 *  please mind that $ simply indicates the value at key and data, not
 *  to be included in the data stream
 * 
 *  \param data the valid char stream to be tranformed
 *  \param length the length of the char stream
 *  \param array  the hash to be loaded

*/
void construct_from_serial(char *data,int length,hash *array);
hash init();

#endif

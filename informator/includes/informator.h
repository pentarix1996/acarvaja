#ifndef INFORMATOR_H
# define INFORMATOR_H
# include "../sources/get_next_line/get_next_line.h"
# include <string.h>

typedef struct  s_inform
{
  char  *line;
  char  *answer;
  char  first;
  char  second;
  int   step;
  int   state;
}               t_inform;


#endif
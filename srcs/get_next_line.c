/*
** get_next_line.c for get_next_line in /home/valeru_r/rendu/Prog_Elem/GetNextLine/CPE_2015_getnextline
** 
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
** 
** Started on  Mon Jan 18 20:22:26 2016 Reever Valerus
** Last update Wed Jun  1 21:21:07 2016 Reever Valerus
*/

#include "allum.h"

char            *my_strcpy(char *buff, int s, t_read get, int i)
{
  get.u = 0;
  get.i = 0;
  get.t = 0;

  if ((get.str = malloc(sizeof(char) * (my_strlen(buff) +
                                        1))) == NULL)
    return (NULL);
  if (s == 1)
    while (buff[get.i] != '\n' && buff[get.i] != '\0')
      get.str[get.u++] = buff[get.i++];
  else if (s == 2)
    {
      while (get.t < i && buff[get.i] != '\0')
        {
          if (buff[get.i] == '\n')
            get.t++;
          get.i++;
        }
      while (buff[get.i] != '\0' && buff[get.i] != '\n')
        get.str[get.u++] = buff[get.i++];
    }
  get.str[get.u] = '\0';
  return (get.str);
}

int             verif_line(char *str, int size, int i)
{
  int           z;
  int           y;

  z = 0;
  y = 0;
  while (z < size)
    {
      if (str[z] == '\n')
        {
          y++;
          if (y == i)
            return (z);
        }
      z++;
    }
  return (-1);
}

char            *my_realloc(char *buff, char *result, t_read get)
{
  char          *tmp;

  get.i = 0;
  get.u = 0;
  if ((tmp = malloc(sizeof(char) * (my_strlen(buff) +
                                    my_strlen(result) + 1))) == NULL)
    return (NULL);
  while (result[get.i] != '\0')
    {
      tmp[get.i] = result[get.i];
      get.i++;
    }
  while (buff[get.u] != '\n' && buff[get.u] != '\0')
    {
      tmp[get.i] = buff[get.u];
      get.i++;
      get.u++;
    }
  tmp[get.i] = '\0';
  free(result);
  return (tmp);
}

void	init_variable(t_read *get)
{
  get->i = 1;
  get->g = 1;
  get->t = -1;
}

char            *get_next_line(const int fd)
{
  static char   buffer[READ_SIZE + 1] = "";
  t_read        get;

  init_variable(&get);
  while (get.t == -1)
    {
      if (((get.r = read(fd, buffer, READ_SIZE)) <= 0))
	  return (NULL);
      else if ((get.r <= 0) && (get.g == 1))
	  return (get.str);
      buffer[get.r] = '\0';
      get.i = 1;
      get.t = verif_line(buffer, (my_strlen(buffer)), get.i);
      if (get.g == 1)
        get.str = my_strcpy(buffer, 1, get, 0);
      else
        get.str = my_realloc(buffer, get.str, get);
      get.g++;
    }
  return (get.str);
}

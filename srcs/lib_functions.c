/*
** fonctions_lib.c for fonctions_lib in /home/valeru_r/rendu/Prog_Elem/Allum-1/CPE_2015_Allum1
** 
** Made by valeru_r
** Login   <valeru_r@MrWest>
** 
** Started on  Tue Feb  9 16:45:15 2016 valeru_r
** Last update Wed Jun  1 21:22:03 2016 Reever Valerus
*/

#include "allum.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
  return (0);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

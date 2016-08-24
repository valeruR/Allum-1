/*
** fonctions_lib2.c for fonctions_lib2 in /home/valeru_r/rendu/Prog_Elem/Allum-1/CPE_2015_Allum1
** 
** Made by valeru_r
** Login   <valeru_r@MrWest>
** 
** Started on  Sat Feb 13 12:37:39 2016 valeru_r
** Last update Wed Jun  1 21:21:54 2016 Reever Valerus
*/

#include <unistd.h>
#include <stdio.h>
#include "allum.h"

void    initvar(int *i, int *l, int *entier, int *c)
{
  *i = 0;
  *c = 0;
  *l = 1;
  *entier = 0;
}

int    incrementation(char *str, int i, int *entier, int l)
{
  int	en;

  while (((str[i]) >= 46) && ((str[i]) <= 57))
    {
      if (str[i] < 48)
	return (-21);
      en = *entier;
      *entier = (en * l) + (str[i] - 48);
      l = 10;
      i = i + 1;
    }
    return (i);
}

int     my_getnbr(char *str)
{
  t_get da;
  int	t;

  if (str[0] == '-' && (my_strlen(str)) > 2)
    return (-33);
  else if ((my_strlen(str)) > 4)
    return (33);
  initvar(&da.i, &da.l, &da.entier, &da.c);
  while (((str[da.i]) == 45) || ((str[da.i]) == 43))
    {
      if ((str[da.i]) == 45)
	da.c++;
      da.i++;
    }
  if (((str[da.i]) >= 48) && ((str[da.i]) <= 57))
    {
      t = incrementation(str, da.i, &da.entier, da.l);
      if (t != (my_strlen(str)))
	return (0);
      if ((da.c % 2) != 0)
        return (da.entier * (-1));
      return (da.entier);
    }
  return (-21);
}

void	maxnegatif(int nb)
{
  if (nb == -2147483648)
    write(1, "-2147483648", 10);
}

int     my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
      if (nb >= 0 && nb < 10)
        my_putchar(nb + 48);
      else if (nb >= 10)
        {
          my_put_nbr(nb / 10);
          my_put_nbr(nb % 10);
        }
      maxnegatif(nb);
    }
  else if (nb >= 0 && nb < 10)
    my_putchar(nb + 48);
  else
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  return (0);
}

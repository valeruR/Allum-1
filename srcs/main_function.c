/*
** main_function.c for main_function in /home/valeru_r/rendu/Prog_Elem/Allum-1/CPE_2015_Allum1
** 
** Made by valeru_r
** Login   <valeru_r@MrWest>
** 
** Started on  Fri Feb 12 04:50:05 2016 valeru_r
** Last update Wed Jun  1 21:29:18 2016 Reever Valerus
*/

#include <stdlib.h>
#include <stdio.h>
#include "allum.h"

int		verif_error_line(int *tab, int t)
{
  if (t < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  else
    {
      if (t > 0 && t <= 4)
	{
	  if (tab[t - 1] == 0)
	    {
	      my_putstr("Error: this line is empty\n");
	      return (-1);
	    }
	}
      else
	{
	  my_putstr("Error: this line is out of range\n");
	  return (-1);
	}
    }
  return (0);
}

int		main_function(int *tab, char *s)
{
  int		t;

  t = my_getnbr(s);
  if ((verif_error_line(tab, t)) < 0)
    return (-1);
  else
    return (t);
}

int		verif_error_match(int *tab, int t, int l)
{
  if (t < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  else
    {
      if (tab[l - 1] == t)
	return (0);
      else if (t == 0)
        {
          my_putstr("Error: you have to remove at least one match\n");
          return (-1);
        }
      else if (tab[l - 1] < t)
	{
	  my_putstr("Error: not enough matches on this line\n");
	  return (-1);
	}
    }
  return (0);
}

int		main_function2(int *tab, char *s, int line)
{
  int		t;

  t = my_getnbr(s);
  if ((verif_error_match(tab, t, line)) < 0)
    return (-1);
  else
    {
      tab[line - 1] = tab[line - 1] - t;
      return (t);
    }
}

void		player_moves(int u, int j)
{
  my_putstr("Player removed ");
  my_put_nbr(j);
  my_putstr(" match(es) from line ");
  my_put_nbr(u);
  my_putchar('\n');
}

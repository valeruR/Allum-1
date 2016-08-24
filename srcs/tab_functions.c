/*
** fonctions_tab.c for fonctions_tab in /home/valeru_r/rendu/Prog_Elem/Allum-1/CPE_2015_Allum1
** 
** Made by valeru_r
** Login   <valeru_r@MrWest>
** 
** Started on  Tue Feb  9 17:02:12 2016 valeru_r
** Last update Wed Jun  1 21:29:48 2016 Reever Valerus
*/

#include "allum.h"

int		*tab_line()
{
  int		*tab;

  if ((tab = malloc(sizeof(int) * 4)) == NULL)
    return (NULL);
  tab[0] = 1;
  tab[1] = 3;
  tab[2] = 5;
  tab[3] = 7;
  print_game(tab);
  return (tab);
}

int		end_tab(int *tab)
{
  int		i;

  i = 0;
  while (i < 4)
    i++;
  return (tab[i - 1]);
}

void		init_var(int *i, int *a, int *c)
{
  *i = 0;
  *c = 7;
  *a = *c - *c / 2 - 1;
  my_putstr("*********\n");
}

void		init_var2(int *i, int *a)
{
  int		i2;
  int		a2;

  i2 = *i;
  a2 = *a;
  *i = i2 + 1;
  *a = a2 - 1;
  my_putstr("*\n");
}

void		print_game(int *tab)
{
  t_game	da;

  init_var(&da.i, &da.a, &da.c);
  while (da.i < 4)
    {
      da.u = 0;
      my_putchar('*');
      while ((da.u++ < da.a) && (da.u < da.c))
	  my_putchar(' ');
      da.v = da.u;
      if (da.u < da.c)
	while (da.u < tab[da.i] + da.v)
	  {
	    my_putchar('|');
	    da.u++;
	  }
      while (da.u < da.c + 1)
	{
	  my_putchar(' ');
	  da.u++;
	}
      init_var2(&da.i, &da.a);
    }
  my_putstr("*********\n");
}

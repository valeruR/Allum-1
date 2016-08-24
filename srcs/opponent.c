/*
** opponent.c for opponent in /home/valeru_r/rendu/Prog_Elem/Allum-1/CPE_2015_Allum1
** 
** Made by valeru_r
** Login   <valeru_r@MrWest>
** 
** Started on  Sun Feb 14 12:49:23 2016 valeru_r
** Last update Wed Jun  1 21:31:42 2016 Reever Valerus
*/

#include "allum.h"

static int	my_return_line(int *tab)
{
  if (tab[3] > 0)
    return (3);
  else if (tab[2] > 0 &&
	   (tab[2] == tab[3] || tab[2] > tab[0]))
    return (2);
  else if (tab[0] > 0)
    return (0);
  else
    return (1);
}

static int	return_match(int *tab, int line, int s)
{
  int		i;

  i = rand()%(s-1) + 1;
  if (tab[line] < i)
    return (-1);
  else
    return (i);
}

static void	init_var(int *d, int *s, int *u)
{
  *d = 4;
  *s = 7;
  *u = -1;
}

int		opponent(int *tab)
{
  int		line;
  int		u;
  int		s;
  int		d;

  init_var(&d, &s, &u);
  while (u < 0)
    {
      line = my_return_line(tab);
      u = return_match(tab, line, s);
      s--;
      d--;
      if (d == 1)
	s = 1;
      if (s == 1)
	u = 1;
    }
  tab[line] = tab[line] - u;
  my_putstr("AI removed ");
  my_put_nbr(u);
  my_putstr(" match(es) from line ");
  my_put_nbr(line + 1);
  my_putchar('\n');
  return (u);
}

void		print_opponent(int *tab)
{
  my_putstr("\nAI's turn...\n");
  opponent(tab);
  print_game(tab);
}

/*
** main.c for main in /home/valeru_r/rendu/Prog_Elem/Allum-1/CPE_2015_Allum1
** 
** Made by valeru_r
** Login   <valeru_r@MrWest>
** 
** Started on  Tue Feb  9 16:53:17 2016 valeru_r
** Last update Wed Jun  1 22:36:43 2016 Reever Valerus
*/

#include "allum.h"

int		verif_tab(int *tab, int u, int j)
{
  int		i;
  int		r;

  i = 0;
  r = 0;
  while (i < 4)
    {
      if (tab[i] == 0)
	r++;
      i++;
    }
  if (r == 4)
    {
      if (u == 1)
	{
	  player_moves(u, j);
	  print_game(tab);
	  my_putstr("You lost, too bad..\n");
	}
      else
        my_putstr("I lost.. snif.. but I’ll get you next time!!\n");
      return (-1);
    }
  return (0);
}

void		re_init(int *u, int *j)
{
  *u = -1;
  *j = -1;
}

int		main_to_main(t_main *data)
{
  player_moves(data->u, data->j);
  re_init(&data->u, &data->j);
  print_game(data->tab);
  if ((verif_tab(data->tab, 2, data->j)) < 0)
    return (-1);
  print_opponent(data->tab);
  if ((verif_tab(data->tab, 2, data->j)) < 0)
    return (-1);
  return (0);
}

int		make_player(t_main *data)
{
  my_putstr("Line: ");
  if ((data->s = get_next_line(0)) == NULL)
    return (-1);
  if ((data->u = main_function(data->tab, data->s)) > 0)
    {
      my_putstr("Matches: ");
      if ((data->t = get_next_line(0)) == NULL)
	return (-1);
      data->j = main_function2(data->tab, data->t, data->u);
    }
  return (0);
}

int		main()
{
  t_main	data;

  my_putchar('\n');
  re_init(&data.u, &data.j);
  data.tab = tab_line();
  while (42)
    {
      my_putstr("\nYour turn:\n");
      while (data.u < 0)
        {
	  if ((make_player(&data)) < 0)
	    return (-1);
	  if (data.j < 0)
	    data.u = -1;
	  if (data.u > 0)
	    if ((verif_tab(data.tab, 1, data.j)) == -1)
		return (0);
        }
      if ((main_to_main(&data)) < 0)
	  return (0);
    }
  return (0);
}

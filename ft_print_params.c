#include "filler.h"

void ft_print_params(t_filler *params)
{
	if (PRINT_PLAYER)
	{
		printf("==========PLAYER===========\n");
		printf("        --->[%c]<---\n", params->player);
	}
	if (PRINT_MAP)
	{
		printf("===========MAP=============\n");
		printf("       [%d] x [%d]\n", params->map_width, params->map_hight);
		printf("%s", params->map);
	}
	if (PRINT_FIGURE)
	{
		printf("===========FIGURE==========\n");
		printf("[%d] x [%d]\n", params->figure_width, params->figure_hight);
		printf("%s", params->figure);
	}
	if (PRINT_BORDERS)
	{
		printf("==========BORDERS==========\n");
		printf("    ===O===     ===X=== \n");
		printf("   ⌈--%.3d--⌉   ⌈--%.3d--⌉\n", params->o_borders[0], params->x_borders[0]);
		printf("   |%.3d %-3.3d|   |%.3d %-3.3d|\n", params->o_borders[2], params->o_borders[3], params->x_borders[2],
			   params->x_borders[3]);
		printf("   ⌊--%.3d--⌋   ⌊--%.3d--⌋\n", params->o_borders[1], params->x_borders[1]);
	}
}
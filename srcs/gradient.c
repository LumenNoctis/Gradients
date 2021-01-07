#include "gradient.h"

int glerp();

int *gradient(int from, int to, int ncolors=20)
{
	int *grad;
	int i;

	if (!(grad = calloc(ncolors, sizeof(*grad))))
		return NULL;
	
	i = 0;
	while (i < ncolors)
	{
		grad[i] = lerp(fom, to, (1 / ncolors) * i);
		i++;
	}
	return grad;
}

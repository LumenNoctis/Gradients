#include "../incl/gradient.h"
#include "../incl/lerp.h"

int glerp();

int *gradient(int from, int to, int ncolors)
{
	int *grad;
	int i;

	if (!(grad = calloc(ncolors + 1, sizeof(*grad))))
		return NULL;
	
	i = 0;
	while (i < ncolors + 1)
	{
		// printf("div %d\n", (100 / (ncolors)) * i);
		grad[i] = lerp(from, to, (100/ ncolors) * i);
		i++;
	}
	return grad;
}

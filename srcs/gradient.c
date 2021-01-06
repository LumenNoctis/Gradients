#include "gradient.h"

int glerp();

int *gradient(int from, int to, int ncolors)
{
	int *grad;

	if (!(grad = calloc(ncolors, sizeof(*grad))))
		return NULL;
	
}

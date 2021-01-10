#include "../incl/gradient.h"
#include "../incl/lerp.h"

t_gradient create_gradient()
	int i;
	t_gradient grad;
	
	grad.grad_lerp = calloc(1, sizeof(*grad.grad_lerp));

	grad.grad_lerp[0].start = 0x000000FF;
	grad.grad_lerp[0].end = 0x000000FF;
	grad.grad_lerp[0].span_start = 0;
	grad.grad_lerp[0].span_end = 1;

	return grad;
}

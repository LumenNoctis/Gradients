#ifndef G_STRUCTS_H
# define G_STRUCTS_H

# include 	<stdint.h>
// # include	<stdio.h>


typedef union	RGBA
{
	uint32_t		color;
	struct {
		uint8_t 	r;
		uint8_t 	g;
		uint8_t 	b;
		uint8_t 	a;
	}				color_data;
}					RGBA;


#endif

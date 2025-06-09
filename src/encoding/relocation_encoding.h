#ifndef __RELOCATION_ENCODING_H__
#define __RELOCATION_ENCODING_H__

typedef enum {
	RT_REL64,
	RT_REL32,
	RT_REL16,
	RT_REL8,
	RT_ABS64,
	RT_ABS32,
	RT_ABS16,
	RT_ABS8,
	RT_JMP
} RelType;



#endif 
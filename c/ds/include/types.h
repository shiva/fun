/*
 * types.h
 *
 *  Created on: Nov 11, 2015
 *      Author: shiva
 */

#ifndef C_DS_INCLUDE_TYPES_H_
#define C_DS_INCLUDE_TYPES_H_

/* bool */
#ifndef __bool_true_false_are_defined
    #ifdef _Bool
        #define bool                        _Bool
    #else
        #define bool                        int
    #endif
    #define true                            1
    #define false                           0
    #define __bool_true_false_are_defined   1
#endif

/* NULL */
#ifndef NULL
	#define NULL (void *)0
#endif

#endif /* C_DS_INCLUDE_TYPES_H_ */

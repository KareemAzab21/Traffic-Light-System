/*
 * std_types.h
 *
 * Created: 9/16/2022 1:52:28 PM
 *  Author: Kareem Azab
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef enum
{
	OK=10,NOT_OK
}Status;


/* Boolean Data Type */
typedef unsigned char boolean;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

#define NULL_PTR    ((void*)0)

typedef unsigned char         uint8_t;          
typedef signed char           sint8_t;          
        
typedef signed short          sint16_t;         
typedef unsigned long         uint32_t;         
typedef signed long           sint32_t;         
typedef unsigned long long    uint64_t;         
typedef signed long long      sint64_t;         
typedef float                 float32_t;
typedef double                float64_t;


#endif /* STD_TYPES_H_ */
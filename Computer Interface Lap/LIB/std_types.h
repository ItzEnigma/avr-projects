#ifndef std_types_h
#define std_types_h
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;

typedef void (*FUNC_PTR_IV_OV)(void);
typedef void (*FUNC_PTR_Iu16_OV)(u16);
typedef void (*FUNC_PTR_Iu8_OV)(u8);
typedef void (*FUNC_PTR_Iu16_OV_D)(u16, u16);
#define ADR_NULL ((void *)0)
// cool IO
#define print printf
#define input scanf
#endif

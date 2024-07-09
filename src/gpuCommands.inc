/***********************************************
	Author: Nitin Shukla
	Goal: Macros for OpenACC/OpenMP target
*************************************************/

#ifndef GPU_COMMANDS_INC
#define GPU_COMMANDS_INC
#define STR(X) #X

#ifdef _OPENACC
#include <openacc.h>

#define GPU_PARALLEL_ACC \
	_Pragma( STR(acc parallel loop collapse(2)))

#define GPU_REDUCTION_ACC(x) \
	_Pragma( STR(acc parallel loop collapse(2) reduction(max:x) ))

#define GPU_OFFLOAD(x) \
	_Pragma( STR( acc enter data copyin(x) ))


#define GPU_OFFLOAD_END(x) \
	_Pragma( STR(acc exit data delete(x) ) )

#endif

#ifdef _OPENMP
#include <omp.h>

#define GPU_PARALLEL_MP \
	_Pragma( STR(omp target teams distribute parallel for simd collapse(2) ))

#define GPU_REDUCTION_MP(x) \
	_Pragma( STR(omp target teams distribute parallel for simd collapse(2) reduction(max:x) schedule(static,1)))

#define GPU_OFFLOAD(x) \
	_Pragma( STR( omp target enter data map(to: x)) ) 
	
#define GPU_OFFLOAD_END(x) \
	_Pragma( STR(omp target exit data map(from: x))) 

#endif


#endif // GPU_COMMANDS_INC

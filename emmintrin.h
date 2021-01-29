#ifndef SSE2RVV_H
#define SSE2RVV_H
#endif

#include <riscv_vector.h>

#define INIT_SSE_VL vsetvl_e32m1(4);

typedef vfloat32m1_t __m128;
typedef vint32m1_t __m128i;

// Copy the lower single-precision (32-bit) floating-point element of a to dst.
// TESTED
float _mm_cvtss_f32(__m128 a){
	return (float)vfmv_f_s_f32m1_f32(a);	
}

// Return vector of type __m128i with all elements set to zero.
// TESTED
__m128i _mm_setzero_si128(){
	return vmv_v_x_i32m1(0); 
}

// Return vector of type __m128 with all elements set to zero.
// TESTED
__m128 _mm_setzero_ps(void){
	return vfmv_v_f_f32m1(0);	
}

// Broadcast single-precision (32-bit) floating-point value a to all elements of dst.
// TESTED
__m128 _mm_set1_ps(float _w){
	return vfmv_v_f_f32m1(_w);
}

// Broadcast single-precision (32-bit) floating-point value a to all elements of dst.
// TESTED
__m128 _mm_set_ps1(float _w){
	return vfmv_v_f_f32m1(_w); 
}

// Set packed single-precision (32-bit) floating-point elements in dst with the supplied values.
// TESTED
__m128 _mm_set_ps(float w, float z, float y, float x){
	float __attribute__((aligned(16))) data[4] = { x, y, z, w };
	return vle32ff_v_f32m1((float32_t *)data);	
}

// Set packed single-precision (32-bit) floating-point elements in dst with the supplied values in reverse order.
// TESTED
__m128 _mm_setr_ps(float w, float z , float y , float x ){
	float __attribute__((aligned(16))) data[4] = { w, z, y, x };
        return vle32ff_v_f32m1((float32_t *)data);
}

// Set packed 32-bit integers in dst with the supplied values in reverse order.
// TESTED
__m128i _mm_setr_epi32(int i3, int i2, int i1, int i0){
	int __attribute__((aligned(16))) data[4] = { i3, i2, i1, i0 };
        return vle32_v_i32m1((int32_t *)data);
}

// Add packed 32-bit integers in a and b, and store the results in dst.
// TESTED
__m128i _mm_add_epi32(__m128i a, __m128i b){
        return vadd_vv_i32m1(a, b);
}

// Broadcast 8-bit integer a to all elements of dst. This intrinsic may generate vpbroadcastb.
// TESTED
__m128i _mm_set1_epi8(char w){
	// TODO: Find better alternative
	vsetvl_e8m1 (16);
	__m128i tmp = vreinterpret_v_i8m1_i32m1(vmv_v_x_i8m1(w));
	INIT_SSE_VL
	return tmp;
}

// Broadcast 16-bit integer a to all all elements of dst. This intrinsic may generate vpbroadcastw.
// TESTED
__m128i _mm_set1_epi16(short w){
	// TODO: Find better alternative
	vsetvl_e16m1(8);
        __m128i tmp = vreinterpret_v_i16m1_i32m1(vmv_v_x_i16m1(w));
	INIT_SSE_VL
        return tmp;
}

// Broadcast 32-bit integer a to all elements of dst. This intrinsic may generate vpbroadcastd.
// TESTED
__m128i _mm_set1_epi32(int _i){
	return vmv_v_x_i32m1(_i);
}

// Set packed 16-bit integers in dst with the supplied values.
// TESTED
__m128i _mm_set_epi16(short i7, short i6, short i5, short i4, short i3, short i2, short i1, short i0){
	int16_t __attribute__((aligned(16))) data[8] = { i0, i1, i2, i3, i4, i5, i6, i7 };
	vsetvl_e16m1(8);
	__m128i tmp = vreinterpret_v_i16m1_i32m1(vle16_v_i16m1(data));
	INIT_SSE_VL
	return tmp;
}

// Load 128-bits of integer data from memory into dst. mem_addr must be aligned on a 16-byte boundary or a general-protection exception may be generated.
// TESTED
__m128i _mm_load_si128(const __m128i *p){
        return vle32_v_i32m1((int32_t *)p);
}

// Compute the bitwise NOT of 128 bits (representing integer data) in a and then AND with b, and store the result in dst.
// TESTED
__m128i _mm_andnot_si128(__m128i a, __m128i b){
        return vand_vv_i32m1(vnot_v_i32m1(a), b);
}

// Compare packed signed 8-bit integers in a and b for greater-than, and store the results in dst.
// TESTED
__m128i _mm_cmpgt_epi8 (__m128i a, __m128i b){
	vsetvl_e8m1(16);
	vint8m1_t vff = vmv_v_x_i8m1(0xff), v0 = vmv_v_x_i8m1(0);
	
	// vmask[i] = (a[i] > b[i] ) ? 1 : 0
	vbool8_t vmask = vmsgt_vv_i8m1_b8(vreinterpret_v_i32m1_i8m1(a), vreinterpret_v_i32m1_i8m1(b));
	// tmp[i] = vmask[i] ? 0xff : 0
	vint32m1_t tmp = vreinterpret_v_i8m1_i32m1(vadd_vv_i8m1_m(vmask, v0, vff, v0));
	INIT_SSE_VL
	return tmp;
}

// Compute the bitwise AND of 128 bits (representing integer data) in a and b, and store the result in dst.
// TESTED
__m128i _mm_and_si128(__m128i a, __m128i b){
	 return vand_vv_i32m1(a, b);
}

// Compute the bitwise OR of 128 bits (representing integer data) in a and b, and store the result in dst.
// TESTED
__m128i _mm_or_si128(__m128i a, __m128i b){
	return vor_vv_i32m1(a, b);
}

// Compare packed 8-bit integers in a and b for equality, and store the results in dst.
// TESTED
__m128i _mm_cmpeq_epi8(__m128i a, __m128i b){
	vsetvl_e8m1(16);
        vint8m1_t vff = vmv_v_x_i8m1(0xff), v0 = vmv_v_x_i8m1(0);

        // vmask[i] = (a[i] = b[i] ) ? 1 : 0
        vbool8_t vmask = vmseq_vv_i8m1_b8(vreinterpret_v_i32m1_i8m1(a), vreinterpret_v_i32m1_i8m1(b));
        // tmp[i] = vmask[i] ? 0xff : 0
        vint32m1_t tmp = vreinterpret_v_i8m1_i32m1(vadd_vv_i8m1_m(vmask, v0, vff, v0));
        INIT_SSE_VL
        return tmp;
}

// Compare packed signed 32-bit integers in a and b for greater-than, and store the results in dst. 
// TESTED 
__m128i _mm_cmpgt_epi32(__m128i a, __m128i b){
        __m128i vff = vmv_v_x_i32m1(0xffffffff), v0 = vmv_v_x_i32m1(0);

        // vmask[i] = (a[i] > b[i] ) ? 1 : 0
        vbool32_t vmask = vmsgt_vv_i32m1_b32(a, b);
        // tmp[i] = vmask[i] ? 0xff : 0
        return vadd_vv_i32m1_m(vmask, v0, vff, v0);
}

// Compare packed signed 8-bit integers in a and b for less-than, and store the results in dst. Note: This intrinsic emits the pcmpgtb instruction with the order of the operands switched.
// TESTED
__m128i _mm_cmplt_epi8 (__m128i a, __m128i b){
	vsetvl_e8m1(16);
        vint8m1_t vff = vmv_v_x_i8m1(0xff), v0 = vmv_v_x_i8m1(0);

        // vmask[i] = (a[i] = b[i] ) ? 1 : 0
        vbool8_t vmask = vmslt_vv_i8m1_b8(vreinterpret_v_i32m1_i8m1(a), vreinterpret_v_i32m1_i8m1(b));
        // tmp[i] = vmask[i] ? 0xff : 0
        vint32m1_t tmp = vreinterpret_v_i8m1_i32m1(vadd_vv_i8m1_m(vmask, v0, vff, v0));
        INIT_SSE_VL
        return tmp;
}

// Copy 32-bit integer a to the lower elements of dst, and zero the upper elements of dst.
// TESTED
__m128i _mm_cvtsi32_si128(int a){
	int arr[4] = {1, 0, 0, 0};
	__m128i v0 = vmv_v_x_i32m1(0);

	// Re-interpret arr (without changing any bits) to vbool32_t
	vbool32_t mask = vmsne_vx_i32m1_b32(vle32_v_i32m1((int32_t *)arr), 0);
	return vadd_vx_i32m1_m(mask, v0, v0, a);
}

// Shift a left by imm8 bytes while shifting in zeros, and store the results in dst.
// TODO
__m128i _mm_slli_si128(__m128i a, int imm){
	int offset = (imm & 0xff);
	if(offset > 15) offset = 16;
	offset = offset << 3;
	
	//return ;
	//return vsll_vx_i32m1(a, (int8_t) (op2 & 0xf) << 3);
	return vmv_v_x_i32m1(0);
}

// Shift a left by imm8 bytes while shifting in zeros, and store the results in dst.
// TODO
__m128i _mm_srli_si128(__m128i a, int imm){
        int offset = (imm & 0xff);
        if(offset > 15) offset = 16;
        offset = offset << 3;

        //return ;
        //return vsll_vx_i32m1(a, (int8_t) (op2 & 0xf) << 3);
        return vmv_v_x_i32m1(0);
}

// Store 128-bits of integer data from a into memory. mem_addr must be aligned on a 16-byte boundary or a general-protection exception may be generated.
// TESTED 
void _mm_store_si128(__m128i *p, __m128i a){
	vse32_v_i32m1((int32_t *)p, a);
}

// Store 128-bits of integer data from a into memory. mem_addr does not need to be aligned on any particular boundary.
// TESTED
void _mm_storeu_si128(__m128i *p, __m128i a){
	vse32_v_i32m1((int32_t *)p, a);
}

// Add packed 8-bit integers in a and b, and store the results in dst.
// TESTED
__m128i _mm_add_epi8(__m128i a, __m128i b)
{
	vsetvl_e8m1(16);
	__m128i tmp = vreinterpret_v_i8m1_i32m1(vadd_vv_i8m1(vreinterpret_v_i32m1_i8m1(a), vreinterpret_v_i32m1_i8m1(b)));
	INIT_SSE_VL
	return tmp;
}

// Subtract packed 8-bit integers in b from packed 8-bit integers in a, and store the results in dst.
// TESTED
__m128i _mm_sub_epi8(__m128i a, __m128i b)
{
	vsetvl_e8m1(16);
        __m128i tmp = vreinterpret_v_i8m1_i32m1(vsub_vv_i8m1(vreinterpret_v_i32m1_i8m1(a), vreinterpret_v_i32m1_i8m1(b)));;
        INIT_SSE_VL
        return tmp;
}

// Load 128-bits of integer data from memory into dst. mem_addr does not need to be aligned on any particular boundary.
// TESTED
__m128i _mm_loadu_si128(const __m128i *a){
        return vle32_v_i32m1((int32_t *)a);
}

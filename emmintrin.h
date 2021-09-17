// Author: Feddrick Aquino
// email: feddrick38@yahoo.com
//
// A header file that convert SSE instruction to its equivalent RISC-V
// Vector

#ifndef SSE2RVV_H
#define SSE2RVV_H

#include <riscv_vector.h>
#include <stdint.h>
#include <string.h>

typedef struct __attribute__((__aligned__(16))) { uint64_t x, y; } __m128i;
typedef struct __attribute__((__aligned__(16)))  { double x, y; } __m128;

//#define m128i_to_vint32m1(a)  (*((vint32m1_t *)(&a)))
static inline vint32m1_t m128i_to_vint32m1(__m128i a){
	return *((vint32m1_t *)(&a));
}

//#define m128_to_vfloat32m1(a) (*((vfloat32m1_t *)(&a)))
static inline vfloat32m1_t m128_to_vfloat32m1(__m128 a){
	return *((vfloat32m1_t *)(&a));
}

//#define vint32m1_to_m128i(a)  (*((__m128i *)(&a)))
static inline __m128i vint32m1_to_m128i(vint32m1_t a){
	return *((__m128i *)(&a));
}

//#define vfloat32m1_to_m128(a)  (*((__m128 *)(&a)))
static inline __m128 vfloat32m1_to_m128(vfloat32m1_t a){
	return *((__m128 *)(&a));
}

// Copy the lower single-precision (32-bit) floating-point element of a to dst.
static inline float _mm_cvtss_f32(__m128 a){
	return (float)vfmv_f_s_f32m1_f32(m128_to_vfloat32m1(a));
}

// Return vector of type __m128i with all elements set to zero.
static inline __m128i _mm_setzero_si128(){
	return vint32m1_to_m128i(vmv_v_x_i32m1(0, 4));
}

// Return vector of type __m128 with all elements set to zero.
static inline __m128 _mm_setzero_ps(void){
	return vfloat32m1_to_m128(vfmv_v_f_f32m1(0, 4));
}

// Broadcast single-precision (32-bit) floating-point value a to all elements of dst.
static inline __m128 _mm_set1_ps(float _w){
	return vfloat32m1_to_m128(vfmv_v_f_f32m1(_w, 4));
}

// Broadcast single-precision (32-bit) floating-point value a to all elements of dst.
static inline __m128 _mm_set_ps1(float _w){
	return vfloat32m1_to_m128(vfmv_v_f_f32m1(_w, 4));
}

// Set packed single-precision (32-bit) floating-point elements in dst with the supplied values.
static inline __m128 _mm_set_ps(float w, float z, float y, float x){
	float __attribute__((aligned(16))) data[4] = { x, y, z, w };
	size_t new_vl;
	return vfloat32m1_to_m128(vle32ff_v_f32m1((float32_t *)data, &new_vl, 4));
}

// Set packed single-precision (32-bit) floating-point elements in dst with the supplied values in reverse order.
static inline __m128 _mm_setr_ps(float w, float z , float y , float x ){
	float __attribute__((aligned(16))) data[4] = { w, z, y, x };
	size_t new_vl;
        return vfloat32m1_to_m128(vle32ff_v_f32m1((float32_t *)data, &new_vl, 4));
}

// Set packed 32-bit integers in dst with the supplied values in reverse order.
static inline __m128i _mm_setr_epi32(int i3, int i2, int i1, int i0){
	int __attribute__((aligned(16))) data[4] = { i3, i2, i1, i0 };
        return vint32m1_to_m128i(vle32_v_i32m1((int32_t *)data, 4));
}

// Add packed 32-bit integers in a and b, and store the results in dst.
static inline __m128i _mm_add_epi32(__m128i a, __m128i b){
        return vint32m1_to_m128i(vadd_vv_i32m1(m128i_to_vint32m1(a), m128i_to_vint32m1(b), 4));
}

// Add packed signed 16-bit integers in a and b using saturation, and store the results in dst.
static inline __m128i _mm_adds_epi16(__m128i a, __m128i b){
	vint32m1_t tmp = vreinterpret_v_i16m1_i32m1(vsadd_vv_i16m1(vreinterpret_v_i32m1_i16m1(m128i_to_vint32m1(a)), vreinterpret_v_i32m1_i16m1(m128i_to_vint32m1(b)), 8));
	return vint32m1_to_m128i(tmp);
}

// Subtract packed unsigned 16-bit integers in b from packed unsigned 16-bit integers in a using saturation, and store the results in dst.
static inline __m128i _mm_subs_epu16(__m128i a, __m128i b){
	vint32m1_t tmp = vreinterpret_v_u16m1_i32m1(vssubu_vv_u16m1(vreinterpret_v_i32m1_u16m1(m128i_to_vint32m1(a)), vreinterpret_v_i32m1_u16m1(m128i_to_vint32m1(b)), 8));
	return vint32m1_to_m128i(tmp);
}

// Broadcast 8-bit integer a to all elements of dst. This intrinsic may generate vpbroadcastb.
static inline __m128i _mm_set1_epi8(char w){
	vint32m1_t tmp = vreinterpret_v_i8m1_i32m1(vmv_v_x_i8m1(w, 16));
	return vint32m1_to_m128i(tmp);
}

// Broadcast 16-bit integer a to all all elements of dst. This intrinsic may generate vpbroadcastw.
static inline __m128i _mm_set1_epi16(short w){
        vint32m1_t tmp = vreinterpret_v_i16m1_i32m1(vmv_v_x_i16m1(w, 8));
        return vint32m1_to_m128i(tmp);
}

// Broadcast 32-bit integer a to all elements of dst. This intrinsic may generate vpbroadcastd.
static inline __m128i _mm_set1_epi32(int _i){
	return vint32m1_to_m128i(vmv_v_x_i32m1(_i, 4));
}

// Set packed 16-bit integers in dst with the supplied values.
static inline __m128i _mm_set_epi16(short i7, short i6, short i5, short i4, short i3, short i2, short i1, short i0){
	int16_t __attribute__((aligned(16))) data[8] = { i0, i1, i2, i3, i4, i5, i6, i7 };
	__m128i tmp = vint32m1_to_m128i(vreinterpret_v_i16m1_i32m1(vle16_v_i16m1(data, 8)));
	return tmp;
}

// Load 128-bits of integer data from memory into dst. mem_addr must be aligned on a 16-byte boundary or a general-protection exception may be generated.
static inline __m128i _mm_load_si128(const __m128i *p){
        return vint32m1_to_m128i(vle32_v_i32m1((int32_t *)p, 4));
}

// Compute the bitwise NOT of 128 bits (representing integer data) in a and then AND with b, and store the result in dst.
static inline __m128i _mm_andnot_si128(__m128i a, __m128i b){
        return vint32m1_to_m128i(vand_vv_i32m1(vnot_v_i32m1(m128i_to_vint32m1(a), 4), m128i_to_vint32m1(b), 4));
}

// Compute the bitwise AND of 128 bits (representing integer data) in a and b, and store the result in dst.
static inline __m128i _mm_and_si128(__m128i a, __m128i b){
	 return vint32m1_to_m128i(vand_vv_i32m1(m128i_to_vint32m1(a), m128i_to_vint32m1(b), 4));
}

// Compute the bitwise OR of 128 bits (representing integer data) in a and b, and store the result in dst.
static inline __m128i _mm_or_si128(__m128i a, __m128i b){
	return vint32m1_to_m128i(vor_vv_i32m1(m128i_to_vint32m1(a), m128i_to_vint32m1(b), 4));
}

// Compare packed 8-bit integers in a and b for equality, and store the results in dst.
static inline __m128i _mm_cmpeq_epi8(__m128i a, __m128i b){
        vint8m1_t vff = vmv_v_x_i8m1(0xff, 16), v0 = vmv_v_x_i8m1(0, 16);

        // vmask[i] = (a[i] = b[i] ) ? 1 : 0
        vbool8_t vmask = vmseq_vv_i8m1_b8(vreinterpret_v_i32m1_i8m1(m128i_to_vint32m1(a)), vreinterpret_v_i32m1_i8m1(m128i_to_vint32m1(b)), 16);
        // tmp[i] = vmask[i] ? 0xff : 0
        vint32m1_t tmp = vreinterpret_v_i8m1_i32m1(vadd_vv_i8m1_m(vmask, v0, vff, v0, 16));
        return vint32m1_to_m128i(tmp);
}

// Compare packed signed 32-bit integers in a and b for greater-than, and store the results in dst.
static inline __m128i _mm_cmpgt_epi32(__m128i a, __m128i b){
        vint32m1_t vff = vmv_v_x_i32m1(0xffffffff, 4), v0 = vmv_v_x_i32m1(0, 4);

        // vmask[i] = (a[i] > b[i] ) ? 1 : 0
        vbool32_t vmask = vmsgt_vv_i32m1_b32(m128i_to_vint32m1(a), m128i_to_vint32m1(b), 4);
        // tmp[i] = vmask[i] ? 0xff : 0
        return vint32m1_to_m128i(vadd_vv_i32m1_m(vmask, v0, vff, v0, 4));
}

// Compare packed signed 16-bit integers in a and b for greater-than, and store the results in dst.
static inline __m128i _mm_cmpgt_epi16(__m128i a, __m128i b){
        vint16m1_t vff = vmv_v_x_i16m1(0xffff, 8), v0 = vmv_v_x_i16m1(0, 8);

        // vmask[i] = (a[i] > b[i] ) ? 1 : 0
        vbool16_t vmask = vmsgt_vv_i16m1_b16(vreinterpret_v_i32m1_i16m1(m128i_to_vint32m1(a)), vreinterpret_v_i32m1_i16m1(m128i_to_vint32m1(b)), 8);
        // tmp[i] = vmask[i] ? 0xffff : 0
        vint32m1_t tmp = vreinterpret_v_i16m1_i32m1(vadd_vv_i16m1_m(vmask, v0, vff, v0, 8));
        return vint32m1_to_m128i(tmp);
}

// Compare packed signed 8-bit integers in a and b for greater-than, and store the results in dst
static inline __m128i _mm_cmpgt_epi8 (__m128i a, __m128i b){
        vint8m1_t vff = vmv_v_x_i8m1(0xff, 16), v0 = vmv_v_x_i8m1(0, 16);

        // vmask[i] = (a[i] > b[i] ) ? 1 : 0
        vbool8_t vmask = vmsgt_vv_i8m1_b8(vreinterpret_v_i32m1_i8m1(m128i_to_vint32m1(a)), vreinterpret_v_i32m1_i8m1(m128i_to_vint32m1(b)), 16);
        // tmp[i] = vmask[i] ? 0xff : 0
        vint32m1_t tmp = vreinterpret_v_i8m1_i32m1(vadd_vv_i8m1_m(vmask, v0, vff, v0, 16));
        return vint32m1_to_m128i(tmp);
}

// Compare packed signed 8-bit integers in a and b for less-than, and store the results in dst. Note: This intrinsic emits the pcmpgtb instruction with the order of the operands switched.
static inline __m128i _mm_cmplt_epi8 (__m128i a, __m128i b){
        vint8m1_t vff = vmv_v_x_i8m1(0xff, 16), v0 = vmv_v_x_i8m1(0, 16);

        // vmask[i] = (a[i] = b[i] ) ? 1 : 0
        vbool8_t vmask = vmslt_vv_i8m1_b8(vreinterpret_v_i32m1_i8m1(m128i_to_vint32m1(a)), vreinterpret_v_i32m1_i8m1(m128i_to_vint32m1(b)), 16);
        // tmp[i] = vmask[i] ? 0xff : 0
        vint32m1_t tmp = vreinterpret_v_i8m1_i32m1(vadd_vv_i8m1_m(vmask, v0, vff, v0, 16));
        return vint32m1_to_m128i(tmp);
}

// Copy 32-bit integer a to the lower elements of dst, and zero the upper elements of dst.
static inline __m128i _mm_cvtsi32_si128(int a){
	int __attribute__((aligned(16))) arr[4] = {1, 0, 0, 0};
	vint32m1_t v0 = vmv_v_x_i32m1(0, 4);

	// Re-interpret arr (without changing any bits) to vbool32_t
	vbool32_t mask = vmsne_vx_i32m1_b32(vle32_v_i32m1((int32_t *)arr, 4), 0, 4);
	return vint32m1_to_m128i(vadd_vx_i32m1_m(mask, v0, v0, a, 4));
}

// Shift a left by imm8 bytes while shifting in zeros, and store the results in dst.
static inline __m128i _mm_slli_si128(__m128i a, int imm){
	int offset = (imm & 0xff);
	if(offset > 15) offset = 16;

	vint32m1_t tmp = vreinterpret_v_i8m1_i32m1(vslideup_vx_i8m1(vmv_v_x_i8m1(0, 16), vreinterpret_v_i32m1_i8m1(m128i_to_vint32m1(a)), offset, 16));
	return vint32m1_to_m128i(tmp);
}

// Shift a left by imm8 bytes while shifting in zeros, and store the results in dst.
static inline __m128i _mm_srli_si128(__m128i a, int imm){
        int offset = (imm & 0xff);
        if(offset > 15) offset = 16;

        vint32m1_t tmp = vreinterpret_v_i8m1_i32m1(vslidedown_vx_i8m1(vmv_v_x_i8m1(0, 16), vreinterpret_v_i32m1_i8m1(m128i_to_vint32m1(a)), offset, 16));
	return vint32m1_to_m128i(tmp);
}

// Store 128-bits of integer data from a into memory. mem_addr must be aligned on a 16-byte boundary or a general-protection exception may be generated.
static inline void _mm_store_si128(__m128i *p, __m128i a){
	vse32_v_i32m1((int32_t *)p, m128i_to_vint32m1(a), 4);
}

// Store 128-bits of integer data from a into memory. mem_addr does not need to be aligned on any particular boundary.
static inline void _mm_storeu_si128(__m128i *p, __m128i a){
	memcpy((void *)p, (void *)&a, 16);
}

// Add packed 8-bit integers in a and b, and store the results in dst.
static inline __m128i _mm_add_epi8(__m128i a, __m128i b)
{
	vint32m1_t tmp = vreinterpret_v_i8m1_i32m1(vadd_vv_i8m1(vreinterpret_v_i32m1_i8m1(m128i_to_vint32m1(a)), vreinterpret_v_i32m1_i8m1(m128i_to_vint32m1(b)), 16));
	return vint32m1_to_m128i(tmp);
}

// Subtract packed 8-bit integers in b from packed 8-bit integers in a, and store the results in dst.
static inline __m128i _mm_sub_epi8(__m128i a, __m128i b)
{
        vint32m1_t tmp = vreinterpret_v_i8m1_i32m1(vsub_vv_i8m1(vreinterpret_v_i32m1_i8m1(m128i_to_vint32m1(a)), vreinterpret_v_i32m1_i8m1(m128i_to_vint32m1(b)), 16));;
        return vint32m1_to_m128i(tmp);
}

// Subtract packed 32-bit integers in b from packed 32-bit integers in a, and store the results in dst.
static inline __m128i _mm_sub_epi32(__m128i a, __m128i b){
	return vint32m1_to_m128i(vsub_vv_i32m1(m128i_to_vint32m1(a), m128i_to_vint32m1(b), 4));
}

// Load 128-bits of integer data from memory into dst. mem_addr does not need to be aligned on any particular boundary.
static inline __m128i _mm_loadu_si128(const __m128i *a){
	__m128i res = _mm_set1_epi32(0);
	memcpy((void *)&res, (void *)a, 16);
	return res;
}

// Extract a 16-bit integer from a, selected with imm8, and store the result in the lower element of dst.
static inline int _mm_extract_epi16(__m128i a, int imm){
	vint16m1_t tmp = vrgather_vx_i16m1(vreinterpret_v_i32m1_i16m1(m128i_to_vint32m1(a)), (imm & 0x7), 8);
	return *((uint32_t *)&tmp) & 0xffff;
}

// Compare packed signed 16-bit integers in a and b, and store packed maximum values in dst.
static inline __m128i _mm_max_epi16(__m128i a, __m128i b){
	vint32m1_t tmp = vreinterpret_v_i16m1_i32m1(vmax_vv_i16m1(vreinterpret_v_i32m1_i16m1(m128i_to_vint32m1(a)), vreinterpret_v_i32m1_i16m1(m128i_to_vint32m1(b)), 8));
	return vint32m1_to_m128i(tmp);
}

// Compare packed unsigned 8-bit integers in a and b, and store packed maximum values in dst.
static inline __m128i _mm_max_epu8(__m128i a, __m128i b){
        vint32m1_t tmp = vreinterpret_v_u8m1_i32m1(vmaxu_vv_u8m1(vreinterpret_v_i32m1_u8m1(m128i_to_vint32m1(a)), vreinterpret_v_i32m1_u8m1(m128i_to_vint32m1(b)), 16));
        return vint32m1_to_m128i(tmp);
}

// Compare packed unsigned 8-bit integers in a and b, and store packed minimum values in dst.
static inline __m128i _mm_min_epu8(__m128i a, __m128i b){
        vint32m1_t tmp = vreinterpret_v_u8m1_i32m1(vminu_vv_u8m1(vreinterpret_v_i32m1_u8m1(m128i_to_vint32m1(a)), vreinterpret_v_i32m1_u8m1(m128i_to_vint32m1(b)), 16));
        return vint32m1_to_m128i(tmp);
}

// Create mask from the most significant bit of each 8-bit element in a, and store the result in dst.
static inline int _mm_movemask_epi8(__m128i _a){
	//vsetvl_e8m8(16);

	// msb_mask[15:0] = 0x80
	vint8m8_t msb_mask = vmv_v_x_i8m8(0x80, 16);

	// bool_res[i] = ((_a[i] & msb_mask[i]) == msb_mask[i]) ? 1 : 0
	vbool1_t bool_res = vmseq_vv_i8m8_b1(vand_vv_i8m8(vle8_v_i8m8((int8_t *)(&_a), 16), msb_mask, 16), msb_mask, 16);

	return *((uint32_t *) &bool_res) & 0xffff;
}

#endif

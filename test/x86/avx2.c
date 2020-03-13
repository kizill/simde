/* Copyright (c) 2018, 2019 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define SIMDE_TESTS_CURRENT_ISAX avx2
#include <simde/x86/avx2.h>
#include <test/x86/test-avx.h>

#if defined(SIMDE_AVX2_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

static MunitResult
test_simde_mm256_add_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C(  38), INT8_C(   7), INT8_C(  -2), INT8_C(  58),
                           INT8_C( 110), INT8_C( -99), INT8_C( -44), INT8_C(  54),
                           INT8_C(  -7), INT8_C(  11), INT8_C(  37), INT8_C(  89),
                           INT8_C(-116), INT8_C( -61), INT8_C( -62), INT8_C(-100),
                           INT8_C(  93), INT8_C(-106), INT8_C( -93), INT8_C( -65),
                           INT8_C(  41), INT8_C(  48), INT8_C( 119), INT8_C( -81),
                           INT8_C( 111), INT8_C(-127), INT8_C( -20), INT8_C(  49),
                           INT8_C( -86), INT8_C(  40), INT8_C(   8), INT8_C( -11)),
      simde_mm256_set_epi8(INT8_C(  39), INT8_C(  75), INT8_C(  21), INT8_C( -79),
                           INT8_C(  76), INT8_C( -46), INT8_C(  91), INT8_C(  40),
                           INT8_C(  97), INT8_C( -98), INT8_C( -82), INT8_C(  44),
                           INT8_C( -73), INT8_C( -89), INT8_C(-127), INT8_C( -32),
                           INT8_C( 120), INT8_C( 113), INT8_C( -53), INT8_C( -49),
                           INT8_C( -63), INT8_C(  81), INT8_C( -64), INT8_C(  90),
                           INT8_C( 100), INT8_C( -73), INT8_C( -51), INT8_C(-117),
                           INT8_C( -40), INT8_C(  69), INT8_C(-110), INT8_C( -48)),
      simde_mm256_set_epi8(INT8_C(  77), INT8_C(  82), INT8_C(  19), INT8_C( -21),
                           INT8_C( -70), INT8_C( 111), INT8_C(  47), INT8_C(  94),
                           INT8_C(  90), INT8_C( -87), INT8_C( -45), INT8_C(-123),
                           INT8_C(  67), INT8_C( 106), INT8_C(  67), INT8_C( 124),
                           INT8_C( -43), INT8_C(   7), INT8_C( 110), INT8_C(-114),
                           INT8_C( -22), INT8_C(-127), INT8_C(  55), INT8_C(   9),
                           INT8_C( -45), INT8_C(  56), INT8_C( -71), INT8_C( -68),
                           INT8_C(-126), INT8_C( 109), INT8_C(-102), INT8_C( -59)) },
    { simde_mm256_set_epi8(INT8_C(  71), INT8_C(   4), INT8_C(  70), INT8_C( -16),
                           INT8_C( -60), INT8_C( -69), INT8_C( -49), INT8_C( 108),
                           INT8_C( 108), INT8_C(  12), INT8_C(  69), INT8_C( -44),
                           INT8_C( 104), INT8_C(-122), INT8_C(  94), INT8_C( -44),
                           INT8_C(  20), INT8_C( -27), INT8_C(  55), INT8_C( 116),
                           INT8_C( 117), INT8_C(-108), INT8_C(  62), INT8_C(-118),
                           INT8_C(  86), INT8_C( -59), INT8_C(   3), INT8_C(  -3),
                           INT8_C( -82), INT8_C( 110), INT8_C(  88), INT8_C(  57)),
      simde_mm256_set_epi8(INT8_C( -80), INT8_C( 112), INT8_C(  78), INT8_C( -63),
                           INT8_C( 105), INT8_C(  59), INT8_C(  13), INT8_C( -94),
                           INT8_C( 116), INT8_C( -39), INT8_C(  42), INT8_C(  69),
                           INT8_C( 119), INT8_C(  -2), INT8_C( -96), INT8_C( -26),
                           INT8_C(  78), INT8_C(  -3), INT8_C( 125), INT8_C(  93),
                           INT8_C( -99), INT8_C( -92), INT8_C(  87), INT8_C( 115),
                           INT8_C( -58), INT8_C( 102), INT8_C(  77), INT8_C(  14),
                           INT8_C(-124), INT8_C(  69), INT8_C( 123), INT8_C(  22)),
      simde_mm256_set_epi8(INT8_C(  -9), INT8_C( 116), INT8_C(-108), INT8_C( -79),
                           INT8_C(  45), INT8_C( -10), INT8_C( -36), INT8_C(  14),
                           INT8_C( -32), INT8_C( -27), INT8_C( 111), INT8_C(  25),
                           INT8_C( -33), INT8_C(-124), INT8_C(  -2), INT8_C( -70),
                           INT8_C(  98), INT8_C( -30), INT8_C( -76), INT8_C( -47),
                           INT8_C(  18), INT8_C(  56), INT8_C(-107), INT8_C(  -3),
                           INT8_C(  28), INT8_C(  43), INT8_C(  80), INT8_C(  11),
                           INT8_C(  50), INT8_C( -77), INT8_C( -45), INT8_C(  79)) },
    { simde_mm256_set_epi8(INT8_C(  35), INT8_C(  50), INT8_C(-118), INT8_C( -51),
                           INT8_C( 104), INT8_C(  20), INT8_C( -38), INT8_C(-105),
                           INT8_C(  57), INT8_C(  19), INT8_C( -89), INT8_C( -46),
                           INT8_C(  27), INT8_C( -40), INT8_C(  -8), INT8_C( -54),
                           INT8_C(  74), INT8_C(-108), INT8_C( -11), INT8_C(  36),
                           INT8_C(  14), INT8_C(  26), INT8_C( -19), INT8_C( -47),
                           INT8_C(  70), INT8_C( -22), INT8_C(   1), INT8_C(  48),
                           INT8_C(-104), INT8_C(  96), INT8_C(  54), INT8_C( -65)),
      simde_mm256_set_epi8(INT8_C(  28), INT8_C( -52), INT8_C( 107), INT8_C(-103),
                           INT8_C( 110), INT8_C(  86), INT8_C(  60), INT8_C(   2),
                           INT8_C( -17), INT8_C(  30), INT8_C( -28), INT8_C( -92),
                           INT8_C(  93), INT8_C( 112), INT8_C( -31), INT8_C(  -9),
                           INT8_C(   8), INT8_C( -36), INT8_C( -58), INT8_C(-120),
                           INT8_C( -53), INT8_C(  26), INT8_C( -55), INT8_C( -73),
                           INT8_C(  20), INT8_C(  83), INT8_C( 124), INT8_C(  54),
                           INT8_C(  30), INT8_C( -54), INT8_C( -43), INT8_C(-123)),
      simde_mm256_set_epi8(INT8_C(  63), INT8_C(  -2), INT8_C( -11), INT8_C( 102),
                           INT8_C( -42), INT8_C( 106), INT8_C(  22), INT8_C(-103),
                           INT8_C(  40), INT8_C(  49), INT8_C(-117), INT8_C( 118),
                           INT8_C( 120), INT8_C(  72), INT8_C( -39), INT8_C( -63),
                           INT8_C(  82), INT8_C( 112), INT8_C( -69), INT8_C( -84),
                           INT8_C( -39), INT8_C(  52), INT8_C( -74), INT8_C(-120),
                           INT8_C(  90), INT8_C(  61), INT8_C( 125), INT8_C( 102),
                           INT8_C( -74), INT8_C(  42), INT8_C(  11), INT8_C(  68)) },
    { simde_mm256_set_epi8(INT8_C( -39), INT8_C( 114), INT8_C(  -7), INT8_C( 121),
                           INT8_C(  92), INT8_C(  79), INT8_C( 102), INT8_C(  76),
                           INT8_C( 109), INT8_C( -19), INT8_C(  70), INT8_C( -60),
                           INT8_C(  69), INT8_C( -31), INT8_C(  37), INT8_C(  40),
                           INT8_C( -46), INT8_C(  88), INT8_C( -21), INT8_C( -43),
                           INT8_C(  83), INT8_C(  14), INT8_C( -23), INT8_C( -33),
                           INT8_C(  86), INT8_C( -85), INT8_C(   8), INT8_C(  59),
                           INT8_C( 123), INT8_C(  93), INT8_C( -22), INT8_C(  26)),
      simde_mm256_set_epi8(INT8_C( 116), INT8_C( -91), INT8_C(  32), INT8_C( -33),
                           INT8_C(-123), INT8_C(-113), INT8_C(  98), INT8_C( -60),
                           INT8_C(-116), INT8_C( -75), INT8_C(  96), INT8_C(  10),
                           INT8_C( -53), INT8_C( -10), INT8_C( -80), INT8_C(-128),
                           INT8_C(  59), INT8_C( -73), INT8_C( -11), INT8_C(   8),
                           INT8_C(-127), INT8_C(-108), INT8_C(-124), INT8_C( 111),
                           INT8_C( -79), INT8_C(  28), INT8_C(  24), INT8_C(  40),
                           INT8_C(  40), INT8_C(  29), INT8_C( 119), INT8_C( 100)),
      simde_mm256_set_epi8(INT8_C(  77), INT8_C(  23), INT8_C(  25), INT8_C(  88),
                           INT8_C( -31), INT8_C( -34), INT8_C( -56), INT8_C(  16),
                           INT8_C(  -7), INT8_C( -94), INT8_C( -90), INT8_C( -50),
                           INT8_C(  16), INT8_C( -41), INT8_C( -43), INT8_C( -88),
                           INT8_C(  13), INT8_C(  15), INT8_C( -32), INT8_C( -35),
                           INT8_C( -44), INT8_C( -94), INT8_C( 109), INT8_C(  78),
                           INT8_C(   7), INT8_C( -57), INT8_C(  32), INT8_C(  99),
                           INT8_C( -93), INT8_C( 122), INT8_C(  97), INT8_C( 126)) },
    { simde_mm256_set_epi8(INT8_C(-108), INT8_C( -39), INT8_C( -41), INT8_C( 120),
                           INT8_C(-106), INT8_C( -66), INT8_C( -98), INT8_C( -12),
                           INT8_C(-106), INT8_C( -94), INT8_C( -31), INT8_C( -14),
                           INT8_C(  -2), INT8_C( -34), INT8_C( -30), INT8_C( -64),
                           INT8_C(  65), INT8_C(  50), INT8_C(  73), INT8_C( -32),
                           INT8_C( 106), INT8_C(-126), INT8_C(  67), INT8_C(  53),
                           INT8_C( 104), INT8_C(  17), INT8_C( -36), INT8_C(  95),
                           INT8_C(  57), INT8_C(  32), INT8_C( -59), INT8_C( -12)),
      simde_mm256_set_epi8(INT8_C(  29), INT8_C(  61), INT8_C( -31), INT8_C( 122),
                           INT8_C(   8), INT8_C( -70), INT8_C(  11), INT8_C(  62),
                           INT8_C( -73), INT8_C( -96), INT8_C( -10), INT8_C( -40),
                           INT8_C( -52), INT8_C( -38), INT8_C(  92), INT8_C(  51),
                           INT8_C(  35), INT8_C(  53), INT8_C(  88), INT8_C( -11),
                           INT8_C(  57), INT8_C(-113), INT8_C(-123), INT8_C( 106),
                           INT8_C(-110), INT8_C(-110), INT8_C(   2), INT8_C(  67),
                           INT8_C( -30), INT8_C( -96), INT8_C( -97), INT8_C( -86)),
      simde_mm256_set_epi8(INT8_C( -79), INT8_C(  22), INT8_C( -72), INT8_C( -14),
                           INT8_C( -98), INT8_C( 120), INT8_C( -87), INT8_C(  50),
                           INT8_C(  77), INT8_C(  66), INT8_C( -41), INT8_C( -54),
                           INT8_C( -54), INT8_C( -72), INT8_C(  62), INT8_C( -13),
                           INT8_C( 100), INT8_C( 103), INT8_C( -95), INT8_C( -43),
                           INT8_C( -93), INT8_C(  17), INT8_C( -56), INT8_C( -97),
                           INT8_C(  -6), INT8_C( -93), INT8_C( -34), INT8_C( -94),
                           INT8_C(  27), INT8_C( -64), INT8_C( 100), INT8_C( -98)) },
    { simde_mm256_set_epi8(INT8_C( -25), INT8_C( -91), INT8_C(  57), INT8_C( -61),
                           INT8_C(  27), INT8_C( -92), INT8_C(-114), INT8_C(-104),
                           INT8_C( 125), INT8_C( 120), INT8_C( -30), INT8_C(   8),
                           INT8_C(  88), INT8_C( -75), INT8_C( 100), INT8_C(  97),
                           INT8_C( -61), INT8_C( 122), INT8_C(  27), INT8_C( -70),
                           INT8_C( -30), INT8_C( -60), INT8_C( -90), INT8_C( -43),
                           INT8_C( -10), INT8_C( -38), INT8_C(  12), INT8_C(  90),
                           INT8_C(   1), INT8_C(  39), INT8_C( -80), INT8_C(  53)),
      simde_mm256_set_epi8(INT8_C( 121), INT8_C(  85), INT8_C(-111), INT8_C(-111),
                           INT8_C(  84), INT8_C(  54), INT8_C( -52), INT8_C( -62),
                           INT8_C( -55), INT8_C(  17), INT8_C(  68), INT8_C(  63),
                           INT8_C( 113), INT8_C( -67), INT8_C( -38), INT8_C(-118),
                           INT8_C(-104), INT8_C( -71), INT8_C(  55), INT8_C(  21),
                           INT8_C( -66), INT8_C(  19), INT8_C(-123), INT8_C(  95),
                           INT8_C( 118), INT8_C(  65), INT8_C( -70), INT8_C( -13),
                           INT8_C( 120), INT8_C( -27), INT8_C( -66), INT8_C( 122)),
      simde_mm256_set_epi8(INT8_C(  96), INT8_C(  -6), INT8_C( -54), INT8_C(  84),
                           INT8_C( 111), INT8_C( -38), INT8_C(  90), INT8_C(  90),
                           INT8_C(  70), INT8_C(-119), INT8_C(  38), INT8_C(  71),
                           INT8_C( -55), INT8_C( 114), INT8_C(  62), INT8_C( -21),
                           INT8_C(  91), INT8_C(  51), INT8_C(  82), INT8_C( -49),
                           INT8_C( -96), INT8_C( -41), INT8_C(  43), INT8_C(  52),
                           INT8_C( 108), INT8_C(  27), INT8_C( -58), INT8_C(  77),
                           INT8_C( 121), INT8_C(  12), INT8_C( 110), INT8_C( -81)) },
    { simde_mm256_set_epi8(INT8_C( 117), INT8_C( -64), INT8_C(  32), INT8_C( -52),
                           INT8_C(  16), INT8_C( -33), INT8_C(  14), INT8_C( -85),
                           INT8_C(   3), INT8_C( -57), INT8_C( -94), INT8_C( -41),
                           INT8_C( -98), INT8_C( 127), INT8_C(  42), INT8_C(  48),
                           INT8_C(  17), INT8_C( 106), INT8_C( -29), INT8_C( -56),
                           INT8_C(  75), INT8_C(-117), INT8_C( 106), INT8_C(  46),
                           INT8_C(-110), INT8_C( 123), INT8_C(  46), INT8_C(   8),
                           INT8_C(-118), INT8_C( 103), INT8_C(  19), INT8_C(  26)),
      simde_mm256_set_epi8(INT8_C(-123), INT8_C(  76), INT8_C( 117), INT8_C(  39),
                           INT8_C( 120), INT8_C( -11), INT8_C(  12), INT8_C( -12),
                           INT8_C( -32), INT8_C(   7), INT8_C(  13), INT8_C(  45),
                           INT8_C(  60), INT8_C( -83), INT8_C( -84), INT8_C( -17),
                           INT8_C( -88), INT8_C( -57), INT8_C( 102), INT8_C( -44),
                           INT8_C( 119), INT8_C(  16), INT8_C( 101), INT8_C( -86),
                           INT8_C(-106), INT8_C(-124), INT8_C(  83), INT8_C(-127),
                           INT8_C(  55), INT8_C( -92), INT8_C(  15), INT8_C(-114)),
      simde_mm256_set_epi8(INT8_C(  -6), INT8_C(  12), INT8_C(-107), INT8_C( -13),
                           INT8_C(-120), INT8_C( -44), INT8_C(  26), INT8_C( -97),
                           INT8_C( -29), INT8_C( -50), INT8_C( -81), INT8_C(   4),
                           INT8_C( -38), INT8_C(  44), INT8_C( -42), INT8_C(  31),
                           INT8_C( -71), INT8_C(  49), INT8_C(  73), INT8_C(-100),
                           INT8_C( -62), INT8_C(-101), INT8_C( -49), INT8_C( -40),
                           INT8_C(  40), INT8_C(  -1), INT8_C(-127), INT8_C(-119),
                           INT8_C( -63), INT8_C(  11), INT8_C(  34), INT8_C( -88)) },
    { simde_mm256_set_epi8(INT8_C(-111), INT8_C( -68), INT8_C( -72), INT8_C(-123),
                           INT8_C(  60), INT8_C(  19), INT8_C( -56), INT8_C( -34),
                           INT8_C(  75), INT8_C(-101), INT8_C(  82), INT8_C(  25),
                           INT8_C( 119), INT8_C(  87), INT8_C(  12), INT8_C( -81),
                           INT8_C( 120), INT8_C(  58), INT8_C(  77), INT8_C(-102),
                           INT8_C( -65), INT8_C(  14), INT8_C(  32), INT8_C(-111),
                           INT8_C(  72), INT8_C(  -1), INT8_C( 117), INT8_C(-104),
                           INT8_C(  81), INT8_C( -80), INT8_C( -43), INT8_C( -80)),
      simde_mm256_set_epi8(INT8_C( 114), INT8_C( -63), INT8_C(  59), INT8_C( -32),
                           INT8_C( 113), INT8_C(-103), INT8_C( -89), INT8_C( -53),
                           INT8_C( -11), INT8_C(  31), INT8_C(  71), INT8_C( -59),
                           INT8_C(  89), INT8_C(  28), INT8_C(  76), INT8_C(  62),
                           INT8_C(  13), INT8_C( 105), INT8_C( -93), INT8_C(  64),
                           INT8_C( -40), INT8_C(  38), INT8_C( -73), INT8_C(-114),
                           INT8_C(-121), INT8_C( -54), INT8_C(-113), INT8_C(   1),
                           INT8_C( -77), INT8_C( -55), INT8_C(  24), INT8_C( -16)),
      simde_mm256_set_epi8(INT8_C(   3), INT8_C( 125), INT8_C( -13), INT8_C( 101),
                           INT8_C( -83), INT8_C( -84), INT8_C( 111), INT8_C( -87),
                           INT8_C(  64), INT8_C( -70), INT8_C(-103), INT8_C( -34),
                           INT8_C( -48), INT8_C( 115), INT8_C(  88), INT8_C( -19),
                           INT8_C(-123), INT8_C( -93), INT8_C( -16), INT8_C( -38),
                           INT8_C(-105), INT8_C(  52), INT8_C( -41), INT8_C(  31),
                           INT8_C( -49), INT8_C( -55), INT8_C(   4), INT8_C(-103),
                           INT8_C(   4), INT8_C( 121), INT8_C( -19), INT8_C( -96)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_add_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_add_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi16(INT16_C(-12908), INT16_C(-15352), INT16_C( -9871), INT16_C( 11131),
                            INT16_C(-13055), INT16_C( 26967), INT16_C(-23057), INT16_C( 20309),
                            INT16_C(-12549), INT16_C(-20367), INT16_C(  6732), INT16_C( -7853),
                            INT16_C(-23923), INT16_C( -3719), INT16_C(-28976), INT16_C( 10001)),
      simde_mm256_set_epi16(INT16_C( 13883), INT16_C( 24989), INT16_C(-27634), INT16_C( 20264),
                            INT16_C( 15739), INT16_C(-13782), INT16_C( -2125), INT16_C(-14153),
                            INT16_C( -5381), INT16_C(-18938), INT16_C(-15901), INT16_C( -7111),
                            INT16_C(-11138), INT16_C( 23506), INT16_C( -6177), INT16_C(-29557)),
      simde_mm256_set_epi16(INT16_C(   975), INT16_C(  9637), INT16_C( 28031), INT16_C( 31395),
                            INT16_C(  2684), INT16_C( 13185), INT16_C(-25182), INT16_C(  6156),
                            INT16_C(-17930), INT16_C( 26231), INT16_C( -9169), INT16_C(-14964),
                            INT16_C( 30475), INT16_C( 19787), INT16_C( 30383), INT16_C(-19556)) },
    { simde_mm256_set_epi16(INT16_C(-20529), INT16_C(-26039), INT16_C( 27693), INT16_C(-13325),
                            INT16_C(-24443), INT16_C(-32106), INT16_C(-21283), INT16_C( -3709),
                            INT16_C(   747), INT16_C( 18820), INT16_C(-26624), INT16_C( 10967),
                            INT16_C( 25066), INT16_C( 19698), INT16_C(-32202), INT16_C(-11757)),
      simde_mm256_set_epi16(INT16_C( 10244), INT16_C(-18450), INT16_C(  5048), INT16_C( -3511),
                            INT16_C(-16723), INT16_C(-30842), INT16_C( 22572), INT16_C( -8065),
                            INT16_C( 30703), INT16_C(-26965), INT16_C( 23628), INT16_C(-27177),
                            INT16_C(-17808), INT16_C(-15958), INT16_C( 15529), INT16_C( 11766)),
      simde_mm256_set_epi16(INT16_C(-10285), INT16_C( 21047), INT16_C( 32741), INT16_C(-16836),
                            INT16_C( 24370), INT16_C(  2588), INT16_C(  1289), INT16_C(-11774),
                            INT16_C( 31450), INT16_C( -8145), INT16_C( -2996), INT16_C(-16210),
                            INT16_C(  7258), INT16_C(  3740), INT16_C(-16673), INT16_C(     9)) },
    { simde_mm256_set_epi16(INT16_C( 20347), INT16_C( 23946), INT16_C( 24055), INT16_C(  9643),
                            INT16_C( -2110), INT16_C(-31092), INT16_C(-13787), INT16_C( -6302),
                            INT16_C(  1396), INT16_C(  8481), INT16_C(-32148), INT16_C( 29268),
                            INT16_C( -9419), INT16_C( -3935), INT16_C( -1720), INT16_C(-10026)),
      simde_mm256_set_epi16(INT16_C( 15679), INT16_C( -2155), INT16_C( 32033), INT16_C( -2216),
                            INT16_C(-11561), INT16_C( 32737), INT16_C(-28164), INT16_C(  9867),
                            INT16_C( 17610), INT16_C(-22692), INT16_C(-28058), INT16_C(  7040),
                            INT16_C( 26754), INT16_C( -3306), INT16_C( -7351), INT16_C( 27370)),
      simde_mm256_set_epi16(INT16_C(-29510), INT16_C( 21791), INT16_C( -9448), INT16_C(  7427),
                            INT16_C(-13671), INT16_C(  1645), INT16_C( 23585), INT16_C(  3565),
                            INT16_C( 19006), INT16_C(-14211), INT16_C(  5330), INT16_C(-29228),
                            INT16_C( 17335), INT16_C( -7241), INT16_C( -9071), INT16_C( 17344)) },
    { simde_mm256_set_epi16(INT16_C(-27154), INT16_C(-23947), INT16_C(  1952), INT16_C(  7823),
                            INT16_C( 29492), INT16_C( -6766), INT16_C( 11046), INT16_C( 22007),
                            INT16_C( 15625), INT16_C( -6212), INT16_C( 31802), INT16_C( 17826),
                            INT16_C( 14647), INT16_C( 24188), INT16_C(-26765), INT16_C( 18766)),
      simde_mm256_set_epi16(INT16_C(-26373), INT16_C( 11481), INT16_C(-29646), INT16_C(-31758),
                            INT16_C(-13826), INT16_C( 16818), INT16_C( -2585), INT16_C(  3549),
                            INT16_C(   930), INT16_C(-29705), INT16_C(-19505), INT16_C(-18939),
                            INT16_C(-22195), INT16_C(  6794), INT16_C(  4204), INT16_C( 28707)),
      simde_mm256_set_epi16(INT16_C( 12009), INT16_C(-12466), INT16_C(-27694), INT16_C(-23935),
                            INT16_C( 15666), INT16_C( 10052), INT16_C(  8461), INT16_C( 25556),
                            INT16_C( 16555), INT16_C( 29619), INT16_C( 12297), INT16_C( -1113),
                            INT16_C( -7548), INT16_C( 30982), INT16_C(-22561), INT16_C(-18063)) },
    { simde_mm256_set_epi16(INT16_C( 30710), INT16_C( 24751), INT16_C( -4369), INT16_C( 18532),
                            INT16_C( 22682), INT16_C( 30280), INT16_C( 11292), INT16_C( 11710),
                            INT16_C(-17556), INT16_C( 10009), INT16_C(-27333), INT16_C( 22196),
                            INT16_C(-19056), INT16_C( -7837), INT16_C( 29666), INT16_C(  6547)),
      simde_mm256_set_epi16(INT16_C( -2566), INT16_C(  5814), INT16_C( 26818), INT16_C( 27091),
                            INT16_C(-10234), INT16_C( 23509), INT16_C( 13267), INT16_C( -7338),
                            INT16_C( 13949), INT16_C(  1472), INT16_C( 11063), INT16_C( -7215),
                            INT16_C( -8090), INT16_C(-23785), INT16_C(-15335), INT16_C(  4848)),
      simde_mm256_set_epi16(INT16_C( 28144), INT16_C( 30565), INT16_C( 22449), INT16_C(-19913),
                            INT16_C( 12448), INT16_C(-11747), INT16_C( 24559), INT16_C(  4372),
                            INT16_C( -3607), INT16_C( 11481), INT16_C(-16270), INT16_C( 14981),
                            INT16_C(-27146), INT16_C(-31622), INT16_C( 14331), INT16_C( 11395)) },
    { simde_mm256_set_epi16(INT16_C( 30207), INT16_C(-18325), INT16_C(  1180), INT16_C(-26389),
                            INT16_C( 14745), INT16_C(  7441), INT16_C(-23138), INT16_C(-20960),
                            INT16_C( 16686), INT16_C(-12834), INT16_C( -5724), INT16_C(  1237),
                            INT16_C( 12783), INT16_C( -1549), INT16_C(  7604), INT16_C(-25399)),
      simde_mm256_set_epi16(INT16_C( -5331), INT16_C(-23526), INT16_C( 14670), INT16_C(-15592),
                            INT16_C( 18159), INT16_C(  4760), INT16_C( 10369), INT16_C(-25724),
                            INT16_C(-28583), INT16_C( -6941), INT16_C(-17844), INT16_C(-14094),
                            INT16_C( 16769), INT16_C( 12540), INT16_C(-26071), INT16_C(  8463)),
      simde_mm256_set_epi16(INT16_C( 24876), INT16_C( 23685), INT16_C( 15850), INT16_C( 23555),
                            INT16_C(-32632), INT16_C( 12201), INT16_C(-12769), INT16_C( 18852),
                            INT16_C(-11897), INT16_C(-19775), INT16_C(-23568), INT16_C(-12857),
                            INT16_C( 29552), INT16_C( 10991), INT16_C(-18467), INT16_C(-16936)) },
    { simde_mm256_set_epi16(INT16_C( 28357), INT16_C( 20172), INT16_C( 17421), INT16_C(-11866),
                            INT16_C(-11434), INT16_C( 24363), INT16_C( 30807), INT16_C( -1507),
                            INT16_C(-31442), INT16_C( 25409), INT16_C( 25186), INT16_C( 22807),
                            INT16_C(-13333), INT16_C(-32257), INT16_C(-15570), INT16_C(  2752)),
      simde_mm256_set_epi16(INT16_C(-19799), INT16_C(-19809), INT16_C(-16948), INT16_C( -1715),
                            INT16_C( 29345), INT16_C(-32027), INT16_C(  5007), INT16_C(  4903),
                            INT16_C( -2392), INT16_C(-30038), INT16_C( 23207), INT16_C(-24060),
                            INT16_C( 29275), INT16_C( 13317), INT16_C( 26431), INT16_C( 23940)),
      simde_mm256_set_epi16(INT16_C(  8558), INT16_C(   363), INT16_C(   473), INT16_C(-13581),
                            INT16_C( 17911), INT16_C( -7664), INT16_C(-29722), INT16_C(  3396),
                            INT16_C( 31702), INT16_C( -4629), INT16_C(-17143), INT16_C( -1253),
                            INT16_C( 15942), INT16_C(-18940), INT16_C( 10861), INT16_C( 26692)) },
    { simde_mm256_set_epi16(INT16_C(  6003), INT16_C( 21193), INT16_C( 27446), INT16_C( 12164),
                            INT16_C(-15839), INT16_C(-27621), INT16_C( 27366), INT16_C(  3166),
                            INT16_C(-14586), INT16_C( 16192), INT16_C( 17380), INT16_C(  2397),
                            INT16_C( 17243), INT16_C(  7969), INT16_C(-18393), INT16_C(-28306)),
      simde_mm256_set_epi16(INT16_C( -9798), INT16_C(  1801), INT16_C(-11340), INT16_C(-25270),
                            INT16_C( -7120), INT16_C( -2660), INT16_C( 23941), INT16_C( 18110),
                            INT16_C( -3348), INT16_C( -5762), INT16_C( 30271), INT16_C(  3473),
                            INT16_C( -7979), INT16_C( -3070), INT16_C( 12208), INT16_C( 30362)),
      simde_mm256_set_epi16(INT16_C( -3795), INT16_C( 22994), INT16_C( 16106), INT16_C(-13106),
                            INT16_C(-22959), INT16_C(-30281), INT16_C(-14229), INT16_C( 21276),
                            INT16_C(-17934), INT16_C( 10430), INT16_C(-17885), INT16_C(  5870),
                            INT16_C(  9264), INT16_C(  4899), INT16_C( -6185), INT16_C(  2056)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_add_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_add_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( 1102687755), INT32_C( 1275949869), INT32_C( -388043296), INT32_C( 1616523445),
                            INT32_C( -312991452), INT32_C(-1980926618), INT32_C( 1274012126), INT32_C(  -45808693)),
      simde_mm256_set_epi32(INT32_C(-1821401638), INT32_C( 1143218625), INT32_C(-1072188421), INT32_C( -228883992),
                            INT32_C( 1453787917), INT32_C(-1686415046), INT32_C(-1856178723), INT32_C(-1344248495)),
      simde_mm256_set_epi32(INT32_C( -718713883), INT32_C(-1875798802), INT32_C(-1460231717), INT32_C( 1387639453),
                            INT32_C( 1140796465), INT32_C(  627625632), INT32_C( -582166597), INT32_C(-1390057188)) },
    { simde_mm256_set_epi32(INT32_C( -511556352), INT32_C(  512138684), INT32_C( 2115720361), INT32_C( -345092241),
                            INT32_C( -115713034), INT32_C( 1435785542), INT32_C( -578341737), INT32_C(  626663856)),
      simde_mm256_set_epi32(INT32_C( 1905028737), INT32_C(  164639990), INT32_C(-1952346601), INT32_C( 1853095591),
                            INT32_C(-1825217200), INT32_C(-1102744367), INT32_C(-1105586227), INT32_C(-1908622941)),
      simde_mm256_set_epi32(INT32_C( 1393472385), INT32_C(  676778674), INT32_C(  163373760), INT32_C( 1508003350),
                            INT32_C(-1940930234), INT32_C(  333041175), INT32_C(-1683927964), INT32_C(-1281959085)) },
    { simde_mm256_set_epi32(INT32_C(  841608097), INT32_C(-2001797484), INT32_C(-1658305288), INT32_C(  966942303),
                            INT32_C(  842108123), INT32_C(  697774066), INT32_C(-1273233002), INT32_C( -331057125)),
      simde_mm256_set_epi32(INT32_C(  824745259), INT32_C( 1162513122), INT32_C( 1536105364), INT32_C( 1572988069),
                            INT32_C( 1601630355), INT32_C(  105174023), INT32_C( -548723565), INT32_C(  342919548)),
      simde_mm256_set_epi32(INT32_C( 1666353356), INT32_C( -839284362), INT32_C( -122199924), INT32_C(-1755036924),
                            INT32_C(-1851228818), INT32_C(  802948089), INT32_C(-1821956567), INT32_C(   11862423)) },
    { simde_mm256_set_epi32(INT32_C(-1982661498), INT32_C( -454967885), INT32_C( 1606399367), INT32_C( 1911771725),
                            INT32_C( -320200723), INT32_C( 2055189331), INT32_C( 1782567162), INT32_C(  617047003)),
      simde_mm256_set_epi32(INT32_C(-1988185598), INT32_C( 1350171177), INT32_C( -741176174), INT32_C( 1024642864),
                            INT32_C( 1174775607), INT32_C(-1489493977), INT32_C( 2114610376), INT32_C(-1150946108)),
      simde_mm256_set_epi32(INT32_C(  324120200), INT32_C(  895203292), INT32_C(  865223193), INT32_C(-1358552707),
                            INT32_C(  854574884), INT32_C(  565695354), INT32_C( -397789758), INT32_C( -533899105)) },
    { simde_mm256_set_epi32(INT32_C(-1636237507), INT32_C(-2022044523), INT32_C( 1298417038), INT32_C( -498789244),
                            INT32_C(-1120565370), INT32_C(  -10552717), INT32_C( 1267811859), INT32_C( 1736112342)),
      simde_mm256_set_epi32(INT32_C(   30746202), INT32_C( 1464439343), INT32_C( 1694184093), INT32_C(-1066802952),
                            INT32_C( -664495133), INT32_C(-2016253412), INT32_C(-1975304715), INT32_C(  -70672826)),
      simde_mm256_set_epi32(INT32_C(-1605491305), INT32_C( -557605180), INT32_C(-1302366165), INT32_C(-1565592196),
                            INT32_C(-1785060503), INT32_C(-2026806129), INT32_C( -707492856), INT32_C( 1665439516)) },
    { simde_mm256_set_epi32(INT32_C(  289000373), INT32_C( 1573632519), INT32_C(  -39248751), INT32_C( -989305129),
                            INT32_C( -946333511), INT32_C( -275686449), INT32_C(  -98660627), INT32_C(-1519479102)),
      simde_mm256_set_epi32(INT32_C(  297476793), INT32_C(  436731799), INT32_C(  124294563), INT32_C(-1635813332),
                            INT32_C(  263383074), INT32_C( -533172755), INT32_C( 1125990821), INT32_C( -786980387)),
      simde_mm256_set_epi32(INT32_C(  586477166), INT32_C( 2010364318), INT32_C(   85045812), INT32_C( 1669848835),
                            INT32_C( -682950437), INT32_C( -808859204), INT32_C( 1027330194), INT32_C( 1988507807)) },
    { simde_mm256_set_epi32(INT32_C(  518182194), INT32_C(-1204047142), INT32_C(  -66070725), INT32_C(  499109808),
                            INT32_C(-2041576579), INT32_C( -621515360), INT32_C(  566201077), INT32_C(  301667364)),
      simde_mm256_set_epi32(INT32_C(-1846226401), INT32_C(-1479610627), INT32_C( -205605694), INT32_C( 2074175879),
                            INT32_C(  797873427), INT32_C(  232260429), INT32_C( 2122451120), INT32_C(-1502060759)),
      simde_mm256_set_epi32(INT32_C(-1328044207), INT32_C( 1611309527), INT32_C( -271676419), INT32_C(-1721681609),
                            INT32_C(-1243703152), INT32_C( -389254931), INT32_C(-1606315099), INT32_C(-1200393395)) },
    { simde_mm256_set_epi32(INT32_C(  405834501), INT32_C(-1910761465), INT32_C(  957239954), INT32_C( -786856288),
                            INT32_C(  843920617), INT32_C(  327146567), INT32_C( -333483012), INT32_C(-1269489720)),
      simde_mm256_set_epi32(INT32_C( -343554450), INT32_C( -768698719), INT32_C(-1629325598), INT32_C(  -86112156),
                            INT32_C(-1762054840), INT32_C(-1230219631), INT32_C(-1955142376), INT32_C(  681367456)),
      simde_mm256_set_epi32(INT32_C(   62280051), INT32_C( 1615507112), INT32_C( -672085644), INT32_C( -872968444),
                            INT32_C( -918134223), INT32_C( -903073064), INT32_C( 2006341908), INT32_C( -588122264)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_add_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_add_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C( -919395005897301486), INT64_C( -150854599157471417),
                             INT64_C( 8808382520295569970), INT64_C(-2573562509116397532)),
      simde_mm256_set_epi64x(INT64_C( 3276842246935198107), INT64_C(  509596195322373870),
                             INT64_C( 5497236691336464382), INT64_C( 7792219835689675301)),
      simde_mm256_set_epi64x(INT64_C( 2357447241037896621), INT64_C(  358741596164902453),
                             INT64_C(-4141124862077517264), INT64_C( 5218657326573277769)) },
    { simde_mm256_set_epi64x(INT64_C(-8319032728400165160), INT64_C( 5761166475766138642),
                             INT64_C( 1889840457419449714), INT64_C(-7866468136110945528)),
      simde_mm256_set_epi64x(INT64_C(-7943707797090752726), INT64_C(-3031420544278169311),
                             INT64_C( -274806827926037798), INT64_C(-6305854756278616306)),
      simde_mm256_set_epi64x(INT64_C( 2184003548218633730), INT64_C( 2729745931487969331),
                             INT64_C( 1615033629493411916), INT64_C( 4274421181319989782)) },
    { simde_mm256_set_epi64x(INT64_C( 5895960517559859999), INT64_C( 6208968053276251170),
                             INT64_C( 7761614749466428803), INT64_C(-6998556565488043930)),
      simde_mm256_set_epi64x(INT64_C(-7645095141522766353), INT64_C( 7326575676453958933),
                             INT64_C( 1354311398343021783), INT64_C( 5074528974494991107)),
      simde_mm256_set_epi64x(INT64_C(-1749134623962906354), INT64_C(-4911200343979341513),
                             INT64_C( 9115926147809450586), INT64_C(-1924027590993052823)) },
    { simde_mm256_set_epi64x(INT64_C( 7265152682832433510), INT64_C(-3085894531646767861),
                             INT64_C(-9131129251692740054), INT64_C(  -13949299420174832)),
      simde_mm256_set_epi64x(INT64_C(-8945299951793325147), INT64_C( 1105999600596947619),
                             INT64_C( 1005965954309535795), INT64_C( 6577596548744990052)),
      simde_mm256_set_epi64x(INT64_C(-1680147268960891637), INT64_C(-1979894931049820242),
                             INT64_C(-8125163297383204259), INT64_C( 6563647249324815220)) },
    { simde_mm256_set_epi64x(INT64_C(-1757821625677084255), INT64_C(-2404608367637526264),
                             INT64_C(  707296317246937957), INT64_C(-8620111396460581683)),
      simde_mm256_set_epi64x(INT64_C(-3596883371125205809), INT64_C( 2676371285603083419),
                             INT64_C( 6821095199901887872), INT64_C(-7512247745220049837)),
      simde_mm256_set_epi64x(INT64_C(-5354704996802290064), INT64_C(  271762917965557155),
                             INT64_C( 7528391517148825829), INT64_C( 2314384932028920096)) },
    { simde_mm256_set_epi64x(INT64_C( 6839811261830973327), INT64_C( 5631394124827236824),
                             INT64_C(-5955019407573777834), INT64_C(-3458836099791348328)),
      simde_mm256_set_epi64x(INT64_C( 7744082525445212477), INT64_C(-8800502010596219205),
                             INT64_C(  384951712332227405), INT64_C(  430518285591300198)),
      simde_mm256_set_epi64x(INT64_C(-3862850286433365812), INT64_C(-3169107885768982381),
                             INT64_C(-5570067695241550429), INT64_C(-3028317814200048130)) },
    { simde_mm256_set_epi64x(INT64_C(-3472881623031498101), INT64_C(-1430648476837955016),
                             INT64_C(-3715397159055217239), INT64_C( 5273106926976979674)),
      simde_mm256_set_epi64x(INT64_C(-4550310691059172162), INT64_C( 3088580064706171589),
                             INT64_C( 5815698628016314327), INT64_C(-8735000016575196569)),
      simde_mm256_set_epi64x(INT64_C(-8023192314090670263), INT64_C( 1657931587868216573),
                             INT64_C( 2100301468961097088), INT64_C(-3461893089598216895)) },
    { simde_mm256_set_epi64x(INT64_C(-8609934348254886079), INT64_C( 4626495260054383935),
                             INT64_C(-1742895605763712389), INT64_C( 8190624861564512538)),
      simde_mm256_set_epi64x(INT64_C(-1653872282243675761), INT64_C(-8277823144431279152),
                             INT64_C( 5269960775097450688), INT64_C( 3526432474948394359)),
      simde_mm256_set_epi64x(INT64_C( 8182937443210989776), INT64_C(-3651327884376895217),
                             INT64_C( 3527065169333738299), INT64_C(-6729686737196644719)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_add_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_alignr_epi8_case0(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C(  57), INT8_C( -47), INT8_C( -81), INT8_C( -95),
                           INT8_C(-100), INT8_C( -69), INT8_C( -75), INT8_C(-127),
                           INT8_C(  -8), INT8_C( -83), INT8_C( -94), INT8_C(-113),
                           INT8_C( 107), INT8_C( -39), INT8_C( -99), INT8_C(  46),
                           INT8_C( -61), INT8_C( -72), INT8_C(  -5), INT8_C(-126),
                           INT8_C( 113), INT8_C(-120), INT8_C(  -9), INT8_C( 117),
                           INT8_C( 121), INT8_C( -14), INT8_C( -58), INT8_C(-118),
                           INT8_C( -70), INT8_C( -35), INT8_C(-100), INT8_C(  48)),
      simde_mm256_set_epi8(INT8_C( -98), INT8_C(  80), INT8_C( -16), INT8_C(  73),
                           INT8_C( 126), INT8_C(-115), INT8_C(  31), INT8_C(  80),
                           INT8_C( -75), INT8_C( 117), INT8_C( -13), INT8_C( -70),
                           INT8_C(-101), INT8_C( -10), INT8_C(-111), INT8_C(  96),
                           INT8_C( -77), INT8_C(   0), INT8_C(  70), INT8_C(-121),
                           INT8_C(  78), INT8_C(  54), INT8_C(  38), INT8_C(  18),
                           INT8_C( -12), INT8_C(  68), INT8_C(  53), INT8_C(  45),
                           INT8_C(  77), INT8_C( 103), INT8_C( 118), INT8_C( 116)),
      simde_mm256_set_epi8(INT8_C( -39), INT8_C( -99), INT8_C(  46), INT8_C( -98),
                           INT8_C(  80), INT8_C( -16), INT8_C(  73), INT8_C( 126),
                           INT8_C(-115), INT8_C(  31), INT8_C(  80), INT8_C( -75),
                           INT8_C( 117), INT8_C( -13), INT8_C( -70), INT8_C(-101),
                           INT8_C( -35), INT8_C(-100), INT8_C(  48), INT8_C( -77),
                           INT8_C(   0), INT8_C(  70), INT8_C(-121), INT8_C(  78),
                           INT8_C(  54), INT8_C(  38), INT8_C(  18), INT8_C( -12),
                           INT8_C(  68), INT8_C(  53), INT8_C(  45), INT8_C(  77)) },
    { simde_mm256_set_epi8(INT8_C(   8), INT8_C(  70), INT8_C(  96), INT8_C(  42),
                           INT8_C(  73), INT8_C( -91), INT8_C( -93), INT8_C( -58),
                           INT8_C( -35), INT8_C( -14), INT8_C( 118), INT8_C(-128),
                           INT8_C( -97), INT8_C(  97), INT8_C(  22), INT8_C(   4),
                           INT8_C(  24), INT8_C( 124), INT8_C( -32), INT8_C( -48),
                           INT8_C( -74), INT8_C(  95), INT8_C(  95), INT8_C( -38),
                           INT8_C(  54), INT8_C( 120), INT8_C( -65), INT8_C( -96),
                           INT8_C( -44), INT8_C( -78), INT8_C( -95), INT8_C(-111)),
      simde_mm256_set_epi8(INT8_C(  66), INT8_C(  48), INT8_C(  60), INT8_C(  -4),
                           INT8_C(  33), INT8_C(  67), INT8_C(  97), INT8_C(  65),
                           INT8_C(  80), INT8_C(-109), INT8_C(  88), INT8_C( -23),
                           INT8_C( 107), INT8_C( -65), INT8_C( -65), INT8_C(  62),
                           INT8_C(  90), INT8_C( 118), INT8_C(  25), INT8_C( 105),
                           INT8_C( 109), INT8_C( -45), INT8_C(   4), INT8_C(-107),
                           INT8_C(  55), INT8_C(-101), INT8_C( -65), INT8_C( 121),
                           INT8_C( -76), INT8_C(  55), INT8_C(   6), INT8_C(  86)),
      simde_mm256_set_epi8(INT8_C(  97), INT8_C(  22), INT8_C(   4), INT8_C(  66),
                           INT8_C(  48), INT8_C(  60), INT8_C(  -4), INT8_C(  33),
                           INT8_C(  67), INT8_C(  97), INT8_C(  65), INT8_C(  80),
                           INT8_C(-109), INT8_C(  88), INT8_C( -23), INT8_C( 107),
                           INT8_C( -78), INT8_C( -95), INT8_C(-111), INT8_C(  90),
                           INT8_C( 118), INT8_C(  25), INT8_C( 105), INT8_C( 109),
                           INT8_C( -45), INT8_C(   4), INT8_C(-107), INT8_C(  55),
                           INT8_C(-101), INT8_C( -65), INT8_C( 121), INT8_C( -76)) },
    { simde_mm256_set_epi8(INT8_C(  -1), INT8_C(  93), INT8_C( 114), INT8_C(  49),
                           INT8_C( 120), INT8_C( -70), INT8_C(-112), INT8_C(  19),
                           INT8_C(  56), INT8_C( -12), INT8_C( -77), INT8_C( -85),
                           INT8_C( -59), INT8_C(  80), INT8_C( -47), INT8_C( -28),
                           INT8_C( -33), INT8_C(  73), INT8_C( -24), INT8_C(-106),
                           INT8_C(-122), INT8_C(-111), INT8_C(  -3), INT8_C(  57),
                           INT8_C(  67), INT8_C( 107), INT8_C( -68), INT8_C(-101),
                           INT8_C(  -9), INT8_C(   5), INT8_C(-124), INT8_C( -69)),
      simde_mm256_set_epi8(INT8_C( -67), INT8_C(  65), INT8_C( -72), INT8_C( -90),
                           INT8_C( -44), INT8_C(   2), INT8_C(  39), INT8_C( -45),
                           INT8_C(  51), INT8_C( -30), INT8_C( -47), INT8_C(   1),
                           INT8_C( -91), INT8_C( -40), INT8_C( -73), INT8_C(  33),
                           INT8_C(-117), INT8_C( -31), INT8_C(-117), INT8_C(  60),
                           INT8_C( -36), INT8_C(-120), INT8_C( -10), INT8_C( -12),
                           INT8_C( -25), INT8_C(-103), INT8_C(  48), INT8_C( -50),
                           INT8_C( 101), INT8_C(  93), INT8_C( -31), INT8_C( -33)),
      simde_mm256_set_epi8(INT8_C(  80), INT8_C( -47), INT8_C( -28), INT8_C( -67),
                           INT8_C(  65), INT8_C( -72), INT8_C( -90), INT8_C( -44),
                           INT8_C(   2), INT8_C(  39), INT8_C( -45), INT8_C(  51),
                           INT8_C( -30), INT8_C( -47), INT8_C(   1), INT8_C( -91),
                           INT8_C(   5), INT8_C(-124), INT8_C( -69), INT8_C(-117),
                           INT8_C( -31), INT8_C(-117), INT8_C(  60), INT8_C( -36),
                           INT8_C(-120), INT8_C( -10), INT8_C( -12), INT8_C( -25),
                           INT8_C(-103), INT8_C(  48), INT8_C( -50), INT8_C( 101)) },
    { simde_mm256_set_epi8(INT8_C( 114), INT8_C( -28), INT8_C( -81), INT8_C(-126),
                           INT8_C(-114), INT8_C( -94), INT8_C(-101), INT8_C(  52),
                           INT8_C(  30), INT8_C(  66), INT8_C(-105), INT8_C(  50),
                           INT8_C(  48), INT8_C(  15), INT8_C(   1), INT8_C(-106),
                           INT8_C( -36), INT8_C(  61), INT8_C( -18), INT8_C(   8),
                           INT8_C(  89), INT8_C( -23), INT8_C(  58), INT8_C( -29),
                           INT8_C( 110), INT8_C(  57), INT8_C( -39), INT8_C(   1),
                           INT8_C( -60), INT8_C(  60), INT8_C( -80), INT8_C( -20)),
      simde_mm256_set_epi8(INT8_C( -60), INT8_C(  69), INT8_C( -69), INT8_C( 107),
                           INT8_C(   2), INT8_C( -33), INT8_C(  14), INT8_C(  77),
                           INT8_C(  15), INT8_C(  63), INT8_C(  63), INT8_C( -53),
                           INT8_C(  -9), INT8_C(  76), INT8_C(   7), INT8_C( -76),
                           INT8_C( -23), INT8_C(-107), INT8_C(  84), INT8_C(  37),
                           INT8_C( -18), INT8_C(  47), INT8_C(  58), INT8_C(  31),
                           INT8_C(  69), INT8_C(  12), INT8_C(  46), INT8_C( 101),
                           INT8_C( -38), INT8_C( 117), INT8_C(-113), INT8_C( -36)),
      simde_mm256_set_epi8(INT8_C(  15), INT8_C(   1), INT8_C(-106), INT8_C( -60),
                           INT8_C(  69), INT8_C( -69), INT8_C( 107), INT8_C(   2),
                           INT8_C( -33), INT8_C(  14), INT8_C(  77), INT8_C(  15),
                           INT8_C(  63), INT8_C(  63), INT8_C( -53), INT8_C(  -9),
                           INT8_C(  60), INT8_C( -80), INT8_C( -20), INT8_C( -23),
                           INT8_C(-107), INT8_C(  84), INT8_C(  37), INT8_C( -18),
                           INT8_C(  47), INT8_C(  58), INT8_C(  31), INT8_C(  69),
                           INT8_C(  12), INT8_C(  46), INT8_C( 101), INT8_C( -38)) },
    { simde_mm256_set_epi8(INT8_C(  13), INT8_C( -32), INT8_C( -51), INT8_C(  49),
                           INT8_C(  15), INT8_C(  15), INT8_C( -66), INT8_C( -38),
                           INT8_C(  69), INT8_C(   1), INT8_C( -50), INT8_C(-103),
                           INT8_C(  72), INT8_C( -87), INT8_C(-104), INT8_C( -58),
                           INT8_C(  63), INT8_C(-120), INT8_C(  36), INT8_C( -61),
                           INT8_C( 106), INT8_C(  97), INT8_C(-128), INT8_C(  26),
                           INT8_C(-121), INT8_C( -27), INT8_C( 107), INT8_C(-112),
                           INT8_C(  57), INT8_C(  39), INT8_C(  98), INT8_C( 126)),
      simde_mm256_set_epi8(INT8_C(-110), INT8_C(  50), INT8_C( 102), INT8_C( -85),
                           INT8_C( -62), INT8_C(  74), INT8_C( 102), INT8_C(  36),
                           INT8_C( -55), INT8_C(-104), INT8_C(  11), INT8_C( -70),
                           INT8_C( -20), INT8_C(-104), INT8_C( -37), INT8_C( 122),
                           INT8_C( -88), INT8_C(  70), INT8_C(  43), INT8_C( -34),
                           INT8_C(  14), INT8_C(  55), INT8_C( -41), INT8_C(  33),
                           INT8_C(  53), INT8_C(-102), INT8_C(  56), INT8_C(  26),
                           INT8_C( -79), INT8_C( -30), INT8_C(  73), INT8_C( -53)),
      simde_mm256_set_epi8(INT8_C( -87), INT8_C(-104), INT8_C( -58), INT8_C(-110),
                           INT8_C(  50), INT8_C( 102), INT8_C( -85), INT8_C( -62),
                           INT8_C(  74), INT8_C( 102), INT8_C(  36), INT8_C( -55),
                           INT8_C(-104), INT8_C(  11), INT8_C( -70), INT8_C( -20),
                           INT8_C(  39), INT8_C(  98), INT8_C( 126), INT8_C( -88),
                           INT8_C(  70), INT8_C(  43), INT8_C( -34), INT8_C(  14),
                           INT8_C(  55), INT8_C( -41), INT8_C(  33), INT8_C(  53),
                           INT8_C(-102), INT8_C(  56), INT8_C(  26), INT8_C( -79)) },
    { simde_mm256_set_epi8(INT8_C(-103), INT8_C(  23), INT8_C( -90), INT8_C(  43),
                           INT8_C(  -8), INT8_C(  54), INT8_C( -93), INT8_C(  64),
                           INT8_C(-116), INT8_C( -76), INT8_C( -53), INT8_C(  35),
                           INT8_C(  51), INT8_C( -86), INT8_C(   8), INT8_C(  43),
                           INT8_C( -60), INT8_C(-113), INT8_C(  44), INT8_C(-102),
                           INT8_C(  77), INT8_C(  95), INT8_C(  57), INT8_C( 124),
                           INT8_C( -91), INT8_C( -87), INT8_C( -54), INT8_C( -83),
                           INT8_C( 108), INT8_C(  76), INT8_C(  90), INT8_C( -49)),
      simde_mm256_set_epi8(INT8_C( -43), INT8_C(  -5), INT8_C(  94), INT8_C(  76),
                           INT8_C(  -9), INT8_C( 110), INT8_C( -82), INT8_C( 112),
                           INT8_C( -25), INT8_C(  11), INT8_C( -46), INT8_C( -57),
                           INT8_C( -13), INT8_C(-127), INT8_C(  10), INT8_C(-113),
                           INT8_C(  55), INT8_C(  85), INT8_C(  75), INT8_C(  61),
                           INT8_C(  49), INT8_C( -14), INT8_C(  44), INT8_C(-128),
                           INT8_C(-102), INT8_C( -17), INT8_C(  64), INT8_C( -73),
                           INT8_C(  14), INT8_C(  19), INT8_C(  -2), INT8_C(   7)),
      simde_mm256_set_epi8(INT8_C( -86), INT8_C(   8), INT8_C(  43), INT8_C( -43),
                           INT8_C(  -5), INT8_C(  94), INT8_C(  76), INT8_C(  -9),
                           INT8_C( 110), INT8_C( -82), INT8_C( 112), INT8_C( -25),
                           INT8_C(  11), INT8_C( -46), INT8_C( -57), INT8_C( -13),
                           INT8_C(  76), INT8_C(  90), INT8_C( -49), INT8_C(  55),
                           INT8_C(  85), INT8_C(  75), INT8_C(  61), INT8_C(  49),
                           INT8_C( -14), INT8_C(  44), INT8_C(-128), INT8_C(-102),
                           INT8_C( -17), INT8_C(  64), INT8_C( -73), INT8_C(  14)) },
    { simde_mm256_set_epi8(INT8_C( -32), INT8_C( -82), INT8_C(  79), INT8_C(  79),
                           INT8_C( 127), INT8_C(  16), INT8_C(-118), INT8_C( 113),
                           INT8_C( -52), INT8_C( -25), INT8_C(-124), INT8_C( -77),
                           INT8_C( 114), INT8_C(-118), INT8_C( -84), INT8_C(  73),
                           INT8_C( -12), INT8_C( -67), INT8_C(-127), INT8_C( -69),
                           INT8_C(  30), INT8_C(  14), INT8_C( -47), INT8_C(-119),
                           INT8_C( -36), INT8_C( -97), INT8_C( -89), INT8_C(  24),
                           INT8_C( -41), INT8_C( 117), INT8_C(-102), INT8_C(  54)),
      simde_mm256_set_epi8(INT8_C( -66), INT8_C( -50), INT8_C(  39), INT8_C(  30),
                           INT8_C(  53), INT8_C( 108), INT8_C( -71), INT8_C( -62),
                           INT8_C(  58), INT8_C( -69), INT8_C( -39), INT8_C( -28),
                           INT8_C(  58), INT8_C(  54), INT8_C(-117), INT8_C( -49),
                           INT8_C( 126), INT8_C( -71), INT8_C( -39), INT8_C(-120),
                           INT8_C(  88), INT8_C(  41), INT8_C( 127), INT8_C( 111),
                           INT8_C( -32), INT8_C( -18), INT8_C(  12), INT8_C(  97),
                           INT8_C(  83), INT8_C( -96), INT8_C(  13), INT8_C(-101)),
      simde_mm256_set_epi8(INT8_C(-118), INT8_C( -84), INT8_C(  73), INT8_C( -66),
                           INT8_C( -50), INT8_C(  39), INT8_C(  30), INT8_C(  53),
                           INT8_C( 108), INT8_C( -71), INT8_C( -62), INT8_C(  58),
                           INT8_C( -69), INT8_C( -39), INT8_C( -28), INT8_C(  58),
                           INT8_C( 117), INT8_C(-102), INT8_C(  54), INT8_C( 126),
                           INT8_C( -71), INT8_C( -39), INT8_C(-120), INT8_C(  88),
                           INT8_C(  41), INT8_C( 127), INT8_C( 111), INT8_C( -32),
                           INT8_C( -18), INT8_C(  12), INT8_C(  97), INT8_C(  83)) },
    { simde_mm256_set_epi8(INT8_C(-105), INT8_C(   9), INT8_C( -52), INT8_C(  54),
                           INT8_C( -11), INT8_C( -39), INT8_C( -64), INT8_C( -79),
                           INT8_C(  88), INT8_C(  52), INT8_C( -95), INT8_C( -70),
                           INT8_C(  46), INT8_C( 121), INT8_C( -22), INT8_C( 113),
                           INT8_C(  26), INT8_C( 104), INT8_C( -52), INT8_C( 109),
                           INT8_C(   5), INT8_C(  87), INT8_C(  90), INT8_C(  -7),
                           INT8_C( -35), INT8_C(-112), INT8_C(  20), INT8_C(-128),
                           INT8_C( -21), INT8_C( -67), INT8_C(  37), INT8_C( -35)),
      simde_mm256_set_epi8(INT8_C(  66), INT8_C( -23), INT8_C(  45), INT8_C( -38),
                           INT8_C( -94), INT8_C( 119), INT8_C( -23), INT8_C(  70),
                           INT8_C( -75), INT8_C(  25), INT8_C(  79), INT8_C(-101),
                           INT8_C(-122), INT8_C(-107), INT8_C( -10), INT8_C(-109),
                           INT8_C( -96), INT8_C(  45), INT8_C(  31), INT8_C( -60),
                           INT8_C( 100), INT8_C( 115), INT8_C(  79), INT8_C(  38),
                           INT8_C( -35), INT8_C(  57), INT8_C(  13), INT8_C(  93),
                           INT8_C(  54), INT8_C( -61), INT8_C( 101), INT8_C(-113)),
      simde_mm256_set_epi8(INT8_C( 121), INT8_C( -22), INT8_C( 113), INT8_C(  66),
                           INT8_C( -23), INT8_C(  45), INT8_C( -38), INT8_C( -94),
                           INT8_C( 119), INT8_C( -23), INT8_C(  70), INT8_C( -75),
                           INT8_C(  25), INT8_C(  79), INT8_C(-101), INT8_C(-122),
                           INT8_C( -67), INT8_C(  37), INT8_C( -35), INT8_C( -96),
                           INT8_C(  45), INT8_C(  31), INT8_C( -60), INT8_C( 100),
                           INT8_C( 115), INT8_C(  79), INT8_C(  38), INT8_C( -35),
                           INT8_C(  57), INT8_C(  13), INT8_C(  93), INT8_C(  54)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_alignr_epi8(test_vec[i].a, test_vec[i].b, 3);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_alignr_epi8_case1(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C(  57), INT8_C( -47), INT8_C( -81), INT8_C( -95),
                           INT8_C(-100), INT8_C( -69), INT8_C( -75), INT8_C(-127),
                           INT8_C(  -8), INT8_C( -83), INT8_C( -94), INT8_C(-113),
                           INT8_C( 107), INT8_C( -39), INT8_C( -99), INT8_C(  46),
                           INT8_C( -61), INT8_C( -72), INT8_C(  -5), INT8_C(-126),
                           INT8_C( 113), INT8_C(-120), INT8_C(  -9), INT8_C( 117),
                           INT8_C( 121), INT8_C( -14), INT8_C( -58), INT8_C(-118),
                           INT8_C( -70), INT8_C( -35), INT8_C(-100), INT8_C(  48)),
      simde_mm256_set_epi8(INT8_C( -98), INT8_C(  80), INT8_C( -16), INT8_C(  73),
                           INT8_C( 126), INT8_C(-115), INT8_C(  31), INT8_C(  80),
                           INT8_C( -75), INT8_C( 117), INT8_C( -13), INT8_C( -70),
                           INT8_C(-101), INT8_C( -10), INT8_C(-111), INT8_C(  96),
                           INT8_C( -77), INT8_C(   0), INT8_C(  70), INT8_C(-121),
                           INT8_C(  78), INT8_C(  54), INT8_C(  38), INT8_C(  18),
                           INT8_C( -12), INT8_C(  68), INT8_C(  53), INT8_C(  45),
                           INT8_C(  77), INT8_C( 103), INT8_C( 118), INT8_C( 116)),
      simde_mm256_set_epi8(INT8_C( -75), INT8_C(-127), INT8_C(  -8), INT8_C( -83),
                           INT8_C( -94), INT8_C(-113), INT8_C( 107), INT8_C( -39),
                           INT8_C( -99), INT8_C(  46), INT8_C( -98), INT8_C(  80),
                           INT8_C( -16), INT8_C(  73), INT8_C( 126), INT8_C(-115),
                           INT8_C(  -9), INT8_C( 117), INT8_C( 121), INT8_C( -14),
                           INT8_C( -58), INT8_C(-118), INT8_C( -70), INT8_C( -35),
                           INT8_C(-100), INT8_C(  48), INT8_C( -77), INT8_C(   0),
                           INT8_C(  70), INT8_C(-121), INT8_C(  78), INT8_C(  54)) },
    { simde_mm256_set_epi8(INT8_C(   8), INT8_C(  70), INT8_C(  96), INT8_C(  42),
                           INT8_C(  73), INT8_C( -91), INT8_C( -93), INT8_C( -58),
                           INT8_C( -35), INT8_C( -14), INT8_C( 118), INT8_C(-128),
                           INT8_C( -97), INT8_C(  97), INT8_C(  22), INT8_C(   4),
                           INT8_C(  24), INT8_C( 124), INT8_C( -32), INT8_C( -48),
                           INT8_C( -74), INT8_C(  95), INT8_C(  95), INT8_C( -38),
                           INT8_C(  54), INT8_C( 120), INT8_C( -65), INT8_C( -96),
                           INT8_C( -44), INT8_C( -78), INT8_C( -95), INT8_C(-111)),
      simde_mm256_set_epi8(INT8_C(  66), INT8_C(  48), INT8_C(  60), INT8_C(  -4),
                           INT8_C(  33), INT8_C(  67), INT8_C(  97), INT8_C(  65),
                           INT8_C(  80), INT8_C(-109), INT8_C(  88), INT8_C( -23),
                           INT8_C( 107), INT8_C( -65), INT8_C( -65), INT8_C(  62),
                           INT8_C(  90), INT8_C( 118), INT8_C(  25), INT8_C( 105),
                           INT8_C( 109), INT8_C( -45), INT8_C(   4), INT8_C(-107),
                           INT8_C(  55), INT8_C(-101), INT8_C( -65), INT8_C( 121),
                           INT8_C( -76), INT8_C(  55), INT8_C(   6), INT8_C(  86)),
      simde_mm256_set_epi8(INT8_C( -93), INT8_C( -58), INT8_C( -35), INT8_C( -14),
                           INT8_C( 118), INT8_C(-128), INT8_C( -97), INT8_C(  97),
                           INT8_C(  22), INT8_C(   4), INT8_C(  66), INT8_C(  48),
                           INT8_C(  60), INT8_C(  -4), INT8_C(  33), INT8_C(  67),
                           INT8_C(  95), INT8_C( -38), INT8_C(  54), INT8_C( 120),
                           INT8_C( -65), INT8_C( -96), INT8_C( -44), INT8_C( -78),
                           INT8_C( -95), INT8_C(-111), INT8_C(  90), INT8_C( 118),
                           INT8_C(  25), INT8_C( 105), INT8_C( 109), INT8_C( -45)) },
    { simde_mm256_set_epi8(INT8_C(  -1), INT8_C(  93), INT8_C( 114), INT8_C(  49),
                           INT8_C( 120), INT8_C( -70), INT8_C(-112), INT8_C(  19),
                           INT8_C(  56), INT8_C( -12), INT8_C( -77), INT8_C( -85),
                           INT8_C( -59), INT8_C(  80), INT8_C( -47), INT8_C( -28),
                           INT8_C( -33), INT8_C(  73), INT8_C( -24), INT8_C(-106),
                           INT8_C(-122), INT8_C(-111), INT8_C(  -3), INT8_C(  57),
                           INT8_C(  67), INT8_C( 107), INT8_C( -68), INT8_C(-101),
                           INT8_C(  -9), INT8_C(   5), INT8_C(-124), INT8_C( -69)),
      simde_mm256_set_epi8(INT8_C( -67), INT8_C(  65), INT8_C( -72), INT8_C( -90),
                           INT8_C( -44), INT8_C(   2), INT8_C(  39), INT8_C( -45),
                           INT8_C(  51), INT8_C( -30), INT8_C( -47), INT8_C(   1),
                           INT8_C( -91), INT8_C( -40), INT8_C( -73), INT8_C(  33),
                           INT8_C(-117), INT8_C( -31), INT8_C(-117), INT8_C(  60),
                           INT8_C( -36), INT8_C(-120), INT8_C( -10), INT8_C( -12),
                           INT8_C( -25), INT8_C(-103), INT8_C(  48), INT8_C( -50),
                           INT8_C( 101), INT8_C(  93), INT8_C( -31), INT8_C( -33)),
      simde_mm256_set_epi8(INT8_C(-112), INT8_C(  19), INT8_C(  56), INT8_C( -12),
                           INT8_C( -77), INT8_C( -85), INT8_C( -59), INT8_C(  80),
                           INT8_C( -47), INT8_C( -28), INT8_C( -67), INT8_C(  65),
                           INT8_C( -72), INT8_C( -90), INT8_C( -44), INT8_C(   2),
                           INT8_C(  -3), INT8_C(  57), INT8_C(  67), INT8_C( 107),
                           INT8_C( -68), INT8_C(-101), INT8_C(  -9), INT8_C(   5),
                           INT8_C(-124), INT8_C( -69), INT8_C(-117), INT8_C( -31),
                           INT8_C(-117), INT8_C(  60), INT8_C( -36), INT8_C(-120)) },
    { simde_mm256_set_epi8(INT8_C( 114), INT8_C( -28), INT8_C( -81), INT8_C(-126),
                           INT8_C(-114), INT8_C( -94), INT8_C(-101), INT8_C(  52),
                           INT8_C(  30), INT8_C(  66), INT8_C(-105), INT8_C(  50),
                           INT8_C(  48), INT8_C(  15), INT8_C(   1), INT8_C(-106),
                           INT8_C( -36), INT8_C(  61), INT8_C( -18), INT8_C(   8),
                           INT8_C(  89), INT8_C( -23), INT8_C(  58), INT8_C( -29),
                           INT8_C( 110), INT8_C(  57), INT8_C( -39), INT8_C(   1),
                           INT8_C( -60), INT8_C(  60), INT8_C( -80), INT8_C( -20)),
      simde_mm256_set_epi8(INT8_C( -60), INT8_C(  69), INT8_C( -69), INT8_C( 107),
                           INT8_C(   2), INT8_C( -33), INT8_C(  14), INT8_C(  77),
                           INT8_C(  15), INT8_C(  63), INT8_C(  63), INT8_C( -53),
                           INT8_C(  -9), INT8_C(  76), INT8_C(   7), INT8_C( -76),
                           INT8_C( -23), INT8_C(-107), INT8_C(  84), INT8_C(  37),
                           INT8_C( -18), INT8_C(  47), INT8_C(  58), INT8_C(  31),
                           INT8_C(  69), INT8_C(  12), INT8_C(  46), INT8_C( 101),
                           INT8_C( -38), INT8_C( 117), INT8_C(-113), INT8_C( -36)),
      simde_mm256_set_epi8(INT8_C(-101), INT8_C(  52), INT8_C(  30), INT8_C(  66),
                           INT8_C(-105), INT8_C(  50), INT8_C(  48), INT8_C(  15),
                           INT8_C(   1), INT8_C(-106), INT8_C( -60), INT8_C(  69),
                           INT8_C( -69), INT8_C( 107), INT8_C(   2), INT8_C( -33),
                           INT8_C(  58), INT8_C( -29), INT8_C( 110), INT8_C(  57),
                           INT8_C( -39), INT8_C(   1), INT8_C( -60), INT8_C(  60),
                           INT8_C( -80), INT8_C( -20), INT8_C( -23), INT8_C(-107),
                           INT8_C(  84), INT8_C(  37), INT8_C( -18), INT8_C(  47)) },
    { simde_mm256_set_epi8(INT8_C(  13), INT8_C( -32), INT8_C( -51), INT8_C(  49),
                           INT8_C(  15), INT8_C(  15), INT8_C( -66), INT8_C( -38),
                           INT8_C(  69), INT8_C(   1), INT8_C( -50), INT8_C(-103),
                           INT8_C(  72), INT8_C( -87), INT8_C(-104), INT8_C( -58),
                           INT8_C(  63), INT8_C(-120), INT8_C(  36), INT8_C( -61),
                           INT8_C( 106), INT8_C(  97), INT8_C(-128), INT8_C(  26),
                           INT8_C(-121), INT8_C( -27), INT8_C( 107), INT8_C(-112),
                           INT8_C(  57), INT8_C(  39), INT8_C(  98), INT8_C( 126)),
      simde_mm256_set_epi8(INT8_C(-110), INT8_C(  50), INT8_C( 102), INT8_C( -85),
                           INT8_C( -62), INT8_C(  74), INT8_C( 102), INT8_C(  36),
                           INT8_C( -55), INT8_C(-104), INT8_C(  11), INT8_C( -70),
                           INT8_C( -20), INT8_C(-104), INT8_C( -37), INT8_C( 122),
                           INT8_C( -88), INT8_C(  70), INT8_C(  43), INT8_C( -34),
                           INT8_C(  14), INT8_C(  55), INT8_C( -41), INT8_C(  33),
                           INT8_C(  53), INT8_C(-102), INT8_C(  56), INT8_C(  26),
                           INT8_C( -79), INT8_C( -30), INT8_C(  73), INT8_C( -53)),
      simde_mm256_set_epi8(INT8_C( -66), INT8_C( -38), INT8_C(  69), INT8_C(   1),
                           INT8_C( -50), INT8_C(-103), INT8_C(  72), INT8_C( -87),
                           INT8_C(-104), INT8_C( -58), INT8_C(-110), INT8_C(  50),
                           INT8_C( 102), INT8_C( -85), INT8_C( -62), INT8_C(  74),
                           INT8_C(-128), INT8_C(  26), INT8_C(-121), INT8_C( -27),
                           INT8_C( 107), INT8_C(-112), INT8_C(  57), INT8_C(  39),
                           INT8_C(  98), INT8_C( 126), INT8_C( -88), INT8_C(  70),
                           INT8_C(  43), INT8_C( -34), INT8_C(  14), INT8_C(  55)) },
    { simde_mm256_set_epi8(INT8_C(-103), INT8_C(  23), INT8_C( -90), INT8_C(  43),
                           INT8_C(  -8), INT8_C(  54), INT8_C( -93), INT8_C(  64),
                           INT8_C(-116), INT8_C( -76), INT8_C( -53), INT8_C(  35),
                           INT8_C(  51), INT8_C( -86), INT8_C(   8), INT8_C(  43),
                           INT8_C( -60), INT8_C(-113), INT8_C(  44), INT8_C(-102),
                           INT8_C(  77), INT8_C(  95), INT8_C(  57), INT8_C( 124),
                           INT8_C( -91), INT8_C( -87), INT8_C( -54), INT8_C( -83),
                           INT8_C( 108), INT8_C(  76), INT8_C(  90), INT8_C( -49)),
      simde_mm256_set_epi8(INT8_C( -43), INT8_C(  -5), INT8_C(  94), INT8_C(  76),
                           INT8_C(  -9), INT8_C( 110), INT8_C( -82), INT8_C( 112),
                           INT8_C( -25), INT8_C(  11), INT8_C( -46), INT8_C( -57),
                           INT8_C( -13), INT8_C(-127), INT8_C(  10), INT8_C(-113),
                           INT8_C(  55), INT8_C(  85), INT8_C(  75), INT8_C(  61),
                           INT8_C(  49), INT8_C( -14), INT8_C(  44), INT8_C(-128),
                           INT8_C(-102), INT8_C( -17), INT8_C(  64), INT8_C( -73),
                           INT8_C(  14), INT8_C(  19), INT8_C(  -2), INT8_C(   7)),
      simde_mm256_set_epi8(INT8_C( -93), INT8_C(  64), INT8_C(-116), INT8_C( -76),
                           INT8_C( -53), INT8_C(  35), INT8_C(  51), INT8_C( -86),
                           INT8_C(   8), INT8_C(  43), INT8_C( -43), INT8_C(  -5),
                           INT8_C(  94), INT8_C(  76), INT8_C(  -9), INT8_C( 110),
                           INT8_C(  57), INT8_C( 124), INT8_C( -91), INT8_C( -87),
                           INT8_C( -54), INT8_C( -83), INT8_C( 108), INT8_C(  76),
                           INT8_C(  90), INT8_C( -49), INT8_C(  55), INT8_C(  85),
                           INT8_C(  75), INT8_C(  61), INT8_C(  49), INT8_C( -14)) },
    { simde_mm256_set_epi8(INT8_C( -32), INT8_C( -82), INT8_C(  79), INT8_C(  79),
                           INT8_C( 127), INT8_C(  16), INT8_C(-118), INT8_C( 113),
                           INT8_C( -52), INT8_C( -25), INT8_C(-124), INT8_C( -77),
                           INT8_C( 114), INT8_C(-118), INT8_C( -84), INT8_C(  73),
                           INT8_C( -12), INT8_C( -67), INT8_C(-127), INT8_C( -69),
                           INT8_C(  30), INT8_C(  14), INT8_C( -47), INT8_C(-119),
                           INT8_C( -36), INT8_C( -97), INT8_C( -89), INT8_C(  24),
                           INT8_C( -41), INT8_C( 117), INT8_C(-102), INT8_C(  54)),
      simde_mm256_set_epi8(INT8_C( -66), INT8_C( -50), INT8_C(  39), INT8_C(  30),
                           INT8_C(  53), INT8_C( 108), INT8_C( -71), INT8_C( -62),
                           INT8_C(  58), INT8_C( -69), INT8_C( -39), INT8_C( -28),
                           INT8_C(  58), INT8_C(  54), INT8_C(-117), INT8_C( -49),
                           INT8_C( 126), INT8_C( -71), INT8_C( -39), INT8_C(-120),
                           INT8_C(  88), INT8_C(  41), INT8_C( 127), INT8_C( 111),
                           INT8_C( -32), INT8_C( -18), INT8_C(  12), INT8_C(  97),
                           INT8_C(  83), INT8_C( -96), INT8_C(  13), INT8_C(-101)),
      simde_mm256_set_epi8(INT8_C(-118), INT8_C( 113), INT8_C( -52), INT8_C( -25),
                           INT8_C(-124), INT8_C( -77), INT8_C( 114), INT8_C(-118),
                           INT8_C( -84), INT8_C(  73), INT8_C( -66), INT8_C( -50),
                           INT8_C(  39), INT8_C(  30), INT8_C(  53), INT8_C( 108),
                           INT8_C( -47), INT8_C(-119), INT8_C( -36), INT8_C( -97),
                           INT8_C( -89), INT8_C(  24), INT8_C( -41), INT8_C( 117),
                           INT8_C(-102), INT8_C(  54), INT8_C( 126), INT8_C( -71),
                           INT8_C( -39), INT8_C(-120), INT8_C(  88), INT8_C(  41)) },
    { simde_mm256_set_epi8(INT8_C(-105), INT8_C(   9), INT8_C( -52), INT8_C(  54),
                           INT8_C( -11), INT8_C( -39), INT8_C( -64), INT8_C( -79),
                           INT8_C(  88), INT8_C(  52), INT8_C( -95), INT8_C( -70),
                           INT8_C(  46), INT8_C( 121), INT8_C( -22), INT8_C( 113),
                           INT8_C(  26), INT8_C( 104), INT8_C( -52), INT8_C( 109),
                           INT8_C(   5), INT8_C(  87), INT8_C(  90), INT8_C(  -7),
                           INT8_C( -35), INT8_C(-112), INT8_C(  20), INT8_C(-128),
                           INT8_C( -21), INT8_C( -67), INT8_C(  37), INT8_C( -35)),
      simde_mm256_set_epi8(INT8_C(  66), INT8_C( -23), INT8_C(  45), INT8_C( -38),
                           INT8_C( -94), INT8_C( 119), INT8_C( -23), INT8_C(  70),
                           INT8_C( -75), INT8_C(  25), INT8_C(  79), INT8_C(-101),
                           INT8_C(-122), INT8_C(-107), INT8_C( -10), INT8_C(-109),
                           INT8_C( -96), INT8_C(  45), INT8_C(  31), INT8_C( -60),
                           INT8_C( 100), INT8_C( 115), INT8_C(  79), INT8_C(  38),
                           INT8_C( -35), INT8_C(  57), INT8_C(  13), INT8_C(  93),
                           INT8_C(  54), INT8_C( -61), INT8_C( 101), INT8_C(-113)),
      simde_mm256_set_epi8(INT8_C( -64), INT8_C( -79), INT8_C(  88), INT8_C(  52),
                           INT8_C( -95), INT8_C( -70), INT8_C(  46), INT8_C( 121),
                           INT8_C( -22), INT8_C( 113), INT8_C(  66), INT8_C( -23),
                           INT8_C(  45), INT8_C( -38), INT8_C( -94), INT8_C( 119),
                           INT8_C(  90), INT8_C(  -7), INT8_C( -35), INT8_C(-112),
                           INT8_C(  20), INT8_C(-128), INT8_C( -21), INT8_C( -67),
                           INT8_C(  37), INT8_C( -35), INT8_C( -96), INT8_C(  45),
                           INT8_C(  31), INT8_C( -60), INT8_C( 100), INT8_C( 115)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_alignr_epi8(test_vec[i].a, test_vec[i].b, 10);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_alignr_epi8_case2(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C( 113), INT8_C( -69), INT8_C(  23), INT8_C( -66),
                           INT8_C( 115), INT8_C( -83), INT8_C( -66), INT8_C( -71),
                           INT8_C(  28), INT8_C(  74), INT8_C(  -4), INT8_C(  16),
                           INT8_C(  16), INT8_C( -20), INT8_C(  79), INT8_C( -49),
                           INT8_C(  13), INT8_C(  59), INT8_C( -99), INT8_C(  73),
                           INT8_C(  19), INT8_C(  31), INT8_C( -64), INT8_C( -94),
                           INT8_C( 111), INT8_C( 121), INT8_C( -91), INT8_C( -99),
                           INT8_C(-120), INT8_C(  24), INT8_C(-116), INT8_C( -29)),
      simde_mm256_set_epi8(INT8_C(  19), INT8_C( 117), INT8_C(  83), INT8_C(  54),
                           INT8_C( -84), INT8_C(-110), INT8_C( 115), INT8_C(  25),
                           INT8_C( 122), INT8_C( -20), INT8_C(  49), INT8_C( -87),
                           INT8_C(   9), INT8_C( -79), INT8_C(  28), INT8_C( -93),
                           INT8_C( -97), INT8_C(  38), INT8_C(  85), INT8_C( -70),
                           INT8_C(  96), INT8_C(   7), INT8_C( -55), INT8_C(  -8),
                           INT8_C(  94), INT8_C(  69), INT8_C(  20), INT8_C(  64),
                           INT8_C(  54), INT8_C(  88), INT8_C( -92), INT8_C( -89)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C( 113), INT8_C( -69), INT8_C(  23),
                           INT8_C( -66), INT8_C( 115), INT8_C( -83), INT8_C( -66),
                           INT8_C( -71), INT8_C(  28), INT8_C(  74), INT8_C(  -4),
                           INT8_C(  16), INT8_C(  16), INT8_C( -20), INT8_C(  79),
                           INT8_C(   0), INT8_C(  13), INT8_C(  59), INT8_C( -99),
                           INT8_C(  73), INT8_C(  19), INT8_C(  31), INT8_C( -64),
                           INT8_C( -94), INT8_C( 111), INT8_C( 121), INT8_C( -91),
                           INT8_C( -99), INT8_C(-120), INT8_C(  24), INT8_C(-116)) },
    { simde_mm256_set_epi8(INT8_C(  -7), INT8_C( -66), INT8_C(-120), INT8_C( 103),
                           INT8_C( -48), INT8_C( -55), INT8_C(-109), INT8_C(  52),
                           INT8_C( 103), INT8_C(  30), INT8_C( -21), INT8_C(-107),
                           INT8_C(  14), INT8_C(  -9), INT8_C(  61), INT8_C(-114),
                           INT8_C(-120), INT8_C(-116), INT8_C( -34), INT8_C( -96),
                           INT8_C( 124), INT8_C(  29), INT8_C( -49), INT8_C(  74),
                           INT8_C( -82), INT8_C(  66), INT8_C(  24), INT8_C(  47),
                           INT8_C(  -7), INT8_C( -96), INT8_C(  99), INT8_C( -53)),
      simde_mm256_set_epi8(INT8_C(  77), INT8_C(  25), INT8_C(  25), INT8_C(  69),
                           INT8_C( -34), INT8_C(   2), INT8_C(  12), INT8_C(  -5),
                           INT8_C( -49), INT8_C( -58), INT8_C( -38), INT8_C( -80),
                           INT8_C(  88), INT8_C(  48), INT8_C(  49), INT8_C(  73),
                           INT8_C( 121), INT8_C(  39), INT8_C( -20), INT8_C(  28),
                           INT8_C( 121), INT8_C(   0), INT8_C( -34), INT8_C(  24),
                           INT8_C( -45), INT8_C(-121), INT8_C( -12), INT8_C(  37),
                           INT8_C(  64), INT8_C(  31), INT8_C(  31), INT8_C(  41)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(  -7), INT8_C( -66), INT8_C(-120),
                           INT8_C( 103), INT8_C( -48), INT8_C( -55), INT8_C(-109),
                           INT8_C(  52), INT8_C( 103), INT8_C(  30), INT8_C( -21),
                           INT8_C(-107), INT8_C(  14), INT8_C(  -9), INT8_C(  61),
                           INT8_C(   0), INT8_C(-120), INT8_C(-116), INT8_C( -34),
                           INT8_C( -96), INT8_C( 124), INT8_C(  29), INT8_C( -49),
                           INT8_C(  74), INT8_C( -82), INT8_C(  66), INT8_C(  24),
                           INT8_C(  47), INT8_C(  -7), INT8_C( -96), INT8_C(  99)) },
    { simde_mm256_set_epi8(INT8_C(  -1), INT8_C(  20), INT8_C( -95), INT8_C( 112),
                           INT8_C(  49), INT8_C(-103), INT8_C( 108), INT8_C( -46),
                           INT8_C( -85), INT8_C( -99), INT8_C(  78), INT8_C( 125),
                           INT8_C( -66), INT8_C( -37), INT8_C(  94), INT8_C( 112),
                           INT8_C(-126), INT8_C( -37), INT8_C(-124), INT8_C( -71),
                           INT8_C( -21), INT8_C( -79), INT8_C(  -2), INT8_C(  34),
                           INT8_C( -56), INT8_C(  22), INT8_C(-102), INT8_C(  53),
                           INT8_C( -24), INT8_C( -87), INT8_C(  16), INT8_C( -85)),
      simde_mm256_set_epi8(INT8_C(  66), INT8_C( -80), INT8_C(  10), INT8_C( -95),
                           INT8_C( -33), INT8_C(  65), INT8_C(-115), INT8_C( -97),
                           INT8_C( -96), INT8_C(  17), INT8_C( 123), INT8_C( -81),
                           INT8_C( -25), INT8_C( -92), INT8_C( 110), INT8_C(  74),
                           INT8_C(  58), INT8_C( 126), INT8_C(  24), INT8_C( -87),
                           INT8_C(-124), INT8_C(  -7), INT8_C( -55), INT8_C( 112),
                           INT8_C(  10), INT8_C(-117), INT8_C( -16), INT8_C(  34),
                           INT8_C( -23), INT8_C( 105), INT8_C(  32), INT8_C(-122)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(  20), INT8_C( -95),
                           INT8_C( 112), INT8_C(  49), INT8_C(-103), INT8_C( 108),
                           INT8_C( -46), INT8_C( -85), INT8_C( -99), INT8_C(  78),
                           INT8_C( 125), INT8_C( -66), INT8_C( -37), INT8_C(  94),
                           INT8_C(   0), INT8_C(-126), INT8_C( -37), INT8_C(-124),
                           INT8_C( -71), INT8_C( -21), INT8_C( -79), INT8_C(  -2),
                           INT8_C(  34), INT8_C( -56), INT8_C(  22), INT8_C(-102),
                           INT8_C(  53), INT8_C( -24), INT8_C( -87), INT8_C(  16)) },
    { simde_mm256_set_epi8(INT8_C(  25), INT8_C( -64), INT8_C( 105), INT8_C( -19),
                           INT8_C(-100), INT8_C( 119), INT8_C(  53), INT8_C(-128),
                           INT8_C(  50), INT8_C(-115), INT8_C(  36), INT8_C( 126),
                           INT8_C(   7), INT8_C( -21), INT8_C(-106), INT8_C(-120),
                           INT8_C( 127), INT8_C( -66), INT8_C(  -1), INT8_C( -93),
                           INT8_C(  -5), INT8_C(  40), INT8_C(  78), INT8_C(-119),
                           INT8_C(  82), INT8_C( -17), INT8_C(  18), INT8_C(  47),
                           INT8_C(   8), INT8_C(-108), INT8_C(-114), INT8_C(  65)),
      simde_mm256_set_epi8(INT8_C(-113), INT8_C( 113), INT8_C(-118), INT8_C( -40),
                           INT8_C(-102), INT8_C( -62), INT8_C(  64), INT8_C( -33),
                           INT8_C(  77), INT8_C( -83), INT8_C( -74), INT8_C(  19),
                           INT8_C(  71), INT8_C(  17), INT8_C( -17), INT8_C( -35),
                           INT8_C(  93), INT8_C( -41), INT8_C(  11), INT8_C(   0),
                           INT8_C( -41), INT8_C( -66), INT8_C( -72), INT8_C( 117),
                           INT8_C( 100), INT8_C(-122), INT8_C(  24), INT8_C(-112),
                           INT8_C(  87), INT8_C(  37), INT8_C( -17), INT8_C( -51)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(  25), INT8_C( -64), INT8_C( 105),
                           INT8_C( -19), INT8_C(-100), INT8_C( 119), INT8_C(  53),
                           INT8_C(-128), INT8_C(  50), INT8_C(-115), INT8_C(  36),
                           INT8_C( 126), INT8_C(   7), INT8_C( -21), INT8_C(-106),
                           INT8_C(   0), INT8_C( 127), INT8_C( -66), INT8_C(  -1),
                           INT8_C( -93), INT8_C(  -5), INT8_C(  40), INT8_C(  78),
                           INT8_C(-119), INT8_C(  82), INT8_C( -17), INT8_C(  18),
                           INT8_C(  47), INT8_C(   8), INT8_C(-108), INT8_C(-114)) },
    { simde_mm256_set_epi8(INT8_C( -71), INT8_C(  29), INT8_C( -63), INT8_C( -99),
                           INT8_C(  16), INT8_C(  67), INT8_C(-118), INT8_C(  12),
                           INT8_C( -46), INT8_C( 113), INT8_C(-128), INT8_C(-114),
                           INT8_C( -51), INT8_C( -75), INT8_C(  97), INT8_C( -73),
                           INT8_C(  24), INT8_C( -63), INT8_C(  20), INT8_C( -26),
                           INT8_C( -44), INT8_C(  71), INT8_C( 109), INT8_C( 113),
                           INT8_C(  36), INT8_C( 100), INT8_C(  42), INT8_C( -55),
                           INT8_C(  12), INT8_C( -66), INT8_C( -91), INT8_C(  82)),
      simde_mm256_set_epi8(INT8_C(  81), INT8_C(  93), INT8_C(  76), INT8_C(  23),
                           INT8_C( -32), INT8_C(  31), INT8_C(  25), INT8_C( -76),
                           INT8_C(  38), INT8_C( 114), INT8_C(  74), INT8_C( -11),
                           INT8_C(  55), INT8_C( -33), INT8_C( -78), INT8_C( -96),
                           INT8_C( 106), INT8_C(   1), INT8_C(  32), INT8_C( -46),
                           INT8_C( 124), INT8_C(  89), INT8_C( -80), INT8_C( -22),
                           INT8_C(-117), INT8_C( -99), INT8_C( -39), INT8_C( -63),
                           INT8_C(  12), INT8_C( 106), INT8_C( 120), INT8_C(  64)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C( -71), INT8_C(  29), INT8_C( -63),
                           INT8_C( -99), INT8_C(  16), INT8_C(  67), INT8_C(-118),
                           INT8_C(  12), INT8_C( -46), INT8_C( 113), INT8_C(-128),
                           INT8_C(-114), INT8_C( -51), INT8_C( -75), INT8_C(  97),
                           INT8_C(   0), INT8_C(  24), INT8_C( -63), INT8_C(  20),
                           INT8_C( -26), INT8_C( -44), INT8_C(  71), INT8_C( 109),
                           INT8_C( 113), INT8_C(  36), INT8_C( 100), INT8_C(  42),
                           INT8_C( -55), INT8_C(  12), INT8_C( -66), INT8_C( -91)) },
    { simde_mm256_set_epi8(INT8_C(  91), INT8_C( -47), INT8_C( -11), INT8_C(  95),
                           INT8_C(-101), INT8_C(  71), INT8_C( -99), INT8_C( 119),
                           INT8_C(  53), INT8_C( -40), INT8_C(  93), INT8_C( -71),
                           INT8_C(  53), INT8_C( 101), INT8_C(  91), INT8_C(  38),
                           INT8_C( 101), INT8_C(  10), INT8_C(   7), INT8_C(  37),
                           INT8_C( -66), INT8_C(   4), INT8_C( -96), INT8_C( -47),
                           INT8_C( -72), INT8_C(-123), INT8_C( -18), INT8_C( -16),
                           INT8_C(  57), INT8_C(  -1), INT8_C(-122), INT8_C(  93)),
      simde_mm256_set_epi8(INT8_C( 125), INT8_C( -97), INT8_C( -63), INT8_C(  47),
                           INT8_C(  76), INT8_C( -11), INT8_C(  32), INT8_C(  96),
                           INT8_C( 121), INT8_C( -93), INT8_C(  72), INT8_C( -40),
                           INT8_C( -11), INT8_C( -76), INT8_C(  51), INT8_C(-122),
                           INT8_C( 108), INT8_C( -61), INT8_C(  -9), INT8_C( -38),
                           INT8_C( -65), INT8_C( -53), INT8_C( -36), INT8_C(  43),
                           INT8_C( -52), INT8_C( -14), INT8_C( -72), INT8_C(  79),
                           INT8_C(   4), INT8_C(  96), INT8_C( -88), INT8_C(  40)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(  91), INT8_C( -47), INT8_C( -11),
                           INT8_C(  95), INT8_C(-101), INT8_C(  71), INT8_C( -99),
                           INT8_C( 119), INT8_C(  53), INT8_C( -40), INT8_C(  93),
                           INT8_C( -71), INT8_C(  53), INT8_C( 101), INT8_C(  91),
                           INT8_C(   0), INT8_C( 101), INT8_C(  10), INT8_C(   7),
                           INT8_C(  37), INT8_C( -66), INT8_C(   4), INT8_C( -96),
                           INT8_C( -47), INT8_C( -72), INT8_C(-123), INT8_C( -18),
                           INT8_C( -16), INT8_C(  57), INT8_C(  -1), INT8_C(-122)) },
    { simde_mm256_set_epi8(INT8_C(-125), INT8_C(  50), INT8_C(   9), INT8_C(-114),
                           INT8_C(  12), INT8_C(-115), INT8_C(  20), INT8_C( -81),
                           INT8_C(  65), INT8_C(  -9), INT8_C(   1), INT8_C(  -7),
                           INT8_C(  48), INT8_C(  81), INT8_C( -58), INT8_C( -29),
                           INT8_C(-102), INT8_C(  98), INT8_C( 126), INT8_C(  49),
                           INT8_C(  95), INT8_C(  45), INT8_C( -60), INT8_C( -92),
                           INT8_C(  -7), INT8_C( -56), INT8_C( -47), INT8_C( -85),
                           INT8_C( -93), INT8_C(  33), INT8_C( -91), INT8_C( -34)),
      simde_mm256_set_epi8(INT8_C(  88), INT8_C( -22), INT8_C( -14), INT8_C(  72),
                           INT8_C(-106), INT8_C( -75), INT8_C( -40), INT8_C( -29),
                           INT8_C(  71), INT8_C(  52), INT8_C( -19), INT8_C( -85),
                           INT8_C(  47), INT8_C( -19), INT8_C( -33), INT8_C( -99),
                           INT8_C( -95), INT8_C(-103), INT8_C( 113), INT8_C(  75),
                           INT8_C(  16), INT8_C(-125), INT8_C(  51), INT8_C( -20),
                           INT8_C( -87), INT8_C(  79), INT8_C(  50), INT8_C( -45),
                           INT8_C( -77), INT8_C( -89), INT8_C(  25), INT8_C( -53)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(-125), INT8_C(  50), INT8_C(   9),
                           INT8_C(-114), INT8_C(  12), INT8_C(-115), INT8_C(  20),
                           INT8_C( -81), INT8_C(  65), INT8_C(  -9), INT8_C(   1),
                           INT8_C(  -7), INT8_C(  48), INT8_C(  81), INT8_C( -58),
                           INT8_C(   0), INT8_C(-102), INT8_C(  98), INT8_C( 126),
                           INT8_C(  49), INT8_C(  95), INT8_C(  45), INT8_C( -60),
                           INT8_C( -92), INT8_C(  -7), INT8_C( -56), INT8_C( -47),
                           INT8_C( -85), INT8_C( -93), INT8_C(  33), INT8_C( -91)) },
    { simde_mm256_set_epi8(INT8_C( 108), INT8_C( -54), INT8_C(  79), INT8_C( -34),
                           INT8_C(  79), INT8_C( 114), INT8_C(  95), INT8_C( -13),
                           INT8_C( -32), INT8_C( 106), INT8_C(   6), INT8_C(-103),
                           INT8_C( -17), INT8_C( 126), INT8_C( -76), INT8_C( 100),
                           INT8_C( 103), INT8_C( -73), INT8_C(-120), INT8_C(  89),
                           INT8_C(  92), INT8_C(   1), INT8_C(  24), INT8_C( -42),
                           INT8_C( -87), INT8_C(-120), INT8_C( -69), INT8_C( 118),
                           INT8_C( -71), INT8_C(  35), INT8_C(  31), INT8_C( -27)),
      simde_mm256_set_epi8(INT8_C( 106), INT8_C(  34), INT8_C( -93), INT8_C( -41),
                           INT8_C(  92), INT8_C(  50), INT8_C(-109), INT8_C(  24),
                           INT8_C(  49), INT8_C( -59), INT8_C( -13), INT8_C(  39),
                           INT8_C( 111), INT8_C( -38), INT8_C(  26), INT8_C(  -9),
                           INT8_C(-106), INT8_C(-118), INT8_C( 104), INT8_C( -38),
                           INT8_C( 127), INT8_C( -21), INT8_C(  72), INT8_C(-105),
                           INT8_C( 100), INT8_C(  65), INT8_C(  70), INT8_C(-111),
                           INT8_C(  93), INT8_C(-113), INT8_C( -69), INT8_C( -81)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C( 108), INT8_C( -54), INT8_C(  79),
                           INT8_C( -34), INT8_C(  79), INT8_C( 114), INT8_C(  95),
                           INT8_C( -13), INT8_C( -32), INT8_C( 106), INT8_C(   6),
                           INT8_C(-103), INT8_C( -17), INT8_C( 126), INT8_C( -76),
                           INT8_C(   0), INT8_C( 103), INT8_C( -73), INT8_C(-120),
                           INT8_C(  89), INT8_C(  92), INT8_C(   1), INT8_C(  24),
                           INT8_C( -42), INT8_C( -87), INT8_C(-120), INT8_C( -69),
                           INT8_C( 118), INT8_C( -71), INT8_C(  35), INT8_C(  31)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_alignr_epi8(test_vec[i].a, test_vec[i].b, 17);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_alignr_epi8_case3(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C(  57), INT8_C( -47), INT8_C( -81), INT8_C( -95),
                           INT8_C(-100), INT8_C( -69), INT8_C( -75), INT8_C(-127),
                           INT8_C(  -8), INT8_C( -83), INT8_C( -94), INT8_C(-113),
                           INT8_C( 107), INT8_C( -39), INT8_C( -99), INT8_C(  46),
                           INT8_C( -61), INT8_C( -72), INT8_C(  -5), INT8_C(-126),
                           INT8_C( 113), INT8_C(-120), INT8_C(  -9), INT8_C( 117),
                           INT8_C( 121), INT8_C( -14), INT8_C( -58), INT8_C(-118),
                           INT8_C( -70), INT8_C( -35), INT8_C(-100), INT8_C(  48)),
      simde_mm256_set_epi8(INT8_C( -98), INT8_C(  80), INT8_C( -16), INT8_C(  73),
                           INT8_C( 126), INT8_C(-115), INT8_C(  31), INT8_C(  80),
                           INT8_C( -75), INT8_C( 117), INT8_C( -13), INT8_C( -70),
                           INT8_C(-101), INT8_C( -10), INT8_C(-111), INT8_C(  96),
                           INT8_C( -77), INT8_C(   0), INT8_C(  70), INT8_C(-121),
                           INT8_C(  78), INT8_C(  54), INT8_C(  38), INT8_C(  18),
                           INT8_C( -12), INT8_C(  68), INT8_C(  53), INT8_C(  45),
                           INT8_C(  77), INT8_C( 103), INT8_C( 118), INT8_C( 116)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  57), INT8_C( -47),
                           INT8_C( -81), INT8_C( -95), INT8_C(-100), INT8_C( -69),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( -61), INT8_C( -72),
                           INT8_C(  -5), INT8_C(-126), INT8_C( 113), INT8_C(-120)) },
    { simde_mm256_set_epi8(INT8_C(   8), INT8_C(  70), INT8_C(  96), INT8_C(  42),
                           INT8_C(  73), INT8_C( -91), INT8_C( -93), INT8_C( -58),
                           INT8_C( -35), INT8_C( -14), INT8_C( 118), INT8_C(-128),
                           INT8_C( -97), INT8_C(  97), INT8_C(  22), INT8_C(   4),
                           INT8_C(  24), INT8_C( 124), INT8_C( -32), INT8_C( -48),
                           INT8_C( -74), INT8_C(  95), INT8_C(  95), INT8_C( -38),
                           INT8_C(  54), INT8_C( 120), INT8_C( -65), INT8_C( -96),
                           INT8_C( -44), INT8_C( -78), INT8_C( -95), INT8_C(-111)),
      simde_mm256_set_epi8(INT8_C(  66), INT8_C(  48), INT8_C(  60), INT8_C(  -4),
                           INT8_C(  33), INT8_C(  67), INT8_C(  97), INT8_C(  65),
                           INT8_C(  80), INT8_C(-109), INT8_C(  88), INT8_C( -23),
                           INT8_C( 107), INT8_C( -65), INT8_C( -65), INT8_C(  62),
                           INT8_C(  90), INT8_C( 118), INT8_C(  25), INT8_C( 105),
                           INT8_C( 109), INT8_C( -45), INT8_C(   4), INT8_C(-107),
                           INT8_C(  55), INT8_C(-101), INT8_C( -65), INT8_C( 121),
                           INT8_C( -76), INT8_C(  55), INT8_C(   6), INT8_C(  86)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   8), INT8_C(  70),
                           INT8_C(  96), INT8_C(  42), INT8_C(  73), INT8_C( -91),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  24), INT8_C( 124),
                           INT8_C( -32), INT8_C( -48), INT8_C( -74), INT8_C(  95)) },
    { simde_mm256_set_epi8(INT8_C(  -1), INT8_C(  93), INT8_C( 114), INT8_C(  49),
                           INT8_C( 120), INT8_C( -70), INT8_C(-112), INT8_C(  19),
                           INT8_C(  56), INT8_C( -12), INT8_C( -77), INT8_C( -85),
                           INT8_C( -59), INT8_C(  80), INT8_C( -47), INT8_C( -28),
                           INT8_C( -33), INT8_C(  73), INT8_C( -24), INT8_C(-106),
                           INT8_C(-122), INT8_C(-111), INT8_C(  -3), INT8_C(  57),
                           INT8_C(  67), INT8_C( 107), INT8_C( -68), INT8_C(-101),
                           INT8_C(  -9), INT8_C(   5), INT8_C(-124), INT8_C( -69)),
      simde_mm256_set_epi8(INT8_C( -67), INT8_C(  65), INT8_C( -72), INT8_C( -90),
                           INT8_C( -44), INT8_C(   2), INT8_C(  39), INT8_C( -45),
                           INT8_C(  51), INT8_C( -30), INT8_C( -47), INT8_C(   1),
                           INT8_C( -91), INT8_C( -40), INT8_C( -73), INT8_C(  33),
                           INT8_C(-117), INT8_C( -31), INT8_C(-117), INT8_C(  60),
                           INT8_C( -36), INT8_C(-120), INT8_C( -10), INT8_C( -12),
                           INT8_C( -25), INT8_C(-103), INT8_C(  48), INT8_C( -50),
                           INT8_C( 101), INT8_C(  93), INT8_C( -31), INT8_C( -33)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  93),
                           INT8_C( 114), INT8_C(  49), INT8_C( 120), INT8_C( -70),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( -33), INT8_C(  73),
                           INT8_C( -24), INT8_C(-106), INT8_C(-122), INT8_C(-111)) },
    { simde_mm256_set_epi8(INT8_C( 114), INT8_C( -28), INT8_C( -81), INT8_C(-126),
                           INT8_C(-114), INT8_C( -94), INT8_C(-101), INT8_C(  52),
                           INT8_C(  30), INT8_C(  66), INT8_C(-105), INT8_C(  50),
                           INT8_C(  48), INT8_C(  15), INT8_C(   1), INT8_C(-106),
                           INT8_C( -36), INT8_C(  61), INT8_C( -18), INT8_C(   8),
                           INT8_C(  89), INT8_C( -23), INT8_C(  58), INT8_C( -29),
                           INT8_C( 110), INT8_C(  57), INT8_C( -39), INT8_C(   1),
                           INT8_C( -60), INT8_C(  60), INT8_C( -80), INT8_C( -20)),
      simde_mm256_set_epi8(INT8_C( -60), INT8_C(  69), INT8_C( -69), INT8_C( 107),
                           INT8_C(   2), INT8_C( -33), INT8_C(  14), INT8_C(  77),
                           INT8_C(  15), INT8_C(  63), INT8_C(  63), INT8_C( -53),
                           INT8_C(  -9), INT8_C(  76), INT8_C(   7), INT8_C( -76),
                           INT8_C( -23), INT8_C(-107), INT8_C(  84), INT8_C(  37),
                           INT8_C( -18), INT8_C(  47), INT8_C(  58), INT8_C(  31),
                           INT8_C(  69), INT8_C(  12), INT8_C(  46), INT8_C( 101),
                           INT8_C( -38), INT8_C( 117), INT8_C(-113), INT8_C( -36)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( 114), INT8_C( -28),
                           INT8_C( -81), INT8_C(-126), INT8_C(-114), INT8_C( -94),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( -36), INT8_C(  61),
                           INT8_C( -18), INT8_C(   8), INT8_C(  89), INT8_C( -23)) },
    { simde_mm256_set_epi8(INT8_C(  13), INT8_C( -32), INT8_C( -51), INT8_C(  49),
                           INT8_C(  15), INT8_C(  15), INT8_C( -66), INT8_C( -38),
                           INT8_C(  69), INT8_C(   1), INT8_C( -50), INT8_C(-103),
                           INT8_C(  72), INT8_C( -87), INT8_C(-104), INT8_C( -58),
                           INT8_C(  63), INT8_C(-120), INT8_C(  36), INT8_C( -61),
                           INT8_C( 106), INT8_C(  97), INT8_C(-128), INT8_C(  26),
                           INT8_C(-121), INT8_C( -27), INT8_C( 107), INT8_C(-112),
                           INT8_C(  57), INT8_C(  39), INT8_C(  98), INT8_C( 126)),
      simde_mm256_set_epi8(INT8_C(-110), INT8_C(  50), INT8_C( 102), INT8_C( -85),
                           INT8_C( -62), INT8_C(  74), INT8_C( 102), INT8_C(  36),
                           INT8_C( -55), INT8_C(-104), INT8_C(  11), INT8_C( -70),
                           INT8_C( -20), INT8_C(-104), INT8_C( -37), INT8_C( 122),
                           INT8_C( -88), INT8_C(  70), INT8_C(  43), INT8_C( -34),
                           INT8_C(  14), INT8_C(  55), INT8_C( -41), INT8_C(  33),
                           INT8_C(  53), INT8_C(-102), INT8_C(  56), INT8_C(  26),
                           INT8_C( -79), INT8_C( -30), INT8_C(  73), INT8_C( -53)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  13), INT8_C( -32),
                           INT8_C( -51), INT8_C(  49), INT8_C(  15), INT8_C(  15),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  63), INT8_C(-120),
                           INT8_C(  36), INT8_C( -61), INT8_C( 106), INT8_C(  97)) },
    { simde_mm256_set_epi8(INT8_C(-103), INT8_C(  23), INT8_C( -90), INT8_C(  43),
                           INT8_C(  -8), INT8_C(  54), INT8_C( -93), INT8_C(  64),
                           INT8_C(-116), INT8_C( -76), INT8_C( -53), INT8_C(  35),
                           INT8_C(  51), INT8_C( -86), INT8_C(   8), INT8_C(  43),
                           INT8_C( -60), INT8_C(-113), INT8_C(  44), INT8_C(-102),
                           INT8_C(  77), INT8_C(  95), INT8_C(  57), INT8_C( 124),
                           INT8_C( -91), INT8_C( -87), INT8_C( -54), INT8_C( -83),
                           INT8_C( 108), INT8_C(  76), INT8_C(  90), INT8_C( -49)),
      simde_mm256_set_epi8(INT8_C( -43), INT8_C(  -5), INT8_C(  94), INT8_C(  76),
                           INT8_C(  -9), INT8_C( 110), INT8_C( -82), INT8_C( 112),
                           INT8_C( -25), INT8_C(  11), INT8_C( -46), INT8_C( -57),
                           INT8_C( -13), INT8_C(-127), INT8_C(  10), INT8_C(-113),
                           INT8_C(  55), INT8_C(  85), INT8_C(  75), INT8_C(  61),
                           INT8_C(  49), INT8_C( -14), INT8_C(  44), INT8_C(-128),
                           INT8_C(-102), INT8_C( -17), INT8_C(  64), INT8_C( -73),
                           INT8_C(  14), INT8_C(  19), INT8_C(  -2), INT8_C(   7)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(-103), INT8_C(  23),
                           INT8_C( -90), INT8_C(  43), INT8_C(  -8), INT8_C(  54),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( -60), INT8_C(-113),
                           INT8_C(  44), INT8_C(-102), INT8_C(  77), INT8_C(  95)) },
    { simde_mm256_set_epi8(INT8_C( -32), INT8_C( -82), INT8_C(  79), INT8_C(  79),
                           INT8_C( 127), INT8_C(  16), INT8_C(-118), INT8_C( 113),
                           INT8_C( -52), INT8_C( -25), INT8_C(-124), INT8_C( -77),
                           INT8_C( 114), INT8_C(-118), INT8_C( -84), INT8_C(  73),
                           INT8_C( -12), INT8_C( -67), INT8_C(-127), INT8_C( -69),
                           INT8_C(  30), INT8_C(  14), INT8_C( -47), INT8_C(-119),
                           INT8_C( -36), INT8_C( -97), INT8_C( -89), INT8_C(  24),
                           INT8_C( -41), INT8_C( 117), INT8_C(-102), INT8_C(  54)),
      simde_mm256_set_epi8(INT8_C( -66), INT8_C( -50), INT8_C(  39), INT8_C(  30),
                           INT8_C(  53), INT8_C( 108), INT8_C( -71), INT8_C( -62),
                           INT8_C(  58), INT8_C( -69), INT8_C( -39), INT8_C( -28),
                           INT8_C(  58), INT8_C(  54), INT8_C(-117), INT8_C( -49),
                           INT8_C( 126), INT8_C( -71), INT8_C( -39), INT8_C(-120),
                           INT8_C(  88), INT8_C(  41), INT8_C( 127), INT8_C( 111),
                           INT8_C( -32), INT8_C( -18), INT8_C(  12), INT8_C(  97),
                           INT8_C(  83), INT8_C( -96), INT8_C(  13), INT8_C(-101)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( -32), INT8_C( -82),
                           INT8_C(  79), INT8_C(  79), INT8_C( 127), INT8_C(  16),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( -12), INT8_C( -67),
                           INT8_C(-127), INT8_C( -69), INT8_C(  30), INT8_C(  14)) },
    { simde_mm256_set_epi8(INT8_C(-105), INT8_C(   9), INT8_C( -52), INT8_C(  54),
                           INT8_C( -11), INT8_C( -39), INT8_C( -64), INT8_C( -79),
                           INT8_C(  88), INT8_C(  52), INT8_C( -95), INT8_C( -70),
                           INT8_C(  46), INT8_C( 121), INT8_C( -22), INT8_C( 113),
                           INT8_C(  26), INT8_C( 104), INT8_C( -52), INT8_C( 109),
                           INT8_C(   5), INT8_C(  87), INT8_C(  90), INT8_C(  -7),
                           INT8_C( -35), INT8_C(-112), INT8_C(  20), INT8_C(-128),
                           INT8_C( -21), INT8_C( -67), INT8_C(  37), INT8_C( -35)),
      simde_mm256_set_epi8(INT8_C(  66), INT8_C( -23), INT8_C(  45), INT8_C( -38),
                           INT8_C( -94), INT8_C( 119), INT8_C( -23), INT8_C(  70),
                           INT8_C( -75), INT8_C(  25), INT8_C(  79), INT8_C(-101),
                           INT8_C(-122), INT8_C(-107), INT8_C( -10), INT8_C(-109),
                           INT8_C( -96), INT8_C(  45), INT8_C(  31), INT8_C( -60),
                           INT8_C( 100), INT8_C( 115), INT8_C(  79), INT8_C(  38),
                           INT8_C( -35), INT8_C(  57), INT8_C(  13), INT8_C(  93),
                           INT8_C(  54), INT8_C( -61), INT8_C( 101), INT8_C(-113)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(-105), INT8_C(   9),
                           INT8_C( -52), INT8_C(  54), INT8_C( -11), INT8_C( -39),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  26), INT8_C( 104),
                           INT8_C( -52), INT8_C( 109), INT8_C(   5), INT8_C(  87)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_alignr_epi8(test_vec[i].a, test_vec[i].b, 26);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_and_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C( 8722470578646828517), INT64_C(  891261850847437783),
                             INT64_C( 8698554819020653857), INT64_C(-7282900013878242954)),
      simde_mm256_set_epi64x(INT64_C(-8128142018056442141), INT64_C( 5559182722028422309),
                             INT64_C( 2093267872519066825), INT64_C(-7117023562774970023)),
      simde_mm256_set_epi64x(INT64_C(  648519197013312737), INT64_C(  866420841735143557),
                             INT64_C( 1730587322060899329), INT64_C(-7482378910948097712)) },
    { simde_mm256_set_epi64x(INT64_C(-2297219683620407228), INT64_C(-2314825045857877411),
                             INT64_C(-2223407797787304327), INT64_C( 5408595704702705619)),
      simde_mm256_set_epi64x(INT64_C( 1902387556947256757), INT64_C(-4636290958455233996),
                             INT64_C( -193279292138890017), INT64_C( 2387678637527501964)),
      simde_mm256_set_epi64x(INT64_C(    1867272746704900), INT64_C(-6944527661819330028),
                             INT64_C(-2233693047608222631), INT64_C(   72674428659436672)) },
    { simde_mm256_set_epi64x(INT64_C(-8083909718117301567), INT64_C(   11995607010100125),
                             INT64_C(-6068617776224060223), INT64_C(-6387203967446836987)),
      simde_mm256_set_epi64x(INT64_C(-8320376883848651160), INT64_C(-4950145821323384534),
                             INT64_C(-7969688999974624617), INT64_C(  659904372446782737)),
      simde_mm256_set_epi64x(INT64_C(-8322647438183611840), INT64_C(    2406350531494152),
                             INT64_C(-9131628786599059327), INT64_C(   74330855942160641)) },
    { simde_mm256_set_epi64x(INT64_C(-7862557356832127783), INT64_C(-5197238245936512816),
                             INT64_C(-1440736387308233171), INT64_C( -422437923560182700)),
      simde_mm256_set_epi64x(INT64_C( 4501573497311276896), INT64_C( 1568099047173454230),
                             INT64_C( 6784671475384752865), INT64_C(-5901872067663085826)),
      simde_mm256_set_epi64x(INT64_C( 1324204786773460032), INT64_C( 1568098471546732688),
                             INT64_C( 5476791399028365857), INT64_C(-6196932668584612780)) },
    { simde_mm256_set_epi64x(INT64_C(  -83457062575009429), INT64_C(-7222721162513873213),
                             INT64_C( 8275972355230696496), INT64_C( 5685146925209815999)),
      simde_mm256_set_epi64x(INT64_C( 7621095561231011691), INT64_C(-1384347240916299959),
                             INT64_C( 8784701942784527649), INT64_C(-6329984144489188000)),
      simde_mm256_set_epi64x(INT64_C( 7549018173429252459), INT64_C(-8592431562369268159),
                             INT64_C( 8126746635764630560), INT64_C(  586910516468318496)) },
    { simde_mm256_set_epi64x(INT64_C( 5973184558080946927), INT64_C(-1786695518880322601),
                             INT64_C(  564422817571527071), INT64_C( 4038585732338755869)),
      simde_mm256_set_epi64x(INT64_C(-8901168232869945121), INT64_C( 8118630853720063073),
                             INT64_C( -228868271804772649), INT64_C(-6456700929251086932)),
      simde_mm256_set_epi64x(INT64_C(   27024505729917135), INT64_C( 6926573216261613633),
                             INT64_C(  346814025888696471), INT64_C( 2306177340255840524)) },
    { simde_mm256_set_epi64x(INT64_C( 4967668340414178010), INT64_C(-2410168209476403592),
                             INT64_C(-3019436090811439415), INT64_C(-6965119139859890192)),
      simde_mm256_set_epi64x(INT64_C(-5120337331222163918), INT64_C(-1589564432494918546),
                             INT64_C( 5292723257474752308), INT64_C( 2511807878775255697)),
      simde_mm256_set_epi64x(INT64_C(   67729921108361746), INT64_C(-3999169530918599576),
                             INT64_C( 4616337787987166720), INT64_C(  167381957966049936)) },
    { simde_mm256_set_epi64x(INT64_C(-6179811667909625694), INT64_C(-2471055444546593648),
                             INT64_C( 7540412455883833292), INT64_C( 6654843089135720963)),
      simde_mm256_set_epi64x(INT64_C( -939588147635733509), INT64_C(-1340596046637757449),
                             INT64_C(-1662948605324253370), INT64_C(  817158485966988858)),
      simde_mm256_set_epi64x(INT64_C(-6758530821969135454), INT64_C(-3664509346923870064),
                             INT64_C( 7540157231680104260), INT64_C(  599541701488411138)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_and_si256(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_andnot_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
   { simde_mm256_set_epi32(INT32_C( 1296069903), INT32_C( -401713319), INT32_C( -398512257), INT32_C( 1831595067),
                            INT32_C(  -79935516), INT32_C(-1180021826), INT32_C( 1322035843), INT32_C( 1532358492)),
      simde_mm256_set_epi32(INT32_C( 1994603249), INT32_C(-1155877896), INT32_C( 1480474617), INT32_C( 1055447888),
                            INT32_C( 1247599905), INT32_C( -290225910), INT32_C(  -75325456), INT32_C( 1443351725)),
      simde_mm256_set_epi32(INT32_C(  849545968), INT32_C(  319856800), INT32_C(  268439680), INT32_C(  314577728),
                            INT32_C(    4233217), INT32_C( 1175552000), INT32_C(-1325263504), INT32_C(   67240097)) },
    { simde_mm256_set_epi32(INT32_C(  751085853), INT32_C(  464664830), INT32_C( 1171943738), INT32_C(  238039385),
                            INT32_C(  447621112), INT32_C( -944668210), INT32_C(  -26835475), INT32_C( -497913063)),
      simde_mm256_set_epi32(INT32_C( -346681351), INT32_C( 1057375625), INT32_C(-1640028951), INT32_C( 1365052187),
                            INT32_C( 1146265967), INT32_C( -337636497), INT32_C(-2119055512), INT32_C(-1077772260)),
      simde_mm256_set_epi32(INT32_C(-1022228768), INT32_C(  604259585), INT32_C(-1708849983), INT32_C( 1364003330),
                            INT32_C( 1146126343), INT32_C(  675287585), INT32_C(   26296832), INT32_C(  494960644)) },
    { simde_mm256_set_epi32(INT32_C( 1652916374), INT32_C(  430611066), INT32_C(-1135996673), INT32_C( 1059116837),
                            INT32_C(  642663426), INT32_C(-2076745619), INT32_C(-1526373034), INT32_C(-1938949753)),
      simde_mm256_set_epi32(INT32_C(   21997480), INT32_C( 2006437191), INT32_C(-1106118986), INT32_C( -552923366),
                            INT32_C( 1259738142), INT32_C(-1272739174), INT32_C(  256185924), INT32_C(  828965431)),
      simde_mm256_set_epi32(INT32_C(   21636904), INT32_C( 1712669957), INT32_C(   34727424), INT32_C(-1073018854),
                            INT32_C( 1225789468), INT32_C(  805341842), INT32_C(  171971072), INT32_C(  822084144)) },
    { simde_mm256_set_epi32(INT32_C( 1850172884), INT32_C(  347371552), INT32_C(-2124471172), INT32_C(-1122146912),
                            INT32_C(-2084330368), INT32_C(-1474045155), INT32_C(-1097896595), INT32_C( -157279178)),
      simde_mm256_set_epi32(INT32_C( 1150160686), INT32_C( 1294066543), INT32_C(-1264650397), INT32_C( -958193094),
                            INT32_C( 1906124487), INT32_C(-1106662757), INT32_C(-1281709058), INT32_C(-1981986383)),
      simde_mm256_set_epi32(INT32_C(    8915498), INT32_C( 1224835919), INT32_C(  880857859), INT32_C( 1122107930),
                            INT32_C( 1880883783), INT32_C(  369631362), INT32_C(   17859218), INT32_C(  157106561)) },
    { simde_mm256_set_epi32(INT32_C( 1083224354), INT32_C(-2047292862), INT32_C(-1063111811), INT32_C(  679392193),
                            INT32_C(-1649939198), INT32_C(  165669772), INT32_C(-1686920475), INT32_C( -669365464)),
      simde_mm256_set_epi32(INT32_C(    1910614), INT32_C( 1742547828), INT32_C( 1824050734), INT32_C( 1245292821),
                            INT32_C( 1373149632), INT32_C(-1705573089), INT32_C(-2120011139), INT32_C( 1659478998)),
      simde_mm256_set_epi32(INT32_C(     853588), INT32_C( 1644503348), INT32_C(  739822594), INT32_C( 1107363860),
                            INT32_C( 1079513280), INT32_C(-1845492717), INT32_C(    8392728), INT32_C(  585212118)) },
    { simde_mm256_set_epi32(INT32_C( -215087200), INT32_C(  439485206), INT32_C(   52069439), INT32_C( 1985678052),
                            INT32_C(  236126003), INT32_C( 1543880509), INT32_C(-1076073317), INT32_C(  911942733)),
      simde_mm256_set_epi32(INT32_C(  289944943), INT32_C( 1791469709), INT32_C(-1356404241), INT32_C(-2084942503),
                            INT32_C(-1405988531), INT32_C(   52512230), INT32_C( -191001241), INT32_C(   11336758)),
      simde_mm256_set_epi32(INT32_C(    4206671), INT32_C( 1623566473), INT32_C(-1406899776), INT32_C(-2120202983),
                            INT32_C(-1608515508), INT32_C(   52445378), INT32_C( 1073840484), INT32_C(   10803250)) },
    { simde_mm256_set_epi32(INT32_C( -255265247), INT32_C(  884745637), INT32_C(-1256896434), INT32_C( 1712403469),
                            INT32_C(-1168205511), INT32_C( 1417172277), INT32_C(    6510726), INT32_C( 1896753771)),
      simde_mm256_set_epi32(INT32_C( 1154369104), INT32_C( 1355111439), INT32_C(  107073276), INT32_C( 1081379485),
                            INT32_C( -791672049), INT32_C(-1430371667), INT32_C( 1251404018), INT32_C(  686255615)),
      simde_mm256_set_epi32(INT32_C(   67502160), INT32_C( 1078024202), INT32_C(   39880368), INT32_C(    6589072),
                            INT32_C( 1082130950), INT32_C(-1434058104), INT32_C( 1251254384), INT32_C(  148981140)) },
    { simde_mm256_set_epi32(INT32_C( 1670586553), INT32_C( 1338043318), INT32_C(-2053008274), INT32_C( 1109326069),
                            INT32_C(  858036123), INT32_C(  201080868), INT32_C( -768148447), INT32_C( 1651890892)),
      simde_mm256_set_epi32(INT32_C( 1950737481), INT32_C(-1368157265), INT32_C(  504476696), INT32_C(-1751057511),
                            INT32_C(-1576762410), INT32_C( 1167387907), INT32_C(  398094763), INT32_C( 1151527447)),
      simde_mm256_set_epi32(INT32_C(  340051008), INT32_C(-1607266295), INT32_C(  437264400), INT32_C(-1784675576),
                            INT32_C(-2147483580), INT32_C( 1140894979), INT32_C(   92799370), INT32_C(   75636755)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_andnot_si256(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_adds_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu8(UINT8_C(253), UINT8_C(134), UINT8_C(240), UINT8_C(121),
                             UINT8_C(194), UINT8_C(  6), UINT8_C( 90), UINT8_C(185),
                             UINT8_C( 52), UINT8_C(188), UINT8_C(255), UINT8_C(213),
                             UINT8_C( 70), UINT8_C(140), UINT8_C( 59), UINT8_C(206),
                             UINT8_C( 91), UINT8_C( 56), UINT8_C(139), UINT8_C( 19),
                             UINT8_C( 62), UINT8_C( 91), UINT8_C( 24), UINT8_C( 86),
                             UINT8_C(156), UINT8_C( 89), UINT8_C( 98), UINT8_C(113),
                             UINT8_C(237), UINT8_C(  2), UINT8_C(237), UINT8_C(177)),
      simde_x_mm256_set_epu8(UINT8_C(213), UINT8_C( 63), UINT8_C( 15), UINT8_C(166),
                             UINT8_C( 63), UINT8_C(196), UINT8_C(141), UINT8_C(108),
                             UINT8_C( 47), UINT8_C(216), UINT8_C( 17), UINT8_C(218),
                             UINT8_C(111), UINT8_C(130), UINT8_C(  1), UINT8_C(159),
                             UINT8_C( 50), UINT8_C(145), UINT8_C(171), UINT8_C( 70),
                             UINT8_C( 84), UINT8_C(160), UINT8_C(222), UINT8_C(215),
                             UINT8_C( 44), UINT8_C(139), UINT8_C( 68), UINT8_C( 49),
                             UINT8_C(218), UINT8_C( 62), UINT8_C(151), UINT8_C(225)),
      simde_x_mm256_set_epu8(UINT8_C(255), UINT8_C(197), UINT8_C(255), UINT8_C(255),
                             UINT8_C(255), UINT8_C(202), UINT8_C(231), UINT8_C(255),
                             UINT8_C( 99), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                             UINT8_C(181), UINT8_C(255), UINT8_C( 60), UINT8_C(255),
                             UINT8_C(141), UINT8_C(201), UINT8_C(255), UINT8_C( 89),
                             UINT8_C(146), UINT8_C(251), UINT8_C(246), UINT8_C(255),
                             UINT8_C(200), UINT8_C(228), UINT8_C(166), UINT8_C(162),
                             UINT8_C(255), UINT8_C( 64), UINT8_C(255), UINT8_C(255)) },
    { simde_x_mm256_set_epu8(UINT8_C( 46), UINT8_C( 60), UINT8_C( 83), UINT8_C( 69),
                             UINT8_C( 75), UINT8_C( 52), UINT8_C(182), UINT8_C( 56),
                             UINT8_C( 10), UINT8_C(180), UINT8_C(245), UINT8_C(208),
                             UINT8_C(165), UINT8_C( 77), UINT8_C(214), UINT8_C(172),
                             UINT8_C( 90), UINT8_C( 10), UINT8_C(190), UINT8_C(204),
                             UINT8_C(174), UINT8_C(200), UINT8_C( 75), UINT8_C(188),
                             UINT8_C(215), UINT8_C( 51), UINT8_C(188), UINT8_C( 47),
                             UINT8_C( 17), UINT8_C(116), UINT8_C(116), UINT8_C(103)),
      simde_x_mm256_set_epu8(UINT8_C( 76), UINT8_C( 23), UINT8_C( 40), UINT8_C(  7),
                             UINT8_C( 32), UINT8_C(238), UINT8_C(187), UINT8_C( 34),
                             UINT8_C(130), UINT8_C(185), UINT8_C(135), UINT8_C( 64),
                             UINT8_C(167), UINT8_C(215), UINT8_C(226), UINT8_C(221),
                             UINT8_C( 22), UINT8_C( 21), UINT8_C( 86), UINT8_C(166),
                             UINT8_C( 38), UINT8_C( 88), UINT8_C(194), UINT8_C( 97),
                             UINT8_C( 79), UINT8_C(177), UINT8_C(251), UINT8_C(218),
                             UINT8_C( 76), UINT8_C(121), UINT8_C(164), UINT8_C( 80)),
      simde_x_mm256_set_epu8(UINT8_C(122), UINT8_C( 83), UINT8_C(123), UINT8_C( 76),
                             UINT8_C(107), UINT8_C(255), UINT8_C(255), UINT8_C( 90),
                             UINT8_C(140), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                             UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                             UINT8_C(112), UINT8_C( 31), UINT8_C(255), UINT8_C(255),
                             UINT8_C(212), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                             UINT8_C(255), UINT8_C(228), UINT8_C(255), UINT8_C(255),
                             UINT8_C( 93), UINT8_C(237), UINT8_C(255), UINT8_C(183)) },
    { simde_x_mm256_set_epu8(UINT8_C( 62), UINT8_C(125), UINT8_C(167), UINT8_C( 69),
                             UINT8_C(185), UINT8_C(211), UINT8_C(194), UINT8_C( 87),
                             UINT8_C( 42), UINT8_C( 67), UINT8_C(196), UINT8_C(131),
                             UINT8_C( 56), UINT8_C(103), UINT8_C( 93), UINT8_C(201),
                             UINT8_C(200), UINT8_C( 67), UINT8_C(  5), UINT8_C(251),
                             UINT8_C(171), UINT8_C(  0), UINT8_C(242), UINT8_C(219),
                             UINT8_C( 52), UINT8_C( 56), UINT8_C(153), UINT8_C(193),
                             UINT8_C(206), UINT8_C(184), UINT8_C(179), UINT8_C(112)),
      simde_x_mm256_set_epu8(UINT8_C(  3), UINT8_C( 94), UINT8_C(  2), UINT8_C( 80),
                             UINT8_C( 75), UINT8_C( 54), UINT8_C(116), UINT8_C(175),
                             UINT8_C(133), UINT8_C(183), UINT8_C(131), UINT8_C(  7),
                             UINT8_C( 65), UINT8_C( 80), UINT8_C(192), UINT8_C( 97),
                             UINT8_C(148), UINT8_C(232), UINT8_C(135), UINT8_C(251),
                             UINT8_C(194), UINT8_C( 84), UINT8_C(121), UINT8_C( 35),
                             UINT8_C( 55), UINT8_C(172), UINT8_C( 74), UINT8_C( 18),
                             UINT8_C( 14), UINT8_C( 11), UINT8_C( 86), UINT8_C(161)),
      simde_x_mm256_set_epu8(UINT8_C( 65), UINT8_C(219), UINT8_C(169), UINT8_C(149),
                             UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                             UINT8_C(175), UINT8_C(250), UINT8_C(255), UINT8_C(138),
                             UINT8_C(121), UINT8_C(183), UINT8_C(255), UINT8_C(255),
                             UINT8_C(255), UINT8_C(255), UINT8_C(140), UINT8_C(255),
                             UINT8_C(255), UINT8_C( 84), UINT8_C(255), UINT8_C(254),
                             UINT8_C(107), UINT8_C(228), UINT8_C(227), UINT8_C(211),
                             UINT8_C(220), UINT8_C(195), UINT8_C(255), UINT8_C(255)) },
    { simde_x_mm256_set_epu8(UINT8_C(180), UINT8_C(149), UINT8_C(241), UINT8_C( 31),
                             UINT8_C( 45), UINT8_C(238), UINT8_C(127), UINT8_C( 41),
                             UINT8_C( 61), UINT8_C( 40), UINT8_C(253), UINT8_C(133),
                             UINT8_C(247), UINT8_C(164), UINT8_C(139), UINT8_C(228),
                             UINT8_C( 62), UINT8_C(209), UINT8_C(132), UINT8_C( 80),
                             UINT8_C(102), UINT8_C(192), UINT8_C(185), UINT8_C(191),
                             UINT8_C(100), UINT8_C(154), UINT8_C( 33), UINT8_C( 61),
                             UINT8_C( 93), UINT8_C(153), UINT8_C(220), UINT8_C(160)),
      simde_x_mm256_set_epu8(UINT8_C(230), UINT8_C( 84), UINT8_C( 78), UINT8_C(157),
                             UINT8_C(192), UINT8_C( 80), UINT8_C(173), UINT8_C(216),
                             UINT8_C( 47), UINT8_C(218), UINT8_C( 93), UINT8_C(143),
                             UINT8_C( 45), UINT8_C( 59), UINT8_C(151), UINT8_C(134),
                             UINT8_C( 70), UINT8_C( 90), UINT8_C( 58), UINT8_C(114),
                             UINT8_C(223), UINT8_C(242), UINT8_C( 15), UINT8_C(131),
                             UINT8_C( 82), UINT8_C(204), UINT8_C(173), UINT8_C(  5),
                             UINT8_C( 58), UINT8_C(182), UINT8_C(252), UINT8_C(237)),
      simde_x_mm256_set_epu8(UINT8_C(255), UINT8_C(233), UINT8_C(255), UINT8_C(188),
                             UINT8_C(237), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                             UINT8_C(108), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                             UINT8_C(255), UINT8_C(223), UINT8_C(255), UINT8_C(255),
                             UINT8_C(132), UINT8_C(255), UINT8_C(190), UINT8_C(194),
                             UINT8_C(255), UINT8_C(255), UINT8_C(200), UINT8_C(255),
                             UINT8_C(182), UINT8_C(255), UINT8_C(206), UINT8_C( 66),
                             UINT8_C(151), UINT8_C(255), UINT8_C(255), UINT8_C(255)) },
    { simde_x_mm256_set_epu8(UINT8_C(201), UINT8_C(214), UINT8_C(179), UINT8_C(233),
                             UINT8_C(198), UINT8_C( 81), UINT8_C(243), UINT8_C(119),
                             UINT8_C(160), UINT8_C(147), UINT8_C( 34), UINT8_C(138),
                             UINT8_C(127), UINT8_C( 31), UINT8_C(145), UINT8_C( 40),
                             UINT8_C(228), UINT8_C( 45), UINT8_C(  3), UINT8_C(  4),
                             UINT8_C(249), UINT8_C(180), UINT8_C(210), UINT8_C(  7),
                             UINT8_C(175), UINT8_C( 81), UINT8_C( 15), UINT8_C(137),
                             UINT8_C( 20), UINT8_C( 57), UINT8_C(  3), UINT8_C(157)),
      simde_x_mm256_set_epu8(UINT8_C(209), UINT8_C( 16), UINT8_C(253), UINT8_C(199),
                             UINT8_C(185), UINT8_C(238), UINT8_C( 28), UINT8_C( 87),
                             UINT8_C( 41), UINT8_C(232), UINT8_C( 54), UINT8_C(100),
                             UINT8_C(160), UINT8_C( 87), UINT8_C(101), UINT8_C(193),
                             UINT8_C(173), UINT8_C(242), UINT8_C(182), UINT8_C(  0),
                             UINT8_C(222), UINT8_C(142), UINT8_C(217), UINT8_C(177),
                             UINT8_C(237), UINT8_C(196), UINT8_C(145), UINT8_C(208),
                             UINT8_C( 95), UINT8_C(248), UINT8_C( 86), UINT8_C( 20)),
      simde_x_mm256_set_epu8(UINT8_C(255), UINT8_C(230), UINT8_C(255), UINT8_C(255),
                             UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(206),
                             UINT8_C(201), UINT8_C(255), UINT8_C( 88), UINT8_C(238),
                             UINT8_C(255), UINT8_C(118), UINT8_C(246), UINT8_C(233),
                             UINT8_C(255), UINT8_C(255), UINT8_C(185), UINT8_C(  4),
                             UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(184),
                             UINT8_C(255), UINT8_C(255), UINT8_C(160), UINT8_C(255),
                             UINT8_C(115), UINT8_C(255), UINT8_C( 89), UINT8_C(177)) },
    { simde_x_mm256_set_epu8(UINT8_C(117), UINT8_C(251), UINT8_C(156), UINT8_C( 72),
                             UINT8_C(241), UINT8_C( 25), UINT8_C( 80), UINT8_C(195),
                             UINT8_C(213), UINT8_C( 26), UINT8_C( 44), UINT8_C(154),
                             UINT8_C( 40), UINT8_C(201), UINT8_C(142), UINT8_C(110),
                             UINT8_C( 17), UINT8_C(100), UINT8_C( 41), UINT8_C(223),
                             UINT8_C(255), UINT8_C(232), UINT8_C(253), UINT8_C(190),
                             UINT8_C(155), UINT8_C(178), UINT8_C(150), UINT8_C(248),
                             UINT8_C(166), UINT8_C(223), UINT8_C( 92), UINT8_C(146)),
      simde_x_mm256_set_epu8(UINT8_C(164), UINT8_C(171), UINT8_C(230), UINT8_C(232),
                             UINT8_C( 86), UINT8_C(220), UINT8_C(153), UINT8_C(194),
                             UINT8_C( 83), UINT8_C( 81), UINT8_C( 80), UINT8_C( 93),
                             UINT8_C( 96), UINT8_C( 68), UINT8_C( 55), UINT8_C(183),
                             UINT8_C(110), UINT8_C(151), UINT8_C( 66), UINT8_C(168),
                             UINT8_C(210), UINT8_C( 58), UINT8_C(169), UINT8_C(189),
                             UINT8_C( 61), UINT8_C( 15), UINT8_C(124), UINT8_C(190),
                             UINT8_C( 93), UINT8_C(242), UINT8_C( 80), UINT8_C(225)),
      simde_x_mm256_set_epu8(UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                             UINT8_C(255), UINT8_C(245), UINT8_C(233), UINT8_C(255),
                             UINT8_C(255), UINT8_C(107), UINT8_C(124), UINT8_C(247),
                             UINT8_C(136), UINT8_C(255), UINT8_C(197), UINT8_C(255),
                             UINT8_C(127), UINT8_C(251), UINT8_C(107), UINT8_C(255),
                             UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                             UINT8_C(216), UINT8_C(193), UINT8_C(255), UINT8_C(255),
                             UINT8_C(255), UINT8_C(255), UINT8_C(172), UINT8_C(255)) },
    { simde_x_mm256_set_epu8(UINT8_C(130), UINT8_C( 76), UINT8_C( 98), UINT8_C(  8),
                             UINT8_C(243), UINT8_C(125), UINT8_C(189), UINT8_C(162),
                             UINT8_C(107), UINT8_C( 98), UINT8_C(171), UINT8_C( 80),
                             UINT8_C(243), UINT8_C(225), UINT8_C(  6), UINT8_C( 11),
                             UINT8_C(250), UINT8_C(210), UINT8_C( 60), UINT8_C(230),
                             UINT8_C( 17), UINT8_C(222), UINT8_C( 70), UINT8_C(180),
                             UINT8_C( 28), UINT8_C( 96), UINT8_C(128), UINT8_C(195),
                             UINT8_C(240), UINT8_C(119), UINT8_C(199), UINT8_C( 65)),
      simde_x_mm256_set_epu8(UINT8_C( 47), UINT8_C(225), UINT8_C( 74), UINT8_C(106),
                             UINT8_C(149), UINT8_C(250), UINT8_C(221), UINT8_C( 24),
                             UINT8_C(161), UINT8_C( 69), UINT8_C(209), UINT8_C(120),
                             UINT8_C(116), UINT8_C(235), UINT8_C(  4), UINT8_C(161),
                             UINT8_C(156), UINT8_C(193), UINT8_C(253), UINT8_C(  2),
                             UINT8_C(168), UINT8_C( 52), UINT8_C(231), UINT8_C(201),
                             UINT8_C(115), UINT8_C(  0), UINT8_C(176), UINT8_C(224),
                             UINT8_C(  4), UINT8_C(219), UINT8_C(202), UINT8_C(177)),
      simde_x_mm256_set_epu8(UINT8_C(177), UINT8_C(255), UINT8_C(172), UINT8_C(114),
                             UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(186),
                             UINT8_C(255), UINT8_C(167), UINT8_C(255), UINT8_C(200),
                             UINT8_C(255), UINT8_C(255), UINT8_C( 10), UINT8_C(172),
                             UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(232),
                             UINT8_C(185), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                             UINT8_C(143), UINT8_C( 96), UINT8_C(255), UINT8_C(255),
                             UINT8_C(244), UINT8_C(255), UINT8_C(255), UINT8_C(242)) },
    { simde_x_mm256_set_epu8(UINT8_C(144), UINT8_C( 62), UINT8_C(142), UINT8_C(211),
                             UINT8_C( 41), UINT8_C(162), UINT8_C(184), UINT8_C(180),
                             UINT8_C(242), UINT8_C( 80), UINT8_C( 73), UINT8_C( 63),
                             UINT8_C(168), UINT8_C(176), UINT8_C( 12), UINT8_C( 85),
                             UINT8_C( 62), UINT8_C( 83), UINT8_C( 52), UINT8_C( 39),
                             UINT8_C( 56), UINT8_C(245), UINT8_C( 65), UINT8_C(213),
                             UINT8_C( 94), UINT8_C( 88), UINT8_C(157), UINT8_C(124),
                             UINT8_C(123), UINT8_C(196), UINT8_C( 79), UINT8_C( 49)),
      simde_x_mm256_set_epu8(UINT8_C(142), UINT8_C( 71), UINT8_C(103), UINT8_C(139),
                             UINT8_C(236), UINT8_C(100), UINT8_C(139), UINT8_C(154),
                             UINT8_C(203), UINT8_C(125), UINT8_C(237), UINT8_C(236),
                             UINT8_C( 45), UINT8_C(103), UINT8_C( 56), UINT8_C( 68),
                             UINT8_C( 26), UINT8_C( 73), UINT8_C(130), UINT8_C( 19),
                             UINT8_C(222), UINT8_C(206), UINT8_C(129), UINT8_C(101),
                             UINT8_C( 56), UINT8_C(145), UINT8_C(213), UINT8_C(249),
                             UINT8_C(145), UINT8_C( 67), UINT8_C(236), UINT8_C(136)),
      simde_x_mm256_set_epu8(UINT8_C(255), UINT8_C(133), UINT8_C(245), UINT8_C(255),
                             UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                             UINT8_C(255), UINT8_C(205), UINT8_C(255), UINT8_C(255),
                             UINT8_C(213), UINT8_C(255), UINT8_C( 68), UINT8_C(153),
                             UINT8_C( 88), UINT8_C(156), UINT8_C(182), UINT8_C( 58),
                             UINT8_C(255), UINT8_C(255), UINT8_C(194), UINT8_C(255),
                             UINT8_C(150), UINT8_C(233), UINT8_C(255), UINT8_C(255),
                             UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(185)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_adds_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_adds_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu16(UINT16_C( 46173), UINT16_C( 51502), UINT16_C( 53334), UINT16_C( 43223),
                              UINT16_C( 23928), UINT16_C( 20321), UINT16_C( 51743), UINT16_C( 37618),
                              UINT16_C( 65078), UINT16_C(  7253), UINT16_C( 52827), UINT16_C( 55189),
                              UINT16_C(  4987), UINT16_C( 17665), UINT16_C( 14350), UINT16_C( 38811)),
      simde_x_mm256_set_epu16(UINT16_C( 37136), UINT16_C( 48792), UINT16_C(  4303), UINT16_C(  5479),
                              UINT16_C( 25191), UINT16_C( 58551), UINT16_C( 48285), UINT16_C(  4997),
                              UINT16_C( 11428), UINT16_C( 55078), UINT16_C( 56047), UINT16_C( 52960),
                              UINT16_C( 65202), UINT16_C( 38018), UINT16_C(   624), UINT16_C(  7777)),
      simde_x_mm256_set_epu16(UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 57637), UINT16_C( 48702),
                              UINT16_C( 49119), UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 42615),
                              UINT16_C( 65535), UINT16_C( 62331), UINT16_C( 65535), UINT16_C( 65535),
                              UINT16_C( 65535), UINT16_C( 55683), UINT16_C( 14974), UINT16_C( 46588)) },
    { simde_x_mm256_set_epu16(UINT16_C( 32326), UINT16_C( 24612), UINT16_C( 21846), UINT16_C( 55200),
                              UINT16_C( 41586), UINT16_C( 19758), UINT16_C( 51650), UINT16_C( 38909),
                              UINT16_C( 46063), UINT16_C( 28335), UINT16_C(  9134), UINT16_C( 41639),
                              UINT16_C( 55060), UINT16_C( 39890), UINT16_C(  8293), UINT16_C( 53471)),
      simde_x_mm256_set_epu16(UINT16_C( 41234), UINT16_C(  2183), UINT16_C( 63540), UINT16_C(  1722),
                              UINT16_C( 28608), UINT16_C( 25104), UINT16_C( 45712), UINT16_C( 60419),
                              UINT16_C( 19160), UINT16_C(  3341), UINT16_C( 25253), UINT16_C( 20430),
                              UINT16_C( 42207), UINT16_C( 24498), UINT16_C( 15365), UINT16_C( 19541)),
      simde_x_mm256_set_epu16(UINT16_C( 65535), UINT16_C( 26795), UINT16_C( 65535), UINT16_C( 56922),
                              UINT16_C( 65535), UINT16_C( 44862), UINT16_C( 65535), UINT16_C( 65535),
                              UINT16_C( 65223), UINT16_C( 31676), UINT16_C( 34387), UINT16_C( 62069),
                              UINT16_C( 65535), UINT16_C( 64388), UINT16_C( 23658), UINT16_C( 65535)) },
    { simde_x_mm256_set_epu16(UINT16_C( 26386), UINT16_C( 63006), UINT16_C( 58203), UINT16_C( 62377),
                              UINT16_C( 47602), UINT16_C( 30067), UINT16_C( 23114), UINT16_C( 33473),
                              UINT16_C( 53575), UINT16_C( 38408), UINT16_C( 17337), UINT16_C( 42126),
                              UINT16_C(  5249), UINT16_C( 35315), UINT16_C( 42156), UINT16_C( 18091)),
      simde_x_mm256_set_epu16(UINT16_C( 52612), UINT16_C( 30768), UINT16_C( 53242), UINT16_C( 17367),
                              UINT16_C( 55155), UINT16_C( 55208), UINT16_C( 40791), UINT16_C( 34106),
                              UINT16_C( 38398), UINT16_C(  3526), UINT16_C( 48471), UINT16_C( 61865),
                              UINT16_C( 26735), UINT16_C( 59797), UINT16_C( 61911), UINT16_C(  9267)),
      simde_x_mm256_set_epu16(UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 65535),
                              UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 63905), UINT16_C( 65535),
                              UINT16_C( 65535), UINT16_C( 41934), UINT16_C( 65535), UINT16_C( 65535),
                              UINT16_C( 31984), UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 27358)) },
    { simde_x_mm256_set_epu16(UINT16_C( 52292), UINT16_C( 60997), UINT16_C( 31428), UINT16_C(  9305),
                              UINT16_C( 57362), UINT16_C( 62823), UINT16_C(  6394), UINT16_C( 15984),
                              UINT16_C( 50964), UINT16_C( 21850), UINT16_C( 44748), UINT16_C( 36872),
                              UINT16_C( 14263), UINT16_C( 48235), UINT16_C(  9404), UINT16_C( 55410)),
      simde_x_mm256_set_epu16(UINT16_C(  5822), UINT16_C( 53891), UINT16_C( 53572), UINT16_C( 35299),
                              UINT16_C( 32303), UINT16_C( 47360), UINT16_C(  2824), UINT16_C( 19749),
                              UINT16_C(  6763), UINT16_C( 47400), UINT16_C( 29201), UINT16_C( 32332),
                              UINT16_C( 24570), UINT16_C( 50755), UINT16_C( 22545), UINT16_C(  9382)),
      simde_x_mm256_set_epu16(UINT16_C( 58114), UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 44604),
                              UINT16_C( 65535), UINT16_C( 65535), UINT16_C(  9218), UINT16_C( 35733),
                              UINT16_C( 57727), UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 65535),
                              UINT16_C( 38833), UINT16_C( 65535), UINT16_C( 31949), UINT16_C( 64792)) },
    { simde_x_mm256_set_epu16(UINT16_C( 50076), UINT16_C(  9743), UINT16_C( 10727), UINT16_C( 51592),
                              UINT16_C( 28130), UINT16_C( 34226), UINT16_C( 44764), UINT16_C( 58424),
                              UINT16_C( 15168), UINT16_C(  4051), UINT16_C( 54044), UINT16_C(  7020),
                              UINT16_C( 31115), UINT16_C( 49299), UINT16_C( 40742), UINT16_C( 48855)),
      simde_x_mm256_set_epu16(UINT16_C( 50898), UINT16_C( 60971), UINT16_C(  2964), UINT16_C( 53140),
                              UINT16_C( 39951), UINT16_C( 57637), UINT16_C( 63735), UINT16_C( 40101),
                              UINT16_C( 37326), UINT16_C( 12531), UINT16_C( 29670), UINT16_C( 49503),
                              UINT16_C( 64935), UINT16_C( 44011), UINT16_C( 59422), UINT16_C( 45053)),
      simde_x_mm256_set_epu16(UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 13691), UINT16_C( 65535),
                              UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 65535),
                              UINT16_C( 52494), UINT16_C( 16582), UINT16_C( 65535), UINT16_C( 56523),
                              UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 65535)) },
    { simde_x_mm256_set_epu16(UINT16_C( 12906), UINT16_C( 34342), UINT16_C( 49900), UINT16_C( 16373),
                              UINT16_C( 41099), UINT16_C( 42680), UINT16_C( 11034), UINT16_C(  4050),
                              UINT16_C( 41370), UINT16_C( 18241), UINT16_C( 60694), UINT16_C( 59842),
                              UINT16_C(  7044), UINT16_C( 38288), UINT16_C( 18779), UINT16_C( 33204)),
      simde_x_mm256_set_epu16(UINT16_C( 39975), UINT16_C( 26379), UINT16_C( 49406), UINT16_C( 11197),
                              UINT16_C( 25665), UINT16_C( 45876), UINT16_C(  8978), UINT16_C( 56112),
                              UINT16_C(  5541), UINT16_C( 41816), UINT16_C(  1773), UINT16_C( 25366),
                              UINT16_C( 51395), UINT16_C( 19553), UINT16_C( 37079), UINT16_C( 32528)),
      simde_x_mm256_set_epu16(UINT16_C( 52881), UINT16_C( 60721), UINT16_C( 65535), UINT16_C( 27570),
                              UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 20012), UINT16_C( 60162),
                              UINT16_C( 46911), UINT16_C( 60057), UINT16_C( 62467), UINT16_C( 65535),
                              UINT16_C( 58439), UINT16_C( 57841), UINT16_C( 55858), UINT16_C( 65535)) },
    { simde_x_mm256_set_epu16(UINT16_C( 54610), UINT16_C( 56071), UINT16_C( 54559), UINT16_C( 11899),
                              UINT16_C( 32307), UINT16_C(  4962), UINT16_C( 27630), UINT16_C( 33600),
                              UINT16_C( 31852), UINT16_C( 56358), UINT16_C( 35796), UINT16_C(  8024),
                              UINT16_C( 46221), UINT16_C(  4529), UINT16_C( 49147), UINT16_C(  8518)),
      simde_x_mm256_set_epu16(UINT16_C( 57675), UINT16_C(  2883), UINT16_C( 55066), UINT16_C( 41648),
                              UINT16_C( 12159), UINT16_C( 20265), UINT16_C( 47525), UINT16_C( 54059),
                              UINT16_C( 12623), UINT16_C( 11063), UINT16_C( 34242), UINT16_C( 57692),
                              UINT16_C(  8071), UINT16_C(  9806), UINT16_C( 30691), UINT16_C( 35776)),
      simde_x_mm256_set_epu16(UINT16_C( 65535), UINT16_C( 58954), UINT16_C( 65535), UINT16_C( 53547),
                              UINT16_C( 44466), UINT16_C( 25227), UINT16_C( 65535), UINT16_C( 65535),
                              UINT16_C( 44475), UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 65535),
                              UINT16_C( 54292), UINT16_C( 14335), UINT16_C( 65535), UINT16_C( 44294)) },
    { simde_x_mm256_set_epu16(UINT16_C( 56834), UINT16_C( 64885), UINT16_C(  9140), UINT16_C( 13056),
                              UINT16_C( 40842), UINT16_C( 10347), UINT16_C(  7339), UINT16_C( 17877),
                              UINT16_C( 14924), UINT16_C( 16868), UINT16_C( 50139), UINT16_C( 42854),
                              UINT16_C( 20413), UINT16_C( 64148), UINT16_C( 24871), UINT16_C( 35734)),
      simde_x_mm256_set_epu16(UINT16_C( 20840), UINT16_C( 44144), UINT16_C( 58177), UINT16_C( 28709),
                              UINT16_C( 14233), UINT16_C( 55224), UINT16_C( 50824), UINT16_C( 22009),
                              UINT16_C( 46863), UINT16_C( 40997), UINT16_C( 17728), UINT16_C( 21679),
                              UINT16_C(  9552), UINT16_C( 17236), UINT16_C(  5658), UINT16_C( 51223)),
      simde_x_mm256_set_epu16(UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 65535), UINT16_C( 41765),
                              UINT16_C( 55075), UINT16_C( 65535), UINT16_C( 58163), UINT16_C( 39886),
                              UINT16_C( 61787), UINT16_C( 57865), UINT16_C( 65535), UINT16_C( 64533),
                              UINT16_C( 29965), UINT16_C( 65535), UINT16_C( 30529), UINT16_C( 65535)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_adds_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_blendv_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i i;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C( 119), INT8_C(  14), INT8_C( 127), INT8_C(-117),
                           INT8_C( -92), INT8_C(  49), INT8_C( -15), INT8_C( -64),
                           INT8_C(  66), INT8_C(-125), INT8_C(  43), INT8_C(   6),
                           INT8_C(-117), INT8_C(  95), INT8_C(   4), INT8_C( 100),
                           INT8_C(  82), INT8_C( -66), INT8_C(  57), INT8_C( -98),
                           INT8_C( -94), INT8_C(   7), INT8_C(  58), INT8_C(-109),
                           INT8_C( -21), INT8_C( -88), INT8_C(  12), INT8_C(  65),
                           INT8_C(-108), INT8_C( -25), INT8_C( -96), INT8_C(  -4)),
      simde_mm256_set_epi8(INT8_C( -68), INT8_C(  -8), INT8_C(  57), INT8_C( 103),
                           INT8_C(  55), INT8_C( 120), INT8_C(   1), INT8_C(  68),
                           INT8_C(  85), INT8_C(-119), INT8_C(  -3), INT8_C(  60),
                           INT8_C(-115), INT8_C( -64), INT8_C( 126), INT8_C( -67),
                           INT8_C(  11), INT8_C(  73), INT8_C(  97), INT8_C( -47),
                           INT8_C(  73), INT8_C( -17), INT8_C(  -4), INT8_C(  19),
                           INT8_C( -66), INT8_C(  -1), INT8_C(  84), INT8_C( -63),
                           INT8_C(  58), INT8_C( 114), INT8_C( 107), INT8_C( -13)),
      simde_mm256_set_epi8(INT8_C( -94), INT8_C( -13), INT8_C( -63), INT8_C(  48),
                           INT8_C(  72), INT8_C( -33), INT8_C(-118), INT8_C(  86),
                           INT8_C(  17), INT8_C( 112), INT8_C(   9), INT8_C( 106),
                           INT8_C( 115), INT8_C( -15), INT8_C(  74), INT8_C(   5),
                           INT8_C(  17), INT8_C( -31), INT8_C(-120), INT8_C(  18),
                           INT8_C(  82), INT8_C( -67), INT8_C(-101), INT8_C(-109),
                           INT8_C(  81), INT8_C(-126), INT8_C(  -8), INT8_C(   4),
                           INT8_C( 123), INT8_C( 125), INT8_C(  70), INT8_C(  66)),
      simde_mm256_set_epi8(INT8_C( -68), INT8_C(  -8), INT8_C(  57), INT8_C(-117),
                           INT8_C( -92), INT8_C( 120), INT8_C(   1), INT8_C( -64),
                           INT8_C(  66), INT8_C(-125), INT8_C(  43), INT8_C(   6),
                           INT8_C(-117), INT8_C( -64), INT8_C(   4), INT8_C( 100),
                           INT8_C(  82), INT8_C(  73), INT8_C(  97), INT8_C( -98),
                           INT8_C( -94), INT8_C( -17), INT8_C(  -4), INT8_C(  19),
                           INT8_C( -21), INT8_C(  -1), INT8_C(  84), INT8_C(  65),
                           INT8_C(-108), INT8_C( -25), INT8_C( -96), INT8_C(  -4)) },
    { simde_mm256_set_epi8(INT8_C( -95), INT8_C(  48), INT8_C(-106), INT8_C(   2),
                           INT8_C( -98), INT8_C(  42), INT8_C( 111), INT8_C( -63),
                           INT8_C(  63), INT8_C(  60), INT8_C(-104), INT8_C(-108),
                           INT8_C( -18), INT8_C( -88), INT8_C(  55), INT8_C(  21),
                           INT8_C(-103), INT8_C( 114), INT8_C( -80), INT8_C(  89),
                           INT8_C(  60), INT8_C(  45), INT8_C( -20), INT8_C(  79),
                           INT8_C(-112), INT8_C( -14), INT8_C( -11), INT8_C( 117),
                           INT8_C(  14), INT8_C( -21), INT8_C(  11), INT8_C(-119)),
      simde_mm256_set_epi8(INT8_C(   7), INT8_C( -82), INT8_C( -49), INT8_C(   6),
                           INT8_C(-108), INT8_C(-115), INT8_C( -95), INT8_C( -53),
                           INT8_C(   6), INT8_C(  28), INT8_C(  47), INT8_C(  86),
                           INT8_C( -76), INT8_C(-114), INT8_C( 114), INT8_C(  94),
                           INT8_C(  90), INT8_C(  13), INT8_C( 121), INT8_C(-123),
                           INT8_C( -33), INT8_C( -67), INT8_C(  30), INT8_C( -90),
                           INT8_C(  -5), INT8_C(  42), INT8_C( 102), INT8_C(  53),
                           INT8_C(  95), INT8_C(  56), INT8_C(   1), INT8_C( -15)),
      simde_mm256_set_epi8(INT8_C(-117), INT8_C( -35), INT8_C(  72), INT8_C( -41),
                           INT8_C(-118), INT8_C( 110), INT8_C(  61), INT8_C(  45),
                           INT8_C(-112), INT8_C( 112), INT8_C(  46), INT8_C( -75),
                           INT8_C(  71), INT8_C( -85), INT8_C( -58), INT8_C( 104),
                           INT8_C(-126), INT8_C(-109), INT8_C(  86), INT8_C(  70),
                           INT8_C( -85), INT8_C( 113), INT8_C(  90), INT8_C(  35),
                           INT8_C( -48), INT8_C( -83), INT8_C(  16), INT8_C(  55),
                           INT8_C( -13), INT8_C(  42), INT8_C( -55), INT8_C( -15)),
      simde_mm256_set_epi8(INT8_C(   7), INT8_C( -82), INT8_C(-106), INT8_C(   6),
                           INT8_C(-108), INT8_C(  42), INT8_C( 111), INT8_C( -63),
                           INT8_C(   6), INT8_C(  60), INT8_C(-104), INT8_C(  86),
                           INT8_C( -18), INT8_C(-114), INT8_C( 114), INT8_C(  21),
                           INT8_C(  90), INT8_C(  13), INT8_C( -80), INT8_C(  89),
                           INT8_C( -33), INT8_C(  45), INT8_C( -20), INT8_C(  79),
                           INT8_C(  -5), INT8_C(  42), INT8_C( -11), INT8_C( 117),
                           INT8_C(  95), INT8_C( -21), INT8_C(   1), INT8_C( -15)) },
    { simde_mm256_set_epi8(INT8_C(  12), INT8_C( 118), INT8_C(-120), INT8_C(  17),
                           INT8_C(  61), INT8_C(  24), INT8_C(-114), INT8_C(-117),
                           INT8_C( -20), INT8_C(-118), INT8_C(  93), INT8_C( 106),
                           INT8_C( -99), INT8_C(  -8), INT8_C( 114), INT8_C(-115),
                           INT8_C( -65), INT8_C( -34), INT8_C(  66), INT8_C(  62),
                           INT8_C( 113), INT8_C( -44), INT8_C( 109), INT8_C(  20),
                           INT8_C( 122), INT8_C( -58), INT8_C(   7), INT8_C(-123),
                           INT8_C(  18), INT8_C(  89), INT8_C( -84), INT8_C(-114)),
      simde_mm256_set_epi8(INT8_C( -67), INT8_C( -15), INT8_C( -72), INT8_C( -39),
                           INT8_C( -90), INT8_C( 108), INT8_C(  93), INT8_C( -36),
                           INT8_C( -64), INT8_C(  36), INT8_C( -98), INT8_C(  76),
                           INT8_C( 123), INT8_C( -40), INT8_C( -48), INT8_C(-111),
                           INT8_C(-100), INT8_C(  76), INT8_C( 114), INT8_C(  51),
                           INT8_C(  72), INT8_C(  51), INT8_C( 101), INT8_C(-128),
                           INT8_C( -68), INT8_C(  35), INT8_C( -50), INT8_C(-100),
                           INT8_C(  85), INT8_C(-109), INT8_C( -86), INT8_C(  43)),
      simde_mm256_set_epi8(INT8_C(  21), INT8_C(  44), INT8_C(  93), INT8_C( -14),
                           INT8_C(  76), INT8_C(  78), INT8_C( 101), INT8_C(  40),
                           INT8_C( 126), INT8_C( -37), INT8_C( 115), INT8_C(  17),
                           INT8_C(  43), INT8_C( -71), INT8_C(-123), INT8_C( -85),
                           INT8_C( -19), INT8_C(  27), INT8_C(  72), INT8_C(  57),
                           INT8_C( 118), INT8_C( -19), INT8_C( -66), INT8_C( 124),
                           INT8_C( -52), INT8_C( -69), INT8_C(  32), INT8_C(  64),
                           INT8_C( -16), INT8_C(-103), INT8_C( -39), INT8_C( 121)),
      simde_mm256_set_epi8(INT8_C(  12), INT8_C( 118), INT8_C(-120), INT8_C( -39),
                           INT8_C(  61), INT8_C(  24), INT8_C(-114), INT8_C(-117),
                           INT8_C( -20), INT8_C(  36), INT8_C(  93), INT8_C( 106),
                           INT8_C( -99), INT8_C( -40), INT8_C( -48), INT8_C(-111),
                           INT8_C(-100), INT8_C( -34), INT8_C(  66), INT8_C(  62),
                           INT8_C( 113), INT8_C(  51), INT8_C( 101), INT8_C(  20),
                           INT8_C( -68), INT8_C(  35), INT8_C(   7), INT8_C(-123),
                           INT8_C(  85), INT8_C(-109), INT8_C( -86), INT8_C(-114)) },
    { simde_mm256_set_epi8(INT8_C( -23), INT8_C( 109), INT8_C(  45), INT8_C( -63),
                           INT8_C(  54), INT8_C( -58), INT8_C( -11), INT8_C(  18),
                           INT8_C(  27), INT8_C( -68), INT8_C(-102), INT8_C(  76),
                           INT8_C( -97), INT8_C(  26), INT8_C(  10), INT8_C( -41),
                           INT8_C(  50), INT8_C(  54), INT8_C(-128), INT8_C(  77),
                           INT8_C( -33), INT8_C( -46), INT8_C( 118), INT8_C(  76),
                           INT8_C( -72), INT8_C( 106), INT8_C( -54), INT8_C(  28),
                           INT8_C(  86), INT8_C(  37), INT8_C(  -1), INT8_C(  83)),
      simde_mm256_set_epi8(INT8_C( 123), INT8_C(  58), INT8_C(  98), INT8_C( 125),
                           INT8_C( 118), INT8_C(-119), INT8_C( -36), INT8_C(  78),
                           INT8_C(   0), INT8_C(  77), INT8_C(  67), INT8_C( 118),
                           INT8_C(  22), INT8_C( -94), INT8_C( -70), INT8_C(  21),
                           INT8_C(  65), INT8_C(  89), INT8_C(  34), INT8_C(  21),
                           INT8_C(  65), INT8_C( -53), INT8_C( -43), INT8_C( -55),
                           INT8_C( -12), INT8_C( -79), INT8_C(-123), INT8_C(  80),
                           INT8_C( -58), INT8_C( -76), INT8_C( -82), INT8_C(  16)),
      simde_mm256_set_epi8(INT8_C( -15), INT8_C( -31), INT8_C( 124), INT8_C(  18),
                           INT8_C(  63), INT8_C(-119), INT8_C( -84), INT8_C( -47),
                           INT8_C( 110), INT8_C(  99), INT8_C(  -7), INT8_C( -78),
                           INT8_C( 122), INT8_C(   9), INT8_C(  54), INT8_C(-112),
                           INT8_C(-100), INT8_C(  -9), INT8_C(-127), INT8_C(  67),
                           INT8_C( -60), INT8_C( -43), INT8_C(  76), INT8_C(  10),
                           INT8_C(  83), INT8_C( -83), INT8_C( -60), INT8_C( -94),
                           INT8_C( -63), INT8_C( 113), INT8_C(-114), INT8_C( 124)),
      simde_mm256_set_epi8(INT8_C( 123), INT8_C(  58), INT8_C(  45), INT8_C( -63),
                           INT8_C(  54), INT8_C(-119), INT8_C( -36), INT8_C(  78),
                           INT8_C(  27), INT8_C( -68), INT8_C(  67), INT8_C( 118),
                           INT8_C( -97), INT8_C(  26), INT8_C(  10), INT8_C(  21),
                           INT8_C(  65), INT8_C(  89), INT8_C(  34), INT8_C(  77),
                           INT8_C(  65), INT8_C( -53), INT8_C( 118), INT8_C(  76),
                           INT8_C( -72), INT8_C( -79), INT8_C(-123), INT8_C(  80),
                           INT8_C( -58), INT8_C(  37), INT8_C( -82), INT8_C(  83)) },
    { simde_mm256_set_epi8(INT8_C(  71), INT8_C(  12), INT8_C( 123), INT8_C(-112),
                           INT8_C(-126), INT8_C(  60), INT8_C( 108), INT8_C(-103),
                           INT8_C( 103), INT8_C( 120), INT8_C( -99), INT8_C( 114),
                           INT8_C(  34), INT8_C( -37), INT8_C( -98), INT8_C( -39),
                           INT8_C(-107), INT8_C( -14), INT8_C(  -8), INT8_C( -82),
                           INT8_C( 123), INT8_C(  78), INT8_C(  27), INT8_C(   7),
                           INT8_C(  90), INT8_C(-108), INT8_C( -54), INT8_C(  40),
                           INT8_C(  -9), INT8_C( -18), INT8_C(  12), INT8_C(   6)),
      simde_mm256_set_epi8(INT8_C(  20), INT8_C( -98), INT8_C(  96), INT8_C(   3),
                           INT8_C(  27), INT8_C(  45), INT8_C( -97), INT8_C( -19),
                           INT8_C( -40), INT8_C( -84), INT8_C( -70), INT8_C( -38),
                           INT8_C( -57), INT8_C(-122), INT8_C( -18), INT8_C( -59),
                           INT8_C( -66), INT8_C(  38), INT8_C(  28), INT8_C( -72),
                           INT8_C(  41), INT8_C( -85), INT8_C(-107), INT8_C( 124),
                           INT8_C(-120), INT8_C(   0), INT8_C(  52), INT8_C( -73),
                           INT8_C( -94), INT8_C(-103), INT8_C( 104), INT8_C(-108)),
      simde_mm256_set_epi8(INT8_C( 114), INT8_C(  67), INT8_C(  87), INT8_C(  60),
                           INT8_C( -47), INT8_C(-121), INT8_C( -54), INT8_C( 110),
                           INT8_C(-100), INT8_C( 105), INT8_C( -23), INT8_C(  81),
                           INT8_C(-121), INT8_C(  67), INT8_C(  97), INT8_C(-125),
                           INT8_C(  78), INT8_C( 118), INT8_C(  46), INT8_C( -85),
                           INT8_C(  78), INT8_C( -66), INT8_C(  11), INT8_C(  90),
                           INT8_C(  11), INT8_C( 120), INT8_C(  20), INT8_C(  83),
                           INT8_C( 103), INT8_C( -43), INT8_C(  72), INT8_C( -92)),
      simde_mm256_set_epi8(INT8_C(  71), INT8_C(  12), INT8_C( 123), INT8_C(-112),
                           INT8_C(  27), INT8_C(  45), INT8_C( -97), INT8_C(-103),
                           INT8_C( -40), INT8_C( 120), INT8_C( -70), INT8_C( 114),
                           INT8_C( -57), INT8_C( -37), INT8_C( -98), INT8_C( -59),
                           INT8_C(-107), INT8_C( -14), INT8_C(  -8), INT8_C( -72),
                           INT8_C( 123), INT8_C( -85), INT8_C(  27), INT8_C(   7),
                           INT8_C(  90), INT8_C(-108), INT8_C( -54), INT8_C(  40),
                           INT8_C(  -9), INT8_C(-103), INT8_C(  12), INT8_C(-108)) },
    { simde_mm256_set_epi8(INT8_C(-120), INT8_C( -17), INT8_C(  71), INT8_C( 108),
                           INT8_C(-124), INT8_C(   8), INT8_C(  38), INT8_C(-124),
                           INT8_C( -33), INT8_C( -80), INT8_C(  82), INT8_C( -52),
                           INT8_C( -85), INT8_C(  20), INT8_C( -43), INT8_C(  49),
                           INT8_C(-127), INT8_C(  82), INT8_C(-125), INT8_C(-107),
                           INT8_C(  99), INT8_C( -94), INT8_C(  98), INT8_C( 124),
                           INT8_C(  23), INT8_C(  -8), INT8_C( -30), INT8_C( 107),
                           INT8_C( -17), INT8_C( -36), INT8_C(  65), INT8_C(  35)),
      simde_mm256_set_epi8(INT8_C(  50), INT8_C( -42), INT8_C(  70), INT8_C(  74),
                           INT8_C( -25), INT8_C( 118), INT8_C(  53), INT8_C(  91),
                           INT8_C( -24), INT8_C(  44), INT8_C(-107), INT8_C(  38),
                           INT8_C(  62), INT8_C(  93), INT8_C(  84), INT8_C(  86),
                           INT8_C(  25), INT8_C(  25), INT8_C(  -1), INT8_C( -49),
                           INT8_C( -69), INT8_C( -81), INT8_C(  33), INT8_C( -90),
                           INT8_C( 118), INT8_C(  99), INT8_C( -68), INT8_C(  38),
                           INT8_C( -18), INT8_C( -20), INT8_C( -37), INT8_C( -57)),
      simde_mm256_set_epi8(INT8_C(  36), INT8_C(  48), INT8_C(-118), INT8_C( 125),
                           INT8_C(  12), INT8_C( 115), INT8_C( -38), INT8_C(   1),
                           INT8_C( -43), INT8_C(-120), INT8_C( 119), INT8_C(  88),
                           INT8_C(  19), INT8_C(   1), INT8_C(  40), INT8_C( -39),
                           INT8_C( -67), INT8_C(  66), INT8_C( -86), INT8_C(  38),
                           INT8_C(  40), INT8_C( -46), INT8_C( 104), INT8_C( -95),
                           INT8_C( 115), INT8_C( -49), INT8_C(  15), INT8_C(-101),
                           INT8_C( -79), INT8_C(  -5), INT8_C( 112), INT8_C( -45)),
      simde_mm256_set_epi8(INT8_C(-120), INT8_C( -17), INT8_C(  70), INT8_C( 108),
                           INT8_C(-124), INT8_C(   8), INT8_C(  53), INT8_C(-124),
                           INT8_C( -24), INT8_C(  44), INT8_C(  82), INT8_C( -52),
                           INT8_C( -85), INT8_C(  20), INT8_C( -43), INT8_C(  86),
                           INT8_C(  25), INT8_C(  82), INT8_C(  -1), INT8_C(-107),
                           INT8_C(  99), INT8_C( -81), INT8_C(  98), INT8_C( -90),
                           INT8_C(  23), INT8_C(  99), INT8_C( -30), INT8_C(  38),
                           INT8_C( -18), INT8_C( -20), INT8_C(  65), INT8_C( -57)) },
    { simde_mm256_set_epi8(INT8_C(  55), INT8_C(  33), INT8_C(  43), INT8_C(  65),
                           INT8_C( -59), INT8_C( -95), INT8_C(  10), INT8_C(  11),
                           INT8_C( 122), INT8_C(  35), INT8_C(  55), INT8_C( 107),
                           INT8_C( -46), INT8_C(-119), INT8_C(-106), INT8_C(  77),
                           INT8_C( -56), INT8_C( -78), INT8_C( -97), INT8_C(-126),
                           INT8_C( -36), INT8_C(  17), INT8_C(  13), INT8_C(  38),
                           INT8_C(  52), INT8_C( -31), INT8_C(  68), INT8_C(  51),
                           INT8_C( -16), INT8_C(  61), INT8_C( -72), INT8_C( -48)),
      simde_mm256_set_epi8(INT8_C( 123), INT8_C(-111), INT8_C( -83), INT8_C(  -8),
                           INT8_C(  66), INT8_C( -69), INT8_C( -27), INT8_C(-103),
                           INT8_C(-112), INT8_C( -80), INT8_C(  56), INT8_C(  60),
                           INT8_C(-106), INT8_C(  -4), INT8_C(-128), INT8_C(-122),
                           INT8_C(  74), INT8_C( -55), INT8_C( -48), INT8_C(-128),
                           INT8_C(  -2), INT8_C(  63), INT8_C( -37), INT8_C(  18),
                           INT8_C( -89), INT8_C( -76), INT8_C(  42), INT8_C(  62),
                           INT8_C(  74), INT8_C( -87), INT8_C(  30), INT8_C(-103)),
      simde_mm256_set_epi8(INT8_C(   4), INT8_C( -10), INT8_C(  -5), INT8_C(  -1),
                           INT8_C(  -4), INT8_C(  87), INT8_C( -59), INT8_C(  -9),
                           INT8_C( -53), INT8_C(  83), INT8_C( -63), INT8_C(  99),
                           INT8_C(  55), INT8_C( 119), INT8_C(  36), INT8_C( -96),
                           INT8_C( -98), INT8_C(  22), INT8_C(   4), INT8_C(-128),
                           INT8_C(  16), INT8_C( -72), INT8_C( 114), INT8_C(  35),
                           INT8_C( -15), INT8_C( -10), INT8_C(  97), INT8_C(-112),
                           INT8_C(-109), INT8_C( -68), INT8_C(   8), INT8_C( 101)),
      simde_mm256_set_epi8(INT8_C(  55), INT8_C(-111), INT8_C( -83), INT8_C(  -8),
                           INT8_C(  66), INT8_C( -95), INT8_C( -27), INT8_C(-103),
                           INT8_C(-112), INT8_C(  35), INT8_C(  56), INT8_C( 107),
                           INT8_C( -46), INT8_C(-119), INT8_C(-106), INT8_C(-122),
                           INT8_C(  74), INT8_C( -78), INT8_C( -97), INT8_C(-128),
                           INT8_C( -36), INT8_C(  63), INT8_C(  13), INT8_C(  38),
                           INT8_C( -89), INT8_C( -76), INT8_C(  68), INT8_C(  62),
                           INT8_C(  74), INT8_C( -87), INT8_C( -72), INT8_C( -48)) },
    { simde_mm256_set_epi8(INT8_C(  69), INT8_C( -38), INT8_C(-105), INT8_C( -77),
                           INT8_C(   3), INT8_C( -19), INT8_C( -91), INT8_C(  81),
                           INT8_C( -61), INT8_C(  88), INT8_C( -52), INT8_C( -76),
                           INT8_C(-100), INT8_C( -70), INT8_C( -64), INT8_C(  71),
                           INT8_C(  82), INT8_C(-122), INT8_C( -41), INT8_C( -86),
                           INT8_C(   9), INT8_C(  29), INT8_C( -31), INT8_C( -87),
                           INT8_C(-113), INT8_C( 100), INT8_C( 100), INT8_C( -55),
                           INT8_C( -11), INT8_C(  92), INT8_C( -87), INT8_C(  43)),
      simde_mm256_set_epi8(INT8_C(  96), INT8_C(-116), INT8_C(   5), INT8_C(  16),
                           INT8_C( -66), INT8_C(   4), INT8_C(   8), INT8_C(  34),
                           INT8_C(  93), INT8_C(  90), INT8_C( -27), INT8_C(  86),
                           INT8_C( 115), INT8_C(  27), INT8_C( -30), INT8_C(  15),
                           INT8_C(  94), INT8_C( -93), INT8_C( -55), INT8_C( -18),
                           INT8_C(-122), INT8_C(  51), INT8_C( -22), INT8_C( -72),
                           INT8_C( -80), INT8_C(  24), INT8_C(  38), INT8_C(  87),
                           INT8_C( -35), INT8_C( -67), INT8_C(  94), INT8_C( -17)),
      simde_mm256_set_epi8(INT8_C( -19), INT8_C( -11), INT8_C(  77), INT8_C( -75),
                           INT8_C(  98), INT8_C( -18), INT8_C( -28), INT8_C(   5),
                           INT8_C(  86), INT8_C(-117), INT8_C( 114), INT8_C( -52),
                           INT8_C(  63), INT8_C( -51), INT8_C( 110), INT8_C( -22),
                           INT8_C(  54), INT8_C(  36), INT8_C(  44), INT8_C(  72),
                           INT8_C( -14), INT8_C( -61), INT8_C( -76), INT8_C(  51),
                           INT8_C(  40), INT8_C( -28), INT8_C( -97), INT8_C( 114),
                           INT8_C(-128), INT8_C(   9), INT8_C(  94), INT8_C( -35)),
      simde_mm256_set_epi8(INT8_C(  96), INT8_C(-116), INT8_C(-105), INT8_C(  16),
                           INT8_C(   3), INT8_C(   4), INT8_C(   8), INT8_C(  81),
                           INT8_C( -61), INT8_C(  90), INT8_C( -52), INT8_C(  86),
                           INT8_C(-100), INT8_C(  27), INT8_C( -64), INT8_C(  15),
                           INT8_C(  82), INT8_C(-122), INT8_C( -41), INT8_C( -86),
                           INT8_C(-122), INT8_C(  51), INT8_C( -22), INT8_C( -87),
                           INT8_C(-113), INT8_C(  24), INT8_C(  38), INT8_C( -55),
                           INT8_C( -35), INT8_C(  92), INT8_C( -87), INT8_C( -17)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_blendv_epi8(test_vec[i].a, test_vec[i].b, test_vec[i].i);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cmpeq_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8( INT8_C( -34),  INT8_C(  65),  INT8_C( -18),  INT8_C( -94),
                            INT8_C(  20),  INT8_C(-105),  INT8_C(  79),  INT8_C( -26),
                            INT8_C(   7),  INT8_C( -36),  INT8_C(  33),  INT8_C( 123),
                            INT8_C( 115),  INT8_C( -52),  INT8_C( -98),  INT8_C(  62),
                            INT8_C(  64),  INT8_C( -91),  INT8_C(  45),  INT8_C( 102),
                            INT8_C(  21),  INT8_C(-111),  INT8_C( -41),  INT8_C( -14),
                            INT8_C(  91),  INT8_C(-106),  INT8_C(  23),  INT8_C(  86),
                            INT8_C(-108),  INT8_C(  34),  INT8_C(  -9),  INT8_C(  42)),
      simde_mm256_set_epi8( INT8_C( -34),  INT8_C(  65),  INT8_C(-119),  INT8_C( -94),
                            INT8_C( -15),  INT8_C(  95),  INT8_C(  72),  INT8_C(  66),
                            INT8_C(-113),  INT8_C( -36), ~INT8_C(   0),  INT8_C( 123),
                            INT8_C( -47),  INT8_C( -52),  INT8_C(  -7),  INT8_C(  62),
                            INT8_C(  31),  INT8_C(  79),  INT8_C(  20),  INT8_C( 102),
                            INT8_C(  21),  INT8_C(  17),  INT8_C(-125),  INT8_C( -14),
                            INT8_C(  22),  INT8_C(-111),  INT8_C(  23),  INT8_C( 100),
                            INT8_C(-122),  INT8_C(  34),  INT8_C( -26),  INT8_C(  42)),
      simde_mm256_set_epi8(~INT8_C(   0), ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0), ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                            INT8_C(   0), ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0), ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0)) },
    { simde_mm256_set_epi8( INT8_C(  61),  INT8_C(  96),  INT8_C( -54),  INT8_C(  88),
                            INT8_C(-115),  INT8_C(  14),  INT8_C( 100),  INT8_C( -28),
                            INT8_C(  78),  INT8_C( -79),  INT8_C(  80),  INT8_C( 114),
                            INT8_C(  29),  INT8_C( -69),  INT8_C(   6),  INT8_C(-127),
                            INT8_C( 116),  INT8_C(  35),  INT8_C(  49),  INT8_C( -24),
                            INT8_C(   4),  INT8_C(-123),  INT8_C( -95),  INT8_C( -23),
                            INT8_C(  44),  INT8_C(  68),  INT8_C( -84),  INT8_C(  -9),
                            INT8_C( -86),  INT8_C( 117),  INT8_C(  55),  INT8_C( 121)),
      simde_mm256_set_epi8( INT8_C(  61),  INT8_C(  81),  INT8_C(  33),  INT8_C(  88),
                            INT8_C( -34),  INT8_C(  14),  INT8_C( 111),  INT8_C( -28),
                            INT8_C( -70),  INT8_C(-102),  INT8_C( 116),  INT8_C(-102),
                            INT8_C(  29),  INT8_C( -10),  INT8_C(  13),  INT8_C( 109),
                            INT8_C( 116),  INT8_C( -83),  INT8_C(  49),  INT8_C(   1),
                            INT8_C(   4),  INT8_C(-123),  INT8_C( -18),  INT8_C( -23),
                            INT8_C(  44),  INT8_C(  68),  INT8_C(-109),  INT8_C(  54),
                            INT8_C( 123),  INT8_C(  62),  INT8_C(  71),  INT8_C(   3)),
      simde_mm256_set_epi8(~INT8_C(   0),  INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                            INT8_C(   0), ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0), ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                           ~INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0)) },
    { simde_mm256_set_epi8( INT8_C( -58),  INT8_C( -55),  INT8_C( 126),  INT8_C( -17),
                            INT8_C( -94),  INT8_C( -45),  INT8_C( -42),  INT8_C(  39),
                            INT8_C( -81),  INT8_C( -73),  INT8_C( -20),  INT8_C( -73),
                            INT8_C(  79),  INT8_C(  25),  INT8_C( -86),  INT8_C( -52),
                            INT8_C( 106),  INT8_C(  58),  INT8_C( 113),  INT8_C(  61),
                            INT8_C( -71),  INT8_C(  -3),  INT8_C( 101),  INT8_C(-102),
                            INT8_C( -14),  INT8_C( -40),  INT8_C(  82),  INT8_C( -84),
                            INT8_C(  49),  INT8_C(  46),  INT8_C(  59),  INT8_C( -33)),
      simde_mm256_set_epi8( INT8_C( 110),  INT8_C( -67),  INT8_C( 126),  INT8_C( -17),
                            INT8_C( -94),  INT8_C( -46),  INT8_C( -74),  INT8_C( -37),
                            INT8_C( -81),  INT8_C( -93),  INT8_C(  97),  INT8_C( -73),
                            INT8_C( -66),  INT8_C(  25),  INT8_C(  37),  INT8_C( -52),
                            INT8_C( 106),  INT8_C( -80),  INT8_C( 113),  INT8_C(  61),
                            INT8_C( -50),  INT8_C(  68),  INT8_C( 101),  INT8_C(-102),
                            INT8_C( -14),  INT8_C( -35),  INT8_C(  54),  INT8_C(  -2),
                            INT8_C(  49),  INT8_C(  46),  INT8_C(   6),  INT8_C(   4)),
      simde_mm256_set_epi8( INT8_C(   0),  INT8_C(   0), ~INT8_C(   0), ~INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                            INT8_C(   0), ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0), ~INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0), ~INT8_C(   0), ~INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0)) },
    { simde_mm256_set_epi8( INT8_C(  -9),  INT8_C(  28),  INT8_C(   1),  INT8_C(   0),
                            INT8_C(  57),  INT8_C( -72),  INT8_C( -61),  INT8_C(  74),
                            INT8_C(-105),  INT8_C(  58),  INT8_C(  84),  INT8_C(  60),
                            INT8_C(  21),  INT8_C(  38),  INT8_C(  16),  INT8_C(  25),
                            INT8_C(   2),  INT8_C( -63),  INT8_C(  28),  INT8_C(  93),
                            INT8_C( -44),  INT8_C( -78),  INT8_C( -50),  INT8_C( -21),
                            INT8_C(  47),  INT8_C(  30),  INT8_C(  97),  INT8_C(  18),
                            INT8_C( -36),  INT8_C(  72),  INT8_C( -66),  INT8_C( 124)),
      simde_mm256_set_epi8( INT8_C(-127),  INT8_C( -27),  INT8_C(  86),  INT8_C( -50),
                            INT8_C(  57),  INT8_C( -49),  INT8_C( -61),  INT8_C(  74),
                            INT8_C(-105),  INT8_C( -45),  INT8_C( 125),  INT8_C(  18),
                            INT8_C( -47),  INT8_C(  70),  INT8_C(  16),  INT8_C(  90),
                            INT8_C(   2),  INT8_C( -44),  INT8_C( 121),  INT8_C(  48),
                            INT8_C( -78),  INT8_C( 120),  INT8_C( -50),  INT8_C( -21),
                            INT8_C(  47),  INT8_C( -59),  INT8_C(  97),  INT8_C(  21),
                            INT8_C( -36),  INT8_C(  72),  INT8_C( -44),  INT8_C( 124)),
      simde_mm256_set_epi8( INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0), ~INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0), ~INT8_C(   0), ~INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0), ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0)) },
    { simde_mm256_set_epi8( INT8_C(  75),  INT8_C(  -6),  INT8_C( -43),  INT8_C( 107),
                            INT8_C(  28),  INT8_C(  81),  INT8_C(  82),  INT8_C(  91),
                            INT8_C(  66),  INT8_C( 107),  INT8_C( -41),  INT8_C( -50),
                            INT8_C(  -5),  INT8_C(  66),  INT8_C(-100),  INT8_C( 112),
                            INT8_C(-109),  INT8_C(  92),  INT8_C( -50),  INT8_C(  68),
                            INT8_C( -54),  INT8_C( 111),  INT8_C(  25),  INT8_C(  36),
                            INT8_C(  30),  INT8_C( -33),  INT8_C(  28),  INT8_C(  68),
                            INT8_C( -69),  INT8_C( 124),  INT8_C(-124),  INT8_C(  48)),
      simde_mm256_set_epi8( INT8_C(  26),  INT8_C( 124),  INT8_C( -85),  INT8_C(  90),
                            INT8_C(  49),  INT8_C( -43),  INT8_C(  82),  INT8_C(-110),
                            INT8_C(  -4),  INT8_C(-103),  INT8_C(-116),  INT8_C( -91),
                            INT8_C( 101),  INT8_C( -60),  INT8_C(  28),  INT8_C( -62),
                            INT8_C(-109),  INT8_C(   2),  INT8_C(  71),  INT8_C(  68),
                            INT8_C(  92),  INT8_C( -96),  INT8_C( -47),  INT8_C(  89),
                            INT8_C(-111),  INT8_C( -89),  INT8_C(  38),  INT8_C( 109),
                            INT8_C( -69),  INT8_C(  57),  INT8_C(  87),  INT8_C(  94)),
      simde_mm256_set_epi8( INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0)) },
    { simde_mm256_set_epi8( INT8_C(  78),  INT8_C(-103),  INT8_C( -83),  INT8_C( -64),
                            INT8_C(  86),  INT8_C(  62),  INT8_C(  40),  INT8_C(-116),
                            INT8_C(  49),  INT8_C(  94),  INT8_C( -31),  INT8_C(  82),
                            INT8_C( -55),  INT8_C(-100),  INT8_C( -61),  INT8_C( -62),
                            INT8_C(-101),  INT8_C( 117),  INT8_C( -20),  INT8_C(  19),
                            INT8_C( -97),  INT8_C( -75),  INT8_C(-101),  INT8_C( -39),
                            INT8_C(  28),  INT8_C(  55),  INT8_C(  85),  INT8_C( 106),
                            INT8_C( -97),  INT8_C( -74),  INT8_C(  51),  INT8_C( -54)),
      simde_mm256_set_epi8( INT8_C(-116),  INT8_C( -91),  INT8_C( 105),  INT8_C( -64),
                            INT8_C(  -6),  INT8_C( -63),  INT8_C(  82),  INT8_C(   4),
                            INT8_C(  -7),  INT8_C( -70),  INT8_C( -31),  INT8_C( -83),
                            INT8_C(  22),  INT8_C(-100),  INT8_C(  96),  INT8_C( -62),
                            INT8_C(-120),  INT8_C( 120),  INT8_C( -20),  INT8_C( -80),
                            INT8_C( -97),  INT8_C( -75),  INT8_C( -29),  INT8_C(   4),
                            INT8_C(  28),  INT8_C(  60),  INT8_C(  79),  INT8_C(  73),
                            INT8_C(  17),  INT8_C(-120),  INT8_C( 110),  INT8_C( 100)),
      simde_mm256_set_epi8( INT8_C(   0),  INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0), ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0)) },
    { simde_mm256_set_epi8( INT8_C( 118),  INT8_C(  88),  INT8_C(  13),  INT8_C(  39),
                            INT8_C( -45),  INT8_C(  46),  INT8_C( -85),  INT8_C(  17),
                            INT8_C(  -7),  INT8_C(  75),  INT8_C(  -5),  INT8_C(-120),
                            INT8_C( -77),  INT8_C( -49),  INT8_C(  58),  INT8_C( -50),
                            INT8_C(   0),  INT8_C(  21),  INT8_C( -11),  INT8_C( -48),
                            INT8_C( -85),  INT8_C(  55),  INT8_C( 100), ~INT8_C(   0),
                            INT8_C(   7),  INT8_C(  72),  INT8_C(  25),  INT8_C(-126),
                            INT8_C( -81),  INT8_C( -15),  INT8_C( -25),  INT8_C( -55)),
      simde_mm256_set_epi8( INT8_C( 107),  INT8_C(  67),  INT8_C( -53),  INT8_C(  30),
                            INT8_C(  53),  INT8_C( -25),  INT8_C(  94),  INT8_C(  90),
                            INT8_C( -59),  INT8_C(  75),  INT8_C(  65),  INT8_C(-120),
                            INT8_C(  32),  INT8_C( -11),  INT8_C(  58),  INT8_C(  33),
                            INT8_C(   0),  INT8_C(  44),  INT8_C( -11),  INT8_C(  49),
                            INT8_C( -51),  INT8_C(  55),  INT8_C( 100),  INT8_C( -67),
                            INT8_C( -45),  INT8_C(  89),  INT8_C(  25),  INT8_C( 110),
                            INT8_C(  60),  INT8_C( -42),  INT8_C( -25),  INT8_C(   1)),
      simde_mm256_set_epi8( INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0), ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0), ~INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),  INT8_C(   0)) },
    { simde_mm256_set_epi8( INT8_C(  47),  INT8_C( 126),  INT8_C( -95),  INT8_C(-121),
                            INT8_C(  84),  INT8_C(  11),  INT8_C(  -4),  INT8_C( -74),
                            INT8_C(-124),  INT8_C(   4),  INT8_C( -12),  INT8_C(  31),
                            INT8_C(  41),  INT8_C(  31),  INT8_C( -42),  INT8_C(  92),
                            INT8_C( -62),  INT8_C(  -8),  INT8_C( -73),  INT8_C(  14),
                            INT8_C(  22),  INT8_C(-109),  INT8_C( 103),  INT8_C(  90),
                            INT8_C(  98),  INT8_C( -28),  INT8_C( -11),  INT8_C(-120),
                            INT8_C( -81),  INT8_C(   0),  INT8_C(  34),  INT8_C(  36)),
      simde_mm256_set_epi8( INT8_C(  47),  INT8_C(-103),  INT8_C( -95),  INT8_C(-121),
                            INT8_C(  84),  INT8_C(  72),  INT8_C( 125),  INT8_C( -13),
                            INT8_C( -49),  INT8_C(  14),  INT8_C(  44),  INT8_C( 110),
                            INT8_C(  41),  INT8_C(  68),  INT8_C( -42),  INT8_C(  92),
                            INT8_C( 107),  INT8_C(  -8),  INT8_C( 127),  INT8_C(  14),
                            INT8_C(  22),  INT8_C(-109),  INT8_C( -52),  INT8_C(  -3),
                            INT8_C( -78),  INT8_C(  91),  INT8_C(   8),  INT8_C(  23),
                            INT8_C( 110),  INT8_C( -91),  INT8_C(  34),  INT8_C(  17)),
      simde_mm256_set_epi8(~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0), ~INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                           ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0), ~INT8_C(   0),
                            INT8_C(   0), ~INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),
                           ~INT8_C(   0), ~INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
                            INT8_C(   0),  INT8_C(   0), ~INT8_C(   0),  INT8_C(   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cmpeq_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cmpeq_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi16( INT16_C( -5413),  INT16_C( -8669),  INT16_C(-20019),  INT16_C( 13281),
                             INT16_C( 31513),  INT16_C( 29495),  INT16_C( 24515),  INT16_C( -4843),
                             INT16_C(-25942),  INT16_C(-22058),  INT16_C( 25862),  INT16_C( 17599),
                             INT16_C(  3410),  INT16_C(-25277),  INT16_C( -9899),  INT16_C( -1157)),
      simde_mm256_set_epi16( INT16_C(-24951),  INT16_C( -8669),  INT16_C(-20019),  INT16_C(-25059),
                             INT16_C(-16550),  INT16_C( 29495),  INT16_C( 14158),  INT16_C( 15756),
                             INT16_C(-12717),  INT16_C( 16217),  INT16_C( 23007),  INT16_C(-29661),
                             INT16_C( -4389),  INT16_C( -6794),  INT16_C( 24406),  INT16_C(  3979)),
      simde_mm256_set_epi16( INT16_C(     0),  ~INT16_C(    0),  ~INT16_C(    0),  INT16_C(     0),
                             INT16_C(     0),  ~INT16_C(    0),  INT16_C(     0),  INT16_C(     0),
                             INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
                             INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0)) },
    { simde_mm256_set_epi16( INT16_C(-24592),  INT16_C(-14625),  INT16_C(-22785),  INT16_C(  -539),
                             INT16_C( 27023),  INT16_C( 22410),  INT16_C( 24512),  INT16_C( 28286),
                             INT16_C(  -371),  INT16_C(-19534),  INT16_C( 20760),  INT16_C( -2933),
                             INT16_C( 19420),  INT16_C( 28265),  INT16_C(  -411),  INT16_C(-25192)),
      simde_mm256_set_epi16( INT16_C(-13031),  INT16_C(-29481),  INT16_C(-21398),  INT16_C(  5762),
                             INT16_C(-11151),  INT16_C( 22410),  INT16_C(-17819),  INT16_C(-18343),
                             INT16_C(  -371),  INT16_C(-18178),  INT16_C( 32217),  INT16_C(-13082),
                             INT16_C( 19420),  INT16_C(-14308),  INT16_C(  -411),  INT16_C(-25192)),
      simde_mm256_set_epi16( INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
                             INT16_C(     0),  ~INT16_C(    0),  INT16_C(     0),  INT16_C(     0),
                             ~INT16_C(    0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
                             ~INT16_C(    0),  INT16_C(     0),  ~INT16_C(    0),  ~INT16_C(    0)) },
    { simde_mm256_set_epi16( INT16_C( -1787),  INT16_C( 14472),  INT16_C(  9645),  INT16_C(  6467),
                             INT16_C(-28251),  INT16_C( -4608),  INT16_C(-20138),  INT16_C(-12375),
                             INT16_C( -3139),  INT16_C(-11799),  INT16_C(-25694),  INT16_C( -9505),
                             INT16_C(  2016),  INT16_C(-12994),  INT16_C( 12032),  INT16_C( -1625)),
      simde_mm256_set_epi16( INT16_C( 14082),  INT16_C( 14472),  INT16_C(  9645),  INT16_C(-10341),
                             INT16_C(-21377),  INT16_C(-28844),  INT16_C(-27109),  INT16_C(-21859),
                             INT16_C( -3139),  INT16_C(-20139),  INT16_C(-25694),  INT16_C( 28917),
                             INT16_C(  5339),  INT16_C( 19240),  INT16_C( 12032),  INT16_C(  2212)),
      simde_mm256_set_epi16( INT16_C(     0),  ~INT16_C(    0),  ~INT16_C(    0),  INT16_C(     0),
                             INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
                             ~INT16_C(    0),  INT16_C(     0),  ~INT16_C(    0),  INT16_C(     0),
                             INT16_C(     0),  INT16_C(     0),  ~INT16_C(    0),  INT16_C(     0)) },
    { simde_mm256_set_epi16( INT16_C( 29890),  INT16_C( 31032),  INT16_C(-29157),  INT16_C(-14947),
                             INT16_C(-10307),  INT16_C(-20105),  INT16_C( -2072),  INT16_C( 29196),
                             INT16_C(  1484),  INT16_C(-11865),  INT16_C(-30233),  INT16_C( 30603),
                             INT16_C( 20632),  INT16_C(-27772),  INT16_C(-32273),  INT16_C(  4867)),
      simde_mm256_set_epi16( INT16_C(-21410),  INT16_C(  9749),  INT16_C(-29157),  INT16_C(-14947),
                             INT16_C( 13547),  INT16_C( 28436),  INT16_C( -2072),  INT16_C( 29196),
                             INT16_C(  1484),  INT16_C(-14930),  INT16_C(  6002),  INT16_C( 30603),
                             INT16_C( 27473),  INT16_C(  2844),  INT16_C(-19044),  INT16_C(  4867)),
      simde_mm256_set_epi16( INT16_C(     0),  INT16_C(     0),  ~INT16_C(    0),  ~INT16_C(    0),
                             INT16_C(     0),  INT16_C(     0),  ~INT16_C(    0),  ~INT16_C(    0),
                             ~INT16_C(    0),  INT16_C(     0),  INT16_C(     0),  ~INT16_C(    0),
                             INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  ~INT16_C(    0)) },
    { simde_mm256_set_epi16( INT16_C( -2810),  INT16_C(-12778),  INT16_C( 16624),  INT16_C(  2706),
                             INT16_C( 14585),  INT16_C( -6866),  INT16_C(  -582),  INT16_C( 29880),
                             INT16_C( 20309),  INT16_C( 25315),  INT16_C( -5634),  INT16_C(-21292),
                             INT16_C( 11215),  INT16_C( 13817),  INT16_C( 26751),  INT16_C( -8288)),
      simde_mm256_set_epi16( INT16_C(-11737),  INT16_C(-19770),  INT16_C(  8400),  INT16_C(  2706),
                             INT16_C( 14599),  INT16_C( -6866),  INT16_C(  -582),  INT16_C( 29880),
                             INT16_C( 20309),  INT16_C( 32436),  INT16_C( -5634),  INT16_C(-21292),
                             INT16_C(-11784),  INT16_C( 13817),  INT16_C( 26751),  INT16_C(-12877)),
      simde_mm256_set_epi16( INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  ~INT16_C(    0),
                             INT16_C(     0),  ~INT16_C(    0),  ~INT16_C(    0),  ~INT16_C(    0),
                             ~INT16_C(    0),  INT16_C(     0),  ~INT16_C(    0),  ~INT16_C(    0),
                             INT16_C(     0),  ~INT16_C(    0),  ~INT16_C(    0),  INT16_C(     0)) },
    { simde_mm256_set_epi16( INT16_C( 11738),  INT16_C(-30358),  INT16_C(-23042),  INT16_C( -2979),
                             INT16_C( 32390),  INT16_C( 22571),  INT16_C( -5410),  INT16_C( 14750),
                             INT16_C(-16092),  INT16_C( 27869),  INT16_C( 28085),  INT16_C( 15025),
                             INT16_C(-11732),  INT16_C( 28458),  INT16_C( -3526),  INT16_C(-21900)),
      simde_mm256_set_epi16( INT16_C( 11738),  INT16_C(-30358),  INT16_C(-12411),  INT16_C( -2979),
                             INT16_C(-27990),  INT16_C( 25385),  INT16_C( -5410),  INT16_C( 13011),
                             INT16_C(-30216),  INT16_C(-15754),  INT16_C( 28085),  INT16_C(   142),
                             INT16_C(-11865),  INT16_C( 28458),  INT16_C(  2605),  INT16_C( 31867)),
      simde_mm256_set_epi16( ~INT16_C(    0),  ~INT16_C(    0),  INT16_C(     0),  ~INT16_C(    0),
                             INT16_C(     0),  INT16_C(     0),  ~INT16_C(    0),  INT16_C(     0),
                             INT16_C(     0),  INT16_C(     0),  ~INT16_C(    0),  INT16_C(     0),
                             INT16_C(     0),  ~INT16_C(    0),  INT16_C(     0),  INT16_C(     0)) },
    { simde_mm256_set_epi16( INT16_C(-15649),  INT16_C( 19434),  INT16_C( 30307),  INT16_C( -2580),
                             INT16_C(-17669),  INT16_C(-12636),  INT16_C(-26128),  INT16_C(  1047),
                             INT16_C( 31189),  INT16_C( -4800),  INT16_C(-21775),  INT16_C(  9584),
                             INT16_C(-10037),  INT16_C(-12969),  INT16_C( -2203),  INT16_C(  7107)),
      simde_mm256_set_epi16( INT16_C(-14042),  INT16_C( 19434),  INT16_C( 12761),  INT16_C( -2580),
                             INT16_C(-14129),  INT16_C(-21327),  INT16_C(  8254),  INT16_C( 17988),
                             INT16_C( 31189),  INT16_C(-12604),  INT16_C(-31847),  INT16_C(  9584),
                             INT16_C(  2606),  INT16_C(-15409),  INT16_C( -2203),  INT16_C(  7107)),
      simde_mm256_set_epi16( INT16_C(     0),  ~INT16_C(    0),  INT16_C(     0),  ~INT16_C(    0),
                             INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
                             ~INT16_C(    0),  INT16_C(     0),  INT16_C(     0),  ~INT16_C(    0),
                             INT16_C(     0),  INT16_C(     0),  ~INT16_C(    0),  ~INT16_C(    0)) },
    { simde_mm256_set_epi16( INT16_C(  2093),  INT16_C( 26175),  INT16_C(  5850),  INT16_C(-17892),
                             INT16_C(-28618),  INT16_C(-20409),  INT16_C(   201),  INT16_C(-27373),
                             INT16_C(-25181),  INT16_C( -3904),  INT16_C( 26317),  INT16_C( 18884),
                             INT16_C( 15503),  INT16_C( 21511),  INT16_C(-24060),  INT16_C( -1242)),
      simde_mm256_set_epi16( INT16_C(-27449),  INT16_C( 26175),  INT16_C( 26521),  INT16_C(-16887),
                             INT16_C(-13967),  INT16_C(-16902),  INT16_C(-25148),  INT16_C( 11331),
                             INT16_C(-22706),  INT16_C( -3904),  INT16_C( -3346),  INT16_C( 18884),
                             INT16_C(  2207),  INT16_C( 11164),  INT16_C( 22502),  INT16_C(-11226)),
      simde_mm256_set_epi16( INT16_C(     0),  ~INT16_C(    0),  INT16_C(     0),  INT16_C(     0),
                             INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
                             INT16_C(     0),  ~INT16_C(    0),  INT16_C(     0),  ~INT16_C(    0),
                             INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cmpeq_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cmpeq_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32( INT32_C( -566104414),  INT32_C(  345460710),  INT32_C(  131867003),  INT32_C( 1942789694),
                             INT32_C( 1084566886),  INT32_C(  361879538),  INT32_C( 1536563030),  INT32_C(-1809647830)),
      simde_mm256_set_epi32( INT32_C( 1749780765),  INT32_C( -245413822),  INT32_C(  131867003),  INT32_C( -777848334),
                             INT32_C(  525276311),  INT32_C(  361879538),  INT32_C(  378618724),  INT32_C(-1809647830)),
      simde_mm256_set_epi32( INT32_C(          0),  INT32_C(          0),  ~INT32_C(         0),  INT32_C(          0),
                             INT32_C(          0),  ~INT32_C(         0),  INT32_C(          0),  ~INT32_C(         0)) },
    { simde_mm256_set_epi32( INT32_C( 1746696722),  INT32_C(  940817566),  INT32_C( -345075038),  INT32_C( 1008650721),
                             INT32_C( 1982631981),  INT32_C( 1481863730),  INT32_C( 1367059109),  INT32_C( -627319339)),
      simde_mm256_set_epi32( INT32_C( 1746696722),  INT32_C(  940817566),  INT32_C(-2066241582),  INT32_C( 1008650721),
                             INT32_C(  174011254),  INT32_C(-1995628897),  INT32_C( -710324691),  INT32_C( -119123371)),
      simde_mm256_set_epi32( ~INT32_C(         0),  ~INT32_C(         0),  INT32_C(          0),  ~INT32_C(         0),
                             INT32_C(          0),  INT32_C(          0),  INT32_C(          0),  INT32_C(          0)) },
    { simde_mm256_set_epi32( INT32_C( 1029753432),  INT32_C(-1928436508),  INT32_C( 1320243314),  INT32_C(  498796161),
                             INT32_C( 1948463592),  INT32_C(   75866601),  INT32_C(  742698231),  INT32_C(-1435158663)),
      simde_mm256_set_epi32( INT32_C( 1029753432),  INT32_C(-1928436508),  INT32_C(-1164282726),  INT32_C(  267783533),
                             INT32_C( -156415231),  INT32_C(-1409290651),  INT32_C(  -98856138),  INT32_C( 2067678979)),
      simde_mm256_set_epi32( ~INT32_C(         0),  ~INT32_C(         0),  INT32_C(          0),  INT32_C(          0),
                             INT32_C(          0),  INT32_C(          0),  INT32_C(          0),  INT32_C(          0)) },
    { simde_mm256_set_epi32( INT32_C( -346859314),  INT32_C( 1692797387),  INT32_C(   66311928),  INT32_C(  460824773),
                             INT32_C( -548661058),  INT32_C( -254589283),  INT32_C(  833835845),  INT32_C(-1932331579)),
      simde_mm256_set_epi32( INT32_C( -346859314),  INT32_C(   60539810),  INT32_C( 1011930823),  INT32_C(  460824773),
                             INT32_C(  190841895),  INT32_C( -254589283),  INT32_C(  316499678),  INT32_C(-1932331579)),
      simde_mm256_set_epi32( ~INT32_C(         0),  INT32_C(          0),  INT32_C(          0),  ~INT32_C(         0),
                             INT32_C(          0),  ~INT32_C(         0),  INT32_C(          0),  ~INT32_C(         0)) },
    { simde_mm256_set_epi32( INT32_C( -959873297),  INT32_C(-1563175385),  INT32_C(-1346900809),  INT32_C( 1327082188),
                             INT32_C( 1782214973),  INT32_C(-1174575718),  INT32_C( -220704084),  INT32_C(  825113567)),
      simde_mm256_set_epi32( INT32_C( -959873297),  INT32_C(  735229659),  INT32_C( -660381298),  INT32_C(-1091295976),
                             INT32_C( 1782214973),  INT32_C(-1174575718),  INT32_C( 2094872318),  INT32_C( 1028851204)),
      simde_mm256_set_epi32( ~INT32_C(         0),  INT32_C(          0),  INT32_C(          0),  INT32_C(          0),
                             ~INT32_C(         0),  ~INT32_C(         0),  INT32_C(          0),  INT32_C(          0)) },
    { simde_mm256_set_epi32( INT32_C( 1661232006),  INT32_C( 1627888390),  INT32_C(  757018179),  INT32_C( -750573130),
                             INT32_C(-1367421353),  INT32_C(  198410180),  INT32_C(-1240440841),  INT32_C(-1417499113)),
      simde_mm256_set_epi32( INT32_C( -466269763),  INT32_C(   49857616),  INT32_C(  757018179),  INT32_C( -750573130),
                             INT32_C(-1367421353),  INT32_C(-1831110733),  INT32_C(-1233216938),  INT32_C(   84780453)),
      simde_mm256_set_epi32( INT32_C(          0),  INT32_C(          0),  ~INT32_C(         0),  ~INT32_C(         0),
                             ~INT32_C(         0),  INT32_C(          0),  INT32_C(          0),  INT32_C(          0)) },
    { simde_mm256_set_epi32( INT32_C( -149159680),  INT32_C(  968409930),  INT32_C(-1757785028),  INT32_C(  354816025),
                             INT32_C(   46210141),  INT32_C( -726479125),  INT32_C(  790520082),  INT32_C( -599212420)),
      simde_mm256_set_epi32( INT32_C( -149159680),  INT32_C( 1775235902),  INT32_C(-1757785028),  INT32_C( -783938470),
                             INT32_C(   46210141),  INT32_C( -726479125),  INT32_C( -272289003),  INT32_C( -599212420)),
      simde_mm256_set_epi32( ~INT32_C(         0),  INT32_C(          0),  ~INT32_C(         0),  INT32_C(          0),
                             ~INT32_C(         0),  ~INT32_C(         0),  INT32_C(          0),  ~INT32_C(         0)) },
    { simde_mm256_set_epi32( INT32_C(  431380596),  INT32_C( -800905622),  INT32_C(-1090716510),  INT32_C(  598832812),
                             INT32_C(  183783146),  INT32_C( 1473748330),  INT32_C( 1405235121),  INT32_C( 1193787762)),
      simde_mm256_set_epi32( INT32_C( 1093676520),  INT32_C( -410887875),  INT32_C( 1548812312),  INT32_C( -913535121),
                             INT32_C(  183783146),  INT32_C(-1507745238),  INT32_C( 1405235121),  INT32_C( 1193787762)),
      simde_mm256_set_epi32( INT32_C(          0),  INT32_C(          0),  INT32_C(          0),  INT32_C(          0),
                             ~INT32_C(         0),  INT32_C(          0),  ~INT32_C(         0),  ~INT32_C(         0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cmpeq_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cmpeq_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x( INT64_C( 5666986029204224795),  INT64_C( 4139191150084672711),
                              INT64_C(-2995542033801296871),  INT64_C( 2916699395471658679)),
      simde_mm256_set_epi64x( INT64_C( 5666986029204224795),  INT64_C(-4286656252876457389),
                              INT64_C( 1630571993074201933),  INT64_C(-4091102519963379575)),
      simde_mm256_set_epi64x( INT64_C(                  -1),  INT64_C(                   0),
                              INT64_C(                   0),  INT64_C(                   0)) },
    { simde_mm256_set_epi64x( INT64_C( 3487161978562406497),  INT64_C( 3319820858778075593),
                              INT64_C(-2061262812497087366),  INT64_C( 3422398331177828808)),
      simde_mm256_set_epi64x( INT64_C( 3487161978562406497),  INT64_C( 3319820858778075593),
                              INT64_C( 4615290220825808616),  INT64_C(-1811913409974062507)),
      simde_mm256_set_epi64x( INT64_C(                  -1),  INT64_C(                  -1),
                              INT64_C(                   0),  INT64_C(                   0)) },
    { simde_mm256_set_epi64x( INT64_C( 6876132350949566240),  INT64_C(  286650737897020179),
                              INT64_C( 8647803947797074216),  INT64_C( 8045239586356137615)),
      simde_mm256_set_epi64x( INT64_C(-2007896190058863769),  INT64_C( 1398080065885028992),
                              INT64_C( 8575195519759543000),  INT64_C( 3842062270653749921)),
      simde_mm256_set_epi64x( INT64_C(                   0),  INT64_C(                   0),
                              INT64_C(                   0),  INT64_C(                   0)) },
    { simde_mm256_set_epi64x( INT64_C( -813114899828683326),  INT64_C( 8993356532590363052),
                              INT64_C( 1099980308418045920),  INT64_C( -959713571456510913)),
      simde_mm256_set_epi64x( INT64_C( -813114899828683326),  INT64_C( 8993356532590363052),
                              INT64_C( 2705033811286181232),  INT64_C(-9000650858577263758)),
      simde_mm256_set_epi64x( INT64_C(                  -1),  INT64_C(                  -1),
                              INT64_C(                   0),  INT64_C(                   0)) },
    { simde_mm256_set_epi64x( INT64_C(-2995469803746067901),  INT64_C( 8439110829491825822),
                              INT64_C(  622618816590200788),  INT64_C(-4486881289174213355)),
      simde_mm256_set_epi64x( INT64_C(-2995469803746067901),  INT64_C(-3762957269640528607),
                              INT64_C(  622618816590200788),  INT64_C(-3609138253339109026)),
      simde_mm256_set_epi64x( ~INT64_C(                  0),  INT64_C(                   0),
                              ~INT64_C(                  0),  INT64_C(                   0)) },
    { simde_mm256_set_epi64x( INT64_C(-1016066772373646945),  INT64_C( 3813602464259710788),
                              INT64_C( 7563424360708952600),  INT64_C(-5726115040178877821)),
      simde_mm256_set_epi64x( INT64_C(-1016066772373646945),  INT64_C( 3813602464259710788),
                              INT64_C(-7344230325683392237),  INT64_C(-5726115040178877821)),
      simde_mm256_set_epi64x( ~INT64_C(                  0),  ~INT64_C(                  0),
                              INT64_C(                   0),  ~INT64_C(                  0)) },
    { simde_mm256_set_epi64x( INT64_C(-5638985149235693304),  INT64_C( 3850441284517009347),
                              INT64_C(-7932931861129304736),  INT64_C(-7323455422359325640)),
      simde_mm256_set_epi64x( INT64_C(-6947747787688303029),  INT64_C( 7867789037175719368),
                              INT64_C(-7932931861129304736),  INT64_C(  356641616463870387)),
      simde_mm256_set_epi64x( INT64_C(                   0),  INT64_C(                   0),
                              ~INT64_C(                  0),  INT64_C(                   0)) },
    { simde_mm256_set_epi64x( INT64_C(-3620459218438416224),  INT64_C(-7960741818410807131),
                              INT64_C( 2210317486113607969),  INT64_C( 2056660070405601362)),
      simde_mm256_set_epi64x( INT64_C(  186345282622433582),  INT64_C(-7960741818410807131),
                              INT64_C( 2210317486113607969),  INT64_C( 8434183884659739058)),
      simde_mm256_set_epi64x( INT64_C(                   0),  ~INT64_C(                  0),
                              ~INT64_C(                  0),  INT64_C(                   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cmpeq_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cmpgt_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi16(INT16_C( 22495), INT16_C( -4666), INT16_C( 11364), INT16_C(  3408),
                            INT16_C( -7753), INT16_C( 22355), INT16_C( 25225), INT16_C(-16816),
                            INT16_C( 30843), INT16_C( 15445), INT16_C(-14188), INT16_C( 18672),
                            INT16_C(-17933), INT16_C( 19821), INT16_C( -7211), INT16_C( 10864)),
      simde_mm256_set_epi16(INT16_C(  -752), INT16_C(-15840), INT16_C(-30268), INT16_C( 11179),
                            INT16_C( 16785), INT16_C(-16319), INT16_C(  8147), INT16_C(-29538),
                            INT16_C( 19069), INT16_C( 27101), INT16_C( 26817), INT16_C(-21010),
                            INT16_C(-18350), INT16_C(  1385), INT16_C(-28379), INT16_C(-19254)),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1)) },
    { simde_mm256_set_epi16(INT16_C( 22399), INT16_C(   -10), INT16_C( 26109), INT16_C( 19317),
                            INT16_C( 26547), INT16_C( 21309), INT16_C(-21770), INT16_C(-29851),
                            INT16_C(  8254), INT16_C( -6152), INT16_C( 14575), INT16_C(-26009),
                            INT16_C( -9485), INT16_C(  5665), INT16_C( 19505), INT16_C( -7563)),
      simde_mm256_set_epi16(INT16_C( 14612), INT16_C(-31260), INT16_C(-18743), INT16_C( -4117),
                            INT16_C( 18997), INT16_C(-26816), INT16_C( 13752), INT16_C( 24083),
                            INT16_C(-17683), INT16_C(-12944), INT16_C(-20564), INT16_C( -4251),
                            INT16_C( -8899), INT16_C( -5996), INT16_C( 20472), INT16_C( -9514)),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(    -1)) },
    { simde_mm256_set_epi16(INT16_C( -1570), INT16_C(-21545), INT16_C(-26360), INT16_C( -8434),
                            INT16_C( -3275), INT16_C(-16762), INT16_C( -5746), INT16_C( 30695),
                            INT16_C(  2714), INT16_C( 10463), INT16_C(  9000), INT16_C(  9451),
                            INT16_C( 23785), INT16_C( 12389), INT16_C(-26622), INT16_C(-15647)),
      simde_mm256_set_epi16(INT16_C(  1010), INT16_C(-25985), INT16_C( 16762), INT16_C(  1632),
                            INT16_C(-18641), INT16_C( 15349), INT16_C(-16838), INT16_C(-20536),
                            INT16_C(-25875), INT16_C( 26970), INT16_C(-23524), INT16_C( 11391),
                            INT16_C(  3100), INT16_C(-31773), INT16_C( 26059), INT16_C( 11041)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(     0),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(     0)) },
    { simde_mm256_set_epi16(INT16_C( 23915), INT16_C(   959), INT16_C(-22514), INT16_C( 13747),
                            INT16_C(-26649), INT16_C( 22646), INT16_C( 13432), INT16_C( 27482),
                            INT16_C( 19401), INT16_C( 30181), INT16_C( 31161), INT16_C(-17967),
                            INT16_C(-19058), INT16_C( 31935), INT16_C( 11181), INT16_C( 23239)),
      simde_mm256_set_epi16(INT16_C(-28186), INT16_C(  2084), INT16_C( 31597), INT16_C(  7566),
                            INT16_C( 21799), INT16_C(-27106), INT16_C(  4736), INT16_C( 18793),
                            INT16_C(-13965), INT16_C(-17482), INT16_C( 12657), INT16_C(-20379),
                            INT16_C( 24896), INT16_C( 28918), INT16_C( 22577), INT16_C( 29712)),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0)) },
    { simde_mm256_set_epi16(INT16_C( 11952), INT16_C( 18081), INT16_C(  7197), INT16_C( -9524),
                            INT16_C( 18521), INT16_C(  8735), INT16_C( 31233), INT16_C(-18919),
                            INT16_C(  8906), INT16_C( 21111), INT16_C( 27720), INT16_C(  5158),
                            INT16_C(  2673), INT16_C( 31824), INT16_C(-18067), INT16_C(  -891)),
      simde_mm256_set_epi16(INT16_C(-18602), INT16_C( 15849), INT16_C(-28095), INT16_C( -3999),
                            INT16_C( 13518), INT16_C(-13535), INT16_C(-30865), INT16_C(   675),
                            INT16_C(-26284), INT16_C( -1429), INT16_C(-19333), INT16_C(-26108),
                            INT16_C( 10384), INT16_C(-21020), INT16_C(-15076), INT16_C( 30415)),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0)) },
    { simde_mm256_set_epi16(INT16_C(-31253), INT16_C( -5290), INT16_C(-20180), INT16_C(  8300),
                            INT16_C( 29534), INT16_C( 10169), INT16_C( 27568), INT16_C(-21872),
                            INT16_C( 20546), INT16_C(  3171), INT16_C( -5551), INT16_C( 13838),
                            INT16_C( 10100), INT16_C(-27385), INT16_C( 19172), INT16_C(-26206)),
      simde_mm256_set_epi16(INT16_C(-12916), INT16_C( 16100), INT16_C(-14860), INT16_C(  6730),
                            INT16_C(  2608), INT16_C(-17352), INT16_C( 13860), INT16_C(  6700),
                            INT16_C( -7357), INT16_C( -1733), INT16_C(  7387), INT16_C(  5378),
                            INT16_C(-19225), INT16_C( -5805), INT16_C(   154), INT16_C(-20617)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(     0), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(     0)) },
    { simde_mm256_set_epi16(INT16_C( 13973), INT16_C( 21863), INT16_C( -4187), INT16_C( 31713),
                            INT16_C( -2161), INT16_C(-12788), INT16_C( 13548), INT16_C( 19072),
                            INT16_C(-23365), INT16_C(  2809), INT16_C( 16101), INT16_C( -9274),
                            INT16_C( 12377), INT16_C( 26381), INT16_C( 29677), INT16_C(  4006)),
      simde_mm256_set_epi16(INT16_C( -9250), INT16_C(-11965), INT16_C(-16314), INT16_C( -8035),
                            INT16_C(-12852), INT16_C( -3996), INT16_C(  8694), INT16_C( -8455),
                            INT16_C( 12571), INT16_C(-15529), INT16_C( -8320), INT16_C( 14428),
                            INT16_C( -5397), INT16_C( 17843), INT16_C(  7761), INT16_C( -1266)),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(    -1), INT16_C(     0), INT16_C(    -1), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(    -1), INT16_C(    -1), INT16_C(    -1), INT16_C(    -1)) },
    { simde_mm256_set_epi16(INT16_C(  7404), INT16_C( 10935), INT16_C(-26115), INT16_C(  8618),
                            INT16_C(-27599), INT16_C( 31224), INT16_C(  4654), INT16_C(-18707),
                            INT16_C( 12785), INT16_C( 22785), INT16_C( 25148), INT16_C(-31622),
                            INT16_C( 17070), INT16_C(-22617), INT16_C(  6953), INT16_C(-14046)),
      simde_mm256_set_epi16(INT16_C(-11447), INT16_C( 18342), INT16_C(   563), INT16_C(-13432),
                            INT16_C( 21117), INT16_C( 29427), INT16_C( 31704), INT16_C( 14377),
                            INT16_C( 14770), INT16_C( -3712), INT16_C(  7229), INT16_C(-22634),
                            INT16_C( 28493), INT16_C(-28170), INT16_C(  5912), INT16_C(  7039)),
      simde_mm256_set_epi16(INT16_C(    -1), INT16_C(     0), INT16_C(     0), INT16_C(    -1),
                            INT16_C(     0), INT16_C(    -1), INT16_C(     0), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0),
                            INT16_C(     0), INT16_C(    -1), INT16_C(    -1), INT16_C(     0)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cmpgt_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cmpgt_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(-1910963751), INT32_C(-1037527336), INT32_C( -581253082), INT32_C( -805157505),
                            INT32_C( 1446966287), INT32_C(   -8913681), INT32_C( -494526366), INT32_C(-1857474161)),
      simde_mm256_set_epi32(INT32_C(-1143050049), INT32_C(-1545949366), INT32_C( 1503277288), INT32_C(-1357138171),
                            INT32_C( 1058844939), INT32_C(  309480335), INT32_C( 1825640960), INT32_C(-2083253752)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm256_set_epi32(INT32_C(-1125895018), INT32_C( -151199733), INT32_C(-1156572232), INT32_C(-1719423594),
                            INT32_C(-1350415044), INT32_C( 1941048360), INT32_C( 1462693644), INT32_C(  157276070)),
      simde_mm256_set_epi32(INT32_C( 1685470989), INT32_C(  -23549807), INT32_C( 2101982138), INT32_C(-1846214249),
                            INT32_C(-1855916776), INT32_C( -540831398), INT32_C(  233301808), INT32_C( 1667068415)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm256_set_epi32(INT32_C(-2064202369), INT32_C( -937796718), INT32_C( 1860922821), INT32_C( -943515104),
                            INT32_C( 1932702217), INT32_C(-1909235607), INT32_C( -701927701), INT32_C( 2122537608)),
      simde_mm256_set_epi32(INT32_C( 1359427872), INT32_C(  430067405), INT32_C(-2017266204), INT32_C( -112174075),
                            INT32_C(-2036257158), INT32_C(  794990098), INT32_C( 1595368835), INT32_C(-2025748789)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         -1), INT32_C(          0),
                            INT32_C(         -1), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { simde_mm256_set_epi32(INT32_C(  101914014), INT32_C( 1252307439), INT32_C( -251229086), INT32_C( 1747655874),
                            INT32_C( 1975156439), INT32_C(  244588822), INT32_C(-2030488384), INT32_C(  -41784348)),
      simde_mm256_set_epi32(INT32_C(  126704158), INT32_C(-1817043660), INT32_C(   67229317), INT32_C( 1709840887),
                            INT32_C( -401701180), INT32_C(-1816869894), INT32_C( -356935412), INT32_C( 1029497038)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) },
    { simde_mm256_set_epi32(INT32_C(-1821031073), INT32_C(-1888821389), INT32_C( 1302274763), INT32_C( -889069785),
                            INT32_C(  849224332), INT32_C( 1448513971), INT32_C(-1444618137), INT32_C( -857531383)),
      simde_mm256_set_epi32(INT32_C( -294182987), INT32_C(-1911426210), INT32_C( 1273887477), INT32_C( -804272895),
                            INT32_C(-1138168885), INT32_C(-1273049807), INT32_C( -920424822), INT32_C(   75748881)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(          0),
                            INT32_C(         -1), INT32_C(         -1), INT32_C(          0), INT32_C(          0)) },
    { simde_mm256_set_epi32(INT32_C( -145989095), INT32_C( 1224886052), INT32_C(-1270092347), INT32_C(-2004839127),
                            INT32_C( -805168375), INT32_C(-2053011497), INT32_C(  926069792), INT32_C( -523797780)),
      simde_mm256_set_epi32(INT32_C( 1782736183), INT32_C( 1196895214), INT32_C( 2023829967), INT32_C(  431966763),
                            INT32_C(-1279096565), INT32_C(-1568278654), INT32_C( -225755322), INT32_C(  800135833)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(          0),
                            INT32_C(         -1), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm256_set_epi32(INT32_C(   45181175), INT32_C( 2067174734), INT32_C(-1046962322), INT32_C( -770870625),
                            INT32_C(  166196701), INT32_C(-1211694319), INT32_C( 1891438592), INT32_C(-1986783509)),
      simde_mm256_set_epi32(INT32_C( 1357811899), INT32_C( -666006860), INT32_C(  -78093915), INT32_C(-1784875915),
                            INT32_C(-1592390514), INT32_C( -295345562), INT32_C(-1194315003), INT32_C( -378378269)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(         -1), INT32_C(          0), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(          0), INT32_C(         -1), INT32_C(          0)) },
    { simde_mm256_set_epi32(INT32_C( 2029570724), INT32_C(  593067919), INT32_C( 1378001411), INT32_C(-1490077172),
                            INT32_C( -985008502), INT32_C( -780769236), INT32_C(  983706005), INT32_C( -145048806)),
      simde_mm256_set_epi32(INT32_C( -371614648), INT32_C(  790968401), INT32_C(  604322541), INT32_C( 1275463353),
                            INT32_C(  507685025), INT32_C(-1785065497), INT32_C( -324987069), INT32_C( 1403024939)),
      simde_mm256_set_epi32(INT32_C(         -1), INT32_C(          0), INT32_C(         -1), INT32_C(          0),
                            INT32_C(          0), INT32_C(         -1), INT32_C(         -1), INT32_C(          0)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cmpgt_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cmpgt_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
      { simde_mm256_set_epi64x(INT64_C( 2118945800826688975), INT64_C(-2048024407550915063),
                             INT64_C( 5214505670652994271), INT64_C( -257856994503089701)),
      simde_mm256_set_epi64x(INT64_C( 5695011750507465952), INT64_C( -909596801509157384),
                             INT64_C( 8030198869340496548), INT64_C(  154404577117411578)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                   0)) },
    { simde_mm256_set_epi64x(INT64_C( 5911350820320548021), INT64_C( 1593992970237440641),
                             INT64_C( 1816057404225443518), INT64_C(-5807847363009183486)),
      simde_mm256_set_epi64x(INT64_C( 6716528373762493386), INT64_C(-8043125522610464194),
                             INT64_C( 8780083716644576089), INT64_C( 1141738695323567528)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                  -1),
                             INT64_C(                   0), INT64_C(                   0)) },
    { simde_mm256_set_epi64x(INT64_C( 2128200156105206458), INT64_C( 4268557007045133354),
                             INT64_C(  922795411729807384), INT64_C( -370673782849908924)),
      simde_mm256_set_epi64x(INT64_C(-4606711496612992363), INT64_C( 5770563142009272389),
                             INT64_C( 5439573582391425757), INT64_C( 3818549561656095124)),
      simde_mm256_set_epi64x(INT64_C(                  -1), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                   0)) },
    { simde_mm256_set_epi64x(INT64_C(-7763872078520682010), INT64_C( 8214461135943818795),
                             INT64_C( 6913361685886042209), INT64_C( 4675504907089870645)),
      simde_mm256_set_epi64x(INT64_C( 4559571845325885325), INT64_C(-5258431881764629271),
                             INT64_C( 5559569102824249097), INT64_C( 5799667037503013333)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                  -1),
                             INT64_C(                  -1), INT64_C(                   0)) },
    { simde_mm256_set_epi64x(INT64_C( 4800525853411880003), INT64_C( -184846840160593290),
                             INT64_C(-4953203027402144401), INT64_C( 2572609663077992835)),
      simde_mm256_set_epi64x(INT64_C(-5431416973650143300), INT64_C( 5030179310017915920),
                             INT64_C(-6125011459628645754), INT64_C(-8488302794525901027)),
      simde_mm256_set_epi64x(INT64_C(                  -1), INT64_C(                   0),
                             INT64_C(                  -1), INT64_C(                  -1)) },
    { simde_mm256_set_epi64x(INT64_C(-3860235829589315850), INT64_C( 8837948345888719516),
                             INT64_C( 3875197176959192831), INT64_C(-5180468743599698974)),
      simde_mm256_set_epi64x(INT64_C(-1290331525121336992), INT64_C(-2797732422128290053),
                             INT64_C(-1679378228033738615), INT64_C(-7981001780127731934)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                  -1),
                             INT64_C(                  -1), INT64_C(                  -1)) },
    { simde_mm256_set_epi64x(INT64_C(-1174099241428997420), INT64_C( -973237140110744253),
                             INT64_C(-2478103055519574033), INT64_C(-4160968278707001293)),
      simde_mm256_set_epi64x(INT64_C(-5836788839917359935), INT64_C( 9029070361682465515),
                             INT64_C( 7441474531728878768), INT64_C(-8910660672377811998)),
      simde_mm256_set_epi64x(INT64_C(                  -1), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                  -1)) },
    { simde_mm256_set_epi64x(INT64_C(  660412182468938166), INT64_C( 2628509021710534078),
                             INT64_C(-4480617326594733579), INT64_C( 6124790654743076244)),
      simde_mm256_set_epi64x(INT64_C(-2572783283758925366), INT64_C( 8355777023791813662),
                             INT64_C( 7632362282544129149), INT64_C(-5998036421176707691)),
      simde_mm256_set_epi64x(INT64_C(                  -1), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                  -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cmpgt_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_broadcastsi128_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x   (INT64_C( 3783485884510153131), INT64_C( 5322848723863790661)),
      simde_mm256_set_epi64x(INT64_C( 3783485884510153131), INT64_C( 5322848723863790661),
                             INT64_C( 3783485884510153131), INT64_C( 5322848723863790661)) },
    { simde_mm_set_epi64x   (INT64_C( 3709494745882156155), INT64_C(-6688158465955285293)),
      simde_mm256_set_epi64x(INT64_C( 3709494745882156155), INT64_C(-6688158465955285293),
                             INT64_C( 3709494745882156155), INT64_C(-6688158465955285293)) },
    { simde_mm_set_epi64x   (INT64_C(-8419237038829073489), INT64_C(-1707044583358729761)),
      simde_mm256_set_epi64x(INT64_C(-8419237038829073489), INT64_C(-1707044583358729761),
                             INT64_C(-8419237038829073489), INT64_C(-1707044583358729761)) },
    { simde_mm_set_epi64x   (INT64_C( -168447772491176834), INT64_C(-4784151950425519944)),
      simde_mm256_set_epi64x(INT64_C( -168447772491176834), INT64_C(-4784151950425519944),
                             INT64_C( -168447772491176834), INT64_C(-4784151950425519944)) },
    { simde_mm_set_epi64x   (INT64_C(  992172666234330248), INT64_C( 7115358650695109080)),
      simde_mm256_set_epi64x(INT64_C(  992172666234330248), INT64_C( 7115358650695109080),
                             INT64_C(  992172666234330248), INT64_C( 7115358650695109080)) },
    { simde_mm_set_epi64x   (INT64_C( 6019682307676879898), INT64_C( -745177675559433697)),
      simde_mm256_set_epi64x(INT64_C( 6019682307676879898), INT64_C( -745177675559433697),
                             INT64_C( 6019682307676879898), INT64_C( -745177675559433697)) },
    { simde_mm_set_epi64x   (INT64_C(-8364368011425569946), INT64_C( 1685080214233190853)),
      simde_mm256_set_epi64x(INT64_C(-8364368011425569946), INT64_C( 1685080214233190853),
                             INT64_C(-8364368011425569946), INT64_C( 1685080214233190853)) },
    { simde_mm_set_epi64x   (INT64_C( 6712859087758853138), INT64_C( 2170550621944299043)),
      simde_mm256_set_epi64x(INT64_C( 6712859087758853138), INT64_C( 2170550621944299043),
                             INT64_C( 6712859087758853138), INT64_C( 2170550621944299043)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_broadcastsi128_si256(test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepi8_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -64), INT8_C( -39), INT8_C(  -1), INT8_C( 123),
                        INT8_C( -41), INT8_C(  42), INT8_C( -42), INT8_C(  48),
                        INT8_C(-101), INT8_C( -11), INT8_C(  78), INT8_C( -33),
                        INT8_C(  -4), INT8_C( -46), INT8_C(-128), INT8_C( 115)),
      simde_mm256_set_epi16(INT16_C(   -64), INT16_C(   -39), INT16_C(    -1), INT16_C(   123),
                            INT16_C(   -41), INT16_C(    42), INT16_C(   -42), INT16_C(    48),
                            INT16_C(  -101), INT16_C(   -11), INT16_C(    78), INT16_C(   -33),
                            INT16_C(    -4), INT16_C(   -46), INT16_C(  -128), INT16_C(   115)) },
    { simde_mm_set_epi8(INT8_C( -82), INT8_C(  92), INT8_C(  55), INT8_C( -41),
                        INT8_C(  61), INT8_C(-113), INT8_C( 108), INT8_C(  36),
                        INT8_C( 115), INT8_C(  53), INT8_C( -46), INT8_C( -96),
                        INT8_C( -71), INT8_C( -38), INT8_C(  25), INT8_C(  61)),
      simde_mm256_set_epi16(INT16_C(   -82), INT16_C(    92), INT16_C(    55), INT16_C(   -41),
                            INT16_C(    61), INT16_C(  -113), INT16_C(   108), INT16_C(    36),
                            INT16_C(   115), INT16_C(    53), INT16_C(   -46), INT16_C(   -96),
                            INT16_C(   -71), INT16_C(   -38), INT16_C(    25), INT16_C(    61)) },
    { simde_mm_set_epi8(INT8_C( -73), INT8_C(   5), INT8_C(  10), INT8_C(-111),
                        INT8_C(-127), INT8_C(  16), INT8_C( -16), INT8_C(-115),
                        INT8_C(  94), INT8_C(  88), INT8_C( -20), INT8_C( -24),
                        INT8_C( -27), INT8_C( -17), INT8_C( -31), INT8_C(  67)),
      simde_mm256_set_epi16(INT16_C(   -73), INT16_C(     5), INT16_C(    10), INT16_C(  -111),
                            INT16_C(  -127), INT16_C(    16), INT16_C(   -16), INT16_C(  -115),
                            INT16_C(    94), INT16_C(    88), INT16_C(   -20), INT16_C(   -24),
                            INT16_C(   -27), INT16_C(   -17), INT16_C(   -31), INT16_C(    67)) },
    { simde_mm_set_epi8(INT8_C( -17), INT8_C(   8), INT8_C(  67), INT8_C( -40),
                        INT8_C(  99), INT8_C(  89), INT8_C( -60), INT8_C( -24),
                        INT8_C( 120), INT8_C( -29), INT8_C(-127), INT8_C(  15),
                        INT8_C( -40), INT8_C(-106), INT8_C(  13), INT8_C( -27)),
      simde_mm256_set_epi16(INT16_C(   -17), INT16_C(     8), INT16_C(    67), INT16_C(   -40),
                            INT16_C(    99), INT16_C(    89), INT16_C(   -60), INT16_C(   -24),
                            INT16_C(   120), INT16_C(   -29), INT16_C(  -127), INT16_C(    15),
                            INT16_C(   -40), INT16_C(  -106), INT16_C(    13), INT16_C(   -27)) },
    { simde_mm_set_epi8(INT8_C(  -5), INT8_C(  52), INT8_C( 112), INT8_C( -86),
                        INT8_C(   7), INT8_C(   2), INT8_C(  89), INT8_C(  40),
                        INT8_C(  34), INT8_C( -14), INT8_C(-119), INT8_C(-115),
                        INT8_C(-103), INT8_C( 103), INT8_C( -15), INT8_C( -68)),
      simde_mm256_set_epi16(INT16_C(    -5), INT16_C(    52), INT16_C(   112), INT16_C(   -86),
                            INT16_C(     7), INT16_C(     2), INT16_C(    89), INT16_C(    40),
                            INT16_C(    34), INT16_C(   -14), INT16_C(  -119), INT16_C(  -115),
                            INT16_C(  -103), INT16_C(   103), INT16_C(   -15), INT16_C(   -68)) },
    { simde_mm_set_epi8(INT8_C(  34), INT8_C( 104), INT8_C(-116), INT8_C(-106),
                        INT8_C(-122), INT8_C(  51), INT8_C( -86), INT8_C(  26),
                        INT8_C(  57), INT8_C(  23), INT8_C( 125), INT8_C(  20),
                        INT8_C(  40), INT8_C( -87), INT8_C( -60), INT8_C( -93)),
      simde_mm256_set_epi16(INT16_C(    34), INT16_C(   104), INT16_C(  -116), INT16_C(  -106),
                            INT16_C(  -122), INT16_C(    51), INT16_C(   -86), INT16_C(    26),
                            INT16_C(    57), INT16_C(    23), INT16_C(   125), INT16_C(    20),
                            INT16_C(    40), INT16_C(   -87), INT16_C(   -60), INT16_C(   -93)) },
    { simde_mm_set_epi8(INT8_C(  35), INT8_C( 103), INT8_C(  83), INT8_C(  11),
                        INT8_C(   5), INT8_C( -26), INT8_C( -34), INT8_C( -28),
                        INT8_C( -15), INT8_C(  -2), INT8_C(  10), INT8_C( -97),
                        INT8_C(  35), INT8_C(-108), INT8_C(  38), INT8_C(-122)),
      simde_mm256_set_epi16(INT16_C(    35), INT16_C(   103), INT16_C(    83), INT16_C(    11),
                            INT16_C(     5), INT16_C(   -26), INT16_C(   -34), INT16_C(   -28),
                            INT16_C(   -15), INT16_C(    -2), INT16_C(    10), INT16_C(   -97),
                            INT16_C(    35), INT16_C(  -108), INT16_C(    38), INT16_C(  -122)) },
    { simde_mm_set_epi8(INT8_C(  44), INT8_C(-101), INT8_C(-122), INT8_C(  91),
                        INT8_C(  60), INT8_C(  60), INT8_C(  22), INT8_C(  81),
                        INT8_C(  13), INT8_C(-111), INT8_C(-125), INT8_C( -40),
                        INT8_C( -72), INT8_C(-102), INT8_C( -87), INT8_C( 108)),
      simde_mm256_set_epi16(INT16_C(    44), INT16_C(  -101), INT16_C(  -122), INT16_C(    91),
                            INT16_C(    60), INT16_C(    60), INT16_C(    22), INT16_C(    81),
                            INT16_C(    13), INT16_C(  -111), INT16_C(  -125), INT16_C(   -40),
                            INT16_C(   -72), INT16_C(  -102), INT16_C(   -87), INT16_C(   108)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtepi8_epi16(test_vec[i].a);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepi8_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( 123), INT8_C(  -2), INT8_C( 102), INT8_C( -48),
                        INT8_C(  12), INT8_C(-119), INT8_C( -32), INT8_C(  68),
                        INT8_C( -88), INT8_C(  80), INT8_C(  32), INT8_C(-108),
                        INT8_C( -66), INT8_C(  35), INT8_C( -12), INT8_C(-103)),
      simde_mm256_set_epi32(INT32_C(        -88), INT32_C(         80), INT32_C(         32), INT32_C(       -108),
                            INT32_C(        -66), INT32_C(         35), INT32_C(        -12), INT32_C(       -103)) },
    { simde_mm_set_epi8(INT8_C( -12), INT8_C( -88), INT8_C( -20), INT8_C( -26),
                        INT8_C( -69), INT8_C( -40), INT8_C( 122), INT8_C(-121),
                        INT8_C(  47), INT8_C( 123), INT8_C( -15), INT8_C(-104),
                        INT8_C( -91), INT8_C( -13), INT8_C( -61), INT8_C(-104)),
      simde_mm256_set_epi32(INT32_C(         47), INT32_C(        123), INT32_C(        -15), INT32_C(       -104),
                            INT32_C(        -91), INT32_C(        -13), INT32_C(        -61), INT32_C(       -104)) },
    { simde_mm_set_epi8(INT8_C(-105), INT8_C(  35), INT8_C(-118), INT8_C( -44),
                        INT8_C( -91), INT8_C(  43), INT8_C(  18), INT8_C( -70),
                        INT8_C(  44), INT8_C(  98), INT8_C( -82), INT8_C(-126),
                        INT8_C( -80), INT8_C(-109), INT8_C(  69), INT8_C(-116)),
      simde_mm256_set_epi32(INT32_C(         44), INT32_C(         98), INT32_C(        -82), INT32_C(       -126),
                            INT32_C(        -80), INT32_C(       -109), INT32_C(         69), INT32_C(       -116)) },
    { simde_mm_set_epi8(INT8_C(  43), INT8_C(  92), INT8_C( -66), INT8_C( -32),
                        INT8_C(  71), INT8_C( -63), INT8_C(  51), INT8_C(  89),
                        INT8_C( 102), INT8_C(  -4), INT8_C( -28), INT8_C(  -5),
                        INT8_C(-107), INT8_C( -25), INT8_C(-107), INT8_C( -15)),
      simde_mm256_set_epi32(INT32_C(        102), INT32_C(         -4), INT32_C(        -28), INT32_C(         -5),
                            INT32_C(       -107), INT32_C(        -25), INT32_C(       -107), INT32_C(        -15)) },
    { simde_mm_set_epi8(INT8_C(  -7), INT8_C( -22), INT8_C(  -1), INT8_C(  29),
                        INT8_C(  -3), INT8_C( -97), INT8_C(  61), INT8_C( -36),
                        INT8_C( -81), INT8_C( -83), INT8_C(  54), INT8_C(  37),
                        INT8_C( -70), INT8_C( -70), INT8_C(  12), INT8_C( -61)),
      simde_mm256_set_epi32(INT32_C(        -81), INT32_C(        -83), INT32_C(         54), INT32_C(         37),
                            INT32_C(        -70), INT32_C(        -70), INT32_C(         12), INT32_C(        -61)) },
    { simde_mm_set_epi8(INT8_C(  88), INT8_C( -30), INT8_C( 125), INT8_C( -22),
                        INT8_C( -87), INT8_C(-109), INT8_C( -90), INT8_C( -86),
                        INT8_C(-124), INT8_C( -10), INT8_C(  57), INT8_C( -62),
                        INT8_C( -55), INT8_C(  40), INT8_C( -11), INT8_C(-100)),
      simde_mm256_set_epi32(INT32_C(       -124), INT32_C(        -10), INT32_C(         57), INT32_C(        -62),
                            INT32_C(        -55), INT32_C(         40), INT32_C(        -11), INT32_C(       -100)) },
    { simde_mm_set_epi8(INT8_C(  58), INT8_C(-110), INT8_C(  -6), INT8_C( -58),
                        INT8_C(-110), INT8_C( 125), INT8_C(  39), INT8_C( -82),
                        INT8_C( -88), INT8_C( 107), INT8_C(  76), INT8_C(  58),
                        INT8_C(  -2), INT8_C(-119), INT8_C( -27), INT8_C(  40)),
      simde_mm256_set_epi32(INT32_C(        -88), INT32_C(        107), INT32_C(         76), INT32_C(         58),
                            INT32_C(         -2), INT32_C(       -119), INT32_C(        -27), INT32_C(         40)) },
    { simde_mm_set_epi8(INT8_C(-110), INT8_C( -24), INT8_C( -33), INT8_C(-117),
                        INT8_C(  92), INT8_C( -35), INT8_C( 113), INT8_C(  13),
                        INT8_C(  46), INT8_C(-107), INT8_C(   4), INT8_C(   8),
                        INT8_C(  56), INT8_C(   9), INT8_C( 123), INT8_C(  36)),
      simde_mm256_set_epi32(INT32_C(         46), INT32_C(       -107), INT32_C(          4), INT32_C(          8),
                            INT32_C(         56), INT32_C(          9), INT32_C(        123), INT32_C(         36)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtepi8_epi32(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepi8_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(   9), INT8_C( -74), INT8_C( -52), INT8_C( -68),
                        INT8_C(  95), INT8_C( -10), INT8_C( -99), INT8_C( 121),
                        INT8_C(   1), INT8_C(  69), INT8_C( -36), INT8_C(-102),
                        INT8_C(-124), INT8_C( -93), INT8_C(-101), INT8_C(-118)),
      simde_mm256_set_epi64x(INT64_C(                -124), INT64_C(                 -93),
                             INT64_C(                -101), INT64_C(                -118)) },
    { simde_mm_set_epi8(INT8_C(-107), INT8_C( -34), INT8_C( -75), INT8_C( 119),
                        INT8_C( -79), INT8_C(-103), INT8_C(  -9), INT8_C(-121),
                        INT8_C( -51), INT8_C(   4), INT8_C(  89), INT8_C( 110),
                        INT8_C( 112), INT8_C(  67), INT8_C(-101), INT8_C(  87)),
      simde_mm256_set_epi64x(INT64_C(                 112), INT64_C(                  67),
                             INT64_C(                -101), INT64_C(                  87)) },
    { simde_mm_set_epi8(INT8_C( -85), INT8_C( 121), INT8_C(-116), INT8_C( 121),
                        INT8_C( -43), INT8_C( -80), INT8_C(   1), INT8_C(-102),
                        INT8_C(  39), INT8_C(-105), INT8_C( -26), INT8_C(  88),
                        INT8_C( -52), INT8_C(  61), INT8_C(-127), INT8_C(  21)),
      simde_mm256_set_epi64x(INT64_C(                 -52), INT64_C(                  61),
                             INT64_C(                -127), INT64_C(                  21)) },
    { simde_mm_set_epi8(INT8_C(  85), INT8_C(   1), INT8_C(  94), INT8_C(  60),
                        INT8_C( 102), INT8_C(   9), INT8_C( -56), INT8_C(  64),
                        INT8_C(-103), INT8_C( -86), INT8_C(  51), INT8_C(-126),
                        INT8_C(  -9), INT8_C(  88), INT8_C( -52), INT8_C(  13)),
      simde_mm256_set_epi64x(INT64_C(                  -9), INT64_C(                  88),
                             INT64_C(                 -52), INT64_C(                  13)) },
    { simde_mm_set_epi8(INT8_C(   0), INT8_C( -40), INT8_C(  42), INT8_C(  42),
                        INT8_C( 109), INT8_C(  -5), INT8_C( -28), INT8_C( -80),
                        INT8_C(  70), INT8_C(   6), INT8_C( -51), INT8_C(  17),
                        INT8_C(-105), INT8_C(-108), INT8_C(  14), INT8_C( -91)),
      simde_mm256_set_epi64x(INT64_C(                -105), INT64_C(                -108),
                             INT64_C(                  14), INT64_C(                 -91)) },
    { simde_mm_set_epi8(INT8_C( 125), INT8_C(-114), INT8_C( -39), INT8_C(-118),
                        INT8_C(  29), INT8_C( -81), INT8_C(-121), INT8_C( 115),
                        INT8_C(-128), INT8_C(  99), INT8_C(  64), INT8_C(   7),
                        INT8_C( 114), INT8_C(-101), INT8_C(-127), INT8_C(  30)),
      simde_mm256_set_epi64x(INT64_C(                 114), INT64_C(                -101),
                             INT64_C(                -127), INT64_C(                  30)) },
    { simde_mm_set_epi8(INT8_C(-126), INT8_C( 122), INT8_C(  50), INT8_C( 115),
                        INT8_C(  72), INT8_C( -56), INT8_C(  52), INT8_C( 125),
                        INT8_C(-104), INT8_C( -76), INT8_C(  65), INT8_C( 103),
                        INT8_C(-122), INT8_C( -36), INT8_C( -93), INT8_C( 110)),
      simde_mm256_set_epi64x(INT64_C(                -122), INT64_C(                 -36),
                             INT64_C(                 -93), INT64_C(                 110)) },
    { simde_mm_set_epi8(INT8_C( -80), INT8_C(  98), INT8_C(-119), INT8_C(  51),
                        INT8_C( -37), INT8_C( -17), INT8_C( -94), INT8_C(-122),
                        INT8_C(-114), INT8_C(  13), INT8_C( -75), INT8_C( 111),
                        INT8_C( -76), INT8_C( -15), INT8_C(  -1), INT8_C( -12)),
      simde_mm256_set_epi64x(INT64_C(                 -76), INT64_C(                 -15),
                             INT64_C(                  -1), INT64_C(                 -12)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtepi8_epi64(test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}


static MunitResult
test_simde_mm256_cvtepi16_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( 29201), INT16_C( 17763), INT16_C( 13480), INT16_C( 29487),
                         INT16_C( -6581), INT16_C( 13446), INT16_C( 26538), INT16_C( -3936)),
      simde_mm256_set_epi32(INT32_C(      29201), INT32_C(      17763), INT32_C(      13480), INT32_C(      29487),
                            INT32_C(      -6581), INT32_C(      13446), INT32_C(      26538), INT32_C(      -3936)) },
    { simde_mm_set_epi16(INT16_C( -3829), INT16_C( 12503), INT16_C( 10513), INT16_C( 11407),
                         INT16_C( 28611), INT16_C(  5727), INT16_C( 32199), INT16_C( 11434)),
      simde_mm256_set_epi32(INT32_C(      -3829), INT32_C(      12503), INT32_C(      10513), INT32_C(      11407),
                            INT32_C(      28611), INT32_C(       5727), INT32_C(      32199), INT32_C(      11434)) },
    { simde_mm_set_epi16(INT16_C( -4989), INT16_C(-23450), INT16_C(-15441), INT16_C( 22895),
                         INT16_C(  2927), INT16_C(-20709), INT16_C( -7582), INT16_C(-31347)),
      simde_mm256_set_epi32(INT32_C(      -4989), INT32_C(     -23450), INT32_C(     -15441), INT32_C(      22895),
                            INT32_C(       2927), INT32_C(     -20709), INT32_C(      -7582), INT32_C(     -31347)) },
    { simde_mm_set_epi16(INT16_C( 24635), INT16_C( 21162), INT16_C( 29781), INT16_C(  -488),
                         INT16_C( -6580), INT16_C(-27732), INT16_C(   607), INT16_C(-20782)),
      simde_mm256_set_epi32(INT32_C(      24635), INT32_C(      21162), INT32_C(      29781), INT32_C(       -488),
                            INT32_C(      -6580), INT32_C(     -27732), INT32_C(        607), INT32_C(     -20782)) },
    { simde_mm_set_epi16(INT16_C(  -401), INT16_C( -5605), INT16_C(-28681), INT16_C(  4577),
                         INT16_C( -9094), INT16_C(  6804), INT16_C( -9223), INT16_C( 10661)),
      simde_mm256_set_epi32(INT32_C(       -401), INT32_C(      -5605), INT32_C(     -28681), INT32_C(       4577),
                            INT32_C(      -9094), INT32_C(       6804), INT32_C(      -9223), INT32_C(      10661)) },
    { simde_mm_set_epi16(INT16_C(  2053), INT16_C(-19489), INT16_C(  7360), INT16_C( 16515),
                         INT16_C( 32080), INT16_C(-16555), INT16_C(-32752), INT16_C( 19001)),
      simde_mm256_set_epi32(INT32_C(       2053), INT32_C(     -19489), INT32_C(       7360), INT32_C(      16515),
                            INT32_C(      32080), INT32_C(     -16555), INT32_C(     -32752), INT32_C(      19001)) },
    { simde_mm_set_epi16(INT16_C(-31610), INT16_C(-22910), INT16_C( 22850), INT16_C(-27168),
                         INT16_C( 13092), INT16_C(-21449), INT16_C( 16024), INT16_C(  8597)),
      simde_mm256_set_epi32(INT32_C(     -31610), INT32_C(     -22910), INT32_C(      22850), INT32_C(     -27168),
                            INT32_C(      13092), INT32_C(     -21449), INT32_C(      16024), INT32_C(       8597)) },
    { simde_mm_set_epi16(INT16_C( 28081), INT16_C( -7416), INT16_C( 18632), INT16_C(-28896),
                         INT16_C(-23156), INT16_C(-15424), INT16_C(-13082), INT16_C( 23555)),
      simde_mm256_set_epi32(INT32_C(      28081), INT32_C(      -7416), INT32_C(      18632), INT32_C(     -28896),
                            INT32_C(     -23156), INT32_C(     -15424), INT32_C(     -13082), INT32_C(      23555)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtepi16_epi32(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepi16_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-31485), INT16_C(  6767), INT16_C( -1054), INT16_C(-15390),
                         INT16_C(-10897), INT16_C(-31336), INT16_C( -9551), INT16_C(  8617)),
      simde_mm256_set_epi64x(INT64_C(              -10897), INT64_C(              -31336),
                             INT64_C(               -9551), INT64_C(                8617)) },
    { simde_mm_set_epi16(INT16_C( 30988), INT16_C(  5181), INT16_C( 18938), INT16_C(-32273),
                         INT16_C(  5456), INT16_C( 19282), INT16_C(-21851), INT16_C( 27127)),
      simde_mm256_set_epi64x(INT64_C(                5456), INT64_C(               19282),
                             INT64_C(              -21851), INT64_C(               27127)) },
    { simde_mm_set_epi16(INT16_C( -7527), INT16_C(-20831), INT16_C( 23786), INT16_C(  3131),
                         INT16_C(-19886), INT16_C( -2045), INT16_C(-25062), INT16_C( -5779)),
      simde_mm256_set_epi64x(INT64_C(              -19886), INT64_C(               -2045),
                             INT64_C(              -25062), INT64_C(               -5779)) },
    { simde_mm_set_epi16(INT16_C( 31086), INT16_C( 22946), INT16_C( -1551), INT16_C(  9842),
                         INT16_C(-22586), INT16_C(  5015), INT16_C( 24465), INT16_C(-15199)),
      simde_mm256_set_epi64x(INT64_C(              -22586), INT64_C(                5015),
                             INT64_C(               24465), INT64_C(              -15199)) },
    { simde_mm_set_epi16(INT16_C( 20641), INT16_C(-16277), INT16_C( 32328), INT16_C( 21501),
                         INT16_C( 17537), INT16_C(-11745), INT16_C(-20371), INT16_C( 18200)),
      simde_mm256_set_epi64x(INT64_C(               17537), INT64_C(              -11745),
                             INT64_C(              -20371), INT64_C(               18200)) },
    { simde_mm_set_epi16(INT16_C(-26363), INT16_C(-18240), INT16_C( 21370), INT16_C(-23762),
                         INT16_C(  2610), INT16_C(  7301), INT16_C(-13295), INT16_C( 15532)),
      simde_mm256_set_epi64x(INT64_C(                2610), INT64_C(                7301),
                             INT64_C(              -13295), INT64_C(               15532)) },
    { simde_mm_set_epi16(INT16_C( -6112), INT16_C(-22921), INT16_C( -1544), INT16_C(-16225),
                         INT16_C( 14287), INT16_C(-23793), INT16_C(  5660), INT16_C(-22213)),
      simde_mm256_set_epi64x(INT64_C(               14287), INT64_C(              -23793),
                             INT64_C(                5660), INT64_C(              -22213)) },
    { simde_mm_set_epi16(INT16_C(  -130), INT16_C( -9648), INT16_C(-32446), INT16_C( 22661),
                         INT16_C( 18414), INT16_C(-28168), INT16_C( 10429), INT16_C(  9914)),
      simde_mm256_set_epi64x(INT64_C(               18414), INT64_C(              -28168),
                             INT64_C(               10429), INT64_C(                9914)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtepi16_epi64(test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepi32_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 2035310840), INT32_C(  817509407), INT32_C( 1530478738), INT32_C( 1934275633)),
      simde_mm256_set_epi64x(INT64_C(          2035310840), INT64_C(           817509407),
                             INT64_C(          1530478738), INT64_C(          1934275633)) },
    { simde_mm_set_epi32(INT32_C(-1872979628), INT32_C( 1510684699), INT32_C( -362741060), INT32_C(   56318596)),
      simde_mm256_set_epi64x(INT64_C(         -1872979628), INT64_C(          1510684699),
                             INT64_C(          -362741060), INT64_C(            56318596)) },
    { simde_mm_set_epi32(INT32_C(  -15196779), INT32_C(    3808236), INT32_C( -178294426), INT32_C(-1675394154)),
      simde_mm256_set_epi64x(INT64_C(           -15196779), INT64_C(             3808236),
                             INT64_C(          -178294426), INT64_C(         -1675394154)) },
    { simde_mm_set_epi32(INT32_C( 1742018933), INT32_C( -523666920), INT32_C(-1989565458), INT32_C( -138158906)),
      simde_mm256_set_epi64x(INT64_C(          1742018933), INT64_C(          -523666920),
                             INT64_C(         -1989565458), INT64_C(          -138158906)) },
    { simde_mm_set_epi32(INT32_C( -851329384), INT32_C(-2094859646), INT32_C(-1382699819), INT32_C( 2104722305)),
      simde_mm256_set_epi64x(INT64_C(          -851329384), INT64_C(         -2094859646),
                             INT64_C(         -1382699819), INT64_C(          2104722305)) },
    { simde_mm_set_epi32(INT32_C( 1596198624), INT32_C(-1923442761), INT32_C( 1335983203), INT32_C(-1180029731)),
      simde_mm256_set_epi64x(INT64_C(          1596198624), INT64_C(         -1923442761),
                             INT64_C(          1335983203), INT64_C(         -1180029731)) },
    { simde_mm_set_epi32(INT32_C(  599337487), INT32_C( 1023189876), INT32_C( 1555456525), INT32_C( -191457824)),
      simde_mm256_set_epi64x(INT64_C(           599337487), INT64_C(          1023189876),
                             INT64_C(          1555456525), INT64_C(          -191457824)) },
    { simde_mm_set_epi32(INT32_C( 2100212902), INT32_C( -853030753), INT32_C( -606897046), INT32_C(-1882381199)),
      simde_mm256_set_epi64x(INT64_C(          2100212902), INT64_C(          -853030753),
                             INT64_C(          -606897046), INT64_C(         -1882381199)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtepi32_epi64(test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepu8_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(UINT8_C(240), UINT8_C( 50), UINT8_C(144), UINT8_C(  4),
                          UINT8_C(  7), UINT8_C(233), UINT8_C(157), UINT8_C( 74),
                          UINT8_C(217), UINT8_C( 90), UINT8_C(141), UINT8_C(254),
                          UINT8_C(115), UINT8_C( 96), UINT8_C(126), UINT8_C( 23)),
      simde_mm256_set_epi16(INT16_C(   240), INT16_C(    50), INT16_C(   144), INT16_C(     4),
                            INT16_C(     7), INT16_C(   233), INT16_C(   157), INT16_C(    74),
                            INT16_C(   217), INT16_C(    90), INT16_C(   141), INT16_C(   254),
                            INT16_C(   115), INT16_C(    96), INT16_C(   126), INT16_C(    23)) },
    { simde_x_mm_set_epu8(UINT8_C( 79), UINT8_C(126), UINT8_C(254), UINT8_C( 77),
                          UINT8_C(225), UINT8_C( 76), UINT8_C( 61), UINT8_C(223),
                          UINT8_C( 95), UINT8_C(244), UINT8_C( 66), UINT8_C(  4),
                          UINT8_C(241), UINT8_C(112), UINT8_C(120), UINT8_C(166)),
      simde_mm256_set_epi16(INT16_C(    79), INT16_C(   126), INT16_C(   254), INT16_C(    77),
                            INT16_C(   225), INT16_C(    76), INT16_C(    61), INT16_C(   223),
                            INT16_C(    95), INT16_C(   244), INT16_C(    66), INT16_C(     4),
                            INT16_C(   241), INT16_C(   112), INT16_C(   120), INT16_C(   166)) },
    { simde_x_mm_set_epu8(UINT8_C( 56), UINT8_C(107), UINT8_C(114), UINT8_C( 86),
                          UINT8_C( 35), UINT8_C( 47), UINT8_C( 25), UINT8_C(187),
                          UINT8_C(176), UINT8_C( 49), UINT8_C(164), UINT8_C(236),
                          UINT8_C(110), UINT8_C( 61), UINT8_C( 64), UINT8_C( 42)),
      simde_mm256_set_epi16(INT16_C(    56), INT16_C(   107), INT16_C(   114), INT16_C(    86),
                            INT16_C(    35), INT16_C(    47), INT16_C(    25), INT16_C(   187),
                            INT16_C(   176), INT16_C(    49), INT16_C(   164), INT16_C(   236),
                            INT16_C(   110), INT16_C(    61), INT16_C(    64), INT16_C(    42)) },
    { simde_x_mm_set_epu8(UINT8_C( 54), UINT8_C(130), UINT8_C(171), UINT8_C( 76),
                          UINT8_C( 75), UINT8_C(192), UINT8_C(152), UINT8_C(247),
                          UINT8_C(165), UINT8_C(252), UINT8_C(115), UINT8_C( 73),
                          UINT8_C( 86), UINT8_C( 52), UINT8_C( 29), UINT8_C(227)),
      simde_mm256_set_epi16(INT16_C(    54), INT16_C(   130), INT16_C(   171), INT16_C(    76),
                            INT16_C(    75), INT16_C(   192), INT16_C(   152), INT16_C(   247),
                            INT16_C(   165), INT16_C(   252), INT16_C(   115), INT16_C(    73),
                            INT16_C(    86), INT16_C(    52), INT16_C(    29), INT16_C(   227)) },
    { simde_x_mm_set_epu8(UINT8_C(175), UINT8_C(214), UINT8_C(138), UINT8_C(132),
                          UINT8_C( 59), UINT8_C( 53), UINT8_C(175), UINT8_C( 98),
                          UINT8_C(195), UINT8_C(230), UINT8_C(207), UINT8_C(189),
                          UINT8_C(100), UINT8_C(255), UINT8_C( 84), UINT8_C(129)),
      simde_mm256_set_epi16(INT16_C(   175), INT16_C(   214), INT16_C(   138), INT16_C(   132),
                            INT16_C(    59), INT16_C(    53), INT16_C(   175), INT16_C(    98),
                            INT16_C(   195), INT16_C(   230), INT16_C(   207), INT16_C(   189),
                            INT16_C(   100), INT16_C(   255), INT16_C(    84), INT16_C(   129)) },
    { simde_x_mm_set_epu8(UINT8_C( 40), UINT8_C( 10), UINT8_C(243), UINT8_C( 28),
                          UINT8_C( 48), UINT8_C(231), UINT8_C(240), UINT8_C(  2),
                          UINT8_C(  1), UINT8_C( 20), UINT8_C(184), UINT8_C(244),
                          UINT8_C(174), UINT8_C(138), UINT8_C( 47), UINT8_C(122)),
      simde_mm256_set_epi16(INT16_C(    40), INT16_C(    10), INT16_C(   243), INT16_C(    28),
                            INT16_C(    48), INT16_C(   231), INT16_C(   240), INT16_C(     2),
                            INT16_C(     1), INT16_C(    20), INT16_C(   184), INT16_C(   244),
                            INT16_C(   174), INT16_C(   138), INT16_C(    47), INT16_C(   122)) },
    { simde_x_mm_set_epu8(UINT8_C( 90), UINT8_C(144), UINT8_C(116), UINT8_C( 64),
                          UINT8_C(250), UINT8_C(233), UINT8_C(185), UINT8_C(193),
                          UINT8_C(172), UINT8_C(128), UINT8_C( 92), UINT8_C(230),
                          UINT8_C(153), UINT8_C( 17), UINT8_C(  8), UINT8_C(121)),
      simde_mm256_set_epi16(INT16_C(    90), INT16_C(   144), INT16_C(   116), INT16_C(    64),
                            INT16_C(   250), INT16_C(   233), INT16_C(   185), INT16_C(   193),
                            INT16_C(   172), INT16_C(   128), INT16_C(    92), INT16_C(   230),
                            INT16_C(   153), INT16_C(    17), INT16_C(     8), INT16_C(   121)) },
    { simde_x_mm_set_epu8(UINT8_C(135), UINT8_C(132), UINT8_C(184), UINT8_C(244),
                          UINT8_C(164), UINT8_C( 94), UINT8_C(216), UINT8_C(238),
                          UINT8_C(112), UINT8_C(252), UINT8_C( 78), UINT8_C(150),
                          UINT8_C( 72), UINT8_C(215), UINT8_C(214), UINT8_C(215)),
      simde_mm256_set_epi16(INT16_C(   135), INT16_C(   132), INT16_C(   184), INT16_C(   244),
                            INT16_C(   164), INT16_C(    94), INT16_C(   216), INT16_C(   238),
                            INT16_C(   112), INT16_C(   252), INT16_C(    78), INT16_C(   150),
                            INT16_C(    72), INT16_C(   215), INT16_C(   214), INT16_C(   215)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtepu8_epi16(test_vec[i].a);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepu8_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(UINT8_C(240), UINT8_C( 50), UINT8_C(144), UINT8_C(  4),
                          UINT8_C(  7), UINT8_C(233), UINT8_C(157), UINT8_C( 74),
                          UINT8_C(217), UINT8_C( 90), UINT8_C(141), UINT8_C(254),
                          UINT8_C(115), UINT8_C( 96), UINT8_C(126), UINT8_C( 23)),
      simde_mm256_set_epi32(INT32_C(        217), INT32_C(         90), INT32_C(        141), INT32_C(        254),
                            INT32_C(        115), INT32_C(         96), INT32_C(        126), INT32_C(         23)) },
    { simde_x_mm_set_epu8(UINT8_C( 79), UINT8_C(126), UINT8_C(254), UINT8_C( 77),
                          UINT8_C(225), UINT8_C( 76), UINT8_C( 61), UINT8_C(223),
                          UINT8_C( 95), UINT8_C(244), UINT8_C( 66), UINT8_C(  4),
                          UINT8_C(241), UINT8_C(112), UINT8_C(120), UINT8_C(166)),
      simde_mm256_set_epi32(INT32_C(         95), INT32_C(        244), INT32_C(         66), INT32_C(          4),
                            INT32_C(        241), INT32_C(        112), INT32_C(        120), INT32_C(        166)) },
    { simde_x_mm_set_epu8(UINT8_C( 56), UINT8_C(107), UINT8_C(114), UINT8_C( 86),
                          UINT8_C( 35), UINT8_C( 47), UINT8_C( 25), UINT8_C(187),
                          UINT8_C(176), UINT8_C( 49), UINT8_C(164), UINT8_C(236),
                          UINT8_C(110), UINT8_C( 61), UINT8_C( 64), UINT8_C( 42)),
      simde_mm256_set_epi32(INT32_C(        176), INT32_C(         49), INT32_C(        164), INT32_C(        236),
                            INT32_C(        110), INT32_C(         61), INT32_C(         64), INT32_C(         42)) },
    { simde_x_mm_set_epu8(UINT8_C( 54), UINT8_C(130), UINT8_C(171), UINT8_C( 76),
                          UINT8_C( 75), UINT8_C(192), UINT8_C(152), UINT8_C(247),
                          UINT8_C(165), UINT8_C(252), UINT8_C(115), UINT8_C( 73),
                          UINT8_C( 86), UINT8_C( 52), UINT8_C( 29), UINT8_C(227)),
      simde_mm256_set_epi32(INT32_C(        165), INT32_C(        252), INT32_C(        115), INT32_C(         73),
                            INT32_C(         86), INT32_C(         52), INT32_C(         29), INT32_C(        227)) },
    { simde_x_mm_set_epu8(UINT8_C(175), UINT8_C(214), UINT8_C(138), UINT8_C(132),
                          UINT8_C( 59), UINT8_C( 53), UINT8_C(175), UINT8_C( 98),
                          UINT8_C(195), UINT8_C(230), UINT8_C(207), UINT8_C(189),
                          UINT8_C(100), UINT8_C(255), UINT8_C( 84), UINT8_C(129)),
      simde_mm256_set_epi32(INT32_C(        195), INT32_C(        230), INT32_C(        207), INT32_C(        189),
                            INT32_C(        100), INT32_C(        255), INT32_C(         84), INT32_C(        129)) },
    { simde_x_mm_set_epu8(UINT8_C( 40), UINT8_C( 10), UINT8_C(243), UINT8_C( 28),
                          UINT8_C( 48), UINT8_C(231), UINT8_C(240), UINT8_C(  2),
                          UINT8_C(  1), UINT8_C( 20), UINT8_C(184), UINT8_C(244),
                          UINT8_C(174), UINT8_C(138), UINT8_C( 47), UINT8_C(122)),
      simde_mm256_set_epi32(INT32_C(          1), INT32_C(         20), INT32_C(        184), INT32_C(        244),
                            INT32_C(        174), INT32_C(        138), INT32_C(         47), INT32_C(        122)) },
    { simde_x_mm_set_epu8(UINT8_C( 90), UINT8_C(144), UINT8_C(116), UINT8_C( 64),
                          UINT8_C(250), UINT8_C(233), UINT8_C(185), UINT8_C(193),
                          UINT8_C(172), UINT8_C(128), UINT8_C( 92), UINT8_C(230),
                          UINT8_C(153), UINT8_C( 17), UINT8_C(  8), UINT8_C(121)),
      simde_mm256_set_epi32(INT32_C(        172), INT32_C(        128), INT32_C(         92), INT32_C(        230),
                            INT32_C(        153), INT32_C(         17), INT32_C(          8), INT32_C(        121)) },
    { simde_x_mm_set_epu8(UINT8_C(135), UINT8_C(132), UINT8_C(184), UINT8_C(244),
                          UINT8_C(164), UINT8_C( 94), UINT8_C(216), UINT8_C(238),
                          UINT8_C(112), UINT8_C(252), UINT8_C( 78), UINT8_C(150),
                          UINT8_C( 72), UINT8_C(215), UINT8_C(214), UINT8_C(215)),
      simde_mm256_set_epi32(INT32_C(        112), INT32_C(        252), INT32_C(         78), INT32_C(        150),
                            INT32_C(         72), INT32_C(        215), INT32_C(        214), INT32_C(        215)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtepu8_epi32(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepu8_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(UINT8_C(  9), UINT8_C(182), UINT8_C(204), UINT8_C(188),
                          UINT8_C( 95), UINT8_C(246), UINT8_C(157), UINT8_C(121),
                          UINT8_C(  1), UINT8_C( 69), UINT8_C(220), UINT8_C(154),
                          UINT8_C(132), UINT8_C(163), UINT8_C(155), UINT8_C(138)),
      simde_mm256_set_epi64x(INT64_C(                 132), INT64_C(                 163),
                             INT64_C(                 155), INT64_C(                 138)) },
    { simde_x_mm_set_epu8(UINT8_C(149), UINT8_C(222), UINT8_C(181), UINT8_C(119),
                          UINT8_C(177), UINT8_C(153), UINT8_C(247), UINT8_C(135),
                          UINT8_C(205), UINT8_C(  4), UINT8_C( 89), UINT8_C(110),
                          UINT8_C(112), UINT8_C( 67), UINT8_C(155), UINT8_C( 87)),
      simde_mm256_set_epi64x(INT64_C(                 112), INT64_C(                  67),
                             INT64_C(                 155), INT64_C(                  87)) },
    { simde_x_mm_set_epu8(UINT8_C(171), UINT8_C(121), UINT8_C(140), UINT8_C(121),
                          UINT8_C(213), UINT8_C(176), UINT8_C(  1), UINT8_C(154),
                          UINT8_C( 39), UINT8_C(151), UINT8_C(230), UINT8_C( 88),
                          UINT8_C(204), UINT8_C( 61), UINT8_C(129), UINT8_C( 21)),
      simde_mm256_set_epi64x(INT64_C(                 204), INT64_C(                  61),
                             INT64_C(                 129), INT64_C(                  21)) },
    { simde_x_mm_set_epu8(UINT8_C( 85), UINT8_C(  1), UINT8_C( 94), UINT8_C( 60),
                          UINT8_C(102), UINT8_C(  9), UINT8_C(200), UINT8_C( 64),
                          UINT8_C(153), UINT8_C(170), UINT8_C( 51), UINT8_C(130),
                          UINT8_C(247), UINT8_C( 88), UINT8_C(204), UINT8_C( 13)),
      simde_mm256_set_epi64x(INT64_C(                 247), INT64_C(                  88),
                             INT64_C(                 204), INT64_C(                  13)) },
    { simde_x_mm_set_epu8(UINT8_C(  0), UINT8_C(216), UINT8_C( 42), UINT8_C( 42),
                          UINT8_C(109), UINT8_C(251), UINT8_C(228), UINT8_C(176),
                          UINT8_C( 70), UINT8_C(  6), UINT8_C(205), UINT8_C( 17),
                          UINT8_C(151), UINT8_C(148), UINT8_C( 14), UINT8_C(165)),
      simde_mm256_set_epi64x(INT64_C(                 151), INT64_C(                 148),
                             INT64_C(                  14), INT64_C(                 165)) },
    { simde_x_mm_set_epu8(UINT8_C(125), UINT8_C(142), UINT8_C(217), UINT8_C(138),
                          UINT8_C( 29), UINT8_C(175), UINT8_C(135), UINT8_C(115),
                          UINT8_C(128), UINT8_C( 99), UINT8_C( 64), UINT8_C(  7),
                          UINT8_C(114), UINT8_C(155), UINT8_C(129), UINT8_C( 30)),
      simde_mm256_set_epi64x(INT64_C(                 114), INT64_C(                 155),
                             INT64_C(                 129), INT64_C(                  30)) },
    { simde_x_mm_set_epu8(UINT8_C(130), UINT8_C(122), UINT8_C( 50), UINT8_C(115),
                          UINT8_C( 72), UINT8_C(200), UINT8_C( 52), UINT8_C(125),
                          UINT8_C(152), UINT8_C(180), UINT8_C( 65), UINT8_C(103),
                          UINT8_C(134), UINT8_C(220), UINT8_C(163), UINT8_C(110)),
      simde_mm256_set_epi64x(INT64_C(                 134), INT64_C(                 220),
                             INT64_C(                 163), INT64_C(                 110)) },
    { simde_x_mm_set_epu8(UINT8_C(176), UINT8_C( 98), UINT8_C(137), UINT8_C( 51),
                          UINT8_C(219), UINT8_C(239), UINT8_C(162), UINT8_C(134),
                          UINT8_C(142), UINT8_C( 13), UINT8_C(181), UINT8_C(111),
                          UINT8_C(180), UINT8_C(241), UINT8_C(255), UINT8_C(244)),
      simde_mm256_set_epi64x(INT64_C(                 180), INT64_C(                 241),
                             INT64_C(                 255), INT64_C(                 244)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtepu8_epi64(test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepu16_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(UINT16_C(61490), UINT16_C(36868), UINT16_C( 2025), UINT16_C(40266),
                           UINT16_C(55642), UINT16_C(36350), UINT16_C(29536), UINT16_C(32279)),
      simde_mm256_set_epi32(INT32_C(      61490), INT32_C(      36868), INT32_C(       2025), INT32_C(      40266),
                            INT32_C(      55642), INT32_C(      36350), INT32_C(      29536), INT32_C(      32279)) },
    { simde_x_mm_set_epu16(UINT16_C(20350), UINT16_C(65101), UINT16_C(57676), UINT16_C(15839),
                           UINT16_C(24564), UINT16_C(16900), UINT16_C(61808), UINT16_C(30886)),
      simde_mm256_set_epi32(INT32_C(      20350), INT32_C(      65101), INT32_C(      57676), INT32_C(      15839),
                            INT32_C(      24564), INT32_C(      16900), INT32_C(      61808), INT32_C(      30886)) },
    { simde_x_mm_set_epu16(UINT16_C(14443), UINT16_C(29270), UINT16_C( 9007), UINT16_C( 6587),
                           UINT16_C(45105), UINT16_C(42220), UINT16_C(28221), UINT16_C(16426)),
      simde_mm256_set_epi32(INT32_C(      14443), INT32_C(      29270), INT32_C(       9007), INT32_C(       6587),
                            INT32_C(      45105), INT32_C(      42220), INT32_C(      28221), INT32_C(      16426)) },
    { simde_x_mm_set_epu16(UINT16_C(13954), UINT16_C(43852), UINT16_C(19392), UINT16_C(39159),
                           UINT16_C(42492), UINT16_C(29513), UINT16_C(22068), UINT16_C( 7651)),
      simde_mm256_set_epi32(INT32_C(      13954), INT32_C(      43852), INT32_C(      19392), INT32_C(      39159),
                            INT32_C(      42492), INT32_C(      29513), INT32_C(      22068), INT32_C(       7651)) },
    { simde_x_mm_set_epu16(UINT16_C(45014), UINT16_C(35460), UINT16_C(15157), UINT16_C(44898),
                           UINT16_C(50150), UINT16_C(53181), UINT16_C(25855), UINT16_C(21633)),
      simde_mm256_set_epi32(INT32_C(      45014), INT32_C(      35460), INT32_C(      15157), INT32_C(      44898),
                            INT32_C(      50150), INT32_C(      53181), INT32_C(      25855), INT32_C(      21633)) },
    { simde_x_mm_set_epu16(UINT16_C(10250), UINT16_C(62236), UINT16_C(12519), UINT16_C(61442),
                           UINT16_C(  276), UINT16_C(47348), UINT16_C(44682), UINT16_C(12154)),
      simde_mm256_set_epi32(INT32_C(      10250), INT32_C(      62236), INT32_C(      12519), INT32_C(      61442),
                            INT32_C(        276), INT32_C(      47348), INT32_C(      44682), INT32_C(      12154)) },
    { simde_x_mm_set_epu16(UINT16_C(23184), UINT16_C(29760), UINT16_C(64233), UINT16_C(47553),
                           UINT16_C(44160), UINT16_C(23782), UINT16_C(39185), UINT16_C( 2169)),
      simde_mm256_set_epi32(INT32_C(      23184), INT32_C(      29760), INT32_C(      64233), INT32_C(      47553),
                            INT32_C(      44160), INT32_C(      23782), INT32_C(      39185), INT32_C(       2169)) },
    { simde_x_mm_set_epu16(UINT16_C(34692), UINT16_C(47348), UINT16_C(42078), UINT16_C(55534),
                           UINT16_C(28924), UINT16_C(20118), UINT16_C(18647), UINT16_C(54999)),
      simde_mm256_set_epi32(INT32_C(      34692), INT32_C(      47348), INT32_C(      42078), INT32_C(      55534),
                            INT32_C(      28924), INT32_C(      20118), INT32_C(      18647), INT32_C(      54999)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtepu16_epi32(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepu16_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(UINT16_C(61490), UINT16_C(36868), UINT16_C( 2025), UINT16_C(40266),
                           UINT16_C(55642), UINT16_C(36350), UINT16_C(29536), UINT16_C(32279)),
      simde_mm256_set_epi64x(INT64_C(               55642), INT64_C(               36350),
                             INT64_C(               29536), INT64_C(               32279)) },
    { simde_x_mm_set_epu16(UINT16_C(20350), UINT16_C(65101), UINT16_C(57676), UINT16_C(15839),
                           UINT16_C(24564), UINT16_C(16900), UINT16_C(61808), UINT16_C(30886)),
      simde_mm256_set_epi64x(INT64_C(               24564), INT64_C(               16900),
                             INT64_C(               61808), INT64_C(               30886)) },
    { simde_x_mm_set_epu16(UINT16_C(14443), UINT16_C(29270), UINT16_C( 9007), UINT16_C( 6587),
                           UINT16_C(45105), UINT16_C(42220), UINT16_C(28221), UINT16_C(16426)),
      simde_mm256_set_epi64x(INT64_C(               45105), INT64_C(               42220),
                             INT64_C(               28221), INT64_C(               16426)) },
    { simde_x_mm_set_epu16(UINT16_C(13954), UINT16_C(43852), UINT16_C(19392), UINT16_C(39159),
                           UINT16_C(42492), UINT16_C(29513), UINT16_C(22068), UINT16_C( 7651)),
      simde_mm256_set_epi64x(INT64_C(               42492), INT64_C(               29513),
                             INT64_C(               22068), INT64_C(                7651)) },
    { simde_x_mm_set_epu16(UINT16_C(45014), UINT16_C(35460), UINT16_C(15157), UINT16_C(44898),
                           UINT16_C(50150), UINT16_C(53181), UINT16_C(25855), UINT16_C(21633)),
      simde_mm256_set_epi64x(INT64_C(               50150), INT64_C(               53181),
                             INT64_C(               25855), INT64_C(               21633)) },
    { simde_x_mm_set_epu16(UINT16_C(10250), UINT16_C(62236), UINT16_C(12519), UINT16_C(61442),
                           UINT16_C(  276), UINT16_C(47348), UINT16_C(44682), UINT16_C(12154)),
      simde_mm256_set_epi64x(INT64_C(                 276), INT64_C(               47348),
                             INT64_C(               44682), INT64_C(               12154)) },
    { simde_x_mm_set_epu16(UINT16_C(23184), UINT16_C(29760), UINT16_C(64233), UINT16_C(47553),
                           UINT16_C(44160), UINT16_C(23782), UINT16_C(39185), UINT16_C( 2169)),
      simde_mm256_set_epi64x(INT64_C(               44160), INT64_C(               23782),
                             INT64_C(               39185), INT64_C(                2169)) },
    { simde_x_mm_set_epu16(UINT16_C(34692), UINT16_C(47348), UINT16_C(42078), UINT16_C(55534),
                           UINT16_C(28924), UINT16_C(20118), UINT16_C(18647), UINT16_C(54999)),
      simde_mm256_set_epi64x(INT64_C(               28924), INT64_C(               20118),
                             INT64_C(               18647), INT64_C(               54999)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtepu16_epi64(test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepu32_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C(2027668512), UINT32_C(4262540660), UINT32_C(2279720356), UINT32_C( 579063940)),
      simde_mm256_set_epi64x(INT64_C(          2027668512), INT64_C(          4262540660),
                             INT64_C(          2279720356), INT64_C(           579063940)) },
    { simde_x_mm_set_epu32(UINT32_C( 214101781), UINT32_C(2515026933), UINT32_C(  10021235), UINT32_C(4284419101)),
      simde_mm256_set_epi64x(INT64_C(           214101781), INT64_C(          2515026933),
                             INT64_C(            10021235), INT64_C(          4284419101)) },
    { simde_x_mm_set_epu32(UINT32_C(2492492584), UINT32_C(1475674737), UINT32_C( 145233694), UINT32_C(2838555915)),
      simde_mm256_set_epi64x(INT64_C(          2492492584), INT64_C(          1475674737),
                             INT64_C(           145233694), INT64_C(          2838555915)) },
    { simde_x_mm_set_epu32(UINT32_C(3488754722), UINT32_C(2142666247), UINT32_C(4044693026), UINT32_C( 975481583)),
      simde_mm256_set_epi64x(INT64_C(          3488754722), INT64_C(          2142666247),
                             INT64_C(          4044693026), INT64_C(           975481583)) },
    { simde_x_mm_set_epu32(UINT32_C(3942926803), UINT32_C(  10053147), UINT32_C(3324554936), UINT32_C( 275092283)),
      simde_mm256_set_epi64x(INT64_C(          3942926803), INT64_C(            10053147),
                             INT64_C(          3324554936), INT64_C(           275092283)) },
    { simde_x_mm_set_epu32(UINT32_C( 609927901), UINT32_C(4032952140), UINT32_C(2163741382), UINT32_C(1197307836)),
      simde_mm256_set_epi64x(INT64_C(           609927901), INT64_C(          4032952140),
                             INT64_C(          2163741382), INT64_C(          1197307836)) },
    { simde_x_mm_set_epu32(UINT32_C( 667494753), UINT32_C(  25338810), UINT32_C( 229628292), UINT32_C(1413771580)),
      simde_mm256_set_epi64x(INT64_C(           667494753), INT64_C(            25338810),
                             INT64_C(           229628292), INT64_C(          1413771580)) },
    { simde_x_mm_set_epu32(UINT32_C(3461166204), UINT32_C(2882591041), UINT32_C(4038947223), UINT32_C(3672325978)),
      simde_mm256_set_epi64x(INT64_C(          3461166204), INT64_C(          2882591041),
                             INT64_C(          4038947223), INT64_C(          3672325978)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtepu32_epi64(test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_extract_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    int index;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C(  85), INT8_C(-106), INT8_C(  44), INT8_C( -49),
                           INT8_C( 119), INT8_C(  80), INT8_C( 116), INT8_C( -43),
                           INT8_C( -47), INT8_C( -11), INT8_C(  62), INT8_C( -51),
                           INT8_C( -20), INT8_C( -60), INT8_C(-115), INT8_C(   4),
                           INT8_C( 127), INT8_C( -43), INT8_C( -71), INT8_C(  56),
                           INT8_C( -31), INT8_C(  66), INT8_C(  34), INT8_C(-119),
                           INT8_C(  19), INT8_C(  36), INT8_C( -12), INT8_C( 112),
                           INT8_C(  60), INT8_C(  83), INT8_C(-120), INT8_C(  56)),
      31, 85 },
    { simde_mm256_set_epi8(INT8_C(  18), INT8_C(  -1), INT8_C(  58), INT8_C(  88),
                           INT8_C( 126), INT8_C(  33), INT8_C( -76), INT8_C(  89),
                           INT8_C( 117), INT8_C(  96), INT8_C(  36), INT8_C( -36),
                           INT8_C( 119), INT8_C(  42), INT8_C(  42), INT8_C(  20),
                           INT8_C(  29), INT8_C(  56), INT8_C(  62), INT8_C(  24),
                           INT8_C( 114), INT8_C(  -2), INT8_C(  32), INT8_C( -56),
                           INT8_C( -33), INT8_C( -80), INT8_C( 116), INT8_C(  62),
                           INT8_C( -70), INT8_C( -24), INT8_C( 104), INT8_C( 113)),
      2, -24 },
    { simde_mm256_set_epi8(INT8_C( 126), INT8_C(-115), INT8_C(-111), INT8_C( 126),
                           INT8_C(  64), INT8_C(  84), INT8_C(-101), INT8_C( -21),
                           INT8_C(  63), INT8_C( -34), INT8_C( -47), INT8_C( 123),
                           INT8_C(  67), INT8_C( -48), INT8_C( -40), INT8_C( -10),
                           INT8_C( -48), INT8_C(-117), INT8_C( 115), INT8_C( -29),
                           INT8_C(  -9), INT8_C(  82), INT8_C(  65), INT8_C(  40),
                           INT8_C(   0), INT8_C(  84), INT8_C(  65), INT8_C( -33),
                           INT8_C( 106), INT8_C(  47), INT8_C( -38), INT8_C(  57)),
      12, -29 },
    { simde_mm256_set_epi8(INT8_C(  -5), INT8_C(-104), INT8_C(  70), INT8_C( 103),
                           INT8_C(  37), INT8_C( -19), INT8_C(  55), INT8_C(  18),
                           INT8_C(  29), INT8_C( -66), INT8_C(-109), INT8_C(-128),
                           INT8_C(  94), INT8_C( -29), INT8_C( -29), INT8_C( -32),
                           INT8_C( -43), INT8_C(  55), INT8_C(  69), INT8_C( -62),
                           INT8_C( -91), INT8_C( -92), INT8_C(  80), INT8_C( -28),
                           INT8_C( -29), INT8_C( -53), INT8_C(-109), INT8_C( -97),
                           INT8_C(  13), INT8_C( -90), INT8_C( -67), INT8_C( -51)),
      29, 70 },
    { simde_mm256_set_epi8(INT8_C(  92), INT8_C(  10), INT8_C( 114), INT8_C( -32),
                           INT8_C(-114), INT8_C( -95), INT8_C( -42), INT8_C(  32),
                           INT8_C( -76), INT8_C( 127), INT8_C(  62), INT8_C(  11),
                           INT8_C( 127), INT8_C(  98), INT8_C(   5), INT8_C( -14),
                           INT8_C( -11), INT8_C( -28), INT8_C(-127), INT8_C(  51),
                           INT8_C( -66), INT8_C(  94), INT8_C(  -6), INT8_C(   7),
                           INT8_C( -95), INT8_C( -38), INT8_C(  -3), INT8_C(-103),
                           INT8_C( -87), INT8_C( 100), INT8_C(-113), INT8_C(  87)),
      22, 127 },
    { simde_mm256_set_epi8(INT8_C( -54), INT8_C(  70), INT8_C( 120), INT8_C( -67),
                           INT8_C(  17), INT8_C(  73), INT8_C(  40), INT8_C(-111),
                           INT8_C( 115), INT8_C( -79), INT8_C( -43), INT8_C(-120),
                           INT8_C(  70), INT8_C(  68), INT8_C( -87), INT8_C( -94),
                           INT8_C( 122), INT8_C( -19), INT8_C(-114), INT8_C(  82),
                           INT8_C(  81), INT8_C(  36), INT8_C(  42), INT8_C(-128),
                           INT8_C(  -8), INT8_C(  49), INT8_C( -14), INT8_C( -85),
                           INT8_C( -12), INT8_C( -81), INT8_C(  99), INT8_C(  11)),
      15, 122 },
    { simde_mm256_set_epi8(INT8_C(  27), INT8_C(  67), INT8_C( -85), INT8_C( -45),
                           INT8_C(-107), INT8_C(  17), INT8_C( -93), INT8_C( -57),
                           INT8_C(-113), INT8_C( -70), INT8_C(  37), INT8_C(  35),
                           INT8_C( -58), INT8_C(-116), INT8_C(  52), INT8_C( -81),
                           INT8_C( -49), INT8_C( -86), INT8_C( -44), INT8_C(  70),
                           INT8_C(  40), INT8_C(  67), INT8_C(  17), INT8_C( -49),
                           INT8_C(-118), INT8_C( -65), INT8_C(  29), INT8_C( -74),
                           INT8_C(   2), INT8_C(-103), INT8_C(  55), INT8_C(-109)),
      19, -58 },
    { simde_mm256_set_epi8(INT8_C( 104), INT8_C(  -9), INT8_C( 103), INT8_C( -86),
                           INT8_C(   0), INT8_C(  11), INT8_C(-114), INT8_C( -78),
                           INT8_C(-128), INT8_C(  29), INT8_C(  27), INT8_C(-121),
                           INT8_C( -68), INT8_C(   9), INT8_C(   6), INT8_C( 111),
                           INT8_C(-117), INT8_C(  82), INT8_C(  75), INT8_C(  -2),
                           INT8_C(-105), INT8_C(  43), INT8_C( 116), INT8_C( -47),
                           INT8_C(  14), INT8_C(  41), INT8_C(  29), INT8_C(  -4),
                           INT8_C( -87), INT8_C( 114), INT8_C( -11), INT8_C(-103)),
      1, -11 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_extract_epi8(test_vec[i].a, test_vec[i].index);
    simde_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_extract_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    int index;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_epi16(INT16_C(-13852), INT16_C( -4342), INT16_C( 11109), INT16_C(-14025),
                            INT16_C(-31515), INT16_C(-26078), INT16_C( 28328), INT16_C( 27282),
                            INT16_C(   502), INT16_C(  4002), INT16_C(-24127), INT16_C(-19778),
                            INT16_C( -5333), INT16_C( -7161), INT16_C(  3486), INT16_C( 19428)),
       9,  28328 },
    { simde_mm256_set_epi16(INT16_C( 28377), INT16_C(  2705), INT16_C(-30669), INT16_C( 14223),
                            INT16_C(-12947), INT16_C(  3902), INT16_C(-31300), INT16_C(-16108),
                            INT16_C( 27185), INT16_C( 31404), INT16_C(  5864), INT16_C(-14684),
                            INT16_C(-16906), INT16_C(-22077), INT16_C( 29573), INT16_C(-29418)),
      14,   2705 },
    { simde_mm256_set_epi16(INT16_C(-27124), INT16_C( 25225), INT16_C(-21524), INT16_C(-25020),
                            INT16_C(-23283), INT16_C( 23354), INT16_C(  6766), INT16_C( 14439),
                            INT16_C( 30011), INT16_C( 12305), INT16_C( -6826), INT16_C( -1503),
                            INT16_C(-14868), INT16_C( -9131), INT16_C( 13807), INT16_C( 20111)),
       3, -14868 },
    { simde_mm256_set_epi16(INT16_C( -7451), INT16_C( 13959), INT16_C( 22108), INT16_C(-25977),
                            INT16_C( 24961), INT16_C(  5172), INT16_C(-22669), INT16_C( 24596),
                            INT16_C( -9625), INT16_C(  8329), INT16_C( 31660), INT16_C(  6372),
                            INT16_C( 22842), INT16_C( -8967), INT16_C(-28506), INT16_C(-25290)),
      15,  -7451 },
    { simde_mm256_set_epi16(INT16_C( -7088), INT16_C(-28965), INT16_C( 12247), INT16_C( 20030),
                            INT16_C(-11225), INT16_C(  9910), INT16_C(  8285), INT16_C(-29915),
                            INT16_C( 31449), INT16_C(-30562), INT16_C(  9135), INT16_C( -5794),
                            INT16_C(-28133), INT16_C( 19959), INT16_C( 11053), INT16_C( 15927)),
      14, -28965 },
    { simde_mm256_set_epi16(INT16_C(-29242), INT16_C( -8879), INT16_C( 20658), INT16_C(  6689),
                            INT16_C(-32364), INT16_C( -6586), INT16_C(-25712), INT16_C(-15508),
                            INT16_C(-18619), INT16_C(  3648), INT16_C(-11317), INT16_C(-24552),
                            INT16_C(  5053), INT16_C( 19407), INT16_C(  7336), INT16_C( 21360)),
      10,  -6586 },
    { simde_mm256_set_epi16(INT16_C(-14447), INT16_C( 22067), INT16_C( 23031), INT16_C( 30523),
                            INT16_C( 22048), INT16_C( 13854), INT16_C(  3679), INT16_C( -6779),
                            INT16_C(-19554), INT16_C( -6724), INT16_C( -2267), INT16_C(-22355),
                            INT16_C(-10286), INT16_C(-26978), INT16_C(-13753), INT16_C(-10708)),
       6,  -6724 },
    { simde_mm256_set_epi16(INT16_C(-19975), INT16_C(-21187), INT16_C(-14562), INT16_C(-29768),
                            INT16_C(  5795), INT16_C(  3174), INT16_C(-13080), INT16_C(  1359),
                            INT16_C(-14826), INT16_C( 14059), INT16_C(  6182), INT16_C(  5609),
                            INT16_C(-12873), INT16_C(-31886), INT16_C(-22495), INT16_C( -9770)),
      12, -29768 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_extract_epi16(test_vec[i].a, test_vec[i].index);
    simde_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_extracti128_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m128i ra;
    simde__m128i rb;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( 1229394801), INT32_C(  992221618), INT32_C(-1388107406), INT32_C(  780445625),
                            INT32_C( 1795700153), INT32_C( -297324271), INT32_C( 1549329146), INT32_C( -534963225)),
      simde_mm256_set_epi32(INT32_C( -867719772), INT32_C(-1804212438), INT32_C( 1849818353), INT32_C(  405560893),
                            INT32_C( 1351338386), INT32_C( -886724662), INT32_C( 1197680760), INT32_C( 1003042592)),
      simde_mm_set_epi32(INT32_C( 1795700153), INT32_C( -297324271), INT32_C( 1549329146), INT32_C( -534963225)),
      simde_mm_set_epi32(INT32_C( 1229394801), INT32_C(  992221618), INT32_C(-1388107406), INT32_C(  780445625)) },
    { simde_mm256_set_epi32(INT32_C( 1839397279), INT32_C( -585358334), INT32_C(  779178160), INT32_C( -362976984),
                            INT32_C(-1015866216), INT32_C( -556342867), INT32_C( -766379029), INT32_C( -130781639)),
      simde_mm256_set_epi32(INT32_C( 2021215895), INT32_C( -422044488), INT32_C(-1385706777), INT32_C(   22702781),
                            INT32_C( 1076807274), INT32_C(-1923875401), INT32_C( -554846936), INT32_C(-1008226174)),
      simde_mm_set_epi32(INT32_C(-1015866216), INT32_C( -556342867), INT32_C( -766379029), INT32_C( -130781639)),
      simde_mm_set_epi32(INT32_C( 1839397279), INT32_C( -585358334), INT32_C(  779178160), INT32_C( -362976984)) },
    { simde_mm256_set_epi32(INT32_C(   23865749), INT32_C( -908972624), INT32_C(-1642418179), INT32_C(  111689864),
                            INT32_C( -835154412), INT32_C( -431540196), INT32_C( -161564683), INT32_C(  204589457)),
      simde_mm256_set_epi32(INT32_C( 2088662618), INT32_C(-1671363325), INT32_C( -997695043), INT32_C( -809764814),
                            INT32_C( 2092581708), INT32_C(-1073689737), INT32_C(-1556963227), INT32_C( -641330488)),
      simde_mm_set_epi32(INT32_C( -835154412), INT32_C( -431540196), INT32_C( -161564683), INT32_C(  204589457)),
      simde_mm_set_epi32(INT32_C(   23865749), INT32_C( -908972624), INT32_C(-1642418179), INT32_C(  111689864)) },
    { simde_mm256_set_epi32(INT32_C( 1727711569), INT32_C(-1915329589), INT32_C( -979233658), INT32_C( -409203179),
                            INT32_C( 1343207861), INT32_C(-1541174422), INT32_C(-2097250480), INT32_C(-1382492089)),
      simde_mm256_set_epi32(INT32_C(  -42175512), INT32_C(-2146588690), INT32_C(-1902868938), INT32_C( 1919945739),
                            INT32_C(  410749235), INT32_C(-1828962645), INT32_C(  525862553), INT32_C( -282512400)),
      simde_mm_set_epi32(INT32_C( 1343207861), INT32_C(-1541174422), INT32_C(-2097250480), INT32_C(-1382492089)),
      simde_mm_set_epi32(INT32_C( 1727711569), INT32_C(-1915329589), INT32_C( -979233658), INT32_C( -409203179)) },
    { simde_mm256_set_epi32(INT32_C(  377369527), INT32_C( 1159197718), INT32_C(  288677560), INT32_C(  828517622),
                            INT32_C( 1815109517), INT32_C( 1103735854), INT32_C( 1342116414), INT32_C( 1750949195)),
      simde_mm256_set_epi32(INT32_C( 1481955155), INT32_C( -119794855), INT32_C(-2109995042), INT32_C(  582656481),
                            INT32_C( 1178951500), INT32_C(  762286037), INT32_C(  628377158), INT32_C( -188026020)),
      simde_mm_set_epi32(INT32_C( 1815109517), INT32_C( 1103735854), INT32_C( 1342116414), INT32_C( 1750949195)),
      simde_mm_set_epi32(INT32_C(  377369527), INT32_C( 1159197718), INT32_C(  288677560), INT32_C(  828517622)) },
    { simde_mm256_set_epi32(INT32_C(-1996051424), INT32_C( -314294760), INT32_C( -770521150), INT32_C(  508113145),
                            INT32_C( -677093043), INT32_C( -527636644), INT32_C( 1238565466), INT32_C(-1592387355)),
      simde_mm256_set_epi32(INT32_C(-1510707643), INT32_C( 1988531398), INT32_C(-1182276921), INT32_C(  363503044),
                            INT32_C( 2086268932), INT32_C( -428647595), INT32_C( 1685321543), INT32_C( 1979089365)),
      simde_mm_set_epi32(INT32_C( -677093043), INT32_C( -527636644), INT32_C( 1238565466), INT32_C(-1592387355)),
      simde_mm_set_epi32(INT32_C(-1996051424), INT32_C( -314294760), INT32_C( -770521150), INT32_C(  508113145)) },
    { simde_mm256_set_epi32(INT32_C(    4593159), INT32_C( 1779671737), INT32_C( -569674634), INT32_C( -184254965),
                            INT32_C( -665786654), INT32_C(  663766301), INT32_C(-1237697897), INT32_C( -260948936)),
      simde_mm256_set_epi32(INT32_C( -575114102), INT32_C( -399786699), INT32_C(-1468780124), INT32_C( 2032090700),
                            INT32_C(  723386747), INT32_C(-1766232746), INT32_C(   73837413), INT32_C(  496540408)),
      simde_mm_set_epi32(INT32_C( -665786654), INT32_C(  663766301), INT32_C(-1237697897), INT32_C( -260948936)),
      simde_mm_set_epi32(INT32_C(    4593159), INT32_C( 1779671737), INT32_C( -569674634), INT32_C( -184254965)) },
    { simde_mm256_set_epi32(INT32_C( -328197013), INT32_C( 1036318270), INT32_C(-1930293157), INT32_C( 1948339432),
                            INT32_C( 1903716614), INT32_C(-1951673698), INT32_C(-1858071379), INT32_C( 2070124471)),
      simde_mm256_set_epi32(INT32_C(-1815372819), INT32_C( -102535612), INT32_C(  115383384), INT32_C( 1004544095),
                            INT32_C( 1506420054), INT32_C(-1014523798), INT32_C(-1776388104), INT32_C( 1550371104)),
      simde_mm_set_epi32(INT32_C( 1903716614), INT32_C(-1951673698), INT32_C(-1858071379), INT32_C( 2070124471)),
      simde_mm_set_epi32(INT32_C( -328197013), INT32_C( 1036318270), INT32_C(-1930293157), INT32_C( 1948339432)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i ra = simde_mm256_extracti128_si256(test_vec[i].a, 0);
    simde__m128i rb = simde_mm256_extracti128_si256(test_vec[i].a, 1);
    simde_assert_m128i_i32(ra, ==, test_vec[i].ra);
    simde_assert_m128i_i32(rb, ==, test_vec[i].rb);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_max_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C(  82), INT8_C(  80), INT8_C( 100), INT8_C(-114),
                           INT8_C(-121), INT8_C(-115), INT8_C( -33), INT8_C( -36),
                           INT8_C(-105), INT8_C( -52), INT8_C(  94), INT8_C(  97),
                           INT8_C( -84), INT8_C( 116), INT8_C( 107), INT8_C( -76),
                           INT8_C(   5), INT8_C(  53), INT8_C( 122), INT8_C(-101),
                           INT8_C(  32), INT8_C(-122), INT8_C( -66), INT8_C( -61),
                           INT8_C( -25), INT8_C(  -2), INT8_C(  14), INT8_C( -94),
                           INT8_C(  18), INT8_C( -35), INT8_C(-102), INT8_C(  57)),
      simde_mm256_set_epi8(INT8_C(  46), INT8_C( -89), INT8_C(  83), INT8_C( 115),
                           INT8_C( 114), INT8_C(  48), INT8_C(   9), INT8_C(   1),
                           INT8_C(  54), INT8_C( -93), INT8_C( 118), INT8_C( -84),
                           INT8_C(  50), INT8_C( -43), INT8_C(-125), INT8_C( -87),
                           INT8_C(  48), INT8_C(  67), INT8_C(  65), INT8_C( 103),
                           INT8_C( 105), INT8_C( -97), INT8_C( -54), INT8_C(  17),
                           INT8_C( -90), INT8_C( -86), INT8_C( 116), INT8_C( 127),
                           INT8_C(  77), INT8_C(  -5), INT8_C(  31), INT8_C(  24)),
      simde_mm256_set_epi8(INT8_C(  82), INT8_C(  80), INT8_C( 100), INT8_C( 115),
                           INT8_C( 114), INT8_C(  48), INT8_C(   9), INT8_C(   1),
                           INT8_C(  54), INT8_C( -52), INT8_C( 118), INT8_C(  97),
                           INT8_C(  50), INT8_C( 116), INT8_C( 107), INT8_C( -76),
                           INT8_C(  48), INT8_C(  67), INT8_C( 122), INT8_C( 103),
                           INT8_C( 105), INT8_C( -97), INT8_C( -54), INT8_C(  17),
                           INT8_C( -25), INT8_C(  -2), INT8_C( 116), INT8_C( 127),
                           INT8_C(  77), INT8_C(  -5), INT8_C(  31), INT8_C(  57)) },
    { simde_mm256_set_epi8(INT8_C( 104), INT8_C( 106), INT8_C(-125), INT8_C(  -4),
                           INT8_C( -59), INT8_C(  95), INT8_C( -56), INT8_C(  31),
                           INT8_C( 108), INT8_C(   5), INT8_C( 101), INT8_C(  27),
                           INT8_C( -64), INT8_C(  57), INT8_C(-101), INT8_C( -55),
                           INT8_C(  77), INT8_C( 118), INT8_C(  99), INT8_C(  21),
                           INT8_C(  95), INT8_C(  17), INT8_C(  54), INT8_C( -21),
                           INT8_C(  92), INT8_C( -54), INT8_C(  78), INT8_C(  40),
                           INT8_C( 102), INT8_C(-101), INT8_C(   0), INT8_C( 127)),
      simde_mm256_set_epi8(INT8_C( -59), INT8_C( 102), INT8_C(  95), INT8_C( -82),
                           INT8_C( -77), INT8_C( -39), INT8_C( -88), INT8_C( -22),
                           INT8_C(  54), INT8_C(  84), INT8_C( -33), INT8_C(  49),
                           INT8_C(  63), INT8_C(  99), INT8_C(  64), INT8_C(-122),
                           INT8_C( 102), INT8_C(  28), INT8_C(  90), INT8_C(  72),
                           INT8_C(  24), INT8_C(  50), INT8_C(  78), INT8_C( -15),
                           INT8_C( -20), INT8_C( -56), INT8_C(  73), INT8_C(  48),
                           INT8_C( -27), INT8_C(   7), INT8_C( -15), INT8_C(-109)),
      simde_mm256_set_epi8(INT8_C( 104), INT8_C( 106), INT8_C(  95), INT8_C(  -4),
                           INT8_C( -59), INT8_C(  95), INT8_C( -56), INT8_C(  31),
                           INT8_C( 108), INT8_C(  84), INT8_C( 101), INT8_C(  49),
                           INT8_C(  63), INT8_C(  99), INT8_C(  64), INT8_C( -55),
                           INT8_C( 102), INT8_C( 118), INT8_C(  99), INT8_C(  72),
                           INT8_C(  95), INT8_C(  50), INT8_C(  78), INT8_C( -15),
                           INT8_C(  92), INT8_C( -54), INT8_C(  78), INT8_C(  48),
                           INT8_C( 102), INT8_C(   7), INT8_C(   0), INT8_C( 127)) },
    { simde_mm256_set_epi8(INT8_C(  65), INT8_C(  23), INT8_C(  64), INT8_C( -32),
                           INT8_C( -17), INT8_C(  98), INT8_C( -25), INT8_C( 100),
                           INT8_C(-100), INT8_C( -55), INT8_C( -13), INT8_C( 105),
                           INT8_C(   8), INT8_C(  62), INT8_C(-102), INT8_C(  30),
                           INT8_C(  -9), INT8_C(  71), INT8_C( -37), INT8_C( -11),
                           INT8_C( -97), INT8_C(  54), INT8_C( -23), INT8_C( 103),
                           INT8_C(  11), INT8_C( -76), INT8_C(  47), INT8_C(  45),
                           INT8_C( -29), INT8_C( -83), INT8_C( -52), INT8_C(  82)),
      simde_mm256_set_epi8(INT8_C(  -2), INT8_C( -84), INT8_C( -69), INT8_C( -58),
                           INT8_C(-128), INT8_C(  76), INT8_C( 110), INT8_C( -99),
                           INT8_C(  46), INT8_C(   8), INT8_C( -50), INT8_C(  -2),
                           INT8_C( 114), INT8_C(  31), INT8_C( -27), INT8_C( -16),
                           INT8_C(  63), INT8_C( -83), INT8_C(-114), INT8_C( 116),
                           INT8_C(  14), INT8_C( -31), INT8_C(   3), INT8_C(-105),
                           INT8_C( -84), INT8_C( -19), INT8_C(  81), INT8_C(  57),
                           INT8_C( -55), INT8_C( -67), INT8_C( -89), INT8_C(  74)),
      simde_mm256_set_epi8(INT8_C(  65), INT8_C(  23), INT8_C(  64), INT8_C( -32),
                           INT8_C( -17), INT8_C(  98), INT8_C( 110), INT8_C( 100),
                           INT8_C(  46), INT8_C(   8), INT8_C( -13), INT8_C( 105),
                           INT8_C( 114), INT8_C(  62), INT8_C( -27), INT8_C(  30),
                           INT8_C(  63), INT8_C(  71), INT8_C( -37), INT8_C( 116),
                           INT8_C(  14), INT8_C(  54), INT8_C(   3), INT8_C( 103),
                           INT8_C(  11), INT8_C( -19), INT8_C(  81), INT8_C(  57),
                           INT8_C( -29), INT8_C( -67), INT8_C( -52), INT8_C(  82)) },
    { simde_mm256_set_epi8(INT8_C(   3), INT8_C( -48), INT8_C( -19), INT8_C( 101),
                           INT8_C(  -3), INT8_C( -85), INT8_C(-102), INT8_C(  26),
                           INT8_C(  89), INT8_C( -95), INT8_C(  51), INT8_C(  -5),
                           INT8_C(  13), INT8_C(  30), INT8_C( -92), INT8_C( -13),
                           INT8_C(  68), INT8_C(  71), INT8_C(-127), INT8_C( -65),
                           INT8_C(-102), INT8_C(  -1), INT8_C(  48), INT8_C(  30),
                           INT8_C(  43), INT8_C(  71), INT8_C(  53), INT8_C(  78),
                           INT8_C(  81), INT8_C( 119), INT8_C( -32), INT8_C(  18)),
      simde_mm256_set_epi8(INT8_C( -81), INT8_C( -54), INT8_C( -70), INT8_C( 102),
                           INT8_C(  86), INT8_C( 106), INT8_C(  99), INT8_C(  -7),
                           INT8_C( -74), INT8_C( -52), INT8_C(-121), INT8_C(-127),
                           INT8_C(  49), INT8_C(-119), INT8_C(  52), INT8_C( 119),
                           INT8_C( 123), INT8_C(-104), INT8_C(  44), INT8_C( -14),
                           INT8_C(  56), INT8_C( -83), INT8_C(  21), INT8_C( 108),
                           INT8_C( -43), INT8_C(  75), INT8_C(  75), INT8_C(  51),
                           INT8_C(  54), INT8_C( -18), INT8_C( 100), INT8_C(  49)),
      simde_mm256_set_epi8(INT8_C(   3), INT8_C( -48), INT8_C( -19), INT8_C( 102),
                           INT8_C(  86), INT8_C( 106), INT8_C(  99), INT8_C(  26),
                           INT8_C(  89), INT8_C( -52), INT8_C(  51), INT8_C(  -5),
                           INT8_C(  49), INT8_C(  30), INT8_C(  52), INT8_C( 119),
                           INT8_C( 123), INT8_C(  71), INT8_C(  44), INT8_C( -14),
                           INT8_C(  56), INT8_C(  -1), INT8_C(  48), INT8_C( 108),
                           INT8_C(  43), INT8_C(  75), INT8_C(  75), INT8_C(  78),
                           INT8_C(  81), INT8_C( 119), INT8_C( 100), INT8_C(  49)) },
    { simde_mm256_set_epi8(INT8_C( -92), INT8_C(  89), INT8_C(  61), INT8_C( 117),
                           INT8_C( -42), INT8_C(  29), INT8_C( -36), INT8_C(  67),
                           INT8_C(-107), INT8_C(  95), INT8_C(-103), INT8_C( -42),
                           INT8_C( -63), INT8_C(  54), INT8_C(  53), INT8_C( -40),
                           INT8_C( -66), INT8_C( -31), INT8_C( -91), INT8_C(  82),
                           INT8_C( 110), INT8_C( -33), INT8_C(  21), INT8_C(  38),
                           INT8_C( -69), INT8_C(  34), INT8_C( -74), INT8_C(  24),
                           INT8_C( -26), INT8_C(-124), INT8_C( -81), INT8_C(  36)),
      simde_mm256_set_epi8(INT8_C(-105), INT8_C(  55), INT8_C(-117), INT8_C(  72),
                           INT8_C( -82), INT8_C( -42), INT8_C( 100), INT8_C( -21),
                           INT8_C(  19), INT8_C( 104), INT8_C(  11), INT8_C(  52),
                           INT8_C(  30), INT8_C(   8), INT8_C(  70), INT8_C( -51),
                           INT8_C( -61), INT8_C( -91), INT8_C( 126), INT8_C( -28),
                           INT8_C( -34), INT8_C( 102), INT8_C(  69), INT8_C(  99),
                           INT8_C(  81), INT8_C(  11), INT8_C( -51), INT8_C(   2),
                           INT8_C(  60), INT8_C( -70), INT8_C(  92), INT8_C( -37)),
      simde_mm256_set_epi8(INT8_C( -92), INT8_C(  89), INT8_C(  61), INT8_C( 117),
                           INT8_C( -42), INT8_C(  29), INT8_C( 100), INT8_C(  67),
                           INT8_C(  19), INT8_C( 104), INT8_C(  11), INT8_C(  52),
                           INT8_C(  30), INT8_C(  54), INT8_C(  70), INT8_C( -40),
                           INT8_C( -61), INT8_C( -31), INT8_C( 126), INT8_C(  82),
                           INT8_C( 110), INT8_C( 102), INT8_C(  69), INT8_C(  99),
                           INT8_C(  81), INT8_C(  34), INT8_C( -51), INT8_C(  24),
                           INT8_C(  60), INT8_C( -70), INT8_C(  92), INT8_C(  36)) },
    { simde_mm256_set_epi8(INT8_C(-123), INT8_C( 126), INT8_C(  24), INT8_C(  94),
                           INT8_C( -42), INT8_C( 118), INT8_C(   5), INT8_C( -41),
                           INT8_C( -65), INT8_C( -51), INT8_C( -68), INT8_C( 107),
                           INT8_C( -74), INT8_C( 112), INT8_C(  53), INT8_C(  87),
                           INT8_C(  26), INT8_C( -33), INT8_C(  99), INT8_C(-107),
                           INT8_C(   6), INT8_C( 119), INT8_C( -42), INT8_C(  32),
                           INT8_C(  54), INT8_C( -97), INT8_C(-117), INT8_C(  -9),
                           INT8_C(-107), INT8_C(  44), INT8_C( -40), INT8_C(  33)),
      simde_mm256_set_epi8(INT8_C(-115), INT8_C( -12), INT8_C( -81), INT8_C(-120),
                           INT8_C(  82), INT8_C( 114), INT8_C( -55), INT8_C(-106),
                           INT8_C( -54), INT8_C( 126), INT8_C(  70), INT8_C(  83),
                           INT8_C(  64), INT8_C( -11), INT8_C(  10), INT8_C(  72),
                           INT8_C(  19), INT8_C( -35), INT8_C( 123), INT8_C( -50),
                           INT8_C(  95), INT8_C(  -2), INT8_C(  77), INT8_C( -12),
                           INT8_C(-127), INT8_C( -73), INT8_C( 117), INT8_C(  14),
                           INT8_C(  40), INT8_C( -92), INT8_C(  74), INT8_C( 114)),
      simde_mm256_set_epi8(INT8_C(-115), INT8_C( 126), INT8_C(  24), INT8_C(  94),
                           INT8_C(  82), INT8_C( 118), INT8_C(   5), INT8_C( -41),
                           INT8_C( -54), INT8_C( 126), INT8_C(  70), INT8_C( 107),
                           INT8_C(  64), INT8_C( 112), INT8_C(  53), INT8_C(  87),
                           INT8_C(  26), INT8_C( -33), INT8_C( 123), INT8_C( -50),
                           INT8_C(  95), INT8_C( 119), INT8_C(  77), INT8_C(  32),
                           INT8_C(  54), INT8_C( -73), INT8_C( 117), INT8_C(  14),
                           INT8_C(  40), INT8_C(  44), INT8_C(  74), INT8_C( 114)) },
    { simde_mm256_set_epi8(INT8_C(  29), INT8_C(  41), INT8_C( 107), INT8_C(  24),
                           INT8_C(-113), INT8_C( 113), INT8_C( -53), INT8_C(   6),
                           INT8_C( -82), INT8_C(  34), INT8_C(   0), INT8_C(  35),
                           INT8_C( -43), INT8_C(-128), INT8_C( -61), INT8_C( -69),
                           INT8_C(   2), INT8_C(  64), INT8_C(  89), INT8_C( -88),
                           INT8_C( 111), INT8_C( -95), INT8_C(  42), INT8_C( -15),
                           INT8_C(  21), INT8_C(  73), INT8_C(  70), INT8_C( 127),
                           INT8_C(  32), INT8_C( 116), INT8_C(  36), INT8_C( -14)),
      simde_mm256_set_epi8(INT8_C(  52), INT8_C( -53), INT8_C( 101), INT8_C(  79),
                           INT8_C(  -8), INT8_C( -70), INT8_C( -81), INT8_C(-117),
                           INT8_C(  27), INT8_C( -60), INT8_C(  78), INT8_C(   6),
                           INT8_C(  79), INT8_C(  72), INT8_C(   1), INT8_C( -62),
                           INT8_C( -36), INT8_C( -42), INT8_C(   0), INT8_C( -10),
                           INT8_C( -19), INT8_C(  -1), INT8_C(  25), INT8_C( -88),
                           INT8_C(  -5), INT8_C( -10), INT8_C( 127), INT8_C( 114),
                           INT8_C( 110), INT8_C(  -1), INT8_C( -27), INT8_C(  51)),
      simde_mm256_set_epi8(INT8_C(  52), INT8_C(  41), INT8_C( 107), INT8_C(  79),
                           INT8_C(  -8), INT8_C( 113), INT8_C( -53), INT8_C(   6),
                           INT8_C(  27), INT8_C(  34), INT8_C(  78), INT8_C(  35),
                           INT8_C(  79), INT8_C(  72), INT8_C(   1), INT8_C( -62),
                           INT8_C(   2), INT8_C(  64), INT8_C(  89), INT8_C( -10),
                           INT8_C( 111), INT8_C(  -1), INT8_C(  42), INT8_C( -15),
                           INT8_C(  21), INT8_C(  73), INT8_C( 127), INT8_C( 127),
                           INT8_C( 110), INT8_C( 116), INT8_C(  36), INT8_C(  51)) },
    { simde_mm256_set_epi8(INT8_C(  94), INT8_C( -83), INT8_C( -81), INT8_C( 109),
                           INT8_C(  -8), INT8_C( 100), INT8_C(  40), INT8_C(-125),
                           INT8_C( 114), INT8_C( -99), INT8_C(  42), INT8_C(  35),
                           INT8_C(  59), INT8_C(  67), INT8_C(  26), INT8_C( -39),
                           INT8_C(  79), INT8_C( 116), INT8_C(   3), INT8_C( -47),
                           INT8_C(  73), INT8_C(  13), INT8_C( -83), INT8_C( -95),
                           INT8_C(  75), INT8_C( -48), INT8_C( -36), INT8_C( 127),
                           INT8_C( 117), INT8_C(  -9), INT8_C(  94), INT8_C( -87)),
      simde_mm256_set_epi8(INT8_C( -44), INT8_C( -67), INT8_C(-100), INT8_C(  73),
                           INT8_C(  63), INT8_C(  69), INT8_C( -48), INT8_C( -87),
                           INT8_C(  -1), INT8_C( -19), INT8_C(  -9), INT8_C(  66),
                           INT8_C(  27), INT8_C(  17), INT8_C(-109), INT8_C(  22),
                           INT8_C(  98), INT8_C( 106), INT8_C( -50), INT8_C( -90),
                           INT8_C(  92), INT8_C( 106), INT8_C( -59), INT8_C(  31),
                           INT8_C( -18), INT8_C( -17), INT8_C( -80), INT8_C( -46),
                           INT8_C(  67), INT8_C( -29), INT8_C(  44), INT8_C(  76)),
      simde_mm256_set_epi8(INT8_C(  94), INT8_C( -67), INT8_C( -81), INT8_C( 109),
                           INT8_C(  63), INT8_C( 100), INT8_C(  40), INT8_C( -87),
                           INT8_C( 114), INT8_C( -19), INT8_C(  42), INT8_C(  66),
                           INT8_C(  59), INT8_C(  67), INT8_C(  26), INT8_C(  22),
                           INT8_C(  98), INT8_C( 116), INT8_C(   3), INT8_C( -47),
                           INT8_C(  92), INT8_C( 106), INT8_C( -59), INT8_C(  31),
                           INT8_C(  75), INT8_C( -17), INT8_C( -36), INT8_C( 127),
                           INT8_C( 117), INT8_C(  -9), INT8_C(  94), INT8_C(  76)) },
  };


  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_max_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_max_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
   { simde_x_mm256_set_epu8(UINT8_C(180), UINT8_C(215), UINT8_C( 58), UINT8_C(173),
                             UINT8_C(238), UINT8_C(242), UINT8_C( 74), UINT8_C(116),
                             UINT8_C(237), UINT8_C( 59), UINT8_C(170), UINT8_C(217),
                             UINT8_C(180), UINT8_C(149), UINT8_C(157), UINT8_C(250),
                             UINT8_C(224), UINT8_C(201), UINT8_C(109), UINT8_C(247),
                             UINT8_C( 25), UINT8_C(111), UINT8_C( 62), UINT8_C(129),
                             UINT8_C(115), UINT8_C(244), UINT8_C( 23), UINT8_C(181),
                             UINT8_C(205), UINT8_C(130), UINT8_C( 15), UINT8_C(  6)),
      simde_x_mm256_set_epu8(UINT8_C(129), UINT8_C(102), UINT8_C(249), UINT8_C(232),
                             UINT8_C(171), UINT8_C(250), UINT8_C(155), UINT8_C( 41),
                             UINT8_C(184), UINT8_C(159), UINT8_C(213), UINT8_C( 99),
                             UINT8_C(220), UINT8_C(155), UINT8_C(220), UINT8_C(163),
                             UINT8_C(219), UINT8_C(184), UINT8_C( 97), UINT8_C(230),
                             UINT8_C( 89), UINT8_C( 94), UINT8_C( 73), UINT8_C(152),
                             UINT8_C( 89), UINT8_C( 86), UINT8_C(115), UINT8_C(206),
                             UINT8_C(132), UINT8_C(230), UINT8_C(207), UINT8_C(  0)),
      simde_x_mm256_set_epu8(UINT8_C(180), UINT8_C(215), UINT8_C(249), UINT8_C(232),
                             UINT8_C(238), UINT8_C(250), UINT8_C(155), UINT8_C(116),
                             UINT8_C(237), UINT8_C(159), UINT8_C(213), UINT8_C(217),
                             UINT8_C(220), UINT8_C(155), UINT8_C(220), UINT8_C(250),
                             UINT8_C(224), UINT8_C(201), UINT8_C(109), UINT8_C(247),
                             UINT8_C( 89), UINT8_C(111), UINT8_C( 73), UINT8_C(152),
                             UINT8_C(115), UINT8_C(244), UINT8_C(115), UINT8_C(206),
                             UINT8_C(205), UINT8_C(230), UINT8_C(207), UINT8_C(  6)) },
    { simde_x_mm256_set_epu8(UINT8_C(218), UINT8_C(157), UINT8_C(237), UINT8_C(159),
                             UINT8_C( 73), UINT8_C(122), UINT8_C( 14), UINT8_C(243),
                             UINT8_C(232), UINT8_C(133), UINT8_C( 42), UINT8_C( 15),
                             UINT8_C( 24), UINT8_C(199), UINT8_C(216), UINT8_C( 25),
                             UINT8_C(242), UINT8_C(254), UINT8_C(156), UINT8_C(113),
                             UINT8_C(  5), UINT8_C( 95), UINT8_C( 73), UINT8_C(123),
                             UINT8_C(224), UINT8_C(233), UINT8_C(137), UINT8_C(219),
                             UINT8_C(122), UINT8_C(103), UINT8_C( 32), UINT8_C( 32)),
      simde_x_mm256_set_epu8(UINT8_C(255), UINT8_C(178), UINT8_C( 89), UINT8_C( 15),
                             UINT8_C( 21), UINT8_C(211), UINT8_C(214), UINT8_C(175),
                             UINT8_C( 24), UINT8_C(208), UINT8_C(242), UINT8_C( 16),
                             UINT8_C( 86), UINT8_C(207), UINT8_C(159), UINT8_C( 23),
                             UINT8_C( 74), UINT8_C( 72), UINT8_C(123), UINT8_C( 85),
                             UINT8_C( 99), UINT8_C(  6), UINT8_C( 15), UINT8_C(240),
                             UINT8_C(112), UINT8_C( 36), UINT8_C(217), UINT8_C( 82),
                             UINT8_C(251), UINT8_C( 67), UINT8_C(226), UINT8_C(252)),
      simde_x_mm256_set_epu8(UINT8_C(255), UINT8_C(178), UINT8_C(237), UINT8_C(159),
                             UINT8_C( 73), UINT8_C(211), UINT8_C(214), UINT8_C(243),
                             UINT8_C(232), UINT8_C(208), UINT8_C(242), UINT8_C( 16),
                             UINT8_C( 86), UINT8_C(207), UINT8_C(216), UINT8_C( 25),
                             UINT8_C(242), UINT8_C(254), UINT8_C(156), UINT8_C(113),
                             UINT8_C( 99), UINT8_C( 95), UINT8_C( 73), UINT8_C(240),
                             UINT8_C(224), UINT8_C(233), UINT8_C(217), UINT8_C(219),
                             UINT8_C(251), UINT8_C(103), UINT8_C(226), UINT8_C(252)) },
    { simde_x_mm256_set_epu8(UINT8_C( 99), UINT8_C(186), UINT8_C(163), UINT8_C(  4),
                             UINT8_C( 50), UINT8_C( 29), UINT8_C(  2), UINT8_C( 45),
                             UINT8_C( 57), UINT8_C(  0), UINT8_C(206), UINT8_C( 78),
                             UINT8_C(164), UINT8_C( 87), UINT8_C( 32), UINT8_C(133),
                             UINT8_C(239), UINT8_C(167), UINT8_C( 26), UINT8_C(218),
                             UINT8_C(142), UINT8_C( 23), UINT8_C( 41), UINT8_C( 63),
                             UINT8_C(230), UINT8_C(150), UINT8_C( 27), UINT8_C(237),
                             UINT8_C(105), UINT8_C(166), UINT8_C( 82), UINT8_C( 50)),
      simde_x_mm256_set_epu8(UINT8_C(129), UINT8_C(111), UINT8_C( 84), UINT8_C(213),
                             UINT8_C( 28), UINT8_C( 33), UINT8_C(141), UINT8_C(175),
                             UINT8_C( 38), UINT8_C(248), UINT8_C(  9), UINT8_C(  4),
                             UINT8_C(199), UINT8_C( 40), UINT8_C(185), UINT8_C(144),
                             UINT8_C( 46), UINT8_C( 14), UINT8_C( 90), UINT8_C(214),
                             UINT8_C( 91), UINT8_C( 56), UINT8_C( 35), UINT8_C(120),
                             UINT8_C(228), UINT8_C( 66), UINT8_C( 89), UINT8_C(196),
                             UINT8_C(150), UINT8_C(233), UINT8_C(114), UINT8_C(153)),
      simde_x_mm256_set_epu8(UINT8_C(129), UINT8_C(186), UINT8_C(163), UINT8_C(213),
                             UINT8_C( 50), UINT8_C( 33), UINT8_C(141), UINT8_C(175),
                             UINT8_C( 57), UINT8_C(248), UINT8_C(206), UINT8_C( 78),
                             UINT8_C(199), UINT8_C( 87), UINT8_C(185), UINT8_C(144),
                             UINT8_C(239), UINT8_C(167), UINT8_C( 90), UINT8_C(218),
                             UINT8_C(142), UINT8_C( 56), UINT8_C( 41), UINT8_C(120),
                             UINT8_C(230), UINT8_C(150), UINT8_C( 89), UINT8_C(237),
                             UINT8_C(150), UINT8_C(233), UINT8_C(114), UINT8_C(153)) },
    { simde_x_mm256_set_epu8(UINT8_C( 80), UINT8_C(  4), UINT8_C(125), UINT8_C(  7),
                             UINT8_C( 48), UINT8_C(207), UINT8_C( 44), UINT8_C(221),
                             UINT8_C(215), UINT8_C( 45), UINT8_C(223), UINT8_C(194),
                             UINT8_C(186), UINT8_C( 12), UINT8_C(145), UINT8_C(171),
                             UINT8_C(238), UINT8_C(191), UINT8_C( 72), UINT8_C(118),
                             UINT8_C( 66), UINT8_C(123), UINT8_C(140), UINT8_C(190),
                             UINT8_C(  2), UINT8_C(202), UINT8_C( 43), UINT8_C( 29),
                             UINT8_C( 54), UINT8_C( 64), UINT8_C(115), UINT8_C( 16)),
      simde_x_mm256_set_epu8(UINT8_C( 80), UINT8_C(158), UINT8_C(246), UINT8_C( 30),
                             UINT8_C(178), UINT8_C(129), UINT8_C(199), UINT8_C(213),
                             UINT8_C( 85), UINT8_C(149), UINT8_C(108), UINT8_C( 59),
                             UINT8_C(205), UINT8_C(149), UINT8_C(119), UINT8_C(194),
                             UINT8_C(246), UINT8_C( 94), UINT8_C(221), UINT8_C(162),
                             UINT8_C( 94), UINT8_C(125), UINT8_C(138), UINT8_C(231),
                             UINT8_C(191), UINT8_C( 11), UINT8_C( 15), UINT8_C( 66),
                             UINT8_C(133), UINT8_C(100), UINT8_C( 76), UINT8_C( 29)),
      simde_x_mm256_set_epu8(UINT8_C( 80), UINT8_C(158), UINT8_C(246), UINT8_C( 30),
                             UINT8_C(178), UINT8_C(207), UINT8_C(199), UINT8_C(221),
                             UINT8_C(215), UINT8_C(149), UINT8_C(223), UINT8_C(194),
                             UINT8_C(205), UINT8_C(149), UINT8_C(145), UINT8_C(194),
                             UINT8_C(246), UINT8_C(191), UINT8_C(221), UINT8_C(162),
                             UINT8_C( 94), UINT8_C(125), UINT8_C(140), UINT8_C(231),
                             UINT8_C(191), UINT8_C(202), UINT8_C( 43), UINT8_C( 66),
                             UINT8_C(133), UINT8_C(100), UINT8_C(115), UINT8_C( 29)) },
    { simde_x_mm256_set_epu8(UINT8_C(197), UINT8_C( 85), UINT8_C( 13), UINT8_C(197),
                             UINT8_C( 97), UINT8_C(213), UINT8_C( 19), UINT8_C(106),
                             UINT8_C(135), UINT8_C(  2), UINT8_C(117), UINT8_C(164),
                             UINT8_C(206), UINT8_C(103), UINT8_C( 74), UINT8_C( 88),
                             UINT8_C(183), UINT8_C( 33), UINT8_C(103), UINT8_C(216),
                             UINT8_C(136), UINT8_C(200), UINT8_C( 59), UINT8_C(124),
                             UINT8_C(188), UINT8_C(115), UINT8_C(181), UINT8_C(132),
                             UINT8_C(156), UINT8_C( 81), UINT8_C(255), UINT8_C(214)),
      simde_x_mm256_set_epu8(UINT8_C( 95), UINT8_C( 13), UINT8_C(157), UINT8_C(137),
                             UINT8_C( 41), UINT8_C(108), UINT8_C(  8), UINT8_C( 29),
                             UINT8_C( 52), UINT8_C(238), UINT8_C( 31), UINT8_C( 23),
                             UINT8_C(  9), UINT8_C( 86), UINT8_C(  2), UINT8_C( 88),
                             UINT8_C( 88), UINT8_C(185), UINT8_C(173), UINT8_C(108),
                             UINT8_C(234), UINT8_C(252), UINT8_C(231), UINT8_C( 15),
                             UINT8_C( 68), UINT8_C(138), UINT8_C( 60), UINT8_C(162),
                             UINT8_C(131), UINT8_C(215), UINT8_C( 87), UINT8_C( 44)),
      simde_x_mm256_set_epu8(UINT8_C(197), UINT8_C( 85), UINT8_C(157), UINT8_C(197),
                             UINT8_C( 97), UINT8_C(213), UINT8_C( 19), UINT8_C(106),
                             UINT8_C(135), UINT8_C(238), UINT8_C(117), UINT8_C(164),
                             UINT8_C(206), UINT8_C(103), UINT8_C( 74), UINT8_C( 88),
                             UINT8_C(183), UINT8_C(185), UINT8_C(173), UINT8_C(216),
                             UINT8_C(234), UINT8_C(252), UINT8_C(231), UINT8_C(124),
                             UINT8_C(188), UINT8_C(138), UINT8_C(181), UINT8_C(162),
                             UINT8_C(156), UINT8_C(215), UINT8_C(255), UINT8_C(214)) },
    { simde_x_mm256_set_epu8(UINT8_C(231), UINT8_C(112), UINT8_C(155), UINT8_C( 33),
                             UINT8_C( 64), UINT8_C(148), UINT8_C(180), UINT8_C( 63),
                             UINT8_C( 75), UINT8_C(171), UINT8_C(170), UINT8_C(114),
                             UINT8_C(142), UINT8_C(212), UINT8_C(162), UINT8_C(149),
                             UINT8_C( 47), UINT8_C(201), UINT8_C( 71), UINT8_C( 17),
                             UINT8_C(237), UINT8_C(172), UINT8_C(186), UINT8_C( 26),
                             UINT8_C(227), UINT8_C(106), UINT8_C(215), UINT8_C(216),
                             UINT8_C(247), UINT8_C(225), UINT8_C(  9), UINT8_C( 60)),
      simde_x_mm256_set_epu8(UINT8_C(136), UINT8_C( 20), UINT8_C(248), UINT8_C(149),
                             UINT8_C(  4), UINT8_C(138), UINT8_C(203), UINT8_C( 63),
                             UINT8_C(168), UINT8_C(148), UINT8_C(215), UINT8_C( 68),
                             UINT8_C(209), UINT8_C(109), UINT8_C(191), UINT8_C(165),
                             UINT8_C( 20), UINT8_C( 98), UINT8_C(113), UINT8_C(151),
                             UINT8_C(142), UINT8_C(111), UINT8_C(162), UINT8_C(190),
                             UINT8_C(230), UINT8_C(122), UINT8_C(213), UINT8_C(213),
                             UINT8_C(118), UINT8_C(189), UINT8_C( 22), UINT8_C(229)),
      simde_x_mm256_set_epu8(UINT8_C(231), UINT8_C(112), UINT8_C(248), UINT8_C(149),
                             UINT8_C( 64), UINT8_C(148), UINT8_C(203), UINT8_C( 63),
                             UINT8_C(168), UINT8_C(171), UINT8_C(215), UINT8_C(114),
                             UINT8_C(209), UINT8_C(212), UINT8_C(191), UINT8_C(165),
                             UINT8_C( 47), UINT8_C(201), UINT8_C(113), UINT8_C(151),
                             UINT8_C(237), UINT8_C(172), UINT8_C(186), UINT8_C(190),
                             UINT8_C(230), UINT8_C(122), UINT8_C(215), UINT8_C(216),
                             UINT8_C(247), UINT8_C(225), UINT8_C( 22), UINT8_C(229)) },
    { simde_x_mm256_set_epu8(UINT8_C(183), UINT8_C(  9), UINT8_C( 46), UINT8_C( 70),
                             UINT8_C( 48), UINT8_C(117), UINT8_C(202), UINT8_C(154),
                             UINT8_C(250), UINT8_C(204), UINT8_C(191), UINT8_C( 51),
                             UINT8_C( 37), UINT8_C(  5), UINT8_C(178), UINT8_C( 19),
                             UINT8_C(105), UINT8_C( 57), UINT8_C( 19), UINT8_C( 60),
                             UINT8_C( 26), UINT8_C( 52), UINT8_C(197), UINT8_C( 41),
                             UINT8_C(112), UINT8_C(146), UINT8_C(171), UINT8_C( 51),
                             UINT8_C( 94), UINT8_C(195), UINT8_C(226), UINT8_C(203)),
      simde_x_mm256_set_epu8(UINT8_C( 96), UINT8_C( 68), UINT8_C( 60), UINT8_C( 83),
                             UINT8_C(130), UINT8_C( 56), UINT8_C(227), UINT8_C(106),
                             UINT8_C(254), UINT8_C(175), UINT8_C(176), UINT8_C(122),
                             UINT8_C(126), UINT8_C(122), UINT8_C(171), UINT8_C(205),
                             UINT8_C( 85), UINT8_C(250), UINT8_C( 22), UINT8_C(153),
                             UINT8_C(140), UINT8_C(119), UINT8_C( 56), UINT8_C(225),
                             UINT8_C( 78), UINT8_C(180), UINT8_C(234), UINT8_C(136),
                             UINT8_C( 47), UINT8_C(214), UINT8_C( 40), UINT8_C(206)),
      simde_x_mm256_set_epu8(UINT8_C(183), UINT8_C( 68), UINT8_C( 60), UINT8_C( 83),
                             UINT8_C(130), UINT8_C(117), UINT8_C(227), UINT8_C(154),
                             UINT8_C(254), UINT8_C(204), UINT8_C(191), UINT8_C(122),
                             UINT8_C(126), UINT8_C(122), UINT8_C(178), UINT8_C(205),
                             UINT8_C(105), UINT8_C(250), UINT8_C( 22), UINT8_C(153),
                             UINT8_C(140), UINT8_C(119), UINT8_C(197), UINT8_C(225),
                             UINT8_C(112), UINT8_C(180), UINT8_C(234), UINT8_C(136),
                             UINT8_C( 94), UINT8_C(214), UINT8_C(226), UINT8_C(206)) },
    { simde_x_mm256_set_epu8(UINT8_C( 93), UINT8_C(234), UINT8_C(139), UINT8_C(  2),
                             UINT8_C(  9), UINT8_C(232), UINT8_C( 35), UINT8_C( 78),
                             UINT8_C(197), UINT8_C( 13), UINT8_C(224), UINT8_C( 83),
                             UINT8_C( 37), UINT8_C(182), UINT8_C( 94), UINT8_C( 69),
                             UINT8_C(143), UINT8_C( 54), UINT8_C(219), UINT8_C(171),
                             UINT8_C( 22), UINT8_C(117), UINT8_C( 46), UINT8_C(238),
                             UINT8_C(  4), UINT8_C(125), UINT8_C(  7), UINT8_C(106),
                             UINT8_C(127), UINT8_C( 87), UINT8_C( 56), UINT8_C( 20)),
      simde_x_mm256_set_epu8(UINT8_C( 73), UINT8_C(103), UINT8_C( 49), UINT8_C(198),
                             UINT8_C(212), UINT8_C(255), UINT8_C(227), UINT8_C( 52),
                             UINT8_C(122), UINT8_C( 22), UINT8_C(213), UINT8_C(204),
                             UINT8_C(103), UINT8_C( 93), UINT8_C( 45), UINT8_C( 45),
                             UINT8_C(221), UINT8_C(118), UINT8_C( 73), UINT8_C( 16),
                             UINT8_C(194), UINT8_C( 60), UINT8_C(246), UINT8_C(126),
                             UINT8_C( 84), UINT8_C(155), UINT8_C(128), UINT8_C( 83),
                             UINT8_C(  5), UINT8_C( 37), UINT8_C(157), UINT8_C(132)),
      simde_x_mm256_set_epu8(UINT8_C( 93), UINT8_C(234), UINT8_C(139), UINT8_C(198),
                             UINT8_C(212), UINT8_C(255), UINT8_C(227), UINT8_C( 78),
                             UINT8_C(197), UINT8_C( 22), UINT8_C(224), UINT8_C(204),
                             UINT8_C(103), UINT8_C(182), UINT8_C( 94), UINT8_C( 69),
                             UINT8_C(221), UINT8_C(118), UINT8_C(219), UINT8_C(171),
                             UINT8_C(194), UINT8_C(117), UINT8_C(246), UINT8_C(238),
                             UINT8_C( 84), UINT8_C(155), UINT8_C(128), UINT8_C(106),
                             UINT8_C(127), UINT8_C( 87), UINT8_C(157), UINT8_C(132)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_max_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_max_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
   { simde_mm256_set_epi16(INT16_C( 13945), INT16_C(-32397), INT16_C( -8500), INT16_C(-16936),
                            INT16_C(  -615), INT16_C( 28879), INT16_C( 19952), INT16_C(-20844),
                            INT16_C(-18762), INT16_C( 23311), INT16_C(-22090), INT16_C( 16355),
                            INT16_C( 18939), INT16_C( -9393), INT16_C( 19655), INT16_C( 25483)),
      simde_mm256_set_epi16(INT16_C(-30076), INT16_C(-27428), INT16_C(-24061), INT16_C( -9620),
                            INT16_C(-17974), INT16_C(  3150), INT16_C(  6986), INT16_C(-23891),
                            INT16_C( 12942), INT16_C( 12645), INT16_C(-13904), INT16_C(  -868),
                            INT16_C(-14591), INT16_C( 24935), INT16_C(  4654), INT16_C(  4591)),
      simde_mm256_set_epi16(INT16_C( 13945), INT16_C(-27428), INT16_C( -8500), INT16_C( -9620),
                            INT16_C(  -615), INT16_C( 28879), INT16_C( 19952), INT16_C(-20844),
                            INT16_C( 12942), INT16_C( 23311), INT16_C(-13904), INT16_C( 16355),
                            INT16_C( 18939), INT16_C( 24935), INT16_C( 19655), INT16_C( 25483)) },
    { simde_mm256_set_epi16(INT16_C( 15746), INT16_C( 16476), INT16_C(-26892), INT16_C( 15551),
                            INT16_C(  4802), INT16_C( 22020), INT16_C(  7684), INT16_C( 20433),
                            INT16_C(-15213), INT16_C( -9067), INT16_C( 11028), INT16_C(  2768),
                            INT16_C( 19036), INT16_C(-29021), INT16_C( 27796), INT16_C(-20181)),
      simde_mm256_set_epi16(INT16_C(-15017), INT16_C(-10120), INT16_C(-23789), INT16_C(-21730),
                            INT16_C( 16078), INT16_C(  3607), INT16_C(-18668), INT16_C(-12209),
                            INT16_C(  -562), INT16_C( 30247), INT16_C( 20324), INT16_C( -8924),
                            INT16_C( 24524), INT16_C( -5426), INT16_C( 25503), INT16_C(  2215)),
      simde_mm256_set_epi16(INT16_C( 15746), INT16_C( 16476), INT16_C(-23789), INT16_C( 15551),
                            INT16_C( 16078), INT16_C( 22020), INT16_C(  7684), INT16_C( 20433),
                            INT16_C(  -562), INT16_C( 30247), INT16_C( 20324), INT16_C(  2768),
                            INT16_C( 24524), INT16_C( -5426), INT16_C( 27796), INT16_C(  2215)) },
    { simde_mm256_set_epi16(INT16_C(  9558), INT16_C( 24602), INT16_C(-11854), INT16_C( 13316),
                            INT16_C( -7111), INT16_C(  5322), INT16_C( 10474), INT16_C( 14309),
                            INT16_C( 10175), INT16_C(-23285), INT16_C( -7105), INT16_C(-18408),
                            INT16_C( -9456), INT16_C(-31797), INT16_C(  6677), INT16_C( 24246)),
      simde_mm256_set_epi16(INT16_C(  8353), INT16_C(-12225), INT16_C( 10989), INT16_C( 20160),
                            INT16_C(-24928), INT16_C( 11285), INT16_C(-21080), INT16_C(-21637),
                            INT16_C(  -557), INT16_C(-15431), INT16_C(-14247), INT16_C(  1813),
                            INT16_C( -7571), INT16_C( 22502), INT16_C( 12550), INT16_C(  3083)),
      simde_mm256_set_epi16(INT16_C(  9558), INT16_C( 24602), INT16_C( 10989), INT16_C( 20160),
                            INT16_C( -7111), INT16_C( 11285), INT16_C( 10474), INT16_C( 14309),
                            INT16_C( 10175), INT16_C(-15431), INT16_C( -7105), INT16_C(  1813),
                            INT16_C( -7571), INT16_C( 22502), INT16_C( 12550), INT16_C( 24246)) },
    { simde_mm256_set_epi16(INT16_C( 25542), INT16_C(-21715), INT16_C(-12723), INT16_C(  3641),
                            INT16_C( 10626), INT16_C(  1975), INT16_C( 32038), INT16_C( 13257),
                            INT16_C( 26030), INT16_C(-29459), INT16_C( 27784), INT16_C(-29348),
                            INT16_C( 24986), INT16_C( 19201), INT16_C(-21133), INT16_C(  -544)),
      simde_mm256_set_epi16(INT16_C(-15360), INT16_C( -9091), INT16_C(  9964), INT16_C(-26119),
                            INT16_C(-13193), INT16_C( -4473), INT16_C(-16910), INT16_C( -8355),
                            INT16_C( 29088), INT16_C( 26903), INT16_C( 19970), INT16_C( 20929),
                            INT16_C( 21866), INT16_C(  -554), INT16_C(-31252), INT16_C(-27281)),
      simde_mm256_set_epi16(INT16_C( 25542), INT16_C( -9091), INT16_C(  9964), INT16_C(  3641),
                            INT16_C( 10626), INT16_C(  1975), INT16_C( 32038), INT16_C( 13257),
                            INT16_C( 29088), INT16_C( 26903), INT16_C( 27784), INT16_C( 20929),
                            INT16_C( 24986), INT16_C( 19201), INT16_C(-21133), INT16_C(  -544)) },
    { simde_mm256_set_epi16(INT16_C(-28957), INT16_C(  7788), INT16_C(-11350), INT16_C( 29385),
                            INT16_C( -7207), INT16_C(-21363), INT16_C(-10963), INT16_C(-23177),
                            INT16_C( 22883), INT16_C(-14765), INT16_C( 17155), INT16_C(-19202),
                            INT16_C(-32343), INT16_C(  8167), INT16_C( 17107), INT16_C(-17194)),
      simde_mm256_set_epi16(INT16_C(-21587), INT16_C( 21036), INT16_C( 16036), INT16_C(-20844),
                            INT16_C(  2600), INT16_C(-15232), INT16_C(  4125), INT16_C( 22708),
                            INT16_C(-29000), INT16_C(-22285), INT16_C(  8338), INT16_C( 25191),
                            INT16_C(  5401), INT16_C(-28508), INT16_C(-16518), INT16_C(-23781)),
      simde_mm256_set_epi16(INT16_C(-21587), INT16_C( 21036), INT16_C( 16036), INT16_C( 29385),
                            INT16_C(  2600), INT16_C(-15232), INT16_C(  4125), INT16_C( 22708),
                            INT16_C( 22883), INT16_C(-14765), INT16_C( 17155), INT16_C( 25191),
                            INT16_C(  5401), INT16_C(  8167), INT16_C( 17107), INT16_C(-17194)) },
    { simde_mm256_set_epi16(INT16_C( 26823), INT16_C( 30422), INT16_C(-10399), INT16_C(  6469),
                            INT16_C(-22608), INT16_C(  3602), INT16_C( 24356), INT16_C( -5312),
                            INT16_C( 22553), INT16_C(  4057), INT16_C( 16984), INT16_C( 14642),
                            INT16_C( -4725), INT16_C(-13132), INT16_C(-32486), INT16_C( -9795)),
      simde_mm256_set_epi16(INT16_C(-16670), INT16_C( 11037), INT16_C(-12867), INT16_C( -9733),
                            INT16_C(-19057), INT16_C( 28626), INT16_C( 27349), INT16_C( 21991),
                            INT16_C(-17860), INT16_C( -7267), INT16_C( 21708), INT16_C( 27219),
                            INT16_C(  3344), INT16_C(-13000), INT16_C( -5702), INT16_C(  8873)),
      simde_mm256_set_epi16(INT16_C( 26823), INT16_C( 30422), INT16_C(-10399), INT16_C(  6469),
                            INT16_C(-19057), INT16_C( 28626), INT16_C( 27349), INT16_C( 21991),
                            INT16_C( 22553), INT16_C(  4057), INT16_C( 21708), INT16_C( 27219),
                            INT16_C(  3344), INT16_C(-13000), INT16_C( -5702), INT16_C(  8873)) },
    { simde_mm256_set_epi16(INT16_C( 28327), INT16_C( 28059), INT16_C(-12455), INT16_C(-22892),
                            INT16_C(  9516), INT16_C(-23091), INT16_C( 28067), INT16_C( 29028),
                            INT16_C(-24610), INT16_C(-13303), INT16_C( -3871), INT16_C( 25753),
                            INT16_C(-19764), INT16_C(-10115), INT16_C( -9313), INT16_C(-10807)),
      simde_mm256_set_epi16(INT16_C(  1267), INT16_C( -7929), INT16_C( 29505), INT16_C( 22745),
                            INT16_C(  1801), INT16_C(  -829), INT16_C(  2659), INT16_C( 24204),
                            INT16_C( 27266), INT16_C(-10805), INT16_C(  7071), INT16_C( 12404),
                            INT16_C( 27748), INT16_C( 11490), INT16_C(-10130), INT16_C(  7320)),
      simde_mm256_set_epi16(INT16_C( 28327), INT16_C( 28059), INT16_C( 29505), INT16_C( 22745),
                            INT16_C(  9516), INT16_C(  -829), INT16_C( 28067), INT16_C( 29028),
                            INT16_C( 27266), INT16_C(-10805), INT16_C(  7071), INT16_C( 25753),
                            INT16_C( 27748), INT16_C( 11490), INT16_C( -9313), INT16_C(  7320)) },
    { simde_mm256_set_epi16(INT16_C(-28396), INT16_C(  3489), INT16_C( 18687), INT16_C( 31879),
                            INT16_C( 15536), INT16_C(-17843), INT16_C( 25087), INT16_C(-27693),
                            INT16_C(-17170), INT16_C( 22369), INT16_C(-27360), INT16_C( -5829),
                            INT16_C(-28550), INT16_C(   650), INT16_C(-11446), INT16_C(  3172)),
      simde_mm256_set_epi16(INT16_C(-17057), INT16_C(-18950), INT16_C( 15210), INT16_C(-25469),
                            INT16_C(-29475), INT16_C( 24211), INT16_C(-14409), INT16_C( -9847),
                            INT16_C( 14530), INT16_C(-24184), INT16_C(-29404), INT16_C(  9879),
                            INT16_C(  2544), INT16_C(-17943), INT16_C(  7392), INT16_C( 21259)),
      simde_mm256_set_epi16(INT16_C(-17057), INT16_C(  3489), INT16_C( 18687), INT16_C( 31879),
                            INT16_C( 15536), INT16_C( 24211), INT16_C( 25087), INT16_C( -9847),
                            INT16_C( 14530), INT16_C( 22369), INT16_C(-27360), INT16_C(  9879),
                            INT16_C(  2544), INT16_C(   650), INT16_C(  7392), INT16_C( 21259)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_max_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_max_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(-1578701412), INT32_C(-1861943275), INT32_C( 1717826073), INT32_C( -689858277),
                            INT32_C(-2120069619), INT32_C( -269745295), INT32_C(  993893699), INT32_C( 1747535129)),
      simde_mm256_set_epi32(INT32_C(-1662415513), INT32_C(  528745592), INT32_C( -219858588), INT32_C(  622357704),
                            INT32_C(-2013314779), INT32_C(-1188086430), INT32_C( 1171120200), INT32_C(  259652605)),
      simde_mm256_set_epi32(INT32_C(-1578701412), INT32_C(  528745592), INT32_C( 1717826073), INT32_C(  622357704),
                            INT32_C(-2013314779), INT32_C( -269745295), INT32_C( 1171120200), INT32_C( 1747535129)) },
    { simde_mm256_set_epi32(INT32_C( 1892880717), INT32_C(  489135272), INT32_C( 1334433155), INT32_C(  820950025),
                            INT32_C(  875780372), INT32_C( 1165542940), INT32_C(-1922521413), INT32_C( 1603602866)),
      simde_mm256_set_epi32(INT32_C( 1774078122), INT32_C(  717307143), INT32_C( 1385706638), INT32_C( 1722931608),
                            INT32_C(  722989282), INT32_C(  346685962), INT32_C(  888351034), INT32_C(-1040558861)),
      simde_mm256_set_epi32(INT32_C( 1892880717), INT32_C(  717307143), INT32_C( 1385706638), INT32_C( 1722931608),
                            INT32_C(  875780372), INT32_C( 1165542940), INT32_C(  888351034), INT32_C( 1603602866)) },
    { simde_mm256_set_epi32(INT32_C(  542527818), INT32_C(  704072326), INT32_C(-1102544845), INT32_C( 1444592706),
                            INT32_C(-1925092178), INT32_C( -204731801), INT32_C(  775742710), INT32_C( 1177505754)),
      simde_mm256_set_epi32(INT32_C( -551142491), INT32_C(  444795418), INT32_C( -825745617), INT32_C(-1787304548),
                            INT32_C(-1241777147), INT32_C(  265612525), INT32_C( 2134936507), INT32_C(-1780599144)),
      simde_mm256_set_epi32(INT32_C(  542527818), INT32_C(  704072326), INT32_C( -825745617), INT32_C( 1444592706),
                            INT32_C(-1241777147), INT32_C(  265612525), INT32_C( 2134936507), INT32_C( 1177505754)) },
    { simde_mm256_set_epi32(INT32_C(  788610578), INT32_C( 1831830497), INT32_C( -755374494), INT32_C( 2130364415),
                            INT32_C( -342185910), INT32_C(  854700402), INT32_C( 1343385181), INT32_C(  891289886)),
      simde_mm256_set_epi32(INT32_C( 1917738489), INT32_C(  690751883), INT32_C(-1037858966), INT32_C(-1567909551),
                            INT32_C(  -26783282), INT32_C( -715472333), INT32_C( -713074037), INT32_C(  -17697982)),
      simde_mm256_set_epi32(INT32_C( 1917738489), INT32_C( 1831830497), INT32_C( -755374494), INT32_C( 2130364415),
                            INT32_C(  -26783282), INT32_C(  854700402), INT32_C( 1343385181), INT32_C(  891289886)) },
    { simde_mm256_set_epi32(INT32_C( 1796568981), INT32_C(-1846046069), INT32_C(-1495880353), INT32_C(-1105562137),
                            INT32_C(-2000119429), INT32_C(  450352139), INT32_C( -734796291), INT32_C(-1851159287)),
      simde_mm256_set_epi32(INT32_C( 1076027923), INT32_C( 1999677975), INT32_C( -498539521), INT32_C(-1166856281),
                            INT32_C(-1611419248), INT32_C(-1268341170), INT32_C(-1115547457), INT32_C( 1554907000)),
      simde_mm256_set_epi32(INT32_C( 1796568981), INT32_C( 1999677975), INT32_C( -498539521), INT32_C(-1105562137),
                            INT32_C(-1611419248), INT32_C(  450352139), INT32_C( -734796291), INT32_C( 1554907000)) },
    { simde_mm256_set_epi32(INT32_C( -263364521), INT32_C( 1666932430), INT32_C(  378039954), INT32_C( 1866502452),
                            INT32_C( -756222443), INT32_C( -752660448), INT32_C( 1087715357), INT32_C( 1808069656)),
      simde_mm256_set_epi32(INT32_C(   10375777), INT32_C(  958545984), INT32_C(-1916055393), INT32_C(-1450264731),
                            INT32_C( -550755823), INT32_C( 2131394316), INT32_C(  243861812), INT32_C( 1031114919)),
      simde_mm256_set_epi32(INT32_C(   10375777), INT32_C( 1666932430), INT32_C(  378039954), INT32_C( 1866502452),
                            INT32_C( -550755823), INT32_C( 2131394316), INT32_C( 1087715357), INT32_C( 1808069656)) },
    { simde_mm256_set_epi32(INT32_C(-1075159077), INT32_C( -789508054), INT32_C(-2102436600), INT32_C(  177892995),
                            INT32_C(-1910430929), INT32_C( -135620958), INT32_C( 1899951190), INT32_C(-1286116105)),
      simde_mm256_set_epi32(INT32_C(-1117240644), INT32_C(-1011771686), INT32_C(-1764247251), INT32_C( -953836385),
                            INT32_C(-1633093106), INT32_C( 1815106343), INT32_C( 1418749534), INT32_C( 1718021188)),
      simde_mm256_set_epi32(INT32_C(-1075159077), INT32_C( -789508054), INT32_C(-1764247251), INT32_C(  177892995),
                            INT32_C(-1633093106), INT32_C( 1815106343), INT32_C( 1899951190), INT32_C( 1718021188)) },
    { simde_mm256_set_epi32(INT32_C( -585726505), INT32_C( -735532451), INT32_C( 1572773329), INT32_C(-1610167093),
                            INT32_C(  934479765), INT32_C( 1726304740), INT32_C(-1433078949), INT32_C(-1056217637)),
      simde_mm256_set_epi32(INT32_C(  201330788), INT32_C( 1825214883), INT32_C(  489777084), INT32_C( -824102072),
                            INT32_C(-1255028012), INT32_C(-1300324544), INT32_C(-1269112569), INT32_C( -124131174)),
      simde_mm256_set_epi32(INT32_C(  201330788), INT32_C( 1825214883), INT32_C( 1572773329), INT32_C( -824102072),
                            INT32_C(  934479765), INT32_C( 1726304740), INT32_C(-1269112569), INT32_C( -124131174)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_max_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_min_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu8(UINT8_C( 83), UINT8_C( 77), UINT8_C(142), UINT8_C(252),
                             UINT8_C( 19), UINT8_C( 26), UINT8_C(193), UINT8_C( 92),
                             UINT8_C(253), UINT8_C(183), UINT8_C(225), UINT8_C(205),
                             UINT8_C(165), UINT8_C( 19), UINT8_C(154), UINT8_C(158),
                             UINT8_C(126), UINT8_C(221), UINT8_C(206), UINT8_C( 22),
                             UINT8_C(217), UINT8_C(166), UINT8_C(237), UINT8_C(161),
                             UINT8_C(207), UINT8_C( 26), UINT8_C( 36), UINT8_C( 78),
                             UINT8_C( 55), UINT8_C(167), UINT8_C( 36), UINT8_C(198)),
      simde_x_mm256_set_epu8(UINT8_C(203), UINT8_C( 44), UINT8_C( 47), UINT8_C( 51),
                             UINT8_C(185), UINT8_C( 39), UINT8_C(221), UINT8_C( 75),
                             UINT8_C(182), UINT8_C(100), UINT8_C(238), UINT8_C(172),
                             UINT8_C(248), UINT8_C(164), UINT8_C( 91), UINT8_C(138),
                             UINT8_C(128), UINT8_C( 29), UINT8_C(136), UINT8_C(164),
                             UINT8_C( 43), UINT8_C( 85), UINT8_C(168), UINT8_C(105),
                             UINT8_C(240), UINT8_C(205), UINT8_C(221), UINT8_C(217),
                             UINT8_C(244), UINT8_C(220), UINT8_C(102), UINT8_C( 37)),
      simde_x_mm256_set_epu8(UINT8_C( 83), UINT8_C( 44), UINT8_C( 47), UINT8_C( 51),
                             UINT8_C( 19), UINT8_C( 26), UINT8_C(193), UINT8_C( 75),
                             UINT8_C(182), UINT8_C(100), UINT8_C(225), UINT8_C(172),
                             UINT8_C(165), UINT8_C( 19), UINT8_C( 91), UINT8_C(138),
                             UINT8_C(126), UINT8_C( 29), UINT8_C(136), UINT8_C( 22),
                             UINT8_C( 43), UINT8_C( 85), UINT8_C(168), UINT8_C(105),
                             UINT8_C(207), UINT8_C( 26), UINT8_C( 36), UINT8_C( 78),
                             UINT8_C( 55), UINT8_C(167), UINT8_C( 36), UINT8_C( 37)) },
    { simde_x_mm256_set_epu8(UINT8_C(177), UINT8_C(210), UINT8_C( 28), UINT8_C(116),
                             UINT8_C(174), UINT8_C(162), UINT8_C(241), UINT8_C( 21),
                             UINT8_C(126), UINT8_C(202), UINT8_C(250), UINT8_C(169),
                             UINT8_C( 43), UINT8_C(239), UINT8_C(224), UINT8_C(202),
                             UINT8_C(208), UINT8_C( 48), UINT8_C(132), UINT8_C( 78),
                             UINT8_C( 59), UINT8_C(  2), UINT8_C(213), UINT8_C(228),
                             UINT8_C( 42), UINT8_C( 45), UINT8_C(244), UINT8_C( 41),
                             UINT8_C( 49), UINT8_C( 48), UINT8_C(111), UINT8_C(211)),
      simde_x_mm256_set_epu8(UINT8_C(114), UINT8_C( 33), UINT8_C(210), UINT8_C(232),
                             UINT8_C(128), UINT8_C(122), UINT8_C(216), UINT8_C(228),
                             UINT8_C( 91), UINT8_C( 37), UINT8_C(119), UINT8_C(203),
                             UINT8_C(236), UINT8_C( 24), UINT8_C(170), UINT8_C(120),
                             UINT8_C( 95), UINT8_C(231), UINT8_C(152), UINT8_C(143),
                             UINT8_C( 42), UINT8_C( 38), UINT8_C(240), UINT8_C(125),
                             UINT8_C(124), UINT8_C(251), UINT8_C(118), UINT8_C( 44),
                             UINT8_C( 68), UINT8_C( 42), UINT8_C( 54), UINT8_C(185)),
      simde_x_mm256_set_epu8(UINT8_C(114), UINT8_C( 33), UINT8_C( 28), UINT8_C(116),
                             UINT8_C(128), UINT8_C(122), UINT8_C(216), UINT8_C( 21),
                             UINT8_C( 91), UINT8_C( 37), UINT8_C(119), UINT8_C(169),
                             UINT8_C( 43), UINT8_C( 24), UINT8_C(170), UINT8_C(120),
                             UINT8_C( 95), UINT8_C( 48), UINT8_C(132), UINT8_C( 78),
                             UINT8_C( 42), UINT8_C(  2), UINT8_C(213), UINT8_C(125),
                             UINT8_C( 42), UINT8_C( 45), UINT8_C(118), UINT8_C( 41),
                             UINT8_C( 49), UINT8_C( 42), UINT8_C( 54), UINT8_C(185)) },
    { simde_x_mm256_set_epu8(UINT8_C( 78), UINT8_C( 16), UINT8_C( 42), UINT8_C(217),
                             UINT8_C(  5), UINT8_C( 96), UINT8_C(  7), UINT8_C( 83),
                             UINT8_C( 16), UINT8_C(208), UINT8_C(  1), UINT8_C(207),
                             UINT8_C( 75), UINT8_C(207), UINT8_C(252), UINT8_C( 92),
                             UINT8_C(122), UINT8_C( 24), UINT8_C( 32), UINT8_C(104),
                             UINT8_C( 88), UINT8_C( 59), UINT8_C(218), UINT8_C( 28),
                             UINT8_C( 51), UINT8_C( 64), UINT8_C( 65), UINT8_C( 92),
                             UINT8_C( 24), UINT8_C( 83), UINT8_C(248), UINT8_C(243)),
      simde_x_mm256_set_epu8(UINT8_C(167), UINT8_C( 87), UINT8_C( 75), UINT8_C( 10),
                             UINT8_C( 44), UINT8_C(173), UINT8_C(210), UINT8_C(150),
                             UINT8_C(187), UINT8_C(229), UINT8_C(246), UINT8_C( 10),
                             UINT8_C( 80), UINT8_C( 74), UINT8_C(174), UINT8_C(128),
                             UINT8_C( 64), UINT8_C(160), UINT8_C(126), UINT8_C(231),
                             UINT8_C(215), UINT8_C( 80), UINT8_C(115), UINT8_C( 66),
                             UINT8_C(204), UINT8_C( 18), UINT8_C(158), UINT8_C(133),
                             UINT8_C(170), UINT8_C(119), UINT8_C(216), UINT8_C(196)),
      simde_x_mm256_set_epu8(UINT8_C( 78), UINT8_C( 16), UINT8_C( 42), UINT8_C( 10),
                             UINT8_C(  5), UINT8_C( 96), UINT8_C(  7), UINT8_C( 83),
                             UINT8_C( 16), UINT8_C(208), UINT8_C(  1), UINT8_C( 10),
                             UINT8_C( 75), UINT8_C( 74), UINT8_C(174), UINT8_C( 92),
                             UINT8_C( 64), UINT8_C( 24), UINT8_C( 32), UINT8_C(104),
                             UINT8_C( 88), UINT8_C( 59), UINT8_C(115), UINT8_C( 28),
                             UINT8_C( 51), UINT8_C( 18), UINT8_C( 65), UINT8_C( 92),
                             UINT8_C( 24), UINT8_C( 83), UINT8_C(216), UINT8_C(196)) },
    { simde_x_mm256_set_epu8(UINT8_C(  4), UINT8_C(145), UINT8_C( 75), UINT8_C( 42),
                             UINT8_C( 60), UINT8_C(146), UINT8_C(158), UINT8_C(  3),
                             UINT8_C( 57), UINT8_C(210), UINT8_C( 14), UINT8_C(106),
                             UINT8_C( 96), UINT8_C(136), UINT8_C( 82), UINT8_C( 54),
                             UINT8_C(227), UINT8_C(202), UINT8_C( 35), UINT8_C(184),
                             UINT8_C( 41), UINT8_C(205), UINT8_C(162), UINT8_C(206),
                             UINT8_C(247), UINT8_C( 69), UINT8_C(139), UINT8_C(186),
                             UINT8_C( 13), UINT8_C(119), UINT8_C( 79), UINT8_C( 53)),
      simde_x_mm256_set_epu8(UINT8_C(239), UINT8_C(239), UINT8_C( 37), UINT8_C(187),
                             UINT8_C(237), UINT8_C(203), UINT8_C( 68), UINT8_C( 35),
                             UINT8_C(147), UINT8_C(109), UINT8_C(244), UINT8_C(194),
                             UINT8_C(131), UINT8_C(189), UINT8_C( 51), UINT8_C( 84),
                             UINT8_C( 48), UINT8_C( 26), UINT8_C(203), UINT8_C( 35),
                             UINT8_C(128), UINT8_C( 76), UINT8_C( 16), UINT8_C( 52),
                             UINT8_C(103), UINT8_C(192), UINT8_C(105), UINT8_C( 65),
                             UINT8_C(117), UINT8_C(100), UINT8_C( 71), UINT8_C(124)),
      simde_x_mm256_set_epu8(UINT8_C(  4), UINT8_C(145), UINT8_C( 37), UINT8_C( 42),
                             UINT8_C( 60), UINT8_C(146), UINT8_C( 68), UINT8_C(  3),
                             UINT8_C( 57), UINT8_C(109), UINT8_C( 14), UINT8_C(106),
                             UINT8_C( 96), UINT8_C(136), UINT8_C( 51), UINT8_C( 54),
                             UINT8_C( 48), UINT8_C( 26), UINT8_C( 35), UINT8_C( 35),
                             UINT8_C( 41), UINT8_C( 76), UINT8_C( 16), UINT8_C( 52),
                             UINT8_C(103), UINT8_C( 69), UINT8_C(105), UINT8_C( 65),
                             UINT8_C( 13), UINT8_C(100), UINT8_C( 71), UINT8_C( 53)) },
    { simde_x_mm256_set_epu8(UINT8_C(144), UINT8_C(140), UINT8_C(121), UINT8_C(161),
                             UINT8_C(  2), UINT8_C( 56), UINT8_C(102), UINT8_C(220),
                             UINT8_C(246), UINT8_C( 67), UINT8_C( 19), UINT8_C( 67),
                             UINT8_C( 18), UINT8_C(117), UINT8_C(155), UINT8_C( 84),
                             UINT8_C(  3), UINT8_C(204), UINT8_C( 72), UINT8_C( 34),
                             UINT8_C(218), UINT8_C(208), UINT8_C( 99), UINT8_C( 27),
                             UINT8_C(224), UINT8_C( 99), UINT8_C(119), UINT8_C(221),
                             UINT8_C( 98), UINT8_C(202), UINT8_C(146), UINT8_C( 18)),
      simde_x_mm256_set_epu8(UINT8_C(127), UINT8_C(108), UINT8_C( 76), UINT8_C(146),
                             UINT8_C(206), UINT8_C(221), UINT8_C(206), UINT8_C(168),
                             UINT8_C( 11), UINT8_C(166), UINT8_C(228), UINT8_C(131),
                             UINT8_C( 46), UINT8_C( 42), UINT8_C(192), UINT8_C(117),
                             UINT8_C(166), UINT8_C(151), UINT8_C(189), UINT8_C(138),
                             UINT8_C(121), UINT8_C( 19), UINT8_C( 89), UINT8_C(188),
                             UINT8_C(255), UINT8_C(104), UINT8_C(124), UINT8_C(206),
                             UINT8_C( 89), UINT8_C(160), UINT8_C(162), UINT8_C( 10)),
      simde_x_mm256_set_epu8(UINT8_C(127), UINT8_C(108), UINT8_C( 76), UINT8_C(146),
                             UINT8_C(  2), UINT8_C( 56), UINT8_C(102), UINT8_C(168),
                             UINT8_C( 11), UINT8_C( 67), UINT8_C( 19), UINT8_C( 67),
                             UINT8_C( 18), UINT8_C( 42), UINT8_C(155), UINT8_C( 84),
                             UINT8_C(  3), UINT8_C(151), UINT8_C( 72), UINT8_C( 34),
                             UINT8_C(121), UINT8_C( 19), UINT8_C( 89), UINT8_C( 27),
                             UINT8_C(224), UINT8_C( 99), UINT8_C(119), UINT8_C(206),
                             UINT8_C( 89), UINT8_C(160), UINT8_C(146), UINT8_C( 10)) },
    { simde_x_mm256_set_epu8(UINT8_C( 74), UINT8_C(143), UINT8_C( 19), UINT8_C(  8),
                             UINT8_C( 11), UINT8_C(124), UINT8_C( 76), UINT8_C(  6),
                             UINT8_C(148), UINT8_C( 67), UINT8_C(224), UINT8_C(163),
                             UINT8_C(113), UINT8_C(245), UINT8_C( 59), UINT8_C( 27),
                             UINT8_C(131), UINT8_C(161), UINT8_C(251), UINT8_C(125),
                             UINT8_C(201), UINT8_C(252), UINT8_C(140), UINT8_C( 24),
                             UINT8_C(254), UINT8_C(183), UINT8_C(205), UINT8_C(238),
                             UINT8_C(180), UINT8_C( 21), UINT8_C( 59), UINT8_C(174)),
      simde_x_mm256_set_epu8(UINT8_C( 98), UINT8_C(152), UINT8_C(212), UINT8_C(148),
                             UINT8_C(183), UINT8_C( 37), UINT8_C(170), UINT8_C( 93),
                             UINT8_C( 52), UINT8_C(182), UINT8_C(181), UINT8_C(242),
                             UINT8_C(229), UINT8_C(182), UINT8_C(143), UINT8_C( 43),
                             UINT8_C(177), UINT8_C(115), UINT8_C(177), UINT8_C(170),
                             UINT8_C( 71), UINT8_C(222), UINT8_C(162), UINT8_C(198),
                             UINT8_C(195), UINT8_C(222), UINT8_C( 10), UINT8_C( 86),
                             UINT8_C( 48), UINT8_C(215), UINT8_C( 16), UINT8_C( 69)),
      simde_x_mm256_set_epu8(UINT8_C( 74), UINT8_C(143), UINT8_C( 19), UINT8_C(  8),
                             UINT8_C( 11), UINT8_C( 37), UINT8_C( 76), UINT8_C(  6),
                             UINT8_C( 52), UINT8_C( 67), UINT8_C(181), UINT8_C(163),
                             UINT8_C(113), UINT8_C(182), UINT8_C( 59), UINT8_C( 27),
                             UINT8_C(131), UINT8_C(115), UINT8_C(177), UINT8_C(125),
                             UINT8_C( 71), UINT8_C(222), UINT8_C(140), UINT8_C( 24),
                             UINT8_C(195), UINT8_C(183), UINT8_C( 10), UINT8_C( 86),
                             UINT8_C( 48), UINT8_C( 21), UINT8_C( 16), UINT8_C( 69)) },
    { simde_x_mm256_set_epu8(UINT8_C(119), UINT8_C(117), UINT8_C( 13), UINT8_C(207),
                             UINT8_C( 70), UINT8_C(197), UINT8_C(152), UINT8_C( 89),
                             UINT8_C(135), UINT8_C(159), UINT8_C( 50), UINT8_C(184),
                             UINT8_C(155), UINT8_C( 62), UINT8_C(253), UINT8_C(248),
                             UINT8_C(240), UINT8_C(207), UINT8_C( 53), UINT8_C(202),
                             UINT8_C(203), UINT8_C(241), UINT8_C(218), UINT8_C(118),
                             UINT8_C(121), UINT8_C(140), UINT8_C(125), UINT8_C( 65),
                             UINT8_C( 70), UINT8_C(249), UINT8_C(217), UINT8_C(237)),
      simde_x_mm256_set_epu8(UINT8_C(125), UINT8_C( 67), UINT8_C( 52), UINT8_C(  8),
                             UINT8_C(207), UINT8_C(205), UINT8_C( 56), UINT8_C(196),
                             UINT8_C( 42), UINT8_C(240), UINT8_C(116), UINT8_C( 44),
                             UINT8_C(109), UINT8_C(201), UINT8_C(220), UINT8_C(182),
                             UINT8_C(224), UINT8_C( 99), UINT8_C(151), UINT8_C(222),
                             UINT8_C(220), UINT8_C(252), UINT8_C(  6), UINT8_C(245),
                             UINT8_C(215), UINT8_C(221), UINT8_C(177), UINT8_C(240),
                             UINT8_C(118), UINT8_C(155), UINT8_C(143), UINT8_C(240)),
      simde_x_mm256_set_epu8(UINT8_C(119), UINT8_C( 67), UINT8_C( 13), UINT8_C(  8),
                             UINT8_C( 70), UINT8_C(197), UINT8_C( 56), UINT8_C( 89),
                             UINT8_C( 42), UINT8_C(159), UINT8_C( 50), UINT8_C( 44),
                             UINT8_C(109), UINT8_C( 62), UINT8_C(220), UINT8_C(182),
                             UINT8_C(224), UINT8_C( 99), UINT8_C( 53), UINT8_C(202),
                             UINT8_C(203), UINT8_C(241), UINT8_C(  6), UINT8_C(118),
                             UINT8_C(121), UINT8_C(140), UINT8_C(125), UINT8_C( 65),
                             UINT8_C( 70), UINT8_C(155), UINT8_C(143), UINT8_C(237)) },
    { simde_x_mm256_set_epu8(UINT8_C(201), UINT8_C(240), UINT8_C( 36), UINT8_C( 35),
                             UINT8_C(236), UINT8_C( 73), UINT8_C( 29), UINT8_C(244),
                             UINT8_C(140), UINT8_C( 36), UINT8_C(200), UINT8_C(155),
                             UINT8_C(  8), UINT8_C(245), UINT8_C( 10), UINT8_C( 93),
                             UINT8_C(124), UINT8_C(125), UINT8_C( 25), UINT8_C(192),
                             UINT8_C( 32), UINT8_C(119), UINT8_C(142), UINT8_C(147),
                             UINT8_C( 56), UINT8_C( 66), UINT8_C(172), UINT8_C(214),
                             UINT8_C(227), UINT8_C(203), UINT8_C( 62), UINT8_C( 37)),
      simde_x_mm256_set_epu8(UINT8_C(  5), UINT8_C( 64), UINT8_C(205), UINT8_C(118),
                             UINT8_C( 53), UINT8_C(  5), UINT8_C( 28), UINT8_C( 17),
                             UINT8_C( 93), UINT8_C(223), UINT8_C( 18), UINT8_C( 93),
                             UINT8_C(210), UINT8_C(158), UINT8_C( 37), UINT8_C( 66),
                             UINT8_C(184), UINT8_C(142), UINT8_C(246), UINT8_C( 15),
                             UINT8_C(153), UINT8_C(  9), UINT8_C(121), UINT8_C(211),
                             UINT8_C(  7), UINT8_C( 12), UINT8_C( 41), UINT8_C( 14),
                             UINT8_C(127), UINT8_C(208), UINT8_C(  7), UINT8_C( 93)),
      simde_x_mm256_set_epu8(UINT8_C(  5), UINT8_C( 64), UINT8_C( 36), UINT8_C( 35),
                             UINT8_C( 53), UINT8_C(  5), UINT8_C( 28), UINT8_C( 17),
                             UINT8_C( 93), UINT8_C( 36), UINT8_C( 18), UINT8_C( 93),
                             UINT8_C(  8), UINT8_C(158), UINT8_C( 10), UINT8_C( 66),
                             UINT8_C(124), UINT8_C(125), UINT8_C( 25), UINT8_C( 15),
                             UINT8_C( 32), UINT8_C(  9), UINT8_C(121), UINT8_C(147),
                             UINT8_C(  7), UINT8_C( 12), UINT8_C( 41), UINT8_C( 14),
                             UINT8_C(127), UINT8_C(203), UINT8_C(  7), UINT8_C( 37)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_min_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_movemask_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    int32_t r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C( -96), INT8_C(-118), INT8_C(  98), INT8_C(  62),
                           INT8_C( -51), INT8_C(  97), INT8_C( -33), INT8_C( 125),
                           INT8_C(-127), INT8_C( -72), INT8_C(  -2), INT8_C(  75),
                           INT8_C(   7), INT8_C(  73), INT8_C( -28), INT8_C(  60),
                           INT8_C(   8), INT8_C( -37), INT8_C(-119), INT8_C(  83),
                           INT8_C( -63), INT8_C( 105), INT8_C(-120), INT8_C( -81),
                           INT8_C(  66), INT8_C( -93), INT8_C(  75), INT8_C( -69),
                           INT8_C(  47), INT8_C(  11), INT8_C(  51), INT8_C(  35)),
      -891131056 },
    { simde_mm256_set_epi8(INT8_C(  15), INT8_C( 104), INT8_C( -65), INT8_C(-125),
                           INT8_C(  29), INT8_C( 110), INT8_C( -50), INT8_C(  21),
                           INT8_C( -48), INT8_C( 105), INT8_C(  56), INT8_C( 122),
                           INT8_C( -60), INT8_C( 127), INT8_C(  65), INT8_C(-126),
                           INT8_C(  -5), INT8_C( -40), INT8_C( -84), INT8_C( -80),
                           INT8_C(  27), INT8_C(  14), INT8_C(  89), INT8_C(  45),
                           INT8_C(-125), INT8_C( -33), INT8_C( 119), INT8_C(  -9),
                           INT8_C(  20), INT8_C(-117), INT8_C( -34), INT8_C( -66)),
      847900887 },
    { simde_mm256_set_epi8(INT8_C( 106), INT8_C(  46), INT8_C( 114), INT8_C( -45),
                           INT8_C(  75), INT8_C(  29), INT8_C( -66), INT8_C(-117),
                           INT8_C(  47), INT8_C(  53), INT8_C(  50), INT8_C(  31),
                           INT8_C(-111), INT8_C(  36), INT8_C( -73), INT8_C(  38),
                           INT8_C( -23), INT8_C( 112), INT8_C( -88), INT8_C(  42),
                           INT8_C( -89), INT8_C( 120), INT8_C(  50), INT8_C(  27),
                           INT8_C(   6), INT8_C(   1), INT8_C( 127), INT8_C( 127),
                           INT8_C(  38), INT8_C(  57), INT8_C(  13), INT8_C( -14)),
      319465473 },
    { simde_mm256_set_epi8(INT8_C( -21), INT8_C( 113), INT8_C( 127), INT8_C( -53),
                           INT8_C( 111), INT8_C( 121), INT8_C( -27), INT8_C(  17),
                           INT8_C(-104), INT8_C(  11), INT8_C( -41), INT8_C( -39),
                           INT8_C(  51), INT8_C(  41), INT8_C(  91), INT8_C( -62),
                           INT8_C(-116), INT8_C(  34), INT8_C(  15), INT8_C( -55),
                           INT8_C( -90), INT8_C( -31), INT8_C( -66), INT8_C( -64),
                           INT8_C( 115), INT8_C( -38), INT8_C( -54), INT8_C(  24),
                           INT8_C( -59), INT8_C( -48), INT8_C(  15), INT8_C(  60)),
      -1833853076 },
    { simde_mm256_set_epi8(INT8_C( -84), INT8_C(  66), INT8_C( 126), INT8_C( -52),
                           INT8_C(  88), INT8_C(  79), INT8_C(  71), INT8_C( -11),
                           INT8_C( -43), INT8_C( -40), INT8_C(-120), INT8_C(  75),
                           INT8_C(  12), INT8_C( -40), INT8_C(  86), INT8_C( 111),
                           INT8_C( 107), INT8_C( -40), INT8_C( -47), INT8_C(  90),
                           INT8_C(  21), INT8_C( 126), INT8_C( -72), INT8_C( -52),
                           INT8_C( -36), INT8_C( -82), INT8_C( -69), INT8_C(  97),
                           INT8_C(-122), INT8_C( -39), INT8_C(  59), INT8_C(  25)),
      -1847303188 },
    { simde_mm256_set_epi8(INT8_C(  67), INT8_C(  64), INT8_C(  17), INT8_C(  -4),
                           INT8_C( -84), INT8_C(  57), INT8_C(  94), INT8_C(  94),
                           INT8_C(-112), INT8_C(  59), INT8_C( -47), INT8_C( -43),
                           INT8_C( -74), INT8_C(  39), INT8_C(  45), INT8_C( -64),
                           INT8_C( -47), INT8_C( 114), INT8_C( -10), INT8_C(  33),
                           INT8_C(  47), INT8_C( -82), INT8_C( -45), INT8_C(  28),
                           INT8_C(  16), INT8_C(  34), INT8_C(  94), INT8_C(  53),
                           INT8_C(  64), INT8_C(-113), INT8_C( -53), INT8_C(  74)),
      414819846 },
    { simde_mm256_set_epi8(INT8_C(  27), INT8_C(  -3), INT8_C(  33), INT8_C( -42),
                           INT8_C( 113), INT8_C( -79), INT8_C( 119), INT8_C(  38),
                           INT8_C(  96), INT8_C( 109), INT8_C( 125), INT8_C(  82),
                           INT8_C(   8), INT8_C( -29), INT8_C(  10), INT8_C( -22),
                           INT8_C( -49), INT8_C( 123), INT8_C( 109), INT8_C( -49),
                           INT8_C(   6), INT8_C( -16), INT8_C( -14), INT8_C( 102),
                           INT8_C(  -5), INT8_C(  88), INT8_C(  66), INT8_C( -63),
                           INT8_C(  82), INT8_C(  34), INT8_C(  44), INT8_C(  56)),
      1409652368 },
    { simde_mm256_set_epi8(INT8_C( -69), INT8_C( -65), INT8_C(  16), INT8_C( 111),
                           INT8_C( 123), INT8_C(  89), INT8_C(  77), INT8_C(   3),
                           INT8_C(  37), INT8_C( -13), INT8_C(  28), INT8_C(  56),
                           INT8_C( -40), INT8_C( -18), INT8_C( -12), INT8_C(  32),
                           INT8_C( -91), INT8_C( -40), INT8_C( 109), INT8_C(  79),
                           INT8_C(  14), INT8_C(  52), INT8_C(  95), INT8_C(  73),
                           INT8_C(  62), INT8_C( -36), INT8_C( -31), INT8_C(  24),
                           INT8_C(  60), INT8_C( -72), INT8_C(   1), INT8_C( -18)),
      -1068580763 },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm256_movemask_epi8(test_vec[i].a);
    simde_assert_int32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_or_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C( -801044498564576659), INT64_C(-2909946603020252481),
                             INT64_C( 5958340648204315976), INT64_C( 8713768337389103061)),
      simde_mm256_set_epi64x(INT64_C( 9176724763357309327), INT64_C( 4054644920102546891),
                             INT64_C( 4782244109117166481), INT64_C( 3831721763102663031)),
      simde_mm256_set_epi64x(INT64_C(   -1584611843413009), INT64_C(   -9571266241499137),
                             INT64_C( 5980208482798747609), INT64_C( 9074056875634305015)) },
    { simde_mm256_set_epi64x(INT64_C( 1317517346722662736), INT64_C( 8192878697228400830),
                             INT64_C(-3537455209908178968), INT64_C(-2713816682012121382)),
      simde_mm256_set_epi64x(INT64_C( 7957277620212510994), INT64_C( -737217900053345188),
                             INT64_C( 8353910688937076237), INT64_C(  240232259721200655)),
      simde_mm256_set_epi64x(INT64_C( 9110201366055221586), INT64_C( -723122418076615426),
                             INT64_C(   -4662226728259603), INT64_C(-2641361182872049953)) },
    { simde_mm256_set_epi64x(INT64_C(-1030545204507091849), INT64_C(-1542600680052722313),
                             INT64_C(-7648307982573512602), INT64_C( 5973019580240685616)),
      simde_mm256_set_epi64x(INT64_C(-6290470397500953523), INT64_C( 8109710997204180941),
                             INT64_C( 5917924879433877736), INT64_C( 8502004464391034004)),
      simde_mm256_set_epi64x(INT64_C( -453800777020900225), INT64_C( -387309568701530113),
                             INT64_C(-2883445622328010514), INT64_C( 8646205037023002292)) },
    { simde_mm256_set_epi64x(INT64_C(-2990334454120409171), INT64_C(-3220201474370514905),
                             INT64_C( 8548083516217107397), INT64_C( 1251663319653874101)),
      simde_mm256_set_epi64x(INT64_C(-2621282330722334206), INT64_C( 5235652619773460077),
                             INT64_C(-8007055325654862889), INT64_C( 4775726838041815408)),
      simde_mm256_set_epi64x(INT64_C(-2333014432620503121), INT64_C(-2598629952962888081),
                             INT64_C( -656965087403232297), INT64_C( 6007467006593006069)) },
    { simde_mm256_set_epi64x(INT64_C( 1315645066342648861), INT64_C( 3754004658427516786),
                             INT64_C(-7880307939890805097), INT64_C(-5701204371115270443)),
      simde_mm256_set_epi64x(INT64_C( 4172903126396830914), INT64_C( -493154668521044871),
                             INT64_C(-2309759438976524777), INT64_C(-1689539225349388212)),
      simde_mm256_set_epi64x(INT64_C( 4317612287190453471), INT64_C( -198167755223214213),
                             INT64_C(-2309335405310321001), INT64_C( -509524860864094499)) },
    { simde_mm256_set_epi64x(INT64_C(-7748112100043814155), INT64_C( 5814291251258484552),
                             INT64_C( 8569511450246080549), INT64_C(-3900190118960098388)),
      simde_mm256_set_epi64x(INT64_C( 9015646334468450927), INT64_C(  883710405382046595),
                             INT64_C( 2743428167896968049), INT64_C(-6564603084509542605)),
      simde_mm256_set_epi64x(INT64_C( -180373114503566593), INT64_C( 6697859792108349387),
                             INT64_C( 8574745263641455477), INT64_C(-1297039137678485569)) },
    { simde_mm256_set_epi64x(INT64_C( 5980675563351081308), INT64_C( 7108230643859206772),
                             INT64_C(-7185068082285956895), INT64_C(-5748801677096031915)),
      simde_mm256_set_epi64x(INT64_C(-1209090942768865396), INT64_C(-7402713372895048445),
                             INT64_C(  -24471728257632960), INT64_C( 3473093230644658861)),
      simde_mm256_set_epi64x(INT64_C(     -14577395916836), INT64_C( -295610862468677769),
                             INT64_C(   -6315904187370015), INT64_C(-5748026933373309955)) },
    { simde_mm256_set_epi64x(INT64_C( 3669045510431781214), INT64_C(-8656850301840548621),
                             INT64_C(-5639311717074453893), INT64_C(-8609899897096571068)),
      simde_mm256_set_epi64x(INT64_C(-5772405160554679118), INT64_C( 8581290868842963452),
                             INT64_C(-7553387725647900846), INT64_C( 1768046205102779153)),
      simde_mm256_set_epi64x(INT64_C(-4616368323934308866), INT64_C( -585750987759698433),
                             INT64_C(-5206728520596308101), INT64_C(-7454726563416572075)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_or_si256(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_packs_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(    1118080), INT32_C(         -7), INT32_C(      -7630), INT32_C(         -2),
                            INT32_C(   -3082145), INT32_C(     -11087), INT32_C(    -687386), INT32_C(          1)),
      simde_mm256_set_epi32(INT32_C(  181612761), INT32_C(      21694), INT32_C(        745), INT32_C(     215111),
                            INT32_C(     435492), INT32_C(  -99515557), INT32_C(      -4549), INT32_C(         -1)),
      simde_mm256_set_epi16(INT16_C( 32767), INT16_C( 21694), INT16_C(   745), INT16_C( 32767),
                            INT16_C( 32767), INT16_C(    -7), INT16_C( -7630), INT16_C(    -2),
                            INT16_C( 32767), INT16_C(-32768), INT16_C( -4549), INT16_C(    -1),
                            INT16_C(-32768), INT16_C(-11087), INT16_C(-32768), INT16_C(     1)) },
    { simde_mm256_set_epi32(INT32_C(       2286), INT32_C(       -143), INT32_C(      11092), INT32_C(        113),
                            INT32_C(        161), INT32_C(          3), INT32_C(  -61643846), INT32_C(       -559)),
      simde_mm256_set_epi32(INT32_C(      -1647), INT32_C(    8798268), INT32_C(        -39), INT32_C(       -200),
                            INT32_C(     -16116), INT32_C(        359), INT32_C(          8), INT32_C(          0)),
      simde_mm256_set_epi16(INT16_C( -1647), INT16_C( 32767), INT16_C(   -39), INT16_C(  -200),
                            INT16_C(  2286), INT16_C(  -143), INT16_C( 11092), INT16_C(   113),
                            INT16_C(-16116), INT16_C(   359), INT16_C(     8), INT16_C(     0),
                            INT16_C(   161), INT16_C(     3), INT16_C(-32768), INT16_C(  -559)) },
    { simde_mm256_set_epi32(INT32_C(     -26267), INT32_C(  203715897), INT32_C(  -15056735), INT32_C(        -29),
                            INT32_C(          0), INT32_C(       -102), INT32_C(    8987732), INT32_C(   -1467116)),
      simde_mm256_set_epi32(INT32_C(   59339060), INT32_C(         14), INT32_C(         39), INT32_C(       7846),
                            INT32_C(        -11), INT32_C(         18), INT32_C(         -2), INT32_C(    7851730)),
      simde_mm256_set_epi16(INT16_C( 32767), INT16_C(    14), INT16_C(    39), INT16_C(  7846),
                            INT16_C(-26267), INT16_C( 32767), INT16_C(-32768), INT16_C(   -29),
                            INT16_C(   -11), INT16_C(    18), INT16_C(    -2), INT16_C( 32767),
                            INT16_C(     0), INT16_C(  -102), INT16_C( 32767), INT16_C(-32768)) },
    { simde_mm256_set_epi32(INT32_C(         20), INT32_C(    1729846), INT32_C(      11325), INT32_C(         -6),
                            INT32_C(    1076453), INT32_C(       2695), INT32_C(       2939), INT32_C(       -672)),
      simde_mm256_set_epi32(INT32_C(      14331), INT32_C( -379958894), INT32_C( -369085099), INT32_C(         10),
                            INT32_C(    7318167), INT32_C( -234036594), INT32_C(        159), INT32_C(       -255)),
      simde_mm256_set_epi16(INT16_C( 14331), INT16_C(-32768), INT16_C(-32768), INT16_C(    10),
                            INT16_C(    20), INT16_C( 32767), INT16_C( 11325), INT16_C(    -6),
                            INT16_C( 32767), INT16_C(-32768), INT16_C(   159), INT16_C(  -255),
                            INT16_C( 32767), INT16_C(  2695), INT16_C(  2939), INT16_C(  -672)) },
    { simde_mm256_set_epi32(INT32_C(      -1993), INT32_C(         12), INT32_C(       1544), INT32_C(      -3883),
                            INT32_C(         -1), INT32_C(          5), INT32_C(        -14), INT32_C(          0)),
      simde_mm256_set_epi32(INT32_C(  238433710), INT32_C( 1672160398), INT32_C(          7), INT32_C(    -335748),
                            INT32_C(         -2), INT32_C(        412), INT32_C(        -41), INT32_C(         57)),
      simde_mm256_set_epi16(INT16_C( 32767), INT16_C( 32767), INT16_C(     7), INT16_C(-32768),
                            INT16_C( -1993), INT16_C(    12), INT16_C(  1544), INT16_C( -3883),
                            INT16_C(    -2), INT16_C(   412), INT16_C(   -41), INT16_C(    57),
                            INT16_C(    -1), INT16_C(     5), INT16_C(   -14), INT16_C(     0)) },
    { simde_mm256_set_epi32(INT32_C(        -43), INT32_C(       -722), INT32_C(    3168686), INT32_C(        786),
                            INT32_C(     309716), INT32_C(  -71131617), INT32_C(   -2242932), INT32_C(        -79)),
      simde_mm256_set_epi32(INT32_C( -529814087), INT32_C(   98057466), INT32_C(   84311759), INT32_C(      -1932),
                            INT32_C(     211676), INT32_C(      -2048), INT32_C(   32017519), INT32_C(      38919)),
      simde_mm256_set_epi16(INT16_C(-32768), INT16_C( 32767), INT16_C( 32767), INT16_C( -1932),
                            INT16_C(   -43), INT16_C(  -722), INT16_C( 32767), INT16_C(   786),
                            INT16_C( 32767), INT16_C( -2048), INT16_C( 32767), INT16_C( 32767),
                            INT16_C( 32767), INT16_C(-32768), INT16_C(-32768), INT16_C(   -79)) },
    { simde_mm256_set_epi32(INT32_C(    1100378), INT32_C(   -2351165), INT32_C(         29), INT32_C(    4689904),
                            INT32_C(     103620), INT32_C(    1739844), INT32_C(    -790582), INT32_C(   73163936)),
      simde_mm256_set_epi32(INT32_C(         -4), INT32_C(         24), INT32_C(    1145468), INT32_C(      -3858),
                            INT32_C(         -2), INT32_C(        493), INT32_C(       -552), INT32_C( -294973875)),
      simde_mm256_set_epi16(INT16_C(    -4), INT16_C(    24), INT16_C( 32767), INT16_C( -3858),
                            INT16_C( 32767), INT16_C(-32768), INT16_C(    29), INT16_C( 32767),
                            INT16_C(    -2), INT16_C(   493), INT16_C(  -552), INT16_C(-32768),
                            INT16_C( 32767), INT16_C( 32767), INT16_C(-32768), INT16_C( 32767)) },
    { simde_mm256_set_epi32(INT32_C(   -2758054), INT32_C(  -48014840), INT32_C(      10027), INT32_C(    7146548),
                            INT32_C(     466187), INT32_C(     513667), INT32_C(       -320), INT32_C(        -13)),
      simde_mm256_set_epi32(INT32_C(    1666809), INT32_C(      25654), INT32_C(          1), INT32_C(    1983852),
                            INT32_C(     380233), INT32_C(       -706), INT32_C(-1412412685), INT32_C(     -44675)),
      simde_mm256_set_epi16(INT16_C( 32767), INT16_C( 25654), INT16_C(     1), INT16_C( 32767),
                            INT16_C(-32768), INT16_C(-32768), INT16_C( 10027), INT16_C( 32767),
                            INT16_C( 32767), INT16_C(  -706), INT16_C(-32768), INT16_C(-32768),
                            INT16_C( 32767), INT16_C( 32767), INT16_C(  -320), INT16_C(   -13)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_packs_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_permute4x64_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-4031273950158647677), INT64_C(-7434948453373431243),
                             INT64_C(  966046851086666502), INT64_C(-3558090175042735721)),
      simde_mm256_set_epi64x(INT64_C(-3558090175042735721), INT64_C(-3558090175042735721),
                             INT64_C(-4031273950158647677), INT64_C(  966046851086666502)) },
    { simde_mm256_set_epi64x(INT64_C(-5846597928812893198), INT64_C(-4353963629209663352),
                             INT64_C(-7799994890686903985), INT64_C( 1444957477620918324)),
      simde_mm256_set_epi64x(INT64_C( 1444957477620918324), INT64_C( 1444957477620918324),
                             INT64_C(-5846597928812893198), INT64_C(-7799994890686903985)) },
    { simde_mm256_set_epi64x(INT64_C(-1184806487964558659), INT64_C( 7043949117721512702),
                             INT64_C(  -92438279376413162), INT64_C( 2263934164871463775)),
      simde_mm256_set_epi64x(INT64_C( 2263934164871463775), INT64_C( 2263934164871463775),
                             INT64_C(-1184806487964558659), INT64_C(  -92438279376413162)) },
    { simde_mm256_set_epi64x(INT64_C( 9090919205935740251), INT64_C( 3797255434791406626),
                             INT64_C(-3974983398240952043), INT64_C(-2667637164037811982)),
      simde_mm256_set_epi64x(INT64_C(-2667637164037811982), INT64_C(-2667637164037811982),
                             INT64_C( 9090919205935740251), INT64_C(-3974983398240952043)) },
    { simde_mm256_set_epi64x(INT64_C( 7885365925671452944), INT64_C( 8557735835567037410),
                             INT64_C( 1805700887716213163), INT64_C(-5945530108016559723)),
      simde_mm256_set_epi64x(INT64_C(-5945530108016559723), INT64_C(-5945530108016559723),
                             INT64_C( 7885365925671452944), INT64_C( 1805700887716213163)) },
    { simde_mm256_set_epi64x(INT64_C( -666700084400918528), INT64_C( 2293046882897477780),
                             INT64_C(-4361422993016110212), INT64_C( 5540865589910111090)),
      simde_mm256_set_epi64x(INT64_C( 5540865589910111090), INT64_C( 5540865589910111090),
                             INT64_C( -666700084400918528), INT64_C(-4361422993016110212)) },
    { simde_mm256_set_epi64x(INT64_C(-4089126903474854143), INT64_C(-3405442608942374627),
                             INT64_C(-5965708747641475330), INT64_C( 3779098457061206514)),
      simde_mm256_set_epi64x(INT64_C( 3779098457061206514), INT64_C( 3779098457061206514),
                             INT64_C(-4089126903474854143), INT64_C(-5965708747641475330)) },
    { simde_mm256_set_epi64x(INT64_C(-7195404196599220190), INT64_C( 4846123797420351534),
                             INT64_C( 1973553066803872882), INT64_C(-2603358823346386940)),
      simde_mm256_set_epi64x(INT64_C(-2603358823346386940), INT64_C(-2603358823346386940),
                             INT64_C(-7195404196599220190), INT64_C( 1973553066803872882)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_permute4x64_epi64(test_vec[i].a, 13);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_shuffle_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu8(UINT8_C(132), UINT8_C(100), UINT8_C(115), UINT8_C( 94),
                             UINT8_C( 73), UINT8_C(247), UINT8_C(104), UINT8_C(220),
                             UINT8_C(117), UINT8_C( 74), UINT8_C( 39), UINT8_C(125),
                             UINT8_C( 51), UINT8_C( 55), UINT8_C(148), UINT8_C(183),
                             UINT8_C(  5), UINT8_C(228), UINT8_C( 33), UINT8_C( 72),
                             UINT8_C( 84), UINT8_C(  4), UINT8_C(172), UINT8_C(134),
                             UINT8_C( 26), UINT8_C(247), UINT8_C(250), UINT8_C(  1),
                             UINT8_C(220), UINT8_C( 43), UINT8_C( 83), UINT8_C(118)),
      simde_x_mm256_set_epu8(UINT8_C( 24), UINT8_C(160), UINT8_C( 38), UINT8_C(201),
                             UINT8_C(108), UINT8_C( 32), UINT8_C( 93), UINT8_C( 16),
                             UINT8_C(104), UINT8_C(146), UINT8_C(128), UINT8_C(127),
                             UINT8_C(240), UINT8_C(187), UINT8_C(163), UINT8_C( 93),
                             UINT8_C(161), UINT8_C(148), UINT8_C(236), UINT8_C(208),
                             UINT8_C(110), UINT8_C( 19), UINT8_C(  3), UINT8_C(142),
                             UINT8_C( 56), UINT8_C( 74), UINT8_C(  2), UINT8_C(168),
                             UINT8_C(100), UINT8_C(209), UINT8_C( 27), UINT8_C( 46)),
      simde_x_mm256_set_epu8(UINT8_C(220), UINT8_C(  0), UINT8_C( 74), UINT8_C(  0),
                             UINT8_C( 94), UINT8_C(183), UINT8_C(115), UINT8_C(183),
                             UINT8_C(220), UINT8_C(  0), UINT8_C(  0), UINT8_C(132),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(115),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(228), UINT8_C(220), UINT8_C(220), UINT8_C(  0),
                             UINT8_C(134), UINT8_C(  4), UINT8_C( 43), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C( 84), UINT8_C(228)) },
    { simde_x_mm256_set_epu8(UINT8_C( 53), UINT8_C(227), UINT8_C(193), UINT8_C(203),
                             UINT8_C(188), UINT8_C( 31), UINT8_C(134), UINT8_C(151),
                             UINT8_C( 90), UINT8_C(227), UINT8_C(228), UINT8_C( 42),
                             UINT8_C(223), UINT8_C( 71), UINT8_C( 37), UINT8_C(166),
                             UINT8_C(115), UINT8_C( 13), UINT8_C(136), UINT8_C( 67),
                             UINT8_C(142), UINT8_C( 55), UINT8_C(218), UINT8_C(135),
                             UINT8_C(160), UINT8_C(121), UINT8_C(105), UINT8_C(225),
                             UINT8_C( 67), UINT8_C(106), UINT8_C( 80), UINT8_C(187)),
      simde_x_mm256_set_epu8(UINT8_C(139), UINT8_C(207), UINT8_C(188), UINT8_C(170),
                             UINT8_C(232), UINT8_C(172), UINT8_C( 51), UINT8_C( 14),
                             UINT8_C( 50), UINT8_C(186), UINT8_C( 76), UINT8_C(187),
                             UINT8_C( 22), UINT8_C( 90), UINT8_C(150), UINT8_C(148),
                             UINT8_C(123), UINT8_C( 36), UINT8_C(145), UINT8_C( 72),
                             UINT8_C(252), UINT8_C(171), UINT8_C(109), UINT8_C( 77),
                             UINT8_C(145), UINT8_C( 77), UINT8_C(121), UINT8_C(107),
                             UINT8_C(138), UINT8_C(154), UINT8_C(236), UINT8_C( 13)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(223), UINT8_C(227),
                             UINT8_C( 71), UINT8_C(  0), UINT8_C(203), UINT8_C(  0),
                             UINT8_C(227), UINT8_C( 31), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(142), UINT8_C(225), UINT8_C(  0), UINT8_C(135),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(136), UINT8_C(136),
                             UINT8_C(  0), UINT8_C(136), UINT8_C(218), UINT8_C(142),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(136)) },
    { simde_x_mm256_set_epu8(UINT8_C(147), UINT8_C(175), UINT8_C(103), UINT8_C(105),
                             UINT8_C(115), UINT8_C( 25), UINT8_C( 88), UINT8_C( 95),
                             UINT8_C(108), UINT8_C(195), UINT8_C( 30), UINT8_C( 32),
                             UINT8_C(183), UINT8_C(198), UINT8_C(177), UINT8_C( 61),
                             UINT8_C(213), UINT8_C(  7), UINT8_C(150), UINT8_C(186),
                             UINT8_C( 52), UINT8_C(  9), UINT8_C( 76), UINT8_C(240),
                             UINT8_C(240), UINT8_C(126), UINT8_C(242), UINT8_C(203),
                             UINT8_C(162), UINT8_C( 72), UINT8_C(186), UINT8_C( 35)),
      simde_x_mm256_set_epu8(UINT8_C( 26), UINT8_C(  1), UINT8_C(253), UINT8_C(220),
                             UINT8_C(156), UINT8_C(126), UINT8_C(237), UINT8_C(228),
                             UINT8_C(210), UINT8_C( 82), UINT8_C(  8), UINT8_C(  8),
                             UINT8_C(104), UINT8_C( 35), UINT8_C( 98), UINT8_C( 24),
                             UINT8_C(230), UINT8_C(227), UINT8_C( 73), UINT8_C(233),
                             UINT8_C(132), UINT8_C( 49), UINT8_C( 63), UINT8_C(172),
                             UINT8_C(137), UINT8_C( 87), UINT8_C( 85), UINT8_C(128),
                             UINT8_C(136), UINT8_C(108), UINT8_C( 70), UINT8_C(218)),
      simde_x_mm256_set_epu8(UINT8_C( 25), UINT8_C(177), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(175), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(198), UINT8_C( 95), UINT8_C( 95),
                             UINT8_C( 95), UINT8_C(183), UINT8_C(198), UINT8_C( 95),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C( 76), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(186), UINT8_C(213), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(240), UINT8_C(242), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(186), UINT8_C(126), UINT8_C(  0)) },
    { simde_x_mm256_set_epu8(UINT8_C(132), UINT8_C( 22), UINT8_C(115), UINT8_C(245),
                             UINT8_C(139), UINT8_C(127), UINT8_C( 30), UINT8_C( 96),
                             UINT8_C(123), UINT8_C(228), UINT8_C( 73), UINT8_C(244),
                             UINT8_C( 12), UINT8_C( 46), UINT8_C( 26), UINT8_C( 36),
                             UINT8_C(186), UINT8_C( 18), UINT8_C(169), UINT8_C(233),
                             UINT8_C(  8), UINT8_C(185), UINT8_C(123), UINT8_C( 50),
                             UINT8_C(171), UINT8_C(240), UINT8_C(159), UINT8_C(176),
                             UINT8_C( 29), UINT8_C(146), UINT8_C( 85), UINT8_C( 34)),
      simde_x_mm256_set_epu8(UINT8_C(197), UINT8_C( 93), UINT8_C( 52), UINT8_C(130),
                             UINT8_C(124), UINT8_C( 87), UINT8_C( 88), UINT8_C( 89),
                             UINT8_C( 56), UINT8_C(209), UINT8_C( 85), UINT8_C(235),
                             UINT8_C( 45), UINT8_C(236), UINT8_C(154), UINT8_C( 72),
                             UINT8_C(164), UINT8_C(253), UINT8_C(196), UINT8_C( 41),
                             UINT8_C( 28), UINT8_C(181), UINT8_C(180), UINT8_C(237),
                             UINT8_C( 65), UINT8_C(122), UINT8_C(110), UINT8_C( 94),
                             UINT8_C(125), UINT8_C( 60), UINT8_C( 80), UINT8_C(209)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C(115), UINT8_C(244), UINT8_C(  0),
                             UINT8_C(245), UINT8_C(123), UINT8_C( 96), UINT8_C( 30),
                             UINT8_C( 96), UINT8_C(  0), UINT8_C( 73), UINT8_C(  0),
                             UINT8_C(115), UINT8_C(  0), UINT8_C(  0), UINT8_C( 96),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(123),
                             UINT8_C(233), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C( 85), UINT8_C(185), UINT8_C( 18), UINT8_C( 18),
                             UINT8_C(169), UINT8_C(233), UINT8_C( 34), UINT8_C(  0)) },
    { simde_x_mm256_set_epu8(UINT8_C(233), UINT8_C(108), UINT8_C(215), UINT8_C(181),
                             UINT8_C(100), UINT8_C( 72), UINT8_C(220), UINT8_C( 52),
                             UINT8_C( 24), UINT8_C(  0), UINT8_C(242), UINT8_C(125),
                             UINT8_C(116), UINT8_C(102), UINT8_C( 94), UINT8_C( 64),
                             UINT8_C(158), UINT8_C(177), UINT8_C(  3), UINT8_C(246),
                             UINT8_C(164), UINT8_C(171), UINT8_C(138), UINT8_C( 15),
                             UINT8_C( 30), UINT8_C( 68), UINT8_C(246), UINT8_C(147),
                             UINT8_C(162), UINT8_C( 13), UINT8_C( 93), UINT8_C( 58)),
      simde_x_mm256_set_epu8(UINT8_C(159), UINT8_C(224), UINT8_C(140), UINT8_C(117),
                             UINT8_C( 95), UINT8_C( 45), UINT8_C(144), UINT8_C( 69),
                             UINT8_C(174), UINT8_C( 34), UINT8_C(237), UINT8_C( 42),
                             UINT8_C( 78), UINT8_C(  7), UINT8_C(200), UINT8_C(173),
                             UINT8_C(137), UINT8_C( 75), UINT8_C(170), UINT8_C(110),
                             UINT8_C(182), UINT8_C(180), UINT8_C(173), UINT8_C(172),
                             UINT8_C(227), UINT8_C(222), UINT8_C(132), UINT8_C(  4),
                             UINT8_C(190), UINT8_C(  7), UINT8_C( 12), UINT8_C( 21)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(242),
                             UINT8_C(233), UINT8_C(215), UINT8_C(  0), UINT8_C(242),
                             UINT8_C(  0), UINT8_C(102), UINT8_C(  0), UINT8_C( 72),
                             UINT8_C(108), UINT8_C( 24), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(164), UINT8_C(  0), UINT8_C(177),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(147),
                             UINT8_C(  0), UINT8_C( 30), UINT8_C(246), UINT8_C(246)) },
    { simde_x_mm256_set_epu8(UINT8_C(239), UINT8_C(190), UINT8_C( 67), UINT8_C(183),
                             UINT8_C(162), UINT8_C( 57), UINT8_C(249), UINT8_C(218),
                             UINT8_C(176), UINT8_C(139), UINT8_C(  3), UINT8_C(248),
                             UINT8_C(214), UINT8_C( 36), UINT8_C(105), UINT8_C( 96),
                             UINT8_C( 80), UINT8_C(108), UINT8_C(142), UINT8_C(  2),
                             UINT8_C(196), UINT8_C(162), UINT8_C( 38), UINT8_C(  4),
                             UINT8_C(175), UINT8_C(178), UINT8_C( 88), UINT8_C(165),
                             UINT8_C(168), UINT8_C( 71), UINT8_C( 76), UINT8_C(232)),
      simde_x_mm256_set_epu8(UINT8_C(199), UINT8_C( 95), UINT8_C( 43), UINT8_C(216),
                             UINT8_C(128), UINT8_C(137), UINT8_C(103), UINT8_C( 51),
                             UINT8_C(121), UINT8_C( 84), UINT8_C(196), UINT8_C(101),
                             UINT8_C(251), UINT8_C(  4), UINT8_C( 89), UINT8_C( 54),
                             UINT8_C(216), UINT8_C(149), UINT8_C(145), UINT8_C( 73),
                             UINT8_C(162), UINT8_C( 73), UINT8_C(124), UINT8_C(146),
                             UINT8_C( 70), UINT8_C(151), UINT8_C(137), UINT8_C(218),
                             UINT8_C(230), UINT8_C(112), UINT8_C( 45), UINT8_C(226)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C(239), UINT8_C(162), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(176), UINT8_C(214),
                             UINT8_C(249), UINT8_C(248), UINT8_C(  0), UINT8_C(  3),
                             UINT8_C(  0), UINT8_C(248), UINT8_C(249), UINT8_C(139),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 38),
                             UINT8_C(  0), UINT8_C( 38), UINT8_C(  2), UINT8_C(  0),
                             UINT8_C(178), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(232), UINT8_C(142), UINT8_C(  0)) },
    { simde_x_mm256_set_epu8(UINT8_C( 81), UINT8_C(102), UINT8_C( 49), UINT8_C(133),
                             UINT8_C(250), UINT8_C( 13), UINT8_C(233), UINT8_C( 67),
                             UINT8_C(205), UINT8_C(254), UINT8_C( 41), UINT8_C(  6),
                             UINT8_C(117), UINT8_C(148), UINT8_C(222), UINT8_C(171),
                             UINT8_C(  8), UINT8_C( 99), UINT8_C( 93), UINT8_C( 39),
                             UINT8_C(103), UINT8_C(215), UINT8_C(216), UINT8_C( 75),
                             UINT8_C( 94), UINT8_C(171), UINT8_C( 41), UINT8_C(173),
                             UINT8_C(217), UINT8_C(138), UINT8_C(180), UINT8_C(160)),
      simde_x_mm256_set_epu8(UINT8_C(200), UINT8_C(107), UINT8_C(119), UINT8_C(216),
                             UINT8_C( 73), UINT8_C(187), UINT8_C(212), UINT8_C( 20),
                             UINT8_C( 22), UINT8_C( 11), UINT8_C(155), UINT8_C(106),
                             UINT8_C( 35), UINT8_C(108), UINT8_C( 43), UINT8_C( 58),
                             UINT8_C(102), UINT8_C(228), UINT8_C(  5), UINT8_C(227),
                             UINT8_C(106), UINT8_C(119), UINT8_C(184), UINT8_C(199),
                             UINT8_C( 57), UINT8_C(120), UINT8_C( 14), UINT8_C( 56),
                             UINT8_C( 82), UINT8_C( 19), UINT8_C( 33), UINT8_C( 82)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C(250), UINT8_C(205), UINT8_C(  0),
                             UINT8_C(233), UINT8_C(  0), UINT8_C(  0), UINT8_C(  6),
                             UINT8_C(254), UINT8_C(250), UINT8_C(  0), UINT8_C( 13),
                             UINT8_C(117), UINT8_C(133), UINT8_C(250), UINT8_C( 13),
                             UINT8_C(171), UINT8_C(  0), UINT8_C( 41), UINT8_C(  0),
                             UINT8_C(215), UINT8_C( 94), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(216), UINT8_C( 75), UINT8_C( 99), UINT8_C( 75),
                             UINT8_C(138), UINT8_C(217), UINT8_C(180), UINT8_C(138)) },
    { simde_x_mm256_set_epu8(UINT8_C(173), UINT8_C(218), UINT8_C( 20), UINT8_C( 45),
                             UINT8_C(110), UINT8_C( 90), UINT8_C(183), UINT8_C( 54),
                             UINT8_C(102), UINT8_C(126), UINT8_C(167), UINT8_C(135),
                             UINT8_C( 42), UINT8_C( 74), UINT8_C( 22), UINT8_C(137),
                             UINT8_C( 56), UINT8_C(  5), UINT8_C( 18), UINT8_C(105),
                             UINT8_C( 83), UINT8_C(146), UINT8_C(229), UINT8_C( 54),
                             UINT8_C(169), UINT8_C( 55), UINT8_C(228), UINT8_C(168),
                             UINT8_C(  1), UINT8_C(126), UINT8_C(169), UINT8_C(235)),
      simde_x_mm256_set_epu8(UINT8_C(254), UINT8_C( 56), UINT8_C(  4), UINT8_C(163),
                             UINT8_C( 35), UINT8_C( 52), UINT8_C(182), UINT8_C( 52),
                             UINT8_C(  1), UINT8_C( 45), UINT8_C(119), UINT8_C(169),
                             UINT8_C(175), UINT8_C(254), UINT8_C( 71), UINT8_C( 63),
                             UINT8_C( 24), UINT8_C(116), UINT8_C(194), UINT8_C(184),
                             UINT8_C(150), UINT8_C(167), UINT8_C(101), UINT8_C(133),
                             UINT8_C( 95), UINT8_C( 84), UINT8_C(199), UINT8_C(134),
                             UINT8_C(251), UINT8_C(101), UINT8_C( 38), UINT8_C( 43)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C( 54), UINT8_C(135), UINT8_C(  0),
                             UINT8_C( 42), UINT8_C(135), UINT8_C(  0), UINT8_C(135),
                             UINT8_C( 22), UINT8_C( 20), UINT8_C(102), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(102), UINT8_C(173),
                             UINT8_C( 54), UINT8_C(168), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(228), UINT8_C(  0),
                             UINT8_C( 56), UINT8_C(168), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(228), UINT8_C( 55), UINT8_C( 83)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_shuffle_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_shuffle_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(    7953530), INT32_C( 1626445648), INT32_C(  338474584), INT32_C( 1314132322),
                            INT32_C( -165526664), INT32_C( 1862544223), INT32_C( 1736492928), INT32_C( -812721862)),
      simde_mm256_set_epi32(INT32_C( 1626445648), INT32_C( 1626445648), INT32_C( 1626445648), INT32_C( 1626445648),
                            INT32_C( 1862544223), INT32_C( 1862544223), INT32_C( 1862544223), INT32_C( 1862544223)) },
    { simde_mm256_set_epi32(INT32_C( 1571455878), INT32_C( 1654912639), INT32_C( 1961566624), INT32_C( 1369731271),
                            INT32_C( -802314883), INT32_C( 1895104772), INT32_C(-1294636783), INT32_C(   -2090880)),
      simde_mm256_set_epi32(INT32_C( 1654912639), INT32_C( 1654912639), INT32_C( 1654912639), INT32_C( 1654912639),
                            INT32_C( 1895104772), INT32_C( 1895104772), INT32_C( 1895104772), INT32_C( 1895104772)) },
    { simde_mm256_set_epi32(INT32_C(  716787034), INT32_C(  279681787), INT32_C(  -21556639), INT32_C(-1981624037),
                            INT32_C(  330738474), INT32_C(-1021797214), INT32_C(  117555788), INT32_C( 1295745410)),
      simde_mm256_set_epi32(INT32_C(  279681787), INT32_C(  279681787), INT32_C(  279681787), INT32_C(  279681787),
                            INT32_C(-1021797214), INT32_C(-1021797214), INT32_C(-1021797214), INT32_C(-1021797214)) },
    { simde_mm256_set_epi32(INT32_C(-1161252350), INT32_C( 1333069761), INT32_C( -746913676), INT32_C(-1297385199),
                            INT32_C( 1762552906), INT32_C( 1819201471), INT32_C(-1000519846), INT32_C( 2096577459)),
      simde_mm256_set_epi32(INT32_C( 1333069761), INT32_C( 1333069761), INT32_C( 1333069761), INT32_C( 1333069761),
                            INT32_C( 1819201471), INT32_C( 1819201471), INT32_C( 1819201471), INT32_C( 1819201471)) },
    { simde_mm256_set_epi32(INT32_C( 1772174643), INT32_C( 2012282759), INT32_C(  407185018), INT32_C(-1907491648),
                            INT32_C(-1950535235), INT32_C(   59473466), INT32_C( -212502371), INT32_C( -171378108)),
      simde_mm256_set_epi32(INT32_C( 2012282759), INT32_C( 2012282759), INT32_C( 2012282759), INT32_C( 2012282759),
                            INT32_C(   59473466), INT32_C(   59473466), INT32_C(   59473466), INT32_C(   59473466)) },
    { simde_mm256_set_epi32(INT32_C(-1786867928), INT32_C(  183968379), INT32_C(-1710767833), INT32_C(  419209661),
                            INT32_C( 1470446764), INT32_C( -838411183), INT32_C( 1711518303), INT32_C(-1929674962)),
      simde_mm256_set_epi32(INT32_C(  183968379), INT32_C(  183968379), INT32_C(  183968379), INT32_C(  183968379),
                            INT32_C( -838411183), INT32_C( -838411183), INT32_C( -838411183), INT32_C( -838411183)) },
    { simde_mm256_set_epi32(INT32_C(-1296827172), INT32_C(-1426782704), INT32_C(  461497475), INT32_C(  857689164),
                            INT32_C( -127267738), INT32_C( -225620875), INT32_C( -476268334), INT32_C(     275470)),
      simde_mm256_set_epi32(INT32_C(-1426782704), INT32_C(-1426782704), INT32_C(-1426782704), INT32_C(-1426782704),
                            INT32_C( -225620875), INT32_C( -225620875), INT32_C( -225620875), INT32_C( -225620875)) },
    { simde_mm256_set_epi32(INT32_C(  492995740), INT32_C(-1095702956), INT32_C( 1746718954), INT32_C( 2048506117),
                            INT32_C(  180431580), INT32_C(-1463759846), INT32_C( 1212242273), INT32_C(-1640731308)),
      simde_mm256_set_epi32(INT32_C(-1095702956), INT32_C(-1095702956), INT32_C(-1095702956), INT32_C(-1095702956),
                            INT32_C(-1463759846), INT32_C(-1463759846), INT32_C(-1463759846), INT32_C(-1463759846)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_shuffle_epi32(test_vec[i].a, 0xaa);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_shufflelo_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi16(INT16_C( -2179), INT16_C( 30608), INT16_C( 19808), INT16_C(-28307),
                            INT16_C( 25873), INT16_C( -9642), INT16_C(    56), INT16_C(   338),
                            INT16_C(-29256), INT16_C(  9693), INT16_C( 18909), INT16_C(  3915),
                            INT16_C(  2653), INT16_C( 26676), INT16_C(-23808), INT16_C( 25025)),
      simde_mm256_set_epi16(INT16_C( -2179), INT16_C( 30608), INT16_C( 19808), INT16_C(-28307),
                            INT16_C( -9642), INT16_C(    56), INT16_C(    56), INT16_C(    56),
                            INT16_C(-29256), INT16_C(  9693), INT16_C( 18909), INT16_C(  3915),
                            INT16_C( 26676), INT16_C(-23808), INT16_C(-23808), INT16_C(-23808)) },
    { simde_mm256_set_epi16(INT16_C( 18348), INT16_C(-29440), INT16_C( -6978), INT16_C( 22811),
                            INT16_C(-31995), INT16_C( 32157), INT16_C( -1931), INT16_C( 15650),
                            INT16_C( 25681), INT16_C( 27258), INT16_C( -9033), INT16_C( 28640),
                            INT16_C(-16045), INT16_C(  2509), INT16_C(-23756), INT16_C(  4399)),
      simde_mm256_set_epi16(INT16_C( 18348), INT16_C(-29440), INT16_C( -6978), INT16_C( 22811),
                            INT16_C( 32157), INT16_C( -1931), INT16_C( -1931), INT16_C( -1931),
                            INT16_C( 25681), INT16_C( 27258), INT16_C( -9033), INT16_C( 28640),
                            INT16_C(  2509), INT16_C(-23756), INT16_C(-23756), INT16_C(-23756)) },
    { simde_mm256_set_epi16(INT16_C( 32389), INT16_C(-20100), INT16_C( 26342), INT16_C(-12082),
                            INT16_C( 27809), INT16_C( 10468), INT16_C( 29312), INT16_C( -5875),
                            INT16_C( 10801), INT16_C(-11039), INT16_C(-32348), INT16_C(-19420),
                            INT16_C(-32754), INT16_C(-20940), INT16_C( 17235), INT16_C(-29506)),
      simde_mm256_set_epi16(INT16_C( 32389), INT16_C(-20100), INT16_C( 26342), INT16_C(-12082),
                            INT16_C( 10468), INT16_C( 29312), INT16_C( 29312), INT16_C( 29312),
                            INT16_C( 10801), INT16_C(-11039), INT16_C(-32348), INT16_C(-19420),
                            INT16_C(-20940), INT16_C( 17235), INT16_C( 17235), INT16_C( 17235)) },
    { simde_mm256_set_epi16(INT16_C(-30489), INT16_C( 27619), INT16_C(-16535), INT16_C(-14927),
                            INT16_C( 10253), INT16_C( 31108), INT16_C(    46), INT16_C( 10088),
                            INT16_C(-25344), INT16_C( -5295), INT16_C( 22387), INT16_C( 27540),
                            INT16_C(-30287), INT16_C(  3057), INT16_C( -2994), INT16_C( 31366)),
      simde_mm256_set_epi16(INT16_C(-30489), INT16_C( 27619), INT16_C(-16535), INT16_C(-14927),
                            INT16_C( 31108), INT16_C(    46), INT16_C(    46), INT16_C(    46),
                            INT16_C(-25344), INT16_C( -5295), INT16_C( 22387), INT16_C( 27540),
                            INT16_C(  3057), INT16_C( -2994), INT16_C( -2994), INT16_C( -2994)) },
    { simde_mm256_set_epi16(INT16_C( -7255), INT16_C(-20910), INT16_C( 13809), INT16_C(  9595),
                            INT16_C( -1612), INT16_C( 23053), INT16_C(  7111), INT16_C(-11581),
                            INT16_C(-12829), INT16_C( 20686), INT16_C(-16865), INT16_C(  5649),
                            INT16_C(-25623), INT16_C( -2444), INT16_C( 11296), INT16_C(  7832)),
      simde_mm256_set_epi16(INT16_C( -7255), INT16_C(-20910), INT16_C( 13809), INT16_C(  9595),
                            INT16_C( 23053), INT16_C(  7111), INT16_C(  7111), INT16_C(  7111),
                            INT16_C(-12829), INT16_C( 20686), INT16_C(-16865), INT16_C(  5649),
                            INT16_C( -2444), INT16_C( 11296), INT16_C( 11296), INT16_C( 11296)) },
    { simde_mm256_set_epi16(INT16_C(-26606), INT16_C(  4305), INT16_C( 13601), INT16_C(  6245),
                            INT16_C( -6095), INT16_C(  5518), INT16_C(-13456), INT16_C(-16529),
                            INT16_C(-18890), INT16_C( 32306), INT16_C( 18285), INT16_C(  9413),
                            INT16_C( -4831), INT16_C( 31394), INT16_C(  7403), INT16_C(  8863)),
      simde_mm256_set_epi16(INT16_C(-26606), INT16_C(  4305), INT16_C( 13601), INT16_C(  6245),
                            INT16_C(  5518), INT16_C(-13456), INT16_C(-13456), INT16_C(-13456),
                            INT16_C(-18890), INT16_C( 32306), INT16_C( 18285), INT16_C(  9413),
                            INT16_C( 31394), INT16_C(  7403), INT16_C(  7403), INT16_C(  7403)) },
    { simde_mm256_set_epi16(INT16_C(-22090), INT16_C(  3292), INT16_C(-24353), INT16_C(-13630),
                            INT16_C(  1106), INT16_C( 20149), INT16_C( 12111), INT16_C( -9481),
                            INT16_C(  8059), INT16_C( 23722), INT16_C(-24846), INT16_C(-19082),
                            INT16_C( 18649), INT16_C( 23374), INT16_C(-15098), INT16_C(  5703)),
      simde_mm256_set_epi16(INT16_C(-22090), INT16_C(  3292), INT16_C(-24353), INT16_C(-13630),
                            INT16_C( 20149), INT16_C( 12111), INT16_C( 12111), INT16_C( 12111),
                            INT16_C(  8059), INT16_C( 23722), INT16_C(-24846), INT16_C(-19082),
                            INT16_C( 23374), INT16_C(-15098), INT16_C(-15098), INT16_C(-15098)) },
    { simde_mm256_set_epi16(INT16_C( 31351), INT16_C(-28147), INT16_C(-17219), INT16_C( 13266),
                            INT16_C( 26309), INT16_C(  5438), INT16_C( -9093), INT16_C(  -541),
                            INT16_C( -7590), INT16_C(-28792), INT16_C(  9449), INT16_C(-27866),
                            INT16_C(  7986), INT16_C(-24032), INT16_C( 23568), INT16_C( 18541)),
      simde_mm256_set_epi16(INT16_C( 31351), INT16_C(-28147), INT16_C(-17219), INT16_C( 13266),
                            INT16_C(  5438), INT16_C( -9093), INT16_C( -9093), INT16_C( -9093),
                            INT16_C( -7590), INT16_C(-28792), INT16_C(  9449), INT16_C(-27866),
                            INT16_C(-24032), INT16_C( 23568), INT16_C( 23568), INT16_C( 23568)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_shufflelo_epi16(test_vec[i].a, 149);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_slli_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[] = {
    { simde_mm256_set_epi16(INT16_C( -7189), INT16_C( -4038), INT16_C(  8832), INT16_C(-31599),
                            INT16_C(  9071), INT16_C(-26166), INT16_C(  4984), INT16_C(-29916),
                            INT16_C( 26692), INT16_C(  7557), INT16_C(-30970), INT16_C(-31903),
                            INT16_C( 32721), INT16_C( 14732), INT16_C( -9072), INT16_C(-28469)),
      simde_mm256_set_epi16(INT16_C( -7189), INT16_C( -4038), INT16_C(  8832), INT16_C(-31599),
                            INT16_C(  9071), INT16_C(-26166), INT16_C(  4984), INT16_C(-29916),
                            INT16_C( 26692), INT16_C(  7557), INT16_C(-30970), INT16_C(-31903),
                            INT16_C( 32721), INT16_C( 14732), INT16_C( -9072), INT16_C(-28469)) },
    { simde_mm256_set_epi16(INT16_C( 27658), INT16_C(-18253), INT16_C( 19135), INT16_C(-22021),
                            INT16_C(-31750), INT16_C( 26403), INT16_C(-14265), INT16_C( -1890),
                            INT16_C( 16323), INT16_C( -5176), INT16_C(-29730), INT16_C( -7646),
                            INT16_C(-24362), INT16_C( 28979), INT16_C( 13248), INT16_C(  6628)),
      simde_mm256_set_epi16(INT16_C(-10220), INT16_C( 29030), INT16_C(-27266), INT16_C( 21494),
                            INT16_C(  2036), INT16_C(-12730), INT16_C(-28530), INT16_C( -3780),
                            INT16_C( 32646), INT16_C(-10352), INT16_C(  6076), INT16_C(-15292),
                            INT16_C( 16812), INT16_C( -7578), INT16_C( 26496), INT16_C( 13256)) },
    { simde_mm256_set_epi16(INT16_C(-18549), INT16_C( -1433), INT16_C( 15072), INT16_C( 28665),
                            INT16_C(-22672), INT16_C( 30426), INT16_C(-11873), INT16_C(-28559),
                            INT16_C( 26366), INT16_C( 20007), INT16_C( 14676), INT16_C( -4391),
                            INT16_C(-13223), INT16_C(-20349), INT16_C(-14071), INT16_C(  6326)),
      simde_mm256_set_epi16(INT16_C( -8660), INT16_C( -5732), INT16_C( -5248), INT16_C(-16412),
                            INT16_C(-25152), INT16_C( -9368), INT16_C( 18044), INT16_C( 16836),
                            INT16_C(-25608), INT16_C( 14492), INT16_C( -6832), INT16_C(-17564),
                            INT16_C( 12644), INT16_C(-15860), INT16_C(  9252), INT16_C( 25304)) },
    { simde_mm256_set_epi16(INT16_C(-15802), INT16_C(  1115), INT16_C(-15134), INT16_C(-24432),
                            INT16_C( 29893), INT16_C( 28473), INT16_C( 18873), INT16_C( 20173),
                            INT16_C(   191), INT16_C( 32281), INT16_C( 13007), INT16_C( 21879),
                            INT16_C( 31137), INT16_C(-25345), INT16_C(  8960), INT16_C(  9998)),
      simde_mm256_set_epi16(INT16_C(  4656), INT16_C(  8920), INT16_C( 10000), INT16_C(  1152),
                            INT16_C(-23000), INT16_C( 31176), INT16_C( 19912), INT16_C( 30312),
                            INT16_C(  1528), INT16_C( -3896), INT16_C(-27016), INT16_C(-21576),
                            INT16_C(-13048), INT16_C( -6152), INT16_C(  6144), INT16_C( 14448)) },
    { simde_mm256_set_epi16(INT16_C(-11235), INT16_C( 12162), INT16_C(-25050), INT16_C(-16691),
                            INT16_C(-21645), INT16_C(-11525), INT16_C( 24581), INT16_C( 20473),
                            INT16_C( 17987), INT16_C( 13992), INT16_C( 21082), INT16_C(  9896),
                            INT16_C( 20946), INT16_C(  -338), INT16_C(  -890), INT16_C(  3047)),
      simde_mm256_set_epi16(INT16_C( 16848), INT16_C( -2016), INT16_C( -7584), INT16_C( -4912),
                            INT16_C(-18640), INT16_C( 12208), INT16_C(    80), INT16_C(  -112),
                            INT16_C( 25648), INT16_C( 27264), INT16_C(  9632), INT16_C( 27264),
                            INT16_C(  7456), INT16_C( -5408), INT16_C(-14240), INT16_C(-16784)) },
    { simde_mm256_set_epi16(INT16_C(  4232), INT16_C(  9528), INT16_C(  5625), INT16_C( -2056),
                            INT16_C( -5147), INT16_C(-18162), INT16_C(-12026), INT16_C(-23947),
                            INT16_C( 19702), INT16_C( 18533), INT16_C( 17268), INT16_C( -7285),
                            INT16_C(-25540), INT16_C( 15541), INT16_C(-16480), INT16_C(-30543)),
      simde_mm256_set_epi16(INT16_C(  4352), INT16_C(-22784), INT16_C(-16608), INT16_C(  -256),
                            INT16_C( 31904), INT16_C(  8640), INT16_C(  8384), INT16_C( 20128),
                            INT16_C(-24896), INT16_C(  3232), INT16_C( 28288), INT16_C( 29024),
                            INT16_C(-30848), INT16_C(-26976), INT16_C( -3072), INT16_C(  5664)) },
    { simde_mm256_set_epi16(INT16_C( 21401), INT16_C(-26197), INT16_C(-15084), INT16_C(  9940),
                            INT16_C(-15195), INT16_C( 26408), INT16_C( 31953), INT16_C(  9654),
                            INT16_C(-16569), INT16_C( 29048), INT16_C(-29616), INT16_C(  6990),
                            INT16_C(  2847), INT16_C(-28587), INT16_C( 20626), INT16_C(  4687)),
      simde_mm256_set_epi16(INT16_C( -6592), INT16_C( 27328), INT16_C( 17664), INT16_C(-19200),
                            INT16_C( 10560), INT16_C(-13824), INT16_C( 13376), INT16_C( 28032),
                            INT16_C(-11840), INT16_C( 24064), INT16_C(  5120), INT16_C(-11392),
                            INT16_C(-14400), INT16_C(  5440), INT16_C(  9344), INT16_C(-27712)) },
    { simde_mm256_set_epi16(INT16_C( -7756), INT16_C( -3283), INT16_C(-22803), INT16_C(-16163),
                            INT16_C(  5629), INT16_C( 29150), INT16_C( -9667), INT16_C( 12335),
                            INT16_C(-18839), INT16_C(-10112), INT16_C(-18195), INT16_C(-15969),
                            INT16_C(-29495), INT16_C( 29894), INT16_C(-13459), INT16_C( 16744)),
      simde_mm256_set_epi16(INT16_C( -9728), INT16_C(-27008), INT16_C( 30336), INT16_C( 28288),
                            INT16_C(  -384), INT16_C( -4352), INT16_C(  7808), INT16_C(  6016),
                            INT16_C( 13440), INT16_C( 16384), INT16_C( 30336), INT16_C(-12416),
                            INT16_C( 25728), INT16_C( 25344), INT16_C(-18816), INT16_C(-19456)) },
    { simde_mm256_set_epi16(INT16_C(-28557), INT16_C(-10724), INT16_C(  2722), INT16_C(-10967),
                            INT16_C(  5210), INT16_C( 29322), INT16_C( 15248), INT16_C( -8080),
                            INT16_C(-19889), INT16_C( 30125), INT16_C( 14116), INT16_C(-29183),
                            INT16_C( 11578), INT16_C(-15372), INT16_C(-24444), INT16_C( 10332)),
      simde_mm256_set_epi16(INT16_C( 29440), INT16_C(  7168), INT16_C(-24064), INT16_C( 10496),
                            INT16_C( 23040), INT16_C(-30208), INT16_C(-28672), INT16_C( 28672),
                            INT16_C( 20224), INT16_C(-21248), INT16_C(  9216), INT16_C(   256),
                            INT16_C( 14848), INT16_C( -3072), INT16_C(-31744), INT16_C( 23552)) },
    { simde_mm256_set_epi16(INT16_C(-21274), INT16_C(-31982), INT16_C(-20961), INT16_C(  5088),
                            INT16_C(-17462), INT16_C( -9409), INT16_C( 15757), INT16_C(  1966),
                            INT16_C(-22236), INT16_C(-28953), INT16_C( -1919), INT16_C(-19201),
                            INT16_C( 20002), INT16_C( 13277), INT16_C(-29203), INT16_C(-31968)),
      simde_mm256_set_epi16(INT16_C(-13312), INT16_C(  9216), INT16_C( 15872), INT16_C(-16384),
                            INT16_C(-27648), INT16_C( 32256), INT16_C(  6656), INT16_C( 23552),
                            INT16_C( 18432), INT16_C(-12800), INT16_C(   512), INT16_C(  -512),
                            INT16_C( 17408), INT16_C(-17920), INT16_C( -9728), INT16_C( 16384)) },
    { simde_mm256_set_epi16(INT16_C( 18957), INT16_C( -9706), INT16_C( -6614), INT16_C( 10095),
                            INT16_C(  5161), INT16_C(  -605), INT16_C( 13764), INT16_C( 27464),
                            INT16_C( -3974), INT16_C( -5977), INT16_C(-10905), INT16_C(   357),
                            INT16_C(-20180), INT16_C(  8910), INT16_C( -3748), INT16_C(  6077)),
      simde_mm256_set_epi16(INT16_C( 13312), INT16_C( 22528), INT16_C(-22528), INT16_C(-17408),
                            INT16_C(-23552), INT16_C(-29696), INT16_C(  4096), INT16_C(  8192),
                            INT16_C( -6144), INT16_C(-25600), INT16_C(-25600), INT16_C(-27648),
                            INT16_C(-20480), INT16_C( 14336), INT16_C( 28672), INT16_C( -3072)) },
    { simde_mm256_set_epi16(INT16_C(-31972), INT16_C( 18963), INT16_C( 30683), INT16_C(-21818),
                            INT16_C(-14936), INT16_C(-28324), INT16_C( -9468), INT16_C(-30588),
                            INT16_C(-23376), INT16_C( 11957), INT16_C(-26836), INT16_C(  1095),
                            INT16_C(  3892), INT16_C( 16953), INT16_C( 18603), INT16_C(-10451)),
      simde_mm256_set_epi16(INT16_C( -8192), INT16_C(-26624), INT16_C(-10240), INT16_C( 12288),
                            INT16_C( 16384), INT16_C( -8192), INT16_C(  8192), INT16_C(  8192),
                            INT16_C(-32768), INT16_C(-22528), INT16_C( 24576), INT16_C( 14336),
                            INT16_C(-24576), INT16_C(-14336), INT16_C( 22528), INT16_C( 26624)) },
    { simde_mm256_set_epi16(INT16_C( -5389), INT16_C(-19407), INT16_C( 25290), INT16_C( -4640),
                            INT16_C( 29672), INT16_C( 23128), INT16_C(-13360), INT16_C(-25779),
                            INT16_C(-15993), INT16_C( -8711), INT16_C(-27319), INT16_C(  5516),
                            INT16_C(-14272), INT16_C( 31123), INT16_C(-10448), INT16_C( 22014)),
      simde_mm256_set_epi16(INT16_C( 12288), INT16_C(  4096), INT16_C(-24576), INT16_C(     0),
                            INT16_C(-32768), INT16_C(-32768), INT16_C(     0), INT16_C(-12288),
                            INT16_C( 28672), INT16_C(-28672), INT16_C(-28672), INT16_C(-16384),
                            INT16_C(     0), INT16_C( 12288), INT16_C(     0), INT16_C( -8192)) },
    { simde_mm256_set_epi16(INT16_C( -8792), INT16_C( -1044), INT16_C(-11356), INT16_C( -9495),
                            INT16_C(  4809), INT16_C(-13629), INT16_C( 15424), INT16_C(-18049),
                            INT16_C(  4498), INT16_C(-15799), INT16_C(-26777), INT16_C(  7570),
                            INT16_C( 20105), INT16_C( -5032), INT16_C( -5734), INT16_C(-24145)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(-32768), INT16_C(-32768), INT16_C(  8192),
                            INT16_C(  8192), INT16_C( 24576), INT16_C(     0), INT16_C( -8192),
                            INT16_C( 16384), INT16_C(  8192), INT16_C( -8192), INT16_C( 16384),
                            INT16_C(  8192), INT16_C(     0), INT16_C( 16384), INT16_C( -8192)) },
    { simde_mm256_set_epi16(INT16_C(-28948), INT16_C(-14792), INT16_C( 23966), INT16_C( 21707),
                            INT16_C(  7390), INT16_C(  8499), INT16_C( 25220), INT16_C( 26210),
                            INT16_C(  3798), INT16_C( 20760), INT16_C(-20165), INT16_C(-15694),
                            INT16_C(   538), INT16_C(    97), INT16_C( -3558), INT16_C(-31643)),
      simde_mm256_set_epi16(INT16_C(     0), INT16_C(     0), INT16_C(-32768), INT16_C(-16384),
                            INT16_C(-32768), INT16_C(-16384), INT16_C(     0), INT16_C(-32768),
                            INT16_C(-32768), INT16_C(     0), INT16_C(-16384), INT16_C(-32768),
                            INT16_C(-32768), INT16_C( 16384), INT16_C(-32768), INT16_C( 16384)) },
    { simde_mm256_set_epi16(INT16_C(-17181), INT16_C(  9599), INT16_C(-10139), INT16_C(-21574),
                            INT16_C( -1148), INT16_C(-14339), INT16_C( -9621), INT16_C(  4987),
                            INT16_C(-25046), INT16_C( 11688), INT16_C( -9678), INT16_C( -6619),
                            INT16_C( 24962), INT16_C(-11214), INT16_C( 26930), INT16_C(-12095)),
      simde_mm256_set_epi16(INT16_C(-32768), INT16_C(-32768), INT16_C(-32768), INT16_C(     0),
                            INT16_C(     0), INT16_C(-32768), INT16_C(-32768), INT16_C(-32768),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(-32768),
                            INT16_C(     0), INT16_C(     0), INT16_C(     0), INT16_C(-32768)) }
  };

  simde__m256i r;

  r = simde_mm256_slli_epi16(test_vec[0].a, 0);
  simde_assert_m256i_i16(r, ==, test_vec[0].r);

  r = simde_mm256_slli_epi16(test_vec[1].a, 1);
  simde_assert_m256i_i16(r, ==, test_vec[1].r);

  r = simde_mm256_slli_epi16(test_vec[2].a, 2);
  simde_assert_m256i_i16(r, ==, test_vec[2].r);

  r = simde_mm256_slli_epi16(test_vec[3].a, 3);
  simde_assert_m256i_i16(r, ==, test_vec[3].r);

  r = simde_mm256_slli_epi16(test_vec[4].a, 4);
  simde_assert_m256i_i16(r, ==, test_vec[4].r);

  r = simde_mm256_slli_epi16(test_vec[5].a, 5);
  simde_assert_m256i_i16(r, ==, test_vec[5].r);

  r = simde_mm256_slli_epi16(test_vec[6].a, 6);
  simde_assert_m256i_i16(r, ==, test_vec[6].r);

  r = simde_mm256_slli_epi16(test_vec[7].a, 7);
  simde_assert_m256i_i16(r, ==, test_vec[7].r);

  r = simde_mm256_slli_epi16(test_vec[8].a, 8);
  simde_assert_m256i_i16(r, ==, test_vec[8].r);

  r = simde_mm256_slli_epi16(test_vec[9].a, 9);
  simde_assert_m256i_i16(r, ==, test_vec[9].r);

  r = simde_mm256_slli_epi16(test_vec[10].a, 10);
  simde_assert_m256i_i16(r, ==, test_vec[10].r);

  r = simde_mm256_slli_epi16(test_vec[11].a, 11);
  simde_assert_m256i_i16(r, ==, test_vec[11].r);

  r = simde_mm256_slli_epi16(test_vec[12].a, 12);
  simde_assert_m256i_i16(r, ==, test_vec[12].r);

  r = simde_mm256_slli_epi16(test_vec[13].a, 13);
  simde_assert_m256i_i16(r, ==, test_vec[13].r);

  r = simde_mm256_slli_epi16(test_vec[14].a, 14);
  simde_assert_m256i_i16(r, ==, test_vec[14].r);

  r = simde_mm256_slli_epi16(test_vec[15].a, 15);
  simde_assert_m256i_i16(r, ==, test_vec[15].r);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_slli_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( 1857969468), INT32_C( 1569141389), INT32_C(-1894985594), INT32_C( 1398609693),
                            INT32_C( 1177229575), INT32_C( 1655079421), INT32_C(-1753400065), INT32_C( -607538910)),
      simde_mm256_set_epi32(INT32_C(-1434991502), INT32_C(-1643531728), INT32_C( 1435031148), INT32_C( -241637048),
                            INT32_C(  325610914), INT32_C(  482634268), INT32_C(-1954026803), INT32_C( -489641480)),
      simde_mm256_set_epi32(INT32_C( -674519168), INT32_C(-1327083104), INT32_C( -509996864), INT32_C( 1805837216),
                            INT32_C( -983359264), INT32_C( 1422933920), INT32_C( -274227232), INT32_C( 2033591360)) },
    { simde_mm256_set_epi32(INT32_C(-1508060177), INT32_C( 2047506344), INT32_C( 1926956558), INT32_C( -567187171),
                            INT32_C( -718834191), INT32_C(  316061425), INT32_C(-1354037966), INT32_C(-2043187872)),
      simde_mm256_set_epi32(INT32_C( -787812104), INT32_C(-1305007947), INT32_C( 1142922615), INT32_C( 1342194494),
                            INT32_C(-1552966924), INT32_C(  272965007), INT32_C(-2116417663), INT32_C( 1446174254)),
      simde_mm256_set_epi32(INT32_C(-1013285408), INT32_C( 1095693568), INT32_C( 1533067712), INT32_C( -970120288),
                            INT32_C(-1527857632), INT32_C( 1524031008), INT32_C( -379541952), INT32_C( -957502464)) },
    { simde_mm256_set_epi32(INT32_C( 1315357752), INT32_C(-1727529785), INT32_C(-1290894210), INT32_C(-1585668235),
                            INT32_C( 1227224502), INT32_C( -793752248), INT32_C( -629408802), INT32_C( 1394059551)),
      simde_mm256_set_epi32(INT32_C(  743833146), INT32_C( -347973949), INT32_C(  521095178), INT32_C( -742841452),
                            INT32_C( -734810084), INT32_C(-1542766714), INT32_C(  575957526), INT32_C(-1816399246)),
      simde_mm256_set_epi32(INT32_C( -858224896), INT32_C(  553621728), INT32_C( 1641058240), INT32_C(  798224032),
                            INT32_C(  616478400), INT32_C(  369731840), INT32_C( 1333754816), INT32_C( 1660232672)) },
    { simde_mm256_set_epi32(INT32_C(  150628023), INT32_C(-2069974717), INT32_C( 1177413093), INT32_C(-2053792688),
                            INT32_C(-1561038597), INT32_C( -690144185), INT32_C( -416879322), INT32_C( 1986359122)),
      simde_mm256_set_epi32(INT32_C(  306184069), INT32_C( 2091432312), INT32_C( 1455569082), INT32_C( 1460019701),
                            INT32_C(-1968965681), INT32_C(-1344732712), INT32_C( 1352620988), INT32_C( 1100122997)),
      simde_mm256_set_epi32(INT32_C(  525129440), INT32_C(-1814681504), INT32_C( -977486688), INT32_C(-1296856576),
                            INT32_C( 1586372448), INT32_C( -609777440), INT32_C( -455236416), INT32_C( -861017536)) },
    { simde_mm256_set_epi32(INT32_C(-1165370523), INT32_C(  190390907), INT32_C( -318174800), INT32_C(-1752249068),
                            INT32_C( 1366077326), INT32_C( 1019085647), INT32_C( 1171551091), INT32_C(-1805589438)),
      simde_mm256_set_epi32(INT32_C(-1007170348), INT32_C( 2038045091), INT32_C(  483759032), INT32_C(-1769389731),
                            INT32_C( 1901958985), INT32_C(-1845366512), INT32_C(  234958311), INT32_C( -992749206)),
      simde_mm256_set_epi32(INT32_C( 1362848928), INT32_C( 1797541728), INT32_C(-1591659008), INT32_C( -237395328),
                            INT32_C(  764801472), INT32_C(-1748997664), INT32_C(-1165070752), INT32_C(-1944287168)) },
    { simde_mm256_set_epi32(INT32_C( -719890300), INT32_C(-1894949227), INT32_C( 1354912660), INT32_C(  262146704),
                            INT32_C(-2066437384), INT32_C( -277466785), INT32_C( 1307284092), INT32_C( -145490102)),
      simde_mm256_set_epi32(INT32_C( 1880856976), INT32_C( -113670921), INT32_C(-1146592891), INT32_C( -833902193),
                            INT32_C( -226567429), INT32_C(  -58637801), INT32_C( -547686157), INT32_C(  870297549)),
      simde_mm256_set_epi32(INT32_C(-1561653120), INT32_C( -508833120), INT32_C(  407532160), INT32_C( -201240064),
                            INT32_C(-1701486848), INT32_C( -289002528), INT32_C(-1116582016), INT32_C( -360715968)) },
    { simde_mm256_set_epi32(INT32_C( 1194726573), INT32_C( -714629781), INT32_C(  721069762), INT32_C(-1027424294),
                            INT32_C(-1451303753), INT32_C( -307072244), INT32_C(  760761319), INT32_C(-1826453170)),
      simde_mm256_set_epi32(INT32_C(-2121454006), INT32_C(  354423919), INT32_C( -610410351), INT32_C(-1822148121),
                            INT32_C( 2107148479), INT32_C(-1935868808), INT32_C( -573099828), INT32_C(  986406309)),
      simde_mm256_set_epi32(INT32_C( -423455328), INT32_C(-1393316512), INT32_C( 1599395904), INT32_C( 1482160960),
                            INT32_C(  802920160), INT32_C(-1236377216), INT32_C(-1425441568), INT32_C( 1683040704)) },
    { simde_mm256_set_epi32(INT32_C( -461263801), INT32_C( 1863945688), INT32_C(  508376318), INT32_C(-1101321410),
                            INT32_C( 1682501002), INT32_C(-1564690744), INT32_C(  469304116), INT32_C(  162493937)),
      simde_mm256_set_epi32(INT32_C( 1027297411), INT32_C(  436621801), INT32_C( 2048624604), INT32_C(  613668083),
                            INT32_C( 2064314140), INT32_C( -717287635), INT32_C( 1286678409), INT32_C(-1591587787)),
      simde_mm256_set_epi32(INT32_C(-1875539744), INT32_C( -483280128), INT32_C( -911827008), INT32_C( -882546752),
                            INT32_C(-1994542784), INT32_C( 1469503744), INT32_C( 2132829824), INT32_C(  904838688)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_slli_epi32(test_vec[i].a, 5);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_slli_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-1180812000753094585), INT64_C(-5675573813228216402),
                             INT64_C(-2208027268370360000), INT64_C( 6465428915389083026)),
      simde_mm256_set_epi64x(INT64_C( 8452611756027991400), INT64_C(-5020149848375082542),
                             INT64_C( 7925308354439905072), INT64_C(  953522845551677435)),
      simde_mm256_set_epi64x(INT64_C( -892495876679923488), INT64_C( 2849078713792591296),
                             INT64_C( 3130103706986686464), INT64_C( 3979540481645589056)) },
    { simde_mm256_set_epi64x(INT64_C(-4047432104007102232), INT64_C(-7778060476316871326),
                             INT64_C( 2270807563927334286), INT64_C(-5320870512275475361)),
      simde_mm256_set_epi64x(INT64_C( 5866182958150697676), INT64_C(-5938517638175025937),
                             INT64_C( 6284264256050873550), INT64_C( 1402097755121835442)),
      simde_mm256_set_epi64x(INT64_C( -390618812260410112), INT64_C(-9090262283915711424),
                             INT64_C(-1121134249163509312), INT64_C(-4247159729429247008)) },
    { simde_mm256_set_epi64x(INT64_C(-5299935544215164629), INT64_C(-5358218550815045801),
                             INT64_C(-2743808865442122704), INT64_C(-5577727586229156383)),
      simde_mm256_set_epi64x(INT64_C(-1628942167927235670), INT64_C( 2616318076895434913),
                             INT64_C(-3093772338434873461), INT64_C( 5967250390824240978)),
      simde_mm256_set_epi64x(INT64_C(-3577240751499303584), INT64_C(-5442296962695501088),
                             INT64_C( 4431836674399831552), INT64_C( 5980157977762511904)) },
    { simde_mm256_set_epi64x(INT64_C( 5567340862163337259), INT64_C(-5967855323816927748),
                             INT64_C(-3043785185238641430), INT64_C( 8117316208405658103)),
      simde_mm256_set_epi64x(INT64_C( 8644099717862406948), INT64_C(-2019559086403734381),
                             INT64_C(-4658546452517300382), INT64_C(-8872814693937714953)),
      simde_mm256_set_epi64x(INT64_C(-6312533147868723872), INT64_C(-6503929625046171776),
                             INT64_C(-5167405559088767680), INT64_C( 1499701637047336672)) },
    { simde_mm256_set_epi64x(INT64_C(-8259641032964555923), INT64_C( 6678157623055419482),
                             INT64_C( -532130775756370858), INT64_C(-6271412084163076656)),
      simde_mm256_set_epi64x(INT64_C( 6145157523311970224), INT64_C(-5190146230173537442),
                             INT64_C(-7773875053091172024), INT64_C(-4385818839583220370)),
      simde_mm256_set_epi64x(INT64_C(-6054096022932066912), INT64_C(-7659884946741195968),
                             INT64_C( 1418559249505684160), INT64_C( 2228998117586614784)) },
    { simde_mm256_set_epi64x(INT64_C(-3893461849415744807), INT64_C(-9064502035867553709),
                             INT64_C( 3098807305629640641), INT64_C( 6650302822439097584)),
      simde_mm256_set_epi64x(INT64_C( 2307018380829868937), INT64_C( 8592643653599303501),
                             INT64_C( 8944692494744620746), INT64_C(-7922755342769649115)),
      simde_mm256_set_epi64x(INT64_C( 4536429334663027488), INT64_C( 5083840031591107168),
                             INT64_C( 6928113411600742432), INT64_C(-8551238566463496704)) },
    { simde_mm256_set_epi64x(INT64_C(-1984148929379503272), INT64_C(-5205661836978001324),
                             INT64_C( 6359749525414039769), INT64_C(-1541764205226378294)),
      simde_mm256_set_epi64x(INT64_C(-1490660722702882908), INT64_C( -633122769786086240),
                             INT64_C(-8686691198507413769), INT64_C(-9123917909533884922)),
      simde_mm256_set_epi64x(INT64_C(-8152533519015449856), INT64_C( -560482119910077824),
                             INT64_C(  597800002444204832), INT64_C( 6003777653884549440)) },
    { simde_mm256_set_epi64x(INT64_C(-5232449947985336963), INT64_C( -518473474085028208),
                             INT64_C( 1841137168562663956), INT64_C( 5952445751598523173)),
      simde_mm256_set_epi64x(INT64_C(-2687140035203018503), INT64_C( -119809082612743153),
                             INT64_C( 6113467954286988131), INT64_C(-1537862337526048352)),
      simde_mm256_set_epi64x(INT64_C(-1417701672144818272), INT64_C( 1855592902988648960),
                             INT64_C( 3576157172876591744), INT64_C( 6010823314057225376)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_slli_epi64(test_vec[i].a,5);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}


static MunitResult
test_simde_mm256_srli_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(13444540030250453406)), HEDLEY_STATIC_CAST(int64_t, UINT64_C( 3078071440592676417)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(12679412335333608791)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(11535715936901372554))),
      simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1641179202911432)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(     375741142650473)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1547779826090528)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1408168449328780))) },
    { simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(  225928524470693751)), HEDLEY_STATIC_CAST(int64_t, UINT64_C( 2474929979316735680)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C( 9996007191945919101)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(17512962486882118479))),
      simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(      27579165584801)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(     302115475990812)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1220215721673085)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(    2137812803574477))) },
    { simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(  982097740378530081)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(  970769818047416681)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(17255424662243862193)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(11037271049098666112))),
      simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(     119884978073551)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(     118502175054616)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(    2106375080840315)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1347323126110677))) },
    { simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(11593238181509994155)), HEDLEY_STATIC_CAST(int64_t, UINT64_C( 7911460325067993277)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(14357185542824356538)), HEDLEY_STATIC_CAST(int64_t, UINT64_C( 8595783393340762736))),
      simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1415190207703856)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(     965754434212401)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1752586125833051)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1049289965007417))) },
    { simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C( 1166612957385363389)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(16938733438792705089)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(15575845187785487375)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(10601739794903951841))),
      simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(     142408808274580)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(    2067716484227625)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1901348289524595)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1294157689807611))) },
    { simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(15633886144376419396)), HEDLEY_STATIC_CAST(int64_t, UINT64_C( 8542868240583792995)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(15596557227725823268)), HEDLEY_STATIC_CAST(int64_t, UINT64_C( 8048867687018942442))),
      simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1908433367233449)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1042830595774388)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1903876614712624)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(     982527793825554))) },
    { simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(15325764881028507458)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(15687264368536599834)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(15848782944379583666)), HEDLEY_STATIC_CAST(int64_t, UINT64_C( 6713584830763153714))),
      simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1870820908328675)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1914949263737377)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1934665886765085)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(     819529398286517))) },
    { simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C( 4987716052637776361)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(12811672244172189341)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C( 5840602719775879932)), HEDLEY_STATIC_CAST(int64_t, UINT64_C( 2103118507556192853))),
      simde_mm256_set_epi64x(HEDLEY_STATIC_CAST(int64_t, UINT64_C(     608852057206759)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(    1563924834493675)),
                             HEDLEY_STATIC_CAST(int64_t, UINT64_C(     712964199191391)), HEDLEY_STATIC_CAST(int64_t, UINT64_C(     256728333441918))) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_srli_epi64(test_vec[i].a, 13);
    simde_assert_m256i_u64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_srli_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C(  96), INT8_C(  17), INT8_C(  11), INT8_C( 103),
                           INT8_C(  75), INT8_C(  47), INT8_C( -18), INT8_C(   1),
                           INT8_C(  93), INT8_C( -43), INT8_C( -55), INT8_C( 100),
                           INT8_C( -48), INT8_C(  21), INT8_C( -29), INT8_C(  10),
                           INT8_C(  66), INT8_C(-116), INT8_C(  19), INT8_C( -92),
                           INT8_C( -95), INT8_C(  82), INT8_C( -36), INT8_C( -42),
                           INT8_C( 126), INT8_C(  88), INT8_C( -28), INT8_C(  -8),
                           INT8_C( -38), INT8_C(-106), INT8_C(  21), INT8_C(  13)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  96),
                           INT8_C(  17), INT8_C(  11), INT8_C( 103), INT8_C(  75),
                           INT8_C(  47), INT8_C( -18), INT8_C(   1), INT8_C(  93),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  66),
                           INT8_C(-116), INT8_C(  19), INT8_C( -92), INT8_C( -95),
                           INT8_C(  82), INT8_C( -36), INT8_C( -42), INT8_C( 126)) },
    { simde_mm256_set_epi8(INT8_C(-108), INT8_C( -86), INT8_C( -14), INT8_C( -95),
                           INT8_C( 109), INT8_C(  36), INT8_C(  47), INT8_C(-100),
                           INT8_C(  19), INT8_C(  29), INT8_C( -48), INT8_C(-125),
                           INT8_C( -86), INT8_C(  59), INT8_C(-103), INT8_C(  59),
                           INT8_C( 123), INT8_C( -73), INT8_C(-107), INT8_C( -42),
                           INT8_C(  68), INT8_C(  37), INT8_C( 115), INT8_C(  51),
                           INT8_C( -48), INT8_C(  56), INT8_C(  -7), INT8_C( -79),
                           INT8_C( -38), INT8_C(-103), INT8_C(  68), INT8_C(  60)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(-108),
                           INT8_C( -86), INT8_C( -14), INT8_C( -95), INT8_C( 109),
                           INT8_C(  36), INT8_C(  47), INT8_C(-100), INT8_C(  19),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( 123),
                           INT8_C( -73), INT8_C(-107), INT8_C( -42), INT8_C(  68),
                           INT8_C(  37), INT8_C( 115), INT8_C(  51), INT8_C( -48)) },
    { simde_mm256_set_epi8(INT8_C(  76), INT8_C(  16), INT8_C( -72), INT8_C( 118),
                           INT8_C(  21), INT8_C( -73), INT8_C( -17), INT8_C( -69),
                           INT8_C( 119), INT8_C(  79), INT8_C(  76), INT8_C(  29),
                           INT8_C(  50), INT8_C( -64), INT8_C( -33), INT8_C( 123),
                           INT8_C( -96), INT8_C(  33), INT8_C(  83), INT8_C( -25),
                           INT8_C(  49), INT8_C(   0), INT8_C( -75), INT8_C( 118),
                           INT8_C( -51), INT8_C( -18), INT8_C( -17), INT8_C(-114),
                           INT8_C(  65), INT8_C(  26), INT8_C( -78), INT8_C(  60)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  76),
                           INT8_C(  16), INT8_C( -72), INT8_C( 118), INT8_C(  21),
                           INT8_C( -73), INT8_C( -17), INT8_C( -69), INT8_C( 119),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( -96),
                           INT8_C(  33), INT8_C(  83), INT8_C( -25), INT8_C(  49),
                           INT8_C(   0), INT8_C( -75), INT8_C( 118), INT8_C( -51)) },
    { simde_mm256_set_epi8(INT8_C( -24), INT8_C( -43), INT8_C( -68), INT8_C(  95),
                           INT8_C( -74), INT8_C(  73), INT8_C( 100), INT8_C( 109),
                           INT8_C(  96), INT8_C( -49), INT8_C( -75), INT8_C( 117),
                           INT8_C(  13), INT8_C( -72), INT8_C( -68), INT8_C(  14),
                           INT8_C( -76), INT8_C(  76), INT8_C(  21), INT8_C( -85),
                           INT8_C( -57), INT8_C(-103), INT8_C(  22), INT8_C( -25),
                           INT8_C( -64), INT8_C(   0), INT8_C(  92), INT8_C( -92),
                           INT8_C(-101), INT8_C( -65), INT8_C( -20), INT8_C(  63)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( -24),
                           INT8_C( -43), INT8_C( -68), INT8_C(  95), INT8_C( -74),
                           INT8_C(  73), INT8_C( 100), INT8_C( 109), INT8_C(  96),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( -76),
                           INT8_C(  76), INT8_C(  21), INT8_C( -85), INT8_C( -57),
                           INT8_C(-103), INT8_C(  22), INT8_C( -25), INT8_C( -64)) },
    { simde_mm256_set_epi8(INT8_C( -68), INT8_C( -24), INT8_C(  84), INT8_C(-116),
                           INT8_C( -43), INT8_C(  79), INT8_C( -39), INT8_C( -68),
                           INT8_C( 124), INT8_C( -14), INT8_C(  98), INT8_C(-100),
                           INT8_C( 125), INT8_C( 110), INT8_C(  79), INT8_C( -13),
                           INT8_C( -72), INT8_C(-119), INT8_C( -50), INT8_C(  -7),
                           INT8_C( 127), INT8_C( 126), INT8_C( -62), INT8_C(-124),
                           INT8_C( -36), INT8_C( -38), INT8_C(  -1), INT8_C(  11),
                           INT8_C(  -6), INT8_C(  75), INT8_C(   3), INT8_C(  46)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( -68),
                           INT8_C( -24), INT8_C(  84), INT8_C(-116), INT8_C( -43),
                           INT8_C(  79), INT8_C( -39), INT8_C( -68), INT8_C( 124),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( -72),
                           INT8_C(-119), INT8_C( -50), INT8_C(  -7), INT8_C( 127),
                           INT8_C( 126), INT8_C( -62), INT8_C(-124), INT8_C( -36)) },
    { simde_mm256_set_epi8(INT8_C(-121), INT8_C( -60), INT8_C(  94), INT8_C( 113),
                           INT8_C( -23), INT8_C( 116), INT8_C(  51), INT8_C(  98),
                           INT8_C(  52), INT8_C( -39), INT8_C( -43), INT8_C(  -8),
                           INT8_C(  98), INT8_C(  57), INT8_C( -33), INT8_C( -19),
                           INT8_C(   7), INT8_C( -17), INT8_C(  13), INT8_C( 106),
                           INT8_C(-115), INT8_C(-117), INT8_C(-118), INT8_C( -11),
                           INT8_C(  -1), INT8_C( 104), INT8_C( -53), INT8_C(  93),
                           INT8_C( -53), INT8_C(  34), INT8_C( -17), INT8_C( -60)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(-121),
                           INT8_C( -60), INT8_C(  94), INT8_C( 113), INT8_C( -23),
                           INT8_C( 116), INT8_C(  51), INT8_C(  98), INT8_C(  52),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   7),
                           INT8_C( -17), INT8_C(  13), INT8_C( 106), INT8_C(-115),
                           INT8_C(-117), INT8_C(-118), INT8_C( -11), INT8_C(  -1)) },
    { simde_mm256_set_epi8(INT8_C( -26), INT8_C( -15), INT8_C( -63), INT8_C(  20),
                           INT8_C( -47), INT8_C( -75), INT8_C( -93), INT8_C( -10),
                           INT8_C( -70), INT8_C( -68), INT8_C(  51), INT8_C( -33),
                           INT8_C( -77), INT8_C( -93), INT8_C(-109), INT8_C( -87),
                           INT8_C(-100), INT8_C( -94), INT8_C(  37), INT8_C( -30),
                           INT8_C( -77), INT8_C( -68), INT8_C( -55), INT8_C(-112),
                           INT8_C( -35), INT8_C(  48), INT8_C(  19), INT8_C( 104),
                           INT8_C(  67), INT8_C( 105), INT8_C(-110), INT8_C( 111)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( -26),
                           INT8_C( -15), INT8_C( -63), INT8_C(  20), INT8_C( -47),
                           INT8_C( -75), INT8_C( -93), INT8_C( -10), INT8_C( -70),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(-100),
                           INT8_C( -94), INT8_C(  37), INT8_C( -30), INT8_C( -77),
                           INT8_C( -68), INT8_C( -55), INT8_C(-112), INT8_C( -35)) },
    { simde_mm256_set_epi8(INT8_C(  45), INT8_C( -53), INT8_C(-119), INT8_C(  36),
                           INT8_C( -11), INT8_C( -24), INT8_C( 109), INT8_C( -22),
                           INT8_C( -79), INT8_C( -98), INT8_C( -10), INT8_C(  35),
                           INT8_C(  46), INT8_C(-121), INT8_C(   7), INT8_C(  38),
                           INT8_C( 124), INT8_C( -47), INT8_C(  -7), INT8_C(  41),
                           INT8_C(  33), INT8_C(  95), INT8_C(  12), INT8_C(   3),
                           INT8_C( 105), INT8_C(  16), INT8_C(  33), INT8_C(-106),
                           INT8_C(  94), INT8_C(  28), INT8_C(  14), INT8_C(  63)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  45),
                           INT8_C( -53), INT8_C(-119), INT8_C(  36), INT8_C( -11),
                           INT8_C( -24), INT8_C( 109), INT8_C( -22), INT8_C( -79),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C( 124),
                           INT8_C( -47), INT8_C(  -7), INT8_C(  41), INT8_C(  33),
                           INT8_C(  95), INT8_C(  12), INT8_C(   3), INT8_C( 105)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_srli_si256(test_vec[i].a, 7);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sub_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
   { simde_mm256_set_epi8(INT8_C( -37), INT8_C(  -5), INT8_C( -23), INT8_C(  84),
                           INT8_C(-108), INT8_C( -92), INT8_C(  86), INT8_C( -77),
                           INT8_C(  77), INT8_C( -93), INT8_C( -37), INT8_C( 101),
                           INT8_C(  79), INT8_C( -45), INT8_C(  56), INT8_C( -51),
                           INT8_C( 103), INT8_C(-116), INT8_C( -58), INT8_C(  -2),
                           INT8_C(  39), INT8_C(-101), INT8_C(-113), INT8_C(  21),
                           INT8_C( -77), INT8_C(  26), INT8_C( -37), INT8_C( 126),
                           INT8_C( 102), INT8_C(  27), INT8_C( -92), INT8_C( -33)),
      simde_mm256_set_epi8(INT8_C(-122), INT8_C( -91), INT8_C(  24), INT8_C(-103),
                           INT8_C(  34), INT8_C(   5), INT8_C( 109), INT8_C(-120),
                           INT8_C(  -7), INT8_C(  86), INT8_C(   3), INT8_C(  90),
                           INT8_C(  98), INT8_C(-108), INT8_C(-128), INT8_C(  33),
                           INT8_C( -84), INT8_C( -73), INT8_C( -39), INT8_C(  33),
                           INT8_C( 103), INT8_C( -21), INT8_C(-117), INT8_C( -60),
                           INT8_C( -48), INT8_C( -88), INT8_C(  95), INT8_C( 100),
                           INT8_C( -66), INT8_C(  52), INT8_C( -40), INT8_C(  90)),
      simde_mm256_set_epi8(INT8_C(  85), INT8_C(  86), INT8_C( -47), INT8_C( -69),
                           INT8_C( 114), INT8_C( -97), INT8_C( -23), INT8_C(  43),
                           INT8_C(  84), INT8_C(  77), INT8_C( -40), INT8_C(  11),
                           INT8_C( -19), INT8_C(  63), INT8_C( -72), INT8_C( -84),
                           INT8_C( -69), INT8_C( -43), INT8_C( -19), INT8_C( -35),
                           INT8_C( -64), INT8_C( -80), INT8_C(   4), INT8_C(  81),
                           INT8_C( -29), INT8_C( 114), INT8_C( 124), INT8_C(  26),
                           INT8_C( -88), INT8_C( -25), INT8_C( -52), INT8_C(-123)) },
    { simde_mm256_set_epi8(INT8_C( -74), INT8_C( -43), INT8_C( -65), INT8_C(  71),
                           INT8_C(-122), INT8_C(-128), INT8_C(   4), INT8_C(  54),
                           INT8_C(  12), INT8_C(  60), INT8_C(  80), INT8_C( -43),
                           INT8_C( -85), INT8_C(  94), INT8_C( -70), INT8_C(  67),
                           INT8_C(  82), INT8_C(  40), INT8_C( -92), INT8_C( -55),
                           INT8_C( 114), INT8_C(  12), INT8_C( -43), INT8_C( -93),
                           INT8_C( -89), INT8_C( -90), INT8_C(  46), INT8_C( -34),
                           INT8_C( -53), INT8_C(   0), INT8_C(  91), INT8_C( -43)),
      simde_mm256_set_epi8(INT8_C(  34), INT8_C( -42), INT8_C(  32), INT8_C( -31),
                           INT8_C( 117), INT8_C( -44), INT8_C( 116), INT8_C( -46),
                           INT8_C( 114), INT8_C(  78), INT8_C(  -3), INT8_C( 123),
                           INT8_C( 103), INT8_C(   4), INT8_C( -99), INT8_C(-112),
                           INT8_C(  67), INT8_C(-113), INT8_C(  -1), INT8_C(-117),
                           INT8_C( -58), INT8_C( -63), INT8_C(-110), INT8_C(  65),
                           INT8_C(  53), INT8_C(-113), INT8_C(-123), INT8_C( -24),
                           INT8_C( -84), INT8_C( -96), INT8_C( 116), INT8_C(  23)),
      simde_mm256_set_epi8(INT8_C(-108), INT8_C(  -1), INT8_C( -97), INT8_C( 102),
                           INT8_C(  17), INT8_C( -84), INT8_C(-112), INT8_C( 100),
                           INT8_C(-102), INT8_C( -18), INT8_C(  83), INT8_C(  90),
                           INT8_C(  68), INT8_C(  90), INT8_C(  29), INT8_C( -77),
                           INT8_C(  15), INT8_C(-103), INT8_C( -91), INT8_C(  62),
                           INT8_C( -84), INT8_C(  75), INT8_C(  67), INT8_C(  98),
                           INT8_C( 114), INT8_C(  23), INT8_C( -87), INT8_C( -10),
                           INT8_C(  31), INT8_C(  96), INT8_C( -25), INT8_C( -66)) },
    { simde_mm256_set_epi8(INT8_C( -56), INT8_C( -54), INT8_C( -84), INT8_C( -79),
                           INT8_C(  25), INT8_C( -22), INT8_C( -93), INT8_C( -71),
                           INT8_C(-106), INT8_C(-125), INT8_C( -67), INT8_C(  53),
                           INT8_C( 101), INT8_C(-105), INT8_C( -28), INT8_C(  37),
                           INT8_C( -61), INT8_C( -39), INT8_C(-117), INT8_C(-116),
                           INT8_C( -16), INT8_C(-126), INT8_C(  25), INT8_C( 103),
                           INT8_C( -81), INT8_C(  88), INT8_C(   1), INT8_C(  20),
                           INT8_C(  36), INT8_C(  16), INT8_C( -44), INT8_C( 107)),
      simde_mm256_set_epi8(INT8_C(  73), INT8_C(-125), INT8_C(  72), INT8_C(  17),
                           INT8_C( -36), INT8_C(  20), INT8_C( -81), INT8_C(  10),
                           INT8_C( 119), INT8_C(  41), INT8_C( -90), INT8_C( -54),
                           INT8_C(-116), INT8_C(  15), INT8_C( -64), INT8_C(  60),
                           INT8_C( -43), INT8_C(   5), INT8_C(  93), INT8_C(  54),
                           INT8_C( -46), INT8_C(-106), INT8_C(-117), INT8_C( 127),
                           INT8_C(  81), INT8_C( -75), INT8_C(-105), INT8_C(  31),
                           INT8_C(  51), INT8_C(-105), INT8_C( -23), INT8_C(  95)),
      simde_mm256_set_epi8(INT8_C( 127), INT8_C(  71), INT8_C( 100), INT8_C( -96),
                           INT8_C(  61), INT8_C( -42), INT8_C( -12), INT8_C( -81),
                           INT8_C(  31), INT8_C(  90), INT8_C(  23), INT8_C( 107),
                           INT8_C( -39), INT8_C(-120), INT8_C(  36), INT8_C( -23),
                           INT8_C( -18), INT8_C( -44), INT8_C(  46), INT8_C(  86),
                           INT8_C(  30), INT8_C( -20), INT8_C(-114), INT8_C( -24),
                           INT8_C(  94), INT8_C( -93), INT8_C( 106), INT8_C( -11),
                           INT8_C( -15), INT8_C( 121), INT8_C( -21), INT8_C(  12)) },
    { simde_mm256_set_epi8(INT8_C( 114), INT8_C(  34), INT8_C(  26), INT8_C( -19),
                           INT8_C( -79), INT8_C( -66), INT8_C( -16), INT8_C(  14),
                           INT8_C(-119), INT8_C(  36), INT8_C(  48), INT8_C(-124),
                           INT8_C(  -3), INT8_C(  65), INT8_C(  48), INT8_C(-117),
                           INT8_C( -76), INT8_C( -16), INT8_C(  83), INT8_C(   8),
                           INT8_C(  76), INT8_C( -37), INT8_C( -88), INT8_C( -95),
                           INT8_C( -96), INT8_C(  84), INT8_C(  -4), INT8_C(  56),
                           INT8_C(  13), INT8_C( -84), INT8_C( 107), INT8_C( -97)),
      simde_mm256_set_epi8(INT8_C(-116), INT8_C( -40), INT8_C( 117), INT8_C(  -7),
                           INT8_C( -80), INT8_C(  53), INT8_C( -24), INT8_C(-123),
                           INT8_C(-119), INT8_C( -47), INT8_C( -64), INT8_C( -25),
                           INT8_C( 117), INT8_C(  45), INT8_C(  40), INT8_C( -91),
                           INT8_C(  19), INT8_C( 123), INT8_C(  36), INT8_C(  -6),
                           INT8_C(  29), INT8_C(  -9), INT8_C( 117), INT8_C( -17),
                           INT8_C( -12), INT8_C(  82), INT8_C( 121), INT8_C(   9),
                           INT8_C( -40), INT8_C(-118), INT8_C( -50), INT8_C( -94)),
      simde_mm256_set_epi8(INT8_C( -26), INT8_C(  74), INT8_C( -91), INT8_C( -12),
                           INT8_C(   1), INT8_C(-119), INT8_C(   8), INT8_C(-119),
                           INT8_C(   0), INT8_C(  83), INT8_C( 112), INT8_C( -99),
                           INT8_C(-120), INT8_C(  20), INT8_C(   8), INT8_C( -26),
                           INT8_C( -95), INT8_C( 117), INT8_C(  47), INT8_C(  14),
                           INT8_C(  47), INT8_C( -28), INT8_C(  51), INT8_C( -78),
                           INT8_C( -84), INT8_C(   2), INT8_C(-125), INT8_C(  47),
                           INT8_C(  53), INT8_C(  34), INT8_C( -99), INT8_C(  -3)) },
    { simde_mm256_set_epi8(INT8_C(  95), INT8_C( -54), INT8_C(  -5), INT8_C( -28),
                           INT8_C( -63), INT8_C(  54), INT8_C(-113), INT8_C( 127),
                           INT8_C( -25), INT8_C( -12), INT8_C(-108), INT8_C(-123),
                           INT8_C( -64), INT8_C(  68), INT8_C(  89), INT8_C(  72),
                           INT8_C( -46), INT8_C( -63), INT8_C(  56), INT8_C( 125),
                           INT8_C(  44), INT8_C(   8), INT8_C(  49), INT8_C( 105),
                           INT8_C(  43), INT8_C(  41), INT8_C( -46), INT8_C(-117),
                           INT8_C(  22), INT8_C(  27), INT8_C( -55), INT8_C( 106)),
      simde_mm256_set_epi8(INT8_C(  15), INT8_C( -64), INT8_C(   3), INT8_C( -17),
                           INT8_C( 127), INT8_C(-101), INT8_C(  76), INT8_C(  31),
                           INT8_C(  79), INT8_C( 115), INT8_C( -72), INT8_C( -19),
                           INT8_C(-105), INT8_C( 117), INT8_C( -69), INT8_C(  62),
                           INT8_C(  51), INT8_C( -12), INT8_C( -69), INT8_C(-109),
                           INT8_C(-101), INT8_C( -50), INT8_C(  90), INT8_C(  52),
                           INT8_C(  58), INT8_C( -94), INT8_C( -69), INT8_C(  88),
                           INT8_C(  -9), INT8_C(  25), INT8_C(  89), INT8_C(  31)),
      simde_mm256_set_epi8(INT8_C(  80), INT8_C(  10), INT8_C(  -8), INT8_C( -11),
                           INT8_C(  66), INT8_C(-101), INT8_C(  67), INT8_C(  96),
                           INT8_C(-104), INT8_C(-127), INT8_C( -36), INT8_C(-104),
                           INT8_C(  41), INT8_C( -49), INT8_C( -98), INT8_C(  10),
                           INT8_C( -97), INT8_C( -51), INT8_C( 125), INT8_C( -22),
                           INT8_C(-111), INT8_C(  58), INT8_C( -41), INT8_C(  53),
                           INT8_C( -15), INT8_C(-121), INT8_C(  23), INT8_C(  51),
                           INT8_C(  31), INT8_C(   2), INT8_C( 112), INT8_C(  75)) },
    { simde_mm256_set_epi8(INT8_C(  58), INT8_C( -35), INT8_C(  -9), INT8_C( -15),
                           INT8_C( -74), INT8_C( -92), INT8_C( -26), INT8_C( -48),
                           INT8_C( -14), INT8_C(  54), INT8_C(  39), INT8_C( 120),
                           INT8_C( -38), INT8_C( -90), INT8_C( 101), INT8_C(  25),
                           INT8_C(  90), INT8_C( 106), INT8_C(  24), INT8_C( -31),
                           INT8_C( -57), INT8_C(   7), INT8_C(  29), INT8_C( 106),
                           INT8_C( 124), INT8_C(  62), INT8_C(  44), INT8_C(  40),
                           INT8_C(  54), INT8_C(  54), INT8_C( -93), INT8_C( -77)),
      simde_mm256_set_epi8(INT8_C(  65), INT8_C(-103), INT8_C(  10), INT8_C( 103),
                           INT8_C(  65), INT8_C(  90), INT8_C( -56), INT8_C(  98),
                           INT8_C(  64), INT8_C( 110), INT8_C( -94), INT8_C(  23),
                           INT8_C( -62), INT8_C(  19), INT8_C( 115), INT8_C(  93),
                           INT8_C(  68), INT8_C(  91), INT8_C(  -1), INT8_C(   5),
                           INT8_C(  19), INT8_C( -54), INT8_C( -79), INT8_C(-124),
                           INT8_C( -14), INT8_C( 106), INT8_C( -71), INT8_C( -34),
                           INT8_C(  39), INT8_C( -20), INT8_C( 117), INT8_C( -23)),
      simde_mm256_set_epi8(INT8_C(  -7), INT8_C(  68), INT8_C( -19), INT8_C(-118),
                           INT8_C( 117), INT8_C(  74), INT8_C(  30), INT8_C( 110),
                           INT8_C( -78), INT8_C( -56), INT8_C(-123), INT8_C(  97),
                           INT8_C(  24), INT8_C(-109), INT8_C( -14), INT8_C( -68),
                           INT8_C(  22), INT8_C(  15), INT8_C(  25), INT8_C( -36),
                           INT8_C( -76), INT8_C(  61), INT8_C( 108), INT8_C( -26),
                           INT8_C(-118), INT8_C( -44), INT8_C( 115), INT8_C(  74),
                           INT8_C(  15), INT8_C(  74), INT8_C(  46), INT8_C( -54)) },
    { simde_mm256_set_epi8(INT8_C( -10), INT8_C(  24), INT8_C(-113), INT8_C( -36),
                           INT8_C( 115), INT8_C(  49), INT8_C(  18), INT8_C(  86),
                           INT8_C( 112), INT8_C(  85), INT8_C( -24), INT8_C( -37),
                           INT8_C( -39), INT8_C(  13), INT8_C(   8), INT8_C(  92),
                           INT8_C( -95), INT8_C(-112), INT8_C(  83), INT8_C(  16),
                           INT8_C( 106), INT8_C(-127), INT8_C( 122), INT8_C( -83),
                           INT8_C( -96), INT8_C( -94), INT8_C(  86), INT8_C( -10),
                           INT8_C( -44), INT8_C( -36), INT8_C(  93), INT8_C(  71)),
      simde_mm256_set_epi8(INT8_C( -12), INT8_C(-115), INT8_C( 101), INT8_C( -47),
                           INT8_C(  85), INT8_C( -78), INT8_C( -44), INT8_C(  16),
                           INT8_C(  71), INT8_C(   4), INT8_C( -58), INT8_C(   7),
                           INT8_C(  30), INT8_C(  54), INT8_C(  60), INT8_C(  -1),
                           INT8_C( -73), INT8_C( -28), INT8_C( -92), INT8_C( -36),
                           INT8_C(  82), INT8_C( -11), INT8_C( -69), INT8_C(   2),
                           INT8_C( -76), INT8_C( 100), INT8_C(  99), INT8_C(   0),
                           INT8_C( -87), INT8_C( -70), INT8_C(  29), INT8_C( 121)),
      simde_mm256_set_epi8(INT8_C(   2), INT8_C(-117), INT8_C(  42), INT8_C(  11),
                           INT8_C(  30), INT8_C( 127), INT8_C(  62), INT8_C(  70),
                           INT8_C(  41), INT8_C(  81), INT8_C(  34), INT8_C( -44),
                           INT8_C( -69), INT8_C( -41), INT8_C( -52), INT8_C(  93),
                           INT8_C( -22), INT8_C( -84), INT8_C( -81), INT8_C(  52),
                           INT8_C(  24), INT8_C(-116), INT8_C( -65), INT8_C( -85),
                           INT8_C( -20), INT8_C(  62), INT8_C( -13), INT8_C( -10),
                           INT8_C(  43), INT8_C(  34), INT8_C(  64), INT8_C( -50)) },
    { simde_mm256_set_epi8(INT8_C(   2), INT8_C( -33), INT8_C(  21), INT8_C(  39),
                           INT8_C(  -5), INT8_C(-110), INT8_C(-113), INT8_C(  98),
                           INT8_C(   6), INT8_C(  47), INT8_C( -26), INT8_C(  73),
                           INT8_C(-121), INT8_C( -53), INT8_C( 102), INT8_C( 110),
                           INT8_C( -38), INT8_C( -97), INT8_C( -70), INT8_C(-105),
                           INT8_C(-128), INT8_C(  48), INT8_C( -78), INT8_C( 108),
                           INT8_C( 118), INT8_C(   9), INT8_C(  40), INT8_C( 110),
                           INT8_C( -32), INT8_C( -25), INT8_C(  39), INT8_C(-123)),
      simde_mm256_set_epi8(INT8_C(  15), INT8_C(  27), INT8_C(  -7), INT8_C(-103),
                           INT8_C(  81), INT8_C( 127), INT8_C( -25), INT8_C(  51),
                           INT8_C( -31), INT8_C(  28), INT8_C(-102), INT8_C(  24),
                           INT8_C(  73), INT8_C( 119), INT8_C( 106), INT8_C(   1),
                           INT8_C(   5), INT8_C(-108), INT8_C( -84), INT8_C(  54),
                           INT8_C( -30), INT8_C(-120), INT8_C(  39), INT8_C(   6),
                           INT8_C(-115), INT8_C(-128), INT8_C( 110), INT8_C(  39),
                           INT8_C(-110), INT8_C(-102), INT8_C(   6), INT8_C( 126)),
      simde_mm256_set_epi8(INT8_C( -13), INT8_C( -60), INT8_C(  28), INT8_C(-114),
                           INT8_C( -86), INT8_C(  19), INT8_C( -88), INT8_C(  47),
                           INT8_C(  37), INT8_C(  19), INT8_C(  76), INT8_C(  49),
                           INT8_C(  62), INT8_C(  84), INT8_C(  -4), INT8_C( 109),
                           INT8_C( -43), INT8_C(  11), INT8_C(  14), INT8_C(  97),
                           INT8_C( -98), INT8_C( -88), INT8_C(-117), INT8_C( 102),
                           INT8_C( -23), INT8_C(-119), INT8_C( -70), INT8_C(  71),
                           INT8_C(  78), INT8_C(  77), INT8_C(  33), INT8_C(   7)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_sub_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sub_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
   { simde_mm256_set_epi16(INT16_C(-27953), INT16_C(-25893), INT16_C( 18102), INT16_C( -6593),
                            INT16_C(  7623), INT16_C( 27326), INT16_C(-15847), INT16_C( 25196),
                            INT16_C(  4150), INT16_C( 31494), INT16_C( 14922), INT16_C(  2426),
                            INT16_C(  8906), INT16_C( -8618), INT16_C(-26305), INT16_C(  2552)),
      simde_mm256_set_epi16(INT16_C(-20113), INT16_C( 26325), INT16_C( 23863), INT16_C(-13511),
                            INT16_C(  6653), INT16_C( 22833), INT16_C( 26506), INT16_C( 21325),
                            INT16_C(-18785), INT16_C( -8308), INT16_C( -2522), INT16_C(   805),
                            INT16_C(-27299), INT16_C( 31631), INT16_C( -9722), INT16_C(  3708)),
      simde_mm256_set_epi16(INT16_C( -7840), INT16_C( 13318), INT16_C( -5761), INT16_C(  6918),
                            INT16_C(   970), INT16_C(  4493), INT16_C( 23183), INT16_C(  3871),
                            INT16_C( 22935), INT16_C(-25734), INT16_C( 17444), INT16_C(  1621),
                            INT16_C(-29331), INT16_C( 25287), INT16_C(-16583), INT16_C( -1156)) },
    { simde_mm256_set_epi16(INT16_C(-11131), INT16_C(-17560), INT16_C( 30989), INT16_C( -1961),
                            INT16_C( 25635), INT16_C(-31167), INT16_C( 13893), INT16_C(-24056),
                            INT16_C( 29937), INT16_C( 24074), INT16_C(  3624), INT16_C( 30721),
                            INT16_C(  7318), INT16_C(-21871), INT16_C(-24159), INT16_C( 27811)),
      simde_mm256_set_epi16(INT16_C(-14801), INT16_C( 18665), INT16_C( 21171), INT16_C(  2083),
                            INT16_C(  9794), INT16_C(-14994), INT16_C( -7071), INT16_C(-14888),
                            INT16_C( 17983), INT16_C(-13129), INT16_C(-28994), INT16_C(  8299),
                            INT16_C( 22982), INT16_C(  2227), INT16_C(-21646), INT16_C(-28910)),
      simde_mm256_set_epi16(INT16_C(  3670), INT16_C( 29311), INT16_C(  9818), INT16_C( -4044),
                            INT16_C( 15841), INT16_C(-16173), INT16_C( 20964), INT16_C( -9168),
                            INT16_C( 11954), INT16_C(-28333), INT16_C( 32618), INT16_C( 22422),
                            INT16_C(-15664), INT16_C(-24098), INT16_C( -2513), INT16_C( -8815)) },
    { simde_mm256_set_epi16(INT16_C(-23995), INT16_C( 25905), INT16_C( -5982), INT16_C( 20058),
                            INT16_C(  2118), INT16_C(  -114), INT16_C(   287), INT16_C(-16504),
                            INT16_C( 12216), INT16_C( 31693), INT16_C(  7692), INT16_C(-10279),
                            INT16_C( -9654), INT16_C( 13919), INT16_C( 14030), INT16_C( -6049)),
      simde_mm256_set_epi16(INT16_C( 18387), INT16_C(  3058), INT16_C( 24810), INT16_C(-31587),
                            INT16_C( 19314), INT16_C(-13527), INT16_C( 20849), INT16_C(-15645),
                            INT16_C(  4064), INT16_C(  5808), INT16_C( 11755), INT16_C( 23823),
                            INT16_C(-12210), INT16_C(  -514), INT16_C(-10077), INT16_C(  8317)),
      simde_mm256_set_epi16(INT16_C( 23154), INT16_C( 22847), INT16_C(-30792), INT16_C(-13891),
                            INT16_C(-17196), INT16_C( 13413), INT16_C(-20562), INT16_C(  -859),
                            INT16_C(  8152), INT16_C( 25885), INT16_C( -4063), INT16_C( 31434),
                            INT16_C(  2556), INT16_C( 14433), INT16_C( 24107), INT16_C(-14366)) },
    { simde_mm256_set_epi16(INT16_C( 16733), INT16_C(-19192), INT16_C(-19177), INT16_C(-13201),
                            INT16_C(-14970), INT16_C(-23573), INT16_C( 23037), INT16_C(-14068),
                            INT16_C( 18230), INT16_C( 11141), INT16_C(  3822), INT16_C(  6182),
                            INT16_C(-23525), INT16_C(-16307), INT16_C( 26522), INT16_C( 21806)),
      simde_mm256_set_epi16(INT16_C(-30186), INT16_C( 24213), INT16_C( 29509), INT16_C(  2127),
                            INT16_C( -4444), INT16_C( 10965), INT16_C(-26578), INT16_C( -9065),
                            INT16_C( -2827), INT16_C( 31843), INT16_C( 28821), INT16_C(  8551),
                            INT16_C( -1781), INT16_C( 16565), INT16_C(-30183), INT16_C(  9876)),
      simde_mm256_set_epi16(INT16_C(-18617), INT16_C( 22131), INT16_C( 16850), INT16_C(-15328),
                            INT16_C(-10526), INT16_C( 30998), INT16_C(-15921), INT16_C( -5003),
                            INT16_C( 21057), INT16_C(-20702), INT16_C(-24999), INT16_C( -2369),
                            INT16_C(-21744), INT16_C( 32664), INT16_C( -8831), INT16_C( 11930)) },
    { simde_mm256_set_epi16(INT16_C(-10649), INT16_C(  1789), INT16_C( 27012), INT16_C(  5765),
                            INT16_C(-10851), INT16_C(  5376), INT16_C( -9175), INT16_C(-28947),
                            INT16_C(  7733), INT16_C(  7167), INT16_C(-27568), INT16_C(  2115),
                            INT16_C( 10120), INT16_C(-30644), INT16_C(-28345), INT16_C( 20915)),
      simde_mm256_set_epi16(INT16_C( 23043), INT16_C( 25420), INT16_C( 19475), INT16_C(-31775),
                            INT16_C(-12265), INT16_C( -4342), INT16_C( 11340), INT16_C( 16492),
                            INT16_C( 28872), INT16_C( -2502), INT16_C(-23877), INT16_C(-30231),
                            INT16_C(  1907), INT16_C(   764), INT16_C(  -427), INT16_C(-25788)),
      simde_mm256_set_epi16(INT16_C( 31844), INT16_C(-23631), INT16_C(  7537), INT16_C(-27996),
                            INT16_C(  1414), INT16_C(  9718), INT16_C(-20515), INT16_C( 20097),
                            INT16_C(-21139), INT16_C(  9669), INT16_C( -3691), INT16_C( 32346),
                            INT16_C(  8213), INT16_C(-31408), INT16_C(-27918), INT16_C(-18833)) },
    { simde_mm256_set_epi16(INT16_C( 10906), INT16_C( -7304), INT16_C(  1755), INT16_C(  4890),
                            INT16_C(-11395), INT16_C( -7564), INT16_C( 10816), INT16_C(-23172),
                            INT16_C(-11608), INT16_C(-11875), INT16_C(-15837), INT16_C(-17763),
                            INT16_C( 21395), INT16_C(  8598), INT16_C(-20063), INT16_C(-10275)),
      simde_mm256_set_epi16(INT16_C( -9448), INT16_C(  6330), INT16_C(-18331), INT16_C( -6901),
                            INT16_C(-14581), INT16_C( 32348), INT16_C(  9963), INT16_C( 31451),
                            INT16_C( 24178), INT16_C( 12481), INT16_C( 12230), INT16_C(-12978),
                            INT16_C(-27030), INT16_C( -1366), INT16_C(-22019), INT16_C( 19232)),
      simde_mm256_set_epi16(INT16_C( 20354), INT16_C(-13634), INT16_C( 20086), INT16_C( 11791),
                            INT16_C(  3186), INT16_C( 25624), INT16_C(   853), INT16_C( 10913),
                            INT16_C( 29750), INT16_C(-24356), INT16_C(-28067), INT16_C( -4785),
                            INT16_C(-17111), INT16_C(  9964), INT16_C(  1956), INT16_C(-29507)) },
    { simde_mm256_set_epi16(INT16_C( 30843), INT16_C( 21336), INT16_C(  5686), INT16_C(  2828),
                            INT16_C( 19954), INT16_C( 31539), INT16_C(-19646), INT16_C(   671),
                            INT16_C( 25132), INT16_C(  3458), INT16_C(-19712), INT16_C(  4606),
                            INT16_C(  5503), INT16_C(-15517), INT16_C(   355), INT16_C( 25145)),
      simde_mm256_set_epi16(INT16_C( -6584), INT16_C( 11532), INT16_C( 13185), INT16_C(-20125),
                            INT16_C( 10954), INT16_C( -8384), INT16_C(  2784), INT16_C( 19614),
                            INT16_C( 16337), INT16_C( 21741), INT16_C( 28414), INT16_C( 19897),
                            INT16_C(-27104), INT16_C( 23081), INT16_C( 17729), INT16_C( 27826)),
      simde_mm256_set_epi16(INT16_C(-28109), INT16_C(  9804), INT16_C( -7499), INT16_C( 22953),
                            INT16_C(  9000), INT16_C(-25613), INT16_C(-22430), INT16_C(-18943),
                            INT16_C(  8795), INT16_C(-18283), INT16_C( 17410), INT16_C(-15291),
                            INT16_C( 32607), INT16_C( 26938), INT16_C(-17374), INT16_C( -2681)) },
    { simde_mm256_set_epi16(INT16_C(-16362), INT16_C(-26163), INT16_C( -8945), INT16_C(  5119),
                            INT16_C( 30284), INT16_C( 12893), INT16_C(-21079), INT16_C(   124),
                            INT16_C( -1271), INT16_C(  3217), INT16_C( 20702), INT16_C(   647),
                            INT16_C(-30215), INT16_C( 25412), INT16_C(   851), INT16_C( 30446)),
      simde_mm256_set_epi16(INT16_C(  8605), INT16_C(-24114), INT16_C( -5979), INT16_C( -9101),
                            INT16_C(  6437), INT16_C(-25374), INT16_C( 24146), INT16_C(-14771),
                            INT16_C(-26765), INT16_C( 30576), INT16_C( 25327), INT16_C(  1225),
                            INT16_C(-13633), INT16_C(-15186), INT16_C(-14472), INT16_C( 31809)),
      simde_mm256_set_epi16(INT16_C(-24967), INT16_C( -2049), INT16_C( -2966), INT16_C( 14220),
                            INT16_C( 23847), INT16_C(-27269), INT16_C( 20311), INT16_C( 14895),
                            INT16_C( 25494), INT16_C(-27359), INT16_C( -4625), INT16_C(  -578),
                            INT16_C(-16582), INT16_C(-24938), INT16_C( 15323), INT16_C( -1363)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_sub_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sub_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(  326943318), INT32_C(-1426446841), INT32_C( -705322739), INT32_C( 1382181134),
                            INT32_C( -752013979), INT32_C( 1926838871), INT32_C(-1267474220), INT32_C(-1807600682)),
      simde_mm256_set_epi32(INT32_C(  251701658), INT32_C( 1304570849), INT32_C(-1313346575), INT32_C(  548342496),
                            INT32_C(  350328631), INT32_C(  492623957), INT32_C(  209048435), INT32_C(  494519967)),
      simde_mm256_set_epi32(INT32_C(   75241660), INT32_C( 1563949606), INT32_C(  608023836), INT32_C(  833838638),
                            INT32_C(-1102342610), INT32_C( 1434214914), INT32_C(-1476522655), INT32_C( 1992846647)) },
    { simde_mm256_set_epi32(INT32_C( -933394757), INT32_C( 2044671684), INT32_C(  359818497), INT32_C( 1070534780),
                            INT32_C( -970998086), INT32_C(-1718071453), INT32_C( 1676992968), INT32_C(-1700643811)),
      simde_mm256_set_epi32(INT32_C( 1601497259), INT32_C( -783324799), INT32_C(  230836562), INT32_C( -793897628),
                            INT32_C( 2109010219), INT32_C( -500991481), INT32_C( 1633364343), INT32_C(-1085575788)),
      simde_mm256_set_epi32(INT32_C( 1760075280), INT32_C(-1466970813), INT32_C(  128981935), INT32_C( 1864432408),
                            INT32_C( 1214958991), INT32_C(-1217079972), INT32_C(   43628625), INT32_C( -615068023)) },
    { simde_mm256_set_epi32(INT32_C(  -51216759), INT32_C( -878749548), INT32_C(-1368701232), INT32_C(-2046658418),
                            INT32_C(-1669301170), INT32_C(-2003910541), INT32_C( 1329758066), INT32_C( 1724000039)),
      simde_mm256_set_epi32(INT32_C(-2019361399), INT32_C( 1441882288), INT32_C(-1015852054), INT32_C(-2140601122),
                            INT32_C( 1393090412), INT32_C(  -54787332), INT32_C(  -18616908), INT32_C(-2129018166)),
      simde_mm256_set_epi32(INT32_C( 1968144640), INT32_C( 1974335460), INT32_C( -352849178), INT32_C(   93942704),
                            INT32_C( 1232575714), INT32_C(-1949123209), INT32_C( 1348374974), INT32_C( -441949091)) },
    { simde_mm256_set_epi32(INT32_C( -198091267), INT32_C( -797938117), INT32_C( 1365606315), INT32_C( 1369771544),
                            INT32_C(  454471573), INT32_C(-1496770990), INT32_C(-1504062345), INT32_C(-1729521659)),
      simde_mm256_set_epi32(INT32_C(-1875378957), INT32_C( 1413357347), INT32_C(-2041380610), INT32_C( 1834864782),
                            INT32_C(  265860555), INT32_C(  367864932), INT32_C(-1203083960), INT32_C(  193499515)),
      simde_mm256_set_epi32(INT32_C( 1677287690), INT32_C( 2083671832), INT32_C( -887980371), INT32_C( -465093238),
                            INT32_C(  188611018), INT32_C(-1864635922), INT32_C( -300978385), INT32_C(-1923021174)) },
    { simde_mm256_set_epi32(INT32_C(-1042833230), INT32_C( 1624054732), INT32_C(  234631196), INT32_C(  738820353),
                            INT32_C(-1501237092), INT32_C(-1737761237), INT32_C(-1663334158), INT32_C( -439342149)),
      simde_mm256_set_epi32(INT32_C(  164170961), INT32_C( 1826341689), INT32_C(-1379584328), INT32_C( -883834236),
                            INT32_C( -145065229), INT32_C( 1276456429), INT32_C(  908937179), INT32_C( 1101978337)),
      simde_mm256_set_epi32(INT32_C(-1207004191), INT32_C( -202286957), INT32_C( 1614215524), INT32_C( 1622654589),
                            INT32_C(-1356171863), INT32_C( 1280749630), INT32_C( 1722695959), INT32_C(-1541320486)) },
    { simde_mm256_set_epi32(INT32_C( 1638607685), INT32_C(-2009128326), INT32_C( -563580109), INT32_C( 1319284819),
                            INT32_C(  -21113241), INT32_C( -656216704), INT32_C(  927278729), INT32_C(  414207795)),
      simde_mm256_set_epi32(INT32_C(-1371308348), INT32_C( 1761271665), INT32_C( 1358250649), INT32_C( -906482895),
                            INT32_C(  540611685), INT32_C(  776022210), INT32_C( 1935373704), INT32_C( -317327387)),
      simde_mm256_set_epi32(INT32_C(-1285051263), INT32_C(  524567305), INT32_C(-1921830758), INT32_C(-2069199582),
                            INT32_C( -561724926), INT32_C(-1432238914), INT32_C(-1008094975), INT32_C(  731535182)) },
    { simde_mm256_set_epi32(INT32_C(-2100986650), INT32_C( 1414058950), INT32_C(-1053542475), INT32_C( -736674814),
                            INT32_C(-2096553410), INT32_C(-1369794669), INT32_C(   26060713), INT32_C(-1294950753)),
      simde_mm256_set_epi32(INT32_C( 2012616977), INT32_C( 1553490078), INT32_C(  324319438), INT32_C(-1664423684),
                            INT32_C( 1284704444), INT32_C( 1334884932), INT32_C(-1343260831), INT32_C( -516360618)),
      simde_mm256_set_epi32(INT32_C(  181363669), INT32_C( -139431128), INT32_C(-1377861913), INT32_C(  927748870),
                            INT32_C(  913709442), INT32_C( 1590287695), INT32_C( 1369321544), INT32_C( -778590135)) },
    { simde_mm256_set_epi32(INT32_C(-1942786341), INT32_C(-1691503678), INT32_C(-1765167726), INT32_C( 1858759286),
                            INT32_C(  627375525), INT32_C(-1868274030), INT32_C(   12505540), INT32_C(  986732702)),
      simde_mm256_set_epi32(INT32_C(-1777720655), INT32_C(-2032047915), INT32_C(  -56259521), INT32_C( -952761137),
                            INT32_C(  805966046), INT32_C(  372017673), INT32_C(   20751226), INT32_C( -331388981)),
      simde_mm256_set_epi32(INT32_C( -165065686), INT32_C(  340544237), INT32_C(-1708908205), INT32_C(-1483446873),
                            INT32_C( -178590521), INT32_C( 2054675593), INT32_C(   -8245686), INT32_C( 1318121683)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_sub_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sub_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-2885858146882597019), INT64_C(-3498254024691385676),
                             INT64_C( 7972223233728178657), INT64_C( 6231317733982512179)),
      simde_mm256_set_epi64x(INT64_C( 3826502112888397679), INT64_C(-8682306207824752089),
                             INT64_C( 8218291866756092637), INT64_C(  977663894185762148)),
      simde_mm256_set_epi64x(INT64_C(-6712360259770994698), INT64_C( 5184052183133366413),
                             INT64_C( -246068633027913980), INT64_C( 5253653839796750031)) },
    { simde_mm256_set_epi64x(INT64_C( 7921380973104735890), INT64_C(-5532460099708114375),
                             INT64_C(  865084101794303087), INT64_C(-7356844417578967355)),
      simde_mm256_set_epi64x(INT64_C(-3491207381975027904), INT64_C(-1030678116339367991),
                             INT64_C(-8175524911489530105), INT64_C(  323779015099665520)),
      simde_mm256_set_epi64x(INT64_C(-7034155718629787822), INT64_C(-4501781983368746384),
                             INT64_C( 9040609013283833192), INT64_C(-7680623432678632875)) },
    { simde_mm256_set_epi64x(INT64_C( 4341016735029725119), INT64_C(-4017352277952498418),
                             INT64_C( 7582500189708583283), INT64_C(-5892965129862928683)),
      simde_mm256_set_epi64x(INT64_C(-8237509791976513777), INT64_C( -470554251606780044),
                             INT64_C( 6040143329078659839), INT64_C( -424501583476695872)),
      simde_mm256_set_epi64x(INT64_C(-5868217546703312720), INT64_C(-3546798026345718374),
                             INT64_C( 1542356860629923444), INT64_C(-5468463546386232811)) },
    { simde_mm256_set_epi64x(INT64_C(-7392183468556786070), INT64_C(-6610175517365172355),
                             INT64_C(-3756419626009538740), INT64_C(-9036454621798279072)),
      simde_mm256_set_epi64x(INT64_C( 6035045015129345008), INT64_C( 8791627257213638823),
                             INT64_C(-8556126845609402343), INT64_C( 1314921607038438268)),
      simde_mm256_set_epi64x(INT64_C( 5019515590023420538), INT64_C( 3044941299130740438),
                             INT64_C( 4799707219599863603), INT64_C( 8095367844872834276)) },
    { simde_mm256_set_epi64x(INT64_C( 8174138309950782489), INT64_C(-3595444893239169269),
                             INT64_C(-6261543721635705717), INT64_C(-8089986319993999570)),
      simde_mm256_set_epi64x(INT64_C( 4668020520258365306), INT64_C( 1754255393252662962),
                             INT64_C( 1690801515152582572), INT64_C(-7136424812163547703)),
      simde_mm256_set_epi64x(INT64_C( 3506117789692417183), INT64_C(-5349700286491832231),
                             INT64_C(-7952345236788288289), INT64_C( -953561507830451867)) },
    { simde_mm256_set_epi64x(INT64_C( 6033172137928900790), INT64_C(-5612895834493214657),
                             INT64_C(-8524528714074059580), INT64_C(-3969628664745125304)),
      simde_mm256_set_epi64x(INT64_C( 7126793331936974199), INT64_C( 5665142255281704397),
                             INT64_C( 1602540828580772090), INT64_C( 8387594021483335882)),
      simde_mm256_set_epi64x(INT64_C(-1093621194008073409), INT64_C( 7168705983934632562),
                             INT64_C( 8319674531054719946), INT64_C( 6089521387481090430)) },
    { simde_mm256_set_epi64x(INT64_C( 3903790755083266798), INT64_C(-4529825138752859475),
                             INT64_C( -488451067611140207), INT64_C(  375847149564403603)),
      simde_mm256_set_epi64x(INT64_C(-7317636610137191039), INT64_C(-6404029010026237648),
                             INT64_C( 2684127196708781119), INT64_C(-4695910663442221977)),
      simde_mm256_set_epi64x(INT64_C(-7225316708489093779), INT64_C( 1874203871273378173),
                             INT64_C(-3172578264319921326), INT64_C( 5071757813006625580)) },
    { simde_mm256_set_epi64x(INT64_C( -634520004609695604), INT64_C(-4556943099082170660),
                             INT64_C(  407417976594608885), INT64_C(-2432518353344050945)),
      simde_mm256_set_epi64x(INT64_C( 8351025001768468670), INT64_C(-2893015942465040381),
                             INT64_C(-7482511571570747740), INT64_C( 2790733591573448110)),
      simde_mm256_set_epi64x(INT64_C(-8985545006378164274), INT64_C(-1663927156617130279),
                             INT64_C( 7889929548165356625), INT64_C(-5223251944917499055)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_sub_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xor_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C( 5259297934522696228), INT64_C( -431388325374833226),
                             INT64_C(-9156654280217339654), INT64_C( 3013799969040676174)),
      simde_mm256_set_epi64x(INT64_C(-5610681863545377343), INT64_C(  612481038911101319),
                             INT64_C( 6883094940018615339), INT64_C( 5567527613349466758)),
      simde_mm256_set_epi64x(INT64_C( -369826194426859547), INT64_C( -973728768696970191),
                             INT64_C(-2348436908296831791), INT64_C( 7246573032282466248)) },
    { simde_mm256_set_epi64x(INT64_C( 3972970387578047990), INT64_C(-3229803026080205617),
                             INT64_C(-6416566799554918012), INT64_C( 7243493956554503841)),
      simde_mm256_set_epi64x(INT64_C(-2328069278528400967), INT64_C( -866344990039815627),
                             INT64_C( 5191362241164177707), INT64_C( 6965508020004735797)),
      simde_mm256_set_epi64x(INT64_C(-1687764814515086257), INT64_C( 2366483896335154938),
                             INT64_C(-1227043938297071441), INT64_C(  300751355152891284)) },
    { simde_mm256_set_epi64x(INT64_C(-2206747055975530789), INT64_C( 4273990306427029435),
                             INT64_C(-8066951550635951807), INT64_C(-6928425273442710875)),
      simde_mm256_set_epi64x(INT64_C(-4939687486626430761), INT64_C(-1679871113178117518),
                             INT64_C( -257233978894060261), INT64_C( 3512456176079583747)),
      simde_mm256_set_epi64x(INT64_C( 6490456006491962892), INT64_C(-3170633551353754167),
                             INT64_C( 7809929228804508762), INT64_C(-5807521855463853914)) },
    { simde_mm256_set_epi64x(INT64_C(-8921324304875098515), INT64_C( 7821700200964206339),
                             INT64_C( 2994261353466796408), INT64_C(-3540068018343188204)),
      simde_mm256_set_epi64x(INT64_C( 4294357400656496399), INT64_C( 3626952931332295508),
                             INT64_C(-7673859083891959013), INT64_C( 1757595472193292730)),
      simde_mm256_set_epi64x(INT64_C(-4636023147992241822), INT64_C( 6834710091372766295),
                             INT64_C(-4896194530503130525), INT64_C(-2973751098574872402)) },
    { simde_mm256_set_epi64x(INT64_C( 6035067220796971838), INT64_C(  776715589999365452),
                             INT64_C( 6384421609504908311), INT64_C(-8816267298986390401)),
      simde_mm256_set_epi64x(INT64_C(-5739247744839421985), INT64_C( 4653816358777581262),
                             INT64_C( 1021833051660996174), INT64_C(-2812490060666099514)),
      simde_mm256_set_epi64x(INT64_C(-2046106215006112543), INT64_C( 5355589079452705666),
                             INT64_C( 6247691286445288025), INT64_C( 6727907985691518137)) },
    { simde_mm256_set_epi64x(INT64_C( 8351942705843556286), INT64_C(-6873744911563016812),
                             INT64_C(-3359807879676804643), INT64_C( 8110291315370526762)),
      simde_mm256_set_epi64x(INT64_C( -126725188666547082), INT64_C( 4977977654704902461),
                             INT64_C(-7727661347289141755), INT64_C( 7453179086506187618)),
      simde_mm256_set_epi64x(INT64_C(-8226449520241153080), INT64_C(-1905346832462535511),
                             INT64_C( 5016522326789730264), INT64_C( 1721087647877354312)) },
    { simde_mm256_set_epi64x(INT64_C(-3541650301143541882), INT64_C( 2340510988864802758),
                             INT64_C(-2484352519219712887), INT64_C(-7823366500674586971)),
      simde_mm256_set_epi64x(INT64_C( 8787496485572343767), INT64_C( 5972980855318355117),
                             INT64_C( 1254817555351506981), INT64_C( 3585972827969393388)),
      simde_mm256_set_epi64x(INT64_C(-5248115586102763439), INT64_C( 8259425971222532971),
                             INT64_C(-3679494355159515988), INT64_C(-6724368097479220151)) },
    { simde_mm256_set_epi64x(INT64_C(-8306510049557921760), INT64_C(-3952727854475033325),
                             INT64_C(-2945542500559658351), INT64_C(  937552523927336948)),
      simde_mm256_set_epi64x(INT64_C( 4952101385331357252), INT64_C( 3142376059888144776),
                             INT64_C(-5526391810306106309), INT64_C( 1965153668529504230)),
      simde_mm256_set_epi64x(INT64_C(-4035158306098612636), INT64_C(-2108000641444326245),
                             INT64_C( 7228588967820590762), INT64_C( 1605387943167658002)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_xor_si256(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_srli_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(  732419944), INT32_C(  -77147012), INT32_C(  489295522), INT32_C( -707244875),
                            INT32_C( 1759674836), INT32_C(  934163130), INT32_C( 1804082267), INT32_C(-1601331496)),
      simde_mm256_set_epi32(INT32_C(  849157488), INT32_C( 1818223314), INT32_C( -155475303), INT32_C(-1398665928),
                            INT32_C( 1594244161), INT32_C( -844009252), INT32_C( 1806417213), INT32_C(-2079022073)),
      simde_mm256_set_epi32(INT32_C(    5722030), INT32_C(   32951720), INT32_C(    3822621), INT32_C(   28029081),
                            INT32_C(   13747459), INT32_C(    7298149), INT32_C(   14094392), INT32_C(   21044029)) },
    { simde_mm256_set_epi32(INT32_C(-1876248297), INT32_C(-2075193364), INT32_C(  172214735), INT32_C( 1442116689),
                            INT32_C(-1288626413), INT32_C(  967081158), INT32_C(-1720117739), INT32_C(  578489253)),
      simde_mm256_set_epi32(INT32_C(  428131799), INT32_C( -748788150), INT32_C(-1439171179), INT32_C(-1390423819),
                            INT32_C(-1892283443), INT32_C( 1334337044), INT32_C(-1388554016), INT32_C( -267755914)),
      simde_mm256_set_epi32(INT32_C(   18896242), INT32_C(   17341983), INT32_C(    1345427), INT32_C(   11266536),
                            INT32_C(   23487038), INT32_C(    7555321), INT32_C(   20116012), INT32_C(    4519447)) },
    { simde_mm256_set_epi32(INT32_C( 2139550852), INT32_C( 1705221620), INT32_C( -794518741), INT32_C( 1217473420),
                            INT32_C( -178348948), INT32_C( -348930603), INT32_C( 1243233554), INT32_C(  409162556)),
      simde_mm256_set_epi32(INT32_C(-1403015061), INT32_C( 1726506153), INT32_C(-1594809223), INT32_C( -409985534),
                            INT32_C( 1511772803), INT32_C( 1304778026), INT32_C(  245063900), INT32_C(-1297537554)),
      simde_mm256_set_epi32(INT32_C(   16715241), INT32_C(   13322043), INT32_C(   27347254), INT32_C(    9511511),
                            INT32_C(   32161080), INT32_C(   30828411), INT32_C(    9712762), INT32_C(    3196582)) },
    { simde_mm256_set_epi32(INT32_C( -266647535), INT32_C(-1026471549), INT32_C( 2142406190), INT32_C(  988722559),
                            INT32_C( -185570336), INT32_C(  377523091), INT32_C(   41928420), INT32_C(  778993888)),
      simde_mm256_set_epi32(INT32_C( -589207043), INT32_C( 1553242780), INT32_C(-1285792025), INT32_C( -729017109),
                            INT32_C( 1574494207), INT32_C(  934652742), INT32_C(  140826824), INT32_C(-1967394389)),
      simde_mm256_set_epi32(INT32_C(   31471248), INT32_C(   25535123), INT32_C(   16737548), INT32_C(    7724394),
                            INT32_C(   32104663), INT32_C(    2949399), INT32_C(     327565), INT32_C(    6085889)) },
    { simde_mm256_set_epi32(INT32_C(-1791792894), INT32_C( 1191804972), INT32_C( -126480817), INT32_C( 1125707739),
                            INT32_C( -881879475), INT32_C(  143668756), INT32_C( -526899451), INT32_C( 1691821556)),
      simde_mm256_set_epi32(INT32_C( 1203771433), INT32_C(-1195415594), INT32_C(   39184838), INT32_C( 1288741747),
                            INT32_C(-1347767789), INT32_C( 1099277192), INT32_C( 1193566195), INT32_C( -378044470)),
      simde_mm256_set_epi32(INT32_C(   19556050), INT32_C(    9310976), INT32_C(   32566300), INT32_C(    8794591),
                            INT32_C(   26664748), INT32_C(    1122412), INT32_C(   29438030), INT32_C(   13217355)) },
    { simde_mm256_set_epi32(INT32_C(-2125943644), INT32_C(-1910893035), INT32_C(  262981568), INT32_C( 1406838420),
                            INT32_C( 1188023687), INT32_C( -157711585), INT32_C(-1355034011), INT32_C( 1720639911)),
      simde_mm256_set_epi32(INT32_C(-2060210004), INT32_C( 1988675682), INT32_C(-1866317501), INT32_C(-1240234337),
                            INT32_C(-1832718526), INT32_C(-1229749178), INT32_C(-1445633372), INT32_C(-1964281870)),
      simde_mm256_set_epi32(INT32_C(   16945497), INT32_C(   18625580), INT32_C(    2054543), INT32_C(   10990925),
                            INT32_C(    9281435), INT32_C(   32322310), INT32_C(   22968228), INT32_C(   13442499)) },
    { simde_mm256_set_epi32(INT32_C(-2026359983), INT32_C(  713896046), INT32_C(  968519053), INT32_C( 1906109584),
                            INT32_C(  -45372712), INT32_C( 1799473244), INT32_C( -655893602), INT32_C( 1170033241)),
      simde_mm256_set_epi32(INT32_C( -638177916), INT32_C( 1362453557), INT32_C( -397570420), INT32_C(-1865678794),
                            INT32_C( -397148457), INT32_C( -942451042), INT32_C(  944509801), INT32_C(  -43249903)),
      simde_mm256_set_epi32(INT32_C(   17723494), INT32_C(    5577312), INT32_C(    7566555), INT32_C(   14891481),
                            INT32_C(   33199957), INT32_C(   14058384), INT32_C(   28430263), INT32_C(    9140884)) },
    { simde_mm256_set_epi32(INT32_C(-1081998790), INT32_C(  485579923), INT32_C(-1608658429), INT32_C(-1749625928),
                            INT32_C( -779220060), INT32_C( 1164169772), INT32_C( 1589226288), INT32_C(-1216437245)),
      simde_mm256_set_epi32(INT32_C(  320527694), INT32_C( 1480004810), INT32_C(  343325687), INT32_C(  772720606),
                            INT32_C( 1014221898), INT32_C(-1455936050), INT32_C(-1191095377), INT32_C( 1501993218)),
      simde_mm256_set_epi32(INT32_C(   25101316), INT32_C(    3793593), INT32_C(   20986788), INT32_C(   19885479),
                            INT32_C(   27466775), INT32_C(    9095076), INT32_C(   12415830), INT32_C(   24051016)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_srli_epi32(test_vec[i].a, 7);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_max_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
         { simde_x_mm256_set_epu16(UINT16_C( 46627), UINT16_C( 59720), UINT16_C( 61906), UINT16_C( 11658),
                              UINT16_C( 20044), UINT16_C( 39774), UINT16_C( 13081), UINT16_C( 26580),
                              UINT16_C( 18209), UINT16_C( 20949), UINT16_C( 29177), UINT16_C( 31372),
                              UINT16_C(  2292), UINT16_C(  1480), UINT16_C( 23053), UINT16_C( 14592)),
      simde_x_mm256_set_epu16(UINT16_C( 18663), UINT16_C( 17474), UINT16_C( 64035), UINT16_C( 52566),
                              UINT16_C( 14212), UINT16_C( 10671), UINT16_C( 65410), UINT16_C( 60796),
                              UINT16_C( 54296), UINT16_C( 44956), UINT16_C(  2247), UINT16_C(  1960),
                              UINT16_C( 42291), UINT16_C( 26784), UINT16_C( 22137), UINT16_C( 30865)),
      simde_x_mm256_set_epu16(UINT16_C( 46627), UINT16_C( 59720), UINT16_C( 64035), UINT16_C( 52566),
                              UINT16_C( 20044), UINT16_C( 39774), UINT16_C( 65410), UINT16_C( 60796),
                              UINT16_C( 54296), UINT16_C( 44956), UINT16_C( 29177), UINT16_C( 31372),
                              UINT16_C( 42291), UINT16_C( 26784), UINT16_C( 23053), UINT16_C( 30865)) },
    { simde_x_mm256_set_epu16(UINT16_C( 18263), UINT16_C( 58739), UINT16_C( 63639), UINT16_C( 55084),
                              UINT16_C( 26185), UINT16_C( 41545), UINT16_C( 59964), UINT16_C( 12474),
                              UINT16_C( 53086), UINT16_C( 18094), UINT16_C( 30753), UINT16_C( 29484),
                              UINT16_C( 20722), UINT16_C( 11313), UINT16_C( 13962), UINT16_C( 39972)),
      simde_x_mm256_set_epu16(UINT16_C( 58325), UINT16_C( 58948), UINT16_C( 43545), UINT16_C( 59756),
                              UINT16_C( 12295), UINT16_C( 57147), UINT16_C( 58632), UINT16_C( 46109),
                              UINT16_C( 49795), UINT16_C(  8909), UINT16_C(  2266), UINT16_C( 36324),
                              UINT16_C( 59196), UINT16_C( 64507), UINT16_C(  7734), UINT16_C( 45358)),
      simde_x_mm256_set_epu16(UINT16_C( 58325), UINT16_C( 58948), UINT16_C( 63639), UINT16_C( 59756),
                              UINT16_C( 26185), UINT16_C( 57147), UINT16_C( 59964), UINT16_C( 46109),
                              UINT16_C( 53086), UINT16_C( 18094), UINT16_C( 30753), UINT16_C( 36324),
                              UINT16_C( 59196), UINT16_C( 64507), UINT16_C( 13962), UINT16_C( 45358)) },
    { simde_x_mm256_set_epu16(UINT16_C( 39984), UINT16_C( 47951), UINT16_C( 65190), UINT16_C( 48692),
                              UINT16_C( 48663), UINT16_C( 53744), UINT16_C( 12623), UINT16_C( 35136),
                              UINT16_C(  1353), UINT16_C( 21406), UINT16_C( 10132), UINT16_C( 27940),
                              UINT16_C(  4906), UINT16_C( 10556), UINT16_C( 20269), UINT16_C( 18864)),
      simde_x_mm256_set_epu16(UINT16_C( 52708), UINT16_C( 50460), UINT16_C( 39275), UINT16_C( 31341),
                              UINT16_C( 59248), UINT16_C( 23377), UINT16_C( 29345), UINT16_C( 50829),
                              UINT16_C(  4977), UINT16_C( 15093), UINT16_C( 36151), UINT16_C( 58243),
                              UINT16_C( 16819), UINT16_C( 62076), UINT16_C( 48614), UINT16_C(  2944)),
      simde_x_mm256_set_epu16(UINT16_C( 52708), UINT16_C( 50460), UINT16_C( 65190), UINT16_C( 48692),
                              UINT16_C( 59248), UINT16_C( 53744), UINT16_C( 29345), UINT16_C( 50829),
                              UINT16_C(  4977), UINT16_C( 21406), UINT16_C( 36151), UINT16_C( 58243),
                              UINT16_C( 16819), UINT16_C( 62076), UINT16_C( 48614), UINT16_C( 18864)) },
    { simde_x_mm256_set_epu16(UINT16_C( 14954), UINT16_C( 41703), UINT16_C( 49393), UINT16_C( 33328),
                              UINT16_C( 13198), UINT16_C(  8963), UINT16_C( 20974), UINT16_C( 46796),
                              UINT16_C(  4895), UINT16_C(  2875), UINT16_C( 62027), UINT16_C( 51154),
                              UINT16_C( 19247), UINT16_C( 34899), UINT16_C( 65019), UINT16_C( 60032)),
      simde_x_mm256_set_epu16(UINT16_C( 58187), UINT16_C(  7429), UINT16_C( 29396), UINT16_C( 13821),
                              UINT16_C( 33371), UINT16_C(  1928), UINT16_C( 49379), UINT16_C(   722),
                              UINT16_C( 28382), UINT16_C( 55366), UINT16_C( 43323), UINT16_C( 47667),
                              UINT16_C(  5125), UINT16_C( 60684), UINT16_C( 59616), UINT16_C( 50280)),
      simde_x_mm256_set_epu16(UINT16_C( 58187), UINT16_C( 41703), UINT16_C( 49393), UINT16_C( 33328),
                              UINT16_C( 33371), UINT16_C(  8963), UINT16_C( 49379), UINT16_C( 46796),
                              UINT16_C( 28382), UINT16_C( 55366), UINT16_C( 62027), UINT16_C( 51154),
                              UINT16_C( 19247), UINT16_C( 60684), UINT16_C( 65019), UINT16_C( 60032)) },
    { simde_x_mm256_set_epu16(UINT16_C( 27739), UINT16_C( 29065), UINT16_C( 56947), UINT16_C( 55426),
                              UINT16_C( 46492), UINT16_C( 58959), UINT16_C( 17884), UINT16_C(   106),
                              UINT16_C( 40322), UINT16_C( 13650), UINT16_C( 50675), UINT16_C( 30885),
                              UINT16_C(  7879), UINT16_C(  4114), UINT16_C( 54484), UINT16_C( 15816)),
      simde_x_mm256_set_epu16(UINT16_C( 43597), UINT16_C( 65192), UINT16_C( 43740), UINT16_C( 54700),
                              UINT16_C( 31952), UINT16_C( 20957), UINT16_C( 20261), UINT16_C( 50955),
                              UINT16_C( 37051), UINT16_C( 36093), UINT16_C( 59438), UINT16_C( 28726),
                              UINT16_C(  6886), UINT16_C( 52003), UINT16_C( 19596), UINT16_C( 59577)),
      simde_x_mm256_set_epu16(UINT16_C( 43597), UINT16_C( 65192), UINT16_C( 56947), UINT16_C( 55426),
                              UINT16_C( 46492), UINT16_C( 58959), UINT16_C( 20261), UINT16_C( 50955),
                              UINT16_C( 40322), UINT16_C( 36093), UINT16_C( 59438), UINT16_C( 30885),
                              UINT16_C(  7879), UINT16_C( 52003), UINT16_C( 54484), UINT16_C( 59577)) },
    { simde_x_mm256_set_epu16(UINT16_C( 57657), UINT16_C( 13117), UINT16_C( 60292), UINT16_C( 65452),
                              UINT16_C(   694), UINT16_C( 21975), UINT16_C( 46000), UINT16_C( 22467),
                              UINT16_C( 60775), UINT16_C(  6084), UINT16_C( 52920), UINT16_C( 10893),
                              UINT16_C( 33722), UINT16_C( 16366), UINT16_C(   746), UINT16_C( 51289)),
      simde_x_mm256_set_epu16(UINT16_C( 18878), UINT16_C( 35582), UINT16_C( 34313), UINT16_C( 41553),
                              UINT16_C( 15025), UINT16_C( 13655), UINT16_C( 30842), UINT16_C( 55976),
                              UINT16_C( 55306), UINT16_C(  8486), UINT16_C( 20326), UINT16_C( 56205),
                              UINT16_C(  9516), UINT16_C(  5604), UINT16_C( 41707), UINT16_C( 23844)),
      simde_x_mm256_set_epu16(UINT16_C( 57657), UINT16_C( 35582), UINT16_C( 60292), UINT16_C( 65452),
                              UINT16_C( 15025), UINT16_C( 21975), UINT16_C( 46000), UINT16_C( 55976),
                              UINT16_C( 60775), UINT16_C(  8486), UINT16_C( 52920), UINT16_C( 56205),
                              UINT16_C( 33722), UINT16_C( 16366), UINT16_C( 41707), UINT16_C( 51289)) },
    { simde_x_mm256_set_epu16(UINT16_C( 35061), UINT16_C( 31271), UINT16_C( 44458), UINT16_C( 43999),
                              UINT16_C( 52764), UINT16_C( 24092), UINT16_C( 55278), UINT16_C(  9729),
                              UINT16_C( 30350), UINT16_C( 35228), UINT16_C( 24843), UINT16_C( 46927),
                              UINT16_C( 47959), UINT16_C(  8348), UINT16_C( 39137), UINT16_C( 59054)),
      simde_x_mm256_set_epu16(UINT16_C( 18920), UINT16_C( 22899), UINT16_C(  4131), UINT16_C( 54549),
                              UINT16_C( 33095), UINT16_C( 25760), UINT16_C(  6465), UINT16_C( 12263),
                              UINT16_C( 47803), UINT16_C( 61613), UINT16_C( 51708), UINT16_C( 45746),
                              UINT16_C( 59719), UINT16_C(  2919), UINT16_C( 24086), UINT16_C(  5665)),
      simde_x_mm256_set_epu16(UINT16_C( 35061), UINT16_C( 31271), UINT16_C( 44458), UINT16_C( 54549),
                              UINT16_C( 52764), UINT16_C( 25760), UINT16_C( 55278), UINT16_C( 12263),
                              UINT16_C( 47803), UINT16_C( 61613), UINT16_C( 51708), UINT16_C( 46927),
                              UINT16_C( 59719), UINT16_C(  8348), UINT16_C( 39137), UINT16_C( 59054)) },
    { simde_x_mm256_set_epu16(UINT16_C( 46764), UINT16_C( 51381), UINT16_C( 57954), UINT16_C( 11573),
                              UINT16_C( 40336), UINT16_C( 26367), UINT16_C( 17948), UINT16_C( 58963),
                              UINT16_C( 63320), UINT16_C( 30133), UINT16_C( 13248), UINT16_C(  4541),
                              UINT16_C( 43652), UINT16_C(  3442), UINT16_C(   602), UINT16_C( 59909)),
      simde_x_mm256_set_epu16(UINT16_C( 34844), UINT16_C( 11763), UINT16_C( 21582), UINT16_C( 37103),
                              UINT16_C( 62839), UINT16_C( 48595), UINT16_C( 34664), UINT16_C( 65307),
                              UINT16_C( 42742), UINT16_C(  1820), UINT16_C( 54309), UINT16_C( 55027),
                              UINT16_C( 64764), UINT16_C( 27300), UINT16_C( 20131), UINT16_C( 43537)),
      simde_x_mm256_set_epu16(UINT16_C( 46764), UINT16_C( 51381), UINT16_C( 57954), UINT16_C( 37103),
                              UINT16_C( 62839), UINT16_C( 48595), UINT16_C( 34664), UINT16_C( 65307),
                              UINT16_C( 63320), UINT16_C( 30133), UINT16_C( 54309), UINT16_C( 55027),
                              UINT16_C( 64764), UINT16_C( 27300), UINT16_C( 20131), UINT16_C( 59909)) }

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_max_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}



#endif /* defined(SIMDE_AVX2_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_AVX2_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)
  SIMDE_TESTS_DEFINE_TEST(mm256_add_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_add_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_add_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_add_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_adds_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm256_adds_epu16),

  SIMDE_TESTS_DEFINE_TEST(mm256_alignr_epi8_case0),
  SIMDE_TESTS_DEFINE_TEST(mm256_alignr_epi8_case1),
  SIMDE_TESTS_DEFINE_TEST(mm256_alignr_epi8_case2),
  SIMDE_TESTS_DEFINE_TEST(mm256_alignr_epi8_case3),

  SIMDE_TESTS_DEFINE_TEST(mm256_and_si256),
  SIMDE_TESTS_DEFINE_TEST(mm256_andnot_si256),

  SIMDE_TESTS_DEFINE_TEST(mm256_blendv_epi8),

  SIMDE_TESTS_DEFINE_TEST(mm256_broadcastsi128_si256),

  SIMDE_TESTS_DEFINE_TEST(mm256_cmpeq_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_cmpeq_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_cmpeq_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_cmpeq_epi64),

  SIMDE_TESTS_DEFINE_TEST(mm256_cmpgt_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_cmpgt_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_cmpgt_epi64),

  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepi8_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepi8_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepi8_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepi16_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepi16_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepi32_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepu8_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepu8_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepu8_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepu16_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepu16_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepu32_epi64),


  SIMDE_TESTS_DEFINE_TEST(mm256_extract_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_extract_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_extracti128_si256),

  SIMDE_TESTS_DEFINE_TEST(mm256_max_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_max_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_max_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_max_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm256_max_epu16),

  SIMDE_TESTS_DEFINE_TEST(mm256_min_epu8),

  SIMDE_TESTS_DEFINE_TEST(mm256_movemask_epi8),

  SIMDE_TESTS_DEFINE_TEST(mm256_or_si256),

  SIMDE_TESTS_DEFINE_TEST(mm256_packs_epi32),

  SIMDE_TESTS_DEFINE_TEST(mm256_permute4x64_epi64),

  SIMDE_TESTS_DEFINE_TEST(mm256_shuffle_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_shuffle_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_shufflelo_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_shuffle_epi8),

  SIMDE_TESTS_DEFINE_TEST(mm256_slli_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_slli_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_slli_epi64),

  SIMDE_TESTS_DEFINE_TEST(mm256_sub_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_sub_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_sub_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_sub_epi64),

  SIMDE_TESTS_DEFINE_TEST(mm256_srli_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_srli_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_srli_si256),
  SIMDE_TESTS_DEFINE_TEST(mm256_srli_epi64),

  SIMDE_TESTS_DEFINE_TEST(mm256_xor_si256),
#endif /* defined(SIMDE_AVX2_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

HEDLEY_C_DECL MunitSuite* SIMDE_TESTS_GENERATE_SYMBOL(suite)(void) {
  static MunitSuite suite = { (char*) "/" HEDLEY_STRINGIFY(SIMDE_TESTS_CURRENT_ISAX), test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return &suite;
}

#if defined(SIMDE_TESTS_SINGLE_ISAX)
int main(int argc, char* argv[HEDLEY_ARRAY_PARAM(argc + 1)]) {
  static MunitSuite suite = { "", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return munit_suite_main(&suite, NULL, argc, argv);
}
#endif /* defined(SIMDE_TESTS_SINGLE_ISAX) */

HEDLEY_DIAGNOSTIC_POP

/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * toc.c
 *
 * Code generation for function 'toc'
 *
 */

/* Include files */
#include "toc.h"
#include "optimize_cpp_data.h"
#include "optimize_cpp_mexutil.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"
#include "emlrt.h"
#include <stdio.h>
#include <string.h>

/* Variable Definitions */
static emlrtMCInfo b_emlrtMCI = { 64,  /* lineNo */
  18,                                  /* colNo */
  "fprintf",                           /* fName */
  "/usr/local/MATLAB/R2020b/toolbox/eml/lib/matlab/iofun/fprintf.m"/* pName */
};

/* Function Declarations */
static const mxArray *feval(const mxArray *b, const mxArray *c, const mxArray *d,
  const mxArray *e, emlrtMCInfo *location);

/* Function Definitions */
static const mxArray *feval(const mxArray *b, const mxArray *c, const mxArray *d,
  const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m, 4, pArrays, "feval",
    true, location);
}

void toc(void)
{
  static const int32_T iv[2] = { 1, 7 };

  static const int32_T iv1[2] = { 1, 28 };

  static const char_T b_u[28] = { 'E', 'l', 'a', 'p', 's', 'e', 'd', ' ', 't',
    'i', 'm', 'e', ' ', 'i', 's', ' ', '%', 'f', ' ', 's', 'e', 'c', 'o', 'n',
    'd', 's', '\\', 'n' };

  static const char_T u[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  emlrtTimespec tnow;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  real_T tstart_tv_nsec;
  real_T tstart_tv_sec;
  b_timeKeeper(&tstart_tv_sec, &tstart_tv_nsec);
  emlrtClockGettimeMonotonic(&tnow);
  y = NULL;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = NULL;
  m = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m);
  c_y = NULL;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 28, m, &b_u[0]);
  emlrtAssign(&c_y, m);
  d_y = NULL;
  m = emlrtCreateDoubleScalar((tnow.tv_sec - tstart_tv_sec) + (tnow.tv_nsec -
    tstart_tv_nsec) / 1.0E+9);
  emlrtAssign(&d_y, m);
  emlrt_marshallIn(feval(y, b_y, c_y, d_y, &b_emlrtMCI), "<output of feval>");
}

/* End of code generation (toc.c) */

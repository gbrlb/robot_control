/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * optimize_cpp_mpc.c
 *
 * Code generation for function 'optimize_cpp_mpc'
 *
 */

/* Include files */
#include "optimize_cpp_mpc.h"
#include "compressBounds.h"
#include "computeForwardDifferences.h"
#include "driver.h"
#include "factoryConstruct.h"
#include "factoryConstruct1.h"
#include "factoryConstruct2.h"
#include "integrate_dynamics.h"
#include "optimize_cpp_mpc_data.h"
#include "optimize_cpp_mpc_emxutil.h"
#include "optimize_cpp_mpc_internal_types.h"
#include "optimize_cpp_mpc_types.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "xcopy.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 11,  /* lineNo */
  9,                                   /* colNo */
  "cost_mpc",                          /* fName */
  "/home/mfocchi/Dropbox/RESEARCH/climbingrobotnotes/matlab/2ropes/optimal_control_2ropes/mpc/cost_mpc.m"/* pName */
};

static emlrtMCInfo emlrtMCI = { 10,    /* lineNo */
  9,                                   /* colNo */
  "cost_mpc",                          /* fName */
  "/home/mfocchi/Dropbox/RESEARCH/climbingrobotnotes/matlab/2ropes/optimal_control_2ropes/mpc/cost_mpc.m"/* pName */
};

static emlrtMCInfo b_emlrtMCI = { 9,   /* lineNo */
  9,                                   /* colNo */
  "eval_pos_vel_mpc",                  /* fName */
  "/home/mfocchi/Dropbox/RESEARCH/climbingrobotnotes/matlab/2ropes/optimal_control_2ropes/mpc/eval_pos_vel_mpc.m"/* pName */
};

static emlrtMCInfo c_emlrtMCI = { 33,  /* lineNo */
  13,                                  /* colNo */
  "integrate_dynamics",                /* fName */
  "/home/mfocchi/Dropbox/RESEARCH/climbingrobotnotes/matlab/2ropes/optimal_control_2ropes/integrate_dynamics.m"/* pName */
};

/* Function Declarations */
static void disp(const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */
static void disp(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "disp", true,
                        location);
}

real_T anon(const real_T actual_state[6], const emxArray_real_T *ref_com, const
            emxArray_real_T *Fr_l0, const emxArray_real_T *Fr_r0, int64_T mpc_N,
            const char_T params_int_method[3], real_T params_int_steps, real_T
            params_b, const real_T params_p_a1[3], const real_T params_p_a2[3],
            real_T params_g, real_T params_m, real_T params_w1, real_T
            params_mpc_dt, const emxArray_real_T *x)
{
  static const int32_T iv[2] = { 1, 72 };

  static const int32_T iv2[2] = { 1, 66 };

  static const int32_T iv3[2] = { 1, 15 };

  static const int32_T iv4[2] = { 1, 15 };

  static const char_T u[72] = { 'c', 'o', 's', 't', '_', 'm', 'p', 'c', ':', 'w',
    'r', 'o', 'n', 'g', ' ', 'r', 'e', 'f', '_', 'c', 'o', 'm', ' ', 'i', 'n',
    'p', 'u', 't', ' ', 'l', 'e', 'n', 'g', 't', 'h', ':', ' ', 'r', 'e', 'f',
    '_', 'c', 'o', 'm', ' ', 's', 'h', 'o', 'u', 'l', 'd', ' ', 'b', 'e', ' ',
    'l', 'o', 'n', 'g', 'e', 'r', ' ', 't', 'h', 'a', 'n', ' ', 'm', 'p', 'c',
    '_', 'N' };

  static const char_T b_u[66] = { 'e', 'v', 'a', 'l', '_', 'p', 'o', 's', '_',
    'm', 'p', 'c', ':', 'w', 'r', 'o', 'n', 'g', ' ', 'i', 'n', 'p', 'u', 't',
    ' ', 'l', 'e', 'n', 'g', 't', 'h', ':', ' ', 'i', 'n', 'p', 'u', 't', ' ',
    's', 'h', 'o', 'u', 'l', 'd', ' ', 'b', 'e', ' ', 'l', 'o', 'n', 'g', 'e',
    'r', ' ', 't', 'h', 'a', 'n', ' ', 'm', 'p', 'c', '_', 'N' };

  static const char_T c_u[15] = { 'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'm',
    'e', 't', 'h', 'o', 'd', '.' };

  static const char_T b[3] = { 'r', 'k', '4' };

  emxArray_real_T *b_p;
  emxArray_real_T *b_states_rough;
  emxArray_real_T *b_x;
  emxArray_real_T *pdx;
  emxArray_real_T *pdy;
  emxArray_real_T *px;
  emxArray_real_T *py;
  emxArray_real_T *states_rough;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *y;
  int64_T i;
  real_T b_unusedU0[6];
  real_T dv[6];
  real_T k_1[6];
  real_T k_2[6];
  real_T k_3[6];
  real_T unusedU0[6];
  real_T a_tmp;
  real_T b_px;
  real_T d;
  real_T d1;
  real_T dt_step;
  real_T scale;
  real_T t;
  real_T varargout_1;
  real_T *pData;
  int32_T iv1[2];
  int32_T j;
  int32_T k;
  int32_T kend;
  int32_T ncols;
  int32_T nx;
  boolean_T guard1 = false;
  boolean_T p;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);

  /*  init for cpp */
  varargout_1 = 0.0;
  if (ref_com->size[1] == 0) {
    nx = 0;
  } else {
    nx = muIntScalarMax_sint32(3, ref_com->size[1]);
  }

  p = false;
  if (mpc_N >= 4503599627370496L) {
    p = true;
  } else {
    if (mpc_N > -4503599627370496L) {
      p = ((real_T)nx < mpc_N);
    }
  }

  if (p) {
    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 72, m, &u[0]);
    emlrtAssign(&y, m);
    disp(y, &emlrtMCI);
    b_y = NULL;
    iv1[0] = ref_com->size[0];
    iv1[1] = ref_com->size[1];
    m = emlrtCreateNumericArray(2, &iv1[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    k = 0;
    for (nx = 0; nx < ref_com->size[1]; nx++) {
      pData[k] = ref_com->data[3 * nx];
      k++;
      pData[k] = ref_com->data[3 * nx + 1];
      k++;
      pData[k] = ref_com->data[3 * nx + 2];
      k++;
    }

    emlrtAssign(&b_y, m);
    emlrtDisplayR2012b(b_y, "ref_com", &emlrtRTEI, emlrtRootTLSGlobal);
  } else {
    if (mpc_N + 1L > (mpc_N << 1)) {
      k = 0;
    } else {
      k = (int32_T)(mpc_N + 1L) - 1;
    }

    /*  compute actual state */
    if (1L > mpc_N) {
      ncols = 0;
    } else {
      ncols = (int32_T)mpc_N;
    }

    emxInit_real_T(&b_p, 2, true);

    /* init values for cpp */
    j = b_p->size[0] * b_p->size[1];
    b_p->size[0] = 3;
    b_p->size[1] = (int32_T)mpc_N;
    emxEnsureCapacity_real_T(b_p, j);
    kend = 3 * (int32_T)mpc_N;
    for (j = 0; j < kend; j++) {
      b_p->data[j] = 0.0;
    }

    emxInit_real_T(&states_rough, 2, true);
    emxInit_real_T(&px, 2, true);
    emxInit_real_T(&py, 2, true);
    emxInit_real_T(&pdx, 2, true);
    emxInit_real_T(&pdy, 2, true);
    emxInit_real_T(&b_states_rough, 2, true);
    nx = Fr_l0->size[1];
    p = false;
    if (mpc_N >= 4503599627370496L) {
      p = true;
    } else {
      if (mpc_N > -4503599627370496L) {
        p = ((real_T)nx < mpc_N);
      }
    }

    guard1 = false;
    if (p) {
      guard1 = true;
    } else {
      nx = Fr_r0->size[1];
      p = false;
      if (mpc_N >= 4503599627370496L) {
        p = true;
      } else {
        if (mpc_N > -4503599627370496L) {
          p = ((real_T)nx < mpc_N);
        }
      }

      if (p) {
        guard1 = true;
      } else {
        /*  check vectors are row and extract first mpc_N elements */
        if (1L > mpc_N) {
          kend = 0;
          nx = 0;
        } else {
          kend = (int32_T)mpc_N;
          nx = (int32_T)mpc_N;
        }

        /*  single shooting */
        j = px->size[0] * px->size[1];
        px->size[0] = 1;
        px->size[1] = kend;
        emxEnsureCapacity_real_T(px, j);
        for (j = 0; j < kend; j++) {
          px->data[j] = Fr_l0->data[j] + x->data[j];
        }

        j = py->size[0] * py->size[1];
        py->size[0] = 1;
        py->size[1] = nx;
        emxEnsureCapacity_real_T(py, j);
        for (j = 0; j < nx; j++) {
          py->data[j] = Fr_r0->data[j] + x->data[k + j];
        }

        /* init */
        k = states_rough->size[0] * states_rough->size[1];
        states_rough->size[0] = 6;
        states_rough->size[1] = (int32_T)mpc_N;
        emxEnsureCapacity_real_T(states_rough, k);
        kend = 6 * (int32_T)mpc_N;
        for (k = 0; k < kend; k++) {
          states_rough->data[k] = 0.0;
        }

        if (params_int_steps == 0.0) {
          /* verify is a column vector */
          k = states_rough->size[0] * states_rough->size[1];
          states_rough->size[0] = 6;
          states_rough->size[1] = 1;
          emxEnsureCapacity_real_T(states_rough, k);
          for (nx = 0; nx < 6; nx++) {
            d = actual_state[nx];
            unusedU0[nx] = d;
            states_rough->data[nx] = d;
          }

          if (memcmp(&params_int_method[0], &b[0], 3) == 0) {
            /* https://www.geeksforgeeks.org/runge-kutta-4th-order-method-solve-differential-equation/ */
            /*  we have  time invariant dynamics so t wont count */
            i = 1L;
            while (i <= mpc_N - 1L) {
              b_px = px->data[(int32_T)i - 1];
              scale = py->data[(int32_T)i - 1];
              b_anon(params_b, params_p_a1, params_p_a2, params_g, params_m,
                     unusedU0, b_px, scale, k_1);
              a_tmp = 0.5 * params_mpc_dt;
              for (k = 0; k < 6; k++) {
                b_unusedU0[k] = unusedU0[k] + a_tmp * k_1[k];
              }

              b_anon(params_b, params_p_a1, params_p_a2, params_g, params_m,
                     b_unusedU0, b_px, scale, k_2);
              for (k = 0; k < 6; k++) {
                b_unusedU0[k] = unusedU0[k] + a_tmp * k_2[k];
              }

              b_anon(params_b, params_p_a1, params_p_a2, params_g, params_m,
                     b_unusedU0, b_px, scale, k_3);
              for (k = 0; k < 6; k++) {
                b_unusedU0[k] = unusedU0[k] + k_3[k] * params_mpc_dt;
              }

              b_anon(params_b, params_p_a1, params_p_a2, params_g, params_m,
                     b_unusedU0, b_px, scale, dv);
              for (k = 0; k < 6; k++) {
                unusedU0[k] += 0.16666666666666666 * (((k_1[k] + 2.0 * k_2[k]) +
                  2.0 * k_3[k]) + dv[k]) * params_mpc_dt;
              }

              k = b_states_rough->size[0] * b_states_rough->size[1];
              b_states_rough->size[0] = 6;
              b_states_rough->size[1] = states_rough->size[1] + 1;
              emxEnsureCapacity_real_T(b_states_rough, k);
              kend = states_rough->size[1];
              for (k = 0; k < kend; k++) {
                for (j = 0; j < 6; j++) {
                  nx = j + 6 * k;
                  b_states_rough->data[nx] = states_rough->data[nx];
                }
              }

              for (k = 0; k < 6; k++) {
                b_states_rough->data[k + 6 * states_rough->size[1]] = unusedU0[k];
              }

              k = states_rough->size[0] * states_rough->size[1];
              states_rough->size[0] = 6;
              states_rough->size[1] = b_states_rough->size[1];
              emxEnsureCapacity_real_T(states_rough, k);
              kend = b_states_rough->size[0] * b_states_rough->size[1];
              for (k = 0; k < kend; k++) {
                states_rough->data[k] = b_states_rough->data[k];
              }

              i++;
              if (*emlrtBreakCheckR2012bFlagVar != 0) {
                emlrtBreakCheckR2012b(emlrtRootTLSGlobal);
              }
            }
          } else {
            d_y = NULL;
            m = emlrtCreateCharArray(2, &iv3[0]);
            emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 15, m, &c_u[0]);
            emlrtAssign(&d_y, m);
            disp(d_y, &c_emlrtMCI);
          }
        } else {
          dt_step = params_mpc_dt / (params_int_steps - 1.0);
          i = 1L;
          while (i <= mpc_N) {
            if (i >= 2L) {
              k = pdx->size[0] * pdx->size[1];
              pdx->size[0] = 1;
              pdx->size[1] = (int32_T)params_int_steps;
              emxEnsureCapacity_real_T(pdx, k);
              b_px = px->data[(int32_T)(i - 1L) - 1];
              kend = (int32_T)params_int_steps;
              k = pdy->size[0] * pdy->size[1];
              pdy->size[0] = 1;
              pdy->size[1] = (int32_T)params_int_steps;
              emxEnsureCapacity_real_T(pdy, k);
              scale = py->data[(int32_T)(i - 1L) - 1];
              for (k = 0; k < kend; k++) {
                pdx->data[k] = b_px;
                pdy->data[k] = scale;
              }

              for (k = 0; k < 6; k++) {
                dv[k] = states_rough->data[k + 6 * ((int32_T)(i - 1L) - 1)];
              }

              /* verify is a column vector */
              if (memcmp(&params_int_method[0], &b[0], 3) == 0) {
                /* https://www.geeksforgeeks.org/runge-kutta-4th-order-method-solve-differential-equation/ */
                /*  we have  time invariant dynamics so t wont count */
                k = (int32_T)(params_int_steps - 1.0);
                for (nx = 0; nx < k; nx++) {
                  d = pdx->data[nx];
                  d1 = pdy->data[nx];
                  b_anon(params_b, params_p_a1, params_p_a2, params_g, params_m,
                         dv, d, d1, k_1);
                  a_tmp = 0.5 * dt_step;
                  for (j = 0; j < 6; j++) {
                    b_unusedU0[j] = dv[j] + a_tmp * k_1[j];
                  }

                  b_anon(params_b, params_p_a1, params_p_a2, params_g, params_m,
                         b_unusedU0, d, d1, k_2);
                  for (j = 0; j < 6; j++) {
                    b_unusedU0[j] = dv[j] + a_tmp * k_2[j];
                  }

                  b_anon(params_b, params_p_a1, params_p_a2, params_g, params_m,
                         b_unusedU0, d, d1, k_3);
                  for (j = 0; j < 6; j++) {
                    b_unusedU0[j] = dv[j] + k_3[j] * dt_step;
                  }

                  b_anon(params_b, params_p_a1, params_p_a2, params_g, params_m,
                         b_unusedU0, d, d1, unusedU0);
                  for (j = 0; j < 6; j++) {
                    dv[j] += 0.16666666666666666 * (((k_1[j] + 2.0 * k_2[j]) +
                      2.0 * k_3[j]) + unusedU0[j]) * dt_step;
                  }

                  if (*emlrtBreakCheckR2012bFlagVar != 0) {
                    emlrtBreakCheckR2012b(emlrtRootTLSGlobal);
                  }
                }
              } else {
                e_y = NULL;
                m = emlrtCreateCharArray(2, &iv4[0]);
                emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 15, m, &c_u[0]);
                emlrtAssign(&e_y, m);
                disp(e_y, &c_emlrtMCI);
              }

              for (k = 0; k < 6; k++) {
                states_rough->data[k + 6 * ((int32_T)i - 1)] = dv[k];
              }

              /*  keep Fr constant            */
            } else {
              for (k = 0; k < 6; k++) {
                states_rough->data[k + 6 * ((int32_T)i - 1)] = actual_state[k];
              }
            }

            i++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(emlrtRootTLSGlobal);
            }
          }
        }

        kend = states_rough->size[1];
        k = px->size[0] * px->size[1];
        px->size[0] = 1;
        px->size[1] = states_rough->size[1];
        emxEnsureCapacity_real_T(px, k);
        for (k = 0; k < kend; k++) {
          px->data[k] = 0.0;
        }

        kend = states_rough->size[1];
        k = py->size[0] * py->size[1];
        py->size[0] = 1;
        py->size[1] = states_rough->size[1];
        emxEnsureCapacity_real_T(py, k);
        for (k = 0; k < kend; k++) {
          py->data[k] = 0.0;
        }

        kend = states_rough->size[1];
        k = pdx->size[0] * pdx->size[1];
        pdx->size[0] = 1;
        pdx->size[1] = states_rough->size[1];
        emxEnsureCapacity_real_T(pdx, k);
        for (k = 0; k < kend; k++) {
          pdx->data[k] = 0.0;
        }

        k = states_rough->size[1] - 1;
        for (nx = 0; nx <= k; nx++) {
          d = states_rough->data[6 * nx];
          d1 = states_rough->data[6 * nx + 1];
          b_px = states_rough->data[6 * nx + 2];
          scale = params_b * params_b;
          t = d1 * d1;
          a_tmp = (scale + t) - b_px * b_px;
          b_px = muDoubleScalarSqrt(1.0 - a_tmp * a_tmp / (4.0 * scale * t));
          px->data[nx] = d1 * muDoubleScalarSin(d) * b_px;
          py->data[nx] = a_tmp / (2.0 * params_b);
          pdx->data[nx] = -d1 * muDoubleScalarCos(d) * b_px;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(emlrtRootTLSGlobal);
          }
        }

        k = b_p->size[0] * b_p->size[1];
        b_p->size[0] = 3;
        b_p->size[1] = px->size[1];
        emxEnsureCapacity_real_T(b_p, k);
        kend = px->size[1];
        for (k = 0; k < kend; k++) {
          b_p->data[3 * k] = px->data[k];
        }

        kend = py->size[1];
        for (k = 0; k < kend; k++) {
          b_p->data[3 * k + 1] = py->data[k];
        }

        kend = pdx->size[1];
        for (k = 0; k < kend; k++) {
          b_p->data[3 * k + 2] = pdx->data[k];
        }
      }
    }

    if (guard1) {
      c_y = NULL;
      m = emlrtCreateCharArray(2, &iv2[0]);
      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 66, m, &b_u[0]);
      emlrtAssign(&c_y, m);
      disp(c_y, &b_emlrtMCI);
    }

    emxFree_real_T(&b_states_rough);
    emxFree_real_T(&py);
    emxFree_real_T(&px);
    emxFree_real_T(&states_rough);
    emxInit_real_T(&b_x, 2, true);

    /* p has mpc_N +1 elements  */
    /*  cartesian track */
    k = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 3;
    b_x->size[1] = ncols;
    emxEnsureCapacity_real_T(b_x, k);
    for (nx = 0; nx < ncols; nx++) {
      b_x->data[3 * nx] = ref_com->data[3 * nx] - b_p->data[3 * nx];
      k = 3 * nx + 1;
      b_x->data[k] = ref_com->data[3 * nx + 1] - b_p->data[k];
      k = 3 * nx + 2;
      b_x->data[k] = ref_com->data[3 * nx + 2] - b_p->data[k];
    }

    emxFree_real_T(&b_p);
    ncols = b_x->size[1];
    k = pdx->size[0] * pdx->size[1];
    pdx->size[0] = 1;
    pdx->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(pdx, k);
    for (j = 0; j < ncols; j++) {
      nx = j * 3;
      b_px = 0.0;
      scale = 3.3121686421112381E-170;
      kend = nx + 3;
      for (k = nx + 1; k <= kend; k++) {
        dt_step = muDoubleScalarAbs(b_x->data[k - 1]);
        if (dt_step > scale) {
          t = scale / dt_step;
          b_px = b_px * t * t + 1.0;
          scale = dt_step;
        } else {
          t = dt_step / scale;
          b_px += t * t;
        }
      }

      pdx->data[j] = scale * muDoubleScalarSqrt(b_px);
    }

    emxFree_real_T(&b_x);

    /*  %state tracking (is worse than cart tracking) */
    /*  tracking_state = 0.; */
    /*  for i=1:mpc_N */
    /*      state_ref = computeStateFromCartesian(params, ref_com_mpc(:,i)); */
    /*      state = computeStateFromCartesian(params, p(:,i)); */
    /*      tracking_state = tracking_state + norm(state_ref(2:3) -state(2:3));%consider only l1 l2 */
    /*  end */
    /*  smoothnes: minimize jerky control action */
    k = pdy->size[0] * pdy->size[1];
    pdy->size[0] = 1;
    pdy->size[1] = pdx->size[1];
    emxEnsureCapacity_real_T(pdy, k);
    nx = pdx->size[1];
    for (k = 0; k < nx; k++) {
      d = pdx->data[k];
      pdy->data[k] = d * d;
    }

    emxFree_real_T(&pdx);
    nx = pdy->size[1];
    if (pdy->size[1] == 0) {
      b_px = 0.0;
    } else {
      b_px = pdy->data[0];
      for (k = 2; k <= nx; k++) {
        b_px += pdy->data[k - 1];
      }
    }

    emxFree_real_T(&pdy);
    varargout_1 = params_w1 * b_px;

    /*  + w2 *smooth ; */
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return varargout_1;
}

void optimize_cpp_mpc(const real_T actual_state[6], real_T actual_t, const
                      emxArray_real_T *ref_com, const emxArray_real_T *Fr_l0,
                      const emxArray_real_T *Fr_r0, real_T Fr_max, int64_T mpc_N,
                      const param *params, emxArray_real_T *x, real_T *EXITFLAG,
                      real_T *final_cost)
{
  c_struct_T memspace;
  d_struct_T TrialState;
  e_struct_T FcnEvaluator;
  emxArray_int32_T *indexFixed;
  emxArray_int32_T *indexLB;
  emxArray_int32_T *indexUB;
  emxArray_real_T *Hessian;
  emxArray_real_T *lb;
  emxArray_real_T *ub;
  emxArray_real_T *x0;
  f_struct_T FiniteDifferences;
  g_struct_T QRManager;
  h_struct_T CholManager;
  i_struct_T QPObjective;
  j_struct_T WorkingSet;
  k_struct_T MeritFunction;
  real_T d;
  real_T fval;
  int32_T b_i;
  int32_T i;
  int32_T mConstrMax;
  int32_T mLB;
  int32_T mUB;
  int32_T maxDims;
  int32_T nVar;
  int32_T nVarMax;
  boolean_T hasLB;
  boolean_T hasUB;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&x0, 2, true);
  i = x0->size[0] * x0->size[1];
  x0->size[0] = 1;
  nVar = (int32_T)mpc_N + (int32_T)mpc_N;
  x0->size[1] = nVar;
  emxEnsureCapacity_real_T(x0, i);
  nVarMax = (int32_T)mpc_N;
  for (i = 0; i < nVarMax; i++) {
    x0->data[i] = 0.0;
  }

  nVarMax = (int32_T)mpc_N;
  for (i = 0; i < nVarMax; i++) {
    x0->data[i + (int32_T)mpc_N] = 0.0;
  }

  emxInit_real_T(&lb, 2, true);

  /* opt vars=   Flegx Flegy Flexz Tf  traj_Fr_l traj_Fr_r */
  i = lb->size[0] * lb->size[1];
  lb->size[0] = 1;
  lb->size[1] = nVar;
  emxEnsureCapacity_real_T(lb, i);
  nVarMax = (int32_T)mpc_N;
  for (i = 0; i < nVarMax; i++) {
    lb->data[i] = -Fr_max;
  }

  nVarMax = (int32_T)mpc_N;
  for (i = 0; i < nVarMax; i++) {
    lb->data[i + (int32_T)mpc_N] = -Fr_max;
  }

  emxInit_real_T(&ub, 2, true);
  i = ub->size[0] * ub->size[1];
  ub->size[0] = 1;
  ub->size[1] = nVar;
  emxEnsureCapacity_real_T(ub, i);
  nVarMax = (int32_T)mpc_N;
  for (i = 0; i < nVarMax; i++) {
    ub->data[i] = Fr_max;
  }

  nVarMax = (int32_T)mpc_N;
  for (i = 0; i < nVarMax; i++) {
    ub->data[i + (int32_T)mpc_N] = Fr_max;
  }

  emxInit_real_T(&Hessian, 2, true);

  /*  % does not always satisfy bounds */
  /* optim (comment this for sanity check test)  */
  mLB = lb->size[1];
  mUB = ub->size[1];
  nVar = x0->size[1];
  mConstrMax = (lb->size[1] + ub->size[1]) + 1;
  nVarMax = x0->size[1] + 1;
  maxDims = muIntScalarMax_sint32(nVarMax, mConstrMax);
  i = Hessian->size[0] * Hessian->size[1];
  Hessian->size[0] = x0->size[1];
  Hessian->size[1] = x0->size[1];
  emxEnsureCapacity_real_T(Hessian, i);
  nVarMax = x0->size[1] * x0->size[1];
  for (i = 0; i < nVarMax; i++) {
    Hessian->data[i] = 0.0;
  }

  if (x0->size[1] > 0) {
    for (nVarMax = 0; nVarMax < nVar; nVarMax++) {
      Hessian->data[nVarMax + Hessian->size[0] * nVarMax] = 1.0;
    }
  }

  emxInitStruct_struct_T(&TrialState, true);
  emxInitStruct_struct_T1(&FcnEvaluator, true);
  factoryConstruct(x0->size[1] + 1, mConstrMax, x0, &TrialState);
  xcopy(x0->size[1], x0, TrialState.xstarsqp);
  FcnEvaluator.nVar = x0->size[1];
  for (b_i = 0; b_i < 6; b_i++) {
    FcnEvaluator.objfun.tunableEnvironment.f1[b_i] = actual_state[b_i];
  }

  FcnEvaluator.objfun.tunableEnvironment.f2 = actual_t;
  i = FcnEvaluator.objfun.tunableEnvironment.f3->size[0] *
    FcnEvaluator.objfun.tunableEnvironment.f3->size[1];
  FcnEvaluator.objfun.tunableEnvironment.f3->size[0] = 3;
  FcnEvaluator.objfun.tunableEnvironment.f3->size[1] = ref_com->size[1];
  emxEnsureCapacity_real_T(FcnEvaluator.objfun.tunableEnvironment.f3, i);
  nVarMax = ref_com->size[0] * ref_com->size[1];
  for (i = 0; i < nVarMax; i++) {
    FcnEvaluator.objfun.tunableEnvironment.f3->data[i] = ref_com->data[i];
  }

  i = FcnEvaluator.objfun.tunableEnvironment.f4->size[0] *
    FcnEvaluator.objfun.tunableEnvironment.f4->size[1];
  FcnEvaluator.objfun.tunableEnvironment.f4->size[0] = 1;
  FcnEvaluator.objfun.tunableEnvironment.f4->size[1] = Fr_l0->size[1];
  emxEnsureCapacity_real_T(FcnEvaluator.objfun.tunableEnvironment.f4, i);
  nVarMax = Fr_l0->size[0] * Fr_l0->size[1];
  for (i = 0; i < nVarMax; i++) {
    FcnEvaluator.objfun.tunableEnvironment.f4->data[i] = Fr_l0->data[i];
  }

  i = FcnEvaluator.objfun.tunableEnvironment.f5->size[0] *
    FcnEvaluator.objfun.tunableEnvironment.f5->size[1];
  FcnEvaluator.objfun.tunableEnvironment.f5->size[0] = 1;
  FcnEvaluator.objfun.tunableEnvironment.f5->size[1] = Fr_r0->size[1];
  emxEnsureCapacity_real_T(FcnEvaluator.objfun.tunableEnvironment.f5, i);
  nVarMax = Fr_r0->size[0] * Fr_r0->size[1];
  for (i = 0; i < nVarMax; i++) {
    FcnEvaluator.objfun.tunableEnvironment.f5->data[i] = Fr_r0->data[i];
  }

  emxInitStruct_struct_T2(&FiniteDifferences, true);
  emxInitStruct_struct_T3(&QRManager, true);
  FcnEvaluator.objfun.tunableEnvironment.f6 = mpc_N;
  FcnEvaluator.objfun.tunableEnvironment.f7 = *params;
  FcnEvaluator.mCineq = 0;
  FcnEvaluator.mCeq = 0;
  FcnEvaluator.NonFiniteSupport = true;
  FcnEvaluator.SpecifyObjectiveGradient = false;
  FcnEvaluator.SpecifyConstraintGradient = false;
  FcnEvaluator.ScaleProblem = false;
  b_factoryConstruct(actual_state, actual_t, ref_com, Fr_l0, Fr_r0, mpc_N,
                     params, x0->size[1], lb, ub, &FiniteDifferences);
  QRManager.ldq = maxDims;
  i = QRManager.QR->size[0] * QRManager.QR->size[1];
  QRManager.QR->size[0] = maxDims;
  QRManager.QR->size[1] = maxDims;
  emxEnsureCapacity_real_T(QRManager.QR, i);
  i = QRManager.Q->size[0] * QRManager.Q->size[1];
  QRManager.Q->size[0] = maxDims;
  QRManager.Q->size[1] = maxDims;
  emxEnsureCapacity_real_T(QRManager.Q, i);
  nVarMax = maxDims * maxDims;
  for (i = 0; i < nVarMax; i++) {
    QRManager.Q->data[i] = 0.0;
  }

  i = QRManager.jpvt->size[0];
  QRManager.jpvt->size[0] = maxDims;
  emxEnsureCapacity_int32_T(QRManager.jpvt, i);
  for (i = 0; i < maxDims; i++) {
    QRManager.jpvt->data[i] = 0;
  }

  emxInitStruct_struct_T4(&CholManager, true);
  emxInitStruct_struct_T5(&QPObjective, true);
  emxInitStruct_struct_T6(&memspace, true);
  emxInit_int32_T(&indexLB, 1, true);
  emxInit_int32_T(&indexUB, 1, true);
  emxInit_int32_T(&indexFixed, 1, true);
  emxInitStruct_struct_T7(&WorkingSet, true);
  QRManager.mrows = 0;
  QRManager.ncols = 0;
  i = QRManager.tau->size[0];
  QRManager.tau->size[0] = muIntScalarMin_sint32(maxDims, maxDims);
  emxEnsureCapacity_real_T(QRManager.tau, i);
  QRManager.minRowCol = 0;
  QRManager.usedPivoting = false;
  i = CholManager.FMat->size[0] * CholManager.FMat->size[1];
  CholManager.FMat->size[0] = maxDims;
  CholManager.FMat->size[1] = maxDims;
  emxEnsureCapacity_real_T(CholManager.FMat, i);
  CholManager.ldm = maxDims;
  CholManager.ndims = 0;
  CholManager.info = 0;
  i = QPObjective.grad->size[0];
  QPObjective.grad->size[0] = x0->size[1] + 1;
  emxEnsureCapacity_real_T(QPObjective.grad, i);
  i = QPObjective.Hx->size[0];
  QPObjective.Hx->size[0] = x0->size[1];
  emxEnsureCapacity_real_T(QPObjective.Hx, i);
  QPObjective.maxVar = x0->size[1] + 1;
  QPObjective.beta = 0.0;
  QPObjective.rho = 0.0;
  QPObjective.prev_objtype = 3;
  QPObjective.prev_nvar = 0;
  QPObjective.prev_hasLinear = false;
  QPObjective.gammaScalar = 0.0;
  QPObjective.nvar = x0->size[1];
  QPObjective.hasLinear = true;
  QPObjective.objtype = 3;
  i = memspace.workspace_double->size[0] * memspace.workspace_double->size[1];
  memspace.workspace_double->size[0] = maxDims;
  if (2 < x0->size[1] + 1) {
    memspace.workspace_double->size[1] = x0->size[1] + 1;
  } else {
    memspace.workspace_double->size[1] = 2;
  }

  emxEnsureCapacity_real_T(memspace.workspace_double, i);
  i = memspace.workspace_int->size[0];
  memspace.workspace_int->size[0] = maxDims;
  emxEnsureCapacity_int32_T(memspace.workspace_int, i);
  i = memspace.workspace_sort->size[0];
  memspace.workspace_sort->size[0] = maxDims;
  emxEnsureCapacity_int32_T(memspace.workspace_sort, i);
  i = indexLB->size[0];
  indexLB->size[0] = lb->size[1];
  emxEnsureCapacity_int32_T(indexLB, i);
  i = indexUB->size[0];
  indexUB->size[0] = ub->size[1];
  emxEnsureCapacity_int32_T(indexUB, i);
  i = indexFixed->size[0];
  indexFixed->size[0] = muIntScalarMin_sint32(mLB, mUB);
  emxEnsureCapacity_int32_T(indexFixed, i);
  compressBounds(x0->size[1], indexLB, indexUB, indexFixed, lb, ub, &mLB, &mUB,
                 &nVarMax);
  c_factoryConstruct(mLB, indexLB, mUB, indexUB, nVarMax, indexFixed, x0->size[1],
                     x0->size[1] + 1, mConstrMax, &WorkingSet);
  emxFree_int32_T(&indexFixed);
  emxFree_int32_T(&indexUB);
  emxFree_int32_T(&indexLB);
  emxFree_real_T(&x0);
  if (lb->size[1] != 0) {
    for (nVar = 0; nVar < mLB; nVar++) {
      TrialState.xstarsqp->data[WorkingSet.indexLB->data[nVar] - 1] =
        muDoubleScalarMax(TrialState.xstarsqp->data[WorkingSet.indexLB->
                          data[nVar] - 1], lb->data[WorkingSet.indexLB->
                          data[nVar] - 1]);
    }
  }

  if (ub->size[1] != 0) {
    for (nVar = 0; nVar < mUB; nVar++) {
      TrialState.xstarsqp->data[WorkingSet.indexUB->data[nVar] - 1] =
        muDoubleScalarMin(TrialState.xstarsqp->data[WorkingSet.indexUB->
                          data[nVar] - 1], ub->data[WorkingSet.indexUB->
                          data[nVar] - 1]);
    }

    for (nVar = 0; nVar < nVarMax; nVar++) {
      TrialState.xstarsqp->data[WorkingSet.indexFixed->data[nVar] - 1] =
        ub->data[WorkingSet.indexFixed->data[nVar] - 1];
    }
  }

  fval = anon(actual_state, ref_com, Fr_l0, Fr_r0, mpc_N, params->int_method,
              params->int_steps, params->b, params->p_a1, params->p_a2,
              params->g, params->m, params->w1, params->mpc_dt,
              TrialState.xstarsqp);
  TrialState.sqpFval = fval;
  computeForwardDifferences(&FiniteDifferences, fval, TrialState.xstarsqp,
    TrialState.grad, lb, ub);
  TrialState.FunctionEvaluations = FiniteDifferences.numEvals + 1;
  hasLB = (lb->size[1] != 0);
  hasUB = (ub->size[1] != 0);
  if (hasLB) {
    for (nVar = 0; nVar < mLB; nVar++) {
      WorkingSet.lb->data[WorkingSet.indexLB->data[nVar] - 1] = -lb->
        data[WorkingSet.indexLB->data[nVar] - 1];
    }
  }

  if (hasUB) {
    for (nVar = 0; nVar < mUB; nVar++) {
      WorkingSet.ub->data[WorkingSet.indexUB->data[nVar] - 1] = ub->
        data[WorkingSet.indexUB->data[nVar] - 1];
    }
  }

  if (hasLB && hasUB) {
    for (nVar = 0; nVar < nVarMax; nVar++) {
      d = ub->data[WorkingSet.indexFixed->data[nVar] - 1];
      WorkingSet.ub->data[WorkingSet.indexFixed->data[nVar] - 1] = d;
      WorkingSet.bwset->data[nVar] = d;
    }
  }

  setProblemType(&WorkingSet, 3);
  nVarMax = WorkingSet.isActiveIdx[2];
  i = WorkingSet.mConstrMax;
  for (nVar = nVarMax; nVar <= i; nVar++) {
    WorkingSet.isActiveConstr->data[nVar - 1] = false;
  }

  WorkingSet.nWConstr[0] = WorkingSet.sizes[0];
  WorkingSet.nWConstr[1] = 0;
  WorkingSet.nWConstr[2] = 0;
  WorkingSet.nWConstr[3] = 0;
  WorkingSet.nWConstr[4] = 0;
  WorkingSet.nActiveConstr = WorkingSet.nWConstr[0];
  nVarMax = WorkingSet.sizes[0];
  for (maxDims = 0; maxDims < nVarMax; maxDims++) {
    WorkingSet.Wid->data[maxDims] = 1;
    WorkingSet.Wlocalidx->data[maxDims] = maxDims + 1;
    WorkingSet.isActiveConstr->data[maxDims] = true;
    i = WorkingSet.indexFixed->data[maxDims];
    for (b_i = 0; b_i <= i - 2; b_i++) {
      WorkingSet.ATwset->data[b_i + WorkingSet.ATwset->size[0] * maxDims] = 0.0;
    }

    WorkingSet.ATwset->data[(WorkingSet.indexFixed->data[maxDims] +
      WorkingSet.ATwset->size[0] * maxDims) - 1] = 1.0;
    i = WorkingSet.indexFixed->data[maxDims] + 1;
    nVar = WorkingSet.nVar;
    for (b_i = i; b_i <= nVar; b_i++) {
      WorkingSet.ATwset->data[(b_i + WorkingSet.ATwset->size[0] * maxDims) - 1] =
        0.0;
    }

    WorkingSet.bwset->data[maxDims] = WorkingSet.ub->data
      [WorkingSet.indexFixed->data[maxDims] - 1];
  }

  MeritFunction.initFval = fval;
  MeritFunction.penaltyParam = 1.0;
  MeritFunction.threshold = 0.0001;
  MeritFunction.nPenaltyDecreases = 0;
  MeritFunction.linearizedConstrViol = 0.0;
  MeritFunction.initConstrViolationEq = 0.0;
  MeritFunction.initConstrViolationIneq = 0.0;
  MeritFunction.phi = 0.0;
  MeritFunction.phiPrimePlus = 0.0;
  MeritFunction.phiFullStep = 0.0;
  MeritFunction.feasRelativeFactor = 0.0;
  MeritFunction.nlpPrimalFeasError = 0.0;
  MeritFunction.nlpDualFeasError = 0.0;
  MeritFunction.nlpComplError = 0.0;
  MeritFunction.firstOrderOpt = 0.0;
  MeritFunction.hasObjective = true;
  driver(Hessian, lb, ub, &TrialState, &MeritFunction, &FcnEvaluator,
         &FiniteDifferences, &memspace, &WorkingSet, &QRManager, &CholManager,
         &QPObjective);
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = TrialState.xstarsqp->size[1];
  emxEnsureCapacity_real_T(x, i);
  nVarMax = TrialState.xstarsqp->size[0] * TrialState.xstarsqp->size[1];
  emxFree_real_T(&Hessian);
  emxFreeStruct_struct_T7(&WorkingSet);
  emxFreeStruct_struct_T6(&memspace);
  emxFreeStruct_struct_T5(&QPObjective);
  emxFreeStruct_struct_T4(&CholManager);
  emxFreeStruct_struct_T3(&QRManager);
  emxFreeStruct_struct_T2(&FiniteDifferences);
  emxFreeStruct_struct_T1(&FcnEvaluator);
  emxFree_real_T(&ub);
  emxFree_real_T(&lb);
  for (i = 0; i < nVarMax; i++) {
    x->data[i] = TrialState.xstarsqp->data[i];
  }

  /* ,  @(x) constraints_mpc(x, actual_com, ref_com, Fr_l0, Fr_r0 ) , options); */
  *EXITFLAG = TrialState.sqpExitFlag;
  *final_cost = TrialState.sqpFval;
  emxFreeStruct_struct_T(&TrialState);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (optimize_cpp_mpc.c) */

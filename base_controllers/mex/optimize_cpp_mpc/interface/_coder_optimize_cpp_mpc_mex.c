/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_optimize_cpp_mpc_mex.c
 *
 * Code generation for function '_coder_optimize_cpp_mpc_mex'
 *
 */

/* Include files */
#include "_coder_optimize_cpp_mpc_mex.h"
#include "_coder_optimize_cpp_mpc_api.h"
#include "optimize_cpp_mpc_data.h"
#include "optimize_cpp_mpc_initialize.h"
#include "optimize_cpp_mpc_terminate.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&optimize_cpp_mpc_atexit);

  /* Module initialization. */
  optimize_cpp_mpc_initialize();

  /* Dispatch the entry-point. */
  optimize_cpp_mpc_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  optimize_cpp_mpc_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

void optimize_cpp_mpc_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
  const mxArray *prhs[8])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;

  /* Check for proper number of arguments. */
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 8, 4, 16, "optimize_cpp_mpc");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 16,
                        "optimize_cpp_mpc");
  }

  /* Call the function. */
  optimize_cpp_mpc_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

/* End of code generation (_coder_optimize_cpp_mpc_mex.c) */

#ifndef PIE_CORE_CUDA_HELPER_H_
#define PIE_CORE_CUDA_HELPER_H_

#include <tuple>

#include "solver.h"

void print_cuda_info();

class CudaSolver : public Solver {
 protected:
  int* buf;
  unsigned char* buf2;
  int grid_size, block_size;
  // CUDA
  int* cA;
  unsigned char* cbuf;
  float *cB, *cX, *cerr, *tmp;

 public:
  explicit CudaSolver(int block_size);
  ~CudaSolver();

  py::array_t<int> partition(py::array_t<int> mask);
  void post_reset();
  std::tuple<py::array_t<unsigned char>, py::array_t<float>> step(
      int iteration);
};

#endif  // PIE_CORE_CUDA_HELPER_H_

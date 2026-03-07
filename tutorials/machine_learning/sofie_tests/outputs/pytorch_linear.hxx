//Code generated automatically by TMVA for Inference of Model file [pytorch_linear.onnx] at [Sat Mar  7 08:15:44 2026] 

#ifndef ROOT_TMVA_SOFIE_PYTORCH_LINEAR
#define ROOT_TMVA_SOFIE_PYTORCH_LINEAR

#include <algorithm>
#include <vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_pytorch_linear{
namespace BLAS{
	extern "C" void sgemv_(const char * trans, const int * m, const int * n, const float * alpha, const float * A,
	                       const int * lda, const float * X, const int * incx, const float * beta, const float * Y, const int * incy);
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
}//BLAS
struct Session {
// initialized (weights and constant) tensors
std::vector<float> fTensor_bias = std::vector<float>(16);
float * tensor_bias = fTensor_bias.data();
std::vector<float> fTensor_weight = std::vector<float>(256);
float * tensor_weight = fTensor_weight.data();

//--- Allocating session memory pool to be used for allocating intermediate tensors
std::vector<char> fIntermediateMemoryPool = std::vector<char>(64);


// --- Positioning intermediate tensor memory --
 // Allocating memory for intermediate tensor linear with size 64 bytes
float* tensor_linear = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);


Session(std::string filename ="pytorch_linear.dat") {

//--- reading weights from file
   std::ifstream f;
   f.open(filename);
   if (!f.is_open()) {
      throw std::runtime_error("tmva-sofie failed to open file " + filename + " for input weights");
   }
   using TMVA::Experimental::SOFIE::ReadTensorFromStream;
   ReadTensorFromStream(f, tensor_bias, "tensor_bias", 16);
   ReadTensorFromStream(f, tensor_weight, "tensor_weight", 256);
   f.close();

}

void doInfer(float const* tensor_input,  std::vector<float> &output_tensor_linear ){


//--------- Gemm op_0 { 1 , 16 } * { 16 , 16 } -> { 1 , 16 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 16 * j;
      for (size_t k = 0; k < 16; k++) { 
         tensor_linear[y_index + k] = tensor_bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_linear, true, false, 16, 1, 16, 1, tensor_weight, tensor_input, 1,nullptr);
   using TMVA::Experimental::SOFIE::UTILITY::FillOutput;

   FillOutput(tensor_linear, output_tensor_linear, 16);
}



std::vector<float> infer(float const* tensor_input){
   std::vector<float > output_tensor_linear;
   doInfer(tensor_input, output_tensor_linear );
   return {output_tensor_linear};
}
};   // end of Session

} //TMVA_SOFIE_pytorch_linear

#endif  // ROOT_TMVA_SOFIE_PYTORCH_LINEAR

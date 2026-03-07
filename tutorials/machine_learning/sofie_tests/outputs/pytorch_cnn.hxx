//Code generated automatically by TMVA for Inference of Model file [pytorch_cnn.onnx] at [Sat Mar  7 08:23:44 2026] 

#ifndef ROOT_TMVA_SOFIE_PYTORCH_CNN
#define ROOT_TMVA_SOFIE_PYTORCH_CNN

#include <algorithm>
#include <vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_pytorch_cnn{
namespace BLAS{
	extern "C" void saxpy_(const int * n, const float * alpha, const float * x,
	                         const int * incx, float * y, const int * incy);
	extern "C" void sgemv_(const char * trans, const int * m, const int * n, const float * alpha, const float * A,
	                       const int * lda, const float * X, const int * incx, const float * beta, const float * Y, const int * incy);
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
}//BLAS
struct Session {
// initialized (weights and constant) tensors
std::vector<float> fTensor_fcweight = std::vector<float>(27040);
float * tensor_fcweight = fTensor_fcweight.data();
std::vector<float> fTensor_fcbias = std::vector<float>(10);
float * tensor_fcbias = fTensor_fcbias.data();
std::vector<float> fTensor_convbias = std::vector<float>(4);
float * tensor_convbias = fTensor_convbias.data();
std::vector<float> fTensor_convweight = std::vector<float>(36);
float * tensor_convweight = fTensor_convweight.data();

//--- Allocating session memory pool to be used for allocating intermediate tensors
std::vector<char> fIntermediateMemoryPool = std::vector<char>(35296);


// --- Positioning intermediate tensor memory --
 // Allocating memory for intermediate tensor input_xcol with size 24336 bytes
float* tensor_input_xcol = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor conv2d with size 10816 bytes
float* tensor_conv2d = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 24336);

 // Allocating memory for intermediate tensor input_f with size 144 bytes
float* tensor_input_f = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 35152);

 // Allocating memory for intermediate tensor relu with size 10816 bytes
float* tensor_relu = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 13520);

 // Allocating memory for intermediate tensor view with size 10816 bytes
float* tensor_view = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 2704);

 // Allocating memory for intermediate tensor output with size 40 bytes
float* tensor_output = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 2664);


Session(std::string filename ="pytorch_cnn.dat") {

//--- reading weights from file
   std::ifstream f;
   f.open(filename);
   if (!f.is_open()) {
      throw std::runtime_error("tmva-sofie failed to open file " + filename + " for input weights");
   }
   using TMVA::Experimental::SOFIE::ReadTensorFromStream;
   ReadTensorFromStream(f, tensor_fcweight, "tensor_fcweight", 27040);
   ReadTensorFromStream(f, tensor_fcbias, "tensor_fcbias", 10);
   ReadTensorFromStream(f, tensor_convbias, "tensor_convbias", 4);
   ReadTensorFromStream(f, tensor_convweight, "tensor_convweight", 36);
   f.close();

//--- broadcast bias tensor convbiasfor Conv op if needed 
   {
      float * data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_convbias, { 4 , 1 , 1 }, { 1 , 4 , 26 , 26 });
      fTensor_convbias.resize(2704);
      std::copy(data, data + 2704, fTensor_convbias.begin());
      tensor_convbias = fTensor_convbias.data();
      delete[] data;
   }
}

void doInfer(float const* tensor_input,  std::vector<float> &output_tensor_output ){


//----  operator Conv op_0
   for (std::size_t oc = 0; oc < 4; oc++) {
      for (std::size_t ic = 0; ic < 1; ic++) {
         for (std::size_t kh = 0; kh < 3; kh++) {
            for (std::size_t kw = 0; kw < 3; kw++) {
               tensor_input_f[oc * 9 + ic * 9 + kh * 3 + kw * 1  ] = tensor_convweight[oc * 9 + ic * 9 + kh * 3 + kw ];
            }
         }
      }
   }
   char op_0_transA = 'N';
   char op_0_transB = 'N';
   int op_0_m = 676;
   int op_0_n = 4;
   int op_0_k = 9;
   float op_0_alpha = 1.0;
   float op_0_beta = 1.0;
   for (size_t n = 0; n < 1; n++) {
      size_t out_offset = n * 2704;
      size_t x_offset = n * 784;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_input + x_offset,1,28,28,3,3,0,0,1,1,1,1,tensor_input_xcol);

    TMVA::Experimental::SOFIE::Gemm_Call(tensor_conv2d + out_offset, false, false, op_0_m, op_0_n, op_0_k, op_0_alpha, tensor_input_xcol, tensor_input_f, op_0_beta, tensor_convbias);
   }

//------ RELU
   for (int id = 0; id < 2704 ; id++){
      tensor_relu[id] = ((tensor_conv2d[id] > 0 )? tensor_conv2d[id] : 0);
   }
   ///--------Reshape operator 2 --> { 1 , 2704 }
   std::copy( tensor_relu, tensor_relu + 2704, tensor_view);

//--------- Gemm op_3 { 1 , 2704 } * { 10 , 2704 } -> { 1 , 10 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 10 * j;
      for (size_t k = 0; k < 10; k++) { 
         tensor_output[y_index + k] = tensor_fcbias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_output, true, false, 10, 1, 2704, 1, tensor_fcweight, tensor_view, 1,nullptr);
   using TMVA::Experimental::SOFIE::UTILITY::FillOutput;

   FillOutput(tensor_output, output_tensor_output, 10);
}



std::vector<float> infer(float const* tensor_input){
   std::vector<float > output_tensor_output;
   doInfer(tensor_input, output_tensor_output );
   return {output_tensor_output};
}
};   // end of Session

} //TMVA_SOFIE_pytorch_cnn

#endif  // ROOT_TMVA_SOFIE_PYTORCH_CNN

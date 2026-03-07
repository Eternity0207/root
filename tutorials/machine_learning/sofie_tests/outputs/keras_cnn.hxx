//Code generated automatically by TMVA for Inference of Model file [keras_cnn.onnx] at [Sat Mar  7 08:28:58 2026] 

#ifndef ROOT_TMVA_SOFIE_KERAS_CNN
#define ROOT_TMVA_SOFIE_KERAS_CNN

#include <algorithm>
#include <vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_keras_cnn{
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
int64_t tensor_const_axes__13[1] = { 0};
int64_t tensor_Const__28[4] = { 0, 2, 3, 1};
int64_t tensor_const_ends__12[1] = { 1};
std::vector<float> fTensor_sequential_1conv2d_1convolutionReadVariableOp0 = std::vector<float>(36);
float * tensor_sequential_1conv2d_1convolutionReadVariableOp0 = fTensor_sequential_1conv2d_1convolutionReadVariableOp0.data();
std::vector<float> fTensor_sequential_1dense_1CastReadVariableOp0 = std::vector<float>(27040);
float * tensor_sequential_1dense_1CastReadVariableOp0 = fTensor_sequential_1dense_1CastReadVariableOp0.data();

//--- Allocating session memory pool to be used for allocating intermediate tensors
std::vector<char> fIntermediateMemoryPool = std::vector<char>(28368);


// --- Positioning intermediate tensor memory --
 // Allocating memory for intermediate tensor sequential_1conv2d_1convolution__60_xcol with size 28224 bytes
float* tensor_sequential_1conv2d_1convolution__60_xcol = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor sequential_1conv2d_1convolution__60_f with size 144 bytes
float* tensor_sequential_1conv2d_1convolution__60_f = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 28224);

 // Allocating memory for intermediate tensor Shape__260 with size 32 bytes
int64_t* tensor_Shape__260 = reinterpret_cast<int64_t*>(fIntermediateMemoryPool.data() + 28336);

 // Allocating memory for intermediate tensor sequential_1flatten_1Shape0 with size 8 bytes
int64_t* tensor_sequential_1flatten_1Shape0 = reinterpret_cast<int64_t*>(fIntermediateMemoryPool.data() + 28328);

 // Allocating memory for intermediate tensor sequential_1flatten_1Shape__100 with size 0 bytes
other_0* tensor_sequential_1flatten_1Shape__100 = reinterpret_cast<other_0*>(fIntermediateMemoryPool.data() + 28328);

 // Allocating memory for intermediate tensor sequential_1flatten_1Reshapeshape_Concat__200 with size 0 bytes
other_0* tensor_sequential_1flatten_1Reshapeshape_Concat__200 = reinterpret_cast<other_0*>(fIntermediateMemoryPool.data() + 28328);

 // Allocating memory for intermediate tensor sequential_1flatten_1Reshape__210 with size 16 bytes
int64_t* tensor_sequential_1flatten_1Reshape__210 = reinterpret_cast<int64_t*>(fIntermediateMemoryPool.data() + 28312);

//--- declare and allocate the intermediate tensors
other_0 * tensor_sequential_1flatten_1strided_slice0 = nullptr;
//--- declare the dynamic tensors
float * tensor_Identity0 = nullptr;
float * tensor_sequential_1flatten_1Reshape0 = nullptr;
float * tensor_Transpose__220 = nullptr;
float * tensor_sequential_1conv2d_1Relu0 = nullptr;
float * tensor_sequential_1conv2d_1convolution0 = nullptr;
float * tensor_sequential_1conv2d_1convolution__60 = nullptr;
//--- dynamic tensors pool
std::vector<char> fDynamicMemoryPool;


size_t fS_sequential_1flatten_1Reshape0_0;
size_t fS_sequential_1flatten_1Reshape0_1;
size_t fUnk__32;


Session(std::string filename ="keras_cnn.dat",
        size_t s_sequential_1flatten_1Reshape0_0 = 0,
        size_t s_sequential_1flatten_1Reshape0_1 = 0,
        size_t unk__32 = 0) {


   fS_sequential_1flatten_1Reshape0_0 = s_sequential_1flatten_1Reshape0_0;
   fS_sequential_1flatten_1Reshape0_1 = s_sequential_1flatten_1Reshape0_1;
   fUnk__32 = unk__32;

//--- reading weights from file
   std::ifstream f;
   f.open(filename);
   if (!f.is_open()) {
      throw std::runtime_error("tmva-sofie failed to open file " + filename + " for input weights");
   }
   using TMVA::Experimental::SOFIE::ReadTensorFromStream;
   ReadTensorFromStream(f, tensor_sequential_1conv2d_1convolutionReadVariableOp0, "tensor_sequential_1conv2d_1convolutionReadVariableOp0", 36);
   ReadTensorFromStream(f, tensor_sequential_1dense_1CastReadVariableOp0, "tensor_sequential_1dense_1CastReadVariableOp0", 27040);
   f.close();

//  dynamic tensor memory management
   std::vector<TMVA::Experimental::SOFIE::TensorLifeInfo> dynamicTensorInfos;
   dynamicTensorInfos.reserve(6);
   dynamicTensorInfos.push_back( {0, 2, 4* (unk__32 * 784) }); // tensor_sequential_1conv2d_1convolution__60
   dynamicTensorInfos.push_back( {1, 3, 4* (unk__32 * 3136) }); // tensor_sequential_1conv2d_1convolution0
   dynamicTensorInfos.push_back( {2, 5, 4* (unk__32 * 3136) }); // tensor_sequential_1conv2d_1Relu0
   dynamicTensorInfos.push_back( {3, 11, 4* (unk__32 * 3136) }); // tensor_Transpose__220
   dynamicTensorInfos.push_back( {10, 12, 4* (s_sequential_1flatten_1Reshape0_0 * s_sequential_1flatten_1Reshape0_1) }); // tensor_sequential_1flatten_1Reshape0
   dynamicTensorInfos.push_back( {11, 12, 4* (s_sequential_1flatten_1Reshape0_0 * 10) }); // tensor_Identity0

   auto memory_result = OrganizeMemory(dynamicTensorInfos);

//  allocating now the memory
   fDynamicMemoryPool = std::vector<char>(memory_result.total_bytes);
   int idx = 0;
   tensor_sequential_1conv2d_1convolution__60 = reinterpret_cast<float *>(fDynamicMemoryPool.data() + memory_result.offsets[idx++]);
   tensor_sequential_1conv2d_1convolution0 = reinterpret_cast<float *>(fDynamicMemoryPool.data() + memory_result.offsets[idx++]);
   tensor_sequential_1conv2d_1Relu0 = reinterpret_cast<float *>(fDynamicMemoryPool.data() + memory_result.offsets[idx++]);
   tensor_Transpose__220 = reinterpret_cast<float *>(fDynamicMemoryPool.data() + memory_result.offsets[idx++]);
   tensor_sequential_1flatten_1Reshape0 = reinterpret_cast<float *>(fDynamicMemoryPool.data() + memory_result.offsets[idx++]);
   tensor_Identity0 = reinterpret_cast<float *>(fDynamicMemoryPool.data() + memory_result.offsets[idx++]);
}

void doInfer(size_t unk__32,float const* tensor_args_00,  std::vector<float> &output_tensor_Identity0 ){

   ///--------Reshape operator 0 --> { unk__32 , 1 , 28 , 28 }
   std::copy( tensor_args_00, tensor_args_00 + unk__32 * 784, tensor_sequential_1conv2d_1convolution__60);

//----  operator Conv op_1
   for (std::size_t oc = 0; oc < 4; oc++) {
      for (std::size_t ic = 0; ic < 1; ic++) {
         for (std::size_t kh = 0; kh < 3; kh++) {
            for (std::size_t kw = 0; kw < 3; kw++) {
               tensor_sequential_1conv2d_1convolution__60_f[oc * 9 + ic * 9 + kh * 3 + kw * 1  ] = tensor_sequential_1conv2d_1convolutionReadVariableOp0[oc * 9 + ic * 9 + kh * 3 + kw ];
            }
         }
      }
   }
   char op_1_transA = 'N';
   char op_1_transB = 'N';
   int op_1_m = 784;
   int op_1_n = 4;
   int op_1_k = 9;
   float op_1_alpha = 1.0;
   float op_1_beta = 0.0;
   for (size_t n = 0; n < unk__32; n++) {
      size_t out_offset = n * 3136;
      size_t x_offset = n * 784;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_sequential_1conv2d_1convolution__60 + x_offset,1,28,28,3,3,1,1,1,1,1,1,tensor_sequential_1conv2d_1convolution__60_xcol);

    TMVA::Experimental::SOFIE::Gemm_Call(tensor_sequential_1conv2d_1convolution0 + out_offset, false, false, op_1_m, op_1_n, op_1_k, op_1_alpha, tensor_sequential_1conv2d_1convolution__60_xcol, tensor_sequential_1conv2d_1convolution__60_f, op_1_beta, nullptr);
   }

//------ RELU
   for (int id = 0; id < unk__32 * 3136 ; id++){
      tensor_sequential_1conv2d_1Relu0[id] = ((tensor_sequential_1conv2d_1convolution0[id] > 0 )? tensor_sequential_1conv2d_1convolution0[id] : 0);
   }
   ///------- Transpose operator op_3{ unk__32 , 4 , 28 , 28 } --> { unk__32 , 28 , 28 , 4 }
   for (size_t id = 0; id < unk__32 * 3136 ; id++){
      tensor_Transpose__220[id] = tensor_sequential_1conv2d_1Relu0[ ( id / (3136) ) * 3136 + ( (id % (4)) ) * 784 + ( (id % (3136)) / (112) ) * 28 + ( (id % (112)) / (4) )];
   }
//--------- Gather op_5 --> sequential_1flatten_1Shape0  { 4 }
//--------------------(constant)----------

//------ CAST 6 ---> sequential_1flatten_1Shape__100  { 1 }
   for (int id = 0; id < 1 ; id++){
      tensor_sequential_1flatten_1Shape__100[id] = static_cast<int32_t>(tensor_sequential_1flatten_1Shape0[id]);
   }
///------- Slice operator 7---> sequential_1flatten_1strided_slice0 { 1 }

/// Slice is just an identity (copy pointers) 
   tensor_sequential_1flatten_1strided_slice0 = tensor_sequential_1flatten_1Shape__100;

//--------- Concat op_8 --> sequential_1flatten_1Reshapeshape_Concat__200  { 2 }
   std::copy(tensor_sequential_1flatten_1strided_slice0, tensor_sequential_1flatten_1strided_slice0+1, tensor_sequential_1flatten_1Reshapeshape_Concat__200);
   std::copy(tensor_const_fold_opt__31, tensor_const_fold_opt__31+1, tensor_sequential_1flatten_1Reshapeshape_Concat__200 + 1);

//------ CAST 9 ---> sequential_1flatten_1Reshape__210  { 2 }
   for (int id = 0; id < 2 ; id++){
      tensor_sequential_1flatten_1Reshape__210[id] = static_cast<int64_t>(tensor_sequential_1flatten_1Reshapeshape_Concat__200[id]);
   }
   ///--------Reshape operator 10 --> { s_sequential_1flatten_1Reshape0_0 , s_sequential_1flatten_1Reshape0_1 }
   size_t s_sequential_1flatten_1Reshape0_0 = tensor_sequential_1flatten_1Reshape__210[0];
   if (tensor_sequential_1flatten_1Reshape__210[0] <= 0 ) s_sequential_1flatten_1Reshape0_0 = unk__32;
   size_t s_sequential_1flatten_1Reshape0_1 = tensor_sequential_1flatten_1Reshape__210[1];
   if (tensor_sequential_1flatten_1Reshape__210[1] <= 0 ) s_sequential_1flatten_1Reshape0_1 = 28;
   if (s_sequential_1flatten_1Reshape0_0 * s_sequential_1flatten_1Reshape0_1!=unk__32 * 3136)
throw std::runtime_error("TMVA SOFIE Reshape Op : output lengths is different than input one");
   std::copy( tensor_Transpose__220, tensor_Transpose__220 + unk__32 * 3136, tensor_sequential_1flatten_1Reshape0);

//--------- Gemm op_11 { s_sequential_1flatten_1Reshape0_0 , s_sequential_1flatten_1Reshape0_1 } * { 2704 , 10 } -> { s_sequential_1flatten_1Reshape0_0 , 10 }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_Identity0, false, false, 10, s_sequential_1flatten_1Reshape0_0, s_sequential_1flatten_1Reshape0_1, 1, tensor_sequential_1dense_1CastReadVariableOp0, tensor_sequential_1flatten_1Reshape0, 0,nullptr);
   using TMVA::Experimental::SOFIE::UTILITY::FillOutput;

   FillOutput(tensor_Identity0, output_tensor_Identity0, s_sequential_1flatten_1Reshape0_0 * 10);
}



std::vector<float> infer(size_t unk__32,float const* tensor_args_00){
   std::vector<float > output_tensor_Identity0;
   if (unk__32 > fUnk__32) {
      throw std::runtime_error("TMVA-SOFIE: dynamic input tensor shape parameter unk__32 exceeds the initialized maximum allowed shape.");
   }
   doInfer(unk__32,tensor_args_00, output_tensor_Identity0 );
   return {output_tensor_Identity0};
}
};   // end of Session

} //TMVA_SOFIE_keras_cnn

#endif  // ROOT_TMVA_SOFIE_KERAS_CNN

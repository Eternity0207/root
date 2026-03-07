//Code generated automatically by TMVA for Inference of Model file [keras_dense.onnx] at [Sat Mar  7 08:27:25 2026] 

#ifndef ROOT_TMVA_SOFIE_KERAS_DENSE
#define ROOT_TMVA_SOFIE_KERAS_DENSE

#include <algorithm>
#include <vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_keras_dense{
namespace BLAS{
	extern "C" void sgemv_(const char * trans, const int * m, const int * n, const float * alpha, const float * A,
	                       const int * lda, const float * X, const int * incx, const float * beta, const float * Y, const int * incy);
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
}//BLAS
struct Session {
// initialized (weights and constant) tensors
std::vector<float> fTensor_sequential_1dense_1CastReadVariableOp0 = std::vector<float>(512);
float * tensor_sequential_1dense_1CastReadVariableOp0 = fTensor_sequential_1dense_1CastReadVariableOp0.data();
std::vector<float> fTensor_sequential_1dense_1_2CastReadVariableOp0 = std::vector<float>(512);
float * tensor_sequential_1dense_1_2CastReadVariableOp0 = fTensor_sequential_1dense_1_2CastReadVariableOp0.data();

// --- Positioning intermediate tensor memory --//--- declare the dynamic tensors
float * tensor_Identity0 = nullptr;
float * tensor_sequential_1dense_1Relu0 = nullptr;
float * tensor_sequential_1dense_1MatMul0 = nullptr;
//--- dynamic tensors pool
std::vector<char> fDynamicMemoryPool;


size_t fUnk__6;


Session(std::string filename ="keras_dense.dat",
        size_t unk__6 = 0) {


   fUnk__6 = unk__6;

//--- reading weights from file
   std::ifstream f;
   f.open(filename);
   if (!f.is_open()) {
      throw std::runtime_error("tmva-sofie failed to open file " + filename + " for input weights");
   }
   using TMVA::Experimental::SOFIE::ReadTensorFromStream;
   ReadTensorFromStream(f, tensor_sequential_1dense_1CastReadVariableOp0, "tensor_sequential_1dense_1CastReadVariableOp0", 512);
   ReadTensorFromStream(f, tensor_sequential_1dense_1_2CastReadVariableOp0, "tensor_sequential_1dense_1_2CastReadVariableOp0", 512);
   f.close();

//  dynamic tensor memory management
   std::vector<TMVA::Experimental::SOFIE::TensorLifeInfo> dynamicTensorInfos;
   dynamicTensorInfos.reserve(3);
   dynamicTensorInfos.push_back( {0, 2, 4* (unk__6 * 32) }); // tensor_sequential_1dense_1MatMul0
   dynamicTensorInfos.push_back( {1, 3, 4* (unk__6 * 32) }); // tensor_sequential_1dense_1Relu0
   dynamicTensorInfos.push_back( {2, 3, 4* (unk__6 * 16) }); // tensor_Identity0

   auto memory_result = OrganizeMemory(dynamicTensorInfos);

//  allocating now the memory
   fDynamicMemoryPool = std::vector<char>(memory_result.total_bytes);
   int idx = 0;
   tensor_sequential_1dense_1MatMul0 = reinterpret_cast<float *>(fDynamicMemoryPool.data() + memory_result.offsets[idx++]);
   tensor_sequential_1dense_1Relu0 = reinterpret_cast<float *>(fDynamicMemoryPool.data() + memory_result.offsets[idx++]);
   tensor_Identity0 = reinterpret_cast<float *>(fDynamicMemoryPool.data() + memory_result.offsets[idx++]);
}

void doInfer(size_t unk__6,float const* tensor_args_00,  std::vector<float> &output_tensor_Identity0 ){


//--------- Gemm op_0 { unk__6 , 16 } * { 16 , 32 } -> { unk__6 , 32 }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_sequential_1dense_1MatMul0, false, false, 32, unk__6, 16, 1, tensor_sequential_1dense_1CastReadVariableOp0, tensor_args_00, 0,nullptr);

//------ RELU
   for (int id = 0; id < unk__6 * 32 ; id++){
      tensor_sequential_1dense_1Relu0[id] = ((tensor_sequential_1dense_1MatMul0[id] > 0 )? tensor_sequential_1dense_1MatMul0[id] : 0);
   }

//--------- Gemm op_2 { unk__6 , 32 } * { 32 , 16 } -> { unk__6 , 16 }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_Identity0, false, false, 16, unk__6, 32, 1, tensor_sequential_1dense_1_2CastReadVariableOp0, tensor_sequential_1dense_1Relu0, 0,nullptr);
   using TMVA::Experimental::SOFIE::UTILITY::FillOutput;

   FillOutput(tensor_Identity0, output_tensor_Identity0, unk__6 * 16);
}



std::vector<float> infer(size_t unk__6,float const* tensor_args_00){
   std::vector<float > output_tensor_Identity0;
   if (unk__6 > fUnk__6) {
      throw std::runtime_error("TMVA-SOFIE: dynamic input tensor shape parameter unk__6 exceeds the initialized maximum allowed shape.");
   }
   doInfer(unk__6,tensor_args_00, output_tensor_Identity0 );
   return {output_tensor_Identity0};
}
};   // end of Session

} //TMVA_SOFIE_keras_dense

#endif  // ROOT_TMVA_SOFIE_KERAS_DENSE

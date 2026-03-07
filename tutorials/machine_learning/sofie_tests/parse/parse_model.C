#include "TMVA/RModelParser_ONNX.hxx"

void parse_model(const char *model_path)
{
   using namespace TMVA::Experimental::SOFIE;

   RModelParser_ONNX parser;

   auto rmodel = parser.Parse(model_path);

   rmodel.Generate();

   rmodel.OutputGenerated();
}
#include <TensorFlowLite.h>
#include <tensorflow/lite/micro/all_ops_resolver.h>

#include "model.h"
//#include "output_handler.h"
//#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"


namespace {
tflite::ErrorReporter* error_reporter = nullptr;
const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
TfLiteTensor* input = nullptr;
TfLiteTensor* output = nullptr;
int inference_count = 0;

constexpr int kTensorArenaSize = 2000;
uint8_t tensor_arena[kTensorArenaSize];
}  // n


void setup() {
  // put your setup code here, to run once:
 model = tflite::GetModel(g_model);
 
 static tflite::AllOpsResolver resolver;

  // Build an interpreter to run the model with.
  static tflite::MicroInterpreter static_interpreter(
      model, resolver, tensor_arena, kTensorArenaSize, error_reporter);
  interpreter = &static_interpreter;

  // Allocate memory from the tensor_arena for the model's tensors.
  TfLiteStatus allocate_status = interpreter->AllocateTensors();


  // Obtain pointers to the model's input and output tensors.
  input = interpreter->input(0);
  output = interpreter->output(0);


}

void loop() {
  // put your main code here, to run repeatedly:

float x=1;
input->data.int8[0] = x;
//digitalWrite(D1,HIGH);
//TfLiteStatus invoke_status = interpreter->Invoke();
 
//Serial.print(output->data.int8[0]);
int a= inferencefunction(1);
//digitalWrite(D1,LOW);

delay(100);


}


int inferencefunction(int x){
TfLiteStatus invoke_status = interpreter->Invoke();

  return x;

}

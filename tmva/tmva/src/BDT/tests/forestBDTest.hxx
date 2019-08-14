#include "gtest/gtest.h"
#include "forest.h"
#include "bdt_helpers.h"

//#include <xgboost/c_api.h> // for xgboost
//#include "generated_files/evaluate_forest2.h"
std::string events_file     = "./data/events.csv";
std::string preds_file      = "./data/python_predictions.csv";
std::string json_model_file = "./data/model.json";

TEST(forestBDT, UniquePredictions)
{
   std::vector<std::vector<float>> events_vector = read_csv<float>(events_file);
   std::vector<std::vector<bool>>  groundtruth   = read_csv<bool>(preds_file);
   std::vector<bool>               preds;
   preds.reserve(events_vector.size());

   Forest<unique_bdt::Tree> Forest;
   Forest.get_Forest(json_model_file);
   Forest.do_predictions(events_vector, preds);

   for (size_t i = 0; i < preds.size(); i++) {
      ASSERT_EQ(preds[i], groundtruth[i][0]);
   }
}

TEST(forestBDT, UniqueBatchPredictions)
{
   int                             loop_size     = 256;
   std::vector<std::vector<float>> events_vector = read_csv<float>(events_file);
   std::vector<std::vector<bool>>  groundtruth   = read_csv<bool>(preds_file);
   std::vector<bool>               preds;
   preds.reserve(events_vector.size());

   Forest<unique_bdt::Tree> Forest;
   Forest.get_Forest(json_model_file);
   Forest.do_predictions_batch(events_vector, preds, loop_size);

   for (size_t i = 0; i < preds.size(); i++) {
      ASSERT_EQ(preds[i], groundtruth[i][0]);
   }
}

TEST(forestBDT, UniqueBatch2Predictions)
{
   int                             loop_size     = 256;
   std::vector<std::vector<float>> events_vector = read_csv<float>(events_file);
   std::vector<std::vector<bool>>  groundtruth   = read_csv<bool>(preds_file);
   std::vector<bool>               preds;
   preds.reserve(events_vector.size());

   Forest<unique_bdt::Tree> Forest;
   Forest.get_Forest(json_model_file);
   Forest.do_predictions_batch2(events_vector, preds, loop_size);

   // std::string tmp_filename = "./data/tmp2.csv";
   // write_csv(tmp_filename, preds);

   for (size_t i = 0; i < preds.size(); i++) {
      ASSERT_EQ(preds[i], groundtruth[i][0]);
   }
}

TEST(forestBDT, ArrayPredictions)
{
   std::vector<std::vector<float>> events_vector = read_csv<float>(events_file);
   std::vector<std::vector<bool>>  groundtruth   = read_csv<bool>(preds_file);
   std::vector<bool>               preds;
   preds.reserve(events_vector.size());

   Forest<array_bdt::Tree> Forest;
   Forest.get_Forest(json_model_file);
   Forest.do_predictions(events_vector, preds);

   for (size_t i = 0; i < preds.size(); i++) {
      ASSERT_EQ(preds[i], groundtruth[i][0]);
   }
}

TEST(forestBDT, JitForestPredictions)
{
   std::vector<std::vector<float>> events_vector = read_csv<float>(events_file);
   std::vector<std::vector<bool>>  groundtruth   = read_csv<bool>(preds_file);
   std::vector<bool>               preds;
   preds.reserve(events_vector.size());

   Forest<std::function<bool(std::vector<float>)>> Forest;
   Forest.get_Forest(json_model_file);
   Forest.do_predictions(events_vector, preds);

   for (size_t i = 0; i < preds.size(); i++) {
      ASSERT_EQ(preds[i], groundtruth[i][0]);
   }
}

TEST(forestBDT, JitPredictionsAll)
{
   std::vector<std::vector<float>> events_vector = read_csv<float>(events_file);
   std::vector<std::vector<bool>>  groundtruth   = read_csv<bool>(preds_file);
   std::vector<bool>               preds;
   preds.reserve(events_vector.size());

   Forest<std::function<void(const std::vector<std::vector<float>> &, std::vector<bool> &)>> Forest;
   Forest.get_Forest(json_model_file, events_vector);
   Forest.do_predictions(events_vector, preds);

   for (size_t i = 0; i < preds.size(); i++) {
      ASSERT_EQ(preds[i], groundtruth[i][0]);
   }
}

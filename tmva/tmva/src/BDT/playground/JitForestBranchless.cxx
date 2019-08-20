#include "forest.h"
#include "setup.h"

int main()
{
   Forest<std::function<bool(const float *)>> Forest;
   Forest.get_Forest(json_model_file, true);
   preds.reserve(events_vector.size());
   Forest.do_predictions(events_vector, preds);
   write_csv(preds_file, preds);
   return 0;
}

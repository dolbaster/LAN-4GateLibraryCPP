#include "PrintSummaryReport.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void PrintSummaryReport::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
            }
        }
    }
}

#include "PrintDetailReport.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void PrintDetailReport::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
            }
        }
    }
}

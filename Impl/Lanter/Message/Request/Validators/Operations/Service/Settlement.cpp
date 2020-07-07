#include "Settlement.h"

namespace Lanter {
    namespace Message {
        namespace Request {

            void Request::Settlement::addSpecificFields() {
                appendMandatoryField(RequestFields::EcrMerchantNumber);
            }
        }
    }
}

#ifndef LAN_4GATELIBRARYCPP_TEST_H
#define LAN_4GATELIBRARYCPP_TEST_H

#include "Lanter/Message/Request/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            class Test : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Request
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_TEST_H

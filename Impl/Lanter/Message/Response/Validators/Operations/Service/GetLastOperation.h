#ifndef LAN_4GATELIBRARYCPP_GETLASTOPERATION_H
#define LAN_4GATELIBRARYCPP_GETLASTOPERATION_H

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class GetLastOperation : public BasicValidator {
            public:
                void addSpecificFields() override;
            };
        }//Response
    }
}//Lanter

#endif //LAN_4GATELIBRARYCPP_GETLASTOPERATION_H

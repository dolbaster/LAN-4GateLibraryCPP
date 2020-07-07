#include "QuickPayment.h"


namespace Lanter {
    namespace Message {
        namespace Response {
            void Response::QuickPayment::addSpecificFields() {
                appendOptionalField(ResponseFields::EcrMerchantNumber);
                appendOptionalField(ResponseFields::TotalAmount);
                appendOptionalField(ResponseFields::AcquirerFeeAmount);
                appendOptionalField(ResponseFields::TerminalFeeAmount);
                appendOptionalField(ResponseFields::CurrencyCode);
                appendOptionalField(ResponseFields::RRN);
                appendOptionalField(ResponseFields::ReceiptReference);
                appendOptionalField(ResponseFields::TransactionID);
                appendOptionalField(ResponseFields::AuthCode);
                appendOptionalField(ResponseFields::ResponseCode);
                appendOptionalField(ResponseFields::ResponseText);
                appendOptionalField(ResponseFields::TerminalID);
                appendOptionalField(ResponseFields::MerchantID);
                appendOptionalField(ResponseFields::TransDateTime);
                appendOptionalField(ResponseFields::TerminalDateTime);
            }
        }
    }
}

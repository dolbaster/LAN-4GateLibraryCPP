#include "AliPay.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            void AliPay::addSpecificFields() {
                appendOptionalField(ResponseField::EcrMerchantNumber);
                appendOptionalField(ResponseField::TotalAmount);
                appendOptionalField(ResponseField::AcquirerFeeAmount);
                appendOptionalField(ResponseField::TerminalFeeAmount);
                appendOptionalField(ResponseField::CurrencyCode);
                appendOptionalField(ResponseField::RRN);
                appendOptionalField(ResponseField::ReceiptReference);
                appendOptionalField(ResponseField::TransactionID);
                appendOptionalField(ResponseField::AuthCode);
                appendOptionalField(ResponseField::ResponseCode);
                appendOptionalField(ResponseField::ResponseText);
                appendOptionalField(ResponseField::TerminalID);
                appendOptionalField(ResponseField::MerchantID);
                appendOptionalField(ResponseField::TransDateTime);
                appendOptionalField(ResponseField::TerminalDateTime);
            }
        }
    }
}

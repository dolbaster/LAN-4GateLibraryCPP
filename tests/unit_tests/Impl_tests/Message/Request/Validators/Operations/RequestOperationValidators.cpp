#include "gtest/gtest.h"

#include "Lanter/Message/Request/Validators/ValidatorFactory.h"

using namespace Lanter;
using namespace Lanter::Message;
using namespace Lanter::Message::Request;

//Refund
TEST(RequestOperationValidators, CheckRefund) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);
    fields.insert(RequestField::RRN);
    fields.insert(RequestField::TransactionID);

    auto validator = ValidatorFactory::getValidator(OperationCode::Refund);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckRefundWithoutRRN) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCode::RefundWithoutRRN);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Sales
TEST(RequestOperationValidators, CheckAliPay) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCode::AliPay);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());

    for(auto i : fields) {
        EXPECT_TRUE(validator->getMandatoryFields().find(i) != validator->getMandatoryFields().end());
    }
}

TEST(RequestOperationValidators, CheckFastTrack) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);
    fields.insert(RequestField::EncTags);
    fields.insert(RequestField::OpenTags);

    auto validator = ValidatorFactory::getValidator(OperationCode::FastTrack);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckMOTO) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCode::MOTO);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());

    for(auto i : fields) {
        EXPECT_TRUE(validator->getMandatoryFields().find(i) != validator->getMandatoryFields().end());
    }
}

TEST(RequestOperationValidators, CheckPreAuth) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);
    fields.insert(RequestField::TransactionID);
    fields.insert(RequestField::CardDataEnc);

    auto validator = ValidatorFactory::getValidator(OperationCode::PreAuth);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckQuickPayment) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCode::QuickPayment);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());

    for(auto i : fields) {
        EXPECT_TRUE(validator->getMandatoryFields().find(i) != validator->getMandatoryFields().end());
    }
}

TEST(RequestOperationValidators, CheckQuickPaymentStatus) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::RRN);
    fields.insert(RequestField::AuthCode);
    fields.insert(RequestField::TransactionID);
    fields.insert(RequestField::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCode::QuickPaymentStatus);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckSale) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);

    auto validator = ValidatorFactory::getValidator(OperationCode::Sale);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());

    for(auto i : fields) {
        EXPECT_TRUE(validator->getMandatoryFields().find(i) != validator->getMandatoryFields().end());
    }
}

TEST(RequestOperationValidators, CheckSalesCompletion) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::Amount);
    fields.insert(RequestField::CurrencyCode);
    fields.insert(RequestField::RRN);
    fields.insert(RequestField::AuthCode);
    fields.insert(RequestField::TransactionID);

    auto validator = ValidatorFactory::getValidator(OperationCode::SalesCompletion);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Void
TEST(RequestOperationValidators, CheckVoid) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCode::Void);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckVoidPartialSale) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::PartialAmount);
    fields.insert(RequestField::CurrencyCode);
    fields.insert(RequestField::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCode::VoidPartialSale);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckVoidPreAuth) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::CardDataEnc);
    fields.insert(RequestField::TransactionID);

    auto validator = ValidatorFactory::getValidator(OperationCode::VoidPreAuth);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

//Service

TEST(RequestOperationValidators, CheckDisplayQR) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::AdditionalInfo);

    auto validator = ValidatorFactory::getValidator(OperationCode::DisplayQR);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_FALSE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckFinalizeTransaction) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::FinalizeTransaction);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckGetCurrentPrinter) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::GetCurrentPrinter);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckGetLastOperation) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::GetLastOperation);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckGetOperationCopy) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCode::GetOperationCopy);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckInitialization) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::Initialization);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckKeyDownload) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::KeyDownload);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckPrintCommsInfo) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintCommsInfo);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckPrintDetailReport) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintDetailReport);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckPrintLastReceipt) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintLastReceipt);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckPrintReceiptCopy) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);
    fields.insert(RequestField::ReceiptReference);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintReceiptCopy);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckPrintSoftInfo) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintSoftInfo);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckPrintSummaryReport) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::PrintSummaryReport);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckRegistration) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::Registration);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckSelfTest) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::SelfTest);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckSetCurrentPrinter) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::AdditionalInfo);

    auto validator = ValidatorFactory::getValidator(OperationCode::SetCurrentPrinter);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckSettlement) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);
    fields.insert(RequestField::EcrMerchantNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::Settlement);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckTest) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::Test);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckTestCommunication) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::TestCommunication);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}

TEST(RequestOperationValidators, CheckUpdateSW) {
    std::set<RequestField> fields;

    fields.insert(RequestField::OperationCode);
    fields.insert(RequestField::EcrNumber);

    auto validator = ValidatorFactory::getValidator(OperationCode::UpdateSW);

    EXPECT_TRUE(validator->validate(fields));

    EXPECT_FALSE(validator->getMandatoryFields().empty());
    EXPECT_TRUE(validator->getOptionalFields().empty());

    std::set<RequestField> allFields;
    allFields.insert(validator->getMandatoryFields().begin(), validator->getMandatoryFields().end());
    allFields.insert(validator->getOptionalFields().begin(), validator->getOptionalFields().end());

    for(auto i : fields) {
        EXPECT_TRUE(allFields.find(i) != allFields.end());
    }
}
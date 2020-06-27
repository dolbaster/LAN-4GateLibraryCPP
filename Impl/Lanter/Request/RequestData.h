//
// Created by Владимир Лысенков on 19.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_REQUESTDATA_H
#define LAN_4GATELIBRARYCPP_REQUESTDATA_H

#include <memory>

#include "Lanter/Request/IRequestData.h"

#include "Validators/IValidator.h"

namespace Lanter {
    namespace Request {
        ///\brief Базовый класс-контейнер для отправки запросов финансовому ПО LAN-4Tap
        class RequestData : public IRequestData {
        public:
            RequestData();
            ~RequestData() override = default;

            const std::set<RequestFields> &getMandatoryFields() const override;

            const std::set<RequestFields> &getOptionalFields() const override;

            bool validateMandatoryFields() override;

            /// Возвращает список установленных полей
            /// \return Список установленных полей
            /// \sa RequestFields
            const std::set<RequestFields> &getFieldsSet() const override;

            /// Возвращает логический идентификатор кассового ПО
            /// \return Если поле установлено - логический идентификатор кассового ПО, иначе -1
            int16_t getEcrNumber() const override;

            /// Устанавливает лоический иденитфикатор кассового ПО
            /// \param ecrNumber Логический идентификатор кассового ПО в диапазоне [1, 999]
            /// \throws invalid_argument, если значение вне разрешенного диапазона
            void setEcrNumber(int16_t ecrNumber) override;

            /// Возвращает логический идентификатор мерчанта в кассовом ПО
            /// \return Если поле установлено - логический идентификатор мерчанта в кассовом ПО, иначе -1
            int16_t getEcrMerchantNumber() const override;

            /// Устанавливает лоический иденитфикатор мерчанта в кассовом ПО
            /// \param ecrNumber Логический идентификатор мерчанта в кассовом в диапазоне [1, 999]
            /// \throws invalid_argument, если значение вне разрешенного диапазона
            void setEcrMerchantNumber(int16_t ecrMerchantNumber) override;

            /// Возвращает код выполняемой операции
            /// \return Если поле установлено, возвращает код операции. Иначе NoOperation
            /// \sa OperationCodes
            OperationCodes getOperationCode() const override;

            /// Устанавливает код выполнямой операции
            /// \param operationCode Значение из перечислений OperationCodes, за исключением NoOperation
            /// \sa OperationCodes
            /// \throws invalid_argument, если передается недопустимый код операции
            void setOperationCode(OperationCodes operationCode) override;

            /// Возвращает установленную сумму операции в минимальных единицах валюты (копейки для рублей)
            /// \return Если поле установлено - значение суммы операции в диапазоне [0, 999999999999]. Иначе -1.
            int64_t getAmount() const override;

            /// Устанавливает сумму в минимальных единицах валюты (копейки для рублей)
            /// \param amount Значение суммы в диапазоне [0, 999999999999]
            /// \throws invalid_argument, если сумма вне диапазона
            void setAmount(int64_t amount) override;

            /// Возвращает установленную частичную сумму в минимальных единицах валюты (копейки для рублей)
            /// \return Если поле установлено - значение суммы операции в диапазоне [0, 999999999999]. Иначе -1.
            int64_t getPartialAmount() const override;

            /// Устанавливает частичную сумму в минимальных единицах валюты (копейки для рублей)
            /// \param partialAmount Значение частичной суммы операции в диапазоне [0, 999999999999]
            /// \throws invalid_argument, если сумма вне диапазона
            void setPartialAmount(int64_t partialAmount) override;

            /// Возвращает установленную сумму чаевых в минимальных единицах валюты (копейки для рублей)
            /// \return Если поле установлено - значение суммы чаевых в диапазоне [0, 999999999999]. Иначе -1.
            int64_t getTipsAmount() const override;

            /// Устанавливает сумму чаевых в минимальных единицах валюты (копейки для рублей)
            /// \param partialAmount Значение суммы чаевых операции в диапазоне [0, 999999999999]
            /// \throws invalid_argument, если сумма вне диапазона
            void setTipsAmount(int64_t tipsAmount) override;

            /// Возвращает установленную сумму кэшбека в минимальных единицах валюты (копейки для рублей)
            /// \return Если поле установлено - значение суммы чаевых в диапазоне [0, 999999999999]. Иначе -1.
            int64_t getCashbackAmount() const override;

            /// Устанавливает сумму кэшбека в минимальных единицах валюты (копейки для рублей)
            /// \param partialAmount Значение суммы кэшбека операции в диапазоне [0, 999999999999]
            /// \throws invalid_argument, если сумма вне диапазона
            void setCashbackAmount(int64_t cashbackAmount) override;

            /// Возвращает установленный код валюты согласно ISO 4217
            /// \return Установленный код валюты, иначе -1
            int16_t getCurrencyCode() const override;

            /// Устанавливает код валюты согласно ISO 4217
            /// \param currencyCode Код валюты в диапазоне [1, 999]
            /// \throws invalid_argument, если значение вне диапазона
            void setCurrencyCode(int16_t currencyCode) override;

            /// Возвращает установленное значение RRN
            /// \return строка, содержащая RRN.
            const std::string &getRRN() const override;

            /// Устанавливает RRN, полученный в ответ на одну из предыдущих операций
            /// \param RRN Строка, содержащая RRN.
            void setRRN(const std::string &RRN) override;

            /// Возвращает установленное знаение кода авторизации
            /// \return строка, содержащая код авторизации
            const std::string &getAuthCode() const override;

            /// Устанавливает код авторизации, полученный в ответ на одну из предыдущих операций
            /// \param authCode Строка, содержащая код авторизации.
            void setAuthCode(const std::string &authCode) override;

            /// Возвращает установленное значение номера чека
            /// \return Строка, содержащая номер чека
            const std::string &getReceiptReference() const override;

            /// Устанавливает значение номера чека в финансовом ПО LAN-4Tap,
            /// полученное в ответ на однй из предыдущих операций
            /// \param receiptReference Строка, содержащая номер чека в финансовом ПО LAN-4Tap
            void setReceiptReference(const std::string &receiptReference) override;

            /// Возвращает установленное значение иднетификатора транзакции
            /// \return Строка содержащая значение идентификатора транзакции
            const std::string &getTransactionId() const override;

            /// Устанавливает значение идентификатора тназакции, полученное в ответ на однй из предыдущих операций
            /// \param transactionId Строка, содержащая идентификатор тразакции
            void setTransactionId(const std::string &transactionId) override;

            /// Возвращает установленное значение, содержащее зашифрованные данные карты
            /// \return Строка, содержащая зашифрованные данные карты
            const std::string &getCardDataEnc() const override;

            /// Устанавливает значение зашифрованных данных карты, полученное в ответ на одну из предыдущих операций
            /// \param cardDataEnc Строка, содержщая зашифрованные данные карты
            void setCardDataEnc(const std::string &cardDataEnc) override;

            /// Возвращает установленное значение списка открытых тегов операции FastTrack
            /// \return Строка, содержащая список открытых тегов операции FastTrack
            /// \sa setOpenTags
            const std::string &getOpenTags() const override;

            /// Устанавливает список тегов, которые необходимо получить от финансового ПО LAN-4Tap в открытом виде
            /// \param openTags Строка, отформатированная по следующему шаблону:
            /// Каждый тег должен быть закодирован 4 байтами в текстовом шестнадцатеричном представлении.
            /// Например, тег DF82 кодируется, как 0000DF82, а тег 82 - 00000082
            /// Несколько тегов записываются друг за другом, например  0000DF8200000082.
            /// Опционально, строка может начинаться с лидирующей последовательности 0x
            /// Регистр текста не важен
            void setOpenTags(const std::string &openTags) override;

            /// Возвращает установленное значение списка шифруемых тегов операции FastTrack
            /// \return Строка, содержащая список шифруемых тегов операции FastTrack
            /// \sa setEncTags
            const std::string &getEncTags() const override;

            /// Устанавливает список тегов, которые необходимо получить от финансового ПО LAN-4Tap в зашифрованном виде
            /// \param encTags Строка, отформатированная по следующему шаблону:
            /// Каждый тег должен быть закодирован 4 байтами в текстовом шестнадцатеричном представлении.
            /// Например, тег DF82 кодируется, как 0000DF82, а тег 82 - 00000082
            /// Несколько тегов записываются друг за другом, например  0000DF8200000082.
            /// Опционально, строка может начинаться с лидирующей последовательности 0x
            /// Регистр текста не важен
            void setEncTags(const std::string &encTags) override;

            /// Возвращает установленный код провайдера платежа
            /// \return Строка, содержащая установленный код провайдера платежа
            const std::string &getProviderCode() const override;

            /// Устанавливает код провайдера платежа
            /// \param providerCode Строка, содержащая код провайдера платежа
            void setProviderCode(const std::string &providerCode) override;

            /// Возвращает установленное значение дополнительных параметров операции
            /// \return Строка, содержащая дополнительные параметры операции
            const std::string &getAdditionalInfo() const override;

            /// Устанавливает дополнительные параметры операции
            /// \param additionalInfo Строка, содержащая дополнительные параметры операции. Формат зависит от операции.
            void setAdditionalInfo(const std::string &additionalInfo) override;

        private:
            void initValidator();
            std::set<RequestFields> m_FieldsSet; ///< Список установленных полей

            std::shared_ptr<IValidator> m_Validator; ///< Валидатор полей операции

            int16_t m_EcrNumber = -1; ///< Логический номер кассы, используемый для взаимодействия с LAN-4Tap
            int16_t m_EcrMerchantNumber = -1; ///< Логический номер мерчанта в кассовом ПО
            OperationCodes m_OperationCode = OperationCodes::NoOperation; ///< Код запрашиваемой операции
            int64_t m_Amount = -1; ///< Сумма операции
            int64_t m_PartialAmount = -1; ///< Часть оригинальной суммы. Используется в операциях отмены и возврата
            int64_t m_TipsAmount = -1; ///< Сумма чаевых
            int64_t m_CashbackAmount = -1; ///< Сумма кэшбека
            int16_t m_CurrencyCode = -1; ///< Код валюты согласно ISO 4217
            std::string m_RRN; ///< Retrieval Reference Number, полученный в ответ на предыдущую операцию
            std::string m_AuthCode; ///< Код авторизации на хосте, полученный в ответ на предыдущю операцию
            std::string m_ReceiptReference; ///< Номер чека в финансовом ПО LAN-4Tap. Может отличаться от номера чека в кассовом ПО
            std::string m_TransactionID; ///< Идентификатор транзакции на хосте, полученный в ответ на предыдущую операцию
            std::string m_CardDataEnc; ///< Зашированные данные карты
            std::string m_OpenTags; ///< Теги, которые необходимо получить в открытом виде (формат TLV) в операции FastTrack
            std::string m_EncTags; ///< Теги, которые необходимо получить в зашифрованном виде в операции FastTrack
            std::string m_ProviderCode; ///< Код вендора платежа
            std::string m_AdditionalInfo; ///< Дополнительные данные операции

            std::set<RequestFields> m_EmptyFieldsPlaceholder; ///< Пустая коллекция для полей при отсутствии валидатора
        };//RequestData
    }//Request
}//Lanter
#endif //LAN_4GATELIBRARYCPP_REQUESTDATA_H
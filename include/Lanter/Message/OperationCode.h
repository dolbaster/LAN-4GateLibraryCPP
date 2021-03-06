#ifndef LAN_4GATELIBRARYCPP_OPERATIONCODES_H
#define LAN_4GATELIBRARYCPP_OPERATIONCODES_H

namespace Lanter {
    namespace Message {
        /// \brief Список поддерживаемых операций
        enum class OperationCode {
            NoOperation, ///< Значение-заглушка. Нет кода операции
            //Операции оплаты
            Sale = 1, ///< Оплата
            MOTO, ///< Mail order/Telephone order - оплата заказа через e-mail или телефон
            QuickPayment, ///< Оплата через систему быстрых платежей ЦБ РФ
            AliPay, ///< Оплата через систему AliPay

            PreAuth = 200, ///< Преавторизация
            SalesCompletion, ///< Завершение преавторизации
            QuickPaymentStatus, ///< Проверка статуса оплаты через СБП
            FastTrack = 300, ///< Получение зашифрованный и открытых тегов карты

            //Операции отмены
            Void = 400, ///< Отмена по номеру чека
            VoidPartialSale, ///< Частичная отмена по номеру чека
            VoidPreAuth, ///< Отмена преавторизации

            //Операции возврата
            Refund = 500, ///< Возврат с m_RRN
            RefundWithoutRRN, ///< Возврат без m_RRN
            QuickPaymentRefund, ///< Возврат через СБП
            QuickPaymentRefundStatus, ///<  Проверка статуса возврата через СБП

            //Служебные операции
            Registration = 800, ///< Регистрация в транспортом сервисе LAN-4Gate
            TestCommunication, ///< Проверка связи с финансовым ПО LAN-4Tap
            Test, ///< Проверки связи финансового ПО LAN-4Tap с хостом
            PrintLastReceipt, ///< Печать копии чека и получение данных последней выполненной финансовой операции
            GetLastOperation, ///< Получение данных последней выполненненой финансовой операции
            PrintReceiptCopy, ///< Печать копии чека и получение данных операции по номеру чека
            PrintDetailReport, ///< Печать детального отчета и получение сведений о нем
            PrintSummaryReport, ///< Печать краткого отчета и получение сведений о нем
            Settlement, ///< Сверка итогов
            KeyDownload, ///< Загрузка рабочих ключей финансовым ПО LAN-4Tap
            Initialization, ///< Загрузка параметров финансового ПО LAN-4Tap
            UpdateSW, ///< Обновление финансового ПО LAN-4Tap
            PrintCommsInfo, ///< Печать и получение данных о настроенных коммуникациях в финансовом ПО LAN-4Tap
            PrintSoftInfo, ///< Печать и получение данных о финансовом ПО LAN-4Tap
            FinalizeTransaction, ///< Подтверждение на завершение финансовой операции финансовым ПО LAN-4Tap
            GetCurrentPrinter, ///< Получение информации о текущем устройстве печати
            SetCurrentPrinter, ///< Установка текущего устройства печати
            SelfTest, ///< Самопроверка финансового ПО LAN-4Tap
            GetOperationCopy, ///< Получение данных операции по номеру чека
            DisplayQR, ///< Отображение информации в виде QR кода финансовым ПО LAN-4Tap

            //Отдельный тип операции для представления массивов операции DetailReport
            ArrayElement = 1000, ///< Фиктивный код операции для создания элементов массива
            //Диапазон операций
            FirstValue = Sale, ///< Ссылка на первый элемент перечисления
            LastValue = ArrayElement ///< Ссылка на последний элемент перечисления
        };//enum OperationCode
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_OPERATIONCODES_H

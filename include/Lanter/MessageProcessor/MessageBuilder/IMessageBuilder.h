//
// Created by Владимир Лысенков on 07.07.2020.
//

#ifndef LAN_4GATELIBRARYCPP_IMESSAGEBUILDER_H
#define LAN_4GATELIBRARYCPP_IMESSAGEBUILDER_H

#include <vector>
#include <memory>

#include "Lanter/Message/Request/IRequestData.h"
#include "Lanter/Message/Response/IResponseData.h"
#include "Lanter/Message/Notification/INotificationData.h"
#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    using namespace Message;
    using namespace Message::Request;
    using namespace Message::Response;
    using namespace Message::Notification;

    namespace MessageProcessor {
        /// \brief Интерфейс сборщика сообщений на основе заполненных контейнеров
        class LANTER_VISIBILITY IMessageBuilder {
        public:
            virtual ~IMessageBuilder() = default;
            /// \brief Создает сообщение на основе контейнера IRequestData
            /// \param[in] data Заполненный контейнер IRequestData
            /// \param[out] result vector из байтов, содержащий собранное сообщение
            /// \return true, если сборка сообщения прошла успешно.
            /// \sa IRequestData
            virtual bool createMessage(std::shared_ptr<IRequestData> data, std::vector<unsigned char> & result) = 0;

            /// \brief Создает сообщение на основе контейнера IResponseData
            /// \param[in] data Заполненный контейнер IResponseData
            /// \param[out] result vector из байтов, содержащий собранное сообщение
            /// \return true, если сборка сообщения прошла успешно.
            /// \sa IResponseData
            virtual bool createMessage(std::shared_ptr<IResponseData> data, std::vector<unsigned char> & result) = 0;

            /// \brief Создает сообщение на основе контейнера INotificationData
            /// \param[in] data Заполненный контейнер INotificationData
            /// \param[out] result vector из байтов, содержащий собранное сообщение
            /// \return true, если сборка сообщения прошла успешно.
            /// \sa INotificationData
            virtual bool createMessage(std::shared_ptr<INotificationData> data, std::vector<unsigned char> & result) = 0;
        };
    }//MessageProcessor
}//Lanter
#endif //LAN_4GATELIBRARYCPP_IMESSAGEBUILDER_H

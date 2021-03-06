#ifndef LAN_4GATELIBRARYCPP_MESSAGEPARSERFACTORY_H
#define LAN_4GATELIBRARYCPP_MESSAGEPARSERFACTORY_H

#include <memory>

#include "IMessageParser.h"
#include "Lanter/Utils/VisibilityMacroses.h"

namespace Lanter {
    namespace MessageProcessor {
        namespace Parser {
            /// \brief Фабричный класс, возвращающий текущий парсер сообщений
            class LANTER_VISIBILITY MessageParserFactory {
            public:
                /// \brief Возвращает указатель на созданный объект парсера
                /// \return nullptr, если не удалось создать парсер
                static std::shared_ptr<IMessageParser> getMessageParser();
            };//class MessageParserFactory
        }//namespace Parser
    }//namespace MessageProcessor
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_MESSAGEPARSERFACTORY_H

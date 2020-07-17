//
// Created by Владимир Лысенков on 12.07.2020.
//

#include "Lanter/MessageProcessor/MessageParser/MessageParserFactory.h"

#include "Lanter/MessageProcessor/MessageParser/JSONMessageParser.h"

namespace Lanter {
    namespace MessageProcessor {
        std::shared_ptr<IMessageParser> MessageParserFactory::getMessageParser() {
            return std::make_shared<JSONMessageParser>();
        }
    }
}
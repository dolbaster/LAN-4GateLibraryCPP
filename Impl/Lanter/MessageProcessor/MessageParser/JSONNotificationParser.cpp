//
// Created by Владимир Лысенков on 14.07.2020.
//

#include "JSONNotificationParser.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "Lanter/Message/Notification/NotificationDataFactory.h"

#include "JSONGetFieldHelper.h"

namespace Lanter {
    namespace MessageProcessor {

        std::shared_ptr<INotificationData> JSONNotificationParser::parseData(const Json::Value &object) {
            std::shared_ptr<INotificationData> result = NotificationDataFactory::getNotificationData();
            if(result) {
                if (getCode(object, *result)) {
                    getAdditional(object, *result);
                    getMessage(object, *result);
                } else {
                    result.reset();
                }
            }
            return result;
        }

        bool JSONNotificationParser::getCode(const Json::Value &object, INotificationData &data) {
            bool result = false;
            int code;
            if(JSONGetFieldHelper::getFieldInt(object, JSONNotificationFields::getCode(), code)) {
                result = data.setCode(static_cast<NotificationCodes>(code));
            }
            return result;
        }

        bool JSONNotificationParser::getAdditional(const Json::Value &object, INotificationData &data) {
            bool result = false;
            std::string additional;
            if(JSONGetFieldHelper::getFieldString(object, JSONNotificationFields::getAdditional(), additional)) {
                if(!additional.empty()) {
                    data.setAdditional(additional);
                    result = true;
                }
            }
            return result;
        }

        bool JSONNotificationParser::getMessage(const Json::Value &object, INotificationData &data) {
            bool result = false;
            std::string message;
            if(JSONGetFieldHelper::getFieldString(object, JSONNotificationFields::getMessage(), message)) {
                if(!message.empty()) {
                    data.setMessage(message);
                    result = true;
                }
            }
            return result;
        }


    }
}
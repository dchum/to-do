/**
 * @file header_message.h
 * @author chumakov (<d.tchumackov2013@yandex.ru>)
 * @brief Заголовок любой посылки между модулями
 * @version 0.1
 * @date 2026-04-19
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#pragma once

#include <cstdint>

#include "module_id.h"

struct HeaderMessage {
    ModuleId receiver;  /* Идентификатор модуля, которому предназначено сообщение */
    ModuleId   sender;  /* Идентификатор модуля, который отправил сообщение */
    uint64_t       id;  /* Уникальный идентификатор каждого снимка*/
    uint32_t  version;  /* Версия снимка, принимающая сторона обязана поддерживать эту версию или выше */
};
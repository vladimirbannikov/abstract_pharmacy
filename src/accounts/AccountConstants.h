#ifndef ARCHITECTURE_ACCOUNTCONSTANTS_H
#define ARCHITECTURE_ACCOUNTCONSTANTS_H
#include "string"

namespace accounts {

    enum class Type {
        user
    };

    namespace table_names {
        static inline std::string user_table{"user_table_name"};
    }
}

#endif

#ifndef ARCHITECTURE_ITEMCONSTANTS_H
#define ARCHITECTURE_ITEMCONSTANTS_H

#include <string>
namespace items {
    enum class Type {
        receipt
    };

    namespace table_names {
        static inline std::string receipt_table{"receipt"};
    }

    namespace type_names {
        static inline std::string receipt{"receipt"};
    }
}

#endif

#include "publicTarget.hpp"
#include "publicTarget2.hpp"
#include "privateTarget.hpp"

namespace publicTarget {
    std::string getDescription() {
        return "Public Target and "
            + publicTarget2::getDescription()
            + " and "
            + privateTarget::getDescription();
    }
}

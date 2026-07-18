#ifndef ELIZA_H
#define ELIZA_H

#include "ConversationHistory.h"
#include "GenericResponses.h"
#include <string>

class Eliza {
public:
    void run();

private:
    ConversationHistory history;
    GenericResponses genericResponses;

    std::string normalizeInput(const std::string& input) const;
    bool isGoodbye(const std::string& input) const;
    std::string defaultResponse(const std::string& input) const;
};

#endif

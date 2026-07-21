#ifndef CONVERSATION_HISTORY_H
#define CONVERSATION_HISTORY_H

#include <string>
#include <vector>

// Stores prior user statements and detects repeated input.
class ConversationHistory {
public:
    bool hasSeen(const std::string& input) const;
    void remember(const std::string& input);

private:
    std::vector<std::string> previousInputs;
    std::string canonicalize(const std::string& input) const;
};

#endif

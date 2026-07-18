#include "ConversationHistory.h"
#include <algorithm>
#include <cctype>

std::string ConversationHistory::canonicalize(const std::string& input) const {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    while (!result.empty() && (result.back() == '.' || result.back() == '!' || result.back() == '?')) {
        result.pop_back();
    }
    return result;
}

bool ConversationHistory::hasSeen(const std::string& input) const {
    const std::string target = canonicalize(input);
    for (const std::string& oldInput : previousInputs) {
        if (canonicalize(oldInput) == target) return true;
    }
    return false;
}

void ConversationHistory::remember(const std::string& input) {
    previousInputs.push_back(input);
}

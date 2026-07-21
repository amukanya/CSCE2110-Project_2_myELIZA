#include "ConversationHistory.h"
#include <algorithm>
#include <cctype>

// Converts an input to a comparison-friendly form for duplicate detection.
std::string ConversationHistory::canonicalize(const std::string& input) const {
    std::string result = input;

    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char ch) {
                       return static_cast<char>(std::tolower(ch));
                   });

    // Ignore final punctuation when deciding whether a statement was repeated.
    while (!result.empty() &&
           (result.back() == '.' || result.back() == '!' || result.back() == '?')) {
        result.pop_back();
    }

    return result;
}

// Returns true when an equivalent input already exists in the history.
bool ConversationHistory::hasSeen(const std::string& input) const {
    const std::string target = canonicalize(input);

    for (const std::string& oldInput : previousInputs) {
        if (canonicalize(oldInput) == target) {
            return true;
        }
    }

    return false;
}

// Adds a new user statement to the conversation history.
void ConversationHistory::remember(const std::string& input) {
    previousInputs.push_back(input);
}

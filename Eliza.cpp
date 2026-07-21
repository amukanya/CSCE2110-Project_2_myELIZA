#include "Eliza.h"
#include <iostream>
#include <regex>

// Trims leading/trailing whitespace and collapses repeated internal spaces.
std::string Eliza::normalizeInput(const std::string& input) const {
    std::string normalized = input;
    const std::string whitespace = " \t\n\r\f\v";
    const std::size_t first = normalized.find_first_not_of(whitespace);

    if (first == std::string::npos) {
        return "";
    }

    const std::size_t last = normalized.find_last_not_of(whitespace);
    normalized = normalized.substr(first, last - first + 1);
    normalized = std::regex_replace(normalized, std::regex(R"(\s+)"), " ");
    return normalized;
}

// Recognizes "bye" regardless of case and optional final punctuation.
bool Eliza::isGoodbye(const std::string& input) const {
    return std::regex_match(
        input,
        std::regex(R"(^bye[.!?]*$)", std::regex_constants::icase));
}

// Supplies a reply whenever no specialized regex rule matches the input.
std::string Eliza::defaultResponse(const std::string& input) const {
    if (std::regex_search(input, std::regex(R"(\?)"))) {
        return "What answer would feel most meaningful to you?";
    }

    return "Please tell me more about that.";
}

// Runs the complete interactive conversation until the user enters "bye".
void Eliza::run() {
    std::cout << "ELIZA: Hello. I am ELIZA. What would you like to discuss?\n";
    std::string rawInput;

    while (true) {
        std::cout << "You: ";

        if (!std::getline(std::cin, rawInput)) {
            std::cout << "\nELIZA: Goodbye.\n";
            break;
        }

        const std::string input = normalizeInput(rawInput);

        if (input.empty()) {
            std::cout << "ELIZA: Please enter a response so we can continue.\n";
            continue;
        }

        if (isGoodbye(input)) {
            std::cout << "ELIZA: Goodbye. Thank you for talking with me.\n";
            break;
        }

        if (history.hasSeen(input)) {
            std::cout << "ELIZA: You have already said that. "
                         "Could you express it differently?\n";
            continue;
        }

        history.remember(input);

        std::string response;
        if (genericResponses.generate(input, response)) {
            std::cout << "ELIZA: " << response << '\n';
        } else {
            std::cout << "ELIZA: " << defaultResponse(input) << '\n';
        }
    }
}

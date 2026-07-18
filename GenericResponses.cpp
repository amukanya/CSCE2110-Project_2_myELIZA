#include "GenericResponses.h"

GenericResponses::GenericResponses() {
    const auto icase = std::regex_constants::icase;
    rules = {
        {std::regex(R"(^I am (.+?)[.!?]*$)", icase), "How long have you been $1?"},
        {std::regex(R"(^I'm (.+?)[.!?]*$)", icase), "Why do you think you are $1?"},
        {std::regex(R"(^I feel (.+?)[.!?]*$)", icase), "What makes you feel $1?"},
        {std::regex(R"(^I have (.+?)[.!?]*$)", icase), "You say you have $1. How does that affect you?"},
        {std::regex(R"(^I had (.+?)[.!?]*$)", icase), "What did having $1 mean to you?"},
        {std::regex(R"(^I want (.+?)[.!?]*$)", icase), "What would it mean if you got $1?"},
        {std::regex(R"(^I need (.+?)[.!?]*$)", icase), "Why do you need $1?"},
        {std::regex(R"(^I like (.+?)[.!?]*$)", icase), "What do you like most about $1?"},
        {std::regex(R"(^I dislike (.+?)[.!?]*$)", icase), "Why do you dislike $1?"},
        {std::regex(R"(^I hate (.+?)[.!?]*$)", icase), "What causes such strong feelings about $1?"},
        {std::regex(R"(^I love (.+?)[.!?]*$)", icase), "Tell me more about your feelings toward $1."},
        {std::regex(R"(^I think (.+?)[.!?]*$)", icase), "What leads you to think $1?"},
        {std::regex(R"(^I believe (.+?)[.!?]*$)", icase), "How certain are you that $1?"},
        {std::regex(R"(^I know (.+?)[.!?]*$)", icase), "How did you come to know $1?"},
        {std::regex(R"(^I remember (.+?)[.!?]*$)", icase), "What else do you remember about $1?"},
        {std::regex(R"(^I forgot (.+?)[.!?]*$)", icase), "Why might you have forgotten $1?"},
        {std::regex(R"(^I can (.+?)[.!?]*$)", icase), "How does being able to $1 make you feel?"},
        {std::regex(R"(^I cannot (.+?)[.!?]*$)", icase), "What prevents you from being able to $1?"},
        {std::regex(R"(^I can't (.+?)[.!?]*$)", icase), "What makes it difficult to $1?"},
        {std::regex(R"(^I will (.+?)[.!?]*$)", icase), "What may happen after you $1?"},
        {std::regex(R"(^I would (.+?)[.!?]*$)", icase), "What would encourage you to $1?"},
        {std::regex(R"(^I should (.+?)[.!?]*$)", icase), "Why do you feel you should $1?"},
        {std::regex(R"(^I must (.+?)[.!?]*$)", icase), "Who or what makes $1 feel necessary?"},
        {std::regex(R"(^I did (.+?)[.!?]*$)", icase), "How did you feel after you $1?"},
        {std::regex(R"(^I do (.+?)[.!?]*$)", icase), "Why do you $1?"}
    };
}

std::string GenericResponses::reflectPronouns(const std::string& text) const {
    std::string reflected = text;
    reflected = std::regex_replace(reflected, std::regex(R"(\bmy\b)", std::regex_constants::icase), "__YOUR__");
    reflected = std::regex_replace(reflected, std::regex(R"(\bme\b)", std::regex_constants::icase), "__YOU__");
    reflected = std::regex_replace(reflected, std::regex(R"(\bI\b)", std::regex_constants::icase), "__YOU_SUBJECT__");
    reflected = std::regex_replace(reflected, std::regex(R"(\bam\b)", std::regex_constants::icase), "__ARE__");
    reflected = std::regex_replace(reflected, std::regex(R"(\byour\b)", std::regex_constants::icase), "__MY__");
    reflected = std::regex_replace(reflected, std::regex(R"(\byou\b)", std::regex_constants::icase), "__I__");
    reflected = std::regex_replace(reflected, std::regex("__YOUR__"), "your");
    reflected = std::regex_replace(reflected, std::regex("__YOU__"), "you");
    reflected = std::regex_replace(reflected, std::regex("__YOU_SUBJECT__"), "you");
    reflected = std::regex_replace(reflected, std::regex("__ARE__"), "are");
    reflected = std::regex_replace(reflected, std::regex("__MY__"), "my");
    reflected = std::regex_replace(reflected, std::regex("__I__"), "I");
    return reflected;
}

bool GenericResponses::generate(const std::string& input, std::string& response) const {
    std::smatch match;
    for (const ResponseRule& rule : rules) {
        if (std::regex_match(input, match, rule.pattern)) {
            // Reflect only the captured user text, not ELIZA's template words.
            const std::string reflectedCapture = reflectPronouns(match[1].str());
            response = rule.responseTemplate;
            const std::size_t marker = response.find("$1");
            if (marker != std::string::npos) {
                response.replace(marker, 2, reflectedCapture);
            }
            return true;
        }
    }
    return false;
}

#ifndef GENERIC_RESPONSES_H
#define GENERIC_RESPONSES_H

#include <regex>
#include <string>
#include <vector>

// Associates one regular-expression pattern with one response template.
struct ResponseRule {
    std::regex pattern;
    std::string responseTemplate;
};

// Owns ELIZA's response rules and generates replies for matching statements.
class GenericResponses {
public:
    GenericResponses();
    bool generate(const std::string& input, std::string& response) const;

private:
    std::vector<ResponseRule> rules;
    std::string reflectPronouns(const std::string& text) const;
};

#endif

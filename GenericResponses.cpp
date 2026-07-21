#include "GenericResponses.h"

// Builds the ordered rule set used by ELIZA. More specific patterns are placed
// before broad patterns so that the best response is selected first.
GenericResponses::GenericResponses() {
    const auto icase = std::regex_constants::icase;

    rules = {
        // Generic first-person statements
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
        {std::regex(R"(^I do (.+?)[.!?]*$)", icase), "Why do you $1?"},

        // Wellbeing and emotions
        {std::regex(R"(^I am sad about (.+?)[.!?]*$)", icase), "What about $1 makes you sad?"},
        {std::regex(R"(^I am happy about (.+?)[.!?]*$)", icase), "Why does $1 make you happy?"},
        {std::regex(R"(^I am worried about (.+?)[.!?]*$)", icase), "What worries you most about $1?"},
        {std::regex(R"(^I am afraid of (.+?)[.!?]*$)", icase), "When did you first become afraid of $1?"},
        {std::regex(R"(^I am angry about (.+?)[.!?]*$)", icase), "How would you like the situation with $1 to change?"},
        {std::regex(R"(^I am stressed about (.+?)[.!?]*$)", icase), "What part of $1 feels most stressful?"},
        {std::regex(R"(^I am tired of (.+?)[.!?]*$)", icase), "How long has $1 been exhausting for you?"},
        {std::regex(R"(^I feel lonely because (.+?)[.!?]*$)", icase), "How does $1 contribute to your loneliness?"},

        // Love and relationships
        {std::regex(R"(^My partner (.+?)[.!?]*$)", icase), "How do you feel when your partner $1?"},
        {std::regex(R"(^My friend (.+?)[.!?]*$)", icase), "What does it mean to you that your friend $1?"},
        {std::regex(R"(^My family (.+?)[.!?]*$)", icase), "How does it affect you when your family $1?"},
        {std::regex(R"(^My mother (.+?)[.!?]*$)", icase), "Tell me more about your relationship with your mother and how she $1."},
        {std::regex(R"(^My father (.+?)[.!?]*$)", icase), "Tell me more about your relationship with your father and how he $1."},
        {std::regex(R"(^I miss (.+?)[.!?]*$)", icase), "What do you miss most about $1?"},
        {std::regex(R"(^I trust (.+?)[.!?]*$)", icase), "What makes you trust $1?"},
        {std::regex(R"(^I do not trust (.+?)[.!?]*$)", icase), "What happened that made it difficult to trust $1?"},

        // Education
        {std::regex(R"(^School is (.+?)[.!?]*$)", icase), "What makes school seem $1 to you?"},
        {std::regex(R"(^My class is (.+?)[.!?]*$)", icase), "How does having a class that is $1 affect you?"},
        {std::regex(R"(^My professor (.+?)[.!?]*$)", icase), "How do you respond when your professor $1?"},
        {std::regex(R"(^I am studying (.+?)[.!?]*$)", icase), "What interests you about studying $1?"},
        {std::regex(R"(^I failed (.+?)[.!?]*$)", icase), "What do you think contributed to failing $1?"},
        {std::regex(R"(^I passed (.+?)[.!?]*$)", icase), "What helped you succeed in $1?"},
        {std::regex(R"(^My assignment (.+?)[.!?]*$)", icase), "What is the most challenging part when your assignment $1?"},

        // Financial concerns
        {std::regex(R"(^Money is (.+?)[.!?]*$)", icase), "How does it affect you when money is $1?"},
        {std::regex(R"(^I owe (.+?)[.!?]*$)", icase), "How do you feel about owing $1?"},
        {std::regex(R"(^I cannot afford (.+?)[.!?]*$)", icase), "What would change for you if you could afford $1?"},
        {std::regex(R"(^I am saving for (.+?)[.!?]*$)", icase), "Why is saving for $1 important to you?"},
        {std::regex(R"(^My job (.+?)[.!?]*$)", icase), "How do you feel when your job $1?"},

        // Entertainment and interests
        {std::regex(R"(^My favorite movie is (.+?)[.!?]*$)", icase), "What do you enjoy most about $1?"},
        {std::regex(R"(^My favorite game is (.+?)[.!?]*$)", icase), "What makes $1 your favorite game?"},
        {std::regex(R"(^I watch (.+?)[.!?]*$)", icase), "What do you enjoy about watching $1?"},
        {std::regex(R"(^I listen to (.+?)[.!?]*$)", icase), "How does listening to $1 make you feel?"},
        {std::regex(R"(^I play (.+?)[.!?]*$)", icase), "What do you experience when you play $1?"},
        {std::regex(R"(^I enjoy (.+?)[.!?]*$)", icase), "What makes $1 enjoyable for you?"},

        // Concern and uncertainty
        {std::regex(R"(^What if (.+?)[?]*$)", icase), "What do you believe might happen if $1?"},
        {std::regex(R"(^Why is (.+?)[?]*$)", icase), "What explanation have you considered for why $1?"},
        {std::regex(R"(^Why do (.+?)[?]*$)", icase), "What do you think may be behind why $1?"},
        {std::regex(R"(^Can you (.+?)[?]*$)", icase), "What would it mean to you if I could $1?"},
        {std::regex(R"(^Could you (.+?)[?]*$)", icase), "Why would you like me to $1?"},
        {std::regex(R"(^Do you (.+?)[?]*$)", icase), "Why is whether I $1 important to you?"},
        {std::regex(R"(^Are you (.+?)[?]*$)", icase), "What makes you wonder whether I am $1?"},
        {std::regex(R"(^Maybe (.+?)[.!?]*$)", icase), "You seem uncertain that $1. What makes you unsure?"},
        {std::regex(R"(^I do not know (.+?)[.!?]*$)", icase), "What would help you understand $1 better?"},

        // Statements involving other people
        {std::regex(R"(^You are (.+?)[.!?]*$)", icase), "What makes you think I am $1?"},
        {std::regex(R"(^You make me (.+?)[.!?]*$)", icase), "Why do you think I make you $1?"},
        {std::regex(R"(^They are (.+?)[.!?]*$)", icase), "Why do you believe they are $1?"},
        {std::regex(R"(^He is (.+?)[.!?]*$)", icase), "How does it affect you that he is $1?"},
        {std::regex(R"(^She is (.+?)[.!?]*$)", icase), "How does it affect you that she is $1?"},
        {std::regex(R"(^Someone (.+?)[.!?]*$)", icase), "Who comes to mind when you say someone $1?"},

        // Broad final patterns
        {std::regex(R"(^Because (.+?)[.!?]*$)", icase), "Is $1 the main reason?"},
        {std::regex(R"(^Yes,? (.+?)[.!?]*$)", icase), "You sound certain that $1. Why?"},
        {std::regex(R"(^No,? (.+?)[.!?]*$)", icase), "What makes you reject the idea that $1?"},
        {std::regex(R"(^It is (.+?)[.!?]*$)", icase), "In what way is it $1?"},
        {std::regex(R"(^This is (.+?)[.!?]*$)", icase), "Why does this seem $1 to you?"}
    };
}

// Changes first-person words in captured user text into ELIZA's perspective.
std::string GenericResponses::reflectPronouns(const std::string& text) const {
    std::string reflected = text;

    // Temporary markers prevent a replacement from being replaced again.
    reflected = std::regex_replace(reflected, std::regex(R"(\bmyself\b)", std::regex_constants::icase), "__YOURSELF__");
    reflected = std::regex_replace(reflected, std::regex(R"(\bmy\b)", std::regex_constants::icase), "__YOUR__");
    reflected = std::regex_replace(reflected, std::regex(R"(\bmine\b)", std::regex_constants::icase), "__YOURS__");
    reflected = std::regex_replace(reflected, std::regex(R"(\bme\b)", std::regex_constants::icase), "__YOU_OBJECT__");
    reflected = std::regex_replace(reflected, std::regex(R"(\bI\b)", std::regex_constants::icase), "__YOU_SUBJECT__");
    reflected = std::regex_replace(reflected, std::regex(R"(\bam\b)", std::regex_constants::icase), "__ARE__");
    reflected = std::regex_replace(reflected, std::regex(R"(\byourself\b)", std::regex_constants::icase), "__MYSELF__");
    reflected = std::regex_replace(reflected, std::regex(R"(\byour\b)", std::regex_constants::icase), "__MY__");
    reflected = std::regex_replace(reflected, std::regex(R"(\byours\b)", std::regex_constants::icase), "__MINE__");
    reflected = std::regex_replace(reflected, std::regex(R"(\byou\b)", std::regex_constants::icase), "__I__");
    reflected = std::regex_replace(reflected, std::regex(R"(\bare\b)", std::regex_constants::icase), "__AM__");

    reflected = std::regex_replace(reflected, std::regex("__YOURSELF__"), "yourself");
    reflected = std::regex_replace(reflected, std::regex("__YOUR__"), "your");
    reflected = std::regex_replace(reflected, std::regex("__YOURS__"), "yours");
    reflected = std::regex_replace(reflected, std::regex("__YOU_OBJECT__"), "you");
    reflected = std::regex_replace(reflected, std::regex("__YOU_SUBJECT__"), "you");
    reflected = std::regex_replace(reflected, std::regex("__ARE__"), "are");
    reflected = std::regex_replace(reflected, std::regex("__MYSELF__"), "myself");
    reflected = std::regex_replace(reflected, std::regex("__MY__"), "my");
    reflected = std::regex_replace(reflected, std::regex("__MINE__"), "mine");
    reflected = std::regex_replace(reflected, std::regex("__I__"), "I");
    reflected = std::regex_replace(reflected, std::regex("__AM__"), "am");

    return reflected;
}

// Finds the first matching rule, reflects its captured text, and creates a reply.
bool GenericResponses::generate(const std::string& input, std::string& response) const {
    std::smatch match;
    bool foundMatch = false;

    // Continue through the list so a later, more specific category rule can
    // replace an earlier broad generic-verb match.
    for (const ResponseRule& rule : rules) {
        if (std::regex_match(input, match, rule.pattern)) {
            const std::string reflectedCapture = reflectPronouns(match[1].str());
            response = rule.responseTemplate;

            const std::size_t marker = response.find("$1");
            if (marker != std::string::npos) {
                response.replace(marker, 2, reflectedCapture);
            }
            foundMatch = true;
        }
    }

    return foundMatch;
}

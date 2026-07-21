myELIZA - Project 2 Final Submission

Student:
Andy Mukanya

DESCRIPTION
myELIZA is a primitive ELIZA-style chatbot written in C++. The program reads
complete user statements, recognizes more than 50 regular-expression patterns,
reflects pronouns in captured text, and generates category-appropriate replies.
It also detects repeated input, always provides a response, and ends when the
user enters "bye".

IMPLEMENTED FEATURES
- More than 50 ordered regex response rules
- Generic verb responses
- Wellbeing and emotion responses
- Love and relationship responses
- Education responses
- Financial concern responses
- Entertainment and interest responses
- Concern and uncertainty responses
- Pronoun reflection using regex_replace()
- Pattern recognition using regex_match()
- Question detection using regex_search()
- Repeated-input detection using conversation history
- Input trimming and whitespace normalization
- Graceful termination when the user enters "bye"
- A default response when no specialized pattern matches

FILES
main.cpp
    Contains only main() and starts the chatbot.

Eliza.h / Eliza.cpp
    Controls the conversation loop, normalizes input, recognizes "bye",
    chooses generated or default responses, and displays output.

ConversationHistory.h / ConversationHistory.cpp
    Stores prior user inputs and detects repeated statements without regard to
    letter case or final punctuation.

GenericResponses.h / GenericResponses.cpp
    Stores the regex rules, matches user input, reflects pronouns, and builds
    ELIZA-style responses.

COMPILATION
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Eliza.cpp \
    ConversationHistory.cpp GenericResponses.cpp -o myELIZA

RUNNING
./myELIZA

Type a complete sentence at the "You:" prompt. Type "bye" to quit.

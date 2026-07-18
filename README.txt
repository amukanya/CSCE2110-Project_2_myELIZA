myELIZA - Project 2 Milestone 1

Group Member:
Andy Mukanya

DESCRIPTION
This milestone implements major functionality component 1, generic verb responses, and repeated-answer detection. The chatbot uses C++ regular expressions to recognize statements, capture text, transform pronouns, and generate an ELIZA-style response. It always replies and ends when the user enters bye.

FILES
main.cpp - Contains only main().
Eliza.h / Eliza.cpp - Conversation loop, input normalization, bye detection, and default replies.
ConversationHistory.h / ConversationHistory.cpp - Stores previous inputs and detects repeats.
GenericResponses.h / GenericResponses.cpp - Generic verb regex rules and pronoun reflection.

COMPILATION
g++ -std=c++17 -Wall -Wextra -pedantic *.cpp -o myELIZA

RUNNING
./myELIZA

Type complete sentences at the You: prompt. Type bye to quit.

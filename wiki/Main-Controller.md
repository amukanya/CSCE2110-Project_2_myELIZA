# Main Controller

## Purpose

The Main Controller manages the lifetime of the chatbot and keeps the components working in the correct order. It greets the user, requests input, ends the program when appropriate, and displays each response.

## Data Storage and Maintenance

The controller owns the conversation-history and category-response objects. It passes strings between components. The program entry point remains in `main.cpp`, while controller behavior is declared in `Eliza.h` and defined in `Eliza.cpp`.

## Functionality

The controller calls `getline`, normalizes the sentence, checks for `bye`, asks Conversation History whether the answer is repeated, and requests a category response. If no category matches, it calls the default-response function and then loops.

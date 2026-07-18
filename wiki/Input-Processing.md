# Input Processing

## Purpose

Input Processing prepares keyboard input for reliable comparison and regular-expression matching. It also identifies empty input and the termination command.

## Data Storage and Maintenance

The component handles one `string` at a time. It removes outside whitespace and collapses repeated spaces with `regex_replace`. Conversation History is responsible for permanent storage.

## Functionality

Input is obtained with `getline`. A case-insensitive `regex_match` recognizes `bye` with optional punctuation. Empty input receives a prompt, while valid input continues to history checking.

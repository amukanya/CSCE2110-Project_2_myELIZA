# Conversation History

## Purpose

Conversation History detects when the user repeats an earlier answer and encourages a different response.

## Data Storage and Maintenance

Previous inputs are stored in a `vector<string>`. For comparison, the text is converted to lowercase and ending punctuation is removed.

## Functionality

`hasSeen` compares the current canonical input with stored inputs. `remember` appends a new statement only after it passes the duplicate check.

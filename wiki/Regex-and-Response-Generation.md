# Regex and Response Generation

## Purpose

This component converts recognized statements into ELIZA-style replies using the required C++ regex tools.

## Data Storage and Maintenance

Rules are stored as `ResponseRule` objects containing a `regex` and response-template string. Temporary `smatch` data holds capture groups.

## Functionality

Rules are tested with `regex_match`. `regex_replace` inserts captured text into a template and then performs pronoun reflection. `regex_search` handles broad clues such as a question mark.

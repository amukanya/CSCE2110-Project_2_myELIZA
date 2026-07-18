# Generic Verbs

## Purpose

This component handles first-person statements using verbs such as am, feel, have, want, need, think, know, remember, can, will, should, and did. It is the Milestone 1 functionality.

## Data Storage and Maintenance

A vector of `ResponseRule` objects stores the patterns and templates. Each pattern captures the words after the verb.

## Functionality

`generate` tests each pattern, creates the response with `regex_replace`, reflects pronouns, and returns the completed reply.

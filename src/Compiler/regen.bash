#!/bin/bash
bisonc++ --debug parser.y && flexc++ scanner.lex

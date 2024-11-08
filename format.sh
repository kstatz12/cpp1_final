#!/usr/bin/env sh

find . -regex '.*\.\(cpp\|hpp\|c\|h\)' -exec clang-format -i {} \;

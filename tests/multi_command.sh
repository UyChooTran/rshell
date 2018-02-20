#!/bin/sh
../bin/rshell << 'EOF'
ls -a; echo hello; mkdir test
ls -a; echo hello && mkdir test || echo world; git status
ls ls && echo hi
ls ls || echo hi
exit
EOF

#!/bin/sh
../bin/rshell << 'EOF'
ls ls && exit; echo hello
ls -a; exit
exitt || exit
exit
EOF

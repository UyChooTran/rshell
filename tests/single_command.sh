#!/bin/sh

../bin/rshell << 'EOF'
ls -a;
echo hello
mkdir test
ls -l
ls
exit
EOF

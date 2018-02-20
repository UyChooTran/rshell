#!/bin/sh
../bin/rshell << 'EOF'
echo hello #how are ypu 
ls -a; # echo pizza
#i like mangos
ls -l && echo hi ; echo #something
exit
EOF

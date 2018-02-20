#!/bin/sh

../bin/rshell << 'EOF'
echo Bye world
echo We are testing rshell
exit
EOF

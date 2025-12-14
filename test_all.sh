#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
echo "--- fork_demo ---"
./bin/fork_demo || true
echo "--- wait_demo ---"
./bin/wait_demo || true
echo "--- pipe_communication ---"
./bin/pipe_communication || true
echo "--- ls_wc_pipe ---"
./bin/ls_wc_pipe || true
echo "--- sum_even_odd (n=10) ---"
printf "10\n" | ./bin/sum_even_odd || true
echo "--- execl_demo ---"
./bin/execl_demo || true
echo "--- tests complete ---"

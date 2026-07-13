#!/usr/bin/env bash

set -euo pipefail

base_url="${1:-http://127.0.0.1:8080}"

echo "Health check"
curl -fsS "${base_url}/health"
echo

echo "Create task"
created="$(curl -fsS -X POST "${base_url}/tasks" \
    -H 'Content-Type: application/json' \
    -d '{"title":"Smoke test","description":"Exercise every TaskHub endpoint"}')"
echo "${created}"
task_id="$(jq -r '.data.id' <<<"${created}")"

echo "List tasks"
curl -fsS "${base_url}/tasks?status=todo"
echo

echo "Get task ${task_id}"
curl -fsS "${base_url}/tasks/${task_id}"
echo

echo "Update task ${task_id}"
curl -fsS -X PATCH "${base_url}/tasks/${task_id}" \
    -H 'Content-Type: application/json' \
    -d '{"status":"doing"}'
echo

echo "Read statistics"
curl -fsS "${base_url}/stats"
echo

echo "Delete task ${task_id}"
curl -fsS -X DELETE "${base_url}/tasks/${task_id}"
echo

echo "All TaskHub API smoke checks passed."

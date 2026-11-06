#!/bin/bash

set -e

PROGRAMA="$1"
ENTRADA="$2"
ESPERADO="$3"

SAIDA=$(mktemp)

trap 'rm -f "$SAIDA"' EXIT

"$PROGRAMA" < "$ENTRADA" > "$SAIDA"

if diff -u "$ESPERADO" "$SAIDA"; then
    echo "Teste passou =)"
else
    echo "Teste falhou :("
    exit 1
fi
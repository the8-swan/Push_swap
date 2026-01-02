#!/usr/bin/env fish


set start_time (date +%s)
set max_seconds 60

set max_moves 0
set max_arg ""

while true
    set now (date +%s)
    set elapsed (math $now - $start_time)

    if test $elapsed -ge $max_seconds
        echo "⏱️  Time limit reached (1 minute)."
        echo "🏆 MAX MOVES FOUND: $max_moves"
        echo "ARG=$max_arg"
        exit 0
    end

    set ARG (shuf -i 1-932342 -n 100)
    set count (./p $ARG | wc -l)

    echo "Moves: $count | Max so far: $max_moves"

    if test $count -gt $max_moves
        set max_moves $count
        set max_arg "$ARG"
    end

    if test $count -gt 700
        echo "🚨 LIMIT BREACHED (>5500)"
        echo "Moves: $count"
        echo "ARG=$ARG"
        exit 1
    end
end
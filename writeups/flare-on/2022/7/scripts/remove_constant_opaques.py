import sys
import re

if_pattern = re.compile("if\s+\((\d+n?)\)")

truth = dict()

with open("truth.txt", "r") as f:
    lines = f.readlines()
    for line in lines:
        parts = line.strip().split(' ')
        truth[parts[0]] = parts[1] == 'true'


with open("anode.no_constant_opaques.js", "w") as f:
    lines = open("anode.edit.js", "r").readlines()

    is_filtering = False
    is_moving = False
    skip_next_brace = False

    for line in lines:
        
        skip_line = False
        match = if_pattern.search(line)
        if match:
            if not truth[match.group(1)]:
                is_filtering = True
            else:
                is_moving = True
            skip_line = True

        elif is_filtering and '}' in line:
            skip_line = True
            is_filtering = False
            skip_next_brace = 'else' in line 

        elif is_moving and 'else' in line:
            # f.write('}\n')
            is_filtering = True
            is_moving = False

        elif skip_next_brace and '}' in line:
            skip_line = True
            skip_next_brace = False


        if is_filtering:
            skip_line = True

        if not skip_line:
            f.write(line)
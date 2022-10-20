import math
import re

random_index = 0
case_pattern = re.compile("case (\d+):")
if_random_pattern = re.compile("if \(Math.random\(\) < ([\d\.]+)\)")


with open("random.txt", "r") as f:
    random = [float(x.strip()) for x in f.readlines()]


with open("floors.txt", "r") as f:
    floors = [float(x.strip()) for x in f.readlines()]


def next_random():
    global random_index
    value = random[random_index]
    random_index += 1
    return value


with open("state_order.txt", "r") as f:
    state_order = [int(x.strip()) for x in f.readlines()]


with open("anode.no_constant_opaques.js", "r") as f:
    case_blocks = dict()
    current_block = None
    for line in f.readlines():
        if "default:" in line:
            break

        match = case_pattern.search(line)
        if match:
            label = int(match.group(1))
            current_block = []
            case_blocks[label] = current_block
        elif current_block is not None:
            current_block.append(line)


with open("anode.reordered.js", "w") as f:

    f.write("""
const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
  });
  
  readline.question(`Enter flag: `, flag => {
    readline.close();
    if (flag.length !== 44) {
      console.log("Try again.");
      process.exit(0);
    }
    var b = [];
    for (var i = 0; i < flag.length; i++) {
      b.push(flag.charCodeAt(i));
    }
""")

    for state in state_order:
        _ = next_random() # random call in switch

        block = case_blocks[state]
        is_filtering = False
        is_moving = False
        skip_next_brace = False
        
        for line in block:
            skip_line = False

            match = if_random_pattern.search(line)
            if match:
                skip_line = True

                threshold = float(match.group(1))
                if next_random() < threshold:
                    is_moving = True
                else:
                    is_filtering = True

            elif is_filtering and '}' in line:
                skip_line = True
                is_filtering = False
                skip_next_brace = 'else' in line 

            elif is_moving and 'else' in line:
                is_filtering = True
                is_moving = False

            elif skip_next_brace and '}' in line:
                skip_line = True
                skip_next_brace = False

            if 'continue' in line or 'break' in line or 'state' in line:
                skip_line = True

            if is_filtering:
                skip_line = True
                
            final_line = line
            if 'Math.random()' in line and not skip_line:
                value = next_random() # random call
                final_line = final_line.replace("Math.random()", str(value))

            if 'Math.floor' in line and not skip_line:
                call_index = final_line.index('Math.floor(')
                argument_idx = call_index + 11
                argument_end_idx = final_line.index(')', argument_idx)
                result = math.floor(eval(final_line[argument_idx:argument_end_idx]))
                final_line = final_line[:call_index] + str(result) + final_line[argument_end_idx+1:]


            if not skip_line:
                f.write(final_line)

    f.write("""
        var target = [106, 196, 106, 178, 174, 102, 31, 91, 66, 255, 86, 196, 74, 139, 219, 166, 106, 4, 211, 68, 227, 72, 156, 38, 239, 153, 223, 225, 73, 171, 51, 4, 234, 50, 207, 82, 18, 111, 180, 212, 81, 189, 73, 76];
        console.log(b);
        if (b.every((x,i) => x === target[i])) {
        console.log('Congrats!');
        } else {
        console.log('Try again.');
        }
    });
    """)
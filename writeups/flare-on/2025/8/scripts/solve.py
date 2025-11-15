def magic(x: int) -> int:
    a = (x ^ 0x3d) & 0xFFFFFFFF
    b = (a + (a << 3)) & 0xFFFFFFFF
    c = (b ^ (b >> 4)) & 0xFFFFFFFF
    d = (c * 0x27D4EB79) & 0xFFFFFFFF
    e = (d ^ (d >> 0xf)) & 0xFFFFFFFF
    f = (e >> 4) & 0xFFFFFFFF
    return f

def checksum(s: bytes) -> int:
    checksum = 0
    for index, c in enumerate(s):
        i = index + 1
        a = magic(i)
        b = magic(i << 8 | c)
        magic_result = (a * b) & 0xFFFFFFFFFFFFFFFF
        checksum = (checksum + magic_result) & 0xFFFFFFFFFFFFFFFF

    return checksum

MASK = 0xFFFFFFFFFFFFFFFF

# Precompute all possible contributions for each character:
A = [magic(i) for i in range(1,26)]
B = [[magic((i<<8)| (0x30+d)) for d in range(10)] for i in range(1,26)]
C = [[(A[i]*B[i][d]) & MASK for d in range(10)] for i in range(25)]

# Determine the valid bounds for each position in the pass code.
ranges = [(0, 0)] * 26 # 25 + 1 (last range contribution 0)
for i in range(24, -1, -1):
    ranges[i] = (
        (ranges[i+1][0] + min(C[i])) & MASK,
        (ranges[i+1][1] + max(C[i])) & MASK
    )

# Define target
target = 0x0bc42d5779fec401

# DFS stack [(position, current_path, tentative_sum)]
agenda = [(0, "", 0)]
while agenda:
    position, current_path, current_sum = agenda.pop()

    if position == 25:
        # Found solution:
        print(current_path)
        continue

    # Try all digits
    for candidate_digit in range(10):
        # Compute the new tentative sum.
        new_sum = (current_sum + C[position][candidate_digit]) & MASK

        # Check if is in within expected range.
        next_range = ranges[position+1]
        low = (next_range[0] + new_sum) & MASK
        high = (next_range[1] + new_sum) & MASK

        possible = low <= target <= high
        if not possible:
            continue

        # This is a potential path, move to the next digit.
        agenda.append((position + 1, current_path + str(candidate_digit), new_sum))

print("Done")

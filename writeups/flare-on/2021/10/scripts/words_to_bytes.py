import word_lists
import sys 

def words_to_bytes(table, provided):
    result = bytearray()
    for p in provided:
        if p.startswith('and '):
            p = p[4:]
        result.append(table.index(p))
    return result

if len(sys.argv) != 3:
    print(f"Usage: {sys.argv[0]} <data_type> <path>")
    sys.exit(0)

data_type = sys.argv[1]
path = sys.argv[2]

provided = open(path, "r").read()
result = bytearray()

provided = provided.replace(":dung3onm4st3r13!user@127.0.0.1 ", '')
provided = provided.replace("PRIVMSG #dungeon :", '')
provided = provided.replace("\n", '')
provided = provided.replace("\r", '')
provided = provided.replace('.', '')

if data_type == "potion":
    idx = provided.find("you must combine ")
    if idx >= 0:
        provided = provided[idx+17:]
    provided = provided.split(', ')
    result = words_to_bytes(word_lists.INGREDIENTS, provided)

elif data_type == "dungeon":
    idx = provided.find("It is ")
    if idx >= 0:
        provided = provided[idx+6:]
    provided = provided.split(', ')
    result = words_to_bytes(word_lists.DUNGEON_DESCRIPTIONS, provided)

elif data_type == "fight":
    individual = provided.split("I cast ")
    for p in individual:
        if not p:
            continue

        idx = p.find(" on the ")
        if idx != -1:
            result.append(word_lists.SPELLS.index(p[:idx]))

        idx1 = p.find(" for ")
        idx2 = p.find(" damage")
        if idx1 != -1 and idx2 != -1:
            dmg = p[idx1+5:idx2].replace(' raw', "")
            if 'd' in dmg:
                dmg = dmg.split('d')
                result.append(int(dmg[0]))
                result.append(int(dmg[1]))
            else:
                result.append(int(dmg))

open(path + ".decoded", "wb").write(result)

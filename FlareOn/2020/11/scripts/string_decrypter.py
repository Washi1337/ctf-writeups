import struct
import sys

def compute_sid_hash(sid):
    splits = sid.split('-')

    seed = int(splits[int(splits[2])]) << 32
    for i in range(4, len(splits) - 1):
        seed = (seed + int(splits[i])) & 0xFFFFFFFFFFFFFFFF
    seed ^= 0xedb88320edb88320
    return seed

class StringDecrypter:

    def __init__(self, sid):
        words = "old new current version process thread id identity task disk keyboard monitor class archive drive message link template logic protocol console magic system software word byte timer window scale info char calc map print list section name lib access code guid build warning save load region column row language date day false true screen net info web server client search storage icon desktop mode project media spell work security explorer cache theme solution"
        self.words = words.split(' ')
        self.seed = compute_sid_hash(sid)
        
    def get_string(self, idx, c):
        selected_words = []
        counter = 0
        while idx != 0 and counter < 8:
            x = (self.seed + counter + (idx & 0xFF)) & 0xFFFFFFFFFFFFFFFF
            x = (x ^ (x >> 12)) & 0xFFFFFFFFFFFFFFFF
            x = (x ^ (x << 25)) & 0xFFFFFFFFFFFFFFFF
            x = (x ^ (x >> 27)) & 0xFFFFFFFFFFFFFFFF
            y = (x * 0x2545F4914F6CDD1D) & 0xFFFFFFFFFFFFFFFF
            x = (y & 0xFFFF) % len(self.words)
            counter += 2

            selected_word = self.words[x]

            z = (y >> 0x20)
            if z & 1 != 0:
                z &= 0xFFFF
                z %= len(selected_word) - 1
                z += 2
                selected_word = selected_word[:z]

            selected_words.append(selected_word)
            idx >>= 8

        result = ""
        for i in range(len(selected_words)):
            word = selected_words[i]
            if (c >> i) & 1 != 0:
                word = word[0].upper() + word[1:]
            result += word
        return result
    
if __name__ == "__main__":
    
    original_sid = "S-1-5-21-3823548243-3100178540-2044283163-1006"
    decrypter = StringDecrypter(original_sid)

    index = int(sys.argv[1], 16)
    capitalization = int(sys.argv[2])

    print(decrypter.get_string(index, capitalization))
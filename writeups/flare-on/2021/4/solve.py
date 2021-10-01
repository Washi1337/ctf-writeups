
mapping = dict()

for i in range(1, 17):
    data = open(f"mmb/Script{i}", "r").readline()
    part = data.split('=')[0][:-1]
    components = data.split("'")[1].split(':')
    
    if components[0] not in mapping:
        mapping[components[0]] = []
    
    mapping[components[0]].append((i, part, components[1]))


for k,v in mapping.items():
    print(k)
    for x in sorted(v, key=lambda y: y[1]):
        print(x)
    print("")

import tqdm
import math
from sage.all import *
from Crypto.Util.number import *


# From binary
Q = 30937339651019945892244794266256713890440922455872051984768764821736576084296075471241474533335191134590995377857533
A = 24699516740398840043612817898240834783822030109296416539052220535505263407290501127985941395251981432741860384780927
B = 24561086537518854907476957344600899117700350970429030091546712823181765905950742731855058586986320754303922826007424
GX = 1305488802776637960515697387274764814560693662216913070824404729088258519836180992623611650289275235949409735080408
GY = 2840284555446760004012395483787208388204705580027573689198385753943125520419959469842139003551394700125370894549378

# From pcap
X1 = 3902729749136290727021456713077352817203141198354795319199240365158569738643238197536678384836705278431794896368793
Y1 = 8229109857867260486993831343979405488668387983876094644791511977475828392446562276759399366591204626781463052691989

X2 = 27688886377906486650974531457404629460190402224453915053124314392088359043897605198852944594715826578852025617899270
Y2 = 20559737347380095279889465811846526151405412593746438076456912255094261907312918087801679069004409625818172174526443

# Set up params
E = EllipticCurve(GF(Q), [A,B])
G = E((GX, GY))

# Observed points to discrete log.
P1 = E((X1, Y1))
P2 = E((X2, Y2))

# Compute factors of order
order = E.order()
print("order:", order)
factors = factor(order)
print("factors:", list(factors))

# Try each subgroup
crt_factors = []
crt_solutions = []
for f, _ in factors:
    # ignore big factor
    if f > 10000000000:
        continue
    
    print("Trying factor", f)

    # Divide out the factor
    new_generator = G * (order // f)
    new_target = P1 * (order // f)

    # Try naive discrete log on this order
    current = new_generator
    for i in range(1, f):
        current += new_generator
        if current == new_target:
            print("Found:", i+1)
            #print((i+1)*new_generator == new_target)
            crt_solutions.append(i+1)
            crt_factors.append(f)
            break
    else:
        print("Not found!")

# Find partial solution via crt
d_1 = crt(crt_solutions, crt_factors) 
print("Found d_1:", d_1)

# Brutefore remainder
p = product(crt_factors)
for i in tqdm.tqdm(range(2**16)):
    if (d_1 + i * p) * G == P1:
        print("Found", i)
        break
else:
    print("Not found")
    
# solution
d = (d_1 + i * p)

recovered = d * G
print("d:", d)
assert recovered == P1

# d: 168606034648973740214207039875253762473

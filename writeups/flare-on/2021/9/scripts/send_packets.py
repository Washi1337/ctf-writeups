import struct 
import time
from scapy.all import *

def send_packet(cmd, payload):
	packet = bytearray()
	packet.extend(struct.pack("I", cmd))
	packet.extend(struct.pack("I", len(payload)))
	packet.extend(payload)
	pkt = IP(src="127.0.0.1",dst="127.0.0.1",flags=0x4)/UDP(sport=13371,dport=0x1104)/packet
	send(pkt)

payloads = [
	b"L0ve\x00",
	b"s3cret\x00",
	b"5Ex\x00",
	b"g0d\x00"
]

for i in range(4):
	send_packet(2,  payloads[i])
	time.sleep(0.5)

send_packet(3, b"MZ")

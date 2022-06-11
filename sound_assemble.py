#örnek ses frekansı birleştirme
from matplotlib import pyplot as plt
from math import pi,sin
import struct

SAMPLE_RATE=44100
BIT_DEPTH=16

class oscillator:
	def __init__(self):
		self.f=0
		self.amp=0
		self.offset=0
		self.ang=0
	def set(self,f,a):
		self.amp=a
		self.f=f
		self.offset=2*pi*self.f/SAMPLE_RATE
	def p(self):
		s=self.amp*sin(self.ang)
		self.ang+=self.offset
		return s
osc=oscillator

k=[]
k2=[]
k3=[]

freq1=523.26
freq2=1046.5

d=osc()
d.set(freq1,.5)

d2=osc()
d2.set(freq2,0.5)

for a in range(SAMPLE_RATE*4):
	k+=[d.p()]
	k2+=[d2.p()]
	k3+=[ (k[a]+k2[a])/2 ]#frekans ortalamalarını alıp birleştir


	
plt.plot(k[:200],"--r",
	 k2[:200],"--b",
	 k3[:200],"-g")
plt.xlabel("periot(T)")
plt.ylabel("amplitude?")

plt.legend(["freq 1:{}".format(freq1),"assembled freq(mean)","freq 2:{}".format(freq2)])
plt.show()

"""
#https://docs.python.org/3/library/struct.html#format-characters
with open("ses.wav","bw") as f:
        f.write(struct.pack("4s",b"RIFF"))
        f.write(struct.pack("4s",b"----"))
        f.write(struct.pack("4s",b"WAVE"))
        f.write(struct.pack("4s",b"fmt "))
        f.write(struct.pack("i",16))#16*4 byte(32 bit) >16=size of all above
        
        f.write(struct.pack("H",1))
        f.write(struct.pack("H",2))#channels
        f.write(struct.pack("f",SAMPLE_RATE))#sample rate
        f.write(struct.pack("f",(SAMPLE_RATE*BIT_DEPTH*2/8)))#bitrate
        f.write(struct.pack("H",2))
        f.write(struct.pack("H",BIT_DEPTH))
        f.write(struct.pack("4s",b"data"))
        f.write(struct.pack("4s",b"----"))

        pos0=f.tell()
        maxAMP=2**(BIT_DEPTH-1)-1
        for a in k3:
                wrote=a*maxAMP
                f.write(struct.pack("h",int(wrote)))

        pos_fin=f.tell()
        f.seek(pos0-4)
        f.write( struct.pack("i",(pos_fin-pos0)) )
        
        f.seek(4)
        f.write(struct.pack("i",(pos_fin-8)))
print("{}b >>{}kb".format((pos_fin-8),(pos_fin-8)/1024))
print("FIN")
"""

fc=5000 ;
fm=500 ;
Vc=9 ;
Vm= 4.5 ;
m=Vm/Vc;
t=0:0.01:2*10;
subplot(311);
plot(Vm*sin(2*3.14*fm*t));
subplot(312);
plot(Vc*sin(2*3.14*fc*t));

Vam=Vc*(1+m*(sin(2*3.14*fm*t))).*(sin(2*3.14*fc*t));
subplot(313);
plot(Vam);

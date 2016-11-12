Vc=9;
fc=100;
fm=50;
t=0:0.001:0.5;
m=0.5;

subplot(311);
plot(Vc*(cos(2*3.14*fc*t)+m*(sin(2*3.14*fm*t))));
subplot(312);
plot(Vc*(cos(2*3.14*fc*t)+1*(sin(2*3.14*fm*t))));
subplot(313);
plot(Vc*(cos(2*3.14*fc*t)+2*(sin(2*3.14*fm*t))));

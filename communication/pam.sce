Vp=3;
Vm=4.5;
t=0:0.01:2*10;

Vm = Vm*(sin(2*3.14*t)) ;
subplot(311);
plot(Vm);

subplot(312);
plot(Vp*Vm*(sin(2*3.14*t)));

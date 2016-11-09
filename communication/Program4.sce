vm=10;
fm=10;
t=0:0.001:1;
noise=rand(1,1001);
plot(vm*sin(2*3.14*fm*t)+noise);

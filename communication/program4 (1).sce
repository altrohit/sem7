fm=10;
Vm=100;
t=0:0.001:1;
k=1.38*10^(-23);
T=range(300,350);
//df=range(100,1000);
df=10^(24);
R=1:0.1:101;
vn=sqrt(4*R*k*T*df);
vm=Vm*sin(2*3.14*fm*t);
//subplot(3 1 1);
plot(R,vm+vn);


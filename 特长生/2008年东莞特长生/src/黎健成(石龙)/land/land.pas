program land;
var i,n,z:longint;
begin
assign(input,'land.in');
reset(input);
read(n);
close(input);
n:=n*n;z:=1;
for i:=1 to n do z:=z*2;
z:=z-1;
assign(output,'land.out');
rewrite(output);
write(z);
close(output);
end.

program land;
var
f1,f2:text;
s,k:longint;
n,i:integer;
begin
assign(f1,'land.in');
assign(f2,'land.out');
reset(f1);
rewrite(f2);
read(f1,n);
k:=1;
s:=s+k;
for i:=2 to sqr(n) do
begin
k:=k*2;
s:=s+k;
end;
write(f2,s);
close(f1);
close(f2);
 end.


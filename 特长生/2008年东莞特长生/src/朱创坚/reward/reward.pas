var n,b,c:array[1..10000]of integer;
m,i,a,g,h,d,f:integer;
begin
assign(input,'reward.in');reset(input);
assign(output,'reward.out');rewrite(output);
readln(a,m);
for i:=1 to a do
n[i]:=100;
for i:=1 to m do begin
readln(d,f);
n[d]:=n[f]+1;
end;
h:=0;
for i:=1 to a do
h:=h+n[i];
if g=20001 then write('-1')
else write(h);
close(input);close(output);
end.
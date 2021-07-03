var a,b,c,d,e,f,g,n,m,max,max1:longint;
h:array[1..100] of longint;
i,j:array[1..25500] of 0..1;
begin
assign(input,'stamps.in');
reset(input);
assign(output,'stamps.out');
rewrite(output);
read(n,m);
for a:=1 to m do
begin read(h[a]);if h[a]>max then max:=h[a];end;
max:=max*n;
for a:=1 to m do
i[h[a]]:=1;
for a:=2 to n do begin for c:=1 to max do j[c]:=0;
for b:=1 to m do
for c:=1 to max do
if i[c]=1 then j[h[b]+c]:=1;
for c:=1 to max do if j[c]=1 then i[c]:=1;
end;
c:=0;max1:=0;
for d:=1 to max do if i[d]<>0 then inc(c)
else begin if c>max1 then max1:=c;c:=0;         end;
write(max1);
close(input);close(output);
end.
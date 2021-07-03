var a,b,c,d,e,f,g:longint;
h,i,j:array[1..200] of integer;
begin
assign(input,'sort.in');
reset(input);
assign(output,'sort.out');
rewrite(output);
read(a);
for b:=1 to a do
begin read(h[b],i[b]);j[b]:=b;end;
for c:=1 to a-1 do
for d:=c+1 to a do
 if i[c]<i[d]
  then
  begin
  e:=i[c];i[c]:=i[d];i[d]:=e;
  e:=h[c];h[c]:=h[d];h[d]:=e;
  end;
for c:=1 to a-1 do
for d:=c+1 to a do
 if (i[c]=i[d]) and (h[c]>h[d])
  then
  begin
  e:=i[c];i[c]:=i[d];i[d]:=e;
  e:=h[c];h[c]:=h[d];h[d]:=e;
  end;
for c:=1 to a-1 do
for d:=c+1 to a do
if i[c]=i[d] then j[d]:=j[c];
for c:=1 to a do
writeln(h[c],' ',i[c],' ',j[c]);
close(input);close(output);
end.
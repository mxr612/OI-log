        var n,j,k,i,z:integer;  a,ti,ai,bi:array[0..1000000] of integer;
  begin
  assign(input,'work.in');
reset(input);
read(n);
for i:=1 to n do readln(ti[i],ai[i],bi[i]);
close(input); i:=1;
while i<=n do
begin
a[i]:=0;
a[i]:=ti[i]+a[i];
for k:=1 to n do if a[i]<=ai[k] then a[i]:=a[i]+ti[k];
inc(i);
end;
i:=i-1;
for j:= 2 to n do
for i:= 1 to n-1 do
begin
if a[i]>a[j] then
begin
z:=a[i];a[i]:=a[j];a[j]:=z;
end; end;
for i:=1 to n do
if a[i]<>0 then
begin
k:=a[i];
break;
end;
assign(output,'work.out');
rewrite(output);
write(k);
close(output);
end.

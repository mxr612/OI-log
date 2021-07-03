var a,b,c:array[1..100000] of integer;
n,i,j,m,k,d:integer;
begin
assign(input,'num.in');reset(input);
assign(output,'num.out');rewrite(output);
read(n);
for i:=1 to n do begin
read(a[i]);b[i]:=i;
end;
readln;
read(k);
for i:=1 to n do
c[i]:=a[i];
for i:=1 to n-1 do
for j:=i+1 to n do
if a[i]<a[j] then begin
m:=a[i];a[i]:=a[j];a[j]:=m;
end;
for i:=1 to n do
if a[k]=c[i] then d:=b[i];
writeln(a[k]);
write(d);
close(input);close(output);
end.
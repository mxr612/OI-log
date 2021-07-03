program num;
var a:array[1..100] of integer;
n,k,z,i,j:integer;
begin
assign(input,'num.in');
reset(input);
readln(n);
for i:=1 to n do read(a[i]);
readln;
read(k);
close(input);
begin
for i:=2 to n do
for j:=1 to n-1 do
begin
if a[i]>a[j] then
begin
z:=a[j];a[j]:=a[i];a[i]:=z;
end;
end;
end;
assign(output,'num.out');
rewrite(output);
write(a[k]);
close(output);
end.

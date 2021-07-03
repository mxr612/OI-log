program num;
var
f1,f2:text;
a,b:array[1..100]of integer;
i,n,j,k,t:integer;
begin
assign(f1,'num.in');
assign(f2,'num.out');
reset(f1);
rewrite(f2);
readln(f1,n);
for i:=1 to n do
read(f1,a[i]);
read(f1,k);
for i:=1 to n do
b[i]:=a[i];
for i:= 1 to n-1 do
 for j:=i+1 to n do
  if a[j]>a[i] then
   begin
   t:=a[i];
   a[i]:=a[j];
   a[j]:=t;
   end;
 for i:=1 to n do
 if a[k]=b[i] then
              begin
              writeln(f2,a[k]);
              write(f2,i);
              end;
close(f1);
close(f2);
 end.

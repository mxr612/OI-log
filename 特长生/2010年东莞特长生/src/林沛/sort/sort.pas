program sort;
var
x,i,j,k,n:integer;
a:array[1..201,1..2]of integer;
b:array[1..201] of integer;
begin
assign(input,'sort.in');reset(input);
assign(output,'sort.out');rewrite(output);
read(n);
for i:=1 to n do
for j:=1 to 2 do
read(a[i,j]);
for i:=1 to n do
for j:=i to n do
if a[i,2]<a[j,2] then
begin
k:=a[i,2];
a[i,2]:=a[j,2];
a[j,2]:=k;
x:=a[i,1];
a[i,1]:=a[j,1];
a[j,1]:=x;
end;
 if (a[i,2]=a[j,2]) and( a[i,1]>a[j,1] ) then
 begin
k:=a[i,2];
a[i,2]:=a[j,2];
a[j,2]:=k;
x:=a[i,1];
a[i,1]:=a[j,1];
a[j,1]:=x;
end;

 b[1]:=1;
for i:=2 to n do
begin
if a[i,2]=a[i-1,2]  then b[i]:=b[i-1]
else b[i]:=i;
end;
for j:=1 to n do
writeln(a[j,1],' ',a[j,2],' ',b[j]);
close(input);
close(output);
end.

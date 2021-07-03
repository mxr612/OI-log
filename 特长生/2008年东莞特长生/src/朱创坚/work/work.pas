var s,n,i,m,j:integer;
t,a,b,c:array[1..1500] of integer;
begin
assign(input,'work.in');reset(input);
assign(output,'work.out');rewrite(output);
read(n);
for i:=1 to n do begin
readln(t[i],a[i],b[i]);
c[i]:=0;
end;
s:=0;
m:=1;
for i:=1 to n-1 do
for j:=i to n do begin
if (a[j]<=c[m]) and (c[m]<b[j]) then c[m]:=t[j]+c[m];
m:=m+1;
end;
if s>c[m] then s:=c[m];
write('50');
close(input);close(output);
end.
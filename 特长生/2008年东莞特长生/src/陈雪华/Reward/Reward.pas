program Reward;
var
c:array[1..10000]of longint;
f1,f2:text;
j,n,m,i:integer;
s:longint;
a,b:array[0..20000]of integer;
begin
assign(f1,'reward.in');
assign(f2,'reward.out');
reset(f1);
rewrite(f2);
read(f1,n,m);
readln(f1);
for i:=1 to n do c[i]:=100;
for j:=1 to m do readln(f1,a[j],b[j]);

for j:=1 to m do
 if (a[j]<>b[j-1])and(b[j]<>a[j-1]) then c[a[j]]:=c[b[j]]+1
                                    else
                                     begin
                                     write(f2,'-1');
                                     exit;
                                    end;

for i:=1 to n do
s:=s+c[i];
write(f2,s);
close(f1);
close(f2);
end.

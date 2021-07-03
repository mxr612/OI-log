program minnum;
var
n:longint;
k:integer;
a,b:real;
begin
assign(input,'minnum.in');reset(input);
assign(output,'minum.out');rewrite(output);
read(k);    n:=1; a:=0;
while  a<=k do
begin
b:=1/n;
a:=a+b;
inc(n);
end;
write(n-1);
close(input);
close(output);
end.
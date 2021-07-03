var n,s,i,j,k:longint;
begin
assign(input,'land.in');reset(input);
assign(output,'land.out');rewrite(output);
read(n);
s:=1;k:=1;
for i:=1 to (n*n-1) do begin
for j:=1 to i do k:=2*k;
s:=s+k;
k:=1;
end;
write(s);
close(input);close(output);
end.

var i,n,k:longint;
    s:real;
begin
assign(input,'minnum.in');
assign(output,'minnum.out');
reset(input);rewrite(output);
 read(k);
 s:=1;n:=1;
 while s<=k do
  begin
   n:=n+1;
   s:=s+1/n;
  end;
 write(n);
close(input);close(output);
end.
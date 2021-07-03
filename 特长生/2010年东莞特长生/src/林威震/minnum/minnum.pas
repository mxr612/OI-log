var i:longint;
    n,m:real;
begin
 assign(input,'minnum.in');
 assign(output,'minnum.out');
 reset(input);
 rewrite(output);
 read(m);
 n:=1;i:=1;
 while n<=m do
  begin
   inc(i);
   n:=n+1/i;
  end;
 write(i);
 close(input);
 close(output);
end.
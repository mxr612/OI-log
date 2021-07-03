var
  f1,f2:text;
  i,n,j:longint;
  a,s:comp;
  b:real;
begin
  assign(f1,'land.in');
  assign(f2,'land.out');
  reset(f1);
  rewrite(f2);
  read(f1,n);
  a:=1;
  for i:=2 to n*n do
   begin
     s:=1;
     for j:=1 to i-1 do s:=s*2;
     a:=a+s;
   end;
  if n>2 then
   begin
     b:=a/2;
     a:=trunc(b);
   end;
  writeln(f2,trunc(a));
  writeln(trunc(a));
  close(f1);
  close(f2);
end.

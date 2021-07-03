program minnum;
 var
  i,j,k:integer;n:longint;s:real;
 begin
  assign(input,'minnum.in');
  reset(input);
  assign(output,'minnum.out');
  rewrite(output);
  readln(k);
  s:=0.0;n:=0;
  while s<=k do
   begin
    n:=n+1;
    s:=s+1/n;
   end;
  writeln(n);
  close(input);
  close(output);
 end.

var
  k:integer;
  n:longint;
  s:real;
  f1,f2:text;
begin
  assign(f1,'minnum.in');
  assign(f2,'minnum.out');
  reset(f1);
  rewrite(f2);
  readln(f1,k);
  n:=0;
  s:=0;
  repeat
    inc(n);
    s:=s+1/n;
  until s>k;
  writeln(f2,n);
  close(f1);
  close(f2);
end.

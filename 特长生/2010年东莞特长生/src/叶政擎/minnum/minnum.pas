var
  k:real;
  n:longint;

begin
  assign(input,'minnum.in');
  assign(output,'minnum.out');
  reset(input);
  rewrite(output);
  readln(k);
  n:=0;
  repeat
    n:=n+1;
    k:=k-1/n;
  until k<0;
  writeln(n);
  close(input);
  close(output);
end.

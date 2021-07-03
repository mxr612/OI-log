const
  maxn=1000;
var
  n,k:longint;
  s:real;

begin
  assign(input,'minnum.in');
  assign(output,'minnum.out');
  reset(input);
  rewrite(output);
  readln(k);
  n:=0;s:=0;
  while s<=k do
    begin
      n:=n+1;
      s:=s+1/n;
    end;
  writeln(n);
  close(input);
  close(output);
end.

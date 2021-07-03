var
  n,k:longint;
  s:real;
begin
  assign(input,'minnum.in');reset(input);
  assign(output,'minnum.out');rewrite(output);
  readln(k);
  n:=0;s:=0;
  while s<k+0.00000000000001 do
    begin
      inc(n);
      s:=s+1/n;
    end;
  writeln(n);
  close(input);
  close(output);
end.

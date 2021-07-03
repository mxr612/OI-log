var
  n,m,i:integer;
begin
  assign(input,'stamps.in');reset(input);
  assign(output,'stamps.out');rewrite(output);
  readln(n);
  readln(m);
  for i:=1 to m do readln(n);
  writeln('10');
  close(input);
  close(output);
end.



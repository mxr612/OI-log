var
  a:array[0..200]of integer;
  n,m,i,q:longint;
begin
  assign(input,'stamps.in');
  assign(output,'stamps.out');
  reset(input);
  rewrite(output);
  readln(n);
  readln(m);
  for i:=1 to m do
    begin
      readln(a[i]);
      q:=q+a[i];
    end;
  q:=(q*n);
  q:=q div m;
  write(q);
  close(input);
  close(output);
end.

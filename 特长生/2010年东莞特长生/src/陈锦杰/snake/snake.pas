var
  a:array[1..100,1..100]of integer;
  i,j,k,l,n,s:integer;
  f1,f2:text;
begin
  assign(f1,'snake.in');
  assign(f2,'snake.out');
  reset(f1);
  rewrite(f2);
  readln(f1,n);
  i:=1;
  j:=1;
  s:=n*n;
  a[i,j]:=s;
  repeat
    inc(i);
    if i>n then
    begin
      dec(i);
      inc(j);
      l:=n-j;
    end else l:=i-1;
    dec(s);
    a[i,j]:=s;
    for k:=1 to l do
    begin
      dec(i);
      inc(j);
      dec(s);
      a[i,j]:=s;
    end;
    inc(j);
    if j>n then
    begin
      inc(i);
      dec(j);
      l:=n-i;
    end else l:=j-1;
    dec(s);
    a[i,j]:=s;
    for k:=1 to l do
    begin
      inc(i);
      dec(j);
      dec(s);
      a[i,j]:=s;
    end;
  until s=1;
  for i:=1 to n do
  begin
    for j:=1 to n do
      write(f2,a[i,j],' ');
    writeln(f2);
  end;
  close(f1);
  close(f2);
end.

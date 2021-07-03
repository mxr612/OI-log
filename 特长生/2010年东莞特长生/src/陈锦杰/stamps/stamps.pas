var
  a:array[1..25500]of boolean;
  b:array[1..100,1..25500]of integer;
  c:array[1..25500]of integer;
  t:boolean;
  i,j,k,l,n,m,x,y:integer;
  f1,f2:text;
begin
  assign(f1,'stamps.in');
  assign(f2,'stamps.out');
  reset(f1);
  rewrite(f2);
  readln(f1,n);
  readln(f1,m);
  for i:=1 to m do
  begin
    readln(f1,b[1,i]);
    a[b[1,i]]:=true;
  end;
  x:=m;
  for i:=2 to n do
  begin
    l:=0;
    for k:=1 to x do
      for j:=1 to m do
      begin
        t:=false;
        for y:=1 to l do
          if b[i-1,k]+b[1,j]=b[i,y] then
            t:=true;
        if not t then
        begin
          inc(l);
          b[i,l]:=b[i-1,k]+b[1,j];
          a[b[i,l]]:=true;
        end;
      end;
    x:=l;
  end;
  j:=1;
  c[j]:=1;
  for i:=2 to b[1,m]*n do
    if a[i] then
      if a[i-1]then inc(c[j])
               else inc(j);
  k:=c[1];
  for i:=2 to j do
    if k<c[i] then k:=c[i];
  writeln(f2,k);
  close(f1);
  close(f2);
end.

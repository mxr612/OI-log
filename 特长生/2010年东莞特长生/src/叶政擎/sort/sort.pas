var
  i,j,n,t:integer;
  a:array [1..200,1..2] of integer;

begin
  assign(input,'sort.in');
  assign(output,'sort.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
    readln(a[i,1],a[i,2]);
  for i:=1 to n do
    for j:=i+1 to n do
      if a[i,2]<a[j,2] then
      begin
        t:=a[i,2];
        a[i,2]:=a[j,2];
        a[j,2]:=t;
        t:=a[i,1];
        a[i,1]:=a[j,1];
        a[j,1]:=t;
      end else
        if (a[i,2]=a[j,2]) and (a[i,1]>a[j,1]) then
        begin
          t:=a[i,2];
          a[i,2]:=a[j,2];
          a[j,2]:=t;
          t:=a[i,1];
          a[i,1]:=a[j,1];
          a[j,1]:=t;
        end;
  writeln(a[1,1],' ',a[1,2],' ','1');
  t:=1;
  for i:=2 to n do
  begin
    if a[i-1,2]<>a[i,2] then t:=i;
    writeln(a[i,1],' ',a[i,2],' ',t);
  end;
  close(input);
  close(output);
end.

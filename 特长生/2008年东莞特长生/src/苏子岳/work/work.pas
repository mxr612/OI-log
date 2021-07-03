const
  inf='work.in';
  ouf='work.out';
var
  s,n,i,j:integer;
  t,a,b,rd:array[1..1000] of integer;
begin
  assign(input,inf);
  assign(output,ouf);
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
      readln(t[i],a[i],b[i]);
      dec(b[i],t[i])
    end;
  for i:=1 to n do
    for j:=1 to n do
      if (i<>j) and (a[i]<=a[j]) and (b[i]>=b[j])
        then inc(rd[j]);
  s:=0;
  for i:=1 to n do
    if rd[i]=0
      then inc(s,t[i]);
  writeln(s);
  close(input);
  close(output)
end.

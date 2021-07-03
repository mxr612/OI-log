var a:array[1..20000,1..2]of integer;
    m,n,x,y:integer;
    p:longint;
begin
  assign(input,'reward.in');
  reset(input);
  readln(input,n,m);
  for x:=1 to m do readln(input,a[x,1],a[x,2]);
  close(input);
  assign(output,'reward.out');
  rewrite(output);
  for x:=1 to m-1 do
    for y:=x+1 to m do
      if (a[x,1]=a[y,2])and(a[x,2]=a[y,1]) then
        begin
          write(output,'-1');
          close(output);
          halt;
        end;
  p:=n*100+trunc((n*n-n)/2);
  write(output,p);
  close(output);
end.

program work(input,output);
var a:array [1..1000,1..2] of integer;
    f:array [0..1500] of integer;
    ti:array [1..1000] of integer;
    n,m,i,j:integer;
    free:boolean;
begin
  assign(input,'work.in');
  assign(output,'work.out');
  reset(input);
  rewrite(output);
  read(input,n);
  m:=0;
  for i:=1 to n do
  begin
    read(input,ti[i],a[i,1],a[i,2]);
    if m<a[i,2]
    then m:=a[i,2];
  end;
  f[0]:=0;
  for i:=1 to m do f[i]:=3000;
  for i:=0 to m do
  begin
    free:=true;
    for j:=1 to n do
      if (i>=a[j,1]) and (i+ti[j]<=a[j,2]) and (f[i]+ti[j]<f[a[j,2]])
      then begin f[i+ti[j]]:=f[i]+ti[j];  free:=false; end;
    if (free) and (f[i]<f[i+1])
    then f[i+1]:=f[i];
  end;
  write(output,f[m]);
  close(input);
  close(output);
end.

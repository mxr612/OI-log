var m,n,i,min,maxa,maxb:integer;
    a,b:array[1..9999] of integer;

begin
  readln(n,m);
  for i:=1 to m do
    readln(a[i],b[i]);
  min:=n*100+n-1;
  for i:=1 to m do
    begin
      maxa:=maxa+a[i];
      maxb:=maxb+b[i];
    end;
  if maxa=maxb then writeln(-1)
                 else writeln(min);
end.
var
  f1,f2:text;
  i,j,n,m,k:integer;
  a,b,c:array[1..20000] of integer;
begin
  assign(f1,'reward.in');
  reset(f1);
  assign(f2,'reward.out');
  rewrite(f2);
  readln(f1,n,m);
  for i:=1 to m do readln(f1,a[i],b[i]);
    for i:=1 to m do
     begin
       c[a[i]]:=c[a[i]]+1;
       inc(k);
     end;
  for i:=1 to m do
   for j:=1 to m do
    if (a[i]=b[j]) and (a[j]=b[i]) and (i<>j) then begin writeln(f2,'-1');break; end
                                   else begin writeln(f2,n*100+k);break; end;
  close(f1);
  close(f2);
end.
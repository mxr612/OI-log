var
  t,a,b:array[1..10000] of integer;
  x,n:integer;
procedure duru;
var
  f1:text;
  i:integer;
begin
  assign(f1,'work.in');
  reset(f1);
  readln(f1,n);
  for i:=1 to n do readln(f1,t[i],a[i],b[i]);
  close(f1);
end;
procedure chuli;
var
  i,j:integer;
begin
  for i:=1 to n do
   if (a[i]=0) and (t[i]<>0) then for j:=1 to n do
    if (a[j]=0) and (i<>j) then
     if t[i]>t[j] then begin x:=x+t[j];t[j]:=0; end
                  else begin x:=x+t[i];t[i]:=0; end;

end;
procedure shuchu;
var
  f2:text;
begin
  assign(f2,'work.out');
  rewrite(f2);
  writeln(f2,x);
  close(f2);
end;
begin
  duru;
  chuli;
  shuchu;
end.
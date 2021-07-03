type
  aa=array[1..200]of integer;
var
  a,b:aa;
  i,j,n:integer;
  f1,f2:text;
procedure kp(var l,r,i:integer);
var
  j,k,x:integer;
begin
  i:=l;
  j:=r;
  k:=a[i];
  repeat
    while (i<j)and(k>a[j])do dec(j);
    if i<j then
    begin
      if ((a[i]=a[j])and(b[i]>b[j]))or(a[i]<>a[j])then
      begin
        x:=b[i];
        b[i]:=b[j];
        b[j]:=x;
      end;
      a[i]:=a[j];
      inc(i);
    end;
    while (i<j)and(k<a[i])do inc(i);
    if i<j then
    begin
      if ((a[i]=a[j])and(b[i]<b[j]))or(a[i]<>a[j])then
      begin
        x:=b[i];
        b[i]:=b[j];
        b[j]:=x;
      end;
      a[j]:=a[i];
      dec(j);
    end;
  until i=j;
  a[i]:=k;
end;
procedure k(l,r:integer);
var
  i:integer;
begin
  kp(l,r,i);
  if l<i-1 then k(l,i-1);
  if i+1<r then k(i+1,r);
end;

begin
  assign(f1,'sort.in');
  assign(f2,'sort.out');
  reset(f1);
  rewrite(f2);
  readln(f1,n);
  for i:=1 to n do
    readln(f1,b[i],a[i]);
  k(1,n);
  j:=1;
  for i:=1 to n do
  begin
    if (i>1)and(a[i-1]>a[i])then j:=i;
    writeln(f2,b[i],' ',a[i],' ',j);
  end;
  close(f1);
  close(f2);
end.

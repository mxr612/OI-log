var n,m,i:integer;
    a,b:array [1..1000] of integer;
    f1,f2:text;

procedure qsport(l,r:integer);
 var i,j,k,t:integer;
 begin
  i:=l;j:=r;t:=a[(i+j) div 2];
  repeat
   while a[i]>t do inc(i);
   while a[j]<t do dec(j);
   if i<=j then
    begin
     k:=a[i];a[i]:=a[j];a[j]:=k;
     k:=b[i];b[i]:=b[j];b[j]:=k;
     i:=i+1;j:=j-1;
    end;
  until i>j;
  if l<j then qsport(l,j);
  if i<r then qsport(i,r);
 end;

begin
 assign(f1,'num.in');assign(f2,'num.out');
 reset(f1);rewrite(f2);
 readln(f1,n);
 for i:=1 to n do begin read(f1,a[i]);b[i]:=i;end;
 readln(f1,m);
 qsport(1,n);
 writeln(f2,a[m]);
 writeln(f2,b[m]);
 close(f1);close(f2);
end.
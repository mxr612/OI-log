var x,y,a,x1,y1:array[1..500]of integer;
    n,i,t,j,max,m:integer;
begin
 assign(input,'sort.in');
 assign(output,'sort.out');
 reset(input);
 rewrite(output);
 for i:=1 to 500 do
  begin
   x[i]:=500;
   y[i]:=500;
  end;
 read(n);
 for i:=1 to n do
  begin
   read(x1[i],y1[i]);
   x[x1[i]]:=x1[i];
   y[x1[i]]:=y1[i];
  end;
 for i:=1 to 500 do
  begin
   if x[i]<>500 then
    for j:=i to 500 do
     if x[j]<>500 then
      if (y[j]>y[i])or((y[j]=y[i])and(x[j]<x[i])) then
       begin
        t:=y[i];y[i]:=y[j];y[j]:=t;
        t:=x[i];x[i]:=x[j];x[j]:=t;
       end;
  end;
  t:=0;
  max:=500;
  m:=500;
 for i:=1 to 500 do
  if x[i]<> 500 then
   begin
    inc(t);
    if y[i]<>max then begin
    write(x[i],' ',y[i],' ',t);m:=i;a[m]:=t; end else write(x[i],' ',y[i],' ',a[m]);
    max:=y[i];
    writeln;
   end;
 close(input);
 close(output);
end.
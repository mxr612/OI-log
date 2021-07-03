var c,d,e,ti,ai,bi,g:array[1..1000] of integer;
    n,m,i,j,x,k:integer;
    f1,f2:text;
begin
 assign(f1,'work.in');
  reset(f1);
  readln(f1,n);
 for i:=1 to n do
  readln(f1,ti[i],ai[i],bi[i]);
  close(f1);
  for i:=1 to n do
   c[i]:=bi[i]-ai[i];
   for i:=1 to n do
    begin
     d[i]:=c[i]-ti[i];
     e[i]:=d[i];
    end;
   for i:=1 to n-1 do
     for j:=i+1 to n do
       if d[i]<d[j] then
        begin
         x:=d[i];
         d[i]:=d[j];
         d[j]:=x;
        end;
       assign(f2,'work.out');
     rewrite(f2);
   for i:=1 to n do
     if d[1]=e[i] then
          begin
           k:=k+1;
           g[k]:=ti[i];
          end;
       if k=1 then
       begin
        writeln(f2,g[1]);
         close(f2);
        halt;
       end;
       for i:=1 to n-1 do
     for j:=i+1 to n do
       if g[i]>g[j] then
        begin
         x:=g[i];
         g[i]:=g[j];
         g[j]:=x;
        end;

        writeln(f2,g[1]);
   close(f2);
  end.





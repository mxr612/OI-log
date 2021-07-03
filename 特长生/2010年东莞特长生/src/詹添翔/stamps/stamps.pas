var a,b:array[1..32767]of integer;
    g,i,j,max,n,m:integer;
    procedure main(s,k:integer);
     var i:integer;
     begin
     if k>n then exit;
      for i:=1 to m do
       begin
        s:=s+a[i];
        b[s]:=1;
         main(s,k+1);
        s:=s-a[i];
       end;
     end;
begin
 assign(input,'stamps.in');
 assign(output,'stamps.out');
 reset(input);
 rewrite(output);
 read(n,m);
 fillchar(b,sizeof(b),0);
 max:=0;
 for i:=1 to m do
  begin
   read(a[i]);
   b[a[i]]:=1;
  end;
 main(0,1);
 g:=0;
 for i:=1 to 25500 do
  begin
   if b[i]<>0 then
    while b[i]<>0 do
     begin
      inc(g);
      inc(i);
     end;
   if g>max then max:=g;
   g:=0;
  end;
 write(max);
 close(input);
 close(output);
end.

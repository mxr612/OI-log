           var a:array[1..150,1..150]of integer;
    i,j,c,b,n,k,h,f,g,x,y:integer;
    procedure jf(s:integer);
     var i,j:integer;
     begin
      g:=0;
      if s=2 then
       begin
        repeat
         dec(k);
         a[x,y]:=k;
         if k=1 then
          begin
           for i:=1 to n do
            begin
             for j:=1 to n do
              write(a[i,j],' ');
             writeln;
            end;
           close(input);
           close(output);
           halt;
          end;
          inc(g);
         if g<>h then
         begin
          x:=x+1;y:=y-1;end;
        until g=h;
       end;
      if s=1 then
       begin
        repeat
         dec(k);
         a[x,y]:=k;
         if k=1 then
          begin
           for i:=1 to n do
            begin
             for j:=1 to n do
              write(a[i,j],' ');
             writeln;
            end;
           close(input);
           close(output);
           halt;
          end;
         inc(g);
         if g<>h then
         begin
          x:=x-1;y:=y+1 end;
        until g=h;
       end;
     end;
begin
 assign(input,'snake.in');
 assign(output,'snake.out');
 reset(input);
 rewrite(output);
 b:=0;
 read(n);
  k:=n*n;
  f:=n;
  h:=2;
  c:=1;
  x:=1;
  y:=1;
 a[1,1]:=n*n;
 x:=2;
 jf(c);
 repeat
  if h=n then begin b:=1; end;
  if c=1 then c:=2 else c:=1;
  if b=1 then begin if c=1 then y:=y+1 else x:=x+1;h:=h-1;jf(c);end
   else begin if c=1 then x:=x+1 else y:=y+1;h:=h+1;jf(c);end;
 until k=1;
end.

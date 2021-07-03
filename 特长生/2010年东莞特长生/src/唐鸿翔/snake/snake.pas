var a,b,c,d,e,f,n,g:longint;
h:array[1..100,1..100]of longint;
begin
assign(input,'snake.in');
reset(input);
assign(output,'snake.out');
rewrite(output);
read(n); f:=n*n;
while f<>0 do
begin
f:=f div 10;inc(g);
end;
h[n,n]:=1; c:=1;
for b:=2 to n do
 begin
  if (b mod 2)=0
   then
     for d:=1 to b do
      begin inc(c); h[n-b+d,n-d+1]:=c;end
      else
     for   d:=1 to b do
       begin inc(c);h[n-d+1,n-b+d]:=c;end;

    end;
if (n mod 2)=1 then begin
for b:=2 to n do
 begin
  if (b mod 2)=0
   then
    for d:=1 to (n-b+1) do
    begin inc(c);h[d,n-b-d+2]:=c;end
    else
    for d:=1 to (n-b+1) do
    begin inc(c);h[n-b-d+2,d]:=c;end;
 end;end
 else for b:=2 to n do
 begin
  if (b mod 2)=1
   then
    for d:=1 to (n-b+1) do
    begin inc(c);h[d,n-b-d+2]:=c;end
    else
    for d:=1 to (n-b+1) do
    begin inc(c);h[n-b-d+2,d]:=c;end;
 end;

   for b:=1 to n do
  begin
 for c:=1 to n do
begin write(h[b,c]:g);write(' ');end;
writeln;
  end;
  close(input);close(output);
end.
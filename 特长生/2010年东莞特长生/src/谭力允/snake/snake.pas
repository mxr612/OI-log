const
  maxn=100;
var
  a:array[1..maxn,1..maxn] of longint;
  n:longint;
procedure init;
var
  i:longint;
begin
  readln(n);
  a[1,1]:=n*n;
  for i:=2 to n do
    if i mod 2=0 then a[1,i]:=a[1,i-1]-((i-1)*2)
                 else a[1,i]:=a[1,i-1]-1;
  for i:=2 to n do
   if i mod 2=0 then a[i,1]:=a[i-1,1]-1
                else a[i,1]:=a[i-1,1]-((i-1)*2);
  a[n,n]:=1;
  for i:=n-1 downto 2 do
    if (n-i+1) mod 2=0 then a[i,n]:=a[i+1,n]+1
                 else a[i,n]:=a[i+1,n]+(n-(i+1)+1)*2;
  for i:=n-1 downto 2 do
    if (n-i+1) mod 2=0 then a[n,i]:=a[n,i+1]+(n-(i+1)+1)*2
                 else a[n,i]:=a[n,i+1]+1;
end;
procedure main;
var
  i,j:longint;
begin
  for i:=2 to n-1 do
    for j:=2 to n-1 do
      begin
        if i mod 2=0
          then begin
                 if j mod 2=0 then a[i,j]:=a[i-1,j+1]-1
                              else a[i,j]:=a[i-1,j+1]+1;
               end;
        if i mod 2<>0
          then begin
                 if j mod 2=0 then a[i,j]:=a[i-1,j+1]+1
                              else a[i,j]:=a[i-1,j+1]-1;
               end;
      end;
end;
procedure print;
var
  i,j:longint;
begin
  for i:=1 to n do
    begin
      for j:=1 to n-1 do
        write(a[i,j],' ');
      writeln(a[i,n]);
    end;
end;
begin
  assign(input,'snake.in');
  reset(input);
  assign(output,'snake.out');
  rewrite(output);
  init;
  main;
  print;
  close(input);
  close(output);
end.
program snake;
var i,j,k,n,x,y:integer;
    a:array[1..100,1..100] of integer;
begin
 assign(input,'snake.in');
 assign(output,'snake.out');
 reset(input);
 rewrite(output);
 readln(n);
    a[n,n]:=1;i:=n;j:=n;
      for k:=2 to n*n do
        begin
          if (i=n) and (j=n) then
            begin
          i:=i-1;a[i,j]:=k;
        end
      else if (i+1<=n) and (j<>1) and (a[i+1,j-1]=0) then
    begin
  i:=i+1;j:=j-1;a[i,j]:=k;
end
  else if (i<>1) and (j+1<=n) and (a[i-1,j+1]=0) then
    begin
      i:=i-1;j:=j+1;a[i,j]:=k;
        end
          else if (i=n) and (j<>1) then
            begin
              j:=j-1;a[i,j]:=k;
                end
              else if (j=n) and (i<>1) then
            begin
          i:=i-1;a[i,j]:=k;
        end
      else if (i=n) and (j=1) then
    begin
  i:=i-1;a[i,j]:=k;
end
else if (j=n) and (i=1) then
  begin
    j:=j-1;a[i,j]:=k;
      end
        else if (i=1) and (j<>n) then
          begin
            j:=j-1;a[i,j]:=k;
          end
        else if (j=1) and (i<>n) then
      begin
    i:=i-1;a[i,j]:=k;
  end;
end;

for x:=1 to n do
  begin
    for y:=1 to n do
      write(a[x,y],' ');
    writeln;
  end;
close(input);
close(output);
end.

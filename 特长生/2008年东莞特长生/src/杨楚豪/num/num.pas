var a:array[1..100,0..1]of integer;
    x,y,z,n,k:integer;
begin
  assign(input,'num.in');
  reset(input);
  readln(input,n);
  for x:=1 to n do
    begin
      read(input,a[x,0]);
      a[x,1]:=x;
    end;
  readln(input);
  read(input,k);
  close(input);
  for x:=1 to n-1 do
    for y:=x+1 to n do
      if a[x,0]<a[y,0] then
        begin
          z:=a[x,0];
          a[x,0]:=a[y,0];
          a[y,0]:=z;
          z:=a[x,1];
          a[x,1]:=a[y,1];
          a[y,1]:=z;
        end;
 assign(output,'num.out');
 rewrite(output);
 writeln(output,a[k,0]);
 write(output,a[k,1]);
 close(output);
end.

var
  i,j,x,n:longint;
  a:array[1..200,1..2]of integer;
begin
  assign(input,'sort.in');reset(input);
  assign(output,'sort.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    readln(a[i,1],a[i,2]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i,2]<=a[j,2] then
        begin
          if a[i,2]=a[j,2] then
            begin
              if a[i,1]>a[j,1] then
                begin
                  x:=a[i,1];
                  a[i,1]:=a[j,1];
                  a[j,1]:=x;
                end;
            end
            else
              begin
                x:=a[i,2];
                a[i,2]:=a[j,2];
                a[j,2]:=x;
                x:=a[i,1];
                a[i,1]:=a[j,1];
                a[j,1]:=x;
             end;
        end;

  x:=1;
  writeln(a[1,1],' ',a[1,2],' ',x);
  for i:=2 to n do
    begin
      if a[i,2]<>a[i-1,2] then
        x:=i;
    writeln(a[i,1],' ',a[i,2], ' ',x);
    end;
  close(input);
  close(output);
end.


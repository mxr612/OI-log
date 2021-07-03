var
  a,b:array[1..100] of integer;
  n,k,d,c:integer;
procedure rr;
  var
    i:integer;
    f1:text;
  begin
    assign(f1,'num.in');
    reset(f1);
    readln(f1,n);
    for i:=1 to n do
      read(f1,a[i]);
    readln(f1);
    readln(f1,k);
    close(f1);
  end;
procedure main;
  var
    i,j,t:integer;
  begin
    for i:=1 to n do
      b[i]:=a[i];
    for i:=1 to n-1 do
      for j:=1 to n-1 do
        if b[j]<b[j+1]
          then
            begin
              t:=b[j];
              b[j]:=b[j+1];
              b[j+1]:=t;
            end;
    for i:=1 to n do
      if b[k]=a[i]
        then
          begin
            d:=a[i];
            c:=i;
            break;
          end;
  end;
procedure ww;
  var
    f2:text;
  begin
    assign(f2,'num.out');
    rewrite(f2);
    writeln(f2,d);
    writeln(f2,c);
    close(f2);
  end;
begin
  rr;
  main;
  ww;
end.
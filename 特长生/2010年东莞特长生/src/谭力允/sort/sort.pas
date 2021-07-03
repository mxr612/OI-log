const
  maxn=200;
var
  a:array[0..maxn,1..2] of longint;
  n:longint;
procedure init;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do
    readln(a[i,1],a[i,2]);
end;
procedure sort;
var
  i,j,s:longint;
begin
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (a[i,2]<a[j,2]) or ((a[i,2]=a[j,2])and (a[i,1]>a[j,1]))
        then begin
               s:=a[i,1];
               a[i,1]:=a[j,1];
               a[j,1]:=s;
               s:=a[i,2];
               a[i,2]:=a[j,2];
               a[j,2]:=s;
             end;
end;
procedure print;
var
  i,j:longint;
begin
  j:=1;
  for i:=1 to n do
    begin
      write(a[i,1],' ',a[i,2]);
      if a[i,2]=a[i-1,2] then writeln(' ',j)
                         else begin
                                writeln(' ',i);
                                j:=i;
                              end;
    end;
end;
begin
  assign(input,'sort.in');
  reset(input);
  assign(output,'sort.out');
  rewrite(output);
  init;
  sort;
  print;
  close(input);
  close(output);
end.
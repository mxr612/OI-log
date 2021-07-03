const
  inf='num.in';
  ouf='num.out';
  maxn=101;
var
  a,b:array[0..maxn] of integer;
  n,k:integer;
procedure init;
  var
    i:integer;
  begin
    assign(input,inf);
    assign(output,ouf);
    reset(input);
    rewrite(output);
    readln(n);
    for i:=1 to n do
      begin
        read(a[i]);
        b[i]:=i
      end;
    readln(k)
  end;
procedure swap(var a,b:integer);
  var
    t:integer;
  begin
    t:=a;
    a:=b;
    b:=t
  end;
procedure work;
  var
    i,j:integer;
  begin
    for i:=1 to n-1 do
      for j:=i+1 to n do
        if a[i]<a[j]
          then
            begin
              swap(a[i],a[j]);
              swap(b[i],b[j])
            end
  end;
procedure print;
  begin
    writeln(a[k]);
    writeln(b[k]);
    close(input);
    close(output)
  end;
begin
  init;
  work;
  print
end.

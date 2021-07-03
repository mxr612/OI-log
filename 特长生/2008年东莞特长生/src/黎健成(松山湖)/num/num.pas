const
  inf='num.in';
  ouf='num.out';
  maxn=100;

var
  a,b:array[1..maxn] of longint;
  n,k:longint;

procedure qsort(l,r:longint);
var
  mid,t,i,j:longint;
begin
  if l<r then
    begin
      i:=l;
      j:=r;
      mid:=a[(l+r) div 2];
      repeat
        while a[i]>mid do inc(i);
        while a[j]<mid do dec(j);
        if i<=j then
          begin
            t:=a[i];
            a[i]:=a[j];
            a[j]:=t;
            t:=b[i];
            b[i]:=b[j];
            b[j]:=t;
            inc(i);
            dec(j);
          end;
      until i>=j;
      qsort(l,j);
      qsort(i,r);
    end;
end;

procedure main;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      read(a[i]);
      b[i]:=i;
    end;
  readln;
  readln(k);
  qsort(1,n);
  writeln(a[k]);
  writeln(b[k]);
end;

begin
  assign(input,inf);
  assign(output,ouf);
  reset(input);
  rewrite(output);
  main;
  close(input);
  close(output);
end.
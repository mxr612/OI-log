const
  inf='work.in';
  ouf='work.out';
  maxn=1000;

var
  f:array[0..1500] of longint;
  a,b,c:array[0..maxn+1] of longint;
  m,n:longint;

procedure qsort(l,r:longint);
var
  mid2,mid,t,i,j:longint;
begin
  if l<r then
    begin
      i:=l;
      j:=r;
      mid:=a[(l+r) div 2];
      mid2:=c[(l+r) div 2];
      repeat
        while (a[i]<mid) or ((a[i]=mid) and (c[i]<mid2)) do inc(i);
        while (a[j]>mid) or ((a[j]=mid) and (c[j]>mid2)) do dec(j);
        if i<=j then
          begin
            t:=a[i];
            a[i]:=a[j];
            a[j]:=t;
            t:=b[i];
            b[i]:=b[j];
            b[j]:=t;
            t:=c[i];
            c[i]:=c[j];
            c[j]:=t;
            inc(i);
            dec(j);
          end;
      until i>=j;
      qsort(l,j);
      qsort(i,r);
    end;
end;

procedure dp;
var
  i,j,k:longint;
begin
  for i:=1 to m do f[i]:=maxlongint;
  f[0]:=0;
  a[n+1]:=m;
  c[n+1]:=b[n]-c[n];
  for i:=0 to m do
    begin
      if f[i]=maxlongint then
        if f[i-1]<f[i] then f[i]:=f[i-1];
      for j:=1 to n do
        if (i>=a[j]) and (i+c[j]<=b[j]) and (f[i]+c[j]<f[i+c[j]]) then
          begin
            f[i+c[j]]:=f[i]+c[j];
            for k:=i+c[j] to a[j+1] do
              if f[i]+c[j]<f[k] then f[k]:=f[i]+c[j];
          end;
    end;
//  for i:=1 to m do writeln(i,':',f[i]);
  writeln(f[m]);
end;

procedure main;
var
  i:longint;
begin
  readln(n);
  m:=0;
  for i:=1 to n do
    begin
      readln(c[i],a[i],b[i]);
      if b[i]>m then m:=b[i];
    end;
  qsort(1,n);
  dp;
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
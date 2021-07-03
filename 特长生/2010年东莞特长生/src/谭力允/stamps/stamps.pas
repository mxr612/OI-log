const
  maxn=25500;
var
  f:array[0..maxn] of boolean;
  a:array[0..maxn] of longint;
  b:array[1..100] of longint;
  n,m,k:longint;
procedure init;
var
  i:longint;
begin
  readln(n);
  readln(m);
  k:=0;
  for i:=1 to m do
    begin
      readln(b[i]);
      if b[i]>k then k:=b[i];
    end;
  k:=k*n;
end;
procedure dp;
var
  i,j,j1:longint;
begin
  fillchar(f,sizeof(f),false);
  f[0]:=true;
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
    for j1:=1 to n do
      for j:=k downto 0 do
        if (f[j]) and (a[j]<n)  then begin
                                       f[j+b[i]]:=true;
                                       if a[j+b[i]]=0 then a[j+b[i]]:=a[j]+1;
                                       if a[j]+1<a[j+b[i]] then a[j+b[i]]:=a[j]+1;
                                     end;
  for i:=1 to k do
    if not(f[i]) then begin
                        write(i-1);
                        exit;
                      end;
end;
begin
  assign(input,'stamps.in');
  reset(input);
  assign(output,'stamps.out');
  rewrite(output);
  init;
  dp;
  close(input);
  close(output);
end.
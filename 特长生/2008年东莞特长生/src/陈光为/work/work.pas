program pp;
var i,j,n,k:integer;
    s:longint;
    a,b,c,t,f:array[0..3000] of integer;
    v:array[0..3000] of boolean;
procedure swap(var x,y:integer);
var t0:integer;
begin
  t0:=x;
  x:=y;
  y:=t0;
end;

begin
  assign(input,'work.in');
  assign(output,'work.out');
  reset(input);rewrite(output);
  fillchar(f,sizeof(f),0);
  readln(n);
  for i:=1 to n do
  begin
    readln(t[i],a[i],b[i]);
    c[i]:=b[i]-a[i];
  end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
    begin
      if c[j]>c[i] then
      begin
        swap(a[j],a[i]);
        swap(b[j],b[i]);
        swap(t[i],t[j]);
        swap(c[i],c[j]);
      end;
      if (c[j]=c[i]) and (t[i]>t[j]) then
      begin
        swap(a[j],a[i]);
        swap(b[j],b[i]);
        swap(t[i],t[j]);
        swap(c[i],c[j]);
      end;
    end;
  for i:=1 to n do
  begin
    if (f[a[i]]=0) and (f[b[i]]=0) then
    begin
      for j:=a[i] to b[i] do f[j]:=i;
      v[i]:=true;
    end
    else
    begin
      for j:=a[i] to b[i] do if f[j]=0 then k:=k+1;
      if k>t[i] then for j:=a[i] to b[i] do if f[j]=0 then begin f[j]:=i;v[i]:=true;end;
    end;
  end;
  s:=0;
  for i:=1 to n do if v[i] then s:=s+t[i];
  writeln(s);
  close(input);close(output);
end.

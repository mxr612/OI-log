  var
  a,b,t,x:array[1..1000] of longint;
  n,i,j,k,min,te:longint;
begin
  assign(input,'work.in'); reset(input);
  assign(output,'work.out'); rewrite(output);

  readln(n);
  for i:=1 to n do readln(t[i],a[i],b[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if b[i]>b[j] then begin
        te:=t[i];
        t[i]:=t[j];
        t[j]:=te;
        te:=a[i];
        a[i]:=a[j];
        a[j]:=te;
        te:=b[i];
        b[i]:=b[j];
        b[j]:=te;
      end;
  j:=0;
  for i:=1 to n do begin
    for k:=j downto 1 do
      if (x[k]>a[i]) and (b[i]>=x[k]+t[i]) then x[k]:=x[k]+t[i];
      if a[i]=0 then begin
        j:=j+1;
        x[j]:=t[i];
      end;
  end;
  min:=x[1];
  for k:=2 to j do  if (x[k]<min) and (x[k]<>0) then min:=x[k];
  writeln(min);

  close(input); close(output);

end.

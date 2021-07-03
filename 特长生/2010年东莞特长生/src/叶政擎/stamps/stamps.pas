var
  i,j,k,x,min,max,n,m:integer;
  a:array [1..100] of byte;
  c:array [0..25500] of byte;

begin
  assign(input,'stamps.in');
  assign(output,'stamps.out');
  reset(input);
  rewrite(output);
  readln(n);
  readln(m);
  max:=0;
  if (n>0) and (m>0) then begin
  readln(a[1]);
  for i:=2 to m do begin
    readln(x);
    j:=1;
    k:=1;
    while (x>a[k]) and (k<i) do k:=k+1;
    for j:=i downto k do
      a[j]:=a[j-1];
    a[k]:=x;
  end;
  if a[1]=1 then begin
    max:=1;
    c[0]:=0;
    c[1]:=1;
    repeat
      max:=max+1;
      min:=c[max-1];
      for i:=1 to m do begin
        if max<a[i] then break;
        if min>c[max-a[i]] then min:=c[max-a[i]];
      end;
      c[max]:=min+1;
    until min+1>n;
    max:=max-1;
  end;
  end;
  writeln(max);
  close(input);
  close(output);
end.
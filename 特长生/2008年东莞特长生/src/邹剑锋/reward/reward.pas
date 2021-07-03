var
  i,j,n,m,max,c,d:integer;
  a:array[1..10000]of integer;
  b:array[1..2000,1..2000]of boolean;
begin
  assign(input,'reward.in'); reset(input);
  assign(output,'reward.out'); rewrite(output);
  read(n,m);
  max:=100*n;
  for i:=1 to n do a[i]:=200;
  for i:=1 to m do begin
      read(c,d);
      b[c,d]:=true;
      for j:=1 to m do if b[d,j]=true then b[c,j]:=true;
      for j:=1 to m do if b[j,c]=true then b[j,d]:=true;
      if b[d,c]=true then begin write('-1'); exit; end;
      m:=a[c];
      while a[d]>=a[c] do a[c]:=a[c]+1;
      max:=max+a[c]-m;
  end;
  write(max);
  close(input);
  close(output);
end.


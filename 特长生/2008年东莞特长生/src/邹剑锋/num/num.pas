var
  n,m,i,k,l,j,v:integer;
  a:array[1..100]of integer;
begin
  assign(input,'num.in'); reset(input);
  assign(output,'num.out'); rewrite(output);
  read(n);
  for i:=1 to n do  read(a[i]);
  read(k);
  j:=1;
  while j<=k do begin
        l:=a[1];
        v:=1;
        for i:=2 to n do if a[i]>l then begin l:=a[i]; v:=i; end;
        if j=k then begin writeln(a[v]);writeln(v);  end;
        a[v]:=0;
        j:=j+1;
        end;
         close(input);
        close(output);
end.

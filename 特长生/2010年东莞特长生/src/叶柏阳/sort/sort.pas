var
  n,i,j,q,w,e:integer;
  a,b,c:array[0..200]of integer;
begin
  assign(input,'sort.in');
  assign(output,'sort.out');
  reset(input);
  rewrite(output);
  read(n);
  for i:=1 to n do
    begin
       read(a[i],b[i]);
       c[i]:=i;
    end;
  for i:=1 to n do
    begin
      for j:=i to n do
        begin
          if b[j]>b[i]
            then begin
                   q:=a[j];
                   a[j]:=a[i];
                   a[i]:=q;
                   w:=b[j];
                   b[j]:=b[i];
                   b[i]:=w;
                 end;
        end;
    end;
  for i:=1 to n do
    begin
      if b[i]=b[i+1]
        then begin
              c[i+1]:=c[i];
             end;
    end;
  for i:=1 to n do begin
    for j:=1 to n do
      begin
        if (a[i]<a[j])and(b[i]=b[j])
          then begin q:=a[i];
               a[i]:=a[j];
               a[j]:=q;end;
        end;
      end;
  for i:=1 to n do
    begin
      write(a[i],' ',b[i],' ',c[i]);
      writeln;
    end;
  close(input);
  close(output);
end.

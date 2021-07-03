var
    bai,i,k,n,m:integer;
    num,o:array[1..100] of integer;

begin
  readln(n);
  for i:=1 to n do
    begin
      read(num[i]);
      o[i]:=num[i];
    end;
  readln(m);
  begin
    for i:=1 to n-1 do
     for k:=i to n do
      if num[i] < num[k] then begin
                                  bai:=num[i];
                                  num[i]:=num[k];
                                  num[k]:=bai;
                                end;
  end;
  begin
    for i:=1 to n do
      if i=m then begin
                    writeln(num[i]);
                    for k:=1 to n do
                      if num[i]=o[k] then writeln(k);
                  end;
  end;
end.

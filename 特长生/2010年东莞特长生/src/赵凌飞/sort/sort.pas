var
  a,s:array[1..500]of longint;
  n,m,i,j,t:longint;
begin
  assign(input,'sort.in');
  assign(output,'sort.out');
  reset(input);
  rewrite(output);
  read(n);
  for i:=1 to n do
    read(a[i],s[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      begin
        if s[i]<s[j] then begin
                            t:=a[i];
                            a[i]:=a[j];
                            a[j]:=t;
                            t:=s[i];
                            s[i]:=s[j];
                            s[j]:=t;
                          end;
        if (s[i]=s[j])and(a[i]>a[j])
          then begin
                            t:=a[i];
                            a[i]:=a[j];
                            a[j]:=t;
                            t:=s[i];
                            s[i]:=s[j];
                            s[j]:=t;
               end;
      end;
  for i:=1 to n do
    writeln(a[i],' ',s[i],' ',i);
  close(input);
  close(output);
end.

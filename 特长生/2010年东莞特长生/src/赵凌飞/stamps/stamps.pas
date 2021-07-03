var
  a:array[1..255*100]of integer;
  b:array[1..10000]of integer;
  s:array[1..200]of integer;
  n,m,max:longint;
procedure init;
var
  i,j:longint;
begin
  read(n,m);
  max:=0;
  for i:=1 to m do
    begin
      read(s[i]);
      a[s[i]]:=1;
      inc(max);
      b[max]:=s[i];
    end;
end;
procedure main;
var
  i,j:longint;
begin
  i:=1;
  while i<=max do
    begin
      j:=1;
      while j<=max do
        begin
          if (a[b[i]]>0)and(a[b[j]]>0)and(a[b[i]]+a[b[j]]<=n)and(a[b[i]+b[j]]>a[b[i]]+a[b[j]])
            then begin
                   if a[b[i]+b[j]]=n then begin
                                            inc(max);
                                            b[max]:=b[i]+b[j];
                                          end;
                   a[b[i]+b[j]]:=a[b[i]]+a[b[j]];
                 end;
          if (a[b[i]]>0)and(a[b[j]]>0)and(a[b[i]]+a[b[j]]<=n)and(a[b[i]+b[j]]=0)
            then begin
              a[b[i]+b[j]]:=a[b[i]]+a[b[j]];
              if a[b[i]+b[j]]<n
              then begin
                     inc(max);
                     b[max]:=b[i]+b[j];
                   end;
          end;
          inc(j);
      end;
      inc(i);
    end;
end;
procedure print;
var
  i,j:longint;
begin
  i:=1;
  while a[i]>0 do
    inc(i);
  writeln(i-1);
end;
begin
  assign(input,'stamps.in');
  assign(output,'stamps.out');
  reset(input);
  rewrite(output);
  init;
  main;
  print;
  close(input);
  close(output);
end.
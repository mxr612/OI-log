program land(input,output);
var
  a,c:array[1..501] of integer;
  n,k,i,j,t:integer;
begin
  assign(input,'land.in');
  assign(output,'land.out');
  reset(input); rewrite(output);
  readln(n);
  fillchar(a,sizeof(a),0);
  fillchar(c,sizeof(c),0);
  a[1]:=1; c[1]:=1;
  for k:=2 to n*n do begin
    t:=0;
    for i:=1 to 500 do begin
      a[i]:=a[i]*2+t;
      t:=a[i] div 10;
      a[i]:=a[i] mod 10;
    end;
    for i:=1 to 500 do begin
      c[i]:=c[i]+a[i];
      if c[i]>=10 then begin
        c[i+1]:=c[i+1]+1;
        c[i]:=c[i]-10;
      end;
    end;
  end;
  k:=500;
  while c[k]=0 do dec(k);
  for i:=k downto 1 do write(c[i]);
  close(input); close(output);
end.

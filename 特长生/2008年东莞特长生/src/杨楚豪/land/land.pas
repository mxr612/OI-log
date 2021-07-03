var a,b:array[1..63] of longint;
    n,x,y,z:integer;
procedure run;
  begin
    for x:=1 to n do
      begin
        fillchar(b,sizeof(b),0);
        b[1]:=1;
        for y:=2 to x do
          begin
            z:=1;
            while b[z]>0 do
              begin
                b[z]:=b[z]*2;
                b[z+1]:=b[z+1]+b[z]div 100000000;
                b[z]:=b[z]mod 100000000;
                inc(z);
              end;
          end;
        z:=1;
        while b[z]>0 do
          begin
            a[z]:=a[z]+b[z];
            inc(z);
          end;
        z:=1;
        while a[z]>0 do
          begin
            a[z+1]:=a[z+1]+a[z]div 100000000;
            a[z]:=a[z]mod 100000000;
            inc(z);
          end;
      end;
    end;

begin
  assign(input,'land.in');
  reset(input);
  read(input,n);
  close(input);
  n:=n*n;
  fillchar(a,sizeof(a),0);
  run;
  for x:=2 to 63 do
    if a[x]=0 then
      begin
        y:=x-1;
        break;
      end;
  assign(output,'outupt.out');
  rewrite(output);
  for x:=y downto 1 do write(output,a[x]);
  close(output);
end.

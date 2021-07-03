program land(input,output);
var
  a,c:array[1..510]of integer;
  i,j,k,n,t:longint;

begin
  assign(input,'land.in');
  assign(output,'land.out');
  reset(input);
  rewrite(output);
  readln(input,n);
  fillchar(a,sizeof(a),0);
  fillchar(c,sizeof(c),0);
  a[1]:=1;
  c[1]:=1;
  for i:=1 to n*n-1 do begin
    k:=0;
    for j:=1 to 501 do begin
      a[j]:=a[j]*2+k;
      k:=a[j] div 10;
      a[j]:=a[j] mod 10;
    end;
    k:=0;
    for j:=1 to 501 do begin
      c[j]:=a[j]+c[j]+k;
      k:=c[j] div 10;
      c[j]:=c[j] mod 10;
    end;
  end;
  k:=510;
  while c[k]=0 do k:=k-1;
  for i:=k downto 1 do write(output,c[i]);
  close(input);
  close(output);
end.
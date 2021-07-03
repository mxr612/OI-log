program num(input,output);
var a:array [1..40000] of integer;
    n,i,j,t,k,max:longint;
begin
  assign(input,'num.in');
  assign(output,'num.out');
  reset(input);
  rewrite(output);
  fillchar(a,sizeof(a),0);
  read(input,n);  max:=0;
  for i:=1 to n do
  begin
    read(input,t);
    a[t]:=i;
    if t>max then max:=t;
  end;
  read(input,k);
  i:=max; j:=0;
  while j<k do
    if a[i]>0
    then begin inc(j); dec(i); end
    else dec(i);
  inc(i);
  writeln(output,i);
  write(output,a[i]);
  close(input);
  close(output);
end.
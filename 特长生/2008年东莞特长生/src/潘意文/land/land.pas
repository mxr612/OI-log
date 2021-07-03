program land(input,output);
type arr=array[1..500] of integer;
var a,total:array[1..500] of integer;
    n,la,i,j:integer;

function wei(a:arr):integer;
begin
  wei:=500;
  while  (wei>0) and (a[wei]=0) do dec(wei);
end;

procedure ping(var a:arr);
var b,c:arr;
    na,nb,i,j:integer;
begin
   b:=a;
   na:=wei(a);
   fillchar(c,sizeof(c),0);
   for i:=1 to na do
   for j:=1 to na do begin
       c[i+j-1]:=c[i+j-1]+a[i]*b[j];
       c[i+j]:=c[i+j-1] div 10+c[i+j];
       c[i+j-1]:=c[i+j-1] mod 10;
   end;
   a:=c;
end;

procedure add(var a:arr);
var c:arr;
    b,na,i,j:integer;
begin
   na:=wei(a);
   fillchar(c,sizeof(c),0);
   for i:=1 to na do begin
     c[i]:=c[i]+a[i]*2;
     c[i+1]:=c[i] div 10;
     c[i]:=c[i] mod 10;
   end;
   a:=c;
end;

procedure add2(var a:arr;b:arr);
var c:arr;
    na,nb,i,j:integer;
begin
  na:=wei(a);
  nb:=wei(b);
  fillchar(c,sizeof(c),0);
  if na<nb then na:=nb;
  for i:=1 to na do begin
     c[i]:=a[i]+b[i]+c[i];
     c[i+1]:=c[i] div 10+c[i+1];
     c[i]:=c[i] mod 10;
  end;
  a:=c;
end;

procedure find(n:integer);
begin
  add2(total,a);
  for i:=1 to n do begin
     add(a);
     add2(total,a);
  end;
end;

begin
   assign(input,'land.in');
   assign(output,'land.out');
   reset(input);rewrite(output);
   readln(n);
   n:=n*n-1;
   fillchar(a,sizeof(a),0);
   a[1]:=1;
   find(n);
   la:=wei(total);
   for i:=la downto 1 do write(total[i]);
   close(input);close(output);
end.

var n,i,j,k,max:longint;
    t,a,b,f:array [-1..2000] of integer;
    p:array [0..2000] of boolean;
    f1,f2:text;
begin
 assign(f1,'work.in');assign(f2,'work.out');
 reset(f1);rewrite(f2);
 readln(f1,n);
 max:=0;
 fillchar(p,sizeof(p),1);
 fillchar(a,sizeof(a),0);
 t:=a;b:=a;
 for i:=1 to n do
  begin
   readln(f1,t[i],a[i],b[i]);
   if b[i]>max then max:=b[i];
  end;
 fillchar(f,sizeof(f),0);
 for i:=1 to n do
  for j:=a[i]+t[i] to b[i] do
   if (f[j]=0) or ((f[j-t[i]]+t[i]<f[j]) and (f[j]>0)) then f[j]:=f[j-t[i]]+t[i];
 writeln(f2,f[max]);
 close(f1);close(f2);
end.